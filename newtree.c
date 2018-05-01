#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "newtree.h"

extern symb_list symtab;
symb_list global;
symb_list tabela_atual;
extern table_list tlist;


no *createNode(char *label, char *value){
    no *node = (no*)malloc(sizeof(no));

    if(value != NULL){
        node->value = (char*)strdup(value);
    }
    
    node->label = (char*)strdup(label);
    node->brother=NULL;
    node->child=NULL;
    node->nChildren=0;

    return node;
}

void addChild(no* father, no* child){
    if(father == NULL) return;
    else if(child == NULL) return;
    else{
        father->child = child;
    }
}

void addBrother(no* oldbro, no* newbro){
    no* aux = oldbro;
    if(oldbro == NULL) return;
    else if(newbro == NULL) return;
    while(aux->brother != NULL){
        aux = aux->brother;
    }
    aux->brother = newbro;
}

int cntBrothers(no* root){
	int cnt = 0;
	no* aux;
	aux=root;
	while(aux!=NULL){
		aux=aux->brother;
		cnt++;
	}
	return cnt;
}

void printAST(no *current, int n){
    int i;

    if(current == NULL){
        return;
    }

    if(strcmp(current->label, "NULL") == 0){
        printAST(current->brother, n);
        return;
    }

    if(strcmp(current->label, "NULL") != 0){
        for(i=0;i<n;i++){
            printf("..");
        }

        if(current->value != NULL){
            printf("%s(%s)\n",current->label, current->value);
        }
        else{
            printf("%s\n",current->label);
        }
    }
    
    printAST(current->child, n+1);
    printAST(current->brother, n);
}

//Insere um novo identificador na cauda de uma lista ligada de simbolo
symb_list insert_el(char *str, basic_type t, int isParam)
{
	symb_list newSymbol=(symb_list) malloc(sizeof(symb_list));
	symb_list aux;
	symb_list previous;
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
	symb_list aux;
	printf("\n");
	for(aux=symtab; aux; aux=aux->next)
		printf("symbol %s, type %d, has param %d\n", aux->name, aux->type, aux->is_param);
}

//Procura um identificador, devolve 0 caso nao exista
symb_list search_el(char *str){
	symb_list aux;
	for(aux=symtab; aux; aux=aux->next)
		if(strcmp(aux->name, str)==0)
			return aux;
return NULL;
}

/*table_list search_table(char *str){
	table_list aux;
	for(aux=tlist; aux; aux=aux->next)
		if(strcmp(aux->table->name, str)==0)
			return aux;
return NULL;
}*/

symb_list create_table(char *name){
	symb_list new_table = (symb_list)malloc(sizeof(struct table));
	new_table->next = NULL;
	new_table->name = strdup(name);
	new_table->is_param = 0;
  	return new_table;
}

// PERCORRER ARVORE E ADICIONAR A TABELA


void handle_funcdefinition(no* root){
	no *aux = root->child;
	int aux_p = 0;
	// O primeiro filho é label da funcao
  	char *label= aux->label; 
	aux = aux->brother;

	while(strcmp(aux->label,"Id") != 0){ 
    	aux_p++;
    	aux = aux->brother;
	}
	tabela_atual = search_el(aux->label);

	if(tabela_atual == NULL){
    	tabela_atual = create_table(aux->label); //current table vai ter a tabela da função que estamos a tratar, para mais tarde sabermos em que tabela inserir os simbolos
    	tabela_atual->is_param = 1;
	}
	insert_el(tabela_atual->name,returne,0);
	
	handle_ast(root->child->brother->brother);
	}

void handle_ast(no* root){
	if (root == NULL){
		return;
	}
	if(strcmp(root->label, "Program") ==0){
		printf("Encontrei Program.\n");
		//criar tabelas global
		//dizer que e tabela atual 
		if(root->child != NULL)
    	handle_ast(root->child);
		if(root->brother != NULL)
    	handle_ast(root->brother);
    	return;
	}
	if(strcmp(root->label, "FuncDefinition") ==0){
		printf("Encontrei Func Definition.\n");
		//criar tabela func
		//global = create_table();
		//dizer que e tabela atual 
		//inserir o simbolo na tabela global
		if(root->child != NULL)
		handle_ast(root->child);
		if(root->brother != NULL)
    	handle_ast(root->brother);
    	return;
	}
		if(strcmp(root->label, "FuncDeclaration") ==0){
			printf("Encontrei Func Declaration.\n");
			//criar tabela func
			//inserir o simbolo na tabela global
			if(root->child != NULL)
			handle_ast(root->child);
			if(root->brother != NULL)
			handle_ast(root->brother);
			return;
			
	}

	if(strcmp(root->label, "Declaration") ==0){
		printf("Encontrei Declaration.\n");
		//inserir o simbolo na tabela atual
		if(root->child != NULL)
		handle_ast(root->child);
		if(root->brother != NULL)
		handle_ast(root->brother);
		return;
	}
	
}




