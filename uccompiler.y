%{
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "newtree.h"
    void yyerror(const char* s);
    int yylex();
    int yyparse();
    int cnt;
	no *root;
	no *aux;
	no *aux2;
%}

%token CHAR ELSE IF INT SHORT DOUBLE RETURN VOID WHILE BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LT MINUS MOD NE NOT OR PLUS RBRACE RPAR LPAR SEMI
%token <string> ID CHRLIT REALLIT RESERVED INTLIT
%type <node> ErrorStatement AuxStatement AuxDeclarator ExprPrim ExprFunction ExprLogic ExprRelat ExprOper ExprSingleOp FuncAndDeclarations DeclarationAndStates FuncDefinition FuncDeclaration Declaration TypeSpec FuncDeclarator FuncBody Statement ParamList ParamDeclaration Declarator Expr

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

%union{
    char *string;
    struct no* node;
}

%%

FuncAndDeclarations:
                    FuncDefinition {root=createNode("Program", NULL); addChild(root, $1);} 
                    |FuncDeclaration {root=createNode("Program",NULL);addChild(root,$1);}
                    |Declaration {root=createNode("Program",NULL);addChild(root,$1);}
                    |FuncDefinition FuncAndDeclarations {root=createNode("Program",NULL);addChild(root,$1);addBrother($1,$2);}
                    |FuncDeclaration FuncAndDeclarations {root=createNode("Program",NULL);addChild(root,$1);addBrother($1,$2);}
                    |Declaration FuncAndDeclarations {root=createNode("Program",NULL);addChild(root,$1);addBrother($1,$2);}
                    ;

FuncDefinition: TypeSpec FuncDeclarator FuncBody {$$=createNode("FuncDefinition", NULL);
                                                  addChild($$,$1);
                                                  addBrother($1,$2);
                                                  addBrother($1,$3);
                                                }
                ;

FuncBody:
            LBRACE DeclarationAndStates RBRACE {$$=createNode("FuncBody", NULL);
                                                addChild($$,$2);    
                                                }
            |LBRACE RBRACE {$$=createNode("FuncBody", NULL);}
            ;

DeclarationAndStates:
                        Statement DeclarationAndStates {$$=$2; 
                                                        addBrother($$,$1);}
                        |Declaration DeclarationAndStates {$$=$2; 
                                                        addBrother($$,$1);}
                        |Statement {$$=$1;}
                        |Declaration {$$=$1;}
                        ;

FuncDeclaration: TypeSpec FuncDeclarator SEMI {$$=createNode("FuncDeclaration", NULL);
                                            addChild($$,$1);
                                            addChild($1,$2);
                                            }
                    ;

FuncDeclarator: ID LPAR ParamList RPAR {$$=createNode("Id", NULL);
                                        aux = createNode("ParamList", NULL);
                                        addChild(aux,$3);
                                        addBrother($$,aux);
                                        }
                    ;

ParamList:
                    ParamDeclaration {$$=$1;}
                    |ParamDeclaration COMMA ParamList { $$=$3;
                                                        addBrother($3,$1);}
                    ;

ParamDeclaration:
                    TypeSpec {$$=createNode("ParamDeclaration", NULL);
                            addChild($$,$1);
                            }
                    |TypeSpec ID {
                        $$=createNode("ParamDeclaration", NULL);
                        addChild($$,$1);
                        aux=createNode("Id", NULL);
                        addChild($1,aux);
                    }
                    ;

Declaration:
                    error SEMI {$$=createNode("", NULL);}
                    |TypeSpec Declarator SEMI {$$=createNode("", NULL);}
                    |TypeSpec Declarator AuxDeclarator SEMI {$$=createNode("", NULL);}
                    ;
AuxDeclarator:
                    COMMA Declarator {$$=createNode("", NULL);}
                    |AuxDeclarator COMMA Declarator {$$=createNode("", NULL);}
                    ;

TypeSpec:
                    CHAR {$$=createNode("Char", NULL);}
                    |INT {$$=createNode("Int", NULL);}
                    |VOID {$$=createNode("Void", NULL);}
                    |DOUBLE {$$=createNode("Double", NULL);}
                    |SHORT {$$=createNode("Short", NULL);}
                    ;

Declarator:
                    ID {$$=createNode("", NULL);}
                    |ID ASSIGN Expr {$$=createNode("", NULL);}
                    ;

Statement:
                    SEMI {$$=createNode("", NULL);}
                    |Expr SEMI {$$=createNode("", NULL);}
                    |LBRACE RBRACE {$$=createNode("", NULL);}
                    |LBRACE AuxStatement RBRACE {$$=createNode("", NULL);}
                    |LBRACE error RBRACE {$$=createNode("", NULL);}
                    |IF LPAR Expr RPAR ErrorStatement {$$=createNode("", NULL);}
                    |IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement {$$=createNode("", NULL);}
                    |WHILE LPAR Expr RPAR ErrorStatement {$$=createNode("", NULL);}
                    |RETURN SEMI {$$=createNode("", NULL);}
                    |RETURN Expr SEMI {$$=createNode("", NULL);}
                    ;
ErrorStatement:
                    Statement {$$=createNode("", NULL);}
                    |error SEMI {$$=createNode("", NULL);}
                    ;

AuxStatement:
                    AuxStatement ErrorStatement {$$=createNode("", NULL);}
                    |ErrorStatement {$$=createNode("", NULL);}
                    ;            

Expr:              
                    Expr ASSIGN Expr {$$=createNode("Store", NULL);addBrother($$,$1);addBrother($1,$3);}
                    |Expr COMMA Expr {$$=createNode("Comma", NULL);addBrother($$,$1);addBrother($1,$3);}
                    |LPAR error RPAR {$$=createNode("Null", NULL);}
                    |ExprOper {$$=$1;}
                    |ExprLogic {$$=$1;}
                    |ExprRelat {$$=$1;}
                    |ExprSingleOp {$$=$1;}
                    |ExprFunction {$$=$1;}
                    |ExprPrim {$$=$1;}
                    |ID LPAR error RPAR {$$=createNode("Null", NULL);}
                    ;
ExprOper:
                    Expr PLUS Expr {$$=createNode("Add", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr MINUS Expr {$$=createNode("Sub", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr MUL Expr {$$=createNode("Mul", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr DIV Expr {$$=createNode("Div", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr MOD Expr {$$=createNode("Mod", NULL);addChild($$,$1);addBrother($1,$3);}
                    ;

ExprLogic:
                    Expr OR Expr {$$=createNode("Or", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr AND Expr {$$=createNode("And", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr BITWISEAND Expr {$$=createNode("BitWiseAnd", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr BITWISEOR Expr {$$=createNode("BitWiseOr", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr BITWISEXOR Expr {$$=createNode("BitWiseXor", NULL);addChild($$,$1);addBrother($1,$3);}
                    ;

ExprRelat:
                    Expr EQ Expr {$$=createNode("Eq", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr NE Expr {$$=createNode("Ne", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr LE Expr {$$=createNode("Le", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr GE Expr {$$=createNode("Ge", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr LT Expr {$$=createNode("Lt", NULL);addChild($$,$1);addBrother($1,$3);}
                    |Expr GT Expr {$$=createNode("Gt", NULL);addChild($$,$1);addBrother($1,$3);}
                    ;

ExprSingleOp:
                    PLUS Expr {$$=createNode("Plus", NULL);addChild($$,$2);}
                    |MINUS Expr {$$=createNode("Minus", NULL);addChild($$,$2);}
                    |NOT Expr {$$=createNode("Not", NULL);addChild($$,$2);}
                    ;

ExprFunction:
                    ID LPAR RPAR {$$=createNode("Call", NULL);aux=createNode("Id",NULL); addChild($$,aux);}
                    |ID LPAR Expr RPAR{$$=createNode("Call", NULL);aux=createNode("Id",NULL); addChild($$,aux);addBrother(aux,$3);}
                    ;


ExprPrim:
                    ID {aux=createNode("Id", NULL);$$=aux;}
                    |INTLIT {aux=createNode("IntLit", NULL);$$=aux;}
                    |REALLIT {aux=createNode("RealLit", NULL);$$=aux;}
                    |CHRLIT {aux=createNode("ChrLit", NULL);$$=aux;}
                    |LPAR Expr RPAR {$$=$2;}
                    ;
%%