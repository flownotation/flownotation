""" Fln Source Parser
@author Darion Cassel
"""

from fln_config import *
from fln_rule import FlnRule


class FlnParse(object):
    """ Parse the input file into a set of
    rules and a cleaned source representation.
    """
    def __init__(self, lines):
        self.ctr = 0
        self.lines = lines
        self.source = self.read_source()
        self.rules, typedefs, structs = self.parse_source()
        self.structs = self.process_structs(structs)
        self.typedefs = self.process_typedefs(typedefs)
        self.rules_clean = self.clean_rules()
        self.source_clean = self.clean_source()

    def read_source(self):
        """ Read in the source line by line, stripping
        out tabs, returns, and newline characters.
        """
        lines = [line.strip(' \t\n\r')
                 for line in self.lines]
        return lines

    def process_typedefs(self, typedefs):
        new_types = []
        for typedef in typedefs:
            typedef = typedef.strip().split(" ")
            if typedef[0] != "typedef":
                raise Exception("Invalid typedef parsed: " + str(typedef))
            if ";" in typedef[-1]:
                new_types.append(typedef[-1].strip(";"))
            else:
                raise Exception("Invalid typedef parsed (end): " + str(typedef))
        return new_types
    
    def process_structs(self, structs):
        new_types = []
        for struct in structs:
            struct_def = struct.strip().split(" ")
            if struct_def[0] != "struct":
                raise Exception("Invalid struct parsed: " + str(struct_def))
            if struct_def[2] == "{":
                new_types.append(struct_def[1])
            else:
                raise Exception("Invalid struct parsed (end): " + str(struct_def))
        return new_types

    def parse_source(self):
        """ Determine the rules and the "true" line
        number for each rule.
        """
        rules = {}
        src_len = len(self.source)
        in_rule = False
        rule_buffer = []
        exclude = 0
        typedefs = []
        in_typedef = False
        typedef_buf = []
        typedef_bal = 0
        structs = []
        struct_buf = []
        struct_bal = 0
        in_struct = False
        in_comment = False
        for i in range(src_len):
            line = self.source[i]
            if line.startswith("/*"):
                in_comment = True
            if not in_comment and "//" not in line:
                if line.startswith("#requires") \
                or line.startswith("#param") or line.startswith("#return"):
                    if not in_rule:
                        in_rule = True
                    rule_buffer.append(line)
                    exclude += 1
                elif in_typedef:
                    typedef_buf.append(line)
                    if "{" in line:
                        typedef_bal += 1
                    if "}" in line:
                        typedef_bal -= 1
                    if typedef_bal == 0 and ";" in line:
                        typedefs.append(" ".join(typedef_buf))
                        typedef_buf = []
                        in_typedef = False
                elif in_struct:
                    struct_buf.append(line)
                    if "{" in line:
                        struct_bal += 1
                    if "}" in line:
                        struct_bal -= 1
                    if struct_bal == 0 and ";" in line:
                        structs.append(" ".join(struct_buf))
                        struct_buf = []
                        in_struct = False
                else:
                    if line.startswith("typedef"):
                        if ";" not in line:
                            in_typedef = True
                            typedef_buf.append(line)
                            if "{" in line:
                                typedef_bal += 1
                            if "}" in line:
                                typedef_bal -= 1
                        else:
                            typedefs.append(line)
                    elif line.startswith("struct") \
                        and "{" in line:
                        if ";" not in line:
                            in_struct = True
                            struct_buf.append(line)
                            if "{" in line:
                                struct_bal += 1
                            if "}" in line:
                                struct_bal -= 1
                        else:
                            structs.append(line)
                    if in_rule:
                        in_rule = False
                        rules[(line, i-exclude+1)] = rule_buffer
                        rule_buffer = []
                        exclude = 0
            if "*/" in line:
                in_comment = False
        return rules, typedefs, structs
    
    def find_arg_types(self, code):
        arg_types = []
        if "(" in code:
            new_code = code.split("(")
            new_code = new_code[1].split(")")
            args = new_code[0]
            if args.strip() != "":
                if "," in args:
                    args = [x.strip() for x in args.split(",")]
                else:
                    args = [args]
                for a in args:
                    parts = a.split(" ")
                    if len(parts) == 1:
                        arg_types.append(parts[0])
                    elif len(parts) == 2:
                        arg_types.append(parts[0].strip().strip("*"))
                    elif len(parts) > 2:
                        i = 0
                        full_type = ""
                        while parts[i].strip() in ["struct", "const", "volatile", "signed", "unsigned", "short", "long"]:
                            full_type += parts[i].strip('*') + "::"
                            i += 1
                        full_type += parts[i].strip('*')
                        if full_type != "":
                            arg_types.append(full_type)
                        else:
                            raise Exception("Invalid C type qualifier parsed: " + parts[0])
                    else:
                        raise Exception("Invalid argument list parsed: " + str(parts))
        return arg_types

    def clean_rules(self):
        """ Clean the rules, converting each rule string to 
        a rule object.
        """
        rules_clean = {}
        qualifiers = ['static', 'inline', 'unsigned', 'signed', 'const', 'volatile', 'struct', 'short', 'long']
        for ((code, line_num), rules_set) in self.rules.items():
            arg_types = self.find_arg_types(code)
            tokens = code.split(" ")
            idx = 0
            while tokens[idx].strip() in qualifiers:
                if idx == 0:
                    type_specifier = tokens[idx]
                else:
                    type_specifier = type_specifier + '::' + tokens[idx] 
                code_symbol = tokens[idx]
                idx += 1
            if idx == 0:
                type_specifier = tokens[idx]
            else:
                type_specifier = type_specifier + '::' + tokens[idx]
            code_symbol = tokens[idx+1]
            if "(" in code_symbol:
                code_symbol = code_symbol.split("(")[0]
            if ";" in code_symbol or ";" in " ".join(tokens):
                code_symbol = code_symbol.split(";")[0].strip()
                new_symbol = code_symbol+"__fln_"+str(self.ctr)
                self.ctr += 1
                for indx, src_line in enumerate(self.source):
                    if code in src_line and line_num == indx or \
                        (line_num+1 == indx and len(rules_set) == 2):
                        code_parts = [x.strip().strip(";") for x in code.split(" ")]
                        for i, part in enumerate(code_parts):
                            if part == code_symbol:
                                code_parts[i] = new_symbol
                        new_code = " ".join(code_parts) + ";"
                        self.source[indx] = new_code
                code_symbol = new_symbol
            rules_set_new = []
            for rule in rules_set:
                if "#param" in rule and "(" not in rule:
                    for i, arg_t in enumerate(arg_types):
                        new_rule = rule.replace("#param", "#param" + "("+str(i+1)+")")
                        rules_set_new.append(FlnRule(new_rule, code_symbol, arg_t, line_num))
                elif "#param" in rule and "(" in rule:
                    idx = int(rule.split("(")[1][0]) - 1
                    rules_set_new.append(FlnRule(rule, code_symbol, arg_types[idx], line_num))
                elif "#return" in rule and type_specifier.strip() == "void":
                    raise Exception("Cannot have write rule with void return type")
                else:
                    rules_set_new.append(FlnRule(rule, code_symbol, type_specifier, line_num))
            rules_clean[code_symbol] = rules_set_new
        return rules_clean

    def output_rules(self):
        """ Output cleaned rules."""
        for (code_symbol, rules_set) in self.rules_clean.items():
            print code_symbol
            for rule in rules_set:
                print rule

    def clean_source(self):
        """ Parse the source into a pre-processable form
        by removing FLN pragmas.
        """
        src_len = len(self.source)
        source_clean = []
        for i in range(src_len):
            line = self.source[i]
            if not (line.startswith("#requires") or line.startswith("#provides")
                    or line.startswith("#return") or line.startswith("#param")):
                source_clean.append(line)
        return source_clean

    def output_clean_source(self, filename):
        """ Output the cleaned source code."""
        out_string = ""
        for line in self.source_clean:
            out_string += line
            out_string += "\n"
        with open(filename, "w") as out_file:
            out_file.write(out_string)
        return out_string
