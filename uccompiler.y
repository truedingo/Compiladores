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
    int num_erros=0;
	no *root;
    no *aux1;
	no *aux;
	no *aux2;
    no *aux3;
    int first=0;
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
                                            addBrother($1,$2);
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
                        aux=createNode("Id", $2);
                        addBrother($1,aux);
                    }
                    ;

Declaration:
                    error SEMI {$$=createNode("Null", NULL);num_erros+=1;}
                    |TypeSpec AuxDeclarator SEMI { 
                        aux = $2;
						first = 0;
						while(aux != NULL){
							aux1 = aux;
							aux = aux->brother;
							aux1->brother = NULL;
							aux2 = createNode("Declaration",NULL);
							aux3 = createNode($1->label,NULL);
							addChild(aux2,aux3);
							if(aux1->child != NULL){
								aux1->brother = aux1->child;
								aux1->child = NULL;							
							}
							addBrother(aux3,aux1);
							if(first==0){
								first = 1;							
								 $$ = aux2;
							}
							else addBrother($$,aux2);
							
						
							}
						free($1);
						
                    }
                    ;
AuxDeclarator:
                    Declarator {$$=$1;}
                    |AuxDeclarator COMMA Declarator {$$ = $1; addBrother($1,$3);}
                    ;

TypeSpec:
                    CHAR {$$=createNode("Char", NULL);}
                    |INT {$$=createNode("Int", NULL);}
                    |VOID {$$=createNode("Void", NULL);}
                    |DOUBLE {$$=createNode("Double", NULL);}
                    |SHORT {$$=createNode("Short", NULL);}
                    ;

Declarator:
                    ID {$$=createNode("Id", $1);}
                    |ID ASSIGN Expr {$$=createNode("Id", $1); addChild($$, $3); }
                    ;

Statement:
                    SEMI {$$=NULL;}
                    |Expr SEMI {$$=$1;}
                    |LBRACE RBRACE {$$=NULL;}
                    |LBRACE AuxStatement RBRACE {
                        if(cntBrothers($2) >= 2){
						    $$=createNode("StatList",NULL);
						    addChild($$,$2);
                        }
					    else{
						$$ = $2;
				    	}
                    }
                    |LBRACE error RBRACE {$$=createNode("Null", NULL);num_erros+=1;}
                    |IF LPAR Expr RPAR ErrorStatement { 
                                    $$=createNode("If",NULL);
                                    addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
										addBrother($3,aux);
                                    }	
                                }
                    |IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement {
                                    $$=createNode("If",NULL);
									addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
                                    }
                                }
                    |WHILE LPAR Expr RPAR ErrorStatement {
			 						$$=createNode("While",NULL);
									addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
										addBrother($3,aux);		
									}								
									else addBrother($3,$5);
									}                        
                    |RETURN SEMI {$$=createNode("Return", NULL);
                                addChild($$, createNode("Null", NULL));
                                }
                        
                    |RETURN Expr SEMI {
                                    $$=createNode("Return", NULL);
                                    addChild($$, $2);
                                    }
                    ;
ErrorStatement:
                    Statement  {$$ =$1;}
                    |error SEMI {$$=createNode("Null", NULL);num_erros+=1;}
                    ;
AuxStatement:
                    AuxStatement ErrorStatement {$$=$1;addBrother($1,$2);}
                    |ErrorStatement {$$=$1;}
                    ;    
Expr:              
                    Expr ASSIGN Expr {$$=createNode("Store", NULL);addBrother($$,$1);addBrother($1,$3);}
                    |Expr COMMA Expr {$$=createNode("Comma", NULL);addBrother($$,$1);addBrother($1,$3);}
                    |LPAR error RPAR {$$=createNode("Null", NULL);num_erros+=1;}
                    |ExprOper {$$=$1;}
                    |ExprLogic {$$=$1;}
                    |ExprRelat {$$=$1;}
                    |ExprSingleOp {$$=$1;}
                    |ExprFunction {$$=$1;}
                    |ExprPrim {$$=$1;}
                    |ID LPAR error RPAR {$$=createNode("Null", NULL);num_erros+=1;}
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
                    ID LPAR RPAR {$$=createNode("Call", NULL);aux=createNode("Id",$1); addChild($$,aux);}
                    |ID LPAR Expr RPAR{$$=createNode("Call", NULL);aux=createNode("Id",$1); addChild($$,aux);addBrother(aux,$3);}
                    ;


ExprPrim:
                    ID {aux=createNode("Id", $1);$$=aux;}
                    |INTLIT {aux=createNode("IntLit", $1);$$=aux;}
                    |REALLIT {aux=createNode("RealLit",$1);$$=aux;}
                    |CHRLIT {aux=createNode("ChrLit", $1);$$=aux;}
                    |LPAR Expr RPAR {$$=$2;}
                    ;
%%