""" Fln AST Transformer
@author Darion Cassel
"""

from fln_config import *
from copy import copy, deepcopy
from fln_rule import FlnRule, FlnRuleSet, TagStatement
from fln_codegen import CCodeGenerator
from pycparser import c_ast


class BuildParents(c_ast.NodeVisitor):
    def visitor(self, node):
        for child in node:
            child.parent = node
            self.visitor(child)

    def visit_FileAST(self, node):
        self.visitor(node)


class DebugFuncDefVisit(c_ast.NodeVisitor):
    """ Outputs pertinent information about every function
    definition.
    """
    def __init__(self):
        self.node = None

    def visit_FuncDef(self, node):
        """ Output function definition parts."""
        self.node = node
        print "Parent:", node.parent.__class__.__name__
        decl = node.decl
        print "Name:", decl.name
        print "Quals:", decl.quals
        print "Storage:", decl.storage
        print "Spec:"
        for spec in decl.funcspec:
            print "    ", spec
        print "Args:"
        if decl.type.args is not None:
            for param in decl.type.args.params:
                if type(param.type.type).__name__ == "TypeDecl":
                    print "    ", param.type.type.type.names[0]
                else:
                    print "    ", param.type.type.names[0]
                    print "    ", param.name
        print "Ret type:", decl.type.type.type.names[0]
        print "Init:", decl.init
        print "Bitsize:", decl.bitsize
        print ""


class IDVisitor(c_ast.NodeVisitor):
    def __init__(self, func=None, args=[]):
        self.result = []
        self.func = func
        self.args = args

    def visit_ID(self, node):
        res = self.func(node, self.args)
        if res:
            self.result.append(res)


class DeclVisitor(c_ast.NodeVisitor):
    def __init__(self, func=None, args=[]):
        self.result = []
        self.func = func
        self.args = args

    def visit_Decl(self, node):
        res = self.func(node, self.args)
        if res:
            self.result.append(res)


class ReturnVisitor(c_ast.NodeVisitor):
    def __init__(self, func=None, args=[]):
        self.result = []
        self.func = func
        self.args = args

    def visit_Return(self, node):
        res = self.func(node, self.args)
        if res:
            self.result.append(res)


class AssignVisitor(c_ast.NodeVisitor):
    def __init__(self, func=None, args=[]):
        self.result = []
        self.func = func
        self.args = args

    def visit_Assignment(self, node):
        res = self.func(node, self.args)
        if res:
            self.result.append(res)


class FCallVisitor(c_ast.NodeVisitor):
    def __init__(self, func=None, args=[]):
        self.result = []
        self.func = func
        self.args = args

    def visit_FuncCall(self, node):
        res = self.func(node, self.args)
        if res:
            self.result.append(res)


class BoundedVisitor(object):
    def __init__(self, target, start_idx=0, func=None, on_result=None, args=[]):
        self.target = target
        self.start_idx = start_idx
        self.func = func
        self.on_result = on_result
        self.args = args
    
    def process(self, c_name, node, idx):
        results = []
        if isinstance(node, self.target):
            args = copy(self.args)
            args.append(c_name)
            args.append(idx)
            if len(args) != 3:
                raise Exception("Bounded visitor arg check failed")
            res = self.func(node, args)
            if res:
                results.append(res)
        for (c_name, child) in node.c_iter():
            res = self.process(c_name, child, idx)
            if res:
                results.extend(res)
        return results
        

    def visit(self, node):
        results = []
        if isinstance(node, c_ast.FuncDef):
            if node.body is not None and node.body.block_items is not None:
                for idx, itm in enumerate(node.body.block_items):
                    if idx >= self.start_idx:
                        res = self.process("exprs[%s]" % idx, itm, idx)
                        if res:
                            results.extend(res)
                if self.on_result and results:
                    self.on_result(node, results)


class Visitor_p(object):
    def __init__(self, c_ast_class, start_idx=0, func=None, on_result=None, args=[]):
        self.c_ast_class = c_ast_class
        self.result = []
        self.start_idx = start_idx
        self.func = func
        self.on_result = on_result
        self.args = args
    
    def visit_inner(self, compound):
        if compound.block_items is not None:
            for idx, itm in enumerate(compound.block_items):
                if idx >= self.start_idx and \
                    (self.c_ast_class is None or isinstance(itm, self.c_ast_class)):
                    self.args[-1] = idx
                    if self.func:
                        res = self.func(itm, self.args)
                        if res:
                            self.result.append(res)
                if isinstance(itm, c_ast.For):
                    if isinstance(itm.stmt, c_ast.Compound):
                        self.visit_inner(itm.stmt)
                if isinstance(itm, c_ast.While):
                    if isinstance(itm.stmt, c_ast.Compound):
                        self.visit_inner(itm.stmt)
                if isinstance(itm, c_ast.DoWhile):
                    if isinstance(itm.stmt, c_ast.Compound):
                        self.visit_inner(itm.stmt)
                if isinstance(itm, c_ast.If):
                    if isinstance(itm.iftrue, c_ast.Compound):
                        self.visit_inner(itm.iftrue)
                    if isinstance(itm.iffalse, c_ast.Compound):
                        self.visit_inner(itm.iffalse)
                if isinstance(itm, c_ast.Compound):
                    self.visit_inner(itm)

    def visit(self, node):
        if isinstance(node, c_ast.FuncDef):
            if node.body is not None and node.body.block_items is not None:
                self.args.append(node)
                self.args.append(-1)
                self.visit_inner(node.body)
                if self.result and self.on_result:
                    self.on_result(node, self.result)


class FDefTransform(c_ast.NodeVisitor):
    def __init__(self, rules):
        self.rules = rules
        self.gen = CCodeGenerator()
    
    def get_compound(self, node):
        curr = node
        while not isinstance(curr, c_ast.Compound) and curr is not None:
            curr = curr.parent
        if curr == node:
            return None
        return curr
    
    def insert_before(self, new_node, insert_node):
        compound = self.get_compound(insert_node)
        if compound:
            i = 0
            while i < len(compound.block_items):
                if compound.block_items[i] == insert_node:
                    compound.block_items.insert(i, new_node)
                    return True
                i += 1
        return False
    
    def insert_after(self, new_node, insert_node):
        compound = self.get_compound(insert_node)
        if compound:
            i = 0
            while i < len(compound.block_items):
                if compound.block_items[i] == insert_node:
                    compound.block_items.insert(i+1, new_node)
                    return True
                i += 1
        return False

    def replace_with(self, new_node, old_node):
        compound = self.get_compound(old_node)
        if compound:
            i = 0
            while i < len(compound.block_items):
                if compound.block_items[i] == old_node:
                    compound.block_items[i] = new_node
                    return True
                i += 1
        return False

    def replace_all_ids(self, old_name, new_name, after_node):
        compound = self.get_compound(after_node)
        start_replacing = False
        if compound:
            def replace_inner(node, args):
                old_name = args[0]
                new_name = args[1]
                if node.name == old_name:
                    node.name = new_name
            iv = IDVisitor(func=replace_inner, args=[old_name, new_name])
            i = 0
            while i < len(compound.block_items):
                if start_replacing:
                    iv.visit(compound.block_items[i])
                if compound.block_items[i] == after_node:
                    start_replacing = True
                i += 1

    def provides_read_base(self, rules):
        """
        @rules [#provides :read(?)]
        - Develop position matrix
        """
        pos = {} # {param.indx: tag_statement}
        for rule in rules:
            if rule.cap_specifier is not None:
                if pos.get(rule.cap_specifier, False) or pos.get(-1, False):
                    raise Exception("Redefined tag for parameter " + str(pos))
                else:
                    pos[int(rule.cap_specifier)-1] = rule.tag_statement, rule.capability
            else:
                if pos.get(-1, False):
                    raise Exception("Redefined tag for parameter")
                else:
                    pos[-1] = rule.tag_statement, rule.capability
        return pos
    
    def provides_read_param(self, pos, node):
        """
        @rules [#provides :read(?)]
        - Transform parameters
        """
        uncast = {} # {param.name: (c_type, fln_type, isPtr?)}
        def inner1(node):
            if isinstance(node, c_ast.TypeDecl):
                if isinstance(node.type, c_ast.IdentifierType):
                    new_type = []
                    new_type.extend(node.quals)
                    new_type.extend(node.type.names)
                    return "_".join(new_type)
                elif isinstance(node.type, c_ast.Struct):
                    new_type = []
                    new_type.extend(node.quals)
                    new_type.append("struct")
                    new_type.append(node.type.name)
                    return "_".join(new_type)
                else:
                    raise Exception("Param c_type not found 1")
            elif isinstance(node, c_ast.PtrDecl):
                return inner1(node.type)
            else:
                raise Exception("Param c_type not found 2")
        def inner2(param, tag, name, ptrs):
            if isinstance(param.type, c_ast.TypeDecl):
                quals = param.type.quals
                param.type.quals = []
                if isinstance(param.type.type, c_ast.IdentifierType):
                    new_type = []
                    new_type.extend(quals)
                    new_type.extend(param.type.type.names)
                    c_type = " ".join(new_type) + "*"*ptrs
                    uncast[name] = (c_type, tag, False if ptrs == 0 else True)
                    param.type.type.names = [tag]
                elif isinstance(param.type.type, c_ast.Struct):
                    new_type = []
                    new_type.extend(quals)
                    new_type.append("struct")
                    new_type.append(param.type.type.name)
                    c_type = " ".join(new_type) + "*"*ptrs
                    uncast[name] = (c_type, tag, False if ptrs == 0 else True)
                    param.type.type = c_ast.IdentifierType([tag])
                else:
                    raise Exception("Param c_type not found 3: " + str(type(param.type.type)))
            elif isinstance(param.type, c_ast.PtrDecl):
                return inner2(param.type, tag, name, ptrs + 1)
            else:
                raise Exception("Param c_type not found 4: " + str(type(param.type)))
        if node.decl.type.args is not None:
            for indx, param in enumerate(node.decl.type.args.params):
                if pos.get(-1, False):
                    if pos[-1][1] == READ_NAME:
                        projection = 0
                    elif pos[-1][1] == WRITE_NAME:
                        projection = 1
                    else:
                        raise Exception("Invalid projection found 1:" + pos[-1][1])
                    tag = self.gen.fln_type(self.gen.tag_type(pos[-1][0]), 
                                            inner1(param.type),
                                            projection) 
                    inner2(param, tag, param.name, 0)
                elif pos.get(indx, False):
                    if pos[indx][1] == READ_NAME:
                        projection = 0
                    elif pos[indx][1] == WRITE_NAME:
                        projection = 1
                    else:
                        raise Exception("Invalid projection found 2: " + pos[indx][1])
                    tag = self.gen.fln_type(self.gen.tag_type(pos[indx][0]), 
                                            inner1(param.type),
                                            projection)
                    inner2(param, tag, param.name, 0)
        return uncast

    def provides_read_uncast(self, uncast, node):
        """
        @rules [#provides :read(?)]
        - Add uncasts
        - Rewrite var names
        """
        new_nodes = []
        replacement = {}
        for var, (c_type, fln_type, is_ptr) in uncast.items():
            fcall = None
            name_p = var + "__fln_p"
            replacement[var] = name_p
            if is_ptr:
                fcall = self.gen.new_fcall(fln_type+GEN_READP_NAME, [var])
                ivar = self.gen.new_ivar(name_p, fcall, c_type,
                                         parent=node.body) 
            else:
                fcall = self.gen.new_fcall(fln_type+GEN_READ_NAME, [var])
                ivar = self.gen.new_ivar(name_p, fcall, c_type,
                                         parent=node.body)
            new_nodes.append(ivar)
        def replace(node, args):
            replacement = args[0]
            if replacement.get(node.name, False):
                if not (isinstance(node.parent, c_ast.StructRef) and \
                    node.parent.field.name == node.name):
                    node.name = replacement[node.name]
        if hasattr(node.body, "block_items") and node.body.block_items is not None:
            for itm in node.body.block_items:
                iv = IDVisitor(func=replace, args=[replacement])
                iv.visit(itm)
            for n in new_nodes:
                node.body.block_items.insert(0, n)

    def provides_write(self, rules, node):
        """
        - Change return type
        - Add cast to return
        """
        if len(rules) == 1:
            rule = rules[0]
            tag = self.gen.tag_type(rule.tag_statement)
            if rule.capability == READ_NAME:
                projection = 0
            elif rule.capability == WRITE_NAME:
                projection = 1
            else:
                raise Exception("Invalid projection found 3: " + str(rule.capability))
            write_ptr = False
            if isinstance(node.decl.type.type, c_ast.TypeDecl):
                if isinstance(node.decl.type.type.type, c_ast.Struct):
                    c_type = node.decl.type.type.type.name
                elif isinstance(node.decl.type.type.type, c_ast.IdentifierType):
                    c_type = "_".join(node.decl.type.type.type.names)
                else:
                    raise Exception("Unhandled c_type class 1: {0}".format(str(type(node.decl.type.type.type.type))))
                fln_type = self.gen.fln_type(tag, c_type, projection)
                node.decl.type.type.type.names = [fln_type]
            elif isinstance(node.decl.type.type, c_ast.PtrDecl):
                write_ptr = True
                if isinstance(node.decl.type.type.type.type, c_ast.TypeDecl):
                    c_type = "_".join(node.decl.type.type.type.type.type.names)
                else:
                    if isinstance(node.decl.type.type.type.type, c_ast.TypeDecl):
                        c_type = "_".join(node.decl.type.type.type.type.names)
                    elif isinstance(node.decl.type.type.type.type, c_ast.Struct):
                        c_type = node.decl.type.type.type.type.name
                    elif isinstance(node.decl.type.type.type.type, c_ast.IdentifierType):
                        c_type = "_".join(node.decl.type.type.type.type.names)
                    else:
                        raise Exception("Unhandled c_type class: {0}".format(str(type(node.decl.type.type.type.type))))
                fln_type = self.gen.fln_type(tag, c_type, projection)
                node.decl.type.type.type.type.names = [fln_type]
            else:
                raise Exception("Unhandled provides write ctype")
            if write_ptr:
                gen_name = GEN_WRITEP_NAME
            else:
                gen_name = GEN_WRITE_NAME
            def cast(node, args):
                gen = CCodeGenerator()
                fln_type = args[0]
                if isinstance(node.expr, c_ast.Constant):
                    fc = gen.new_fcall(fln_type+gen_name, [node.expr.value])
                elif isinstance(node.expr, c_ast.ID):
                    fc = gen.new_fcall(fln_type+gen_name, [node.expr.name])
                elif isinstance(node.expr, c_ast.StructRef):
                    fc = gen.new_fcall(fln_type+gen_name, [node.expr])
                elif isinstance(node.expr, c_ast.BinaryOp):
                    fc = gen.new_fcall(fln_type+gen_name, [node.expr])
                elif isinstance(node.expr, c_ast.ArrayRef):
                    fc = gen.new_fcall(fln_type+gen_name, [node.expr])
                else:
                    raise Exception("Unsupported return class: " + node.expr.__class__.__name__)
                fc.parent = node
                node.expr = fc
            rv = ReturnVisitor(func=cast, args=[fln_type])
            rv.visit(node)
        elif len(rules) > 1:
            raise Exception("Multiple write rules found")

    def requires_transform_base(self, node, rules_set):
        """
        - Return requires var names to original state
        - Extracts C type
        """
        c_type = None
        field_members = []
        for rule in rules_set.rules:
            if rule.struct_members:
                for member in rule.struct_members:
                    member = member.split(":")[1]
                    field_members.append(member)
        if isinstance(node.type, c_ast.TypeDecl):
            quals = node.type.quals
            node.type.quals = []
            if isinstance(node.type.type, c_ast.IdentifierType):
                quals.extend(node.type.type.names)
                c_type = "_".join(quals)
            elif isinstance(node.type.type, c_ast.Struct):
                quals.append("struct")
                quals.append(node.type.type.name)
                c_type = "_".join(quals)
            else:
                raise Exception("Unhandled inner node type")
            if "__fln_" in node.type.declname:
                node.type.declname = node.type.declname.split("__fln_")[0]
                node.name = node.type.declname.split("__fln_")[0]
            else:
                raise Exception("Invalid requires type decl name reached")
            if node.init is not None:
                regular_init =[]
                nested_init = []
                for field in node.init.exprs:
                    if field.name[0].name not in field_members:
                        nested_init.append(field)
                    else:
                        regular_init.append(field)
                member = self.gen.new_var("d")
                ni = self.gen.new_namedinit([member], 
                                            self.gen.new_ilist(nested_init))
                regular_init.append(ni)
                il = self.gen.new_ilist(regular_init, parent=node)
                node.init = il
        elif isinstance(node.type, c_ast.PtrDecl):
            quals = node.type.type.quals
            node.type.type.quals = []
            if isinstance(node.type.type.type, c_ast.Struct):
                quals.append("struct")
                quals.append(node.type.type.type.name)
                c_type = "_".join(quals)
            elif isinstance(node.type.type.type, c_ast.IdentifierType):
                quals.extend(node.type.type.type.names)
                c_type = "_".join(quals)
            else:
                raise Exception("Invalid requires ptr decl type name reached")
            if "__fln_" in node.type.type.declname:
                node.type.type.declname = node.type.type.declname.split("__fln_")[0]
                node.name = node.type.type.declname.split("__fln_")[0]
            else:
                raise Exception("Invalid requires ptr decl name reached")
        return c_type
    
    def requires_tranform_init(self, rules_set, c_type, node):
        """
        - Change type init to fln_type
        """
        rules = []
        read = rules_set.get(capability=READ_NAME)
        write = rules_set.get(capability=WRITE_NAME)
        if len(read) > 1 or len(write) > 1:
            raise Exception("Redefined read or write found")
        rules.extend(read)
        rules.extend(write)
        fln_type = None
        tag_stmt = None
        tag_type = None
        members = None
        is_ptr = False
        if read:
            tag_stmt = read[0].tag_statement
            tag_type = self.gen.tag_type(read[0].tag_statement)
            members = read[0].struct_members
            is_ptr = read[0].is_ptr
            projection = 0
        elif write:
            tag_stmt = write[0].tag_statement
            tag_type = self.gen.tag_type(write[0].tag_statement)
            members = write[0].struct_members
            is_ptr = write[0].is_ptr
            projection = 1
        elif read and write:
            raise Exception("Two requires rules defined")
        fln_type = self.gen.fln_type(tag_type, c_type, projection)
        if isinstance(node.type, c_ast.TypeDecl):
            if isinstance(node.type.type, c_ast.IdentifierType):
                node.type.type.names = [fln_type]
            elif isinstance(node.type.type, c_ast.Struct):
                node.type.type = c_ast.IdentifierType([fln_type])
            else:
                raise Exception("Unhandled node init type: " +
                                node.type.type.__class__.__name__)
        elif isinstance(node.type, c_ast.PtrDecl):
            if isinstance(node.type.type.type, c_ast.IdentifierType):
                node.type.type.type.names = [fln_type]
            elif isinstance(node.type.type.type, c_ast.Struct):
                node.type.type.type = c_ast.IdentifierType([fln_type])
        else:
            raise Exception("Unhandled node type: " +
                            node.type.__class__.__name__)
        return (node.name, (fln_type, bool(read), bool(write), 
                tag_stmt, members, c_type, is_ptr, FlnRuleSet(rules)))

    def requires_transform_assign_then(self, node, args):
        """
        @rules [x: #requires write]
        if write and not read and has(then):
            x = y -> { tail x'; 
                       tail z = fst->tail(y); 
                       x' = z; }
        """
        wrapper, _, _ = args
        # new_nodes = []
        # replacement = None
        root = None
        if isinstance(node.lvalue, c_ast.ID):
            root = node.lvalue
        elif isinstance(node.lvalue, c_ast.StructRef):
            root = node.lvalue.name
        elif isinstance(node.lvalue, c_ast.UnaryOp):
            root = node.lvalue.expr
        elif isinstance(node.lvalue, c_ast.ArrayRef):
            root = node.lvalue.name
        else:
            raise Exception("Unhandled assign then lvalue: " + str(type(node.lvalue)))
        if isinstance(root, c_ast.ID) or isinstance(root, c_ast.Cast):
            pass
        else:
            while not isinstance(root, c_ast.ID):
                if isinstance(root, c_ast.UnaryOp):
                    root = root.expr
                elif isinstance(root, c_ast.BinaryOp):
                    root = root.left
                elif isinstance(root, c_ast.StructRef):
                    root = root.name
                else:
                    raise Exception("Unhandled assign then lvalue: " + str(type(root)))
        if root and not isinstance(root, c_ast.Cast):
            if wrapper.get(root.name, False):
                fln_type, is_read, is_write, tag_stmt, members, c_type, is_ptr, rules_set = wrapper[root.name]
                cont = True
                if isinstance(node.rvalue, c_ast.ID):
                    if '__fln_r' in node.rvalue.name:
                        cont = False
                projection = 0 if is_read else 1
                if is_write and not is_read and tag_stmt.hasAttr("then") and cont:
                    t_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.tail()), c_type, projection)
                    latest = None
                    endt, endf = '', ''
                    if is_ptr:
                        endt, endf = '*', '_ptr'
                    wr_tail = self.gen.new_fcall(fln_type+"_tail_r"+endf, [root.name])
                    latest = self.gen.new_ivar(root.name+"__fln_t", wr_tail, t_type+endt, parent=root.parent)
                    self.insert_before(latest, root.parent)
                    if isinstance(node.rvalue, c_ast.ID):
                        if tag_stmt.tag_size() > 2:
                            wr_head = self.gen.new_fcall(t_type+"_fst_w"+endf, [node.rvalue.name])
                        else:
                            wr_head = self.gen.new_fcall(t_type+GEN_WRITE_NAME+endf, [node.rvalue.name])
                        latest = self.gen.new_ivar(root.name+"__fln_r", wr_head, t_type+endt, parent=root.parent)
                        self.insert_before(latest, root.parent)
                        node.rvalue.name = root.name+"__fln_r"
                    elif isinstance(node.rvalue, c_ast.FuncCall):
                        self.requires_transform_fcall_assign(node.rvalue, [wrapper])
                    else:
                        raise Exception("Unhandled assign then rhs type:" + str(type(node.rvalue)))
                    self.replace_all_ids(root.name, root.name+"__fln_t", latest)
                    wrapper[root.name] = (t_type, is_read, is_write, tag_stmt.tail(), members, c_type, is_ptr, rules_set)
            elif isinstance(node.rvalue, c_ast.FuncCall):
                self.requires_transform_fcall_assign(node.rvalue, [wrapper])
        elif isinstance(root, c_ast.Cast):
            pass
        else:
            raise Exception("Assignment lhs class unhandled: " + node.lvalue.__class__.__name__)
    
    def requires_transform_assign(self, node, args):
        """
        @rules [x: #requires read t] /\ !@rules [y: #requires read t]
        if read and not write:
            x = y -> x = write_wrapper(y);
        """
        wrapper = args[0]
        if isinstance(node.lvalue, c_ast.ID):
            old_name = node.lvalue.name
            if '__fln_' in node.lvalue.name:
                old_name = old_name.split('__fln_')[0]
            if wrapper.get(old_name, False):
                fln_type, is_read, is_write, _, _, _, is_ptr, _ = wrapper[old_name]
                cont = True
                if isinstance(node.rvalue, c_ast.ID):
                    if wrapper.get(node.rvalue.name, False):
                        f_type = wrapper[node.rvalue.name][0]
                        if fln_type == f_type:
                            cont = False
                if is_read and not is_write:
                    if cont:
                        if is_ptr:
                            new_rhs = self.gen.new_fcall(fln_type+GEN_WRITEP_NAME, [node.rvalue])
                        else:
                            new_rhs = self.gen.new_fcall(fln_type+GEN_WRITE_NAME, [node.rvalue])
                        new_rhs.parent = node
                        node.rvalue = new_rhs

    def requires_transform_fcall_assign(self, node, args):
        """
        @rules [x: #requires read]
        if read and not write and has(then)
            y = f(x) -> { fst x' = fst(x); 
                          y = f(x'); 
                          tail y' = snd->tail(y); }
        """
        wrapper = args[0]
        fln_type = None
        t_type = None
        is_ptr = False
        if node.args is not None:
            if isinstance(node.parent.lvalue, c_ast.ID):
                old_name = node.parent.lvalue.name
            elif isinstance(node.parent.lvalue, c_ast.UnaryOp):
                old_name = node.parent.lvalue.expr.name
            for idx, expr in enumerate(node.args.exprs):
                root = None
                if isinstance(expr, c_ast.ID):
                    root = expr
                if isinstance(expr, c_ast.StructRef):
                    root = expr.name
                if isinstance(expr, c_ast.ID) and wrapper.get(root.name, False):
                    fln_type, is_read, is_write, tag_stmt, members, c_type, is_ptr, rules_set = wrapper[root.name]
                    projection = 0 if is_read else 1
                    if is_read and not is_write and tag_stmt.hasAttr("then"):
                        f_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.fst()), c_type, projection)
                        s_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.snd()), c_type, projection)
                        t_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.tail()), c_type, projection)
                        endt, endf = '', ''
                        if is_ptr:
                            endt, endf = '*', '_ptr'
                        # Base case: tag_stmt len >= 2
                        wr_head = self.gen.new_fcall(fln_type+"_fst_r"+endf, [root.name])
                        self.insert_before(self.gen.new_ivar(root.name+"__fln_h", wr_head, f_type+endt,
                                                             parent=node.parent.parent), node.parent)
                        # Inductive case: tag_stmt len >= 3
                        if t_type != s_type:
                            wr_tail = self.gen.new_fcall(t_type+"_fst_w"+endf, [node.parent.lvalue])
                            wr = self.gen.new_ivar(old_name+"__fln_t", wr_tail, t_type+endt, parent=node.parent.parent)
                            self.insert_after(wr, node.parent)
                            self.replace_all_ids(old_name, old_name+"__fln_t", wr)
                            wrapper[old_name+'__fln_t'] = (t_type, is_read, is_write, tag_stmt.tail(), members, c_type, is_ptr, rules_set)
                        else:
                            self.replace_all_ids(old_name, old_name+"__fln_s", node.parent)
                            wrapper[old_name+'__fln_s'] = (s_type, is_read, is_write, tag_stmt.tail(), members, c_type, is_ptr, rules_set)
                        root.name = root.name+"__fln_h"
                    if is_write and not is_read:
                        if is_ptr:
                            fc = self.gen.new_fcall(fln_type+GEN_READP_NAME, [root.name], parent=node.args.exprs[idx].parent)
                        else:
                            fc = self.gen.new_fcall(fln_type+GEN_READ_NAME, [root.name], parent=node.args.exprs[idx].parent)
                        fc.parent = node.args
                        node.args.exprs[idx] = fc

    def requires_transform_fcall_then(self, node, args):
        """
        @rules [x: #requires :read]
        if read and not write and has(then):
            f(x) -> { fst x' = fst(x); 
                      snd y = f(x');
                      tail y' = snd->tail(y); }
        """
        wrapper, _, _ = args
        if node.args is not None:
            for expr in node.args.exprs:
                root = None
                if isinstance(expr, c_ast.ID):
                    root = expr
                if isinstance(expr, c_ast.StructRef):
                    root = expr.name
                if root and wrapper.get(root.name, False):
                    old_name = root.name
                    fln_type, is_read, is_write, tag_stmt, members, c_type, is_ptr, rules_set = wrapper[root.name]
                    projection = 0 if is_read else 1
                    if is_read and not is_write and tag_stmt.hasAttr("then"):
                        f_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.fst()), c_type, projection)
                        s_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.snd()), c_type, projection)
                        t_type = self.gen.fln_type(self.gen.tag_type(tag_stmt.tail()), c_type, projection)
                        endt, endf = '', ''
                        if is_ptr:
                            endt, endf = '*', '_ptr'
                        # Base case: tag_stmt len >= 2
                        name_p = root.name+"__fln_s"
                        id_replace_node = None
                        wr_head = self.gen.new_fcall(fln_type+"_fst_r"+endf, [root.name])
                        self.insert_before(self.gen.new_ivar(root.name+"__fln_h", wr_head, f_type+endt,
                                            parent=node.parent), node)
                        id_replace_node = self.gen.new_ivar(name_p, node, s_type+endt, parent=node.parent)
                        # Inductive case: tag_stmt len >= 3
                        if t_type != s_type:
                            wr_tail = self.gen.new_fcall(t_type+"_fst_w"+endf, [name_p])
                            self.insert_after(self.gen.new_ivar(root.name+"__fln_t", wr_tail, t_type+endt,
                                                                parent=node.parent), node)
                            self.replace_with(id_replace_node, node)
                            self.replace_all_ids(old_name, old_name+"__fln_t", id_replace_node)
                            wrapper[old_name+'__fln_t'] = (t_type, is_read, is_write, tag_stmt.tail(), members, c_type, is_ptr, rules_set)
                        else:
                            self.replace_with(id_replace_node, node)
                            self.replace_all_ids(old_name, old_name+"__fln_s", id_replace_node)
                            wrapper[old_name+'__fln_s'] = (s_type, is_read, is_write, tag_stmt.tail(), members, c_type, is_ptr, rules_set)
                        root.name = root.name+"__fln_h"
    
    def requires_transform_id(self, node, args):
        """
        @rules [x: #requires :write t] /\ !@rules [f: #provides :read t]
        if write and not read:
            x -> read_wrapper(x)
        """
        wrapper, c_name, my_idx = args
        if wrapper.get(node.name, False):
            fln_type, is_read, is_write, tag_stmt, members, c_type, is_ptr, _ = wrapper[node.name]
            cont = True
            if is_write and not is_read:
                # Check that !@rules [f: #provides :read t]
                if isinstance(node.parent, c_ast.ExprList):
                    rules_set = FlnRuleSet(self.rules.get(node.parent.parent.name.name, []))
                    f_reads = rules_set.get(rule_type="provides", capability=READ_NAME)
                    if f_reads:
                        f_read = f_reads[0]
                        projection = 0 if f_read.capability == "secrecy" else 1
                        f_type = self.gen.fln_type(self.gen.tag_type(f_read.tag_statement),  
                                                    f_read.type_specifier, projection)
                        if fln_type == f_type:
                            if f_read.cap_specifier and f_read.cap_specifier == my_idx:
                                cont = False
                            else:
                                cont = False
                if isinstance(node.parent, c_ast.Assignment):
                    cont = False
                if isinstance(node.parent, c_ast.StructRef):
                    if isinstance(node.parent.parent, c_ast.Assignment):
                        cont = False
                if cont:
                    if isinstance(node, c_ast.ID):
                        if is_ptr:
                            fc = self.gen.new_fcall(fln_type+GEN_READP_NAME, [node],
                                                    set_args_parent=False) 
                        else:
                            fc = self.gen.new_fcall(fln_type+GEN_READ_NAME, [node],
                                                    set_args_parent=False) 
                    if isinstance(node, c_ast.StructRef):
                        field_items = [x.split(":") for x in members]
                        base_type = None
                        for c_type, field_name in field_items:
                            if node.field.name == field_name:
                                base_type = c_type
                        if base_type:
                            member_type = self.gen.fln_type(tag_stmt.join(), base_type)
                        else:
                            raise Exception("Invalid struct member access base type")
                        if is_ptr:
                            fc = self.gen.new_fcall(fln_type+GEN_READP_NAME, [node],
                                                    set_args_parent=False) 
                        else:
                            fc = self.gen.new_fcall(member_type+GEN_READ_NAME, [node],
                                                    set_args_parent=False)
                    if c_name != 'lvalue':
                        if "[" in c_name:
                            idx = int(c_name.split("[")[1].split("]")[0])
                            fc.parent = node.parent
                            node.parent.exprs[idx] = fc
                        else:
                            setattr(node.parent, c_name, fc)
            if isinstance(node.parent, c_ast.StructRef) and isinstance(node.parent.name, c_ast.ID) \
                and node.name == node.parent.name.name:
                if members:
                    field_names = [x.split(":")[1] for x in members]
                    if node.parent.field.name not in field_names:
                        new_ref = self.gen.new_structRef(node.parent.name, node.parent.type,
                                                         self.gen.new_var("d"), parent=node.parent)
                        node.parent.name = new_ref
                        node.parent.type = "."
                else:
                    new_ref = self.gen.new_structRef(node.parent.name, node.parent.type,
                                                     self.gen.new_var("d"), parent=node.parent)
                    node.parent.name = new_ref
                    node.parent.type = "."

    def init_trans(self, node, args):
        """
        Apply base transformation to requisite nodes
        """
        rules = args[0]
        if isinstance(node.type, c_ast.TypeDecl) or \
            isinstance(node.type, c_ast.PtrDecl) or \
            isinstance(node.type, c_ast.Struct) or \
            isinstance(node.type, c_ast.ArrayDecl):
            rules_set = FlnRuleSet(rules.get(node.name, []))
            if rules_set.rules:
                c_type = self.requires_transform_base(node, rules_set)
                return self.requires_tranform_init(rules_set, c_type, node)
        elif isinstance(node.type, c_ast.FuncDecl):
            return
        else:
            raise Exception("Unhandled requires init type: " +
                            node.type.__class__.__name__)

    def visit_FuncDef(self, node):
        # Requires init transform
        dv = DeclVisitor(func=self.init_trans, args=[self.rules])
        dv.visit(node)
        # Generate wrapper matrix
        wrapper = {} # node.name: (fln_type, hasRead, hasWrite, tag_stmt, 
                     #             members, c_type, is_ptr, rules)
        for decl_info in dv.result:
            wrapper[decl_info[0]] = decl_info[1]
        # Requires fcall transform
        Visitor_p(c_ast.FuncCall,
                  func=self.requires_transform_fcall_then,
                  args=[wrapper]).visit(node)
        BoundedVisitor(c_ast.ID,
                       func=self.requires_transform_id,
                       args=[wrapper]).visit(node)
        # Requires assign transform        
        Visitor_p(c_ast.Assignment, 
                  func=self.requires_transform_assign_then,
                  args=[wrapper]).visit(node)
        BoundedVisitor(c_ast.Assignment,
                       func=self.requires_transform_assign,
                       args=[wrapper]).visit(node)
        # Provides
        rules_set = FlnRuleSet(self.rules.get(node.decl.name, []))
        # Provides read
        prov_read = rules_set.get(rule_type="param")
        pos = self.provides_read_base(prov_read)
        uncast = self.provides_read_param(pos, node)
        self.provides_read_uncast(uncast, node)
        # Provides write
        prov_write = rules_set.get(rule_type="return")
        self.provides_write(prov_write, node)


def process_fln_c(ast, rules):
    """ Helper method to trigger the calling of
        the root visitors.
    """
    BuildParents().visit(ast)
    FDefTransform(rules).visit(ast)
