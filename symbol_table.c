#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>

extern table_element* symtab;

//Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element *insert_el(char *str, basic_type t, int isParam)
{
	table_element *newSymbol=(table_element*) malloc(sizeof(table_element));
	table_element *aux;
	table_element* previous;
    newSymbol->name = (char*)strdup(str);
    newSymbol->type = t;
    newSymbol->next = NULL;
    newSymbol->is_param = isParam;	

	if(symtab)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=symtab; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;
		
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		symtab=newSymbol;		
	
	return newSymbol; 
}

void show_table()
{
table_element *aux;
printf("\n");
for(aux=symtab; aux; aux=aux->next)
	printf("symbol %s, type %d, has param %d\n", aux->name, aux->type, aux->is_param);
}

//Procura um identificador, devolve 0 caso nao exista
table_element *search_el(char *str){
table_element *aux;

for(aux=symtab; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return NULL;
}





