
%{
#include "table_symboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
void yyerror(const char *msg);
int yylex(void);
char * typesNames[]={"error","int","void","struct"};

int valtmp;
//extern int yylval; // Définition de yylval

%}

%union {
        int integer;
        char * code;
        char * str;
        char * varname;
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
//%type <id> declarator direct_declarator

%token <elem> SIZEOF PTR_OP LE_OP GE_OP EQ_OP NE_OP 
%token <elem> AND_OP OR_OP EXTERN INT VOID STRUCT IF ELSE WHILE FOR RETURN
//%token <integer> CONSTANT
//%token <elem> IDENTIFIER

%type <elem> type_specifier declaration_specifiers struct_specifier additive_expression multiplicative_expression primary_expression expression argument_expression_list
%type <elem> logical_or_expression logical_and_expression equality_expression relational_expression unary_expression postfix_expression
%type <elem> open_accol close_accol declarator direct_declarator struct_declaration parameter_declaration 
%type <elem> iteration_statement expression_statement statement compound_statement selection_statement jump_statement
%type <id> unary_operator 
%type <elem> parameter_list
%nonassoc THEN
%nonassoc ELSE
%start program


%%

primary_expression
        : IDENTIFIER {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_INT;
                e->code=$1;
                $$=e;
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
                Element * e = malloc(sizeof(Element));
                e->type = TYPE_INT;
                e->code = $1;
                $$=e;
        }
        | '(' expression ')' {
                $$ = $2;
                $$->code=$2->code;
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

                printf("Yacc code 3adrs:%s(%s)\n",$1->code,$3->code);
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
                if($1=="-"){
                        char chiffre[20];
                        sprintf(chiffre,"%d",valtmp);
                        valtmp++;
                        char* var=concat("_t",chiffre);
                        
                        printf("Yacc code 3adrs:%s = %s * -1\n",var,$2->code);
                        $$=$2;
                        $$->code = var;
                }else{
                        char * res=concat($1,$2->code);
                        $$ = $2;
                        $$->code=res;
                }
                
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
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s * %s\n",var,$1->code,$3->code);
                $$->code = var;
        }
        | multiplicative_expression '/' unary_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '/' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s / %s\n",var,$1->code,$3->code);
                $$->code = var;
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
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s + %s\n",var,$1->code,$3->code);
                $$->code = var;
        }
        | additive_expression '-' multiplicative_expression {
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '-' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                $$->type = TYPE_INT;
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s - %s\n",var,$1->code,$3->code);
                $$->code = var;
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
                if ($1->type != TYPE_INT || $3->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Assignation entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                printf("yacc code 3adrs:%s = %s;\n",$1->code,$3->code);
                $$ = $1;
        }
        ;

declaration
        : declaration_specifiers declarator ';' {
               printf("yacc code 3adrs:%s %s;\n",$1->code,$2->code);
                insert_symbol_toptas(tas, $2->code, $1->type);
        }
        | struct_specifier ';' {
                // À implémenter si nécessaire
        }
        ;

declaration_specifiers
        : EXTERN type_specifier {
                $$ = $2;
                $$->code=concat("extern ",$2->code);
        }
        | type_specifier {
                $$ = $1;
        }
        ;

type_specifier
        : VOID {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_VOID;
                e->code="void";
                $$=e;
        }
        | INT {
                
                Element * e = malloc(sizeof(Element));
                e->type = TYPE_INT;
                e->code = "int";
                $$ = e;
        }
        | struct_specifier {

                $$->type = TYPE_STRUCT;
        }
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}' {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                $$=e;
        }
        | STRUCT '{' struct_declaration_list '}' {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                $$=e;
        }
        | STRUCT IDENTIFIER {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                $$=e;
        }
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'{
                //printf("yacctypesNamesCharde3adrs:~%s %s\n",$1->code,$2->code);
        }
        ;

declarator
        : '*' direct_declarator {//pointeur
                $$ = $2;
                $$->code=concat("*",$2->code);
        }
        | direct_declarator {
                $$ = $1;
        }
        ;

direct_declarator
        : IDENTIFIER {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_INT;
                e->code=$1;
                $$=e;

        }
        | '(' declarator ')' {
                $$ = $2;
        }
        | direct_declarator '(' parameter_list ')' {
                $$ = $1;
                $$->code=concat($1->code,concat("(",concat($3->code,")")));
        }
        | direct_declarator '(' ')' {
                printf("yacc code 3adrs:%s %s(){\n",typesNames[$1->type],$1->code);
                $$ = $1;
        }
        ;

parameter_list
        : parameter_declaration{
                $$=$1;
                $$->code=$1->code;
        }
        | parameter_list ',' parameter_declaration{
                $$=$1;
                $$->code=concat($1->code,concat(" , ",$3->code));
        }
        ;

parameter_declaration
        : declaration_specifiers declarator{
                $$->type = $1->type;
                $$->code = concat(typesNames[$2->type],concat(" ",$2->code));
        }
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
        }
        | open_accol declaration_list close_accol{
        }
        | open_accol declaration_list statement_list close_accol{
        }
        ;

open_accol
        :'{'{   
                //printf("DANS LE YACC:ICI LA OP8U");
                expandTas(&tas);        
        }

close_accol
        :'}'{
                printf("Yacc code 3adrs:}\n");
                popTas(&tas);
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
                /*printf("Code 3adrs:%s\n","");
               //printf("Code 3adrs:%s\n","goto condX");
               //printf("Code 3adrs:%s\n","corpX:");
               //printf("Code 3adrs:%s\n","7");
               //printf("Code 3adrs:%s\n","5");
               //printf("Code 3adrs:%s\n","condX:");
               //printf("Code 3adrs:if(%s) goto corpX\n","$4");*/
        }
        ;

jump_statement
        : RETURN ';'{
               printf("yacc code 3adrs:return;\n");
        }
        | RETURN expression ';'{
               printf("yacc code 3adrs:return %s;\n",$2->code);
        }
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
        : declaration_specifiers declarator compound_statement{
        }
        ;

%%
void yyerror(const char *msg) {
    fprintf(stderr, "Erreur de syntaxe : %s à la ligne: %d ???\n", msg, yylineno);
}

int main() {
        valtmp=0;
        initialize_tas(&tas);
        initialize_table(symbol_table);
        addinTas(&tas, symbol_table);

        yyparse();
        return 0;
        }