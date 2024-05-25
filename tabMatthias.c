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

const char* TypesNames[] = {"TYPE_ERROR", "TYPE_INT", "TYPE_VOID", "TYPE_STRUCT"};

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

LinkedList symbol_table[SIZE];

typedef struct {
    LinkedList* list[MAX];
    int length;
} Tas;

Tas tas;

int isEmpty(Tas t) {
    return t.length == 0;
}

void addinTas(Tas* t, LinkedList* ts) {
    t->list[t->length++] = ts;
}

void popTas(Tas* t) {
    if (!isEmpty(*t)) {
        t->length--;
    }
}

LinkedList* getTopTas(Tas* t) {
    if (!isEmpty(*t)) {
        return t->list[t->length - 1];
    }
    return NULL;
}

int fonction_hash(char* name) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash += name[i];
    }
    return hash % SIZE;
}

void initialize_tas(Tas* t) {
    for (int i = 0; i < MAX; i++) {
        t->list[i] = NULL;
    }
    t->length = 0;
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
            free(temp->symbole.name);
            free(temp);
        }
        table[i].head = NULL;
        table[i].length = 0;
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

void update_symbol(LinkedList* table, char* old_name, char* new_name, SymboleType type) {
    Symbole* symbol = find_symbol(table, old_name);
    if (symbol != NULL) {
        free(symbol->name);
        symbol->name = strdup(new_name);
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

LinkedList* copyLinkedList(LinkedList* l) {
    LinkedList* newll = (LinkedList*)malloc(SIZE * sizeof(LinkedList));
    initialize_table(newll);
    for (int i = 0; i < SIZE; i++) {
        Node* current = l[i].head;
        while (current != NULL) {
            insert_symbol(newll, current->symbole.name, current->symbole.type);
            current = current->next;
        }
    }
    return newll;
}

int main(void) {
    initialize_tas(&tas);
    initialize_table(symbol_table);

    insert_symbol(symbol_table, "Bi", TYPE_INT);
    insert_symbol(symbol_table, "Zon", TYPE_STRUCT);
    insert_symbol(symbol_table, "Fu", TYPE_VOID);
    insert_symbol(symbol_table, "T", TYPE_ERROR);

    LinkedList* test = getTopTas(&tas);
    if (test != NULL) {
        print_symbol_table(test);
    } else {
        printf("Pile vide\n");
    }
    LinkedList* ll = copyLinkedList(symbol_table);
    print_symbol_table(ll);
    update_symbol(ll, "Bi", "TE", TYPE_INT);
    print_symbol_table(ll);
    print_symbol_table(ll);

    print_symbol_table(symbol_table);



    clear_table(ll);
    free(ll);

    return 0;
}