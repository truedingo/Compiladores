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
	int print_annotation;
	char *annotation;
	char * llvm_counter;
} no;

typedef struct table * symb_list;
typedef struct table{
	char *name; //nome
    char *type; //tipo da variavel
	int is_function;
	symb_list next; //apontador para next
}_s;
typedef struct plist * params_list;
typedef struct plist{
    char *name;
	char *type;
	params_list next; //apontador next
}_pl;

typedef struct functions * functions_list;
typedef struct functions{
	symb_list table; //table element para table
	params_list args;
	functions_list next; //apontador next
	int is_defined;
}_t;

symb_list insert_el(char *str,  char *type, int is_function);
symb_list search_el(functions_list list, char *str);
symb_list create_table();
void handle_ast(no* root);
no *createNode(char *label, char *value);
void addChild(no* father, no* child);
void addBrother(no* oldbro, no* newbro);
void printAST(no *current, int n);
int cntBrothers(no* root);
void change_types(no* type_spec);
void print_global_table();
void print_local_table(functions_list atual);
params_list create_params_list();
functions_list create_functions_list();
functions_list search_table_name(char *str);

functions_list global;
functions_list tabela_atual;

params_list search_par(functions_list list, char *str);

void generate_llvm(no *node);
void end_llvm();


char* convert_c_type_to_llvm_type(char* c_type);
