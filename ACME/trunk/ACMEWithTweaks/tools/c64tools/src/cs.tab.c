/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "cs.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include "tree.h"
#include "types.h"
#include "codegen.h"

extern int onefile;
extern int lineno;
extern FILE *yyin;
extern FILE *yyout;
extern char *filename;
extern char *outname;
char *srcname = NULL;
FILE *yyasm = NULL;
FILE *yyextern = NULL;
treenode *tree = NULL;

extern int vars, varsize, pagesize, noconstants, debug, header;

int errors = 0;

void yyerror(char *str)
{
  fprintf(stdout,"error in %s, line %d: %s.\n", filename, lineno, str);
  errors++;
}

int yywrap()
{
	return 1;
}

int main(int argc, char *argv[])
{
  int c;
  for (c = 1; c < argc; c++)
  {
    if ((argv[c][0] == '-') || ((argv[c][0] == '/') && (strlen(argv[c]) > 1)))
    {
      int ch = tolower(argv[c][1]);
      switch(ch)
      {
        case 'c':
        noconstants = 1;
        break;

        case 'd':
        debug = 1;
        break;

        case 'h':
        header = 1;
        break;

        case 'l':
        yyasm = fopen(&argv[c][2], "wt");
        break;

        case 'o':
        onefile = 1;
        yyout = fopen(&argv[c][2], "wb");
        break;

        case 'p':
        sscanf(&argv[c][2], "%x", &pagesize);
        break;

        case 'v':
        sscanf(&argv[c][2], "%x,%x", &vars, &varsize);
        break;

        case 'e':
        yyextern = fopen(&argv[c][2], "rt");
        break;
      }
    }
    else
    {
      if (!srcname) srcname = argv[c];
    }
  }

  if (!srcname)
  {
    printf("CovertScript compiler V1.0\n"
           "usage: cs <infile> [options]\n\n"
           "-c            Do not automatically import constants from extern file\n"
           "-d            Enable compiler debugging output\n"
           "-e<name>      Extern definition file name\n"
           "-h            Add chunk-header (for datafiles)\n"
           "-l<name>      Listing file name\n"
           "-o<name>      Output to one file, instead of multiple pages\n"
           "-p<val>       Bytecode page size in hex                  (default: 0400)\n"
           "-v<val>,<val> Startaddress & length for variables in hex (default: 0334,100)\n");
    return 1;
  }
  yyin = fopen(srcname, "rt");
  if (!yyin)
  {
    fprintf(stderr, "error: couldn't open input file %s\n", srcname);
    return 1;
  }
  filename = srcname;
  yyparse();
  if (errors) return 1;
  compile(tree);
  if (errors) return 1;
  else return 0;
}



/* Line 189 of yacc.c  */
#line 189 "cs.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FLUSH = 258,
     INCLUDE = 259,
     LOADPTR = 260,
     CHUNK = 261,
     SWITCH = 262,
     CASE = 263,
     DEFAULT = 264,
     ALIAS = 265,
     ASSIGN = 266,
     ADDASSIGN = 267,
     SUBASSIGN = 268,
     MULASSIGN = 269,
     DIVASSIGN = 270,
     MODASSIGN = 271,
     ANDASSIGN = 272,
     ORASSIGN = 273,
     EORASSIGN = 274,
     SHIFTLASSIGN = 275,
     SHIFTRASSIGN = 276,
     EQ = 277,
     NE = 278,
     GTE = 279,
     LTE = 280,
     GT = 281,
     LT = 282,
     INC = 283,
     DEC = 284,
     ADD = 285,
     SUB = 286,
     MUL = 287,
     DIV = 288,
     MOD = 289,
     AND = 290,
     OR = 291,
     BOOLAND = 292,
     BOOLOR = 293,
     BOOLNOT = 294,
     EOR = 295,
     LEFT = 296,
     RIGHT = 297,
     LEFTBR = 298,
     RIGHTBR = 299,
     LEFTCOMP = 300,
     RIGHTCOMP = 301,
     SHIFTL = 302,
     SHIFTR = 303,
     COMMA = 304,
     DBLCOLON = 305,
     CONSTANT = 306,
     VAR = 307,
     EXTERN = 308,
     ENDSTAT = 309,
     IF = 310,
     ELSE = 311,
     WHILE = 312,
     DO = 313,
     FOR = 314,
     GOTO = 315,
     DATA = 316,
     STOP = 317,
     BREAK = 318,
     RETURN = 319,
     NUMBER = 320,
     NAME = 321,
     STRING = 322
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 118 "cs.y"

  int number;
  char *string;
  treenode *node;



/* Line 214 of yacc.c  */
#line 300 "cs.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 312 "cs.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    18,    25,    28,
      30,    31,    35,    37,    41,    44,    47,    51,    55,    59,
      63,    67,    71,    75,    79,    83,    87,    95,    97,   103,
     107,   112,   119,   124,   129,   133,   139,   146,   153,   161,
     165,   170,   177,   181,   188,   191,   195,   197,   200,   202,
     205,   211,   217,   225,   233,   239,   249,   257,   266,   275,
     282,   290,   298,   304,   308,   311,   317,   321,   324,   329,
     333,   336,   341,   344,   345,   347,   351,   353,   355,   358,
     361,   363,   368,   370,   372,   376,   380,   384,   388,   392,
     396,   400,   404,   407,   409,   414,   418,   423,   427,   431,
     435,   439,   443,   445,   449,   453,   455,   459,   463,   467,
     470,   473,   477,   479
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    70,    -1,    70,    71,    -1,    71,    -1,
      75,    -1,    66,    41,    73,    42,    76,    -1,    66,    66,
      41,    73,    42,    76,    -1,    72,    77,    -1,    77,    -1,
      -1,    73,    49,    82,    -1,    82,    -1,    82,    11,    83,
      -1,    82,    28,    -1,    82,    29,    -1,    82,    12,    83,
      -1,    82,    13,    83,    -1,    82,    14,    83,    -1,    82,
      15,    83,    -1,    82,    16,    83,    -1,    82,    17,    83,
      -1,    82,    18,    83,    -1,    82,    19,    83,    -1,    82,
      20,    83,    -1,    82,    21,    83,    -1,     6,    41,    83,
      42,    45,    78,    46,    -1,     3,    -1,    61,    41,    78,
      42,    54,    -1,    45,    78,    46,    -1,    66,    10,    66,
      54,    -1,    81,    61,    41,    78,    42,    54,    -1,    81,
      45,    78,    46,    -1,    51,    66,    11,    83,    -1,    51,
      66,    83,    -1,    66,    41,    73,    42,    54,    -1,    66,
      66,    41,    73,    42,    54,    -1,    53,    66,    41,    73,
      42,    54,    -1,    53,    66,    66,    41,    73,    42,    54,
      -1,    53,    66,    54,    -1,    53,    52,    66,    54,    -1,
      53,    52,    66,    43,    44,    54,    -1,    52,    66,    54,
      -1,    52,    66,    43,    83,    44,    54,    -1,    45,    46,
      -1,    45,    72,    46,    -1,    54,    -1,    81,    77,    -1,
      76,    -1,    74,    54,    -1,     5,    41,    82,    42,    54,
      -1,    55,    41,    83,    42,    77,    -1,    55,    41,    83,
      42,    77,    56,    77,    -1,    58,    77,    57,    41,    83,
      42,    54,    -1,    57,    41,    83,    42,    77,    -1,    59,
      41,    74,    54,    83,    54,    74,    42,    77,    -1,    59,
      41,    54,    83,    54,    42,    77,    -1,    59,    41,    54,
      83,    54,    74,    42,    77,    -1,    59,    41,    74,    54,
      83,    54,    42,    77,    -1,    59,    41,    54,    54,    42,
      77,    -1,    59,    41,    54,    54,    74,    42,    77,    -1,
      59,    41,    74,    54,    54,    42,    77,    -1,     7,    41,
      83,    42,    77,    -1,     8,    83,    50,    -1,     9,    50,
      -1,    66,    41,    78,    42,    54,    -1,    60,    66,    54,
      -1,    64,    54,    -1,    64,    41,    42,    54,    -1,    64,
      83,    54,    -1,    62,    54,    -1,    62,    41,    42,    54,
      -1,    63,    54,    -1,    -1,    83,    -1,    78,    49,    83,
      -1,    67,    -1,    79,    -1,    80,    79,    -1,    66,    50,
      -1,    66,    -1,    66,    43,    83,    44,    -1,    84,    -1,
      80,    -1,    84,    22,    84,    -1,    84,    23,    84,    -1,
      84,    26,    84,    -1,    84,    27,    84,    -1,    84,    24,
      84,    -1,    84,    25,    84,    -1,    84,    38,    84,    -1,
      84,    37,    84,    -1,    39,    84,    -1,    85,    -1,    61,
      41,    78,    42,    -1,    45,    78,    46,    -1,    66,    41,
      78,    42,    -1,    84,    47,    85,    -1,    84,    48,    85,
      -1,    84,    40,    85,    -1,    84,    36,    85,    -1,    84,
      35,    85,    -1,    86,    -1,    85,    30,    86,    -1,    85,
      31,    86,    -1,    87,    -1,    86,    34,    87,    -1,    86,
      33,    87,    -1,    86,    32,    87,    -1,    30,    87,    -1,
      31,    87,    -1,    41,    83,    42,    -1,    65,    -1,    82,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   218,   218,   225,   229,   236,   240,   246,   255,   259,
     267,   270,   274,   281,   285,   289,   293,   298,   303,   308,
     313,   318,   323,   328,   333,   338,   346,   350,   354,   358,
     362,   368,   373,   378,   383,   388,   394,   400,   406,   412,
     417,   422,   427,   432,   440,   444,   451,   455,   460,   464,
     468,   472,   476,   480,   484,   488,   492,   497,   502,   507,
     512,   517,   522,   526,   530,   534,   539,   544,   548,   552,
     556,   560,   564,   572,   575,   579,   586,   594,   598,   605,
     612,   617,   625,   629,   633,   637,   641,   645,   649,   653,
     657,   661,   665,   672,   676,   680,   684,   689,   693,   697,
     701,   705,   712,   716,   720,   727,   731,   735,   739,   746,
     750,   754,   758,   763
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLUSH", "INCLUDE", "LOADPTR", "CHUNK",
  "SWITCH", "CASE", "DEFAULT", "ALIAS", "ASSIGN", "ADDASSIGN", "SUBASSIGN",
  "MULASSIGN", "DIVASSIGN", "MODASSIGN", "ANDASSIGN", "ORASSIGN",
  "EORASSIGN", "SHIFTLASSIGN", "SHIFTRASSIGN", "EQ", "NE", "GTE", "LTE",
  "GT", "LT", "INC", "DEC", "ADD", "SUB", "MUL", "DIV", "MOD", "AND", "OR",
  "BOOLAND", "BOOLOR", "BOOLNOT", "EOR", "LEFT", "RIGHT", "LEFTBR",
  "RIGHTBR", "LEFTCOMP", "RIGHTCOMP", "SHIFTL", "SHIFTR", "COMMA",
  "DBLCOLON", "CONSTANT", "VAR", "EXTERN", "ENDSTAT", "IF", "ELSE",
  "WHILE", "DO", "FOR", "GOTO", "DATA", "STOP", "BREAK", "RETURN",
  "NUMBER", "NAME", "STRING", "$accept", "program", "units", "unit",
  "statements", "identifiers", "assignment", "declaration",
  "compstatement", "statement", "expressions", "string", "strings",
  "label", "identifier", "expression", "expr", "expr2", "expr3", "expr4", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    79,    80,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    86,    86,    86,    86,    87,
      87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     6,     2,     1,
       0,     3,     1,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     1,     5,     3,
       4,     6,     4,     4,     3,     5,     6,     6,     7,     3,
       4,     6,     3,     6,     2,     3,     1,     2,     1,     2,
       5,     5,     7,     7,     5,     9,     7,     8,     8,     6,
       7,     7,     5,     3,     2,     5,     3,     2,     4,     3,
       2,     4,     2,     0,     1,     3,     1,     1,     2,     2,
       1,     4,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     4,     3,     4,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     2,
       2,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,     0,    73,     0,     0,     0,     0,     0,     0,
       2,     4,     5,     0,     0,     0,     0,     0,     0,    73,
       0,   112,    80,    76,     0,    77,    83,   113,    74,    82,
      93,   102,   105,     0,     0,     0,     0,    73,     0,    10,
      79,     0,     1,     3,    73,     0,     0,    80,   109,   110,
      92,     0,     0,    73,    73,     0,    29,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      42,     0,    10,    39,     0,     0,     0,     0,    12,    10,
       0,    73,     0,   111,    95,     0,     0,     0,    75,    84,
      85,    88,    89,    86,    87,   101,   100,    91,    90,    99,
      97,    98,   103,   104,   108,   107,   106,    33,     0,     0,
      40,     0,    10,     0,    30,     0,     0,     0,    32,     0,
      73,    94,    96,    81,     0,     0,     0,     0,    28,     0,
      35,     6,    11,     0,     0,     0,    43,    41,    37,     0,
       0,     0,     0,     0,    44,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    48,     9,     0,
       0,    36,     7,    31,    26,    38,     0,     0,     0,    64,
       0,     0,     0,     0,     0,     0,    70,    72,     0,    67,
       0,    73,    45,     8,    49,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,    63,     0,     0,     0,     0,     0,    66,     0,     0,
      69,     0,    13,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    68,     0,    50,    62,    51,    54,     0,     0,
       0,     0,     0,     0,    65,     0,     0,    59,     0,     0,
       0,     0,     0,    52,    53,    60,    56,     0,    61,     0,
       0,    57,    58,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,   165,    87,   166,    12,   167,   168,
      24,    25,    26,   169,    27,    28,    29,    30,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
       4,  -181,    27,   306,   -40,   -38,   -18,    69,    -4,   112,
       4,  -181,  -181,   -14,   306,    -6,    -6,   335,   306,   306,
      73,  -181,    63,  -181,    76,  -181,    41,  -181,  -181,   380,
      23,    58,  -181,    90,     9,    28,   -33,   306,    50,    62,
    -181,   120,  -181,  -181,   306,   153,   156,   165,  -181,  -181,
      49,   167,   116,   306,   306,   306,  -181,   306,  -181,   335,
     335,   335,   335,   335,   335,    -6,    -6,   335,   335,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,   306,  -181,   306,
    -181,    18,    62,  -181,   170,   -19,   160,    91,  -181,    62,
     117,   306,   172,  -181,  -181,    94,    99,   171,  -181,    49,
      49,    49,    49,    49,    49,    23,    23,    49,    49,    23,
      23,    23,    58,    58,  -181,  -181,  -181,  -181,   174,   177,
    -181,   100,    62,   181,  -181,    53,    62,   103,  -181,   104,
     306,  -181,  -181,  -181,   182,   183,   184,   158,  -181,   196,
    -181,  -181,  -181,    64,   185,   133,  -181,  -181,  -181,   186,
     203,   205,   306,   175,  -181,  -181,   211,   216,   240,   220,
     197,   -22,   189,    93,    45,   224,   210,  -181,  -181,   240,
     418,  -181,  -181,  -181,  -181,  -181,    62,   306,   176,  -181,
     306,   306,   208,    15,   212,   232,  -181,  -181,   277,  -181,
     221,   306,  -181,  -181,  -181,  -181,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,  -181,  -181,   234,
     235,  -181,   238,   247,   250,   294,   239,  -181,   242,   251,
    -181,   164,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,   255,   240,   240,   240,   306,   -30,   256,
     323,  -181,  -181,   257,  -181,  -181,   236,  -181,   259,   240,
     270,   -26,   271,   260,  -181,   240,   261,  -181,   240,   240,
     275,   240,   -25,  -181,  -181,  -181,  -181,   240,  -181,   240,
     278,  -181,  -181,   240,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,   311,  -181,   -71,  -180,  -181,   -98,  -156,
     -15,   297,  -181,    67,   -39,   -13,   110,   202,   108,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      88,    46,   182,   216,    52,    51,    38,     1,    82,   193,
       2,   121,   249,   195,    48,    49,   259,   269,   127,   185,
      78,    83,    85,   123,    15,    16,    33,   141,    34,    90,
      57,    44,   186,    84,    35,    18,    47,    39,    95,    96,
      47,    47,    97,    88,    98,   172,    40,    45,    36,     3,
      88,   137,    79,    72,    73,     4,     5,     6,   250,    21,
      47,   119,    41,    80,   117,     7,   118,    13,    14,   215,
       8,   260,   120,   114,   115,   116,   129,    13,   245,   246,
     247,    47,   270,    88,    65,    66,   191,   142,    55,    69,
      74,    75,    76,   257,    81,    40,    70,    71,   139,   263,
     170,    77,   265,   266,    54,   268,    55,   140,    23,   139,
      37,   271,    42,   272,    53,   145,    86,   274,   171,   170,
      15,    16,    56,    15,    16,    57,   170,    50,    47,    17,
     170,    18,    17,   125,   188,    19,   131,   209,    19,   178,
     126,   132,   136,    57,   170,   143,   144,   189,    57,   126,
     190,    20,   126,    57,    20,    21,    22,    23,    21,    22,
      23,    89,    94,   128,   210,    57,    57,   212,   213,    99,
     100,   101,   102,   103,   104,    51,   221,   107,   108,   174,
     112,   113,    57,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    91,   170,   170,   170,    92,   170,
     149,   150,   239,   151,   152,   153,   243,   126,    55,    93,
     170,   122,   170,    57,   124,   133,   170,   130,   134,   170,
     170,   135,   170,   170,   248,   179,   211,   253,   170,   150,
     170,   151,   152,   153,   170,   138,   146,   147,   148,   173,
     175,   139,   154,   187,   176,   150,   177,   151,   152,   153,
     155,   156,   180,   157,   158,   159,   160,   181,   161,   162,
     163,   183,   164,   184,   194,   214,   217,   105,   106,   139,
     192,   109,   110,   111,   218,   220,   233,   234,   155,   156,
     235,   157,   158,   159,   160,   139,   161,   162,   163,   236,
     164,   237,   255,   240,   155,   156,   241,   157,   158,   159,
     160,   256,   161,   162,   163,   242,   164,    15,    16,   244,
     251,   254,   258,   261,   262,   264,    17,   267,    18,   219,
     273,    43,    19,    58,    15,    16,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,    15,    16,    20,    19,
       0,     0,    21,    22,    23,    17,     0,    18,   238,     0,
       0,    19,     0,    15,    16,    20,     0,     0,     0,    21,
      22,    23,    17,     0,    18,    15,    16,    20,    19,     0,
       0,    21,    22,    23,     0,     0,    18,   252,     0,     0,
      19,     0,     0,     0,    20,     0,     0,     0,    21,    22,
      23,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      21,    22,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,     0,
      69,     0,     0,     0,     0,     0,     0,    70,    71,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,     0,     0,     0,     0,     0,   207,   208
};

static const yytype_int16 yycheck[] =
{
      39,    14,   158,   183,    19,    18,    10,     3,    41,   165,
       6,    82,    42,   169,    15,    16,    42,    42,    89,    41,
      33,    54,    37,    42,    30,    31,    66,   125,    66,    44,
      49,    45,    54,    66,    52,    41,    66,    41,    53,    54,
      66,    66,    55,    82,    57,   143,    50,    61,    66,    45,
      89,   122,    43,    30,    31,    51,    52,    53,   238,    65,
      66,    43,    66,    54,    77,    61,    79,     0,    41,    54,
      66,   251,    54,    74,    75,    76,    91,    10,   234,   235,
     236,    66,   262,   122,    35,    36,    41,   126,    43,    40,
      32,    33,    34,   249,    66,    50,    47,    48,    45,   255,
     139,    11,   258,   259,    41,   261,    43,    54,    67,    45,
      41,   267,     0,   269,    41,   130,    66,   273,    54,   158,
      30,    31,    46,    30,    31,    49,   165,    17,    66,    39,
     169,    41,    39,    42,    41,    45,    42,   176,    45,   152,
      49,    42,    42,    49,   183,    42,    42,    54,    49,    49,
     163,    61,    49,    49,    61,    65,    66,    67,    65,    66,
      67,    41,    46,    46,   177,    49,    49,   180,   181,    59,
      60,    61,    62,    63,    64,   188,   191,    67,    68,    46,
      72,    73,    49,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    41,   234,   235,   236,    42,   238,
      42,     5,   215,     7,     8,     9,    42,    49,    43,    42,
     249,    41,   251,    49,    54,    44,   255,    45,    44,   258,
     259,    44,   261,   262,   237,    50,    50,   240,   267,     5,
     269,     7,     8,     9,   273,    54,    54,    54,    54,    54,
      54,    45,    46,    54,    41,     5,    41,     7,     8,     9,
      54,    55,    41,    57,    58,    59,    60,    41,    62,    63,
      64,    41,    66,    66,    54,    57,    54,    65,    66,    45,
      46,    69,    70,    71,    42,    54,    42,    42,    54,    55,
      42,    57,    58,    59,    60,    45,    62,    63,    64,    42,
      66,    41,    56,    54,    54,    55,    54,    57,    58,    59,
      60,    42,    62,    63,    64,    54,    66,    30,    31,    54,
      54,    54,    42,    42,    54,    54,    39,    42,    41,    42,
      42,    10,    45,    26,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    30,    31,    61,    45,
      -1,    -1,    65,    66,    67,    39,    -1,    41,    54,    -1,
      -1,    45,    -1,    30,    31,    61,    -1,    -1,    -1,    65,
      66,    67,    39,    -1,    41,    30,    31,    61,    45,    -1,
      -1,    65,    66,    67,    -1,    -1,    41,    54,    -1,    -1,
      45,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      65,    66,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    45,    51,    52,    53,    61,    66,    69,
      70,    71,    75,    81,    41,    30,    31,    39,    41,    45,
      61,    65,    66,    67,    78,    79,    80,    82,    83,    84,
      85,    86,    87,    66,    66,    52,    66,    41,    10,    41,
      50,    66,     0,    71,    45,    61,    83,    66,    87,    87,
      84,    83,    78,    41,    41,    43,    46,    49,    79,    22,
      23,    24,    25,    26,    27,    35,    36,    37,    38,    40,
      47,    48,    30,    31,    32,    33,    34,    11,    83,    43,
      54,    66,    41,    54,    66,    78,    66,    73,    82,    41,
      78,    41,    42,    42,    46,    78,    78,    83,    83,    84,
      84,    84,    84,    84,    84,    85,    85,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    87,    83,    83,    43,
      54,    73,    41,    42,    54,    42,    49,    73,    46,    78,
      45,    42,    42,    44,    44,    44,    42,    73,    54,    45,
      54,    76,    82,    42,    42,    78,    54,    54,    54,    42,
       5,     7,     8,     9,    46,    54,    55,    57,    58,    59,
      60,    62,    63,    64,    66,    72,    74,    76,    77,    81,
      82,    54,    76,    54,    46,    54,    41,    41,    83,    50,
      41,    41,    77,    41,    66,    41,    54,    54,    41,    54,
      83,    41,    46,    77,    54,    77,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    28,    29,    82,
      83,    50,    83,    83,    57,    54,    74,    54,    42,    42,
      54,    78,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    42,    42,    42,    42,    41,    54,    83,
      54,    54,    54,    42,    54,    77,    77,    77,    83,    42,
      74,    54,    54,    83,    54,    56,    42,    77,    42,    42,
      74,    42,    54,    77,    54,    77,    77,    42,    77,    42,
      74,    77,    77,    42,    77
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1464 of yacc.c  */
#line 219 "cs.y"
    {
    tree = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 226 "cs.y"
    {
    (yyval.node) = node2(UNIT_SEQ, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 230 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 237 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 241 "cs.y"
    {
    (yyval.node) = node2(FUNCT_BODY, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    (yyval.node)->label = (yyvsp[(1) - (5)].string);
    (yyval.node)->index = NULL;
  ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 247 "cs.y"
    {
    (yyval.node) = node2(FUNCT_BODY, (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
    (yyval.node)->label = (yyvsp[(1) - (6)].string);
    (yyval.node)->index = (yyvsp[(2) - (6)].string);
  ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 256 "cs.y"
    {
    (yyval.node) = node2(STMT_SEQ, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 260 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 267 "cs.y"
    {
    (yyval.node) = node(EMPTY_STMT);
  ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 271 "cs.y"
    {
    (yyval.node) = node2(IDENT_SEQ, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 275 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 282 "cs.y"
    {
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 286 "cs.y"
    {
    (yyval.node) = node1(INCASSIGN_STMT, (yyvsp[(1) - (2)].node));
  ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 290 "cs.y"
    {
    (yyval.node) = node1(DECASSIGN_STMT, (yyvsp[(1) - (2)].node));
  ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 294 "cs.y"
    {
    treenode *temp = node2(ADD_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 299 "cs.y"
    {
    treenode *temp = node2(SUB_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 304 "cs.y"
    {
    treenode *temp = node2(MUL_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 309 "cs.y"
    {
    treenode *temp = node2(DIV_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 314 "cs.y"
    {
    treenode *temp = node2(MOD_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 319 "cs.y"
    {
    treenode *temp = node2(AND_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 324 "cs.y"
    {
    treenode *temp = node2(OR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 329 "cs.y"
    {
    treenode *temp = node2(EOR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 334 "cs.y"
    {
    treenode *temp = node2(SHIFTL_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 339 "cs.y"
    {
    treenode *temp = node2(SHIFTR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    (yyval.node) = node2(ASSIGN_STMT, (yyvsp[(1) - (3)].node), temp);
  ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 347 "cs.y"
    {
    (yyval.node) = node2(CHUNK_STMT, (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
  ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 351 "cs.y"
    {
    (yyval.node) = node(FLUSH_STMT);
  ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 355 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(3) - (5)].node));
  ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 359 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(2) - (3)].node));
  ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 363 "cs.y"
    {
    (yyval.node) = node(ALIAS_STMT);
    (yyval.node)->name = (yyvsp[(1) - (4)].string);
    (yyval.node)->index = (yyvsp[(3) - (4)].string);
   ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 369 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(4) - (6)].node));
    (yyval.node)->label = (yyvsp[(1) - (6)].string);
  ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 374 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(3) - (4)].node));
    (yyval.node)->label = (yyvsp[(1) - (4)].string);
  ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 379 "cs.y"
    {
    (yyval.node) = node1(CONSTANT_DEF, (yyvsp[(4) - (4)].node));
    (yyval.node)->name = (yyvsp[(2) - (4)].string);
  ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 384 "cs.y"
    {
    (yyval.node) = node1(CONSTANT_DEF, (yyvsp[(3) - (3)].node));
    (yyval.node)->name = (yyvsp[(2) - (3)].string);
  ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 389 "cs.y"
    {
    (yyval.node) = node1(FUNCT_DEF, (yyvsp[(3) - (5)].node));
    (yyval.node)->name = (yyvsp[(1) - (5)].string);
    (yyval.node)->index = NULL;
  ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 395 "cs.y"
    {
    (yyval.node) = node1(FUNCT_DEF, (yyvsp[(4) - (6)].node));
    (yyval.node)->name = (yyvsp[(1) - (6)].string);
    (yyval.node)->index = (yyvsp[(2) - (6)].string);
  ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 401 "cs.y"
    {
    (yyval.node) = node1(EXTFUNCT_DEF, (yyvsp[(4) - (6)].node));
    (yyval.node)->name = (yyvsp[(2) - (6)].string);
    (yyval.node)->index = NULL;
  ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 407 "cs.y"
    {
    (yyval.node) = node1(EXTFUNCT_DEF, (yyvsp[(5) - (7)].node));
    (yyval.node)->name = (yyvsp[(2) - (7)].string);
    (yyval.node)->index = (yyvsp[(3) - (7)].string);
  ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 413 "cs.y"
    {
    (yyval.node) = node(EXTERN_DEF);
    (yyval.node)->name = (yyvsp[(2) - (3)].string);
  ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 418 "cs.y"
    {
    (yyval.node) = node(EXTERN_DEF);
    (yyval.node)->name = (yyvsp[(3) - (4)].string);
  ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 423 "cs.y"
    {
    (yyval.node) = node(EXTERN_DEF);
    (yyval.node)->name = (yyvsp[(3) - (6)].string);
  ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 428 "cs.y"
    {
    (yyval.node) = node(GLOBAL_DEF);
    (yyval.node)->name = (yyvsp[(2) - (3)].string);
  ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 433 "cs.y"
    {
    (yyval.node) = node1(GLOBALARRAY_DEF, (yyvsp[(4) - (6)].node));
    (yyval.node)->name = (yyvsp[(2) - (6)].string);
  ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 441 "cs.y"
    {
    (yyval.node) = node(EMPTY_STMT);
  ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 445 "cs.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 452 "cs.y"
    {
    (yyval.node) = node(EMPTY_STMT);
  ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 456 "cs.y"
    {
    (yyval.node) = (yyvsp[(2) - (2)].node);
    (yyval.node)->label = (yyvsp[(1) - (2)].string);
  ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 461 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 465 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (2)].node);
  ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 469 "cs.y"
    {
    (yyval.node) = node1(LOADPTR_STMT, (yyvsp[(3) - (5)].node));
  ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 473 "cs.y"
    {
    (yyval.node) = node2(IF_STMT, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
  ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 477 "cs.y"
    {
    (yyval.node) = node3(IFELSE_STMT, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 481 "cs.y"
    {
    (yyval.node) = node2(REPWHILE_STMT, (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node));
  ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 485 "cs.y"
    {
    (yyval.node) = node2(WHILE_STMT, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
  ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 489 "cs.y"
    {
    (yyval.node) = node4(FORNEXT_STMT, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node));
  ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 493 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, temp, (yyvsp[(4) - (7)].node), temp, (yyvsp[(7) - (7)].node));
  ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 498 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, temp, (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node));
  ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 503 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, (yyvsp[(3) - (8)].node), (yyvsp[(5) - (8)].node), temp, (yyvsp[(8) - (8)].node));
  ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 508 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, temp, temp, temp, (yyvsp[(6) - (6)].node));
  ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 513 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, temp, temp, (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
  ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 518 "cs.y"
    {
    treenode *temp = node(EMPTY_STMT);
    (yyval.node) = node4(FORNEXT_STMT, (yyvsp[(3) - (7)].node), temp, temp, (yyvsp[(7) - (7)].node));
  ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 523 "cs.y"
    {
    (yyval.node) = node2(SWITCH_STMT, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
  ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 527 "cs.y"
    {
    (yyval.node) = node1(CASE_STMT, (yyvsp[(2) - (3)].node));
  ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 531 "cs.y"
    {
    (yyval.node) = node(DEFAULTCASE_STMT);
  ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 535 "cs.y"
    {
    (yyval.node) = node1(FUNCT_STMT, (yyvsp[(3) - (5)].node));
    (yyval.node)->name = (yyvsp[(1) - (5)].string);
  ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 540 "cs.y"
    {
    (yyval.node) = node(GOTO_STMT);
    (yyval.node)->name = (yyvsp[(2) - (3)].string);
  ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 545 "cs.y"
    {
    (yyval.node) = node(RETURN_STMT);
  ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 549 "cs.y"
    {
    (yyval.node) = node(RETURN_STMT);
  ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 553 "cs.y"
    {
    (yyval.node) = node1(RETURNEXPR_STMT, (yyvsp[(2) - (3)].node));
  ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 557 "cs.y"
    {
    (yyval.node) = node(STOP_STMT);
  ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 561 "cs.y"
    {
    (yyval.node) = node(STOP_STMT);
  ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 565 "cs.y"
    {
    (yyval.node) = node(BREAK_STMT);
  ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 572 "cs.y"
    {
    (yyval.node) = node(EMPTY_STMT);
  ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 576 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 580 "cs.y"
    {
    (yyval.node) = node2(EXPR_SEQ, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 587 "cs.y"
    {
    (yyval.node) = node(STRINGDEF);
    (yyval.node)->name = (yyvsp[(1) - (1)].string);
  ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 595 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 599 "cs.y"
    {
    (yyval.node) = node2(STRINGDEF_SEQ, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 606 "cs.y"
    {
    (yyval.string) = (yyvsp[(1) - (2)].string);
  ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 613 "cs.y"
    {
    (yyval.node) = node(ABS_IDENT);
    (yyval.node)->name = (yyvsp[(1) - (1)].string);
  ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 618 "cs.y"
    {
    (yyval.node) = node1(SUB_IDENT, (yyvsp[(3) - (4)].node));
    (yyval.node)->name = (yyvsp[(1) - (4)].string);
  ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 626 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 630 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 634 "cs.y"
    {
    (yyval.node) = node2(EQ_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 638 "cs.y"
    {
    (yyval.node) = node2(NE_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 642 "cs.y"
    {
    (yyval.node) = node2(GT_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 646 "cs.y"
    {
    (yyval.node) = node2(LT_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 650 "cs.y"
    {
    (yyval.node) = node2(GTE_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 654 "cs.y"
    {
    (yyval.node) = node2(LTE_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 658 "cs.y"
    {
    (yyval.node) = node2(OR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 662 "cs.y"
    {
    (yyval.node) = node2(AND_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 666 "cs.y"
    {
    (yyval.node) = node1(NOT_EXPR, (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 673 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 677 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(3) - (4)].node));
  ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 681 "cs.y"
    {
    (yyval.node) = node1(DATA_STMT, (yyvsp[(2) - (3)].node));
  ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 685 "cs.y"
    {
    (yyval.node) = node1(FUNCT_EXPR, (yyvsp[(3) - (4)].node));
    (yyval.node)->name = (yyvsp[(1) - (4)].string);
  ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 690 "cs.y"
    {
    (yyval.node) = node2(SHIFTL_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 694 "cs.y"
    {
    (yyval.node) = node2(SHIFTR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 698 "cs.y"
    {
    (yyval.node) = node2(EOR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 702 "cs.y"
    {
    (yyval.node) = node2(OR_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 706 "cs.y"
    {
    (yyval.node) = node2(AND_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 713 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 717 "cs.y"
    {
    (yyval.node) = node2(ADD_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 721 "cs.y"
    {
    (yyval.node) = node2(SUB_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 728 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 732 "cs.y"
    {
    (yyval.node) = node2(MOD_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 736 "cs.y"
    {
    (yyval.node) = node2(DIV_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 740 "cs.y"
    {
    (yyval.node) = node2(MUL_EXPR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 747 "cs.y"
    {
    (yyval.node) = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 751 "cs.y"
    {
    (yyval.node) = node1(NEG_EXPR, (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 755 "cs.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 759 "cs.y"
    {
    (yyval.node) = node(IMM_EXPR);
    (yyval.node)->number = (yyvsp[(1) - (1)].number);
  ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 764 "cs.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;



/* Line 1464 of yacc.c  */
#line 2840 "cs.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1684 of yacc.c  */
#line 769 "cs.y"


