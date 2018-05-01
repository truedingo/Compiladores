#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {chr, integer, shortint, doubleint, voidret, charlit, reallit, intlit} basic_type;
typedef struct table * symb_list;
typedef struct table{
	char *name; //nome
	basic_type type; //tipo according to type
	symb_list next; //apontador para next
	int is_param; //bool 0 ou 1 (tem parametro ou nao)
}_s;
typedef struct functions * table_list;
typedef struct functions{
	symb_list table; //table element para table
	table_list next; //apontador next
}_t;

symb_list insert_el(char *str, basic_type t, int isParam);
void show_table();
symb_list search_el(char *str);
symb_list create_table();

#endif
