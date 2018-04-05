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


no *createNode(char *label, char *value);
void addChild(no* father, no* child);
void addBrother(no* oldbro, no* newbro);
void printAST(no *current, int n);