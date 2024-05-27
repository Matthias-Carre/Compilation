%{
#include "table_symboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
void yyerror(const char *msg);
int yylex(void);


//extern int yylval; // Définition de yylval

%}

%union {
    int intval;
    char* id;
    SymboleType symtype;
    Symbole* symptr;
    Node* nnode;
    LinkedList* ll;
    Element* elem;
}

%token <id> IDENTIFIER CONSTANT
//%token SIZEOF PTR_OP LE_OP GE_OP EQ_OP NE_OP
//%token AND_OP OR_OP EXTERN INT VOID STRUCT IF ELSE WHILE FOR RETURN
//%type <symtype> type_specifier declaration_specifiers struct_specifier additive_expression multiplicative_expression primary_expression expression argument_expression_list
//%type <symtype> logical_or_expression logical_and_expression equality_expression relational_expression unary_expression postfix_expression 
%type <id> declarator direct_declarator


%token <elem> SIZEOF PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token <elem> AND_OP OR_OP EXTERN INT VOID STRUCT IF ELSE WHILE FOR RETURN

%type <elem> type_specifier declaration_specifiers struct_specifier additive_expression multiplicative_expression primary_expression expression argument_expression_list
%type <elem> logical_or_expression logical_and_expression equality_expression relational_expression unary_expression postfix_expression
%type <elem> open_accol close_accol 
%type <elem> iteration_statement expression_statement statement compound_statement selection_statement jump_statement
%type <id> unary_operator
%nonassoc THEN
%nonassoc ELSE
%start program


%%

primary_expression
        : IDENTIFIER {
                printf("test1\n");

                $$->code = $1;
                /*
                Symbole* sym = find_symbol(getTopTas(&tas), $1->type);
                if (sym) {
                    $$ = sym->type;
                } else {
                    fprintf(stderr, "Erreur: Identifiant %s non déclaré à la ligne %d\n", $1->type, yylineno);
                    YYERROR;
                }*/
        }
        | CONSTANT {
                printf("test1\n");
                $$->type = TYPE_INT;
        }
        | '(' expression ')' {
                $$ = $2;
        }
        ;

postfix_expression
        : primary_expression {
                $$ = $1;
        }
        | postfix_expression '(' ')' {
                $$ = $1;
        }
        | postfix_expression '(' argument_expression_list ')' {
                $$ = $1;
        }
        | postfix_expression '.' IDENTIFIER {
                $$->type=TYPE_INT;
        }
        | postfix_expression PTR_OP IDENTIFIER {
                $$->type=TYPE_INT;
        }
        ;

argument_expression_list
        : expression {
                $$ = $1;
        }
        | argument_expression_list ',' expression {
                $$ = $1;
        }
        ;

unary_expression
        : postfix_expression {
                $$ = $1;
        }
        | unary_operator unary_expression {
                printf("test de unaryope:%s",$1);
                $$ = $2;
        }
        | SIZEOF unary_expression {
                $$->type = TYPE_INT;
        }
        ;

unary_operator
        : '&'{$$ = "&";}
        | '*'{$$ = "*";}
        | '-'{$$ = "-";}
        ;

multiplicative_expression
        : unary_expression {
                $$ = $1;
        }
        | multiplicative_expression '*' unary_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '*' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | multiplicative_expression '/' unary_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '/' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

additive_expression
        : multiplicative_expression {
                $$ = $1;
        }
        | additive_expression '+' multiplicative_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '+' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | additive_expression '-' multiplicative_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '-' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

relational_expression
        : additive_expression {
                $$ = $1;
        }
        | relational_expression '<' additive_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '<' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | relational_expression '>' additive_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '>' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | relational_expression LE_OP additive_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '<=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | relational_expression GE_OP additive_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '>=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

equality_expression
        : relational_expression {
                $$ = $1;
        }
        | equality_expression EQ_OP relational_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '==' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        | equality_expression NE_OP relational_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '!=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

logical_and_expression
        : equality_expression {
                $$ = $1;
        }
        | logical_and_expression AND_OP equality_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '&&' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

logical_or_expression
        : logical_and_expression {
                $$ = $1;
        }
        | logical_or_expression OR_OP logical_and_expression {
                if($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '||' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
        }
        ;

expression
        : logical_or_expression {
                $$ = $1;
        }
        | unary_expression '=' expression {
                /*if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Assignation entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }*/
                $$ = $1;
        }
        ;

declaration
        : declaration_specifiers declarator ';' {
                insert_symbol_toptas(tas, $2, $1->type);
        }
        | struct_specifier ';' {
                // À implémenter si nécessaire
        }
        ;

declaration_specifiers
        : EXTERN type_specifier {
                $$ = $2;
        }
        | type_specifier {
                $$ = $1;
        }
        ;

type_specifier
        : VOID {
                $$->type = TYPE_VOID;
        }
        | INT {
                printf("test122\n");
                Element * e = malloc(sizeof(Element));
                e->type = TYPE_INT;
                printf("test1\n");
                $$ = e;
                printf("C'est bon\n");
        }
        | struct_specifier {
                $$->type = TYPE_STRUCT;
        }
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}' {
                $$->type = TYPE_STRUCT;
        }
        | STRUCT '{' struct_declaration_list '}' {
                $$->type = TYPE_STRUCT;
        }
        | STRUCT IDENTIFIER {
                $$->type = TYPE_STRUCT;
        }
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : '*' direct_declarator {
                $$ = $2;
        }
        | direct_declarator {
                $$ = $1;
        }
        ;

direct_declarator
        : IDENTIFIER {
                $$ = $1;
        }
        | '(' declarator ')' {
                $$ = $2;
        }
        | direct_declarator '(' parameter_list ')' {
                $$ = $1;
        }
        | direct_declarator '(' ')' {
                $$ = $1;
        }
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
        : open_accol close_accol
        | open_accol statement_list close_accol{
                printf("DANS LE YACC:on decale\n");
        }
        | open_accol declaration_list close_accol{
                printf("DANS LE YACC:on decale2\n");
        }
        | open_accol declaration_list statement_list close_accol{
                printf("DANS LE YACC:on decale3\n");
        }
        ;

open_accol
        :'{'{   
                printf("DANS LE YACC:ICI LA OP8U");
                expandTas(&tas);
                printf("DANS LE YACC:VAL DE TAILLE TAS:%d",tas.length);
                printf("DANS LE YACC:ouverture\n\n");
        }

close_accol
        :'}'{
                printf("DANS LE YACC:MAIS NON");
                //popTas(&tas);
        }

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'{
                $$=$$;
        }
        | expression ';'
        ;

selection_statement
        : IF '(' expression ')' statement %prec THEN
        | IF '(' expression ')' statement ELSE statement
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement{
                printf("Code 3adrs:%s\n","");
                printf("Code 3adrs:%s\n","goto condX");
                printf("Code 3adrs:%s\n","corpX:");
                printf("Code 3adrs:%s\n","7");
                printf("Code 3adrs:%s\n","5");
                printf("Code 3adrs:%s\n","condX:");
                printf("Code 3adrs:if(%s) goto corpX\n","$4");
        }
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
void yyerror(const char *msg) {
    fprintf(stderr, "Erreur de syntaxe : %s à la ligne: %d ???\n", msg, yylineno);
}

int main() {
    initialize_tas(&tas);
    initialize_table(symbol_table);
    addinTas(&tas, symbol_table);

    yyparse();
    return 0;
}

