#!/bin/sh 
lex uccompiler.l 
yacc -d uccompiler.y
cc -o y.output y.tab.c lex.yy.c 