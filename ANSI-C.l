%{
#include <stdio.h>
#include "y.tab.h"
%}

C	 [0-9]
L	 [A-Za-z]
/* Définition des règles */

%%  

"extern"                { return EXTERN; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"void"                  { return VOID; }

{C}+	 	 		 				{return CONSTANT ;}
{L}({L}|{C}|"_")*	 				{return IDENTIFIER ;}

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
