""" Fln Code Generator
@author Darion Cassel
"""
from fln_config import *
from fln_rule import FlnRule, FlnRuleSet, TagStatement, TagThen
from pycparser import c_ast


class CCodeGenerator(object):
    def new_var(self, name, parent=None):
        var = c_ast.ID(name)
        var.parent = parent
        return var

    def new_ivar(self, name, init, c_type, parent=None):
        var_type = c_ast.IdentifierType([c_type])
        decl_type = c_ast.TypeDecl(name, [], var_type)
        var = c_ast.Decl(name, [], [], [], decl_type, init, None)
        var.parent = parent
        var_type.parent = var
        decl_type.parent = var
        init.parent = var
        return var

    def new_fcall(self, fname, args, parent=None, set_args_parent=True):
        fname = c_ast.ID(fname)
        args_list = []
        for arg in args:
            if isinstance(arg, str):
                args_list.append(c_ast.ID(arg))
            else:
                args_list.append(arg)
        args = c_ast.ExprList(args_list)
        fc = c_ast.FuncCall(fname, args)
        fc.parent = parent
        fname.parent = fc
        args.parent = fc
        if set_args_parent:
            for a in args:
                a.parent = args
        return fc

    def new_const(self, c_type, val, parent=None):
        c = c_ast.Constant(c_type, val)
        c.parent = parent
        return c

    def new_condop(self, op, lval, rval, parent=None):
        bo = c_ast.BinaryOp(op, lval, rval)
        bo.parent = parent
        lval.parent = bo
        rval.parent = bo
        return bo

    def new_if(self, cond, iftrue, iffalse, parent=None):
        c_if = c_ast.If(cond, iftrue, iffalse)
        c_if.parent = parent
        iftrue.parent = c_if
        iffalse.parent = c_if
        return c_if

    def new_namedinit(self, names, exprs, parent=None):
        ni = c_ast.NamedInitializer(names, exprs)
        ni.parent = parent
        for n in names:
            n.parent = ni
        for e in exprs:
            e.parent = ni
        return ni

    def new_ilist(self, exprs, parent=None):
        il = c_ast.InitList(exprs)
        il.parent = parent
        for e in exprs:
            e.parent = il
        return il
    
    def new_structRef(self, name, a_type, field, parent=None):
        sr = c_ast.StructRef(name, a_type, field)
        sr.parent = parent
        field.parent = sr
        return sr
    
    def new_assign(self, lval, rval, parent=None):
        a = c_ast.Assignment('=', lval, rval)
        a.parent = parent
        lval.parent = a
        rval.parent = a
        return a

    def tag_type(self, tag_stmt):
        return tag_stmt.join()

    def fln_type(self, tag, base_type, projection=None):
        """ Base type name generator.
                #fln_keyword :capability @tag
                base_type var_name;
            ->
                __fln___tag_base_type var name;
        """
        if "::" in base_type:
            base_type = base_type.replace("::", "_")
        return "__fln__" + tag + "_" + base_type

    def struct(self, lift_type, base_type):
        """ Generate a typedef struct to represent a new FLN type.
            typedef stuct {base type data} fln_type
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        return "typedef struct {" + base_type + " d; } " \
                + lift_type + ";"
    
    def struct_p(self, lift_type, base_type, members):
        """ Generate a typedef struct to represent a new FLN type.
            typedef stuct {base type data} fln_type
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        fln_type = lift_type.split("_".join(base_type.split(" ")))[0]
        member_str = ""
        for member in members:
            c_type, member = member.split(":")
            member_str +=  fln_type + c_type + " " + member + "; "
        return "typedef struct {" + base_type + " d; " + member_str + "} " \
                + lift_type + ";"

    def read(self, lift_type, base_type, name):
        """ Generate a FLN type read function.
            fln_type -> base_type
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        fn_name = READ_NAME_S
        if name:
            fn_name = name + "_r"
        if "__fln_" in base_type:
            return base_type + " " + lift_type + "_" + fn_name + "(" \
                    + lift_type + " x) { " + base_type \
                    + " y = { .d = x.d }; return y; }"
        else:
            return base_type + " " + lift_type + "_" + fn_name + "(" \
                    + lift_type + " x) { return x.d; }"

    def read_ptr(self, lift_type, base_type, name):
        """ Generate a FLN type read ptr function.
            fln_type* -> base_type*
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        fn_name = READP_NAME_S
        if name:
            fn_name = name+"_r_ptr"
        if "__fln_" in base_type:
            return base_type + "* " + lift_type + "_" + fn_name + "(" \
                    + lift_type + "* x) { " + base_type \
                    + " tmp = { .d = x->d }; " + base_type \
                    + "* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }" # Questionable change: x->d => x.d (maybe revert)
        else:
            return base_type + "* " + lift_type + "_" + fn_name + "(" \
                    + lift_type + "* x) { return &x->d; }"

    def write(self, lift_type, base_type, name):
        """ Generate a FLN type write function.
            base_type -> fln_type
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        fn_name = WRITE_NAME_S
        if name:
            fn_name = name + "_w"
        if "__fln_" in base_type:
            return lift_type +  " " + lift_type \
                    + "_" + fn_name + "(" + base_type + " x) {" \
                    + lift_type + " y = { .d = x.d }; return y; }"
        else:
            return lift_type +  " " + lift_type \
                    + "_" + fn_name + "(" + base_type + " x) {" \
                    + lift_type + " y = { .d = x }; return y; }"
    
    def write_ptr(self, lift_type, base_type, name):
        """ Generate a FLN type write function.
            base_type* -> fln_type*
        """
        if "::" in base_type:
            base_type = base_type.replace("::", " ")
        fn_name = WRITEP_NAME_S
        if name:
            fn_name = name + "_w_ptr"
        if "__fln_" in base_type:
            # + lift_type + "* y; y->d = x->d; return y; }" \
            return lift_type +  "* " + lift_type \
                    + "_" + fn_name + "(" + base_type + "* x) {" \
                    + lift_type + " tmp = { .d = x->d }; " + lift_type \
                    + "* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }"
        else:
            # + lift_type + "* y; y->d = *x; return y; }"
            return lift_type +  "* " + lift_type \
                    + "_" + fn_name + "(" + base_type + "* x) {" \
                    + lift_type + " tmp = { .d = *x }; " + lift_type \
                    + "* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }"

    def write_wrapper(self, lift_type, var_name):
        """ Wrapper for write capability.
            base_type -> fln_type
        """
        return lift_type + GEN_WRITE_NAME + "(" + var_name + ")"
    
    def write_ptr_wrapper(self, lift_type, var_name):
        """ Wrapper for write capability.
            base_type* -> fln_type*
        """
        return lift_type + GEN_WRITEP_NAME + "(" + var_name + ")"

    def read_wrapper(self, lift_type, var_name):
        """ Wrapper for read capability.
            fln_type -> base_type
        """
        return lift_type + GEN_READ_NAME + "(" + var_name + ")"

    def read_ptr_wrapper(self, lift_type, var_name):
        """ Wrapper for read capability.
            fln_type* -> base_type*
        """
        return lift_type + GEN_READP_NAME + "(" + var_name + ")"

    def build_pairs_inner(self, rule, tag_stmt):
        pairs = [] # [(lift_type, base_type, projection, name, struct_members)]
        full = tag_stmt.join()
        if tag_stmt.hasAttr("then"):
            size = tag_stmt.tag_size()
            fst = tag_stmt.fst().join()
            snd = tag_stmt.snd().join()
            # if size > 2:
            tail = tag_stmt.tail().join()
            pairs.append((self.fln_type(full, rule.type_specifier),
                          self.fln_type(tail, rule.type_specifier),
                          "tail"))
            pairs.append((self.fln_type(full, rule.type_specifier),
                          self.fln_type(fst, rule.type_specifier),
                          "fst"))
            pairs.append((self.fln_type(full, rule.type_specifier),
                          self.fln_type(snd, rule.type_specifier),
                          "snd"))
            i = tag_stmt.size() - 1
            buf = []
            while i >= 0:
                cur = tag_stmt.get(i)
                if not isinstance(cur, TagThen):
                    buf.append(cur)
                    pairs.append((self.fln_type(TagStatement(pieces=[cur]).join(),
                                                rule.type_specifier),
                                                rule.type_specifier, None))
                    pairs.append((self.fln_type(TagStatement(pieces=list(reversed(buf))).join(),
                                                rule.type_specifier),
                                                rule.type_specifier, None))
                i -= 1
            if size > 2:
                pairs.extend(self.build_pairs_inner(rule, tag_stmt.tail()))
        pairs.append((self.fln_type(full, rule.type_specifier),
                      rule.type_specifier, None))
        new_pairs = []
        for pair in pairs:
            if len(pair) == 3:
                lift_type, base_type, name = pair
            elif len(pair) == 4:
                lift_type, base_type, name, _ = pair
            else:
                raise Exception("Invalid pair found: " + str(pair))
            if base_type != "void":
                for member in rule.struct_members:
                    c_type, member = member.split(":")
                    new_pairs.append((self.fln_type(full, c_type), c_type, None, []))
                new_pairs.append((lift_type, base_type, name, rule.struct_members))
        return new_pairs

    def build_pairs(self, rules_clean):
        """ Determine the set of unique lift_type, base_type pairs in
        the rules for header generation.
        """
        tag_type_pairs = []
        for (__, rules_set) in rules_clean.items():
            for rule in rules_set:
                pairs = []
                tag_stmt = rule.tag_statement
                pairs.extend(self.build_pairs_inner(rule, tag_stmt))
                for pair in pairs:
                    if pair not in tag_type_pairs:
                        tag_type_pairs.append(pair)
        return tag_type_pairs
    
    def has_qual(self, base_type):
            c_quals = ["const::", "volatile::", "signed::", "unsigned::", "short::", "long::"]
            for qual in c_quals:
                if qual in base_type:
                    return True
            return False

    def generate_header(self, rules_clean, new_types, new_structs):
        """ Generate the header lines."""
        header_lines = []
        structs = []
        functions = []
        c_types = ["int", "float", "char", "bool", "double", "long", "size_t", "uint64_t", "uint8_t"]
        c_types.extend(new_types)
        c_types.extend(["struct::" + x for x in new_structs])
        for lift_type, base_type, name, members in self.build_pairs(rules_clean):
            if base_type in c_types or self.has_qual(base_type):
                if members is []:
                    structs.append(self.struct(lift_type, base_type))
                else:
                    structs.append(self.struct_p(lift_type, base_type, members))
            # if "const" not in base_type:
            functions.append(self.write(lift_type, base_type, name))
            functions.append(self.write_ptr(lift_type, base_type, name))
            functions.append(self.read(lift_type, base_type, name))
            functions.append(self.read_ptr(lift_type, base_type, name))
        header_lines.extend(structs)
        header_lines.extend(functions)
        return header_lines
