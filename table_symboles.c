#include "table_symboles.h"

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
    Node* new_node = create_node(name, type);
    if (new_node != NULL) {
        new_node->next = table[index].head;
        table[index].head = new_node;
        table[index].length++;
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

int isEmpty(Tas t) {
    return t.length == 0;
}

void addinTas(Tas t, LinkedList ts) {
    t.length++;
    t.list[t.length] = &ts;
}

void popTas(Tas t) {
    t.length--;
}

LinkedList getTopTas(Tas t) {
    return *(t.list[t.length - 1]);
}

void initialize_tas(Tas* t) {
    for (int i = 0; i < MAX; i++) {
        t->list[i] = NULL;
    }
    t->length = 0;
}
