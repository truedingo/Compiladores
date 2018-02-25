%{
#include <stdio.h>
#include <string.h>
int flag=0;

%}
%x COMMENTS
ignorar "\n"|"\r"|"\t"|"//"|" "
START_COMMENT "/*"
END_COMMENT "*/"
SINGLE_COMMENT "//"
CHARACTER [a-zA-Z]
NEWLINE "\n"|"\r"
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
RESERVED "extern"|"float"|"for"|"goto"|"if"|"int"|"inline"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"++"|"--"|"["|"]"|"_Bool"|"_Complex"|"_Imaginary"|"_Packed"|"asm"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"
EXPOENTE "e"|"E"
REALLIT ([0-9]+[.][0-9]+([e]|[E])([+]|[-])?[0-9]+)|([0-9]+[.][0-9]+)|[0-9]+[.]([e]|[E])([+]|[-])?[0-9]+|[.][0-9]+([e]|[E])([+]|[-])?[0-9]+|[0-9]+([e]|[E])([+]|[-])?[0-9]+|([.][0-9]+([e]|[E])([+]|[-])?[0-9]+)|([.][0-9]+)
ID ([a-zA-Z]|[_])[a-zA-Z0-9]*
CHRLIT [']\\[0-7][0-7]?[0-7]?[']|['][^\n\\'][']|['][\\][n][']|['][\\][t][']|['][\\][\\][']|['][\\][\\'][']|['][\\][\"][']
INTLIT [0-9]+ 
TEXT_COMMENT [^"\n"]


%%
{CHAR} {if(flag==-1){printf("CHAR\n");}}
{ELSE} {if(flag==-1){printf("ELSE\n");}}
{IF} {if(flag==-1){printf("IF\n");}}
{INT} {if(flag==-1){printf("INT\n");}}
{SHORT} {if(flag==-1){printf("SHORT\n");}}
{DOUBLE} {if(flag==-1){printf("DOUBLE\n");}}
{RETURN} {if(flag==-1){printf("RETURN\n");}}
{VOID} {if(flag==-1){printf("VOID\n");}}
{WHILE} {if(flag==-1){printf("WHILE\n");}}
{BITWISEAND} {if(flag==-1){printf("BITWISEAND\n");}}
{BITWISEOR} {if(flag==-1){printf("BITWISEOR\n");}}
{BITWISEXOR} {if(flag==-1){printf("BITWISEXOR\n");}}
{AND} {if(flag==-1){printf("AND\n");}}
{ASSIGN} {if(flag==-1){printf("ASSIGN\n");}}
{MUL} {if(flag==-1){printf("MUL\n");}}
{COMMA} {if(flag==-1){printf("COMMA\n");}}
{DIV} {if(flag==-1){printf("DIV\n");}}
{EQ} {if(flag==-1){printf("EQ\n");}}
{GE} {if(flag==-1){printf("GE\n");}}
{GT} {if(flag==-1){printf("GT\n");}}
{LBRACE} {if(flag==-1){printf("LBRACE\n");}}
{LE} {if(flag==-1){printf("LE\n");}}
{LT} {if(flag==-1){printf("LT\n");}}
{MINUS} {if(flag==-1){printf("MINUS\n");}}
{MOD} {if(flag==-1){printf("MOD\n");}}
{NE} {if(flag==-1){printf("NE\n");}}
{NOT} {if(flag==-1){printf("NOT\n");}}
{OR} {if(flag==-1){printf("OR\n");}}
{PLUS} {if(flag==-1){printf("PLUS\n");}}
{RBRACE} {if(flag==-1){printf("RBRACE\n");}}
{RPAR} {if(flag==-1){printf("RPAR\n");}}
{LPAR} {if(flag==-1){printf("LPAR\n");}}
{SEMI} {if(flag==-1){printf("SEMI\n");}}
{REALLIT} {if(flag==-1){printf("REALLIT(%s)\n", yytext);}}
{RESERVED} {if(flag==-1){printf("RESERVED(%s)\n", yytext);}}
{CHRLIT} {if(flag==-1){printf("CHRLIT(%s)\n", yytext);}}
{ID} {if(flag==-1){printf("ID(%s)\n", yytext);}}
{INTLIT} {if(flag==-1){printf("INTLIT(%s)\n", yytext);}}



{START_COMMENT} {BEGIN COMMENTS;}
<COMMENTS>(.|"\n") ;
<COMMENTS>{END_COMMENT} {BEGIN 0;}
{SINGLE_COMMENT}{TEXT_COMMENT}*{NEWLINE} ;
{ignorar}   ;

.   {printf("Line col : illegal character (%s)\n",yytext);}
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