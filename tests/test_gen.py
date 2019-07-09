from sys import argv
from random import sample, shuffle


# (frmt str, loc, loa, then stmt)
# {0} : function name
# {1} : Policy
# {2} : type
# {3} : rule commented out
templates = [
("int {0}() {{ \n\
    {3}#requires {1} \n\
    {2} a; \n\
    {{ {{ f(a); a = f(1); }} }} }}", 3, 1, True),
("int {0}() {{ \n\
    {3}#requires {1} \n\
    {2} a; \n\
    {{ f(a); {{ a = b; }} }} }}", 3, 1, True),
("int {0}() {{ \n\
    {3}#requires {1} \n\
    {2} a; \n\
    a = b; a = c; a = d; }}", 3, 1, True),
("{3}#param {1} \n\
int {0}({2} a, {2} b) {{ \n\
    f(a); a = 1; return a; }}", 2, 1, False),
("{3}#return {1} \n\
{2} {0}(int a, int b) {{ \n\
    f(a); a = 1; return a; }}", 2, 1, False),
("{3}#param {1} \n\
int {0}({2} a) {{ \n\
    return 0; }}", 2, 1, False)
]
projections = ["secrecy", "integrity"]
types = ["struct foo", "signed long int", "unsigned long int", 
        "unsigned short int", "signed short int", "unsigned int",
        "long double", "short int", "long int", "signed int", 
        "unsigned char", "float", "double", "int", "char"]
qualifiers = ["const ", "volatile ", ""]
pointers = ["*", ""]

num_loa = int(argv[1])
num_loc = int(argv[2])

SAMPLE = False
def to_sample(lst, cont):
    if cont:
        return sample(lst, len(lst))
    else:
        return lst

def to_shuffle(lst, cont):
    if cont:
        shuffle(lst)

tests = []
cur_loa = 0
cur_loc = 0
i = 0
cont = True
for _ in range(2):
    for qual in qualifiers:
        for typ in types:
            for template, loc, loa, isThen in templates:
                for projection in projections:
                    for ptr in pointers:
                        policies = []
                        if isThen:
                            policies.append("@test" + str(i) + "a:" + projection
                                            + " .then " + 
                                            "@test" + str(i) + "b:" + projection
                                            + " .then " + 
                                            "@test" + str(i) + "c:" + projection)
                            i += 1
                            policies.append("@test" + str(i) + "a:" + projection
                                            + " .then " + 
                                            "@test" + str(i) + "b:" + projection)
                            i += 1
                            policies.append("@test" + str(i) + ":" + projection)
                            i += 1                        
                        else:
                            policies.append( "@test" + str(i) + ":" + projection)
                            i += 1
                        to_shuffle(policies, SAMPLE)
                        for policy in policies:
                            if cur_loa < num_loa:
                                comment = ""
                                if cont:
                                    cur_loa += loa
                            else:
                                comment = "// "
                            if cur_loc >= num_loc:
                                cont = False
                            if cont:
                                tests.append(template.format(
                                    "test" + str(i), 
                                    policy, 
                                    qual + typ + ptr,
                                    comment
                                ))
                                cur_loc += loc
print("LoA: {0}, LoC: {1}".format(cur_loa, cur_loc))

out = []
for test in tests:
    out.append(test)
out = to_sample(out, SAMPLE)
arr = ["#include \"test11.h\"\n"]
arr.extend(out)

with open("tests/test11/test11.c", "w") as f:
    f.write("\n".join(arr))
