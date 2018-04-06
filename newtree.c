/* Diogo Amores 2015231975 damores@student.uc.pt */
/* Maria Roseiro 2015233281 miroseiro@student.uc.pt */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "newtree.h"


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

void print_ast(no *root, int n){
    int i =0;

    if(root == NULL){
        return;
    }

    if(strcmp(root->label, "NULL") == 0){
        print_ast(root->brother, n);
        return;
    }

    else{
        for(i=0;i<n;i++){
            printf("..");
        }

        if(root->value != NULL){
            printf("%s(%s)\n",root->label, root->value);
        }
        else{
            printf("%s\n",root->label);
        }
    }
    
    print_ast(root->child, n+1);
    print_ast(root->brother, n);
}