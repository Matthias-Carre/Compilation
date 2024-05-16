%option noyywrap
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include "y.tab.h"

 #define TOKEN_EOF 0
 extern int yylineno;
 int yylex(void);
 int yyerror(char* s);

%}

C	 [0-9]
L	 [A-Za-z]


%%
"void"       {printf("VOID\n");return VOID ;}
"extern"     {printf("EXTERN\n");return EXTERN;}
"int"        {printf("INT\n");return INT;}
"struct"     {printf("STRUCT\n");return STRUCT;}
"sizeof"     {printf("SIZEOF\n");return SIZEOF;}

"if"         {printf("IF\n");return IF;}
"else"       {printf("ELSE\n");return ELSE;}
"while"      {printf("WHILE\n");return WHILE;}
"for"        {printf("FOR\n");return FOR;}
"return"     {printf("RETURN\n");return RETURN;}

"+"		   {printf("+"); return '+' ;}
"-"		   {printf("-"); return '-' ;}
"*"		   {printf("*"); return '*' ;}
"/"		   {printf("/"); return '/' ;}

";"		   {printf(";"); return ';' ;}
"("		   {printf("("); return '(' ;}
")"	 	   {printf(")"); return ')' ;}

"{"         return '{';
"}"         return '}';
"%%"		return AND_OP;
"||"		return OR_OP;

"<="		return LE_OP;
">="		return GE_OP;
"=="		return EQ_OP;
"!="		return NE_OP;
">"		return '>';
"<"		return '<';





{C}+	 	 printf("val");return CONSTANT ;
{L}({L}|{C})*	 printf("val");return IDENTIFIER ;
[ \t\n] 	 ;

.	 { fprintf (stderr,"erreur lexicale %s à la ligne %d.\n",yytext, yylineno);}

%%
int main(){
	int token_courant=yylex();
	/*printf("Codes des tokens retournés par yylex: ");*/
	do {
		/*printf("%d ", token_courant);*/
		token_courant=yylex();
	}while (token_courant !=TOKEN_EOF);
	return(0);
}
