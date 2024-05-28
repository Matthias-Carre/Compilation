/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "structfe.y"

#include "table_symboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filegestion.h"

extern int yylineno;
void yyerror(const char *msg);
int yylex(void);
char * typesNames[]={"error","int","void","struct"};

Filechar* fc;

int valtmp;
int cond;
int corp;
int fin;
//extern int yylval; // Définition de yylval


#line 93 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    SIZEOF = 260,                  /* SIZEOF  */
    PTR_OP = 261,                  /* PTR_OP  */
    LE_OP = 262,                   /* LE_OP  */
    GE_OP = 263,                   /* GE_OP  */
    EQ_OP = 264,                   /* EQ_OP  */
    NE_OP = 265,                   /* NE_OP  */
    AND_OP = 266,                  /* AND_OP  */
    OR_OP = 267,                   /* OR_OP  */
    EXTERN = 268,                  /* EXTERN  */
    INT = 269,                     /* INT  */
    VOID = 270,                    /* VOID  */
    STRUCT = 271,                  /* STRUCT  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    RETURN = 276,                  /* RETURN  */
    THEN = 277                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define CONSTANT 259
#define SIZEOF 260
#define PTR_OP 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define AND_OP 266
#define OR_OP 267
#define EXTERN 268
#define INT 269
#define VOID 270
#define STRUCT 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define FOR 275
#define RETURN 276
#define THEN 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "structfe.y"

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

#line 204 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_SIZEOF = 5,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 6,                     /* PTR_OP  */
  YYSYMBOL_LE_OP = 7,                      /* LE_OP  */
  YYSYMBOL_GE_OP = 8,                      /* GE_OP  */
  YYSYMBOL_EQ_OP = 9,                      /* EQ_OP  */
  YYSYMBOL_NE_OP = 10,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 11,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 12,                     /* OR_OP  */
  YYSYMBOL_EXTERN = 13,                    /* EXTERN  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_STRUCT = 16,                    /* STRUCT  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_THEN = 22,                      /* THEN  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* '.'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '&'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_primary_expression = 39,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 40,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 41,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 42,          /* unary_expression  */
  YYSYMBOL_unary_operator = 43,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 44, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 45,       /* additive_expression  */
  YYSYMBOL_relational_expression = 46,     /* relational_expression  */
  YYSYMBOL_equality_expression = 47,       /* equality_expression  */
  YYSYMBOL_logical_and_expression = 48,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 49,     /* logical_or_expression  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 52,    /* declaration_specifiers  */
  YYSYMBOL_type_specifier = 53,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 54,          /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 55,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 56,        /* struct_declaration  */
  YYSYMBOL_declarator = 57,                /* declarator  */
  YYSYMBOL_direct_declarator = 58,         /* direct_declarator  */
  YYSYMBOL_parameter_list = 59,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 60,     /* parameter_declaration  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_compound_statement = 62,        /* compound_statement  */
  YYSYMBOL_open_accol = 63,                /* open_accol  */
  YYSYMBOL_close_accol = 64,               /* close_accol  */
  YYSYMBOL_declaration_list = 65,          /* declaration_list  */
  YYSYMBOL_statement_list = 66,            /* statement_list  */
  YYSYMBOL_expression_statement = 67,      /* expression_statement  */
  YYSYMBOL_selection_statement = 68,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 69,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 70,            /* jump_statement  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_external_declaration = 72,      /* external_declaration  */
  YYSYMBOL_function_definition = 73        /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,     2,
      23,    24,    28,    31,    26,    29,    25,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      32,    34,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    78,    84,    91,    94,    97,   105,   108,
     114,   117,   123,   126,   146,   152,   153,   154,   158,   161,
     177,   197,   200,   216,   236,   239,   247,   254,   261,   271,
     274,   281,   291,   294,   304,   307,   317,   320,   333,   339,
     345,   349,   355,   361,   368,   375,   381,   387,   396,   397,
     401,   407,   411,   417,   424,   427,   431,   440,   444,   451,
     458,   459,   460,   461,   462,   466,   467,   469,   471,   476,
     484,   492,   493,   497,   498,   502,   505,   509,   510,   528,
     529,   541,   546,   554,   555,   559,   560,   564
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "SIZEOF", "PTR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "EXTERN", "INT", "VOID", "STRUCT", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "THEN", "'('", "')'", "'.'", "','", "'&'",
  "'*'", "'-'", "'/'", "'+'", "'<'", "'>'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "expression", "declaration",
  "declaration_specifiers", "type_specifier", "struct_specifier",
  "struct_declaration_list", "struct_declaration", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
  "statement", "compound_statement", "open_accol", "close_accol",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "program", "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     168,   173,   -71,   -71,    10,   -71,   148,   -71,   -24,   180,
     -71,   -71,   -71,   -71,    36,   173,   -71,   148,    15,    45,
      -1,   -71,   -71,   -71,   173,   148,    72,   -71,    54,    -1,
     -71,   -71,   -71,    87,   186,   103,    50,   -71,   -71,   -71,
     -71,   -71,    66,    73,    75,    82,   150,    66,   -71,   -71,
     -71,   -71,   -71,   -71,   136,    92,    66,   -13,    -6,    19,
     111,   119,   135,   125,   -71,   148,   -71,   -71,   -71,    87,
     108,   -71,   -71,   -71,   -71,   -71,   148,     8,   -71,   -71,
     -71,   -71,    66,    66,   163,   -71,   134,   117,   167,    26,
     169,    66,   -71,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,   -71,   139,   -71,   -71,   108,
     -71,   -71,   -71,   -71,   168,   151,   183,   163,   -71,   -71,
     -71,   -71,    51,   -71,   -71,   -71,   -71,   -71,   -71,   -13,
     -13,    -6,    -6,    -6,    -6,    19,    19,   111,   119,   -71,
     -71,   129,   129,    66,   -71,    66,   179,   -71,   184,   -71,
     129,   129,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    43,    42,     0,    86,     0,    41,    44,     0,
      83,    85,    40,    44,    47,     0,    53,     0,     0,     0,
      52,    39,     1,    84,     0,     0,     0,    48,     0,    51,
      38,    69,    87,     0,     0,     0,     0,    46,    49,    54,
       2,     3,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    75,    70,     5,    12,    18,     0,    21,    24,    29,
      32,    34,    36,     0,    71,     0,    73,    60,    65,     0,
       0,    61,    62,    63,    64,    56,     0,     0,    57,    45,
      50,    14,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    72,    67,     0,
      74,    66,    59,    55,     0,     0,     0,     0,    82,     4,
       9,     6,     0,    10,     8,    37,    19,    20,    18,    23,
      22,    27,    28,    25,    26,    30,    31,    33,    35,    68,
      58,     0,     0,     0,     7,     0,    77,    79,     0,    11,
       0,     0,    78,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -37,   -71,    43,   106,    61,   109,
     105,   -71,   -46,   -27,   -30,     9,     7,   187,   -14,     3,
     195,   -71,   100,   -68,   196,   -71,   -61,   -71,   147,   -70,
     -71,   -71,   -71,   -71,   208,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    53,    54,   122,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     5,     6,     7,    13,    26,    27,    19,
      20,    77,    78,    66,    67,    33,    68,    69,    70,    71,
      72,    73,    74,     9,    10,    11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    87,   110,    65,    76,    81,    64,     8,   108,   111,
      12,    21,    38,    14,   117,    93,     8,    94,    16,    92,
      28,    38,    34,    95,    25,    96,    97,    98,    36,    40,
      41,    42,   113,    25,   114,    25,   115,   116,    17,    65,
       8,   110,   107,   123,    25,   125,    15,   143,   139,    47,
     121,    99,   100,    48,    49,    50,   126,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   106,    40,
      41,    42,    24,   146,   147,   144,     8,   145,    39,   112,
      30,    31,   152,   153,    76,    80,     2,     3,     4,    47,
      40,    41,    42,    48,    49,    50,    82,   148,    83,   149,
       1,     2,     3,     4,    43,    84,    44,    45,    46,    37,
      47,    40,    41,    42,    48,    49,    50,     2,     3,     4,
     101,   102,    51,    31,    52,    43,    91,    44,    45,    46,
     103,    47,    40,    41,    42,    48,    49,    50,   129,   130,
      79,   119,    88,    51,    31,    52,    43,   104,    44,    45,
      46,    16,    47,    40,    41,    42,    48,    49,    50,    89,
     105,    90,   135,   136,    51,    31,    40,    41,    42,   118,
     120,    17,   124,    47,    30,   141,    18,    48,    49,    50,
      22,     1,     2,     3,     4,    85,    47,     2,     3,     4,
      48,    49,    50,     1,     2,     3,     4,   150,    51,     1,
       2,     3,     4,   131,   132,   133,   134,   142,   151,   138,
      75,    35,   137,    29,   140,    32,   109,    23
};

static const yytype_uint8 yycheck[] =
{
      46,    47,    70,    33,    34,    42,    33,     0,    69,    70,
       1,    35,    26,     3,    84,    28,     9,    30,     3,    56,
      17,    35,    23,    29,    15,    31,     7,     8,    25,     3,
       4,     5,    24,    24,    26,    26,    82,    83,    23,    69,
      33,   109,    69,    89,    35,    91,    36,   117,   109,    23,
      24,    32,    33,    27,    28,    29,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    65,     3,
       4,     5,    36,   141,   142,    24,    69,    26,    24,    76,
      35,    36,   150,   151,   114,    35,    14,    15,    16,    23,
       3,     4,     5,    27,    28,    29,    23,   143,    23,   145,
      13,    14,    15,    16,    17,    23,    19,    20,    21,    37,
      23,     3,     4,     5,    27,    28,    29,    14,    15,    16,
       9,    10,    35,    36,    37,    17,    34,    19,    20,    21,
      11,    23,     3,     4,     5,    27,    28,    29,    95,    96,
      37,    24,     6,    35,    36,    37,    17,    12,    19,    20,
      21,     3,    23,     3,     4,     5,    27,    28,    29,    23,
      35,    25,   101,   102,    35,    36,     3,     4,     5,    35,
       3,    23,     3,    23,    35,    24,    28,    27,    28,    29,
       0,    13,    14,    15,    16,    35,    23,    14,    15,    16,
      27,    28,    29,    13,    14,    15,    16,    18,    35,    13,
      14,    15,    16,    97,    98,    99,   100,    24,    24,   104,
      24,    24,   103,    18,   114,    19,    69,     9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    14,    15,    16,    51,    52,    53,    54,    71,
      72,    73,    53,    54,     3,    36,     3,    23,    28,    57,
      58,    35,     0,    72,    36,    53,    55,    56,    57,    58,
      35,    36,    62,    63,    23,    55,    57,    37,    56,    24,
       3,     4,     5,    17,    19,    20,    21,    23,    27,    28,
      29,    35,    37,    39,    40,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    61,    62,    64,    65,
      66,    67,    68,    69,    70,    24,    52,    59,    60,    37,
      35,    42,    23,    23,    23,    35,    50,    50,     6,    23,
      25,    34,    42,    28,    30,    29,    31,     7,     8,    32,
      33,     9,    10,    11,    12,    35,    57,    51,    64,    66,
      61,    64,    57,    24,    26,    50,    50,    67,    35,    24,
       3,    24,    41,    50,     3,    50,    42,    42,    42,    44,
      44,    45,    45,    45,    45,    46,    46,    47,    48,    64,
      60,    24,    24,    67,    24,    26,    61,    61,    50,    50,
      18,    24,    61,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    43,    43,    43,    44,    44,
      44,    45,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     5,     4,     2,     1,     2,
       3,     2,     1,     1,     3,     4,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     1,
       1,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       7,     2,     3,     1,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 64 "structfe.y"
                     {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_INT;
                e->code=(yyvsp[0].id);
                (yyval.elem)=e;
                /*
                Symbole* sym = find_symbol(getTopTas(&tas), $1->type);
                if (sym) {
                    $$ = sym->type;
                } else {
                    fprintf(stderr, "Erreur: Identifiant %s non déclaré à la ligne %d\n", $1->type, yylineno);
                    YYERROR;
                }*/
        }
#line 1389 "y.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 78 "structfe.y"
                   {
                Element * e = malloc(sizeof(Element));
                e->type = TYPE_INT;
                e->code = (yyvsp[0].id);
                (yyval.elem)=e;
        }
#line 1400 "y.tab.c"
    break;

  case 4: /* primary_expression: '(' expression ')'  */
#line 84 "structfe.y"
                             {
                (yyval.elem) = (yyvsp[-1].elem);
                (yyval.elem)->code=(yyvsp[-1].elem)->code;
        }
#line 1409 "y.tab.c"
    break;

  case 5: /* postfix_expression: primary_expression  */
#line 91 "structfe.y"
                             {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1417 "y.tab.c"
    break;

  case 6: /* postfix_expression: postfix_expression '(' ')'  */
#line 94 "structfe.y"
                                     {
                (yyval.elem) = (yyvsp[-2].elem);
        }
#line 1425 "y.tab.c"
    break;

  case 7: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 97 "structfe.y"
                                                              {

                //printf("Yacc code 3adrs:%s(%s)\n",$1->code,$3->code);

                char* ligne=concat((yyvsp[-3].elem)->code,concat("(",concat((yyvsp[-1].elem)->code,")")));
                addline(fc,ligne);
                (yyval.elem) = (yyvsp[-3].elem);
        }
#line 1438 "y.tab.c"
    break;

  case 8: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 105 "structfe.y"
                                            {
                (yyval.elem)->type=TYPE_INT;
        }
#line 1446 "y.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 108 "structfe.y"
                                               {
                (yyval.elem)->type=TYPE_INT;
        }
#line 1454 "y.tab.c"
    break;

  case 10: /* argument_expression_list: expression  */
#line 114 "structfe.y"
                     {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1462 "y.tab.c"
    break;

  case 11: /* argument_expression_list: argument_expression_list ',' expression  */
#line 117 "structfe.y"
                                                  {
                (yyval.elem) = (yyvsp[-2].elem);
        }
#line 1470 "y.tab.c"
    break;

  case 12: /* unary_expression: postfix_expression  */
#line 123 "structfe.y"
                             {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1478 "y.tab.c"
    break;

  case 13: /* unary_expression: unary_operator unary_expression  */
#line 126 "structfe.y"
                                          {
                if((yyvsp[-1].id)=="-"){
                        char chiffre[20];
                        sprintf(chiffre,"%d",valtmp);
                        valtmp++;
                        char* var=concat("_t",chiffre);
                        
                        //printf("Yacc code 3adrs:%s = %s * -1\n",var,$2->code);
                        
                        char* ligne=concat(var,concat(" = ",concat((yyvsp[0].elem)->code," * -1")));
                        addline(fc,ligne);
                        (yyval.elem)=(yyvsp[0].elem);
                        (yyval.elem)->code = var;
                }else{
                        char * res=concat((yyvsp[-1].id),(yyvsp[0].elem)->code);
                        (yyval.elem) = (yyvsp[0].elem);
                        (yyval.elem)->code=res;
                }
                
        }
#line 1503 "y.tab.c"
    break;

  case 14: /* unary_expression: SIZEOF unary_expression  */
#line 146 "structfe.y"
                                  {
                (yyval.elem)->type = TYPE_INT;
        }
#line 1511 "y.tab.c"
    break;

  case 15: /* unary_operator: '&'  */
#line 152 "structfe.y"
             {(yyval.id) = "&";}
#line 1517 "y.tab.c"
    break;

  case 16: /* unary_operator: '*'  */
#line 153 "structfe.y"
             {(yyval.id) = "*";}
#line 1523 "y.tab.c"
    break;

  case 17: /* unary_operator: '-'  */
#line 154 "structfe.y"
             {(yyval.id) = "-";}
#line 1529 "y.tab.c"
    break;

  case 18: /* multiplicative_expression: unary_expression  */
#line 158 "structfe.y"
                           {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1537 "y.tab.c"
    break;

  case 19: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 161 "structfe.y"
                                                         {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '*' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s * %s\n",var,(yyvsp[-2].elem)->code,(yyvsp[0].elem)->code);
                char* ligne=concat(var,concat(" = ",concat((yyvsp[-2].elem)->code,concat(" * ",(yyvsp[0].elem)->code))));
                addline(fc,ligne);
                (yyval.elem)->code = var;
        }
#line 1558 "y.tab.c"
    break;

  case 20: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 177 "structfe.y"
                                                         {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '/' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s / %s\n",var,(yyvsp[-2].elem)->code,(yyvsp[0].elem)->code);

                char* ligne=concat(var,concat(" = ",concat((yyvsp[-2].elem)->code,concat(" / ",(yyvsp[0].elem)->code))));
                addline(fc,ligne);
                (yyval.elem)->code = var;
        }
#line 1580 "y.tab.c"
    break;

  case 21: /* additive_expression: multiplicative_expression  */
#line 197 "structfe.y"
                                    {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1588 "y.tab.c"
    break;

  case 22: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 200 "structfe.y"
                                                            {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '+' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s + %s\n",var,(yyvsp[-2].elem)->code,(yyvsp[0].elem)->code);
                char* ligne = concat(var,concat(" = ",concat((yyvsp[-2].elem)->code,concat(" + ",(yyvsp[0].elem)->code))));
                addline(fc,ligne);
                (yyval.elem)->code = var;
        }
#line 1609 "y.tab.c"
    break;

  case 23: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 216 "structfe.y"
                                                            {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '-' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;

                char chiffre[20];
                sprintf(chiffre,"%d",valtmp);
                valtmp++;
                char* var=concat("_t",chiffre);
                
                printf("Yacc code 3adrs:%s = %s - %s\n",var,(yyvsp[-2].elem)->code,(yyvsp[0].elem)->code);
                char* ligne=concat(var,concat(" = ",concat((yyvsp[-2].elem)->code,concat(" - ",(yyvsp[0].elem)->code))));
                addline(fc,ligne);
                (yyval.elem)->code = var;
        }
#line 1631 "y.tab.c"
    break;

  case 24: /* relational_expression: additive_expression  */
#line 236 "structfe.y"
                              {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1639 "y.tab.c"
    break;

  case 25: /* relational_expression: relational_expression '<' additive_expression  */
#line 239 "structfe.y"
                                                        {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '<' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
                (yyval.elem)->code=concat((yyvsp[-2].elem)->code,concat("<",(yyvsp[0].elem)->code));
        }
#line 1652 "y.tab.c"
    break;

  case 26: /* relational_expression: relational_expression '>' additive_expression  */
#line 247 "structfe.y"
                                                        {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '>' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1664 "y.tab.c"
    break;

  case 27: /* relational_expression: relational_expression LE_OP additive_expression  */
#line 254 "structfe.y"
                                                          {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '<=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1676 "y.tab.c"
    break;

  case 28: /* relational_expression: relational_expression GE_OP additive_expression  */
#line 261 "structfe.y"
                                                          {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '>=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1688 "y.tab.c"
    break;

  case 29: /* equality_expression: relational_expression  */
#line 271 "structfe.y"
                                {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1696 "y.tab.c"
    break;

  case 30: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 274 "structfe.y"
                                                          {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '==' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1708 "y.tab.c"
    break;

  case 31: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 281 "structfe.y"
                                                          {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '!=' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1720 "y.tab.c"
    break;

  case 32: /* logical_and_expression: equality_expression  */
#line 291 "structfe.y"
                              {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1728 "y.tab.c"
    break;

  case 33: /* logical_and_expression: logical_and_expression AND_OP equality_expression  */
#line 294 "structfe.y"
                                                            {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '&&' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1740 "y.tab.c"
    break;

  case 34: /* logical_or_expression: logical_and_expression  */
#line 304 "structfe.y"
                                 {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1748 "y.tab.c"
    break;

  case 35: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 307 "structfe.y"
                                                             {
                if((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Opération '||' entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                (yyval.elem)->type = TYPE_INT;
        }
#line 1760 "y.tab.c"
    break;

  case 36: /* expression: logical_or_expression  */
#line 317 "structfe.y"
                                {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1768 "y.tab.c"
    break;

  case 37: /* expression: unary_expression '=' expression  */
#line 320 "structfe.y"
                                          {
                if ((yyvsp[-2].elem)->type != TYPE_INT || (yyvsp[0].elem)->type != TYPE_INT) {
                    fprintf(stderr, "Erreur: Assignation entre types incompatibles à la ligne %d\n", yylineno);
                    YYERROR;
                }
                printf("yacc code 3adrs:%s = %s;\n",(yyvsp[-2].elem)->code,(yyvsp[0].elem)->code);
                char* ligne=concat((yyvsp[-2].elem)->code,concat(" = ",(yyvsp[0].elem)->code));
                addline(fc,ligne);
                (yyval.elem) = (yyvsp[-2].elem);
        }
#line 1783 "y.tab.c"
    break;

  case 38: /* declaration: declaration_specifiers declarator ';'  */
#line 333 "structfe.y"
                                                {
                printf("yacc code 3adrs:%s %s;\n",(yyvsp[-2].elem)->code,(yyvsp[-1].elem)->code);
                char* ligne=concat((yyvsp[-2].elem)->code,concat(" ",(yyvsp[-1].elem)->code));
                addline(fc,ligne);
                insert_symbol_toptas(tas, (yyvsp[-1].elem)->code, (yyvsp[-2].elem)->type);
        }
#line 1794 "y.tab.c"
    break;

  case 39: /* declaration: struct_specifier ';'  */
#line 339 "structfe.y"
                               {
                // À implémenter si nécessaire
        }
#line 1802 "y.tab.c"
    break;

  case 40: /* declaration_specifiers: EXTERN type_specifier  */
#line 345 "structfe.y"
                                {
                (yyval.elem) = (yyvsp[0].elem);
                (yyval.elem)->code=concat("extern ",(yyvsp[0].elem)->code);
        }
#line 1811 "y.tab.c"
    break;

  case 41: /* declaration_specifiers: type_specifier  */
#line 349 "structfe.y"
                         {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1819 "y.tab.c"
    break;

  case 42: /* type_specifier: VOID  */
#line 355 "structfe.y"
               {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_VOID;
                e->code="void";
                (yyval.elem)=e;
        }
#line 1830 "y.tab.c"
    break;

  case 43: /* type_specifier: INT  */
#line 361 "structfe.y"
              {
                
                Element * e = malloc(sizeof(Element));
                e->type = TYPE_INT;
                e->code = "int";
                (yyval.elem) = e;
        }
#line 1842 "y.tab.c"
    break;

  case 44: /* type_specifier: struct_specifier  */
#line 368 "structfe.y"
                           {

                (yyval.elem)->type = TYPE_STRUCT;
        }
#line 1851 "y.tab.c"
    break;

  case 45: /* struct_specifier: STRUCT IDENTIFIER '{' struct_declaration_list '}'  */
#line 375 "structfe.y"
                                                            {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                (yyval.elem)=e;
        }
#line 1862 "y.tab.c"
    break;

  case 46: /* struct_specifier: STRUCT '{' struct_declaration_list '}'  */
#line 381 "structfe.y"
                                                 {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                (yyval.elem)=e;
        }
#line 1873 "y.tab.c"
    break;

  case 47: /* struct_specifier: STRUCT IDENTIFIER  */
#line 387 "structfe.y"
                            {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_STRUCT;
                e->code="";
                (yyval.elem)=e;
        }
#line 1884 "y.tab.c"
    break;

  case 50: /* struct_declaration: type_specifier declarator ';'  */
#line 401 "structfe.y"
                                       {
                //printf("yacctypesNamesCharde3adrs:~%s %s\n",$1->code,$2->code);
        }
#line 1892 "y.tab.c"
    break;

  case 51: /* declarator: '*' direct_declarator  */
#line 407 "structfe.y"
                                {//pointeur
                (yyval.elem) = (yyvsp[0].elem);
                (yyval.elem)->code=concat("*",(yyvsp[0].elem)->code);
        }
#line 1901 "y.tab.c"
    break;

  case 52: /* declarator: direct_declarator  */
#line 411 "structfe.y"
                            {
                (yyval.elem) = (yyvsp[0].elem);
        }
#line 1909 "y.tab.c"
    break;

  case 53: /* direct_declarator: IDENTIFIER  */
#line 417 "structfe.y"
                     {
                Element * e = malloc(sizeof(Element));
                e->type=TYPE_INT;
                e->code=(yyvsp[0].id);
                (yyval.elem)=e;

        }
#line 1921 "y.tab.c"
    break;

  case 54: /* direct_declarator: '(' declarator ')'  */
#line 424 "structfe.y"
                             {
                (yyval.elem) = (yyvsp[-1].elem);
        }
#line 1929 "y.tab.c"
    break;

  case 55: /* direct_declarator: direct_declarator '(' parameter_list ')'  */
#line 427 "structfe.y"
                                                   {
                (yyval.elem) = (yyvsp[-3].elem);
                (yyval.elem)->code=concat((yyvsp[-3].elem)->code,concat("(",concat((yyvsp[-1].elem)->code,")")));
        }
#line 1938 "y.tab.c"
    break;

  case 56: /* direct_declarator: direct_declarator '(' ')'  */
#line 431 "structfe.y"
                                    {
                printf("yacc code 3adrs:%s %s()\n",typesNames[(yyvsp[-2].elem)->type],(yyvsp[-2].elem)->code);
                char* ligne=concat(typesNames[(yyvsp[-2].elem)->type],concat(" ",concat((yyvsp[-2].elem)->code,"()")));
                addline(fc,ligne);
                (yyval.elem) = (yyvsp[-2].elem);
        }
#line 1949 "y.tab.c"
    break;

  case 57: /* parameter_list: parameter_declaration  */
#line 440 "structfe.y"
                               {
                (yyval.elem)=(yyvsp[0].elem);
                (yyval.elem)->code=(yyvsp[0].elem)->code;
        }
#line 1958 "y.tab.c"
    break;

  case 58: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 444 "structfe.y"
                                                  {
                (yyval.elem)=(yyvsp[-2].elem);
                (yyval.elem)->code=concat((yyvsp[-2].elem)->code,concat(" , ",(yyvsp[0].elem)->code));
        }
#line 1967 "y.tab.c"
    break;

  case 59: /* parameter_declaration: declaration_specifiers declarator  */
#line 451 "structfe.y"
                                           {
                (yyval.elem)->type = (yyvsp[-1].elem)->type;
                (yyval.elem)->code = concat(typesNames[(yyvsp[0].elem)->type],concat(" ",(yyvsp[0].elem)->code));
        }
#line 1976 "y.tab.c"
    break;

  case 66: /* compound_statement: open_accol statement_list close_accol  */
#line 467 "structfe.y"
                                               {
        }
#line 1983 "y.tab.c"
    break;

  case 67: /* compound_statement: open_accol declaration_list close_accol  */
#line 469 "structfe.y"
                                                 {
        }
#line 1990 "y.tab.c"
    break;

  case 68: /* compound_statement: open_accol declaration_list statement_list close_accol  */
#line 471 "structfe.y"
                                                                {
        }
#line 1997 "y.tab.c"
    break;

  case 69: /* open_accol: '{'  */
#line 476 "structfe.y"
            {   
                printf("Yacc code 3adrs:{\n");
                char* ligne="{";
                addline(fc,ligne);
                expandTas(&tas);        
        }
#line 2008 "y.tab.c"
    break;

  case 70: /* close_accol: '}'  */
#line 484 "structfe.y"
            {
                printf("Yacc code 3adrs:}\n");
                char* ligne="}";
                addline(fc,ligne);
                popTas(&tas);
        }
#line 2019 "y.tab.c"
    break;

  case 75: /* expression_statement: ';'  */
#line 502 "structfe.y"
             {
                (yyval.elem)=(yyval.elem);
        }
#line 2027 "y.tab.c"
    break;

  case 78: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 510 "structfe.y"
                                                        {
                
                char* condif =increm(&cond,"cond");
                char* corpif =increm(&corp,"corp");
                char* finif =increm(&fin,"fin");
                //printf("Yacc L488 cond:%s\n",cond);

                printf("Yacc code 3adrs:goto %s\n",concat(condif,":"));
                printf("Yacc code 3adrs:%s\n",concat(corpif,":"));
                printf("Yacc code 3adrs:code de:%s\n",(yyvsp[-2].elem)->code);
                printf("Yacc code 3adrs:goto %s\n",finif);
                printf("Yacc code 3adrs:%s\n",concat(condif,":"));
                printf("Yacc code 3adrs:if(%s) goto %s:\n",(yyvsp[-4].elem)->code,corpif);
                printf("Yacc code 3adrs:%s\n\n",concat(finif,":"));
        }
#line 2047 "y.tab.c"
    break;

  case 80: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 529 "structfe.y"
                                                                                    {
                /*printf("Code 3adrs:%s\n","");
               //printf("Code 3adrs:%s\n","goto condX");
               //printf("Code 3adrs:%s\n","corpX:");
               //printf("Code 3adrs:%s\n","7");
               //printf("Code 3adrs:%s\n","5");
               //printf("Code 3adrs:%s\n","condX:");
               //printf("Code 3adrs:if(%s) goto corpX\n","$4");*/
        }
#line 2061 "y.tab.c"
    break;

  case 81: /* jump_statement: RETURN ';'  */
#line 541 "structfe.y"
                    {
                printf("yacc code 3adrs:return;\n");
                char* ligne="return;";
                addline(fc,ligne);
        }
#line 2071 "y.tab.c"
    break;

  case 82: /* jump_statement: RETURN expression ';'  */
#line 546 "structfe.y"
                               {
                printf("yacc code 3adrs:return %s;\n",(yyvsp[-1].elem)->code);
                char* ligne=concat("return ",concat((yyvsp[-1].elem)->code,";"));
                addline(fc,ligne);
        }
#line 2081 "y.tab.c"
    break;

  case 87: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 564 "structfe.y"
                                                              {
                printf("Yacc518\n");
        }
#line 2089 "y.tab.c"
    break;


#line 2093 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 569 "structfe.y"

void yyerror(const char *msg) {
    fprintf(stderr, "Erreur de syntaxe : %s à la ligne: %d ???\n", msg, yylineno);
}

int main() {

        valtmp=0;
        cond=0;
        corp=0;
        fin=0;
        fc=malloc(sizeof(Filechar));

        initialize_tas(&tas);

        initialize_table(symbol_table);
        addinTas(&tas, symbol_table);
        


        yyparse();
        setinfile(fc,"you");
        return 0;
        }
