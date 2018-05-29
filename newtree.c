#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "newtree.h"

int contador_llvm = 1;
int check_entry = 0;

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
    node->print_annotation = 0;
    node->llvm_counter = NULL;
    node->annotation = NULL;

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

            if (current->annotation == NULL)
                printf("%s(%s)\n", current->label, current->value);
            else

                printf("%s(%s) - %s\n", current->label, current->value, current->annotation);
        }
        else
        {
            if (current->annotation == NULL)
                printf("%s\n", current->label);
            else
                printf("%s - %s\n", current->label, current->annotation);
        }
    }

    printAST(current->child, n + 1);
    printAST(current->brother, n);
}
// ---------------- SEMANTICS --------------------------------

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
        tabela_atual->table = newSymbol;
    }
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
    if (global->next != NULL) //Se table ja tem elementos
    {

        functions_list aux; //Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
        for (aux = global->next; aux->next != NULL; aux = aux->next)
            if (strcmp(aux->table->name, name) == 0)
            {
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
        //a lista esta vazia
        nova_funcao->args = NULL;
        nova_funcao->next = NULL;
        nova_funcao->table = newSymbol;
        global->next = nova_funcao;
    }

    return nova_funcao;
}

void insert_param(functions_list function, char *name, char *type)
{
    params_list newParam = (params_list)malloc(sizeof(_pl));

    if (name == NULL)
        newParam->name = NULL;
    else
        newParam->name = strdup(name);

    newParam->type = strdup(type);
    newParam->next = NULL;

    params_list aux = function->args;

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
        if (strcmp(param_aux->type, "void") != 0)
        {
            if (param_aux->name != NULL)
            {
                printf("%s\t%s\tparam\n", param_aux->name, param_aux->type);
            }
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
//procura parametro
params_list search_par(functions_list list, char *str)
{
    params_list aux = list->args;

    while (aux != NULL)
    {
        if (aux->name != NULL && strcmp(aux->name, str) == 0)
            return aux;

        aux = aux->next;
    }

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
        if (node->brother != NULL)
            handle_ast(node->brother);
        //return;
    }
    else if (strcmp(node->label, "FuncDefinition") == 0)
    {
        no *type_spec = node->child;
        no *id = type_spec->brother;
        no *param_list = id->brother;
        id->print_annotation = 1;
        symb_list variavel_antiga = search_el(global, id->value);
        functions_list funcao = search_table_name(id->value);

        if (variavel_antiga == NULL || funcao->args != NULL)
        {
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
                    while (param_declaration != NULL)
                    {
                        no *param_type = param_declaration->child;
                        no *param_id = param_type->brother;
                        param_type->print_annotation = 1;
                        char *param_minusculo = malloc(sizeof(param_type->label));
                        int i = 0;

                        while (param_type->label[i])
                        {
                            param_type->print_annotation = 1;
                            param_minusculo[i] = tolower(param_type->label[i]);
                            i++;
                        }
                        if (param_id != NULL)
                        {
                            param_id->print_annotation = 1;
                            insert_param(funcao, param_id->value, param_minusculo);
                        }
                        else
                        {
                            insert_param(funcao, NULL, param_minusculo);
                        }
                        param_declaration = param_declaration->brother;
                    }

                    tabela_atual = funcao;
                }
            }
        }
        if (node->child != NULL)
            handle_ast(node->child);
        tabela_atual = global;
        if (node->brother != NULL)
            handle_ast(node->brother);
        //return;
    }
    else if (strcmp(node->label, "FuncDeclaration") == 0)
    {
        no *type_spec = node->child;
        no *id = type_spec->brother;
        no *param_list = id->brother;
        symb_list variavel_antiga = search_el(global, id->value);
        functions_list funcao = search_table_name(id->value);
        id->print_annotation = 0;

        if (variavel_antiga == NULL && funcao == NULL)
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
            if (funcao->args != NULL && funcao->is_defined == 0)
            {
                funcao->args = NULL;
            }

            if (funcao->is_defined == 0)
                if (strcmp(param_list->label, "ParamList") == 0)
                {
                    no *param_declaration = param_list->child;
                    while (param_declaration != NULL)
                    {
                        no *param_type = param_declaration->child;
                        no *param_id = param_type->brother;
                        char *param_minusculo = malloc(sizeof(param_type->label));
                        int i = 0;
                        while (param_type->label[i])
                        {
                            param_type->print_annotation = 1;
                            param_minusculo[i] = tolower(param_type->label[i]);
                            i++;
                        }

                        if (param_id != NULL)
                        {
                            param_id->print_annotation = 1;
                            insert_param(funcao, param_id->value, param_minusculo);
                        }
                        else
                        {

                            insert_param(funcao, NULL, param_minusculo);
                        }

                        param_declaration = param_declaration->brother;
                    }
                }
        }
        if (node->brother != NULL)
            handle_ast(node->brother);
        //return;
    }
    else if (strcmp(node->label, "Declaration") == 0)
    {
        //inserir o simbolo na tabela atual

        no *type_spec = node->child;
        no *id = type_spec->brother;
        id->print_annotation = 1;

        //tipo de funcao
        no *aux_print = type_spec->brother->brother;

        symb_list simbolo = search_el(tabela_atual, id->value);

        if (strcmp(type_spec->label, "Double") != 0 && aux_print != NULL)
        {
            if (strcmp("RealLit", aux_print->label) == 0)
            {

                aux_print->print_annotation = 1;
            }
        }
        if (simbolo == NULL)
        {
            change_types(type_spec);
        }
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);
        //return;
    }
    else if (strcmp(node->label, "Not") == 0 || strcmp(node->label, "Or") == 0 || strcmp(node->label, "And") == 0 || strcmp(node->label, "Eq") == 0 || strcmp(node->label, "Ne") == 0 || strcmp(node->label, "Lt") == 0 || strcmp(node->label, "Gt") == 0 || strcmp(node->label, "Le") == 0 || strcmp(node->label, "Ge") == 0 || strcmp(node->label, "Mod") == 0 || strcmp(node->label, "ChrLit") == 0 || strcmp(node->label, "IntLit") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        node->annotation = strdup("int");
    }
    else if (strcmp(node->label, "Minus") == 0 || strcmp(node->label, "Plus") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        node->annotation = strdup(node->child->annotation);
    }
    else if (strcmp(node->label, "RealLit") == 0 && (node->print_annotation == 0))
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        node->print_annotation = 1;

        node->annotation = strdup("double");
    }
    else if (strcmp(node->label, "Store") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);
        //node->child->annotation
        //printf("valor do no %s \n",node->child->annotation);
        if (node->child->annotation != NULL)
        {
            node->annotation = node->child->annotation;
        }
    }
    else if (strcmp(node->label, "Comma") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        if (node->child->brother->annotation != NULL)
        {
            node->annotation = strdup(node->child->brother->annotation);
        }
    }
    else if ((strcmp(node->label, "Id") == 0) && (node->print_annotation == 0))
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        if (strcmp(node->value, "getchar") == 0)
            node->annotation = strdup("int(void)");
        else if (strcmp(node->value, "putchar") == 0)
            node->annotation = strdup("int(int)");
        else
        {
            symb_list aux;
            params_list tmp = search_par(tabela_atual, node->value);
            //se node for funcao
            if (tmp != NULL) //symb list
            {

                //printf("sou o aux->type : %s \n",aux->type);
                node->annotation = strdup(tmp->type);
            }
            else
            {
                aux = search_el(tabela_atual, node->value);

                if (aux != NULL) //symb list
                {
                    //printf("sou o no %s - %s e apareco %d vezes\n",node->label, node->value,node->number_times);
                    node->annotation = strdup(aux->type);
                }
                else
                {
                    aux = search_el(global, node->value);

                    if (aux != NULL) //param list
                    {

                        //printf("sou o no %s e apareco %d vezes\n",node->label, node->number_times);
                        node->annotation = strdup(aux->type);
                    }
                }
            }
        }
    }
    else if (strcmp(node->label, "Add") == 0 || strcmp(node->label, "Sub") == 0 || strcmp(node->label, "Mul") == 0 || strcmp(node->label, "Div") == 0 || strcmp(node->label, "BitWiseAnd") == 0 || strcmp(node->label, "BitWiseOr") == 0 || strcmp(node->label, "BitWiseXor") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        if (strcmp(node->child->annotation, node->child->brother->annotation) == 0)
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup(node->child->annotation);
        }
        else if (strcmp(node->child->annotation, "double") == 0 || strcmp(node->child->brother->annotation, "double") == 0)
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup("double");
        }
        else if (strcmp(node->child->annotation, "int") == 0 || strcmp(node->child->brother->annotation, "int") == 0)
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup("int");
        }
        else if (strcmp(node->child->annotation, "short") == 0 || strcmp(node->child->brother->annotation, "short") == 0)
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup("short");
        }
        else if (strcmp(node->child->annotation, "char") == 0 || strcmp(node->child->brother->annotation, "char") == 0)
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup("char");
        }
        else
        {
            if (node->child->brother->annotation != NULL)
                node->annotation = strdup("undef");
        }
    }
    else if (strcmp(node->label, "Call") == 0)
    {
        if (node->child != NULL)
            handle_ast(node->child);
        if (node->brother != NULL)
            handle_ast(node->brother);

        if (strcmp(node->child->value, "getchar") == 0)
        {
            if (node->child->value != NULL)
                node->annotation = strdup("int");
        }
        else if (strcmp(node->child->value, "putchar") == 0)
        {
            if (node->child->value != NULL)
                node->annotation = strdup("int");
        }

        else
        {
            symb_list aux = search_el(global, node->child->value);

            if (aux != NULL)
            {
                node->annotation = strdup(aux->type);
                node->annotation[0] = tolower(node->annotation[0]);
                strcat(node->child->annotation, "(");

                functions_list local = search_table_name(aux->name);

                params_list param = local->args;

                while (param != NULL)
                {
                    strcat(node->child->annotation, param->type);

                    if (param->next != NULL)
                        strcat(node->child->annotation, ",");

                    param = param->next;
                }
                strcat(node->child->annotation, ")");
            }
        }
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

// ------- llvm -------
void generate_llvm(no *node)
{

    if (node == NULL)
    {
        return;
    }
    //printf("node label: %s\n", node->label);
    if (strcmp(node->label, "Program") == 0)
    {
        //printf("Encontrei Program.\n");
        printf("declare i32 @putchar(i32)\ndeclare i32 @getchar()\n");

        tabela_atual = global;

        if (node->child != NULL)
            generate_llvm(node->child);
        if (node->brother != NULL)
            generate_llvm(node->brother);
        return;
    }
    if (strcmp(node->label, "FuncDefinition") == 0)
    {

        tabela_atual = global;
        char *func_name = node->child->brother->value;
        char *type = node->child->label;

        //printf("FuncDef - %s \n",type);
        if (strcmp(type, "Int") == 0)
        {
            printf("define i32 ");
        }
        else if (strcmp(type, "Void") == 0)
        {
            printf("define void ");
        }
        else if (strcmp(type, "Short") == 0)
        {
            printf("define i16 ");
        }
        else if (strcmp(type, "Char") == 0)
        {
            printf("define i8 ");
        }
        else if (strcmp(type, "Double") == 0)
        {
            printf("define double ");
        }
        printf("@%s (", func_name);

        no *type_spec = node->child;
        no *id = type_spec->brother;
        no *param_list = id->brother;

        if (strcmp(param_list->label, "ParamList") == 0)
        {

            no *param_declaration = param_list->child;
            while (param_declaration != NULL)
            {
                no *param_type = param_declaration->child;
                no *param_id = param_type->brother;
                //printf(".. %s",param_type->label);
                if (strcmp(param_type->label, "Void") == 0)
                {
                    printf(") {\n");
                }

                if (param_declaration->brother != NULL)
                {
                    if (param_id != NULL)
                    {
                        if (strcmp(param_type->label, "Int") == 0)
                        {
                            printf("i32 ");
                        }
                        else if (strcmp(param_type->label, "Short") == 0)
                        {
                            printf("i16 ");
                        }
                        else if (strcmp(param_type->label, "Char") == 0)
                        {
                            printf("i8 ");
                        }
                        else if (strcmp(param_type->label, "Double") == 0)
                        {
                            printf("double ");
                        }
                        printf("%%%s,", param_id->value);
                    }
                }
                else
                {
                    //ultimo parametro
                    if (param_id != NULL)
                    {
                        if (strcmp(param_type->label, "Int") == 0)
                        {
                            printf("i32 ");
                        }
                        else if (strcmp(param_type->label, "Short") == 0)
                        {
                            printf("i16 ");
                        }
                        else if (strcmp(param_type->label, "Char") == 0)
                        {
                            printf("i8 ");
                        }
                        else if (strcmp(param_type->label, "Double") == 0)
                        {
                            printf("double ");
                        }
                        printf("%%%s){\n", param_id->value);
                    }
                }

                param_declaration = param_declaration->brother;
            }
            tabela_atual = global;
        }
        if (node->child != NULL)
            generate_llvm(node->child);
        if (node->brother != NULL)
            generate_llvm(node->brother);
        return;
    }
    
    if (strcmp(node->label, "Return") == 0)
    {
        if (check_entry == 0)
        {
            printf("entry:\n");
            check_entry++;
        }
        printf("\tret ");
        if (node->child->label != NULL)
        {
            if (strcmp(node->child->label, "IntLit") == 0)
            {
                printf("i32 ");
            }
            else if (strcmp(node->child->label, "CharLit") == 0)
            {
                printf("i8 ");
            }
            else if (strcmp(node->child->label, "Reallit") == 0)
            {
                printf("double ");
            }

            printf("%s\n}", node->child->value);

        }
        else{
            printf("\tret void\n}");
        }
    }

    else
    {
        if (node->child != NULL)
            generate_llvm(node->child);
        if (node->brother != NULL)
            generate_llvm(node->brother);
        return;
    }
    return;
}

void end_llvm()
{
    //ver tabela global
    char *type = global->table->next->type;

    if (strcmp("void", type) == 0)
    {
        printf("\tret void\n}");
    }
}