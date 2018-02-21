INTLIT [0-9]
CHARACTER [a-zA-z]
NEWLINE "\n"
UNDERSCORE "_"
CHAR "char"
ELSE "else"
WHILE "while"
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
RESERVED "auto"|"struct"|"break"|"long"|"switch"|"case"|"enum"|"register"|"typedef"|"extern"|"union"|"const"|"unsigned"|"continue"|"for"|"signed"|"default"|"goto"|"sizeof"|"volatile"|"do"|"static"|"_Bool"|"_Imaginary"|"restrict"|"inline"|"_Complex"|"["|"]"|"++"|"--"


%{
char endstring[300];
int i=0;
%}

%%
{blockexcluded} ;
{stringtype} {strcat(endstring, yytext); strcat(endstring, ", ");}
.       ;
   
%%
int main()
{
yylex();
printf("%s", endstring);
return 0;
}

int yywrap()
{
return 1;
}