""" Fln Rule Object
@author Darion Cassel
"""
from fln_config import *

class FlnRuleSet(object):
    def __init__(self, rules):
        self.rules = rules

    def get(self, rule_type=None, capability=None, tag=None, code_symbol=None):
        rules_set = []
        for rule in self.rules:
            if rule_type is None or rule.rule_type == rule_type:
                if capability is None or rule.capability == capability:
                    if tag is None or rule.tag_statement.isa(tag):
                        if rule.code_symbol == code_symbol \
                            or code_symbol is None:
                            rules_set.append(rule)
        return rules_set

    def contains(self, rule_type=None, capability=None, tag=None, code_symbol=None):
        for rule in self.rules:
            if rule.rule_type == rule_type or rule_type is None:
                if rule.capability == capability or capability is None:
                    for rtag in rule.tag_statement:
                        rtag = rtag.strip("@")
                        if rtag == tag or tag is None:
                            if rule.code_symbol == code_symbol \
                                or code_symbol is None:
                                return True
        return False


class TagBase(object):
    def __init__(self):
        self.value = None

    def getValue(self):
        return self.value

    def __repr__(self):
        return self.getValue()


class TagValue(TagBase):
    def __init__(self, value, projection):
        super(TagValue, self).__init__()
        self.value = value
        self.projection = projection
    
    def getProj(self):
        return self.projection
    
    def __repr__(self):
        return "(" + self.getValue() + ", " + self.getProj() + ")"


class TagThen(TagBase):
    def __init__(self):
        super(TagThen, self).__init__()
        self.value = "then"


class TagStatement(object):
    def __init__(self, pieces=[], tag_stmt=[]):
        self.pieces = pieces
        self.tag_stmt = tag_stmt
        self.tags = []
        self.attrs = []
        self.ptr = 0
        self.parse()
        self.check()
    
    def unique_add(self, lst, itm):
        if itm not in lst:
            lst.append(itm)
    
    def check(self):
        for part in self.pieces:
            if isinstance(part, TagThen):
                self.unique_add(self.attrs, "then")
            else:
                self.tags.append(part)

    def parse(self):
        pieces = []
        piece_buf = TagValue(None, None)
        end = False
        for x in self.tag_stmt:
            if '@' in x:
                x = x.strip("@")
                piece_buf.value = x
            elif ':' in x:
                x = x.strip(':')
                if '!' in x:
                    x = x.strip('!')
                    end = True
                piece_buf.projection = x
                pieces.append(piece_buf)
                piece_buf = TagValue(None, None)
                if end:
                    break
            elif ".then" in x:
                pieces.append(TagThen())
            else:
                raise Exception("Tag stmt parse error: " + str(self.tag_stmt) + ": " + str(x))
        if pieces:
            self.pieces = pieces

    def size(self):
        return len(self.pieces)

    def tag_size(self):
        return len(self.tags)

    def hasAttr(self, name):
        return name.lower() in self.attrs

    def get(self, i):
        return self.pieces[i]

    def fst(self):
        return TagStatement(pieces=[self.tags[0]])

    def snd(self):
        if len(self.tags) > 1:
            return TagStatement(pieces=[self.tags[1]])
        else:
            raise Exception("Tail on single-tag statement")

    def tail(self):
        if len(self.tags) > 1:
            idx = 1
            for i, itm in enumerate(self.pieces):
                if isinstance(itm, TagThen):
                    idx = i + 1
                    break
            return TagStatement(pieces=self.pieces[idx:])
        else:
            raise Exception("Tail on single-tag statement")

    def isa(self, tagstmt):
        for x in self.pieces:
            for y in tagstmt.pieces:
                if x.getValue() != y.getValue():
                    return False
        return True

    def join(self):
        res = []
        for x in self.tags:
            buf = x.getValue()
            if x.getProj() == "secrecy":
                buf += PROJ0_NAME
            elif x.getProj() == "integrity":
                buf += PROJ1_NAME
            else:
                buf += PROJB_NAME
            res.append(buf)
        return "_".join(res)

    def reset(self):
        self.ptr = 0
    
    def __repr__(self):
        outstr = "["
        for part in self.pieces:
            outstr += str(part) + ", "
        return outstr + "]"


class FlnRule(object):
    """ The rule class stores a rule."""
    def __init__(self, rule, code_symbol, type_specifier, line):
        self.rule_type = None
        self.code_symbol = code_symbol
        self.type_specifier = type_specifier
        self.line = line
        self.tag_statement = None
        self.capability = None
        self.cap_specifier = None
        self.struct_members = []
        self.is_ptr = 0
        self.parse(rule)
    
    def rule_error(self, msg, code):
        raise Exception("Error Code " + str(code) + ": " + str(msg))
    
    def parse_rule(self, rule):
        rule_parts = []
        in_part = False
        buf = ""
        start_set = ['#', ':', '@', '(', '{', '.']
        end_set = [' ', ',', ')', '}']
        exclude = ['{']
        for i, char in enumerate(list(rule)):
            if in_part:
                if char in end_set:
                    if char == ',':
                        buf += "!"
                    in_part = False
                    if buf:
                        rule_parts.append(buf)
                    buf = ""
                elif char in start_set:
                    if buf:
                        rule_parts.append(buf)
                    buf = ""
                    if char not in exclude:
                        buf += char
                elif i == len(list(rule)) - 1:
                    buf += char
                    rule_parts.append(buf)
                else:
                    buf += char
            else:
                if char in start_set:
                    if char not in exclude:
                        buf += char
                    in_part = True
        return rule_parts
    
    def parse_rule_parts(self, rule_parts):
        self.rule_type = rule_parts[0].strip('#')
        if self.rule_type not in ['param', 'return', 'requires']:
            self.rule_error(rule_parts, 0)
        ptr = 1
        struct_members = []
        member_idx = -1
        while ptr < len(rule_parts):
            if rule_parts[ptr].startswith('('):
                self.cap_specifier = rule_parts[ptr].strip('(')
            if rule_parts[ptr].startswith('.'):
                field_name = rule_parts[ptr].strip('.')
                ptr += 1
                field_type = rule_parts[ptr].strip(':')
                struct_members.append(':'.join([field_type, field_name]))
                member_idx += 1
            if rule_parts[ptr].startswith('@'):
                if struct_members:
                    struct_members[member_idx] = (struct_members[member_idx], 
                                                  TagStatement(tag_stmt=rule_parts[ptr:]))
                else:
                    self.tag_statement = TagStatement(tag_stmt=rule_parts[ptr:])
                    break
            ptr += 1
        if struct_members:
            self.struct_members = struct_members

    def parse(self, rule):
        """ Parse the rule string into its components."""
        if '*' in self.type_specifier:
            self.is_ptr = True
            self.type_specifier = self.type_specifier.strip('*')
        pts = self.parse_rule(rule)
        self.parse_rule_parts(pts)
        if self.tag_statement:
            self.capability = self.tag_statement.get(0).getProj()
        else:
            self.capability = self.struct_members[0][1].getProj()

    def __repr__(self):
        """ Output the rule."""
        return    " " + self.rule_type \
                + " " + (str(self.tag_statement) if not self.struct_members else '') \
                + " " + str(self.cap_specifier) \
                + " " + str(self.struct_members) \
                + " " + self.type_specifier \
                + " " + ('*'*self.is_ptr if self.is_ptr else '') \
                + " " + self.code_symbol \
                + " " + str(self.line)
