import sys
import os
from fln_parse import FlnParse
from fln_rule import FlnRule
from fln_codegen import CCodeGenerator
from fln_transform import process_fln_c
from pycparser import c_ast, parse_file, c_generator

# Timing code for perf mesurement
MEASURE_TIME = True
if MEASURE_TIME:
    REPEAT = 10
    from time import clock
    times = []


original_filename = ''
original_prefix = ''
modified_files = {}


def generate_ast(filename):
    """ Generate the ast from the cleaned source."""
    src = ""
    with open(filename, "r") as src_file:
        for line in src_file.readlines():
            src += line
    ast = parse_file(filename, use_cpp=True)
    return ast

def generate_header_file(filename, header_lines, ifiles, i, REPEAT):
    name = filename.split('/')[-1][:-2].replace('-', '_')
    out_string = "#ifndef " + name.upper() + "__FLN_H__\n"
    out_string += "#define " + name.upper() + "__FLN_H__\n"
    if i == REPEAT - 1:
        for ifile in ifiles:
            out_string += "#include \"" + ifile +"\"\n" 
    for line in header_lines:
        out_string += line + "\n"
    out_string += "#endif"
    with open(filename, "w") as out_file:
        out_file.write(out_string)

def generate_fln_c(filename, ast):
    out_string = ""
    generator = c_generator.CGenerator()
    out_string += generator.visit(ast)
    with open(filename, "w") as out_file:
        out_file.write(out_string)
    return out_string

def read_file_tree(filename):
    root = '/'.join(filename.split('/')[:-1]) + '/'
    file_lines = []
    with open(filename, "r") as src_file:
        file_lines = src_file.readlines()
    ifiles = []
    for line in file_lines:
        if line.startswith("#include"):
            ifile = line.strip().split(' ')[1]
            if '<' not in ifile and "__fln" not in ifile \
                and "pycparser" not in ifile:
                ifile = ifile.strip('"')
                ifiles.append(ifile)
    total_lines = []
    for ifile in ifiles:
        with open(root+ifile, 'r') as f:
            total_lines.extend(f.readlines())
    total_lines.extend(file_lines)
    return total_lines, ifiles

def get_time():
    if MEASURE_TIME:
        return clock()
    else:
        return 0

def measure_time(diff, msg):
    if MEASURE_TIME:
        times.append(diff)
        print msg + str(diff)

def do_parse_instrumented(filename):
    print "---------------PARSING-----------------"
    avg_diff = 0.0
    for _ in range(REPEAT):
        t0 = get_time()
        file_lines, ifiles = read_file_tree(filename)
        t1 = get_time()
        avg_diff += (t1 - t0)
    measure_time(avg_diff / REPEAT, "TIME: Read files: ")
    # Parse the rules
    avg_diff = 0.0
    for _ in range(REPEAT):
        t0 = get_time()
        parser = FlnParse(file_lines)
        t1 = get_time()
        avg_diff += (t1 - t0)
    measure_time(avg_diff / REPEAT, "TIME: Parsing: ")
    # parser.output_rules()
    print "--------------HEADER_GEN-----------------"
    # Generate the typedef file header
    avg_diff = 0.0
    for i in range(REPEAT):
        t0 = get_time()
        gen = CCodeGenerator()
        header_lines = gen.generate_header(parser.rules_clean,
                                        parser.typedefs,
                                        parser.structs)
        # print header_lines
        filename_h = filename.split(".")[0] + "__fln.h"
        generate_header_file(filename_h, header_lines, ifiles, i, REPEAT)
        t1 = get_time()
        avg_diff += (t1 - t0)
    measure_time(avg_diff / REPEAT, "TIME: Header gen: ")
    print "-------------CLEAN_SOURCE----------------"
    # Generate cleaned source
    avg_diff = 0.0
    for _ in range(REPEAT):
        t0 = get_time()
        filename_int = filename.split(".")[0] + "__int.c"
        parser.output_clean_source(filename_int)
        t1 = get_time()
        avg_diff += (t1 - t0) 
    measure_time(avg_diff / REPEAT, "TIME: Clean source: ")
    print "-------------TRAVERSE_AST----------------"
    # Traverse the AST for transformations
    avg_diff = 0.0
    for _ in range(REPEAT):
        t0 = get_time()
        ast = generate_ast(filename_int)
        t1 = get_time()
        avg_diff += (t1 - t0) 
    measure_time(avg_diff / REPEAT, "TIME: Build AST: ")
    # ast.show()
    print "--------------PROCESS_FLN----------------"
    avg_diff = 0.0
    for _ in range(REPEAT):
        ast = generate_ast(filename_int)
        t0 = get_time()
        process_fln_c(ast, parser.rules_clean)
        t1 = get_time()
        avg_diff += (t1 - t0) 
    measure_time(avg_diff / REPEAT, "TIME: Transformation: ")
    print "-------------OUTPUT_TRANSF---------------"
    # Output the transformed C code
    avg_diff = 0.0
    for _ in range(REPEAT):
        t0 = get_time()
        filename_fln = filename.split(".")[0] + "__fln.c"
        generate_fln_c(filename_fln, ast)
        t1 = get_time()
        avg_diff += (t1 - t0) 
    measure_time(avg_diff / REPEAT, "TIME: Output transformed: ")


def do_parse(filename):
    print "---------------PARSING-----------------"
    file_lines, ifiles = read_file_tree(filename)
    # Parse the rules
    parser = FlnParse(file_lines)
    # parser.output_rules()
    print "--------------HEADER_GEN-----------------"
    # Generate the typedef file header
    gen = CCodeGenerator()
    header_lines = gen.generate_header(parser.rules_clean,
                                       parser.typedefs,
                                       parser.structs)
    # print header_lines
    filename_h = filename.split(".")[0] + "__fln.h"
    generate_header_file(filename_h, header_lines, ifiles, 0, 1)
    print "-------------CLEAN_SOURCE----------------"
    # Generate cleaned source
    filename_int = filename.split(".")[0] + "__int.c"
    parser.output_clean_source(filename_int)
    print "-------------TRAVERSE_AST----------------"
    # Traverse the AST for transformations
    ast = generate_ast(filename_int)
    # ast.show()
    print "--------------PROCESS_FLN----------------"
    process_fln_c(ast, parser.rules_clean)
    print "-------------OUTPUT_TRANSF---------------"
    # Output the transformed C code
    filename_fln = filename.split(".")[0] + "__fln.c"
    generate_fln_c(filename_fln, ast)

    
# Adds the include statement in the .c file, and finds the remaining
# .c dependencies in the .c file
def add_include(filename):
    first_line_set = {'\n', '\r'}
    include_statement = '#include "' + filename.split('/')[-1][:-2] + '__fln.h"'
    include_c_files = []
    overwrite_offset = 0
    curr_offset = 0
    overwrite = False
    overwrite_buffer = include_statement + '\n\n'
    modified_files[filename] = []
    with open(filename, 'r+b') as f:
        for line in f.readlines():
            # Insert the include statement
            if (len(line) > 1 and line[0] not in first_line_set and line[:8] != '#include'):
                modified_files[filename].append(include_statement)
                f.seek(curr_offset, 0)
                overwrite_buffer += f.read()
                f.seek(overwrite_offset, 0)
                f.write(overwrite_buffer)
                break
            # Check for chain dependencies, and replace include line with __int.c file
            if (line[:8] == '#include' and line[-4:] == '.c"\n'):
                include_c_files.append(line.strip()[10:-1])
                modified_include_line = line[:-4] + '__int.c"\n\n'
                modified_files[filename].append(modified_include_line[:-2]) # Everything but newline
                overwrite_buffer = modified_include_line + overwrite_buffer
                if (not overwrite):
                    overwrite = True
                curr_offset += len(line)
                continue
            if (overwrite):
                overwrite_buffer += line
            else:
                overwrite_offset += len(line)
            curr_offset += len(line)
    return include_c_files


def preprocess(filename, orig_name):
    original_filename = orig_name
    original_prefix = original_filename.rsplit('/', 1)[0] + '/' 
    included_c_files = add_include(filename)
    for c_file in included_c_files:
        preprocess(original_prefix + c_file, orig_name)
    # if (filename != orig_name):
    #     do_parse(filename)


def remove_include(filename, include_lines):
    outbuf = ""
    # Take care of the included __int.c files
    # print "\n Removing includes: include lines are: ",include_lines
    for line in include_lines:
        if line[-8:-1] == '__int.c':
            outbuf += line[:-8] + '.c"\n\n'
            print "included line is: |"+line+"| outbuf is now: "+outbuf
    with open(filename, "r+b") as f:
        ignore = False
        for line in f:
            if ignore:
                ignore = False
            elif line.strip() not in include_lines:
                outbuf += line
            else:
                ignore = True
    os.remove(filename)
    with open(filename, "w") as f:
        f.write(outbuf)


def postprocess():
    for filename in modified_files:
        remove_include(filename, modified_files[filename])


def main(argv):
    if argv == []:
        print "Please supply files to parse!"
        exit(-1)
    for filename in argv:
        preprocess(filename, filename)
        if MEASURE_TIME:
            do_parse_instrumented(filename)
        else:
            do_parse(filename)
        postprocess()


if __name__ == "__main__":
    main(sys.argv[1:])
    if MEASURE_TIME:
        total_time = 0
        for time in times:
            total_time += time
        measure_time(total_time, "TIME: Overall execution: ")
        for time in times:
            print str(time)
