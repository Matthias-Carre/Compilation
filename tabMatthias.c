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

typedef struct {
    LinkedList* list[MAX];
    int length;
} Tas;

Tas tas;

int isEmpty(Tas t) {
    return t.length == 0;
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

void addinTas(Tas* t, LinkedList* ts) {
    if (t->length < MAX) {
        t->list[t->length] = ts;
        t->length++;
        printf("VAL DE LENGTH: %d\n", t->length);
        printf("Geulle du tas ajouté:");
        print_symbol_table(t->list[t->length - 1]);
        printf("Voila\n");
    } else {
        printf("Tas overflow\n");
    }
}

void popTas(Tas* t) {
    if (t->length > 0) {
        t->length--;
    }
}

LinkedList* getTopTas(Tas* t) {
    if (t->length > 0) {
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
    t->length = 0;
    for (int i = 0; i < MAX; i++) {
        t->list[i] = NULL;
    }
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

void update_symbol(LinkedList* table, char* name, SymboleType type) {
    Symbole* symbol = find_symbol(table, name);
    if (symbol != NULL) {
        symbol->type = type;
    }
}

void printLLfromTas(Tas* t) {
    for (int i = 0; i < t->length; i++) {
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




int main(void) {
    initialize_tas(&tas);
    LinkedList L[SIZE];
    LinkedList symbol_table[SIZE];
    initialize_table(L);
    initialize_table(symbol_table);

    insert_symbol(L, "Bi", TYPE_ERROR);
    insert_symbol(L, "Zon", TYPE_STRUCT);
    insert_symbol(L, "Fu", TYPE_VOID);
    insert_symbol(L, "T", TYPE_ERROR);
    insert_symbol(symbol_table, "ah", TYPE_INT);

    printf("TAB DE BASE (L):\n");
    print_symbol_table(L);
    print_symbol_table(symbol_table);
    printf("===========\n");

    LinkedList* copied_L = copyLinkedList(L);
    addinTas(&tas, copied_L);

    LinkedList* copied_symbol_table = copyLinkedList(symbol_table);
    addinTas(&tas, copied_symbol_table);

    LinkedList* copied_L2 = copyLinkedList(L);
    addinTas(&tas, copied_L);

    expandTas(&tas);

    printf("val de top0:\n");
    printLLfromTas(&tas);

    clear_table(L);
    clear_table(symbol_table);
    for (int i = 0; i < tas.length; i++) {
        clear_table(tas.list[i]);
        free(tas.list[i]);
    }

    return 0;
}
