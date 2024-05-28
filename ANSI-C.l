%{
#include <stdio.h>
#include "y.tab.h"

#define YY_NO_UNPUT

extern int yylineno;
%}

%option yylineno

C	 [0-9]
L	 [A-Za-z]

%%  

"extern"                { printf("Token: EXTERN at line %d\n", yylineno); return EXTERN; }
"if"                    { printf("Token: IF at line %d\n", yylineno); return IF; }
"int"                   { printf("Token: INT at line %d\n", yylineno); return INT; }
"return"                { printf("Token: RETURN at line %d\n", yylineno); return RETURN; }
"void"                  { printf("Token: VOID at line %d\n", yylineno); return VOID; }

{C}+	 	 		 	{ printf("Token: CONSTANT - Value: %s at line %d\n", yytext, yylineno); return CONSTANT; }
{L}({L}|{C}|"_")*	 	{ printf("Token: IDENTIFIER - Value: %s at line %d\n", yytext, yylineno); return IDENTIFIER; }

L?\"(\\.|[^\\"])*\"     { printf("Token: CONSTANT - Value: %s at line %d\n", yytext, yylineno); return CONSTANT; }

"<="                    { printf("Token: LE_OP at line %d\n", yylineno); return LE_OP; }
">="                    { printf("Token: GE_OP at line %d\n", yylineno); return GE_OP; }
"=="                    { printf("Token: EQ_OP at line %d\n", yylineno); return EQ_OP; }
"!="                    { printf("Token: NE_OP at line %d\n", yylineno); return NE_OP; }

[ \t\r\v\f]+            ; /* Ignorer les espaces, tabulations, sauts de ligne, et retours chariot */
\n                      { yylineno++; }

.                       { printf("Token: UNKNOWN - Value: %s at line %d\n", yytext, yylineno); return yytext[0]; } /* Retourner tout autre caractère individuel */

%%
