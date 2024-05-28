#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

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

typedef struct{
    SymboleType type;
    char * code;
    char * namevar;
}Element;

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

extern LinkedList symbol_table[SIZE];

typedef struct {
    LinkedList* list[MAX];
    int length;
} Tas;

extern Tas tas;

Node* create_node(char* name, SymboleType type);
void delete_node(Node* node);
void insert_symbol(LinkedList* table, char* name, SymboleType type);
Symbole* find_symbol(LinkedList* table, char* name);
void update_symbol(LinkedList* table, char* name, SymboleType type);
void initialize_table(LinkedList* table);
int fonction_hash(char* name);
void print_symbol_table(LinkedList* table);
void insert_symbol_toptas(Tas t,char* name,SymboleType type);
void printLLfromTas(Tas *t);
LinkedList* copyLinkedList(LinkedList* table);
void copyAndUpdateTableInTas(Tas* t, char* new_symbol_name, SymboleType new_symbol_type);
void expandTas(Tas* t);
void add_symbol(LinkedList* tab,char* name,SymboleType st);
int isEmpty(Tas t);
void addinTas(Tas* t, LinkedList* ts);
void popTas(Tas* t);
LinkedList * getTopTas(Tas *t);
void initialize_tas(Tas* t);
char* concat(char * a,char * b);
char* increm(int* c,char* name);

#endif
