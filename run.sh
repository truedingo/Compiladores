#!/bin/sh 
lex uccompiler.l yacc -d -v uccompiler.y cc -o uccompiler y.tab.c lex.yy.c 