#!/bin/sh 
lex uccompiler.l 
clang-3.8 -Wall -Wno-unused-function lex.yy.c 
zip uccompiler.zip uccompiler.l