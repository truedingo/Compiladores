#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "newtree.h"

no *createNode(char *label, char *value)
{
    no *node = (no *)malloc(sizeof(no));

    if (value != NULL)
    {
        node->value = (char *)strdup(value);
    }
    else
    {
        node->value = NULL;
    }

    node->label = (char *)strdup(label);
    node->brother = NULL;
    node->child = NULL;
    node->nChildren = 0;

    return node;
}

void addChild(no *father, no *child)
{
    if (father == NULL)
        return;
    else if (child == NULL)
        return;
    else
    {
        father->child = child;
    }
}

void addBrother(no *oldbro, no *newbro)
{
    no *aux = oldbro;
    if (oldbro == NULL)
        return;
    else if (newbro == NULL)
        return;
    while (aux->brother != NULL)
    {
        aux = aux->brother;
    }
    aux->brother = newbro;
}

int cntBrothers(no *root)
{
    int cnt = 0;
    no *aux;
    aux = root;
    while (aux != NULL)
    {
        aux = aux->brother;
        cnt++;
    }
    return cnt;
}

void printAST(no *current, int n)
{
    int i;

    if (current == NULL)
    {
        return;
    }

    if (strcmp(current->label, "NULL") == 0)
    {
        printAST(current->brother, n);
        return;
    }

    if (strcmp(current->label, "NULL") != 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("..");
        }

        if (current->value != NULL)
        {
            printf("%s(%s)\n", current->label, current->value);
        }
        else
        {
            printf("%s\n", current->label);
        }
    }

    printAST(current->child, n + 1);
    printAST(current->brother, n);
}
// ---------------- SEMANTICS --------------------------------

//print global table
void print_global_table()
{
    functions_list aux = global->next;

    printf("===== Global Symbol Table =====\n");
    printf("putchar\tint(int)\n");
    printf("getchar\tint(void)\n");
    symb_list global_table = global->table->next;
    while (global_table != NULL)
    {
        // nao e funcao!
        if (global_table->is_function)
        {
            functions_list lista = search_table_name(global_table->name);
            if (global_table->name != NULL)
            {
                if (lista == NULL)
                {
                    printf("%s\t%s", global_table->name, global_table->type);
                }
                else
                {
                    params_list auxP = lista->args;
                    printf("%s\t", lista->table->name);
                    printf("%s(", lista->table->type);
                    //printf("params type: %s\n", auxP->params);
                    while (auxP != NULL)
                    {
                        printf("%s", auxP->type);
                        if (auxP->next != NULL)
                        {
                            printf(",");
                        }
                        auxP = auxP->next;
                    }
                    printf(")");
                }
                printf("\n");
            }
        }
        else
        {

            printf("%s\t%s\n", global_table->name, global_table->type);
        }
        global_table = global_table->next;
    }
    aux = global->next;
    while (aux != NULL)
    {
        if (aux->args != NULL)
            print_local_table(aux);
        aux = aux->next;
    }
    printf("\n");
}

//insere simbolo na lista da funcao atual
symb_list insert_el(char *str, char *type, int is_function)
{
    symb_list newSymbol = (symb_list)malloc(sizeof(_s));
    symb_list aux;

    newSymbol->name = strdup(str);
    newSymbol->type = strdup(type);
    newSymbol->is_function = is_function;

    newSymbol->next = NULL;

    if (tabela_atual->table != NULL) //Se table ja tem elementos
    {                                //Procura fim da lista e verifica se simbolo ja existe
        params_list aux_args = tabela_atual->args;
        while (aux_args != NULL)
        {
            if (aux_args->name != NULL)
                if (strcmp(aux_args->name, str) == 0)
                {
                    return NULL;
                }

            aux_args = aux_args->next;
        }
        aux = tabela_atual->table->next;
        if (aux != NULL)
        {
            while (aux->next != NULL)
            {
                if (strcmp(aux->name, str) == 0)
                {
                    return NULL;
                }

                aux = aux->next;
            }
            aux->next = newSymbol; //adiciona ao final da lista
        }
        else
        {
            tabela_atual->table->next = newSymbol;
        }
    }
    else
    {
        //Se nao tiver elementos a lista passa a ser este elemento
        tabela_atual->table = newSymbol;
    }
    //printf("Inseri isto: %s em %s\n", str, tabela_atual->table->name);
    return newSymbol;
}

functions_list insert_function(char *name, char *type)
{
    symb_list newSymbol = (symb_list)malloc(sizeof(_s));

    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    newSymbol->is_function = 1;
    newSymbol->next = NULL;
    //change_types(type);
    insert_el(name, type, 1);
    functions_list nova_funcao = (functions_list)malloc(sizeof(_t));
    //printf("vou tentar inserir %s\n", name);
    if (global->next != NULL) //Se table ja tem elementos
    {
        //printf("a lista nao esta vazia\n");

        functions_list aux; //Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
        for (aux = global->next; aux->next != NULL; aux = aux->next)
            if (strcmp(aux->table->name, name) == 0)
            {
                //printf("entrei aqui porque já existo %s\n", name);
                return NULL;
            }

        nova_funcao->args = NULL;
        nova_funcao->next = NULL;
        nova_funcao->table = newSymbol;
        nova_funcao->is_defined = 0;
        aux->next = nova_funcao; //adiciona ao final da lista
    }
    else
    {
        //printf("boas\n");
        //a lista esta vazia
        nova_funcao->args = NULL;
        nova_funcao->next = NULL;
        nova_funcao->table = newSymbol;
        global->next = nova_funcao;
    }
    //printf("Inseri %s em Global\n", name);

    return nova_funcao;
}

void insert_param(functions_list function, char *name, char *type)
{
    params_list newParam = (params_list)malloc(sizeof(_pl));
    //printf("no insert\n");

    if (name == NULL)
        newParam->name = NULL;
    else
        newParam->name = strdup(name);
    //printf("depois do name\n");

    newParam->type = strdup(type);
    newParam->next = NULL;

    //printf("morri no aux\n");

    params_list aux = function->args;
    //printf("fake\n");

    if (aux != NULL)
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newParam;
    }
    else
    {
        function->args = newParam;
    }
}

void print_local_table(functions_list atual)
{
    if (atual->is_defined == 0)
        return;
    symb_list sym_aux = atual->table;
    params_list param_aux = atual->args;
    printf("\n===== Function %s Symbol Table =====\n", sym_aux->name);
    printf("return\t%s\n", atual->table->type);

    int first = 0;
    while (param_aux != NULL)
    {
        //printf("tipo param: %s\n" ,param_aux->name);
        if (strcmp(param_aux->type, "void") != 0)
        {
            printf("%s\t%s\tparam\n", param_aux->name, param_aux->type);
        }

        param_aux = param_aux->next;
    }

    while (sym_aux != NULL)
    {
        if (strcmp(sym_aux->type, "void") != 0)
        {
            if (first != 0)
            {
                printf("%s\t%s\n", sym_aux->name, sym_aux->type);
            }
        }
        first++;
        sym_aux = sym_aux->next;
    }
}
//Procura um identificador, devolve 0 caso nao exista
symb_list search_el(functions_list list, char *str)
{
    symb_list aux;
    for (aux = list->table->next; aux; aux = aux->next)
        if (strcmp(aux->name, str) == 0)
            return aux;
    return NULL;
}

functions_list search_table_name(char *str)
{
    functions_list aux;
    for (aux = global->next; aux; aux = aux->next)
        if (strcmp(aux->table->name, str) == 0)
            return aux;
    return NULL;
}

void change_types(no *type_spec)
{
    no *id = type_spec->brother;
    if (strcmp(type_spec->label, "Int") == 0)
    {
        if (id == NULL)
        {
            insert_el(NULL, "int", 0);
        }
        else
        {
            insert_el(id->value, "int", 0);
        }
    }
    if (strcmp(type_spec->label, "Void") == 0)
    {
        if (id == NULL)
        {
            insert_el(NULL, "void", 0);
        }
        else
        {
            insert_el(id->value, "void", 0);
        }
    }
    if (strcmp(type_spec->label, "Double") == 0)
    {
        if (id == NULL)
        {
            insert_el(NULL, "double", 0);
        }
        else
        {
            insert_el(id->value, "double", 0);
        }
    }
    if (strcmp(type_spec->label, "Short") == 0)
    {
        if (id == NULL)
        {
            insert_el(NULL, "short", 0);
        }
        else
        {
            insert_el(id->value, "short", 0);
        }
    }
    if (strcmp(type_spec->label, "Char") == 0)
    {
        if (id == NULL)
        {
            insert_el(NULL, "char", 0);
        }
        else
        {
            insert_el(id->value, "char", 0);
        }
    }
}

void handle_ast(no *node)
{

    if (node == NULL)
    {
        return;
    }
    //printf("node label: %s\n", node->label);
    if (strcmp(node->label, "Program") == 0)
    {
        //printf("Encontrei Program.\n");
        global = (functions_list)malloc(sizeof(_t));
        global->table = (symb_list)malloc(sizeof(_s));
        global->table->type = NULL;
        global->table->name = "global";
        global->table->next = NULL;
        global->table->is_function = 0;
        global->args = NULL;
        global->next = NULL;
        tabela_atual = global;
        if (node->child != NULL)
            handle_ast(node->child);
        return;
    }
    else if (strcmp(node->label, "FuncDefinition") == 0)
    {
        no *type_spec = node->child;
        no *id = type_spec->brother;
        no *param_list = id->brother;
        /*symb_list variavel_antiga = search_el(global, id->value);
        if (variavel_antiga == NULL)
        {*/
        symb_list variavel_antiga = search_el(global, id->value);
        functions_list funcao = search_table_name(id->value);

        if (variavel_antiga == NULL || funcao->args != NULL)
        { //printf("%s %s\n", id->value, type_spec->label);
            if (funcao == NULL || funcao->is_defined == 0)
            {
                char *label_minusculo = malloc(sizeof(type_spec->label));
                int i = 0;
                while (type_spec->label[i])
                {
                    label_minusculo[i] = tolower(type_spec->label[i]);
                    i++;
                }

                if (funcao == NULL)
                {
                    funcao = insert_function(id->value, label_minusculo);
                }
                funcao->is_defined = 1;

                if (funcao->args != NULL)
                    funcao->args = NULL;
                if (strcmp(param_list->label, "ParamList") == 0)
                {
                    no *param_declaration = param_list->child;
                    //printf("sasasas\n");
                    while (param_declaration != NULL)
                    {
                        //printf("sasasas\n");
                        no *param_type = param_declaration->child;
                        no *param_id = param_type->brother;
                        char *param_minusculo = malloc(sizeof(param_type->label));
                        int i = 0;

                        while (param_type->label[i])
                        {
                            param_minusculo[i] = tolower(param_type->label[i]);
                            i++;
                        }
                        if (param_id != NULL)
                        {
                            insert_param(funcao, param_id->value, param_minusculo);
                        }
                        else
                        {
                            insert_param(funcao, NULL, param_minusculo);
                        }
                        param_declaration = param_declaration->brother;
                    }
                    //}
                    tabela_atual = funcao;
                }
            }
        }
        if (node->child != NULL)
            handle_ast(node->child);
        tabela_atual = global;
        if (node->brother != NULL)
            handle_ast(node->brother);
        return;
    }
    else if (strcmp(node->label, "FuncDeclaration") == 0)
    {
        no *type_spec = node->child;
        no *id = type_spec->brother;
        no *param_list = id->brother;
        //if (search_el(tabela_atual, id->value) != NULL){
        //printf("Funcao %s nao definida!!\n",id->value);
        symb_list variavel_antiga = search_el(global, id->value);
        functions_list funcao = search_table_name(id->value);

        if (variavel_antiga == NULL && funcao == NULL)
        {
            //printf("%s %s\n", id->value, type_spec->label);
            char *label_minusculo = malloc(sizeof(type_spec->label));
            int i = 0;
            while (type_spec->label[i])
            {
                label_minusculo[i] = tolower(type_spec->label[i]);
                i++;
            }
            //printf("...%s...\n", label_minusculo);
            if (funcao == NULL)
            {
                funcao = insert_function(id->value, label_minusculo);
            }
            //params_list aux3;
            if (funcao->args != NULL && funcao->is_defined == 0)
            {
                //aux3 = funcao->args;
                funcao->args = NULL;
            }

            if (funcao->is_defined == 0)
                if (strcmp(param_list->label, "ParamList") == 0)
                {
                    no *param_declaration = param_list->child;
                    //printf("sasasas\n");
                    while (param_declaration != NULL)
                    {
                        //printf("sasasas\n");
                        no *param_type = param_declaration->child;
                        no *param_id = param_type->brother;
                        char *param_minusculo = malloc(sizeof(param_type->label));
                        int i = 0;
                        while (param_type->label[i])
                        {
                            param_minusculo[i] = tolower(param_type->label[i]);
                            i++;
                        }

                        if (param_id != NULL)
                        {
                            //printf("ashajsha %s    %s\n", param_id->value, param_type->label);
                            insert_param(funcao, param_id->value, param_minusculo);
                        }
                        else
                        {
                            /*if(aux3 != NULL){

                        if(aux3->name != NULL){
                    //printf("ashajsha null    %s\n", param_type->label);
                            insert_param(funcao, aux3->name, param_minusculo);
                        }
                        else{
                            insert_param(funcao, NULL, param_minusculo);
                        }
                        aux3 = aux3 ->next;
                    }
                    else{*/
                            insert_param(funcao, NULL, param_minusculo);
                        }
                        //}
                        param_declaration = param_declaration->brother;
                    }
                    //}
                }
        }
        if (node->brother != NULL)
            handle_ast(node->brother);
        return;
    }
    else if (strcmp(node->label, "Declaration") == 0)
    {
        //printf("Encontrei Declaration.\n");
        //inserir o simbolo na tabela atual
        no *type_spec = node->child;
        no *id = type_spec->brother;
        //tipo de funcao
        //printf("%s %s\n",id->label, id->value);
        //printf("%s\n", type_spec->label);
        symb_list simbolo = search_el(tabela_atual, id->value);
        if (simbolo == NULL)
        {
            change_types(type_spec);
        }
        //}

        //insert_el(id->value, type_spec->label);

        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);
        return;
    }
    else
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);
    }
    return;
}
