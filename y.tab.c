/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     ELSE = 259,
     IF = 260,
     INT = 261,
     SHORT = 262,
     DOUBLE = 263,
     RETURN = 264,
     VOID = 265,
     WHILE = 266,
     BITWISEAND = 267,
     BITWISEOR = 268,
     BITWISEXOR = 269,
     AND = 270,
     ASSIGN = 271,
     MUL = 272,
     COMMA = 273,
     DIV = 274,
     EQ = 275,
     GE = 276,
     GT = 277,
     LBRACE = 278,
     LE = 279,
     LT = 280,
     MINUS = 281,
     MOD = 282,
     NE = 283,
     NOT = 284,
     OR = 285,
     PLUS = 286,
     RBRACE = 287,
     RPAR = 288,
     LPAR = 289,
     SEMI = 290,
     ID = 291,
     CHRLIT = 292,
     REALLIT = 293,
     RESERVED = 294,
     INTLIT = 295
   };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define IF 260
#define INT 261
#define SHORT 262
#define DOUBLE 263
#define RETURN 264
#define VOID 265
#define WHILE 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LT 280
#define MINUS 281
#define MOD 282
#define NE 283
#define NOT 284
#define OR 285
#define PLUS 286
#define RBRACE 287
#define RPAR 288
#define LPAR 289
#define SEMI 290
#define ID 291
#define CHRLIT 292
#define REALLIT 293
#define RESERVED 294
#define INTLIT 295




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y"

    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "newtree.h"
    void yyerror(const char* s);
    int yylex();
    int yyparse();
    int cnt;
    int num_erros=0;
	no *root;
    no *aux1;
	no *aux;
	no *aux2;
    no *aux3;
    int first=0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "uccompiler.y"
{
    char *string;
    struct no* node;
}
/* Line 193 of yacc.c.  */
#line 200 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   536

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    18,    22,
      26,    29,    32,    35,    37,    39,    43,    48,    50,    54,
      56,    59,    62,    66,    68,    72,    74,    76,    78,    80,
      82,    84,    88,    90,    93,    96,   100,   104,   110,   118,
     124,   127,   131,   135,   137,   140,   143,   145,   149,   153,
     155,   157,   159,   161,   163,   165,   170,   174,   178,   182,
     186,   190,   194,   198,   202,   206,   210,   214,   218,   222,
     226,   230,   234,   237,   240,   243,   247,   252,   254,   256,
     258,   260
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    46,    -1,    50,    -1,    43,
      42,    -1,    46,    42,    -1,    50,    42,    -1,    52,    47,
      44,    -1,    23,    45,    32,    -1,    23,    32,    -1,    45,
      54,    -1,    45,    50,    -1,    54,    -1,    50,    -1,    52,
      47,    35,    -1,    36,    34,    48,    33,    -1,    49,    -1,
      49,    18,    48,    -1,    52,    -1,    52,    36,    -1,     1,
      35,    -1,    52,    51,    35,    -1,    53,    -1,    51,    18,
      53,    -1,     3,    -1,     6,    -1,    10,    -1,     8,    -1,
       7,    -1,    36,    -1,    36,    16,    57,    -1,    35,    -1,
      57,    35,    -1,    23,    32,    -1,    23,    56,    32,    -1,
      23,     1,    32,    -1,     5,    34,    57,    33,    55,    -1,
       5,    34,    57,    33,    55,     4,    55,    -1,    11,    34,
      57,    33,    55,    -1,     9,    35,    -1,     9,    57,    35,
      -1,    34,     1,    33,    -1,    54,    -1,     1,    35,    -1,
      55,    56,    -1,    55,    -1,    57,    16,    57,    -1,    57,
      18,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,    63,    -1,    36,    34,     1,    33,    -1,
      57,    31,    57,    -1,    57,    26,    57,    -1,    57,    17,
      57,    -1,    57,    19,    57,    -1,    57,    27,    57,    -1,
      57,    30,    57,    -1,    57,    15,    57,    -1,    57,    12,
      57,    -1,    57,    13,    57,    -1,    57,    14,    57,    -1,
      57,    20,    57,    -1,    57,    28,    57,    -1,    57,    24,
      57,    -1,    57,    21,    57,    -1,    57,    25,    57,    -1,
      57,    22,    57,    -1,    31,    57,    -1,    26,    57,    -1,
      29,    57,    -1,    36,    34,    33,    -1,    36,    34,    57,
      33,    -1,    36,    -1,    40,    -1,    38,    -1,    37,    -1,
      34,    57,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    50,    51,    52,    53,    54,    57,    65,
      68,    72,    73,    74,    75,    78,    84,    92,    93,    98,
     101,   110,   111,   139,   140,   144,   145,   146,   147,   148,
     152,   153,   157,   158,   159,   160,   169,   170,   178,   185,
     194,   198,   202,   205,   206,   209,   210,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   224,   225,   226,   227,
     228,   232,   233,   234,   235,   236,   240,   241,   242,   243,
     244,   245,   249,   250,   251,   255,   256,   261,   262,   263,
     264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "IF", "INT", "SHORT",
  "DOUBLE", "RETURN", "VOID", "WHILE", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "LPAR", "SEMI", "ID", "CHRLIT", "REALLIT", "RESERVED",
  "INTLIT", "$accept", "FuncAndDeclarations", "FuncDefinition", "FuncBody",
  "DeclarationAndStates", "FuncDeclaration", "FuncDeclarator", "ParamList",
  "ParamDeclaration", "Declaration", "AuxDeclarator", "TypeSpec",
  "Declarator", "Statement", "ErrorStatement", "AuxStatement", "Expr",
  "ExprOper", "ExprLogic", "ExprRelat", "ExprSingleOp", "ExprFunction",
  "ExprPrim", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    42,    43,    44,
      44,    45,    45,    45,    45,    46,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     3,
       2,     2,     2,     1,     1,     3,     4,     1,     3,     1,
       2,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     2,     3,     3,     5,     7,     5,
       2,     3,     3,     1,     2,     2,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     4,     1,     1,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    26,    29,    28,    27,     0,     0,     0,
       0,     0,    21,     1,     5,     6,     7,    30,     0,     0,
      23,     0,     0,     0,    15,     8,     0,    22,     0,     0,
       0,     0,    77,    80,    79,    78,    31,    49,    50,    51,
      52,    53,    54,     0,    17,    19,     0,     0,     0,     0,
      10,     0,    32,     0,    14,     0,    13,     0,    30,    24,
      73,    74,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,    20,     0,    40,     0,     0,
       0,    34,    43,     0,     0,     0,     9,    12,    11,    33,
      81,     0,    75,     0,    63,    64,    65,    62,    47,    58,
      48,    59,    66,    69,    71,    68,    70,    57,    60,    67,
      61,    56,    18,     0,    41,     0,    36,    44,     0,    45,
      35,    42,    55,    76,     0,     0,    37,    39,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,    25,    53,     9,    18,    43,    44,    10,
      19,    11,    20,    92,    93,    94,    57,    37,    38,    39,
      40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
     517,     1,  -107,  -107,  -107,  -107,  -107,    37,    78,   116,
     509,    26,  -107,  -107,  -107,  -107,  -107,   -11,     4,     6,
    -107,   464,   523,    66,  -107,  -107,    27,  -107,   464,   464,
     464,   464,     8,  -107,  -107,  -107,   365,  -107,  -107,  -107,
    -107,  -107,  -107,     7,    48,    34,    46,   439,    49,   120,
    -107,   200,  -107,   104,  -107,    27,  -107,   229,    71,  -107,
     -14,   -14,   -14,   277,   187,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,  -107,   523,  -107,   464,  -107,   253,   464,
       3,  -107,  -107,   158,    50,    57,  -107,  -107,  -107,  -107,
    -107,    58,  -107,   299,   436,   423,    -6,   405,   365,   -14,
     365,   -14,   461,   147,   147,   480,   480,   -14,   -14,   461,
     385,   -14,  -107,   321,  -107,   343,  -107,  -107,    59,  -107,
    -107,  -107,  -107,  -107,   174,   174,    89,  -107,   174,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,   526,  -107,  -107,  -107,  -107,  -107,    12,  -107,   -22,
    -107,   -20,    73,   -19,  -106,    15,   -21,  -107,  -107,  -107,
    -107,  -107,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      36,    54,    45,    55,    56,    21,    65,    60,    61,    62,
      63,    70,    78,    72,    73,    74,    75,    82,    76,    77,
      78,    79,    80,    22,    26,    82,    88,    23,   136,   137,
      63,    97,   139,    55,    98,   126,    12,    13,   127,    24,
      83,    27,    64,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    17,    58,    45,   123,    84,     1,   125,     2,
      85,    46,     3,     4,     5,    47,     6,    48,    -2,     1,
      86,     2,   130,    89,     3,     4,     5,    21,     6,    49,
     131,   132,    28,   138,   127,    29,   122,    30,    50,    59,
      51,    52,    32,    33,    34,     1,    35,     2,   129,    46,
       3,     4,     5,    47,     6,    48,    -3,     1,     0,     2,
       0,    90,     3,     4,     5,    46,     6,    49,     0,    47,
      28,    48,     0,    29,     0,    30,    96,     0,    51,    52,
      32,    33,    34,    49,    35,     0,    28,     0,     0,    29,
       0,    30,    91,     0,    51,    52,    32,    33,    34,   128,
      35,     0,     0,    46,    70,     0,    72,    47,     0,    48,
       0,    76,    77,    78,    79,   128,     0,     0,    82,    46,
       0,    49,     0,    47,    28,    48,     0,    29,   101,    30,
     -46,     0,    51,    52,    32,    33,    34,    49,    35,     0,
      28,    95,     0,    29,     0,    30,     0,     0,    51,    52,
      32,    33,    34,    28,    35,     0,    29,     0,    30,     0,
     102,    31,     0,    32,    33,    34,    28,    35,     0,    29,
       0,    30,     0,     0,    31,     0,    32,    33,    34,     0,
      35,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,    99,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,   124,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,    80,     0,    81,    82,     0,
     100,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,     0,    81,
      82,     0,   133,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,    80,
       0,    81,    82,     0,   134,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,     0,    81,    82,     0,   135,    65,    66,    67,
      68,    69,    70,     0,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,     0,    81,    82,    65,    66,    67,
      68,     0,    70,     0,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,     0,     0,    82,    65,    66,    67,
       0,     0,    70,     0,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,     0,    65,    82,    67,     0,     0,
      70,     0,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,     0,    70,    82,    72,    73,    74,    75,     0,
      76,    77,    78,    79,    80,    28,     0,    82,    29,     0,
      30,     0,     0,    31,    87,    32,    33,    34,    70,    35,
      72,     0,    74,    75,     0,    76,    77,    78,    79,     0,
      28,     0,    82,    29,     0,    30,     0,    70,    31,    72,
      32,    33,    34,     0,    35,     0,    78,    79,     0,    -4,
       1,    82,     2,     0,     0,     3,     4,     5,     1,     6,
       2,     0,     0,     3,     4,     5,     2,     6,     0,     3,
       4,     5,     0,     6,    14,    15,    16
};

static const yytype_int16 yycheck[] =
{
      21,    23,    22,    23,    23,    16,    12,    28,    29,    30,
      31,    17,    26,    19,    20,    21,    22,    31,    24,    25,
      26,    27,    28,    34,    18,    31,    47,    23,   134,   135,
      51,    53,   138,    53,    53,    32,    35,     0,    35,    35,
      33,    35,    34,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    36,    36,    84,    86,    18,     1,    89,     3,
      36,     5,     6,     7,     8,     9,    10,    11,     0,     1,
      34,     3,    32,    34,     6,     7,     8,    16,    10,    23,
      33,    33,    26,     4,    35,    29,    84,    31,    32,    26,
      34,    35,    36,    37,    38,     1,    40,     3,    93,     5,
       6,     7,     8,     9,    10,    11,     0,     1,    -1,     3,
      -1,     1,     6,     7,     8,     5,    10,    23,    -1,     9,
      26,    11,    -1,    29,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    23,    40,    -1,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,     1,
      40,    -1,    -1,     5,    17,    -1,    19,     9,    -1,    11,
      -1,    24,    25,    26,    27,     1,    -1,    -1,    31,     5,
      -1,    23,    -1,     9,    26,    11,    -1,    29,     1,    31,
      32,    -1,    34,    35,    36,    37,    38,    23,    40,    -1,
      26,     1,    -1,    29,    -1,    31,    -1,    -1,    34,    35,
      36,    37,    38,    26,    40,    -1,    29,    -1,    31,    -1,
      33,    34,    -1,    36,    37,    38,    26,    40,    -1,    29,
      -1,    31,    -1,    -1,    34,    -1,    36,    37,    38,    -1,
      40,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    35,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    30,    31,    12,    13,    14,
      15,    -1,    17,    -1,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    31,    12,    13,    14,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    12,    31,    14,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    -1,    17,    31,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    26,    -1,    31,    29,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,    17,    40,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    -1,
      26,    -1,    31,    29,    -1,    31,    -1,    17,    34,    19,
      36,    37,    38,    -1,    40,    -1,    26,    27,    -1,     0,
       1,    31,     3,    -1,    -1,     6,     7,     8,     1,    10,
       3,    -1,    -1,     6,     7,     8,     3,    10,    -1,     6,
       7,     8,    -1,    10,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     6,     7,     8,    10,    42,    43,    46,
      50,    52,    35,     0,    42,    42,    42,    36,    47,    51,
      53,    16,    34,    23,    35,    44,    18,    35,    26,    29,
      31,    34,    36,    37,    38,    40,    57,    58,    59,    60,
      61,    62,    63,    48,    49,    52,     5,     9,    11,    23,
      32,    34,    35,    45,    50,    52,    54,    57,    36,    53,
      57,    57,    57,    57,    34,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,    25,    26,    27,
      28,    30,    31,    33,    18,    36,    34,    35,    57,    34,
       1,    32,    54,    55,    56,     1,    32,    50,    54,    35,
      33,     1,    33,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    48,    57,    35,    57,    32,    35,     1,    56,
      32,    33,    33,    33,    33,    33,    55,    55,     4,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 49 "uccompiler.y"
    {root=createNode("Program", NULL); addChild(root, (yyvsp[(1) - (1)].node));}
    break;

  case 3:
#line 50 "uccompiler.y"
    {root=createNode("Program",NULL);addChild(root,(yyvsp[(1) - (1)].node));}
    break;

  case 4:
#line 51 "uccompiler.y"
    {root=createNode("Program",NULL);addChild(root,(yyvsp[(1) - (1)].node));}
    break;

  case 5:
#line 52 "uccompiler.y"
    {root=createNode("Program",NULL);addChild(root,(yyvsp[(1) - (2)].node));addBrother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 6:
#line 53 "uccompiler.y"
    {root=createNode("Program",NULL);addChild(root,(yyvsp[(1) - (2)].node));addBrother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 7:
#line 54 "uccompiler.y"
    {root=createNode("Program",NULL);addChild(root,(yyvsp[(1) - (2)].node));addBrother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 8:
#line 57 "uccompiler.y"
    {(yyval.node)=createNode("FuncDefinition", NULL);
                                                  addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                  addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));
                                                  addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
                                                }
    break;

  case 9:
#line 65 "uccompiler.y"
    {(yyval.node)=createNode("FuncBody", NULL);
                                                addChild((yyval.node),(yyvsp[(2) - (3)].node));    
                                                }
    break;

  case 10:
#line 68 "uccompiler.y"
    {(yyval.node)=createNode("FuncBody", NULL);}
    break;

  case 11:
#line 72 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node); addBrother((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 12:
#line 73 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node); addBrother((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 13:
#line 74 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 14:
#line 75 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 15:
#line 78 "uccompiler.y"
    {(yyval.node)=createNode("FuncDeclaration", NULL);
                                            addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                            addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));
                                            }
    break;

  case 16:
#line 84 "uccompiler.y"
    {(yyval.node)=createNode("Id", (yyvsp[(1) - (4)].string));
                                        aux = createNode("ParamList", NULL);
                                        addChild(aux,(yyvsp[(3) - (4)].node));
                                        addBrother((yyval.node),aux);
                                        }
    break;

  case 17:
#line 92 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 18:
#line 93 "uccompiler.y"
    { (yyval.node)=(yyvsp[(1) - (3)].node);
                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 19:
#line 98 "uccompiler.y"
    {(yyval.node)=createNode("ParamDeclaration", NULL);
                            addChild((yyval.node),(yyvsp[(1) - (1)].node));
                            }
    break;

  case 20:
#line 101 "uccompiler.y"
    {
                        (yyval.node)=createNode("ParamDeclaration", NULL);
                        addChild((yyval.node),(yyvsp[(1) - (2)].node));
                        aux=createNode("Id", (yyvsp[(2) - (2)].string));
                        addBrother((yyvsp[(1) - (2)].node),aux);
                    }
    break;

  case 21:
#line 110 "uccompiler.y"
    {(yyval.node)=createNode("Null", NULL);num_erros+=1;}
    break;

  case 22:
#line 111 "uccompiler.y"
    { 
                        aux = (yyvsp[(2) - (3)].node);
						first = 0;
						while(aux != NULL){
							aux1 = aux;
							aux = aux->brother;
							aux1->brother = NULL;
							aux2 = createNode("Declaration",NULL);
							aux3 = createNode((yyvsp[(1) - (3)].node)->label,NULL);
							addChild(aux2,aux3);
							if(aux1->child != NULL){
								aux1->brother = aux1->child;
								aux1->child = NULL;							
							}
							addBrother(aux3,aux1);
							if(first==0){
								first = 1;							
								 (yyval.node) = aux2;
							}
							else addBrother((yyval.node),aux2);
							
						
							}
						free((yyvsp[(1) - (3)].node));
						
                    }
    break;

  case 23:
#line 139 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 24:
#line 140 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 25:
#line 144 "uccompiler.y"
    {(yyval.node)=createNode("Char", NULL);}
    break;

  case 26:
#line 145 "uccompiler.y"
    {(yyval.node)=createNode("Int", NULL);}
    break;

  case 27:
#line 146 "uccompiler.y"
    {(yyval.node)=createNode("Void", NULL);}
    break;

  case 28:
#line 147 "uccompiler.y"
    {(yyval.node)=createNode("Double", NULL);}
    break;

  case 29:
#line 148 "uccompiler.y"
    {(yyval.node)=createNode("Short", NULL);}
    break;

  case 30:
#line 152 "uccompiler.y"
    {(yyval.node)=createNode("Id", (yyvsp[(1) - (1)].string));}
    break;

  case 31:
#line 153 "uccompiler.y"
    {(yyval.node)=createNode("Id", (yyvsp[(1) - (3)].string)); addChild((yyval.node), (yyvsp[(3) - (3)].node)); }
    break;

  case 32:
#line 157 "uccompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 33:
#line 158 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 34:
#line 159 "uccompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 35:
#line 160 "uccompiler.y"
    {
                        if(cntBrothers((yyvsp[(2) - (3)].node)) >= 2){
						    (yyval.node)=createNode("StatList",NULL);
						    addChild((yyval.node),(yyvsp[(2) - (3)].node));
                        }
					    else{
						(yyval.node) = (yyvsp[(2) - (3)].node);
				    	}
                    }
    break;

  case 36:
#line 169 "uccompiler.y"
    {(yyval.node)=createNode("Null", NULL);num_erros+=1;}
    break;

  case 37:
#line 170 "uccompiler.y"
    { 
                                    (yyval.node)=createNode("If",NULL);
                                    addChild((yyval.node),(yyvsp[(3) - (5)].node));
									if((yyvsp[(5) - (5)].node) == NULL){
                                        aux = createNode("Null",NULL);
										addBrother((yyvsp[(3) - (5)].node),aux);
                                    }	
                                }
    break;

  case 38:
#line 178 "uccompiler.y"
    {
                                    (yyval.node)=createNode("If",NULL);
									addChild((yyval.node),(yyvsp[(3) - (7)].node));
									if((yyvsp[(5) - (7)].node) == NULL){
                                        aux = createNode("Null",NULL);
                                    }
                                }
    break;

  case 39:
#line 185 "uccompiler.y"
    {
			 						(yyval.node)=createNode("While",NULL);
									addChild((yyval.node),(yyvsp[(3) - (5)].node));
									if((yyvsp[(5) - (5)].node) == NULL){
                                        aux = createNode("Null",NULL);
										addBrother((yyvsp[(3) - (5)].node),aux);		
									}								
									else addBrother((yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node));
									}
    break;

  case 40:
#line 194 "uccompiler.y"
    {(yyval.node)=createNode("Return", NULL);
                                addChild((yyval.node), createNode("Null", NULL));
                                }
    break;

  case 41:
#line 198 "uccompiler.y"
    {
                                    (yyval.node)=createNode("Return", NULL);
                                    addChild((yyval.node), (yyvsp[(2) - (3)].node));
                                    }
    break;

  case 42:
#line 202 "uccompiler.y"
    {(yyval.node)=createNode("Null", NULL);num_erros+=1;}
    break;

  case 43:
#line 205 "uccompiler.y"
    {(yyval.node) =(yyvsp[(1) - (1)].node);}
    break;

  case 44:
#line 206 "uccompiler.y"
    {(yyval.node)=createNode("Null", NULL);num_erros+=1;}
    break;

  case 45:
#line 209 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);addBrother((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 46:
#line 210 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 213 "uccompiler.y"
    {(yyval.node)=createNode("Store", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 48:
#line 214 "uccompiler.y"
    {(yyval.node)=createNode("Comma", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 49:
#line 215 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 50:
#line 216 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 51:
#line 217 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 52:
#line 218 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 53:
#line 219 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 54:
#line 220 "uccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 55:
#line 221 "uccompiler.y"
    {(yyval.node)=createNode("Null", NULL);num_erros+=1;}
    break;

  case 56:
#line 224 "uccompiler.y"
    {(yyval.node)=createNode("Add", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 57:
#line 225 "uccompiler.y"
    {(yyval.node)=createNode("Sub", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 58:
#line 226 "uccompiler.y"
    {(yyval.node)=createNode("Mul", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 227 "uccompiler.y"
    {(yyval.node)=createNode("Div", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 60:
#line 228 "uccompiler.y"
    {(yyval.node)=createNode("Mod", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 232 "uccompiler.y"
    {(yyval.node)=createNode("Or", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 62:
#line 233 "uccompiler.y"
    {(yyval.node)=createNode("And", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 234 "uccompiler.y"
    {(yyval.node)=createNode("BitWiseAnd", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 64:
#line 235 "uccompiler.y"
    {(yyval.node)=createNode("BitWiseOr", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 236 "uccompiler.y"
    {(yyval.node)=createNode("BitWiseXor", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 240 "uccompiler.y"
    {(yyval.node)=createNode("Eq", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 241 "uccompiler.y"
    {(yyval.node)=createNode("Ne", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 242 "uccompiler.y"
    {(yyval.node)=createNode("Le", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 243 "uccompiler.y"
    {(yyval.node)=createNode("Ge", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 244 "uccompiler.y"
    {(yyval.node)=createNode("Lt", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 245 "uccompiler.y"
    {(yyval.node)=createNode("Gt", NULL);addChild((yyval.node),(yyvsp[(1) - (3)].node));addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 249 "uccompiler.y"
    {(yyval.node)=createNode("Plus", NULL);addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 73:
#line 250 "uccompiler.y"
    {(yyval.node)=createNode("Minus", NULL);addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 74:
#line 251 "uccompiler.y"
    {(yyval.node)=createNode("Not", NULL);addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 75:
#line 255 "uccompiler.y"
    {(yyval.node)=createNode("Call", NULL);aux=createNode("Id",(yyvsp[(1) - (3)].string)); addChild((yyval.node),aux);}
    break;

  case 76:
#line 256 "uccompiler.y"
    {(yyval.node)=createNode("Call", NULL);aux=createNode("Id",(yyvsp[(1) - (4)].string)); addChild((yyval.node),aux);addBrother(aux,(yyvsp[(3) - (4)].node));}
    break;

  case 77:
#line 261 "uccompiler.y"
    {(yyval.node)=createNode("Id", (yyvsp[(1) - (1)].string));}
    break;

  case 78:
#line 262 "uccompiler.y"
    {(yyval.node)=createNode("IntLit", (yyvsp[(1) - (1)].string));}
    break;

  case 79:
#line 263 "uccompiler.y"
    {(yyval.node)=createNode("RealLit",(yyvsp[(1) - (1)].string));}
    break;

  case 80:
#line 264 "uccompiler.y"
    {(yyval.node)=createNode("ChrLit", (yyvsp[(1) - (1)].string));}
    break;

  case 81:
#line 265 "uccompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;


/* Line 1267 of yacc.c.  */
#line 2096 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 267 "uccompiler.y"

