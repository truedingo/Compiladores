/* Diogo Amores 2015231975 damores@student.uc.pt */
/* Maria Roseiro 2015233281 miroseiro@student.uc.pt */

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
    no *aux1;
	no *aux;
	no *aux2;
    no *aux3;
    int stat_check=0;
    int error_check=0;
%}

%token CHAR ELSE IF INT SHORT DOUBLE RETURN VOID WHILE BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LT MINUS MOD NE NOT OR PLUS RBRACE RPAR LPAR SEMI
%token <string> ID CHRLIT REALLIT RESERVED INTLIT
%type <node> Start ExprComma ExprCall ErrorStatement AuxStatement AuxDeclarator ExprPrim ExprFunction ExprLogic ExprRelat ExprOper ExprSingleOp FuncAndDeclarations DeclarationAndStates FuncDefinition FuncDeclaration Declaration TypeSpec FuncDeclarator FuncBody Statement ParamList ParamDeclaration Declarator Expr

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GT GE LE LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left LPAR RPAR

%nonassoc ELSE

%union{
    char *string;
    struct no* node;
}

%%

Start: FuncAndDeclarations  {root = createNode("Program", NULL); addChild(root, $1);}
        ;

FuncAndDeclarations:
                    FuncDefinition {$$ = $1;} 
                    |FuncDeclaration {$$ = $1;}
                    |Declaration {$$ = $1;}
                    |FuncAndDeclarations FuncDefinition  {$$ = $1; addBrother($1, $2);}
                    |FuncAndDeclarations FuncDeclaration  {$$ = $1; addBrother($1, $2);}
                    |FuncAndDeclarations Declaration  {$$ = $1; addBrother($1, $2);}
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
                        DeclarationAndStates Statement {$$=$1; addBrother($1, $2);}
                        |DeclarationAndStates Declaration {$$=$1; addBrother($1, $2);}
                        |Statement {$$=$1;}
                        |Declaration {$$=$1;}
                        ;

FuncDeclaration: TypeSpec FuncDeclarator SEMI {$$=createNode("FuncDeclaration", NULL);
                                            addChild($$,$1);
                                            addBrother($1,$2);
                                            }
                    ;

FuncDeclarator: ID LPAR ParamList RPAR {$$=createNode("Id", $1);
                                        aux = createNode("ParamList", NULL);
                                        addChild(aux,$3);
                                        addBrother($$,aux);
                                        }
                    ;

ParamList:
                    ParamDeclaration {$$=$1;}
                    |ParamList COMMA ParamDeclaration { $$=$1;
                                                        addBrother($1,$3);}
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
                    error SEMI {$$=createNode("Error", NULL);error_check=1;}
                    | TypeSpec AuxDeclarator SEMI {
                        $$ = $2;

                        aux = $$;
                        while(aux != NULL){
                            aux->child->label = $1->label;
                            aux=aux->brother;
                        }
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
                    ID {$$ = createNode("Declaration", NULL); aux = createNode("Id", $1); aux1 = createNode("AuxNode", NULL); addChild($$, aux1); addBrother(aux1, aux);}
                    |ID ASSIGN ExprComma {$$ = createNode("Declaration", NULL); aux = createNode("Id", $1); aux1 = createNode("AuxNode", NULL); addChild($$, aux1); addBrother(aux1, aux); addBrother(aux1, $3);}
                    ;

Statement:
                    SEMI {$$=NULL;}
                    |ExprComma SEMI {$$=$1;}
                    |LBRACE RBRACE {$$=NULL;}
                    |LBRACE AuxStatement RBRACE {
                        if(stat_check == 1){
						    $$=createNode("StatList",NULL);
						    addChild($$,$2);
                        }
					    else{
						    $$ = $2;
				    	}
                    }
                    |LBRACE error RBRACE {$$=createNode("Error", NULL);error_check=1;}
                    |IF LPAR ExprComma RPAR ErrorStatement { 
                                    $$ = createNode("If",NULL);
                                    addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
										addBrother($3,aux);
                                    }
                                    else{
                                        addBrother($3, $5);
                                    }
                                    addBrother($3, createNode("Null", NULL));
                                }
                    |IF LPAR ExprComma RPAR ErrorStatement ELSE ErrorStatement {
                                    $$=createNode("If",NULL);
									addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
                                        addBrother($3,aux);
                                    }
                                    else{
                                        addBrother($3, $5);
                                    }

									if($7 == NULL){
                                        aux = createNode("Null",NULL);
                                        addBrother($3,aux);
                                    }
                                    else{
                                        addBrother($3, $7);
                                    }
                                }
                    |WHILE LPAR ExprComma RPAR ErrorStatement {
			 						$$=createNode("While",NULL);
									addChild($$,$3);
									if($5 == NULL){
                                        aux = createNode("Null",NULL);
										addBrother($3,aux);		
									}								
									else{
                                        addBrother($3,$5);
									}} 
                    |RETURN SEMI {$$=createNode("Return", NULL);
                                addChild($$, createNode("Null", NULL));
                                }
                        
                    |RETURN ExprComma SEMI {
                                    $$=createNode("Return", NULL);
                                    addChild($$, $2);
                                    }
                    ;
ErrorStatement:
                    Statement  {$$ =$1;}
                    |error SEMI {$$=createNode("Error", NULL);error_check=1;}
                    ;
AuxStatement:
                    AuxStatement ErrorStatement {stat_check = 1; $$=$1;addBrother($1,$2);}
                    |ErrorStatement {stat_check = 0; $$=$1;}
                    ; 

ExprComma: ExprComma COMMA Expr {$$ = createNode("Comma", NULL); addBrother($1, $3); addChild($$, $1);}
            | Expr {$$ = $1;}
            ;

ExprCall: ExprCall COMMA Expr {addBrother($1, $3);}
            | Expr {$$ = $1;}
            ;

Expr:              
                    Expr ASSIGN Expr {$$=createNode("Store", NULL);addChild($$,$1);addBrother($1,$3);}
                    |LPAR error RPAR {$$=createNode("Error", NULL);error_check=1;}
                    |ExprOper {$$=$1;}
                    |ExprLogic {$$=$1;}
                    |ExprRelat {$$=$1;}
                    |ExprSingleOp {$$=$1;}
                    |ExprFunction {$$=$1;}
                    |ExprPrim {$$=$1;}
                    |ID LPAR error RPAR {$$=createNode("Error", NULL);error_check=1;free($1);}
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
                    PLUS Expr %prec NOT {$$=createNode("Plus", NULL);addChild($$,$2);}
                    |MINUS Expr %prec NOT {$$=createNode("Minus", NULL);addChild($$,$2);}
                    |NOT Expr {$$=createNode("Not", NULL);addChild($$,$2);}
                    ;

ExprFunction:
                    ID LPAR RPAR {$$=createNode("Call", NULL);aux=createNode("Id",$1); addChild($$,aux);}
                    |ID LPAR ExprCall RPAR {$$=createNode("Call", NULL); aux=createNode("Id",$1); addChild($$,aux);addBrother(aux,$3);}
                    ;

ExprPrim:
                    ID {$$=createNode("Id", $1);}
                    |INTLIT {$$=createNode("IntLit", $1);}
                    |REALLIT {$$=createNode("RealLit",$1);}
                    |CHRLIT {$$=createNode("ChrLit", $1);}
                    |LPAR ExprComma RPAR {$$=$2;}
                    ;
%%