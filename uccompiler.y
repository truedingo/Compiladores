%{
    #include <stdio.h>
	    #include <stdlib.h>
	    #include <string.h>
	    #include <stdarg.h>
    #include "ast.h"
    void yyerror(const char* s);
    int yylex();
    int yyparse();
    int cnt;
	no root;
	no aux;
	no aux2;
%}

%union{
int inteiro;
char* string;
struct node* ynode;
}

%token CHAR ELSE IF INT SHORT DOUBLE RETURN VOID WHILE BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LT MINUS MOD NE NOT OR PLUS RBRACE RPAR LPAR SEMI REALLIT RESERVED CHRLIT ID INTLIT
%type <ynode> Program FuncAndDeclarations DeclarationAndStates FuncDefinition FuncDeclaration Declaration TypeSpec FuncDeclarator FuncBody Statement ParamList ParamDeclaration Declarator Expr

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GT GE
%left LE LT
%left MUL DIV MOD
%right NOT
%right PLUS MINUS
%left LPAR RPAR

%nonassoc ELSE

%%

FuncAndDeclarations:
                    FuncDefinition 
                    |FuncDeclaration {root=create(root_node, "","Program");$$=root}
                    |Declaration {}
                    |FuncDefinition FuncAndDeclarations {}
                    |FuncDeclaration FuncAndDeclarations {}
                    |Declaration FuncAndDeclarations {}
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

FuncDeclaration: TypeSpec FuncDeclarator SEMI {{$$=$1;addbro($$,$2);}}
                    ;

FuncDeclarator: ID LPAR ParamList RPAR
                    ;

ParamList:
                    ParamDeclaration
                    |ParamDeclaration COMMA ParamList
                    ;

ParamDeclaration:
                    TypeSpec
                    |TypeSpec ID
                    ;

Declaration:
                    error SEMI 
                    |TypeSpec Declarator SEMI
                    |TypeSpec Declarator AuxDeclarator SEMI
                    ;
AuxDeclarator:
                    COMMA Declarator
                    | AuxDeclarator COMMA Declarator
                    ;

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
                    |LBRACE RBRACE
                    |LBRACE AuxStatement RBRACE
                    |LBRACE error RBRACE
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
                    |ExprOper
                    |ExprLogic
                    |ExprRelat
                    |ExprSingleOp
                    |ExprFunction
                    |ExprPrim
                    |ID LPAR error RPAR
                    ;
ExprRelat:          
                    Expr EQ Expr
                    |Expr NE Expr
                    |Expr LE Expr
                    |Expr GE Expr
                    |Expr LT Expr
                    |Expr GT Expr
                    ;

ExprOper:           
                    Expr PLUS Expr 
                    |Expr MINUS Expr
                    |Expr MUL Expr 
                    |Expr DIV Expr
                    |Expr MOD Expr 
                    ;


ExprLogic:          
                    Expr OR Expr 
                    |Expr AND Expr
                    |Expr BITWISEAND Expr 
                    |Expr BITWISEOR Expr
                    |Expr BITWISEXOR Expr 
                    ;

ExprSingleOp:       
                    PLUS Expr 
                    |MINUS Expr 
                    |NOT Expr
                    ;

ExprFunction:
                    ID LPAR RPAR
                    |ID LPAR Expr RPAR
                    ;


ExprPrim:
                    ID  
                    |INTLIT
                    |REALLIT
                    |CHRLIT
                    |LPAR Expr RPAR
                    ;


%%
