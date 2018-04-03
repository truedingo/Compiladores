#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {root_node, var_node, fdec_node, stat_node, op_node, ter_node, id_node} type_node;
typedef struct node* no;
typedef struct node {
	char* value;
	char* stype;
	type_node type;
	int n;
	no father;
	no bro;
	no son;
}node;


int yyparse(void);
int yylex(void);
void yyerror (const char *s);
int yylex_destroy();
no create(type_node type, char* value, char* stype);
void printftree(no n, int prof);
void addnode(no father, no novo);  //criar no
void addbro(no a, no b); //criar irmao
int cntsons(no root);
void give_type(no novo, char* type);
int verifica(no no, int sons);
int cntbros(no root);