%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;

int yylex(void);
void yyerror(const char *msg);
int yylex(void);
%}

%token IDENTIFIER CONSTANT 
%token LE_OP GE_OP EQ_OP NE_OP
%token EXTERN
%token INT VOID
%token IF RETURN GOTO COMMENT

%start external_declaration

%%

primary_expression
    : IDENTIFIER{
        printf("Ident L24\n");
    }
    | CONSTANT
    ;

postfix_expression
    : primary_expression
    | postfix_expression '(' ')'
    | postfix_expression '(' argument_expression_list ')'
    ;

argument_expression_list
    : primary_expression
    | argument_expression_list ',' primary_expression
    ;

unary_expression
    : postfix_expression
    | unary_operator primary_expression
    ;

unary_operator
    : '&'
    | '*'
    | '-'
    ;

multiplicative_expression
    : unary_expression
    | primary_expression '*' primary_expression
    | primary_expression '/' primary_expression
    ;

additive_expression
    : multiplicative_expression
    | primary_expression '+' primary_expression
    | primary_expression '-' primary_expression
    ;

relational_expression
    : additive_expression
    | primary_expression '<' primary_expression
    | primary_expression '>' primary_expression
    | primary_expression LE_OP primary_expression
    | primary_expression GE_OP primary_expression
    ;

equality_expression
    : relational_expression
    | primary_expression EQ_OP primary_expression
    | primary_expression NE_OP primary_expression
    ;

expression
    : equality_expression
    | unary_operator primary_expression '=' primary_expression
    | primary_expression '=' additive_expression
    ;

declaration
    : declaration_specifiers declarator ';'{
        printf("declaration l85\n");
    }
    | declaration_specifiers declarator
    ;

declaration_specifiers
    : EXTERN type_specifier
    | type_specifier
    ;

type_specifier
    : VOID
    | INT{
        printf("yacc L98\n");
    }
    ;

declarator
    : '*' direct_declarator
    | direct_declarator
    ;

direct_declarator
    : IDENTIFIER{
        printf("ident\n");

    }
    | direct_declarator '(' parameter_list ')'
    | direct_declarator '(' ')'
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
    | labeled_statement
    | expression_statement
    | selection_statement
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

labeled_statement
    : IDENTIFIER ':' statement{
        printf("ident\n");

    }
    ;

expression_statement
    : ';'
    | expression ';'
    ;

selection_statement
    : IF '(' equality_expression ')' GOTO IDENTIFIER ';'{
        printf("ICILA\n");
    }
    ;

jump_statement
    : RETURN ';'
    | RETURN expression ';'
    | GOTO IDENTIFIER ';'{
        printf("ICILA\n");
    }
    ;

external_declaration
    : function_definition
    | declaration
    ;

function_definition
    : declaration_specifiers declarator compound_statement
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Erreur de syntaxe : %s à la ligne: %d ???\n", msg, yylineno);
}


int main() {
    printf("ICI");
    yyparse();
    return 0;
}

int yywrap(void) {
    return 1;
}
