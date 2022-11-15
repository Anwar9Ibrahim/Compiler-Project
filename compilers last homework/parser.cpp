/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     MINUS1 = 258,
     PLUS1 = 259,
     AND = 260,
     OR = 261,
     NOTEQ = 262,
     EQ = 263,
     INF = 264,
     SUP = 265,
     INT = 266,
     CLASS = 267,
     DOUBLE = 268,
     BOOLEAN = 269,
     NUL = 270,
     FOR = 271,
     WHILE = 272,
     IF = 273,
     ELSE = 274,
     TRUE = 275,
     FALSE = 276,
     VOID = 277,
     RETURN = 278,
     NEW = 279,
     ID = 280,
     INTEGER = 281,
     REAL = 282,
     STRING = 283,
     STRING_TYPE = 284,
     THEN = 285,
     UNARYOPERATOR = 286
   };
#endif
/* Tokens.  */
#define MINUS1 258
#define PLUS1 259
#define AND 260
#define OR 261
#define NOTEQ 262
#define EQ 263
#define INF 264
#define SUP 265
#define INT 266
#define CLASS 267
#define DOUBLE 268
#define BOOLEAN 269
#define NUL 270
#define FOR 271
#define WHILE 272
#define IF 273
#define ELSE 274
#define TRUE 275
#define FALSE 276
#define VOID 277
#define RETURN 278
#define NEW 279
#define ID 280
#define INTEGER 281
#define REAL 282
#define STRING 283
#define STRING_TYPE 284
#define THEN 285
#define UNARYOPERATOR 286




/* Copy the first part of user declarations.  */
#line 1 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"

	#include<iostream>
	#include "ast.h"
	using std::cout;
	using std::endl;
	#define YYDEBUG 1;
	Class * root;
	extern int yylex();
	extern int yyerror(const char *);
	extern int yydebug;
	extern int line;
	extern int col;
	extern char* yytext;
	extern int errorno;
	extern int yyleng;
	extern int yywrap();
	extern Deffered *deffered;
	extern SymbolTable *symtab;



	int whileLabel = 0;
	int ifLabel = 0;
	int ifElseLabel = 0;
	int forLabel=0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 29 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
typedef union YYSTYPE {
	Node *Node;
	int tint;
	Identifier* tIdentifier;
	Integer_value *tInteger_value;
	Real_value *tReal_value;
	True_value *tTrue_value;
	False_value *tFalse_value;
	NullExpr * tNullExpr;
	Parameter *tParameter;
	Params *tParams;
	Expr *tExpr;
	Expr_List *tExpr_List;
	May_EXP *tMay_EXP;
	Inst *tInst;
	Instructions *tInstructions;
	Function *tFunction;
	Global *tGlobal;
	Identifier_Global *tIdentifier_Global;
	Identifier_Expr_Global *tIdentifier_Expr_Global;
	Body *tBody;
	Func_Body *tFunc_Body;
	Global_Body *tGlobal_Body;
	Class *tClass;
	SymbolTable * tSymbolTable;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 201 "parser.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 213 "parser.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  20
/* YYNRULES -- Number of rules. */
#define YYNRULES  71
/* YYNRULES -- Number of states. */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    38,     2,     2,
      43,    44,    36,    35,    45,    34,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      32,    31,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,    11,    12,    15,    18,    22,    28,
      29,    39,    40,    50,    53,    55,    59,    60,    62,    64,
      66,    68,    70,    73,    76,    79,    83,    85,    90,    94,
     101,   106,   110,   114,   118,   122,   126,   130,   134,   138,
     142,   146,   150,   154,   158,   162,   164,   166,   168,   170,
     172,   174,   176,   180,   181,   184,   185,   192,   193,   205,
     206,   220,   226,   234,   237,   243,   247,   254,   256,   260,
     264,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      50,     0,    -1,    -1,    51,    12,    25,    40,    52,    41,
      -1,    -1,    52,    54,    -1,    52,    53,    -1,    60,    25,
      42,    -1,    60,    25,    31,    61,    42,    -1,    -1,    60,
      25,    55,    43,    59,    44,    40,    63,    41,    -1,    -1,
      22,    25,    56,    43,    59,    44,    40,    63,    41,    -1,
      60,    25,    -1,    57,    -1,    58,    45,    57,    -1,    -1,
      58,    -1,    14,    -1,    13,    -1,    11,    -1,    29,    -1,
      46,    61,    -1,    34,    61,    -1,    35,    61,    -1,    43,
      61,    44,    -1,    25,    -1,    25,    47,    61,    48,    -1,
      25,    31,    61,    -1,    25,    47,    61,    48,    31,    61,
      -1,    25,    43,    62,    44,    -1,    25,    43,    44,    -1,
      61,    35,    61,    -1,    61,    34,    61,    -1,    61,    36,
      61,    -1,    61,    37,    61,    -1,    61,    38,    61,    -1,
      61,     6,    61,    -1,    61,     5,    61,    -1,    61,     8,
      61,    -1,    61,     7,    61,    -1,    61,    32,    61,    -1,
      61,    33,    61,    -1,    61,     9,    61,    -1,    61,    10,
      61,    -1,    26,    -1,    27,    -1,    28,    -1,    20,    -1,
      21,    -1,    15,    -1,    61,    -1,    62,    45,    61,    -1,
      -1,    63,    64,    -1,    -1,    17,    65,    43,    61,    44,
      64,    -1,    -1,    16,    43,    60,    25,    42,    66,    68,
      42,    68,    44,    64,    -1,    -1,    16,    43,    60,    25,
      31,    61,    42,    67,    68,    42,    68,    44,    64,    -1,
      18,    43,    61,    44,    64,    -1,    18,    43,    61,    44,
      64,    19,    64,    -1,    61,    42,    -1,    60,    25,    31,
      61,    42,    -1,    60,    25,    42,    -1,    60,    25,    47,
      26,    48,    42,    -1,    42,    -1,    40,    63,    41,    -1,
      23,    68,    42,    -1,    -1,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   132,   132,   132,   139,   142,   146,   151,   156,   162,
     162,   168,   168,   175,   182,   186,   194,   197,   202,   206,
     210,   214,   219,   223,   227,   231,   235,   241,   246,   251,
     256,   262,   266,   270,   274,   278,   282,   286,   290,   294,
     298,   302,   306,   310,   314,   318,   322,   326,   330,   334,
     338,   343,   347,   354,   358,   364,   364,   369,   369,   374,
     374,   379,   383,   387,   391,   396,   402,   408,   412,   416,
     422,   425
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS1", "PLUS1", "AND", "OR", "NOTEQ",
  "EQ", "INF", "SUP", "INT", "CLASS", "DOUBLE", "BOOLEAN", "NUL", "FOR",
  "WHILE", "IF", "ELSE", "TRUE", "FALSE", "VOID", "RETURN", "NEW", "ID",
  "INTEGER", "REAL", "STRING", "STRING_TYPE", "THEN", "'='", "'<'", "'>'",
  "'-'", "'+'", "'*'", "'/'", "'%'", "UNARYOPERATOR", "'{'", "'}'", "';'",
  "'('", "')'", "','", "'!'", "'['", "']'", "$accept", "class", "@1",
  "Body", "Global", "Function", "@2", "@3", "parameter", "Params",
  "Params_empty", "Data_Type", "Expr", "Expr_List", "instructions",
  "instruction", "@4", "@5", "@6", "May_EXP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    61,    60,    62,    45,    43,    42,    47,    37,   286,
     123,   125,    59,    40,    41,    44,    33,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    49,    51,    50,    52,    52,    52,    53,    53,    55,
      54,    56,    54,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    65,    64,    66,    64,    67,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     6,     0,     2,     2,     3,     5,     0,
       9,     0,     9,     2,     1,     3,     0,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     1,     4,     3,     6,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     2,     0,     6,     0,    11,     0,
      13,     5,     7,     2,     5,     3,     6,     1,     3,     3,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,     1,     0,     0,     4,     0,    20,    19,
      18,     0,    21,     3,     6,     5,     0,    11,     9,     0,
       0,     7,     0,    16,    50,    48,    49,    26,    45,    46,
      47,     0,     0,     0,     0,     0,    16,    14,    17,     0,
       0,     0,     0,     0,    23,    24,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,    13,    28,    31,    51,     0,
       0,    25,    38,    37,    40,    39,    43,    44,    41,    42,
      33,    32,    34,    35,    36,     0,    15,    53,    30,     0,
      27,    53,     0,    52,     0,     0,     0,    55,     0,    70,
      53,    12,    67,     0,     0,    54,    29,    10,     0,     0,
       0,    71,     0,     0,     0,    63,     0,     0,     0,    69,
      68,     0,    65,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    61,    64,     0,     0,    70,    56,     0,    66,
      59,     0,    62,    70,    70,     0,     0,    70,     0,     0,
      58,     0,    60
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,     7,    14,    15,    22,    19,    37,    38,
      39,   103,   104,    69,    92,   105,   109,   136,   143,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const short int yypact[] =
{
     -91,     5,    47,   -91,    57,   -33,   -91,    39,   -91,   -91,
     -91,    62,   -91,   -91,   -91,   -91,    64,   -91,    24,    21,
     457,   -91,    49,    -5,   -91,   -91,   -91,    20,   -91,   -91,
     -91,   457,   457,   457,   457,   165,    -5,   -91,    54,    51,
      75,   457,    50,   457,   -91,   -91,    97,   -91,   457,   457,
     457,   457,   457,   457,   457,   457,   457,   457,   457,   457,
     457,   -91,    66,    -5,    72,   -91,   426,   -91,   426,   -18,
      10,   -91,   144,   433,   413,   413,   195,   195,   195,   195,
     -34,   -34,   -91,   -91,   -91,    73,   -91,   -91,   -91,   457,
      83,   -91,   282,   426,   457,   316,    82,   -91,    85,   457,
     -91,   -91,   -91,    90,   203,   -91,   426,   -91,    -5,    93,
     457,   426,    95,   350,    41,   -91,   113,   457,   112,   -91,
     -91,   457,   -91,   114,    31,   152,   384,   214,    91,   457,
     -91,   384,   123,   -91,   101,   252,   457,   -91,   384,   -91,
     -91,   121,   -91,   457,   457,   122,   111,   457,   384,   124,
     -91,   384,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   102,   -91,
     130,    18,   -20,   -91,   -90,   -40,   -91,   -91,   -91,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const short int yytable[] =
{
      35,    95,    58,    59,    60,     3,     8,     6,     9,    10,
     113,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    66,    68,    70,    12,    16,    88,    89,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    40,    54,    55,    56,    57,    58,    59,    60,   141,
       8,    41,     9,    10,    40,    20,   145,   146,    90,     4,
     149,    11,   129,    42,    23,    24,    21,    43,    12,    93,
      25,    26,   121,   130,   106,    27,    28,    29,    30,   111,
      13,    40,     5,   122,    31,    32,   132,    17,   123,    18,
     118,   137,    36,    33,    67,    64,    34,   125,   142,    63,
      65,   127,    48,    49,    50,    51,    52,    53,   150,   135,
      85,   152,    87,    91,    94,   114,   111,    48,    49,    50,
      51,    52,    53,   111,   111,   108,   116,   111,   110,    54,
      55,    56,    57,    58,    59,    60,   117,   119,   124,   134,
     128,    71,   138,   139,    54,    55,    56,    57,    58,    59,
      60,    50,    51,    52,    53,   148,   126,    48,    49,    50,
      51,    52,    53,   144,   147,    86,    62,     0,   151,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,   131,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,     0,    61,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,    -1,    -1,    56,
      57,    58,    59,    60,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,   115,    54,    55,    56,    57,
      58,    59,    60,     0,     0,     0,   133,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     8,   140,     9,    10,    24,    96,    97,
      98,     0,    25,    26,     0,    99,     0,    27,    28,    29,
      30,    12,     0,     0,     0,     0,    31,    32,     0,     0,
       0,     0,   100,   101,   102,    33,     0,     8,    34,     9,
      10,    24,    96,    97,    98,     0,    25,    26,     0,    99,
       0,    27,    28,    29,    30,    12,     0,     0,     0,     0,
      31,    32,     0,     0,     0,     0,   100,   107,   102,    33,
       0,     8,    34,     9,    10,    24,    96,    97,    98,     0,
      25,    26,     0,    99,     0,    27,    28,    29,    30,    12,
       0,     0,     0,     0,    31,    32,     0,     0,     0,     0,
     100,   120,   102,    33,     0,     8,    34,     9,    10,    24,
      96,    97,    98,     0,    25,    26,     0,    99,     0,    27,
      28,    29,    30,    12,     0,     0,     0,     0,    31,    32,
      -1,    -1,    52,    53,   100,     0,   102,    33,     0,     0,
      34,    48,    49,    50,    51,    52,    53,     0,    48,     0,
      50,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    54,    55,    56,    57,    58,
      59,    60,    24,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    27,    28,    29,    30,     0,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,    34
};

static const short int yycheck[] =
{
      20,    91,    36,    37,    38,     0,    11,    40,    13,    14,
     100,    31,    32,    33,    34,     5,     6,     7,     8,     9,
      10,    41,    42,    43,    29,     7,    44,    45,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    23,    32,    33,    34,    35,    36,    37,    38,   136,
      11,    31,    13,    14,    36,    31,   143,   144,    48,    12,
     147,    22,    31,    43,    43,    15,    42,    47,    29,    89,
      20,    21,    31,    42,    94,    25,    26,    27,    28,    99,
      41,    63,    25,    42,    34,    35,   126,    25,    47,    25,
     110,   131,    43,    43,    44,    44,    46,   117,   138,    45,
      25,   121,     5,     6,     7,     8,     9,    10,   148,   129,
      44,   151,    40,    40,    31,    25,   136,     5,     6,     7,
       8,     9,    10,   143,   144,    43,   108,   147,    43,    32,
      33,    34,    35,    36,    37,    38,    43,    42,    25,    48,
      26,    44,    19,    42,    32,    33,    34,    35,    36,    37,
      38,     7,     8,     9,    10,    44,    44,     5,     6,     7,
       8,     9,    10,    42,    42,    63,    36,    -1,    44,    -1,
       5,     6,     7,     8,     9,    10,    32,    33,    34,    35,
      36,    37,    38,    -1,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    32,    33,    34,
      35,    36,    37,    38,     9,    10,    -1,    42,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    -1,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    11,    42,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    23,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    -1,    11,    46,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      -1,    11,    46,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    -1,    11,    46,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    23,    -1,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
       7,     8,     9,    10,    40,    -1,    42,    43,    -1,    -1,
      46,     5,     6,     7,     8,     9,    10,    -1,     5,    -1,
       7,     8,     9,    10,    -1,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    32,    33,    34,    35,    36,
      37,    38,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    50,    51,     0,    12,    25,    40,    52,    11,    13,
      14,    22,    29,    41,    53,    54,    60,    25,    25,    56,
      31,    42,    55,    43,    15,    20,    21,    25,    26,    27,
      28,    34,    35,    43,    46,    61,    43,    57,    58,    59,
      60,    31,    43,    47,    61,    61,    61,    61,     5,     6,
       7,     8,     9,    10,    32,    33,    34,    35,    36,    37,
      38,    42,    59,    45,    44,    25,    61,    44,    61,    62,
      61,    44,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    44,    57,    40,    44,    45,
      48,    40,    63,    61,    31,    63,    16,    17,    18,    23,
      40,    41,    42,    60,    61,    64,    61,    41,    43,    65,
      43,    61,    68,    63,    25,    42,    60,    43,    61,    42,
      41,    31,    42,    47,    25,    61,    44,    61,    26,    31,
      42,    44,    64,    42,    48,    61,    66,    64,    19,    42,
      42,    68,    64,    67,    42,    68,    68,    42,    44,    68,
      64,    44,    64
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 132 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {symtab->OpenScope();Initializer::initialize(); ;}
    break;

  case 3:
#line 133 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tClass) = new Class ( (yyvsp[-3].tIdentifier) , (yyvsp[-1].tBody) , line , col );
								root=(yyval.tClass);
							;}
    break;

  case 4:
#line 139 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tBody) = new Body ( line , col );	
							;}
    break;

  case 5:
#line 143 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tBody) = new Func_Body ( (yyvsp[-1].tBody) , (yyvsp[0].tFunction) , line , col );								
							;}
    break;

  case 6:
#line 147 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tBody) = new Global_Body ( (yyvsp[-1].tBody) , (yyvsp[0].tGlobal) , line , col );
							;}
    break;

  case 7:
#line 152 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tGlobal) = new Identifier_Global ( (yyvsp[-2].tint) , (yyvsp[-1].tIdentifier) , line , col );
								symtab -> AddSymbol ((yyvsp[-1].tIdentifier),1,(yyvsp[-2].tint));
							;}
    break;

  case 8:
#line 157 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tGlobal) = new Identifier_Expr_Global ( (yyvsp[-4].tint) , (yyvsp[-3].tIdentifier) , (yyvsp[-1].tExpr) , line , col );
								symtab -> AddSymbol ((yyvsp[-3].tIdentifier),1,(yyvsp[-4].tint));
							;}
    break;

  case 9:
#line 162 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {symtab->OpenScope(); ;}
    break;

  case 10:
#line 163 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tFunction) = new Type_Param_Fun ( (yyvsp[-8].tint) , (yyvsp[-7].tIdentifier) , (yyvsp[-4].tParams) , (yyvsp[-1].tInstructions) , line , col );
								symtab->CloseScope();
								symtab -> AddSymbol( (yyvsp[-7].tIdentifier) , 3 , (yyvsp[-8].tint) , (yyvsp[-4].tParams) , (yyval.tFunction));
							;}
    break;

  case 11:
#line 168 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {symtab->OpenScope(); ;}
    break;

  case 12:
#line 169 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tFunction) = new Void_Param_Fun ( (yyvsp[-7].tIdentifier) , (yyvsp[-4].tParams) , (yyvsp[-1].tInstructions) , line , col );
								symtab->CloseScope();
								symtab -> AddSymbol((yyvsp[-7].tIdentifier), 3, 4,(yyvsp[-4].tParams),(yyval.tFunction));
							;}
    break;

  case 13:
#line 176 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tParameter) = new Parameter((yyvsp[-1].tint), (yyvsp[0].tIdentifier), line, col);
								symtab -> AddSymbol ((yyvsp[0].tIdentifier),2,(yyvsp[-1].tint));
							;}
    break;

  case 14:
#line 183 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tParams) = new Params((yyvsp[0].tParameter), line, col);
							;}
    break;

  case 15:
#line 187 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tParams) = (yyvsp[-2].tParams); 
								(yyval.tParams)->addParameter((yyvsp[0].tParameter));
							;}
    break;

  case 16:
#line 194 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tParams) = NULL;
							;}
    break;

  case 17:
#line 198 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tParams) = (yyvsp[0].tParams);
							;}
    break;

  case 18:
#line 203 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tint) = 3;
							;}
    break;

  case 19:
#line 207 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tint) = 2;
							;}
    break;

  case 20:
#line 211 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tint) = 1;
							;}
    break;

  case 21:
#line 215 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tint) = 5;
							;}
    break;

  case 22:
#line 220 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new NegativeExpr ((yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 23:
#line 224 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new MinusExpr ((yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 24:
#line 228 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new PlusExpr ((yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 25:
#line 232 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new ParenthesesExpr ((yyvsp[-1].tExpr) , line , col);
							;}
    break;

  case 26:
#line 236 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new IdentifierExpr ((yyvsp[0].tIdentifier) , line , col);
								symtab->IsDeclared((yyvsp[0].tIdentifier),deffered);
							;}
    break;

  case 27:
#line 242 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr)= new VariableArrayElenment((yyvsp[-3].tIdentifier), (yyvsp[-1].tExpr), line, col);
								symtab->IsDeclared((yyvsp[-3].tIdentifier),deffered);
							;}
    break;

  case 28:
#line 247 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Identifier_Eq_Expr ((yyvsp[-2].tIdentifier) , (yyvsp[0].tExpr) , line , col);
								symtab->IsDeclared((yyvsp[-2].tIdentifier),deffered);
							;}
    break;

  case 29:
#line 252 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr)= new VariableArrayElenment_Eq_Expr((yyvsp[-5].tIdentifier), (yyvsp[-3].tExpr), (yyvsp[0].tExpr) , line, col);
								symtab->IsDeclared((yyvsp[-5].tIdentifier),deffered);
							;}
    break;

  case 30:
#line 257 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Identifier_Expr_list ((yyvsp[-3].tIdentifier) , (yyvsp[-1].tExpr_List) , line , col);
								// we need type checking before check for declaration.
								//symtab->IsDeclared($1, $3,deffered);
							;}
    break;

  case 31:
#line 263 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Identifier_Expr_list ((yyvsp[-2].tIdentifier) , NULL , line , col);
							;}
    break;

  case 32:
#line 267 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Plus_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 33:
#line 271 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Minus_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 34:
#line 275 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Multiply_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 35:
#line 279 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Div_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 36:
#line 283 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Modulo_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 37:
#line 287 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Or_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 38:
#line 291 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_And_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 39:
#line 295 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Equal_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 40:
#line 299 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_NotEqual_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 41:
#line 303 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Less_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 42:
#line 307 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new  Expr_Geater_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 43:
#line 311 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Inf_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 44:
#line 315 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new Expr_Sup_Expr ((yyvsp[-2].tExpr) , (yyvsp[0].tExpr) , line , col);
							;}
    break;

  case 45:
#line 319 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new IntegerExpr ((yyvsp[0].tInteger_value) , line , col);
							;}
    break;

  case 46:
#line 323 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new RealExpr ((yyvsp[0].tReal_value) , line , col);
							;}
    break;

  case 47:
#line 327 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr)= new StringExpr(strdup(yytext), line, col);
							;}
    break;

  case 48:
#line 331 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new TrueExpr ((yyvsp[0].tTrue_value) , line , col);
							;}
    break;

  case 49:
#line 335 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new FalseExpr ((yyvsp[0].tFalse_value) , line , col);
							;}
    break;

  case 50:
#line 339 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr) = new NullExpr ( line , col);
							;}
    break;

  case 51:
#line 344 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tExpr_List) = new Expr_List ((yyvsp[0].tExpr)  , line , col);
							;}
    break;

  case 52:
#line 348 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyvsp[-2].tExpr_List)->addExpression((yyvsp[0].tExpr));
								(yyval.tExpr_List) = (yyvsp[-2].tExpr_List);
							;}
    break;

  case 53:
#line 354 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInstructions) = new Instructions(line , col);
								// we can put $$ = NULL;
							;}
    break;

  case 54:
#line 359 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyvsp[-1].tInstructions)->addInstruction((yyvsp[0].tInst));
								(yyval.tInstructions) = (yyvsp[-1].tInstructions);
							;}
    break;

  case 55:
#line 364 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    { symtab->OpenScope(); ;}
    break;

  case 56:
#line 365 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new While ( (yyvsp[-2].tExpr) , (yyvsp[0].tInst) , line , col);
								symtab->CloseScope();
							;}
    break;

  case 57:
#line 369 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    { symtab->OpenScope();  symtab -> AddSymbol ((yyvsp[-1].tIdentifier),1,(yyvsp[-2].tint));;}
    break;

  case 58:
#line 370 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new For ( (yyvsp[-8].tint) , (yyvsp[-7].tIdentifier) , (yyvsp[-4].tMay_EXP) , (yyvsp[-2].tMay_EXP) , (yyvsp[0].tInst) , line , col);
								symtab->CloseScope();
							;}
    break;

  case 59:
#line 374 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {symtab->OpenScope();  symtab -> AddSymbol ((yyvsp[-3].tIdentifier),1,(yyvsp[-4].tint));;}
    break;

  case 60:
#line 375 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new For_Expr ( (yyvsp[-10].tint) , (yyvsp[-9].tIdentifier) , (yyvsp[-7].tExpr) , (yyvsp[-4].tMay_EXP) , (yyvsp[-2].tMay_EXP) , (yyvsp[0].tInst) , line , col);
								symtab->CloseScope();
							;}
    break;

  case 61:
#line 380 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new If ( (yyvsp[-2].tExpr) , (yyvsp[0].tInst) , line , col);
							;}
    break;

  case 62:
#line 384 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new If_Else( (yyvsp[-4].tExpr) , (yyvsp[-2].tInst) , (yyvsp[0].tInst) , line , col);
							;}
    break;

  case 63:
#line 388 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new ExprInstruction( (yyvsp[-1].tExpr) , line , col);
							;}
    break;

  case 64:
#line 392 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new Identifier_Eq_Expr_Inst ( (yyvsp[-4].tint) , (yyvsp[-3].tIdentifier) , (yyvsp[-1].tExpr) , line , col);
								symtab->AddSymbol( (yyvsp[-3].tIdentifier) , 2 , (yyvsp[-4].tint) );
							;}
    break;

  case 65:
#line 397 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new Identifier_Declaration ( (yyvsp[-2].tint) , (yyvsp[-1].tIdentifier) , line , col);
								symtab->AddSymbol( (yyvsp[-1].tIdentifier) , 2 , (yyvsp[-2].tint) );
							;}
    break;

  case 66:
#line 403 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst)= new Array((yyvsp[-5].tint), (yyvsp[-4].tIdentifier), (yyvsp[-2].tInteger_value), line, col);
								symtab->AddSymbol( (yyvsp[-4].tIdentifier) , 2 , (yyvsp[-5].tint) );
							;}
    break;

  case 67:
#line 409 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new Semicolon(line , col);
							;}
    break;

  case 68:
#line 413 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new Braces( (yyvsp[-1].tInstructions) , line , col);
							;}
    break;

  case 69:
#line 417 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tInst) = new Return( (yyvsp[-1].tMay_EXP) ,line , col);
							;}
    break;

  case 70:
#line 422 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tMay_EXP) = new May_EXP( line , col);
							;}
    break;

  case 71:
#line 426 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"
    {
								(yyval.tMay_EXP) = new May_EXP( (yyvsp[0].tExpr) ,line , col);
							;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1903 "parser.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 430 "D:\\compiler\\AnwarNeemat\\compilers last homework\\parser.y"

int yyerror(const char* s)
{
	cout<<"\n\n_________________________Parser Error_________________________"<<endl;
	cout<<"Error Number: " <<errorno<<" "<<*yytext<<endl;
	cout<<"file input.txt, Line: "<<line<<endl;
	cout<<"Syntax Error"<<endl;
	return 1;
}
