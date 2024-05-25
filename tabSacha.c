#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 201

#define MAX 100




typedef enum {
    TYPE_ERROR,
    TYPE_INT,
    TYPE_VOID,
    TYPE_STRUCT
} SymboleType;


const char* TypesNames[] = {"TYPE_ERROR","TYPE_INT","TYPE_VOID","TYPE_STRUCT"};

typedef struct {
    char* name;
    SymboleType type;
} Symbole;


typedef struct Node {
    Symbole symbole;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int length;
} LinkedList;

LinkedList symbol_table;
LinkedList symbol_table2;


//definition de la pile d'execution
typedef struct {
    LinkedList *list[MAX];
    int length;
}Tas;

Tas tas;

int isEmpty(Tas t){
    if(t.length == 0){
        return 1;
    }
    return 0;
}

void addinTas(Tas t,LinkedList ts){
    t.length++;
    t.list[t.length]=&ts;
}

void popTas(Tas t){
    t.length--;
}

LinkedList getTopTas(Tas t){
    t.length--;
    return *t.list[t.length-1];
}

int fonction_hash(char* name) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash += name[i];
    }
    return hash % SIZE;
}

void initialize_tas(Tas *t){
    for(int i=0;i<MAX;i++){
        t->list[i]=NULL;
    }
}

void initialize_table(LinkedList* table) {
    for (int i = 0; i < SIZE; i++) {
        table[i].head = NULL;
    }
}

void clear_table(LinkedList* table) {
    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->symbole.name);
            free(temp);
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
    new_node->next = NULL;

    if (table[index].head == NULL) {
        table[index].head = new_node;
    } else {
        new_node->next = table[index].head;
        table[index].head = new_node;
    }
}

void update_symbol(LinkedList* table, char* name, SymboleType type) {
    Symbole* symbol = find_symbol(table, name);
    if (symbol != NULL) {
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


void copyLinkedList(LinkedList* table,LinkedList* newll){

    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            insert_symbol(newll,current->symbole.name,current->symbole.type);
            current = current->next;
        }
    }
}

int main(void){
    symbol_table;
    symbol_table2;
    LinkedList L;
    initialize_table(&L);

    insert_symbol(&L,"Bi",TYPE_ERROR);
    insert_symbol(&L,"Zon",TYPE_STRUCT);
    insert_symbol(&L,"Fu",TYPE_VOID);
    insert_symbol(&L,"T",TYPE_ERROR);

    printf("TAB DE BASE (L):\n");
    print_symbol_table(&L);
    printf("ll:\n");
    print_symbol_table(&symbol_table);
    copyLinkedList(&L,&symbol_table);
    print_symbol_table(&L);
    print_symbol_table(&symbol_table);

    update_symbol(&L,"Bi",TYPE_INT);
    printf("apres edit :\n");
    print_symbol_table(&L);
    print_symbol_table(&symbol_table);
    return(0);
}

