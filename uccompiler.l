%{
#include <stdio.h>
#include <string.h>
int flag=0;
%}
INTLIT [0-9]+
CHARACTER [a-zA-Z]
NEWLINE "\n"
UNDERSCORE "_"
CHAR char
ELSE else
WHILE while
IF "if"
INT "int"
SHORT "short"
DOUBLE "double"
RETURN "return"
VOID "void"
BITWISEAND "&"
BITWISEOR "|"
BITWISEXOR "^"
AND "&&"
ASSIGN "="
MUL "*"
COMMA ","
DIV "/"
EQ "=="
GE ">="
GT ">"
LBRACE "{"
LE "<="
LPAR "("
LT "<"
MINUS "-"
MOD "%"
NE "!="
NOT "!"
OR "||"
PLUS "+"
RBRACE "}"
RPAR ")"
SEMI ";"
ESCAPE "\n"|"\t"|"\\"|"\'"|"\""
RESERVED "auto"|"struct"|"break"|"long"|"switch"|"case"|"enum"|"register"|"typedef"|"extern"|"union"|"const"|"unsigned"|"continue"|"for"|"signed"|"default"|"goto"|"sizeof"|"volatile"|"do"|"static"|"_Bool"|"_Imaginary"|"restrict"|"inline"|"_Complex"|"["|"]"|"++"|"--"
CHRLIT '([a-zA-Z]|\\[0-7]{3}|\_|\\\\|\\n|\\t|[0-9])'
EXPOENTE "e"|"E"
ID2 ([a-zA-z]+|\_+)|([a-zA-z]+|\_+)[0-9]?
ID ([a-zA-Z]|[_])[a-zA-Z0-9]*
%%
{CHAR} {if(flag==-1){printf("CHAR");}}
{ELSE} {if(flag==-1){printf("ELSE");}}
{IF} {if(flag==-1){printf("IF");}}
{INT} {if(flag==-1){printf("INT");}}
{SHORT} {if(flag==-1){printf("SHORT");}}
{DOUBLE} {if(flag==-1){printf("DOUBLE");}}
{RETURN} {if(flag==-1){printf("RETURN");}}
{VOID} {if(flag==-1){printf("VOID");}}
{BITWISEAND} {if(flag==-1){printf("BITWISEAND");}}
{BITWISEOR} {if(flag==-1){printf("BITWISEOR");}}
{BITWISEXOR} {if(flag==-1){printf("BITWISEXOR");}}
{AND} {if(flag==-1){printf("AND");}}
{ASSIGN} {if(flag==-1){printf("ASSIGN");}}
{MUL} {if(flag==-1){printf("MUL");}}
{COMMA} {if(flag==-1){printf("COMMA");}}
{DIV} {if(flag==-1){printf("DIV");}}
{EQ} {if(flag==-1){printf("EQ");}}
{GE} {if(flag==-1){printf("GE");}}
{GT} {if(flag==-1){printf("GT");}}
{LBRACE} {if(flag==-1){printf("LBRACE");}}
{LT} {if(flag==-1){printf("LT");}}
{MINUS} {if(flag==-1){printf("MINUS");}}
{MOD} {if(flag==-1){printf("MOD");}}
{NE} {if(flag==-1){printf("NE");}}
{NOT} {if(flag==-1){printf("NOT");}}
{OR} {if(flag==-1){printf("OR");}}
{PLUS} {if(flag==-1){printf("PLUS");}}
{RBRACE} {if(flag==-1){printf("RBRACE");}}
{RPAR} {if(flag==-1){printf("RPAR");}}
{SEMI} {if(flag==-1){printf("SEMI");}}
{INTLIT} {if(flag==-1){printf("INTLIT(%d)", atoi(yytext));}}
{CHRLIT} {if(flag==-1){printf("CHRLIT(%s)", yytext);}}
{ID} {if(flag==-1){printf("ID(%s)", yytext);}}
<<EOF>> {yyterminate();}
%%
int main(int argc, char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1], "-l") == 0){
            flag=-1;
        }
        yylex();
    }
    return 0;
}
int yywrap()
{
return 1;
}