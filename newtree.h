#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct no{
    struct no* brother;     //brother node
    struct no* child;       //child node
    char *label;               //label of node
    char *value;            //value of the node if it has any         
    int nChildren;          //number of children of said node
} no;

typedef struct table * symb_list;
typedef struct table{
	char *name; //nome
    char *type; //tipo da variavel
	symb_list next; //apontador para next
	int is_param; //bool 0 ou 1 (tem parametro ou nao)
}_s;
typedef struct plist * params_list;
typedef struct plist{
    char *name;
	char *params;
	params_list next; //apontador next
}_pl;

typedef struct functions * functions_list;
typedef struct functions{
	symb_list table; //table element para table
	params_list args;
	functions_list next; //apontador next
}_t;

symb_list insert_el(char *str,  char *type, int isParam);
symb_list search_el(char *str);
void show_table();
symb_list create_table();
void handle_ast(no* root);
no *createNode(char *label, char *value);
void addChild(no* father, no* child);
void addBrother(no* oldbro, no* newbro);
void printAST(no *current, int n);
int cntBrothers(no* root);
void change_types(no* type_spec);
void print_global_table(symb_list tabela_atual);

params_list create_params_list(char *name);
functions_list create_functions_list();