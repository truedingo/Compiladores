/* Diogo Amores 2015231975 damores@student.uc.pt */
/* Maria Roseiro 2015233281 miroseiro@student.uc.pt */
%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    #include "newtree.h"

   symb_list symtab;
   functions_list flist;

    
    #define LINHA linha++; coluna=1;
    #define COLUNA coluna+=yyleng;
    int val = 0;
    int flag=0;
    int linha =1;
    int coluna=1;
    int c_atual=1;
    int l_atual=1; 
    int yyparse();
    extern no* root;
    extern int error_check;

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
{CHAR} {if(flag==-1 && val == 1){printf("CHAR\n");}COLUNA; if(flag==2)return CHAR;}
{ELSE} {if(flag==-1 && val == 1){printf("ELSE\n");}COLUNA; if(flag==2)return ELSE;}
{IF} {if(flag==-1 && val == 1){printf("IF\n");}COLUNA; if(flag==2)return IF;}
{INT} {if(flag==-1 && val == 1){printf("INT\n");}COLUNA; if(flag==2)return INT;}
{SHORT} {if(flag==-1 && val == 1){printf("SHORT\n");}COLUNA; if(flag==2)return SHORT;}
{DOUBLE} {if(flag==-1 && val == 1){printf("DOUBLE\n");}COLUNA; if(flag==2)return DOUBLE;}
{RETURN} {if(flag==-1 && val == 1){printf("RETURN\n");}COLUNA; if(flag==2)return RETURN;}
{VOID} {if(flag==-1 && val == 1){printf("VOID\n");}COLUNA; if(flag==2)return VOID;}
{WHILE} {if(flag==-1 && val == 1){printf("WHILE\n");}COLUNA; if(flag==2)return WHILE;}
{BITWISEAND} {if(flag==-1 && val == 1){printf("BITWISEAND\n");}COLUNA; if(flag==2)return BITWISEAND;}
{BITWISEOR} {if(flag==-1 && val == 1){printf("BITWISEOR\n");}COLUNA; if(flag==2)return BITWISEOR;}
{BITWISEXOR} {if(flag==-1 && val == 1){printf("BITWISEXOR\n");}COLUNA; if(flag==2)return BITWISEXOR;}
{AND} {if(flag==-1 && val == 1){printf("AND\n");}COLUNA; if(flag==2)return AND;}
{ASSIGN} {if(flag==-1 && val == 1){printf("ASSIGN\n");}COLUNA; if(flag==2)return ASSIGN;}
{MUL} {if(flag==-1 && val == 1){printf("MUL\n");}COLUNA; if(flag==2)return MUL;}
{COMMA} {if(flag==-1 && val == 1){printf("COMMA\n");}COLUNA; if(flag==2)return COMMA;}
{DIV} {if(flag==-1 && val == 1){printf("DIV\n");}COLUNA; if(flag==2)return DIV;}
{EQ} {if(flag==-1 && val == 1){printf("EQ\n");}COLUNA; if(flag==2)return EQ;}
{GE} {if(flag==-1 && val == 1){printf("GE\n");}COLUNA; if(flag==2)return GE;}
{GT} {if(flag==-1 && val == 1){printf("GT\n");}COLUNA; if(flag==2)return GT;}
{LBRACE} {if(flag==-1 && val == 1){printf("LBRACE\n");}COLUNA; if(flag==2)return LBRACE;}
{LE} {if(flag==-1 && val == 1){printf("LE\n");}COLUNA; if(flag==2)return LE;}
{LT} {if(flag==-1 && val == 1){printf("LT\n");}COLUNA; if(flag==2)return LT;}
{MINUS} {if(flag==-1 && val == 1){printf("MINUS\n");}COLUNA; if(flag==2)return MINUS;}
{MOD} {if(flag==-1 && val == 1){printf("MOD\n");}COLUNA; if(flag==2)return MOD;}
{NE} {if(flag==-1 && val == 1){printf("NE\n");}COLUNA; if(flag==2)return NE;}
{NOT} {if(flag==-1 && val == 1){printf("NOT\n");}COLUNA; if(flag==2)return NOT;}
{OR} {if(flag==-1 && val == 1){printf("OR\n");}COLUNA; if(flag==2)return OR;}
{PLUS} {if(flag==-1 && val == 1){printf("PLUS\n");}COLUNA; if(flag==2)return PLUS;}
{RBRACE} {if(flag==-1 && val == 1){printf("RBRACE\n");}COLUNA; if(flag==2)return RBRACE;}
{RPAR} {if(flag==-1 && val == 1){printf("RPAR\n");}COLUNA; if(flag==2)return RPAR;}
{LPAR} {if(flag==-1 && val == 1){printf("LPAR\n");}COLUNA; if(flag==2)return LPAR;}
{SEMI} {if(flag==-1 && val == 1){printf("SEMI\n");}COLUNA; if(flag==2)return SEMI;}
{REALLIT} {if(flag==-1 && val == 1){printf("REALLIT(%s)\n", yytext);}COLUNA;yylval.string=(char*)strdup(yytext); if(flag==2)return REALLIT;}
{RESERVED} {if(flag==-1 && val == 1){printf("RESERVED(%s)\n", yytext);}COLUNA;yylval.string=(char*)strdup(yytext); if(flag==2)return RESERVED;}
{CHRLIT} {if(flag==-1 && val == 1){printf("CHRLIT(%s)\n", yytext);}COLUNA;yylval.string=(char*)strdup(yytext); if(flag==2)return CHRLIT;}
{ID} {if(flag==-1 && val == 1){printf("ID(%s)\n", yytext);}COLUNA;yylval.string=(char*)strdup(yytext); if(flag==2)return ID;}
{INTLIT} {if(flag==-1 && val == 1){printf("INTLIT(%s)\n", yytext);}COLUNA;yylval.string=(char*)strdup(yytext); if(flag==2)return INTLIT;}
{LINETERMINATOR} {LINHA;}

"\t"|" "    {COLUNA;}
[']([^\n\\\']|[\\].)*[']    {printf("Line %d, col %d: invalid char constant (%s)\n", linha, coluna, yytext); COLUNA;}
[']([^\n\\\']|[\\].)*[\\]? {printf("Line %d, col %d: unterminated char constant\n", linha, coluna); COLUNA;} 
.       {printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext); COLUNA;} 

%%

int yywrap()
{
return 1;
}

void yyerror (const char *s) { 
     printf ("Line %d, col %d: %s: %s\n",linha,(int)(coluna-strlen(yytext)), s, yytext);
}

int main(int argc, char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1],"-l") == 0){
            flag=-1;
            val = 1;
            yylex(); 
        } 
        if(strcmp(argv[1],"-t")==0){
            flag=2;
            yyparse();
            yylex_destroy();
            if(error_check!=1){
                printAST(root,0);
            }
        }
        if(strcmp(argv[1],"-s")==0){
            flag=2;
            yyparse();
            if(error_check!=1){
                handle_ast(root);
                print_global_table();
                printAST(root,0);
            }
            yylex_destroy();
        }
    }
    else{
        flag=2;
        yyparse();
        if(error_check != 1){
            //funcao de gerar codigo llvm
            handle_ast(root);
            generate_llvm(root); 
            end_llvm();
        }
        yylex_destroy();
    }
    return 0;
}