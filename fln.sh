#!/bin/bash
C=gcc
CFLAGS=-w

if [ "$1" == "--parse" ] || [ "$1" == "-p" ]
then
    # python2.7 src/fln_main.py tests/test9/test9.c
    python src/fln_main.py $2.$3
fi

if [ "$1" == "--compile" ] || [ "$1" == "-c" ]
then
    $C $CFLAGS $2__fln.$3
fi
