/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SIZEOF = 258,                  /* SIZEOF  */
    PTR_OP = 259,                  /* PTR_OP  */
    LE_OP = 260,                   /* LE_OP  */
    GE_OP = 261,                   /* GE_OP  */
    EQ_OP = 262,                   /* EQ_OP  */
    NE_OP = 263,                   /* NE_OP  */
    AND_OP = 264,                  /* AND_OP  */
    OR_OP = 265,                   /* OR_OP  */
    EXTERN = 266,                  /* EXTERN  */
    INT = 267,                     /* INT  */
    VOID = 268,                    /* VOID  */
    STRUCT = 269,                  /* STRUCT  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    FOR = 273,                     /* FOR  */
    RETURN = 274,                  /* RETURN  */
    CONSTANT = 275,                /* CONSTANT  */
    IDENTIFIER = 276,              /* IDENTIFIER  */
    THEN = 277                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SIZEOF 258
#define PTR_OP 259
#define LE_OP 260
#define GE_OP 261
#define EQ_OP 262
#define NE_OP 263
#define AND_OP 264
#define OR_OP 265
#define EXTERN 266
#define INT 267
#define VOID 268
#define STRUCT 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define FOR 273
#define RETURN 274
#define CONSTANT 275
#define IDENTIFIER 276
#define THEN 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "structfe.y"

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

#line 125 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
