%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
    char typing;
%}

%token CHAR ELSE IF INT SHORT DOUBLE RETURN VOID WHILE BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LT MINUS MOD NE NOT OR PLUS RBRACE RPAR LPAR SEMI REALLIT RESERVED CHRLIT ID INTLIT
//FuncAndDeclarations DeclarationAndStates FuncDefinition FuncDeclaration Declaration TypeSpec FuncDeclarator FuncBody Statement ParamList ParamDeclaration Declarator Expr

%left LPAR RPAR
%right PLUS MINUS
%right NOT
%left MUL DIV MOD
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

%%
FuncAndDeclarations:
                    |FuncDefinition 
                    |FuncDeclaration
                    |Declaration
                    |FuncDefinition FuncAndDeclarations
                    |FuncDeclaration FuncAndDeclarations
                    |Declaration FuncAndDeclarations
                    ;

FuncDefinition: TypeSpec FuncDeclarator FuncBody
                ;

FuncBody:
            |LBRACE DeclarationAndStates RBRACE
            |LBRACE RBRACE
            ;

DeclarationAndStates:
                        |Statement DeclarationAndStates
                        |Declaration DeclarationAndStates
                        |Statement
                        |Declaration
                        ;

FuncDeclaration: TypeSpec FuncDeclaration SEMI
                    ;

FuncDeclarator: ID LPAR ParamList RPAR
                    ;

ParamList:
                    |ParamDeclaration
                    |ParamDeclaration COMMA ParamDeclaration
                    ;

ParamDeclaration:
                    |TypeSpec
                    |TypeSpec ID
                    ;

Declaration:
                    |TypeSpec Declarator SEMI
                    |TypeSpec Declarator COMMA Declarator
                    ;

TypeSpec:
                    |CHAR
                    |INT
                    |VOID
                    |DOUBLE
                    |SHORT
                    ;

Declarator:
                    |ID
                    |ID ASSIGN Expr
                    ;

Statement:
                    |SEMI
                    |Expr SEMI
                    |LBRACE RBRACE
                    |LBRACE Statement RBRACE
                    |IF LPAR Expr RPAR Statement
                    |IF LPAR Expr RPAR Statement ELSE Statement
                    |WHILE LPAR Expr RPAR Statement
                    |RETURN SEMI
                    |RETURN Expr SEMI
                    ;

Expr:
                    |Expr ASSIGN Expr
                    |Expr COMMA Expr







%%


int main() {
    yyparse();
    return 0;
}
