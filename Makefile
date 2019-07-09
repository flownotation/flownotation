C = gcc
CFLAGS = -w
TEST = examples/ex6/part3

default: parse compile

parse:
	python src/fln_main.py $(TEST).c

compile:
	$(C) $(CFLAGS) $(TEST)__fln.c -o prog.out
