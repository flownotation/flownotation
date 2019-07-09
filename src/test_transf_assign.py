from fln_parse import FlnParse

src = "\
#has :read @trusted\
int test_func1(int x) {\
    x = 1;\
}\
"

def main():
    parser = FlnParse(src)
    gen = FlnCodeGenerator()
    header_lines = gen.generate_header(parser.rules_clean)
    filename_int = filename.split(".")[0] + "__int.c"
    parser.output_clean_source(filename_int)
    ast = generate_ast(filename_int)

