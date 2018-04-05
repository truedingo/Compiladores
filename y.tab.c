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
     REALLIT = 291,
     RESERVED = 292,
     CHRLIT = 293,
     ID = 294,
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
#define REALLIT 291
#define RESERVED 292
#define CHRLIT 293
#define ID 294
#define INTLIT 295




/* Copy the first part of user declarations.  */
#line 1 "uccompiler.y"

    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "ast.h"
    void yyerror(const char* s);
    int yylex();
    int yyparse();
    int cnt;
	no root;
	no aux;
	no aux2;


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
#line 16 "uccompiler.y"
{
int inteiro;
char* string;
struct node* ynode;
}
/* Line 193 of yacc.c.  */
#line 197 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 210 "y.tab.c"

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
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

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
      56,    59,    62,    66,    71,    74,    78,    80,    82,    84,
      86,    88,    90,    94,    96,    99,   102,   106,   110,   116,
     124,   130,   133,   137,   139,   142,   145,   147,   151,   155,
     159,   161,   163,   165,   167,   169,   171,   176,   180,   184,
     188,   192,   196,   200,   204,   208,   212,   216,   220,   224,
     228,   232,   236,   240,   243,   246,   249,   253,   258,   260,
     262,   264,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    46,    -1,    50,    -1,    43,
      42,    -1,    46,    42,    -1,    50,    42,    -1,    52,    47,
      44,    -1,    23,    45,    32,    -1,    23,    32,    -1,    54,
      45,    -1,    50,    45,    -1,    54,    -1,    50,    -1,    52,
      47,    35,    -1,    39,    34,    48,    33,    -1,    49,    -1,
      49,    18,    48,    -1,    52,    -1,    52,    39,    -1,     1,
      35,    -1,    52,    53,    35,    -1,    52,    53,    51,    35,
      -1,    18,    53,    -1,    51,    18,    53,    -1,     3,    -1,
       6,    -1,    10,    -1,     8,    -1,     7,    -1,    39,    -1,
      39,    16,    57,    -1,    35,    -1,    57,    35,    -1,    23,
      32,    -1,    23,    56,    32,    -1,    23,     1,    32,    -1,
       5,    34,    57,    33,    55,    -1,     5,    34,    57,    33,
      55,     4,    55,    -1,    11,    34,    57,    33,    55,    -1,
       9,    35,    -1,     9,    57,    35,    -1,    54,    -1,     1,
      35,    -1,    56,    55,    -1,    55,    -1,    57,    16,    57,
      -1,    57,    18,    57,    -1,    34,     1,    33,    -1,    58,
      -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,
      -1,    39,    34,     1,    33,    -1,    57,    31,    57,    -1,
      57,    26,    57,    -1,    57,    17,    57,    -1,    57,    19,
      57,    -1,    57,    27,    57,    -1,    57,    30,    57,    -1,
      57,    15,    57,    -1,    57,    12,    57,    -1,    57,    13,
      57,    -1,    57,    14,    57,    -1,    57,    20,    57,    -1,
      57,    28,    57,    -1,    57,    24,    57,    -1,    57,    21,
      57,    -1,    57,    25,    57,    -1,    57,    22,    57,    -1,
      31,    57,    -1,    26,    57,    -1,    29,    57,    -1,    39,
      34,    33,    -1,    39,    34,    57,    33,    -1,    39,    -1,
      40,    -1,    36,    -1,    38,    -1,    34,    57,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    46,    47,    48,    49,    50,    53,    57,
      58,    62,    63,    64,    65,    68,    71,    75,    76,    80,
      81,    85,    86,    87,    90,    91,    95,    96,    97,    98,
      99,   103,   104,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   120,   121,   125,   126,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   142,   143,   144,
     145,   146,   150,   151,   152,   153,   154,   158,   159,   160,
     161,   162,   163,   167,   168,   169,   173,   174,   179,   180,
     181,   182,   183
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
  "RBRACE", "RPAR", "LPAR", "SEMI", "REALLIT", "RESERVED", "CHRLIT", "ID",
  "INTLIT", "$accept", "FuncAndDeclarations", "FuncDefinition", "FuncBody",
  "DeclarationAndStates", "FuncDeclaration", "FuncDeclarator", "ParamList",
  "ParamDeclaration", "Declaration", "AuxDeclarator", "TypeSpec",
  "Declarator", "Statement", "ErrorStatement", "AuxStatement", "Expr",
  "ExprOper", "ExprLogic", "ExprRelat", "ExprSigleOp", "ExprFunction",
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
      49,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     3,
       2,     2,     2,     1,     1,     3,     4,     1,     3,     1,
       2,     2,     3,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     3,     5,     7,
       5,     2,     3,     1,     2,     2,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     3,     4,     1,     1,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    26,    27,    30,    29,    28,     0,     0,     0,
       0,     0,    21,     1,     5,     6,     7,    31,     0,     0,
       0,     0,     0,    15,     8,     0,    22,     0,     0,     0,
       0,     0,    80,    81,    78,    79,    32,    50,    51,    52,
      53,    54,    55,     0,    17,    19,     0,     0,     0,     0,
      10,    33,     0,     0,     0,     0,     0,    31,    24,     0,
      23,    74,    75,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    20,     0,    41,
       0,     0,     0,    35,    43,    46,     0,     9,    12,    11,
      34,    25,    49,    82,     0,    76,     0,    64,    65,    66,
      63,    47,    59,    48,    60,    67,    70,    72,    69,    71,
      58,    61,    68,    62,    57,    18,     0,    42,     0,    37,
      44,     0,    36,    45,    56,    77,     0,     0,    38,    40,
       0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,    24,    52,     9,    18,    43,    44,    10,
      27,    11,    19,    94,    95,    96,    56,    37,    38,    39,
      40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
     160,   -28,   -96,   -96,   -96,   -96,   -96,    13,    83,   121,
     565,     5,   -96,   -96,   -96,   -96,   -96,    -1,    46,   -13,
     514,   207,    69,   -96,   -96,    34,   -96,    47,   514,   514,
     514,   251,   -96,   -96,   -14,   -96,   416,   -96,   -96,   -96,
     -96,   -96,   -96,    52,    70,    48,    60,   487,    62,   168,
     -96,   -96,    81,   109,    34,   149,   280,    86,   -96,    34,
     -96,    80,    80,    80,    90,   328,   236,   514,   514,   514,
     514,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   514,   514,   514,   -96,   207,   -96,   514,   -96,
     304,   514,     8,   -96,   -96,   -96,   200,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,    92,   -96,   350,   484,   454,   471,
     436,   416,    80,   416,    80,   511,   532,   532,   543,   543,
      80,    80,   511,     4,    80,   -96,   372,   -96,   394,   -96,
     -96,    91,   -96,   -96,   -96,   -96,   219,   219,   126,   -96,
     219,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   568,   -96,   -96,   -41,   -96,   -96,    50,   -96,   -16,
     -96,   -19,   -21,    44,   -95,   -96,   -20,   -96,   -96,   -96,
     -96,   -96,   -96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int16 yytable[] =
{
      36,   133,    45,    54,    58,    25,    53,    12,    61,    62,
      63,    65,    98,    13,    99,    20,    67,    68,    69,    70,
      66,    72,    26,    74,    75,    76,    77,    90,    78,    79,
      80,    81,    82,    21,    54,    84,    54,    53,   101,    53,
     129,   138,   139,   130,    17,   141,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    59,    55,    45,   126,    22,
       1,   128,     2,    57,    46,     3,     4,     5,    47,     6,
      48,    23,    60,    -2,     1,    85,     2,    87,    86,     3,
       4,     5,    49,     6,    88,    28,    91,    55,    29,    55,
      30,    50,    20,    31,    51,    32,    80,    33,    34,    35,
       1,    84,     2,    97,    46,     3,     4,     5,    47,     6,
      48,    -3,     1,   102,     2,   134,   130,     3,     4,     5,
     140,     6,    49,     0,     0,    28,   125,     0,    29,     0,
      30,   -14,     0,    31,    51,    32,     0,    33,    34,    35,
       1,     0,     2,     0,    46,     3,     4,     5,    47,     6,
      48,     1,     0,     2,     0,     0,     3,     4,     5,    92,
       6,     0,    49,    46,     0,    28,     0,    47,    29,    48,
      30,   -13,     0,    31,    51,    32,     0,    33,    34,    35,
       0,    49,     0,     0,    28,     0,     0,    29,     0,    30,
      93,   131,    31,    51,    32,    46,    33,    34,    35,    47,
       2,    48,     0,     3,     4,     5,     0,     6,     0,     0,
     131,     0,     0,    49,    46,     0,    28,     0,    47,    29,
      48,    30,   132,     0,    31,    51,    32,   104,    33,    34,
      35,     0,    49,     0,     0,    28,     0,     0,    29,     0,
      30,     0,    64,    31,    51,    32,     0,    33,    34,    35,
       0,     0,    28,     0,     0,    29,     0,    30,     0,   105,
      31,     0,    32,     0,    33,    34,    35,    28,     0,     0,
      29,     0,    30,     0,     0,    31,     0,    32,     0,    33,
      34,    35,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    82,     0,
      83,    84,     0,     0,     0,   100,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,     0,   127,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    82,     0,    83,    84,
       0,   103,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    82,     0,
      83,    84,     0,   135,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    80,    81,
      82,     0,    83,    84,     0,   136,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,     0,    83,    84,     0,   137,    67,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,     0,    83,    84,    67,    68,
      69,     0,     0,    72,     0,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,     0,    67,    84,    69,     0,
       0,    72,     0,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    67,     0,    84,     0,     0,    72,     0,
      74,    75,    76,    77,     0,    78,    79,    80,    81,    82,
       0,    72,    84,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    28,     0,    84,    29,     0,    30,     0,
       0,    31,    89,    32,     0,    33,    34,    35,    72,     0,
      74,     0,    76,    77,     0,    78,    79,    80,    81,     0,
      28,     0,    84,    29,     0,    30,     0,     0,    31,    72,
      32,    74,    33,    34,    35,     0,    78,    79,    80,    81,
      72,     0,    74,    84,     0,    -4,     1,     0,     2,    80,
      81,     3,     4,     5,    84,     6,    14,    15,    16
};

static const yytype_int16 yycheck[] =
{
      20,    96,    21,    22,    25,    18,    22,    35,    28,    29,
      30,    31,    53,     0,    55,    16,    12,    13,    14,    15,
      34,    17,    35,    19,    20,    21,    22,    47,    24,    25,
      26,    27,    28,    34,    53,    31,    55,    53,    59,    55,
      32,   136,   137,    35,    39,   140,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    18,    22,    86,    88,    23,
       1,    91,     3,    39,     5,     6,     7,     8,     9,    10,
      11,    35,    35,     0,     1,    33,     3,    39,    18,     6,
       7,     8,    23,    10,    34,    26,    34,    53,    29,    55,
      31,    32,    16,    34,    35,    36,    26,    38,    39,    40,
       1,    31,     3,    32,     5,     6,     7,     8,     9,    10,
      11,     0,     1,    33,     3,    33,    35,     6,     7,     8,
       4,    10,    23,    -1,    -1,    26,    86,    -1,    29,    -1,
      31,    32,    -1,    34,    35,    36,    -1,    38,    39,    40,
       1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,     1,    -1,     3,    -1,    -1,     6,     7,     8,     1,
      10,    -1,    23,     5,    -1,    26,    -1,     9,    29,    11,
      31,    32,    -1,    34,    35,    36,    -1,    38,    39,    40,
      -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    34,    35,    36,     5,    38,    39,    40,     9,
       3,    11,    -1,     6,     7,     8,    -1,    10,    -1,    -1,
       1,    -1,    -1,    23,     5,    -1,    26,    -1,     9,    29,
      11,    31,    32,    -1,    34,    35,    36,     1,    38,    39,
      40,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,     1,    34,    35,    36,    -1,    38,    39,    40,
      -1,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    34,    -1,    36,    -1,    38,
      39,    40,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    33,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    30,    31,    12,    13,
      14,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    12,    31,    14,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    12,    -1,    31,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      -1,    17,    31,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    26,    -1,    31,    29,    -1,    31,    -1,
      -1,    34,    35,    36,    -1,    38,    39,    40,    17,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    -1,
      26,    -1,    31,    29,    -1,    31,    -1,    -1,    34,    17,
      36,    19,    38,    39,    40,    -1,    24,    25,    26,    27,
      17,    -1,    19,    31,    -1,     0,     1,    -1,     3,    26,
      27,     6,     7,     8,    31,    10,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     6,     7,     8,    10,    42,    43,    46,
      50,    52,    35,     0,    42,    42,    42,    39,    47,    53,
      16,    34,    23,    35,    44,    18,    35,    51,    26,    29,
      31,    34,    36,    38,    39,    40,    57,    58,    59,    60,
      61,    62,    63,    48,    49,    52,     5,     9,    11,    23,
      32,    35,    45,    50,    52,    54,    57,    39,    53,    18,
      35,    57,    57,    57,     1,    57,    34,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    24,    25,
      26,    27,    28,    30,    31,    33,    18,    39,    34,    35,
      57,    34,     1,    32,    54,    55,    56,    32,    45,    45,
      35,    53,    33,    33,     1,    33,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    48,    57,    35,    57,    32,
      35,     1,    32,    55,    33,    33,    33,    33,    55,    55,
       4,    55
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
#line 45 "uccompiler.y"
    {}
    break;

  case 3:
#line 46 "uccompiler.y"
    {}
    break;

  case 4:
#line 47 "uccompiler.y"
    {}
    break;

  case 5:
#line 48 "uccompiler.y"
    {}
    break;

  case 6:
#line 49 "uccompiler.y"
    {}
    break;

  case 7:
#line 50 "uccompiler.y"
    {}
    break;

  case 8:
#line 53 "uccompiler.y"
    {}
    break;

  case 9:
#line 57 "uccompiler.y"
    {}
    break;

  case 10:
#line 58 "uccompiler.y"
    {}
    break;

  case 11:
#line 62 "uccompiler.y"
    {}
    break;

  case 12:
#line 63 "uccompiler.y"
    {}
    break;

  case 13:
#line 64 "uccompiler.y"
    {}
    break;

  case 14:
#line 65 "uccompiler.y"
    {}
    break;

  case 15:
#line 68 "uccompiler.y"
    {}
    break;

  case 16:
#line 71 "uccompiler.y"
    {}
    break;

  case 17:
#line 75 "uccompiler.y"
    {}
    break;

  case 18:
#line 76 "uccompiler.y"
    {}
    break;

  case 19:
#line 80 "uccompiler.y"
    {}
    break;

  case 20:
#line 81 "uccompiler.y"
    {}
    break;

  case 21:
#line 85 "uccompiler.y"
    {}
    break;

  case 22:
#line 86 "uccompiler.y"
    {}
    break;

  case 23:
#line 87 "uccompiler.y"
    {}
    break;

  case 24:
#line 90 "uccompiler.y"
    {}
    break;

  case 25:
#line 91 "uccompiler.y"
    {}
    break;

  case 26:
#line 95 "uccompiler.y"
    {}
    break;

  case 27:
#line 96 "uccompiler.y"
    {}
    break;

  case 28:
#line 97 "uccompiler.y"
    {}
    break;

  case 29:
#line 98 "uccompiler.y"
    {}
    break;

  case 30:
#line 99 "uccompiler.y"
    {}
    break;

  case 31:
#line 103 "uccompiler.y"
    {}
    break;

  case 32:
#line 104 "uccompiler.y"
    {}
    break;

  case 33:
#line 108 "uccompiler.y"
    {}
    break;

  case 34:
#line 109 "uccompiler.y"
    {}
    break;

  case 35:
#line 110 "uccompiler.y"
    {}
    break;

  case 36:
#line 111 "uccompiler.y"
    {}
    break;

  case 37:
#line 112 "uccompiler.y"
    {}
    break;

  case 38:
#line 113 "uccompiler.y"
    {}
    break;

  case 39:
#line 114 "uccompiler.y"
    {}
    break;

  case 40:
#line 115 "uccompiler.y"
    {}
    break;

  case 41:
#line 116 "uccompiler.y"
    {}
    break;

  case 42:
#line 117 "uccompiler.y"
    {}
    break;

  case 43:
#line 120 "uccompiler.y"
    {}
    break;

  case 44:
#line 121 "uccompiler.y"
    {}
    break;

  case 45:
#line 125 "uccompiler.y"
    {}
    break;

  case 46:
#line 126 "uccompiler.y"
    {}
    break;

  case 47:
#line 130 "uccompiler.y"
    {}
    break;

  case 48:
#line 131 "uccompiler.y"
    {}
    break;

  case 49:
#line 132 "uccompiler.y"
    {}
    break;

  case 50:
#line 133 "uccompiler.y"
    {}
    break;

  case 51:
#line 134 "uccompiler.y"
    {}
    break;

  case 52:
#line 135 "uccompiler.y"
    {}
    break;

  case 53:
#line 136 "uccompiler.y"
    {}
    break;

  case 54:
#line 137 "uccompiler.y"
    {}
    break;

  case 55:
#line 138 "uccompiler.y"
    {}
    break;

  case 56:
#line 139 "uccompiler.y"
    {}
    break;

  case 57:
#line 142 "uccompiler.y"
    {}
    break;

  case 58:
#line 143 "uccompiler.y"
    {}
    break;

  case 59:
#line 144 "uccompiler.y"
    {}
    break;

  case 60:
#line 145 "uccompiler.y"
    {}
    break;

  case 61:
#line 146 "uccompiler.y"
    {}
    break;

  case 62:
#line 150 "uccompiler.y"
    {}
    break;

  case 63:
#line 151 "uccompiler.y"
    {}
    break;

  case 64:
#line 152 "uccompiler.y"
    {}
    break;

  case 65:
#line 153 "uccompiler.y"
    {}
    break;

  case 66:
#line 154 "uccompiler.y"
    {}
    break;

  case 67:
#line 158 "uccompiler.y"
    {}
    break;

  case 68:
#line 159 "uccompiler.y"
    {}
    break;

  case 69:
#line 160 "uccompiler.y"
    {}
    break;

  case 70:
#line 161 "uccompiler.y"
    {}
    break;

  case 71:
#line 162 "uccompiler.y"
    {}
    break;

  case 72:
#line 163 "uccompiler.y"
    {}
    break;

  case 73:
#line 167 "uccompiler.y"
    {}
    break;

  case 74:
#line 168 "uccompiler.y"
    {}
    break;

  case 75:
#line 169 "uccompiler.y"
    {}
    break;

  case 76:
#line 173 "uccompiler.y"
    {}
    break;

  case 77:
#line 174 "uccompiler.y"
    {}
    break;

  case 78:
#line 179 "uccompiler.y"
    {}
    break;

  case 79:
#line 180 "uccompiler.y"
    {}
    break;

  case 80:
#line 181 "uccompiler.y"
    {}
    break;

  case 81:
#line 182 "uccompiler.y"
    {}
    break;

  case 82:
#line 183 "uccompiler.y"
    {}
    break;


/* Line 1267 of yacc.c.  */
#line 2029 "y.tab.c"
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


#line 185 "uccompiler.y"

