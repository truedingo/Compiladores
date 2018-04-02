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
                    FuncDefinition 
                    |FuncDeclaration
                    |Declaration
                    |FuncDefinition FuncAndDeclarations
                    |FuncDeclaration FuncAndDeclarations
                    |Declaration FuncAndDeclarations
                    ;

FuncDefinition: TypeSpec FuncDeclarator FuncBody
                ;

FuncBody:
            LBRACE DeclarationAndStates RBRACE
            |LBRACE RBRACE
            ;

DeclarationAndStates:
                        Statement DeclarationAndStates
                        |Declaration DeclarationAndStates
                        |Statement
                        |Declaration
                        ;

FuncDeclaration: TypeSpec FuncDeclaration SEMI
                    ;

FuncDeclarator: ID LPAR ParamList RPAR
                    ;

ParamList:
                    ParamDeclaration
                    |ParamDeclaration COMMA ParamDeclaration
                    ;

ParamDeclaration:
                    TypeSpec
                    |TypeSpec ID
                    ;

Declaration:
                    error SEMI;
                    |TypeSpec Declarator SEMI
                    |TypeSpec Declarator COMMA AuxDeclarator SEMI
                    ;
AuxDeclarator:
                    COMMA Declarator
                    |AuxDeclarator COMMA Declarator;
TypeSpec:
                    CHAR
                    |INT
                    |VOID
                    |DOUBLE
                    |SHORT
                    ;

Declarator:
                    ID
                    |ID ASSIGN Expr
                    ;

Statement:
                    SEMI
                    |Expr SEMI
                    |LBRACE error RBRACE
                    |LBRACE RBRACE
                    |LBRACE AuxStatement RBRACE
                    |IF LPAR Expr RPAR ErrorStatement
                    |IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement
                    |WHILE LPAR Expr RPAR ErrorStatement
                    |RETURN SEMI
                    |RETURN Expr SEMI
                    ;
ErrorStatement:
                    Statement
                    |error SEMI            
                    ;   
AuxStatement:
                    AuxStatement ErrorStatement
                    |ErrorStatement
                    ;

Expr:
                    Expr ASSIGN Expr
                    |Expr COMMA Expr
                    |LPAR error RPAR
                    |ID LPAR error RPAR    
                    |ExprOperations
                    |ExprLogical
                    |ExprRelation
                    |ExprUnary
                    |ExprFunction
                    |ExprPrimary
                    ;

                   
                    
                  

ExprRelation:
                    Expr EQ Expr
                    |Expr NE Expr
                    |Expr LE Expr
                    |Expr GE Expr
                    |Expr LT Expr
                    |Expr GT Expr
                    ;

ExprLogical:
                    Expr OR Expr
                    |Expr AND Expr
                    |Expr BITWISEAND Expr
                    |Expr BITWISEOR Expr
                    |Expr BITWISEXOR Expr
                    ;
ExprOperations:
                    Expr PLUS Expr
                    |Expr MINUS Expr
                    |Expr MUL Expr
                    |Expr DIV Expr
                    |Expr MOD Expr
                    ;
ExprFunction:
                    ID LPAR RPAR
                    |ID LPAR Expr RPAR
                    ;

ExprUnary:
                    PLUS Expr
                    |MINUS Expr
                    |NOT Expr
                    ;

ExprPrimary:
                    ID
                    |INTLIT
                    |REALLIT
                    |CHRLIT
                    |LPAR Expr RPAR
                    ;



%%
