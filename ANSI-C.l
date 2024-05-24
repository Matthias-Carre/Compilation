%{
#include <stdio.h>
#include "y.tab.h"
%}

D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

/* Définition des règles */

%%  

"extern"                { return EXTERN; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"void"                  { return VOID; }

{L}({L}|{D})*           { return IDENTIFIER; }

0[xX]{H}+{IS}?          { return CONSTANT; }
0{D}+{IS}?              { return CONSTANT; }
{D}+{IS}?               { return CONSTANT; }
L?'(\\.|[^\\'])+'       { return CONSTANT; }

{D}+{E}{FS}?            { return CONSTANT; }
{D}*"."{D}+({E})?{FS}?  { return CONSTANT; }
{D}+"."{D}*({E})?{FS}?  { return CONSTANT; }

L?\"(\\.|[^\\"])*\"     { return CONSTANT; }

"<="                    { return LE_OP; }
">="                    { return GE_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }

"//"                    /* Commentaire en ligne, ignorer jusqu'à la fin de la ligne */
"/*"                    /* Commentaire multiligne, ignorer jusqu'à la fin du commentaire */
"*/"                    /* Fin du commentaire multiligne, ignorer */

[ \t\v\n\f]             ; /* Ignorer les espaces, tabulations, sauts de ligne, et retours chariot */
.                       { return yytext[0]; } /* Retourner tout autre caractère individuel */

%%
