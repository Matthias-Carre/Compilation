%option noyywrap
%{
 #include <stdio.h>
 #include <stdlib.h>
 #define TOKEN_EOF 0
 #define TOKEN_VAL 1
 #define TOKEN_VAR 2
 #define TOKEN_PLUS 3
 #define TOKEN_MOINS 4
 #define TOKEN_MUL 5
 #define TOKEN_DIV 6
 #define TOKEN_AFFECT 7
 #define TOKEN_FIN 8
 #define TOKEN_LPAR 9
 #define TOKEN_RPAR 10
 #define TOKEN_VOID 11

 #define TOKEN_LACO 12
 #define TOKEN_RACO 13


 #define TOKEN_EXTERN 40
 #define TOKEN_INT 41
 #define TOKEN_FOR 42
 #define TOKEN_WHILE 43
 #define TOKEN_IF 44
 #define TOKEN_ELSE 45
 #define TOKEN_RETURN 46
 #define TOKEN_STRUCT 47
 #define TOKEN_SIZEOF 48
%}
C	 [0-9]
L	 [A-Za-z]
%%
"void"       {printf("TOKEN_VOID\n");        return TOKEN_VOID ;}
"extern"     {printf("TOKEN_EXTERN \n");     return TOKEN_EXTERN;}
"for"        {printf("TOKEN_FOR \n");        return TOKEN_FOR;}
"int"        {printf("TOKEN_INT \n");        return TOKEN_INT;}
"while"      {printf("TOKEN_WHILE \n");      return TOKEN_WHILE;}
"if"         {printf("TOKEN_IF \n");         return TOKEN_IF;}
"else"       {printf("TOKEN_ELSE \n");       return TOKEN_ELSE;}
"return"     {printf("TOKEN_RETURN \n");     return TOKEN_RETURN;}
"struct"     {printf("TOKEN_STRUCT \n");     return TOKEN_STRUCT;}
"sizeof"     {printf("TOKEN_SIZEOF \n");     return TOKEN_SIZEOF;}

"+"		    return TOKEN_PLUS ;
"-"		    return TOKEN_MOINS ;
"*"		    return TOKEN_MUL ;
"/"		    return TOKEN_DIV ;
":="		return TOKEN_AFFECT ;
";"		    return TOKEN_FIN ;
"("		    return TOKEN_LPAR ;
")"	 	    return TOKEN_RPAR ;

"{"         return TOKEN_LACO;
"}"         return TOKEN_RACO;

{C}+	 	 return TOKEN_VAL ;
{L}({L}|{C})*	 return TOKEN_VAR ;
[ \t\n] 	 ;

.	 { fprintf (stderr,
		"erreur lexicale %s à la ligne %d.\n",yytext, yylineno);
	 }
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
