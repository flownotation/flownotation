class AssignTransform(c_ast.NodeVisitor):
    """ Rewrite assignment statements with this rule:
        lval #has (:read /\ !:write  ||  :write /\ !:read) =>
            -| lval = rval
            -> lval = write_wrapper(rval)
    """
    def __init__(self, rules, rules_set, param_dict, capability,
                 tag, id_transform_exclude):
        self.rules = rules
        self.rules_set = rules_set
        self.param_dict = param_dict
        self.capability = capability
        self.tag = tag
        self.id_transform_exclude = id_transform_exclude

    def transform_write(self, node, type_specifier, tag):
        """ Perform transform for:
            lval #has :param tag /\ func #has :read tag /\ !(func #has :write tag)
        """
        gen = FlnCodeGenerator(type_specifier, tag)
        rval_node_type = type(node.rvalue).__name__
        # If the rval is a constant
        if rval_node_type == "Constant":
            node.rvalue.value = gen.write_wrapper(node.rvalue.value)
        # If the rval is an ID
        elif rval_node_type == "ID":
            # If the identifier is not a 'special' parameter
            if not self.param_dict.get(node.rvalue.name, False):
                node.rvalue.name = gen.write_wrapper(node.rvalue.name)
            else:
                self.id_transform_exclude.append(node.rvalue)
        elif rval_node_type == "FuncCall":
            # If the function call does not have a rule associated with it
            if not self.rules.get(node.rvalue.name.name, False):
                shell = deepcopy(node.rvalue)
                shell.name.name = gen.type_name() + "_write"
                if shell.args.exprs:
                    shell.args.exprs[-1] = node.rvalue
                else:
                    shell.args.exprs.append(node.rvalue)
                node.rvalue = shell
        else:
            raise Exception("Invalid r-value node type: " + rval_node_type)

    def transform_read(self, node, type_specifier, tag):
        """ Perform transform for:
            rval #has :param tag /\ func #has :write tag /\ !(func #has :read tag)
        """
        gen = FlnCodeGenerator(type_specifier, tag)
        # If the identifier is not a 'special' parameter
        if self.param_dict.get(node.rvalue.name, False):
            node.rvalue.name = gen.write_wrapper(node.rvalue.name)

    def visit_Assignment(self, node):
        """ Visit the assignment nodes and conditionally delegate transformations. """
        # Exclude all lvals from ID transformation
        self.id_transform_exclude.append(node.lvalue)
        # If lval #has :param tag /\ func #has :read tag /\ !(func #has :write tag)
        if type(node.lvalue).__name__ != "UnaryOp" \
            and self.rules_set.contains(rule_type="has",
                                        capability="param",
                                        tag=self.tag,
                                        code_symbol=node.lvalue.name) \
            and self.capability == "read" \
            and not self.rules_set.contains(capability="write", tag=self.tag):
            self.transform_write(node, self.param_dict[node.lvalue.name][0], self.tag)
        # If rval #has :param tag /\ func #has :write tag /\ !(func #has :read tag)
        if type(node.rvalue).__name__ == "ID" \
            and self.rules_set.contains(rule_type="has",
                                        capability="param",
                                        tag=self.tag,
                                        code_symbol=node.rvalue.name) \
            and self.capability == "write" \
            and not self.rules_set.contains(capability="read", tag=self.tag):
            self.transform_read(node, self.param_dict[node.rvalue.name][0], self.tag)


class IDTransform(c_ast.NodeVisitor):
    """ Transform ID nodes according to this rule:
        if ID #has :param tag /\ func #has :read tag =>
            -| ID
            -> read_wrapper(ID)
    """
    def __init__(self, rules_set, param_dict, capability,
                 tag, id_transform_exclude):
        self.rules_set = rules_set
        self.param_dict = param_dict
        self.capability = capability
        self.tag = tag
        self.id_transform_exclude = id_transform_exclude

    def transform_read(self, node, type_specifier, tag):
        """ ID -> read_wrapper(ID) """
        gen = FlnCodeGenerator(type_specifier[0], tag)
        if type_specifier[1]:
            node.name = gen.read_ptr_wrapper(node.name)
        else:
            node.name = gen.read_wrapper(node.name)

    def visit_ID(self, node):
        """ if ID #has :param tag /\ func #has :read tag """
        if node not in self.id_transform_exclude \
            and self.rules_set.contains(rule_type="has",
                                        capability="param",
                                        tag=self.tag,
                                        code_symbol=node.name) \
            and self.rules_set.contains(rule_type="has",
                                        capability="read",
                                        tag=self.tag):
            print self.param_dict
            # self.transform_read(node, self.param_dict[node.name], self.tag)


class DeclTransform(c_ast.NodeVisitor):
    """ Transform declarations according to this rule:
        if decl has rule:
            -| ctype var_name
            -> fln_type var_name
    """
    def __init__(self, rules, parent_rules_set):
        self.rules = rules
        self.parent_rules_set = parent_rules_set
        self.rules_set = None

    def transform_requires(self, node, tag):
        """ ctype var_name -> fln_type var_name """
        gen = FlnCodeGenerator(node.type.type.names[0], tag)
        node.type.type.names[0] = gen.type_name()

    def add_parent_rules(self):
        """ For each #requires rule, add a corresponding set
            of rules:
            #requires :read [@tags] -> for @tag in [@tags] {
                                         #has :param @tag
                                         #has :read @tag
                                       }
            #requires :write [@tags] -> for @tag in [@tags] {
                                          #has :param @tag
                                          #has :write @tag
                                        }
        """
        new_rules = []
        for rule in self.rules_set.get(rule_type="requires"):
            for tag in rule.tag_statement:
                tag = tag.strip("@")
                if rule.capability == "read":
                    new_rule1 = FlnRule("#has :param " + tag, rule.code_symbol,
                                        rule.type_specifier, rule.line)
                    new_rule2 = FlnRule("#has :read " + tag, rule.code_symbol,
                                        rule.type_specifier, rule.line)
                elif rule.capability == "write":
                    new_rule1 = FlnRule("#has :param " + tag, rule.code_symbol,
                                        rule.type_specifier, rule.line)
                    new_rule2 = FlnRule("#has :write " + tag, rule.code_symbol,
                                        rule.type_specifier, rule.line)
                else:
                    raise Exception("Unhandled #requires capability!: "
                                    + rule.capability)
                new_rules.append(new_rule1)
                new_rules.append(new_rule2)
        self.parent_rules_set.rules.extend(new_rules)

    def visit_Decl(self, node):
        """ if decl is TypeDecl and decl #requires """
        if type(node.type).__name__ == "TypeDecl":
            self.rules_set = FlnRuleSet(self.rules.get(node.type.declname, []))
            self.add_parent_rules()
            for rule in self.rules_set.get(rule_type="requires"):
                for tag in rule.tag_statement:
                    tag = tag.strip("@")
                    if rule.capability != "no-control-dep" or NOCONTROLDEPS:
                        self.transform_requires(node, tag)
                break


class FuncDefTransform(c_ast.NodeVisitor):
    """ Handles transformation of the function signature and
        calls transformations that act on the function body
    """
    def __init__(self, rules):
        self.rules = rules
        self.rules_set = None
        self.param_dict = {}
        self.id_transform_exclude = []

    def save_original_state(self, node):
        """ Preserve the original function signature {var names : ctypes}. """
        if node.decl.type.args is not None:
            for param in node.decl.type.args.params:
                if type(param.type).__name__ != "PtrDecl":
                    if type(param.type.type).__name__ == "TypeDecl":
                        self.param_dict[param.type.declname] = (param.type.type.type.names[0], False)
                    else:
                        self.param_dict[param.type.declname] = (param.type.type.names[0], False)
                else:
                    if type(param.type.type).__name__ == "TypeDecl":
                        self.param_dict[param.type.type.declname] = (param.type.type.type.names[0], True)
                    else:
                        self.param_dict[param.type.type.declname] = (param.type.type.names[0], True)

    def has_param(self, node):
        """ Transform the function parameters according to this rule:
            ctype name -> fln_type name
        """
        def param_transform(param, tag):
            """ ctype name -> fln_type name """
            if type(param.type.type).__name__ == "TypeDecl":
                gen = FlnCodeGenerator(param.type.type.type.names[0], tag)
                param.type.type.type.names[0] = gen.type_name()
            else:
                gen = FlnCodeGenerator(param.type.type.names[0], tag)
                param.type.type.names[0] = gen.type_name()
        if node.decl.type.args is not None:
            for rule in self.rules_set.get(rule_type="has", capability="param"):
                tag = rule.tag_statement[0].strip("@")
                tag_pos = rule.cap_specifier
                if tag_pos is None:
                    for param in node.decl.type.args.params:
                        param_transform(param, tag)
                        rule.code_symbol = param.name
                elif tag_pos >= len(node.decl.type.args.params) or tag_pos < 0:
                    raise Exception("Invalid tag_pos in #has @param(tag_pos): "
                                    + str(tag_pos+1))
                else:
                    param = node.decl.type.args.params[tag_pos]
                    param_transform(param, tag)
                    rule.code_symbol = param.name

    def has_read(self, node):
        """ Transform the function body with the following transforms:
            - AssignTransform
            - IDTransform
        """
        for rule in self.rules_set.get(rule_type="has", capability="read"):
            tag = rule.tag_statement[0].strip("@")
            AssignTransform(self.rules, self.rules_set, self.param_dict, "read", tag,
                            self.id_transform_exclude).visit(node)
            IDTransform(self.rules_set, self.param_dict, "read",
                        tag, self.id_transform_exclude).visit(node)

    def has_return(self, node):
        """ Transform the function return according to this rule:
            ctype name -> fln_type name
        """
        for rule in self.rules_set.get(rule_type="has", capability="return"):
            tag = rule.tag_statement[0].strip("@")
            gen = FlnCodeGenerator(node.decl.type.type.type.names[0], tag)
            node.decl.type.type.type.names[0] = gen.type_name()

    def has_write(self, node):
        """ Transform the function body with the following transforms:
            - AssignTransform
            - IDTransform
            - FuncCallTransform
        """
        for rule in self.rules_set.get(rule_type="has", capability="write"):
            tag = rule.tag_statement[0].strip("@")
            AssignTransform(self.rules, self.rules_set, self.param_dict, "write", tag,
                            self.id_transform_exclude).visit(node)
            IDTransform(self.rules_set, self.param_dict, "write",
                        tag, self.id_transform_exclude).visit(node)
    
    def cast_return(self, node):
        def cast(node, args):
            node.show()
            rule = args[0]
            tag = rule.tag_statement[0].strip("@")
            if rule.type_specifier.__class__ is tuple:
                genF = FlnCodeGenerator(rule.type_specifier[0], tag)
            else:
                genF = FlnCodeGenerator(rule.type_specifier, tag)
            genC = CCodeGenerator()
            if node.expr.__class__ == c_ast.Constant:
                fc = genC.new_fcall(genF.type_name()+"_write", node.expr.value)
            else:
                raise Exception("Unsupported return class")
            node.expr = fc
        for rule in self.rules_set.get(rule_type="has", capability="write1"):
            rv = ReturnVisitor(func=cast, args=[rule])
            rv.visit(node)
    
    def uncast_rewrite(self, node):
        """ Transform the function body with a cast that removes 
            fln parameter types
        """
        for rule in self.rules_set.get(rule_type="has", capability="uncast"):
            tag = rule.tag_statement[0].strip("@")
            if rule.type_specifier.__class__ == tuple:
                genF = FlnCodeGenerator(rule.type_specifier[0], tag)
            else:
                genF = FlnCodeGenerator(rule.type_specifier, tag)
            genC = CCodeGenerator()
            new_nodes = []
            replacement = {}
            params = []
            if hasattr(node.decl.type.args, "params") and node.decl.type.args.params is not None:
                params = node.decl.type.args.params
            for param in params:
                fcall = None
                name_p = param.name + "__fln_p"
                replacement[param.name] = name_p
                if rule.type_specifier.__class__ == tuple:
                    if rule.type_specifier[1]:
                        fcall = genC.new_fcall(genF.type_name()+"_read_ptr", param.name)   
                    else:
                        fcall = genC.new_fcall(genF.type_name()+"_read", param.name)
                    ivar = genC.new_ivar(name_p, fcall, rule.type_specifier[0])
                else:
                    fcall = genC.new_fcall(genF.type_name()+"_read", param.name)
                    ivar = genC.new_ivar(name_p, fcall, rule.type_specifier)
                new_nodes.append(ivar)
            def replace(node, args):
                replacement = args[0]
                if replacement.get(node.name, False):
                    node.name = replacement[node.name]
            if hasattr(node.body, "block_items") and node.body.block_items is not None:
                for itm in node.body.block_items:
                    iv = IDVisitor(func=replace, args=[replacement])
                    iv.visit(itm)
                for n in new_nodes:
                    node.body.block_items.insert(0, n)

    def provides_read(self):
        """ #provides :read [@tags] implies the following rules:
                - #has :param [@tags]
                - #has :uncast [@tags]
                // - #has :read [@tags]
            These new rules are added to the current rule set
        """
        new_rules = []
        for rule in self.rules_set.get(rule_type="provides", capability="read"):
            param_rule = FlnRule("#has :param " + " ".join(rule.tag_statement),
                                 rule.code_symbol, rule.type_specifier, rule.line)
            # read_rule = FlnRule("#has :read " + " ".join(rule.tag_statement),
            #                     rule.code_symbol, rule.type_specifier, rule.line)
            uncast_rule = FlnRule("#has :uncast " + " ".join(rule.tag_statement),
                                 rule.code_symbol, rule.type_specifier, rule.line)
            new_rules.append(param_rule)
            new_rules.append(uncast_rule)
            # new_rules.append(read_rule)
        self.rules_set.rules.extend(new_rules)

    def provides_write(self):
        """ #provides :write [@tags] implies the following rules:
                // - #has :param [@tags]
                // - #has :write [@tags]
                - #has :return [@tags]
            These new rules are added to the current rule set
        """
        new_rules = []
        for rule in self.rules_set.get(rule_type="provides", capability="write"):
            # param_rule = FlnRule("#has :param " + " ".join(rule.tag_statement),
            #                      rule.code_symbol, rule.type_specifier, rule.line)
            # read_rule = FlnRule("#has :write " + " ".join(rule.tag_statement),
            #                     rule.code_symbol, rule.type_specifier, rule.line)
            # new_rules.append(param_rule)
            # new_rules.append(read_rule)
            write_rule = FlnRule("#has :write1 " + " ".join(rule.tag_statement),
                                rule.code_symbol, rule.type_specifier, rule.line)
            return_rule = FlnRule("#has :return " + " ".join(rule.tag_statement),
                                rule.code_symbol, rule.type_specifier, rule.line)
            new_rules.append(return_rule)
            new_rules.append(write_rule)
        self.rules_set.rules.extend(new_rules)

    def visit_FuncDef(self, node):
        """ Visit all of the function definitions and perform
            all of the transformations on them.
        """
        self.save_original_state(node)
        self.rules_set = FlnRuleSet(self.rules.get(node.decl.name, []))
        DeclTransform(self.rules, self.rules_set).visit(node)
        self.provides_read()
        self.provides_write()
        self.has_param(node)
        self.has_read(node)
        self.has_write(node)
        self.has_return(node)
        self.uncast_rewrite(node)
        self.cast_return(node)
