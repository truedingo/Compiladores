%{
int yylex();
int yyparse();
int val = 0;
#include <stdio.h>
#include <string.h>
#define LINHA linha++; coluna=1;
#define COLUNA coluna+=yyleng;
int flag=0;
int linha =1;
int coluna=1;
int c_atual=1;
int l_atual=1;
%}
%x COMMENTS
START_COMMENT "/*"
END_COMMENT "*/"
SINGLE_COMMENT "//"
CHARACTER [a-zA-Z]
UNDERSCORE "_"
CHAR char
ELSE else
WHILE while
IF if
INT int
SHORT short
DOUBLE double
RETURN return
VOID void
BITWISEAND &
BITWISEOR "|"
BITWISEXOR "^"
AND &&
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
ESCAPE \n|\t|\\|\'|\"
RESERVED "extern"|"float"|"for"|"goto"|"if"|"int"|"inline"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"++"|"--"|"["|"]"|"_Bool"|"_Complex"|"_Imaginary"|"_Packed"|"asm"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"
EXPOENTE "e"|"E"
REALLIT [0-9]+[.]([0-9]+)?(([e]|[E])([+]|[-])?[0-9]+)?|[0-9]+([e]|[E])([+]|[-])?[0-9]+|[.][0-9]+(([e]|[E])([+]|[-])?[0-9]+)?
ID ([a-zA-Z]|[_])([a-zA-Z]|[_]|[0-9])*
CHRLIT [']\\[0-7][0-7]?[0-7]?[']|['][^\n\\'][']|['][\\][n][']|['][\\][t][']|['][\\][\\][']|['][\\][\\'][']|['][\\][\"][']
TEXT_COMMENT [^\r\n]*
INTLIT [0-9]+
RETURNCHAR \r
LINETERMINATOR \n|{RETURNCHAR}|({RETURNCHAR})\n

%%

{SINGLE_COMMENT}{TEXT_COMMENT} {COLUNA;}
{START_COMMENT} {BEGIN COMMENTS; c_atual=coluna; l_atual=linha;COLUNA;}
<COMMENTS>("\n") {LINHA;}
<COMMENTS>(.) {COLUNA;}
<COMMENTS><<EOF>> {BEGIN 0; printf("Line %d, col %d: unterminated comment\n", l_atual, c_atual);COLUNA;}
<COMMENTS>{END_COMMENT} {BEGIN 0;COLUNA;}
{CHAR} {if(flag==-1 && val == 1){printf("CHAR\n");}COLUNA;}
{ELSE} {if(flag==-1 && val == 1){printf("ELSE\n");}COLUNA;}
{IF} {if(flag==-1 && val == 1){printf("IF\n");}COLUNA;}
{INT} {if(flag==-1 && val == 1){printf("INT\n");}COLUNA;}
{SHORT} {if(flag==-1 && val == 1){printf("SHORT\n");}COLUNA;}
{DOUBLE} {if(flag==-1 && val == 1){printf("DOUBLE\n");}COLUNA;}
{RETURN} {if(flag==-1 && val == 1){printf("RETURN\n");}COLUNA;}
{VOID} {if(flag==-1 && val == 1){printf("VOID\n");}COLUNA;}
{WHILE} {if(flag==-1 && val == 1){printf("WHILE\n");}COLUNA;}
{BITWISEAND} {if(flag==-1 && val == 1){printf("BITWISEAND\n");}COLUNA;}
{BITWISEOR} {if(flag==-1 && val == 1){printf("BITWISEOR\n");}COLUNA;}
{BITWISEXOR} {if(flag==-1 && val == 1){printf("BITWISEXOR\n");}COLUNA;}
{AND} {if(flag==-1 && val == 1){printf("AND\n");}COLUNA;}
{ASSIGN} {if(flag==-1 && val == 1){printf("ASSIGN\n");}COLUNA;}
{MUL} {if(flag==-1 && val == 1){printf("MUL\n");}COLUNA;}
{COMMA} {if(flag==-1 && val == 1){printf("COMMA\n");}COLUNA;}
{DIV} {if(flag==-1 && val == 1){printf("DIV\n");}COLUNA;}
{EQ} {if(flag==-1 && val == 1){printf("EQ\n");}COLUNA;}
{GE} {if(flag==-1 && val == 1){printf("GE\n");}COLUNA;}
{GT} {if(flag==-1 && val == 1){printf("GT\n");}COLUNA;}
{LBRACE} {if(flag==-1 && val == 1){printf("LBRACE\n");}COLUNA;}
{LE} {if(flag==-1 && val == 1){printf("LE\n");}COLUNA;}
{LT} {if(flag==-1 && val == 1){printf("LT\n");}COLUNA;}
{MINUS} {if(flag==-1 && val == 1){printf("MINUS\n");}COLUNA;}
{MOD} {if(flag==-1 && val == 1){printf("MOD\n");}COLUNA;}
{NE} {if(flag==-1 && val == 1){printf("NE\n");}COLUNA;}
{NOT} {if(flag==-1 && val == 1){printf("NOT\n");}COLUNA;}
{OR} {if(flag==-1 && val == 1){printf("OR\n");}COLUNA;}
{PLUS} {if(flag==-1 && val == 1){printf("PLUS\n");}COLUNA;}
{RBRACE} {if(flag==-1 && val == 1){printf("RBRACE\n");}COLUNA;}
{RPAR} {if(flag==-1 && val == 1){printf("RPAR\n");}COLUNA;}
{LPAR} {if(flag==-1 && val == 1){printf("LPAR\n");}COLUNA;}
{SEMI} {if(flag==-1 && val == 1){printf("SEMI\n");}COLUNA;}
{REALLIT} {if(flag==-1 && val == 1){printf("REALLIT(%s)\n", yytext);}COLUNA;}
{RESERVED} {if(flag==-1 && val == 1){printf("RESERVED(%s)\n", yytext);}COLUNA;}
{CHRLIT} {if(flag==-1 && val == 1){printf("CHRLIT(%s)\n", yytext);}COLUNA;}
{ID} {if(flag==-1 && val == 1){printf("ID(%s)\n", yytext);}COLUNA;}
{INTLIT} {if(flag==-1 && val == 1){printf("INTLIT(%s)\n", yytext);}COLUNA;}
{LINETERMINATOR} {LINHA;}

"\t"|" "    {COLUNA;}
[']([^\n\\\']|[\\].)*[']    {printf("Line %d, col %d: invalid char constant (%s)\n", linha, coluna, yytext); COLUNA;}
[']([^\n\\\']|[\\].)*[\\]? {printf("Line %d, col %d: unterminated char constant\n", linha, coluna); COLUNA;} 
.       {printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext); COLUNA;} 

%%
int main(int argc, char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1], "-l") == 0){
            flag=-1;
            val = 1;
        }
    }
    yylex();
    return 0;
}
int yywrap()
{
return 1;
}