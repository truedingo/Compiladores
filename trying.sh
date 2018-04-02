    #!/bin/sh 
    lex uccompiler.l 
    yacc -d uccompiler.y
    cc lex.yy.c y.tab.c -ll -ly