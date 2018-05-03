#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "newtree.h"

extern symb_list symtab;
symb_list func_list;
symb_list global;
symb_list tabela_atual;
functions_list flist;
params_list plist;


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
 // ---------------- SEMANTICS --------------------------------

//print global table
void print_global_table(symb_list global){
    symb_list aux = global;
    symb_list auxP;
    printf("===== Global Symbol Table =====\n");
    printf("putchar\tint(int)\n");
    printf("getchar\tint(void)\n");
    while(aux != NULL){
        // nao e funcao!
        if(aux->is_param == 0){
            printf("%s\t%s", aux->name, aux->type);
        }
        else{
            auxP = aux;
            printf("%s\t(", aux->name);
            while(auxP != NULL){
                printf("%s", auxP->type);
                if(auxP->next != NULL){
                    printf(",");
                }
                auxP = auxP->next;
            }
            printf(")\t%s", aux->type);
        }
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
}

//Insere um novo identificador na cauda de uma lista ligada de simbolo
symb_list insert_el(char *str, char *type, int isParam)
{
	symb_list newSymbol=(symb_list) malloc(sizeof(_s));
	symb_list aux;
	symb_list previous;

    newSymbol->name = strdup(str);
    newSymbol->type = strdup(type);
    newSymbol->next = NULL;
    newSymbol->is_param = isParam;	
	if(symtab)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
        for(aux=symtab; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else{  
    //symtab tem um elemento -> o novo simbolo
		symtab=newSymbol;
	
    }		
	return newSymbol; 
}

symb_list insert_el_functions(char *str, char *type, int isParam)
{
    symb_list newSymbol = flist->table;
	newSymbol =(symb_list) malloc(sizeof(_s));
	symb_list aux;
	symb_list previous;

    newSymbol->name = strdup(str);
    newSymbol->type = strdup(type);
    newSymbol->next = NULL;
    newSymbol->is_param = isParam;	
	if(func_list)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
        for(aux=func_list; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else{  
    //symtab tem um elemento -> o novo simbolo
		func_list=newSymbol;
	
    }		
	return newSymbol; 
}

params_list insert_param(char *name, char *type){
    params_list newParam=(params_list) malloc(sizeof(_pl));
	params_list aux;
	params_list previous;

    if(name == NULL)
        newParam->name = NULL;
    else
    newParam->name = strdup(name);

    newParam->params = strdup(type);
    if(plist!= NULL)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)

        for(aux=plist; aux; previous=aux, aux=aux->next){
            if(name != NULL && aux->name != NULL)
			if(strcmp(aux->name, name)==0){
				return NULL;
            }
        }
		previous->next=newParam;	//adiciona ao final da lista
	}
	else{  
    //symtab tem um elemento -> o novo simbolo
		plist=newParam;
    }		
	return newParam; 
}

void show_table()
{
	symb_list aux;
	printf("\n");
	for(aux=symtab; aux; aux=aux->next)
		printf("symbol %s, type %s, has param %d\n", aux->name, aux->type, aux->is_param);
}

void print_local_table(functions_list atual, params_list plist){
    symb_list aux = atual->table;
    params_list aux2 = plist;
    while(aux != NULL){
        printf("===== Function %s Symbol Table =====\n",  aux->name);
        while(aux2 != NULL){
        printf("%s\t%s",aux2->name, aux2->params);
        }
    aux= aux->next;
    }
}
//Procura um identificador, devolve 0 caso nao exista
symb_list search_el(char *str){
	symb_list aux;
	for(aux=symtab; aux; aux=aux->next)
		if(strcmp(aux->name, str)==0)
			return aux;
return NULL;
}

functions_list search_table_name(char *str){
	functions_list aux;
	for(aux=flist; aux; aux=aux->next)
		if(strcmp(aux->table->name, str)==0)
			return aux;
return NULL;
}
/*functions_list search_table(char *str){
	functions_list aux;
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

params_list create_params_list(){
    params_list param_p;
    param_p = (params_list)malloc(sizeof(struct plist));
	param_p->next = NULL;
    param_p->params = NULL;
  	return param_p;
}

functions_list create_functions_list(){
	functions_list new_table = (functions_list)malloc(sizeof(struct functions));
	new_table->next = NULL;
	new_table->table= NULL;
    new_table->args= NULL;
  	return new_table;
}

void change_types(no* type_spec){
    no * id = type_spec->brother;
   if(strcmp(type_spec->label, "Int") == 0){
        if (id == NULL){
            insert_el(NULL, "int", 0);
        }
        else{
            insert_el(id->value, "int", 0);
        }
    }
    if(strcmp(type_spec->label, "Void") == 0){
        if (id == NULL){
            insert_el(NULL, "void", 0);
        }
        else{
            insert_el(id->value, "void", 0);
        }
    }
    if(strcmp(type_spec->label, "Double") == 0){
        if (id == NULL){
            insert_el(NULL, "double", 0);
        }
        else{
            insert_el(id->value, "double", 0);
        }
    }
    if(strcmp(type_spec->label, "Short") == 0){
        if (id == NULL){
            insert_el(NULL, "short", 0);
        }
        else{
            insert_el(id->value, "short", 0);
        }
    }
    if(strcmp(type_spec->label, "Char") == 0){
        if (id == NULL){
            insert_el(NULL, "char", 0);
        }
        else{
            insert_el(id->value, "char", 0);
        }
    }
}

void handle_ast(no* node){
	if (node == NULL){
		return;
	}
	if(strcmp(node->label, "Program") ==0){
		//printf("Encontrei Program.\n");
		//criar tabelas global
		//dizer que e tabela atual 
		if(node->child != NULL)
    	handle_ast(node->child);
		if(node->brother != NULL)
    	handle_ast(node->brother);
    	return;
	}
	if(strcmp(node->label, "FuncDefinition") ==0){
        
        params_list amigo = create_params_list();
        no * type_spec = node->child;
        no * id = type_spec->brother;
        no * param_list = id->brother;

        //printf("Change_types\n");
        change_types(type_spec);
        //printf("Change_types\n");

        if(strcmp(param_list->label, "ParamList")==0){
                no * param_declaration = param_list->child;
                while(param_declaration != NULL){
                    no * param_type = param_declaration->child;
                    no * param_id = param_type->brother;
                    if(param_id != NULL)
                        insert_param(param_id->value, param_type->label);
                    else
                        insert_param(NULL, param_type->label);

                    param_declaration = param_declaration->brother;
                }

        }
		if(node->child != NULL)
		handle_ast(node->child);
		if(node->brother != NULL)
    	handle_ast(node->brother);
    	return;
	}
		if(strcmp(node->label, "FuncDeclaration") ==0){
			//printf("Encontrei Func Declaration.\n");
			flist = create_functions_list();
            flist->args = create_params_list();
            insert_el_functions(node->child->brother->value, node->child->label, 1);
            while(strcmp(node->child->brother->brother->label, "ParamList") == 0){
                printf("node %s\n", node->child->brother->brother->child->label);
                if(node->child != NULL)
			        handle_ast(node->child);

			    if(node->brother != NULL)
			        handle_ast(node->brother);
			    return;	
                //while(node->child->brother->brother->brother != NULL)
            }
			//inserir o simbolo na tabela global
            /*char *type = node->child->label;
            //printf("%s\n",type);
            char *id_func = node->child->brother->value;
            //printf("%s\n",id_func);
            insert_el(id_func,type,0);
            if(strcmp(node->child->brother->brother->label, "ParamList")==0){
                no *aux = node->child->brother->brother->child;
                while(aux != NULL){
                    insert_param(flist->args->params, aux->child->label);
                    //printf("label: %s\n", aux->child->label);
                    aux = aux->brother;
                }
            }*/
	
	}

	if(strcmp(node->label, "Declaration") ==0){
		printf("Encontrei Declaration.\n");
		//inserir o simbolo na tabela atual
        no * type_spec = node->child;
        //tipo de funcao
        //printf("%s %s\n",id->label, id->value);
        //printf("%s\n", type_spec->label);
        change_types(type_spec);
		if(node->child != NULL)
		    handle_ast(node->child);
		if(node->brother != NULL)
		    handle_ast(node->brother);
		return;
	}


	
}