%{
#include "table_symboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *msg) {
    fprintf(stderr, "Erreur de syntaxe : %s\n", msg);
}

extern LinkedList symbol_table[SIZE];

%}

%union {
    int intval;
    char* id;
    SymboleType symtype;
    struct Symbole* symptr;
    struct Node* nnode;
    struct LinkedList* ll;
}

%token <id> IDENTIFIER CONSTANT
%token SIZEOF PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP EXTERN INT VOID STRUCT IF ELSE WHILE FOR RETURN 

%type <symtype> type_specifier declaration_specifiers struct_specifier
%type <id> declarator direct_declarator

%start program

%%

primary_expression
        : IDENTIFIER {
            Symbole* sym = find_symbol(symbol_table, $1);
            if (sym == NULL) {
                fprintf(stderr, "Erreur : Identifiant non déclaré %s\n", $1);
                YYERROR;
            }
        }
        | CONSTANT
        | '(' expression ')'
        ;

postfix_expression
        : primary_expression
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
        ;

argument_expression_list
        : expression
        | argument_expression_list ',' expression
        ;

unary_expression
        : postfix_expression
        | unary_operator unary_expression
        | SIZEOF unary_expression
        ;

unary_operator
        : '&'
        | '*'
        | '-'
        ;

multiplicative_expression
        : unary_expression
        | multiplicative_expression '*' unary_expression
        | multiplicative_expression '/' unary_expression
        ;

additive_expression
        : multiplicative_expression
        | additive_expression '+' multiplicative_expression
        | additive_expression '-' multiplicative_expression
        ;

relational_expression
        : additive_expression
        | relational_expression '<' additive_expression
        | relational_expression '>' additive_expression
        | relational_expression LE_OP additive_expression
        | relational_expression GE_OP additive_expression
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression
        | equality_expression NE_OP relational_expression
        ;

logical_and_expression
        : equality_expression
        | logical_and_expression AND_OP equality_expression
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression
        ;

expression
        : logical_or_expression
        | unary_expression '=' expression
        ;

declaration
        : declaration_specifiers declarator ';' {
            Symbole* sym = find_symbol(symbol_table, $2);
            if (sym != NULL) {
                fprintf(stderr, "Erreur : Identifiant déjà déclaré %s\n", $2);
                YYERROR;
            } else {
                Symbole new_sym;
                new_sym.name = $2;
                new_sym.type = $1;
                insert_symbol(symbol_table, $2, $1);
            }
        }
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier { $$ = $2; }
        | type_specifier { $$ = $1; }
        ;

type_specifier
        : VOID { $$ = TYPE_VOID; }
        | INT { $$ = TYPE_INT; }
        | struct_specifier { $$ = TYPE_STRUCT; }
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}' { $$ = TYPE_STRUCT; }
        | STRUCT '{' struct_declaration_list '}' { $$ = TYPE_STRUCT; }
        | STRUCT IDENTIFIER { $$ = TYPE_STRUCT; }
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : '*' direct_declarator { $$ = $2; }
        | direct_declarator { $$ = $1; }
        ;

direct_declarator
        : IDENTIFIER { $$ = $1; }
        | '(' declarator ')' { $$ = $2; }
        | direct_declarator '(' parameter_list ')' { $$ = $1; }
        | direct_declarator '(' ')' { $$ = $1; }
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        ;

statement
        : compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;

selection_statement
        : IF '(' expression ')' statement
        | IF '(' expression ')' statement ELSE statement
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';'
        | RETURN expression ';'
        ;

program
        : external_declaration
        | program external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        ;

function_definition
        : declaration_specifiers declarator compound_statement
        ;

%%

int main() {
    initialize_table(symbol_table);
    yyparse();
    return 0;
}
