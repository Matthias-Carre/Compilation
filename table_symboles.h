#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 201

typedef enum {
    TYPE_ERROR,
    TYPE_INT,
    TYPE_VOID,
    TYPE_STRUCT
} SymboleType;

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

#endif