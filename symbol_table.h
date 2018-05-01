#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


typedef enum {chr, integer, shortint, doubleint, voidret, charlit, reallit, intlit} basic_type;

typedef struct table{
	char *name; //nome
	basic_type type; //tipo according to type
	struct table *next; //apontador para next
	int is_param; //bool 0 ou 1 (tem parametro ou nao)
} table_element;

typedef struct functions{
	table_element* table; //table element para table
	struct functions* next; //apontador next
} functions_table;

table_element *insert_el(char *str, basic_type t, int isParam);
void show_table();
table_element *search_el(char *str);


#endif
