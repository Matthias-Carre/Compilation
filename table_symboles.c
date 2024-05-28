#include "table_symboles.h"

const char * typesNamesChar[]={"ERR","INT","VOID","Struct"};
LinkedList symbol_table[SIZE];
Tas tas;

const char* TypesNames[] = {
    "TYPE_ERROR",
    "TYPE_INT",
    "TYPE_VOID",
    "TYPE_STRUCT"
};

Node* create_node(char* name, SymboleType type) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->symbole.name = strdup(name);
        new_node->symbole.type = type;
        new_node->next = NULL;
    }
    return new_node;
}

void delete_node(Node* node) {
    if (node != NULL) {
        free(node->symbole.name);
        free(node);
    }
}

int fonction_hash(char* name) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash += name[i];
    }
    return hash % SIZE;
}

LinkedList* getTopTas(Tas* t) {
    if (t->length > 0) {
        return t->list[t->length - 1];
    }
    return NULL;
}


void initialize_tas(Tas* t) {
    for (int i = 0; i < MAX; i++) {
        t->list[i] = NULL;
    }
    t->length = 0;
}

void addinTas(Tas* t, LinkedList* ts) {
    if (t->length < MAX) {
        t->list[t->length] = ts;
        t->length++;
        //print_symbol_table(t->list[t->length - 1]);

    } else {
        //tas plein
    }
}

int isEmpty(Tas t) {
    return t.length == 0;
}



void popTas(Tas* t) {
    t->length--;
}

void initialize_table(LinkedList* table) {
    for (int i = 0; i < SIZE; i++) {
        table[i].head = NULL;
        table[i].length = 0;
    }
}

void clear_table(LinkedList* table) {
    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete_node(temp);
        }
        table[i].head = NULL;
    }
}

Symbole* find_symbol(LinkedList* table, char* name) {
    int index = fonction_hash(name);
    Node* current = table[index].head;
    while (current != NULL) {
        if (strcmp(current->symbole.name, name) == 0) {
            return &(current->symbole);
        }
        current = current->next;
    }
    return NULL;
}


void insert_symbol(LinkedList* table, char* name, SymboleType type) {
    int index = fonction_hash(name);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->symbole.name = strdup(name);
    new_node->symbole.type = type;
    new_node->next = table[index].head;
    table[index].head = new_node;
    table[index].length++;
}
void add_symbol(LinkedList* tab,char* name,SymboleType st){
    if(find_symbol(tab,name)==NULL){
        insert_symbol(tab,name,st);
    }else{
        update_symbol(tab,name,st);
    }
}
void insert_symbol_toptas(Tas t,char* name,SymboleType type){
    LinkedList* ll = getTopTas(&t);
    add_symbol(ll,name,type);
}

void update_symbol(LinkedList *table, char *name, SymboleType type)
{
    Symbole *symbol = find_symbol(table, name);
    if (symbol != NULL)
    {
        symbol->type = type;
    }
}
void print_symbol_table(LinkedList* table) {
    printf("\n%15s | %15s | %15s |\n", "TABLE", "NOM", "TYPE");

    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            printf("table[%d]\t| %15s | %15s |\n", i, current->symbole.name, TypesNames[current->symbole.type]);
            current = current->next;
        }
    }
}
void printLLfromTas(Tas *t)
{
    for (int i = 0; i < t->length; i++)
    {
        printf("Table Des Symboles n°%d\n", i);
        print_symbol_table(t->list[i]);
    }
}


LinkedList* copyLinkedList(LinkedList* table) {
    LinkedList* newll = (LinkedList*)malloc(sizeof(LinkedList) * SIZE);
    initialize_table(newll);
    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            insert_symbol(newll, current->symbole.name, current->symbole.type);
            current = current->next;
        }
    }
    return newll;
}

void copyAndUpdateTableInTas(Tas* t, char* new_symbol_name, SymboleType new_symbol_type) {
    LinkedList* top_table = getTopTas(t);
    if (top_table != NULL) {
        LinkedList* new_table = copyLinkedList(top_table);
        insert_symbol(new_table, new_symbol_name, new_symbol_type);
        popTas(t);
        addinTas(t, new_table);
    }
}

void expandTas(Tas* t) {
    if (t->length > 0 && t->length < MAX) {
        LinkedList* top_table = getTopTas(t);
        if (top_table != NULL) {
            for (int i = t->length; i > 0; i--) {
                t->list[i] = t->list[i - 1];
            }
            t->length++;
            t->list[0] = copyLinkedList(top_table);
        } else {
            printf("Tas vide\n");
        }
    } else {
        printf("Tas plein\n");
    }
}


char* concat(char * a,char * b){
    size_t la = strlen(a);
    size_t lb = strlen(b);

    char* res = malloc(la+lb+1);
    for(int i=0;i<la;i++){
        res[i]=a[i];
    }

    for(int i=0;i<lb;i++){
        res[i+la]=b[i];
    }

    return res;
}
char* increm(int *c,char* name){
    char chiffre[20];
    sprintf(chiffre,"%d",*c);
    (*c)++;
    return concat(name,chiffre);
}
