%option noyywrap noinput nounput
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include "table_symboles.h"
 #include "y.tab.h"

 #define TOKEN_EOF 0
 extern int yylineno;
 int yylex(void);
 int yyerror(char* s);

%}

C	 [0-9]
L	 [A-Za-z]

%%

"void"       {return VOID ;}
"extern"     {return EXTERN;}
"int"        {return INT;}
"struct"     {return STRUCT;}
"sizeof"     {return SIZEOF;}

"if"         {return IF;}
"else"       {return ELSE;}
"while"      {return WHILE;}
"for"        {return FOR;}
"return"     {return RETURN;}

"+"		    {return '+' ;}
"-"		    {return '-' ;}
"*"		    {return '*' ;}
"/"		    {return '/' ;}

";"		    {return ';' ;}
"("		    {return '(' ;}
")"	 	    {return ')' ;}

"{"         {return '{';}
"}"         {return '}';}
"&&"		{return AND_OP;}
"||"		{return OR_OP;}

"<="		{return LE_OP;}
">="		{return GE_OP;}
"=="		{return EQ_OP;}
"!="		{return NE_OP;}
">"			{return '>';}
"<"			{return '<';}
"="			{return '=';}
"&"			{return '&';}
","			{return ',';}

"/*"([^*]|\*+[^*/])*\*+"/"			{}//skip des commentaires entre balise
"//".*"\n"							{yylineno++;}//skip des commentaires sur tout la ligne
{C}+	 	 		 				{yylval.code=strdup(yytext); return CONSTANT ;}
{L}({L}|{C}|"_")*	 				{yylval.code = strdup(yytext); return IDENTIFIER ;}
\n					 				{/*printf("Ligne act: %d\n",*/yylineno++;}
[ \t\r\v\f]+ 	 	 				;

.	 {fprintf (stderr,"erreur lexicale %c à la ligne %d .\n",yytext[0], yylineno);}

%%

/*
int main(){
	int token_courant=yylex();
	//printf("Codes des tokens retournés par yylex: ");
	do {
		printf("%d ", token_courant);
		token_courant=yylex();
	}while (token_courant !=TOKEN_EOF);
	return(0);
}*/
