#ifndef _yy_defines_h_
#define _yy_defines_h_

#define IDENTIFIER 257
#define CONSTANT 258
#define SIZEOF 259
#define PTR_OP 260
#define LE_OP 261
#define GE_OP 262
#define EQ_OP 263
#define NE_OP 264
#define AND_OP 265
#define OR_OP 266
#define EXTERN 267
#define INT 268
#define VOID 269
#define STRUCT 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define FOR 274
#define RETURN 275
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int intval;
    char* id;
    SymboleType symtype;
    struct Symbole* symptr;
    struct Node* nnode;
    struct LinkedList* ll;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
