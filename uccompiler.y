%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
%}

%token CHAR ELSE IF INT SHORT DOUBLE RETURN VOID WHILE BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LT MINUS MOD NE NOT OR PLUS RBRACE RPAR LPAR SEMI REALLIT RESERVED CHRLIT ID INTLIT
%left LPAR RPAR
%right PLUS MINUS
%right NOT
%left MUL DIV MOD
%left PLUS MINUS
%left LE LT
%left GT GE
%left EQ NE
%left BITWISEAND
%left BITWISEXOR
%left BITWISEOR
%left AND
%left OR
%right ASSIGN
%left COMMA


int main() {
    yyparse();
    return 0;
}
