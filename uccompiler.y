%{
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    void yyerror(const char* s);
    int yylex();


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
                    |Expr PLUS Expr
                    |Expr MINUS Expr
                    |Expr MUL Expr
                    |Expr DIV Expr
                    |Expr MOD Expr
                    |Expr OR Expr
                    |Expr AND Expr
                    |Expr BITWISEAND Expr
                    |Expr BITWISEOR Expr
                    |Expr BITWISEXOR Expr
                    |Expr EQ Expr
                    |Expr NE Expr
                    |Expr LE Expr
                    |Expr GE Expr
                    |Expr LT Expr
                    |Expr GT Expr
                    |PLUS Expr
                    |MINUS Expr
                    |NOT Expr
                    |ID LPAR RPAR
                    |ID LPAR Expr RPAR
                    |ID LPAR Expr COMMA Expr RPAR
                    |INTLIT LPAR Expr RPAR
                    |CHRLIT LPAR Expr RPAR
                    |REALLIT LPAR Expr RPAR
                    ;


%%
