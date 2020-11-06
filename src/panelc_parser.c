/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "src/syntactic_analyzer.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/nodes.h"
#include "include/showTree.h"
#include "include/uthash.h"
#include "include/utstack.h"
#include "include/utlist.h"
#include "include/headerSyntactic.h"

extern int yylineno;
extern int yylex_destroy(void);
extern void yyerror (const char *s);
int yylex();
extern FILE *yyin;
SymbolTable *symbol_table = NULL; 
ScopeStack *stack = NULL; 
StoreVariables *variable_list = NULL;

#line 91 "src/panelc_parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PANELC_PARSER_H_INCLUDED
# define YY_YY_SRC_PANELC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "src/syntactic_analyzer.y"

    #include "include/nodes.h"

#line 138 "src/panelc_parser.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    TIPO = 260,
    BOOLCONST = 261,
    STR_VAL = 262,
    OP = 263,
    CMDOP = 264,
    SEMI_COL = 265,
    LP = 266,
    RP = 267,
    LCH = 268,
    RCH = 269,
    LC = 270,
    RC = 271,
    COL = 272,
    ATRIB = 273,
    DOUBLEDOT = 274,
    IF = 275,
    WHILE = 276,
    FOR = 277,
    ELSE = 278,
    ROWS = 279,
    COLUMNS = 280,
    CELLS = 281,
    RETURN = 282,
    ID = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "src/syntactic_analyzer.y"

	int i_val;
    float f_val;
    char tipo[50];
    char id[50];
    char op[3];
    char atrib;
    char cmdop[3];
    int teste;
    char str_val[200];
    Program* _program;          
    DeclList* _decl_list;        
    Decl* _decl;                 
    DeclVar* _decl_var;          
    Function* _function;         
    Params* _params;             
    Param* _param;               
    ParamsList* _params_list;    
    LocalDecl* _local_decl;      
    CompoundStmt* _compound_stmt;
    StmtList* _stmt_list;        
    Stmt* _stmt;                 
    Expr* _expr;                 
    CondBlock* _cond_block;      
    Iter* _iter;                 
    Return* _retrn;              
    IterTable* _iter_table;      
    Variable* _variable;         
    SimpleExpr* _simple_expr;    
    ExprOp* _expr_op;            
    Term* _term;                 
    Factor* _factor;             
    Call* _call;                 
    Args* _args;                 
    ArgsList* _args_list;        
    Table* _table;               
    ListTable* _list_table;      
    FactorList* _factor_list;    

#line 218 "src/panelc_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_SRC_PANELC_PARSER_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYUNDEFTOK  2
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   114,   114,   120,   121,   123,   124,   126,   127,   129,
     132,   133,   135,   136,   138,   139,   141,   142,   144,   145,
     147,   148,   150,   151,   152,   153,   154,   156,   157,   158,
     160,   161,   163,   165,   166,   169,   170,   172,   173,   175,
     176,   178,   179,   181,   182,   184,   185,   186,   187,   188,
     190,   192,   193,   195,   196,   198,   200,   201,   202,   204,
     205,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "TIPO", "BOOLCONST",
  "STR_VAL", "OP", "CMDOP", "SEMI_COL", "LP", "RP", "LCH", "RCH", "LC",
  "RC", "COL", "ATRIB", "DOUBLEDOT", "IF", "WHILE", "FOR", "ELSE", "ROWS",
  "COLUMNS", "CELLS", "RETURN", "ID", "$accept", "program", "decl-list",
  "decl", "decl-var", "function", "params", "params-list", "param",
  "local-decl", "compound-stmt", "stmt-list", "stmt", "expr", "cond-block",
  "iter", "return", "iter-table", "variable", "simple-expr", "expr-op",
  "term", "factor", "call", "args", "args-list", "table", "list-table",
  "factor-list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,   -21,    21,     8,   -84,    50,   -84,    -1,   -84,   -84,
     -84,   -84,    56,    60,    40,    55,    54,   -84,    59,    61,
       2,    56,    67,    62,    65,   -84,   -84,   -84,   -84,   -84,
     -84,    75,    53,   -84,    42,    10,   -84,   -84,    26,   -84,
      71,     7,    13,    33,   -84,    73,   -84,   -84,   -84,   -84,
      66,   -84,    19,    78,   -84,   -84,   -84,   -84,    39,    26,
      26,    72,    77,   -84,    79,    26,    26,   -84,    46,    26,
      26,    26,   -84,    80,    81,    83,    68,   -84,   -84,    82,
      76,    84,    88,    89,   -84,    89,   -84,     2,    26,    85,
      87,    93,   -84,    26,   -84,    86,    41,    90,    94,    95,
      68,   -84,    92,    98,    88,     2,    26,    68,    97,    26,
     -84,   -84,   -84,    99,   100,     2,   101,    96,     2,    68,
     -84,    26,   -84,   -84,   102,   -84,     2,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     6,     0,     1,     3,
       5,     7,    11,     0,     0,     0,    10,    13,     0,    14,
       0,     0,     0,     0,     0,    17,     9,    12,     8,    15,
      19,    21,     0,    16,     0,     0,    48,    49,     0,    18,
       0,     0,     0,    37,    20,     0,    22,    24,    26,    25,
      46,    28,    40,    42,    44,    47,    29,    46,     0,     0,
       0,     0,     0,    34,     0,    52,     0,    23,     0,     0,
       0,     0,    45,     0,     0,     0,     0,    33,    54,     0,
      51,     0,    58,    27,    41,    39,    43,     0,     0,     0,
      37,     0,    50,     0,    38,     0,     0,    30,     0,     0,
       0,    53,     0,     0,    58,     0,     0,     0,     0,    61,
      55,    57,    31,     0,     0,     0,    60,     0,     0,     0,
      36,     0,    56,    32,     0,    59,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   112,    91,   -84,   -84,   -84,   103,   -84,
     -83,   -84,   -84,   -41,   -84,   -84,   -84,   -84,   -34,   -54,
     -32,    29,   -69,   -84,   -84,   -84,   -84,    -5,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    15,    16,    17,    31,
      26,    34,    44,    45,    46,    47,    48,    49,    57,    51,
      52,    53,    54,    55,    79,    80,    56,    96,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      50,    64,    86,    24,    97,    73,    58,     7,    50,    11,
      12,    78,    81,     1,    13,    25,    36,    37,    60,    74,
      11,     8,   112,    63,    38,    13,    50,    69,    70,    36,
      37,    61,   120,    62,    98,   123,    83,    38,    85,   101,
     116,    43,    91,   127,    65,    36,    37,    69,    66,    36,
      37,    72,   125,    38,    43,   103,    39,    38,   104,    82,
      10,    14,    40,    18,    41,   113,   108,    20,    19,    42,
      43,    21,    50,   114,    43,    22,    23,    28,    29,    30,
      32,    35,    59,    67,    68,   124,    71,    75,    76,    77,
      89,    88,    87,    93,    92,    95,    90,    69,    84,   111,
      94,    99,    66,   100,   106,   102,   107,   109,   110,   115,
     119,   118,   122,   105,   126,     9,     0,     0,   121,     0,
       0,     0,    33,     0,    27
};

static const yytype_int8 yycheck[] =
{
      34,    42,    71,     1,    87,    59,    38,    28,    42,    10,
      11,    65,    66,     5,    15,    13,     3,     4,    11,    60,
      10,     0,   105,    10,    11,    15,    60,     8,     9,     3,
       4,    24,   115,    26,    88,   118,    68,    11,    70,    93,
     109,    28,    76,   126,    11,     3,     4,     8,    15,     3,
       4,    12,   121,    11,    28,    14,    14,    11,    17,    13,
      10,     5,    20,     3,    22,   106,   100,    12,    28,    27,
      28,    17,   106,   107,    28,    16,    15,    10,    16,    14,
       5,    28,    11,    10,    18,   119,     8,    15,    11,    10,
       7,    10,    12,    17,    12,     7,    28,     8,    69,   104,
      16,    16,    15,    10,    10,    19,    11,    15,    10,    12,
      10,    12,    16,    23,    12,     3,    -1,    -1,    17,    -1,
      -1,    -1,    31,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    30,    31,    32,    33,    34,    28,     0,    32,
      10,    10,    11,    15,     5,    35,    36,    37,     3,    28,
      12,    17,    16,    15,     1,    13,    39,    37,    10,    16,
      14,    38,     5,    33,    40,    28,     3,     4,    11,    14,
      20,    22,    27,    28,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    55,    47,    49,    11,
      11,    24,    26,    10,    42,    11,    15,    10,    18,     8,
       9,     8,    12,    48,    42,    15,    11,    10,    48,    53,
      54,    48,    13,    49,    50,    49,    51,    12,    10,     7,
      28,    47,    12,    17,    16,     7,    56,    39,    48,    16,
      10,    48,    19,    14,    17,    23,    10,    11,    47,    15,
      10,    56,    39,    42,    47,    12,    51,    57,    12,    10,
      39,    17,    16,    39,    47,    51,    12,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    33,    33,    34,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    40,    41,    41,    41,    41,    41,    42,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      52,    53,    53,    54,    54,    55,    56,    56,    56,    57,
      57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     3,     6,     6,
       1,     0,     3,     1,     2,     4,     2,     0,     4,     2,
       2,     0,     1,     2,     1,     1,     1,     3,     1,     1,
       5,     7,     9,     3,     2,    11,     8,     1,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       4,     1,     0,     3,     1,     6,     5,     3,     0,     3,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
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
  case 2:
#line 114 "src/syntactic_analyzer.y"
                   { (yyval._program) = newProgramNode((yyvsp[0]._decl_list)); 
                     print_declList((yyvsp[0]._decl_list), 0);
                     print_symbol_table();
                     free_symbol_table();
                     free_stack();}
#line 1481 "src/panelc_parser.c"
    break;

  case 3:
#line 120 "src/syntactic_analyzer.y"
                          { (yyval._decl_list) = newDeclListNode((yyvsp[-1]._decl_list), (yyvsp[0]._decl)); }
#line 1487 "src/panelc_parser.c"
    break;

  case 4:
#line 121 "src/syntactic_analyzer.y"
                  { (yyval._decl_list) = newDeclListNode(NULL, (yyvsp[0]._decl)); }
#line 1493 "src/panelc_parser.c"
    break;

  case 5:
#line 123 "src/syntactic_analyzer.y"
                        { (yyval._decl) = newDeclNode((yyvsp[-1]._decl_var),NULL); }
#line 1499 "src/panelc_parser.c"
    break;

  case 6:
#line 124 "src/syntactic_analyzer.y"
                 { (yyval._decl) = newDeclNode(NULL, (yyvsp[0]._function)); }
#line 1505 "src/panelc_parser.c"
    break;

  case 7:
#line 126 "src/syntactic_analyzer.y"
                           { (yyval._decl_var) = newDeclVarNode((yyvsp[-2].tipo), (yyvsp[-1].id), -1); add_store_variable((yyvsp[-1].id), (yyvsp[-2].tipo), 'V'); }
#line 1511 "src/panelc_parser.c"
    break;

  case 8:
#line 127 "src/syntactic_analyzer.y"
                                       { (yyval._decl_var) = newDeclVarNode((yyvsp[-5].tipo), (yyvsp[-4].id), (yyvsp[-2].i_val)); add_store_variable((yyvsp[-4].id), (yyvsp[-5].tipo), 'A'); }
#line 1517 "src/panelc_parser.c"
    break;

  case 9:
#line 129 "src/syntactic_analyzer.y"
                                             { scope_push((yyvsp[-4].id)); transfer_to_symbol_table();
                                               (yyval._function) = newFunctionNode((yyvsp[-4].id), (yyvsp[-5].tipo), (yyvsp[-2]._params), (yyvsp[0]._compound_stmt)); add_store_variable((yyvsp[-4].id), (yyvsp[-5].tipo), 'F'); }
#line 1524 "src/panelc_parser.c"
    break;

  case 10:
#line 132 "src/syntactic_analyzer.y"
                    { (yyval._params) = newParamsNode((yyvsp[0]._params_list)); }
#line 1530 "src/panelc_parser.c"
    break;

  case 11:
#line 133 "src/syntactic_analyzer.y"
          {(yyval._params) = NULL;}
#line 1536 "src/panelc_parser.c"
    break;

  case 12:
#line 135 "src/syntactic_analyzer.y"
                                   { (yyval._params_list) = newParamsListNode((yyvsp[-2]._params_list), (yyvsp[0]._param)); }
#line 1542 "src/panelc_parser.c"
    break;

  case 13:
#line 136 "src/syntactic_analyzer.y"
                     { (yyval._params_list) = newParamsListNode(NULL, (yyvsp[0]._param)); }
#line 1548 "src/panelc_parser.c"
    break;

  case 14:
#line 138 "src/syntactic_analyzer.y"
               { (yyval._param) = newParamNode((yyvsp[-1].tipo), (yyvsp[0].id), 0); add_store_variable((yyvsp[0].id), (yyvsp[-1].tipo), 'P'); }
#line 1554 "src/panelc_parser.c"
    break;

  case 15:
#line 139 "src/syntactic_analyzer.y"
                       { (yyval._param) = newParamNode((yyvsp[-3].tipo), (yyvsp[-2].id), 1); add_store_variable((yyvsp[-2].id), (yyvsp[-3].tipo), 'P'); }
#line 1560 "src/panelc_parser.c"
    break;

  case 16:
#line 141 "src/syntactic_analyzer.y"
                                { (yyval._local_decl) = newLocalDeclNode((yyvsp[-1]._local_decl), (yyvsp[0]._decl_var)); }
#line 1566 "src/panelc_parser.c"
    break;

  case 17:
#line 142 "src/syntactic_analyzer.y"
              {(yyval._local_decl) = NULL;}
#line 1572 "src/panelc_parser.c"
    break;

  case 18:
#line 144 "src/syntactic_analyzer.y"
                                            { (yyval._compound_stmt) = newCompoundStmtNode((yyvsp[-2]._local_decl), (yyvsp[-1]._stmt_list)); }
#line 1578 "src/panelc_parser.c"
    break;

  case 19:
#line 145 "src/syntactic_analyzer.y"
                           { (yyval._compound_stmt) = NULL; }
#line 1584 "src/panelc_parser.c"
    break;

  case 20:
#line 147 "src/syntactic_analyzer.y"
                          { (yyval._stmt_list) = newStmtListNode((yyvsp[-1]._stmt_list), (yyvsp[0]._stmt)); }
#line 1590 "src/panelc_parser.c"
    break;

  case 21:
#line 148 "src/syntactic_analyzer.y"
             {(yyval._stmt_list) = NULL;}
#line 1596 "src/panelc_parser.c"
    break;

  case 22:
#line 150 "src/syntactic_analyzer.y"
                 { (yyval._stmt) = newStmtNode((yyvsp[0]._cond_block), NULL, NULL, NULL, NULL); }
#line 1602 "src/panelc_parser.c"
    break;

  case 23:
#line 151 "src/syntactic_analyzer.y"
                      { (yyval._stmt) = newStmtNode(NULL, (yyvsp[-1]._expr), NULL, NULL, NULL); }
#line 1608 "src/panelc_parser.c"
    break;

  case 24:
#line 152 "src/syntactic_analyzer.y"
             { (yyval._stmt) = newStmtNode(NULL, NULL, (yyvsp[0]._iter), NULL, NULL); }
#line 1614 "src/panelc_parser.c"
    break;

  case 25:
#line 153 "src/syntactic_analyzer.y"
                   { (yyval._stmt) = newStmtNode(NULL, NULL, NULL, (yyvsp[0]._iter_table), NULL); }
#line 1620 "src/panelc_parser.c"
    break;

  case 26:
#line 154 "src/syntactic_analyzer.y"
               { (yyval._stmt) = newStmtNode(NULL, NULL, NULL, NULL, (yyvsp[0]._retrn)); }
#line 1626 "src/panelc_parser.c"
    break;

  case 27:
#line 156 "src/syntactic_analyzer.y"
                             { (yyval._expr) = newExprNode((yyvsp[-2]._variable), (yyvsp[0]._expr_op), NULL, NULL);  }
#line 1632 "src/panelc_parser.c"
    break;

  case 28:
#line 157 "src/syntactic_analyzer.y"
                    { (yyval._expr) = newExprNode(NULL, NULL, (yyvsp[0]._simple_expr), NULL); }
#line 1638 "src/panelc_parser.c"
    break;

  case 29:
#line 158 "src/syntactic_analyzer.y"
              { (yyval._expr) = newExprNode(NULL, NULL, NULL, (yyvsp[0]._table)); }
#line 1644 "src/panelc_parser.c"
    break;

  case 30:
#line 160 "src/syntactic_analyzer.y"
                                               { (yyval._cond_block) = newCondBlockNode((yyvsp[-2]._simple_expr), (yyvsp[0]._compound_stmt), NULL); }
#line 1650 "src/panelc_parser.c"
    break;

  case 31:
#line 161 "src/syntactic_analyzer.y"
                                                                    { (yyval._cond_block) = newCondBlockNode((yyvsp[-4]._simple_expr), (yyvsp[-2]._compound_stmt), (yyvsp[0]._compound_stmt)); }
#line 1656 "src/panelc_parser.c"
    break;

  case 32:
#line 163 "src/syntactic_analyzer.y"
                                                                      { (yyval._iter) = newIterNode((yyvsp[-6]._expr), (yyvsp[-4]._simple_expr), (yyvsp[-2]._expr), (yyvsp[0]._compound_stmt)); }
#line 1662 "src/panelc_parser.c"
    break;

  case 33:
#line 165 "src/syntactic_analyzer.y"
                             { (yyval._retrn) = newReturnNode((yyvsp[-1]._expr)); }
#line 1668 "src/panelc_parser.c"
    break;

  case 34:
#line 166 "src/syntactic_analyzer.y"
                          { (yyval._retrn) = newReturnNode(NULL); }
#line 1674 "src/panelc_parser.c"
    break;

  case 35:
#line 169 "src/syntactic_analyzer.y"
                                                                                  { (yyval._iter_table) = newIterTableNode((yyvsp[-4]._variable), (yyvsp[-2]._variable), (yyvsp[0]._compound_stmt)); }
#line 1680 "src/panelc_parser.c"
    break;

  case 36:
#line 170 "src/syntactic_analyzer.y"
                                                                       { (yyval._iter_table) = newIterTableNode((yyvsp[-4]._variable), (yyvsp[-2]._variable), (yyvsp[0]._compound_stmt)); }
#line 1686 "src/panelc_parser.c"
    break;

  case 37:
#line 172 "src/syntactic_analyzer.y"
             { (yyval._variable) = newVariableNode(NULL, (yyvsp[0].id), 0);  }
#line 1692 "src/panelc_parser.c"
    break;

  case 38:
#line 173 "src/syntactic_analyzer.y"
                                  { (yyval._variable) = newVariableNode((yyvsp[-1]._simple_expr), (yyvsp[-3].id), 1); }
#line 1698 "src/panelc_parser.c"
    break;

  case 39:
#line 175 "src/syntactic_analyzer.y"
                                    { (yyval._simple_expr) = newSimpleExprNode((yyvsp[-2]._expr_op), (yyvsp[-1].cmdop), (yyvsp[0]._expr_op)); }
#line 1704 "src/panelc_parser.c"
    break;

  case 40:
#line 176 "src/syntactic_analyzer.y"
                       { char* n_str = "\0"; (yyval._simple_expr) = newSimpleExprNode((yyvsp[0]._expr_op), n_str, NULL); }
#line 1710 "src/panelc_parser.c"
    break;

  case 41:
#line 178 "src/syntactic_analyzer.y"
                         { (yyval._expr_op) = newExprOpNode((yyvsp[-2]._expr_op), (yyvsp[0]._term)); }
#line 1716 "src/panelc_parser.c"
    break;

  case 42:
#line 179 "src/syntactic_analyzer.y"
                { (yyval._expr_op) = newExprOpNode(NULL, (yyvsp[0]._term)); }
#line 1722 "src/panelc_parser.c"
    break;

  case 43:
#line 181 "src/syntactic_analyzer.y"
                     { (yyval._term) = newTermNode((yyvsp[-2]._term), (yyvsp[0]._factor)); }
#line 1728 "src/panelc_parser.c"
    break;

  case 44:
#line 182 "src/syntactic_analyzer.y"
               { (yyval._term) = newTermNode(NULL, (yyvsp[0]._factor)); }
#line 1734 "src/panelc_parser.c"
    break;

  case 45:
#line 184 "src/syntactic_analyzer.y"
                      { (yyval._factor) = newFactorNode((yyvsp[-1]._expr_op), NULL, NULL, 0, 0, 0); }
#line 1740 "src/panelc_parser.c"
    break;

  case 46:
#line 185 "src/syntactic_analyzer.y"
                   { (yyval._factor) = newFactorNode(NULL, (yyvsp[0]._variable), NULL, 0, 0, 0); }
#line 1746 "src/panelc_parser.c"
    break;

  case 47:
#line 186 "src/syntactic_analyzer.y"
               { (yyval._factor) = newFactorNode(NULL, NULL, (yyvsp[0]._call), 0, 0, 0); }
#line 1752 "src/panelc_parser.c"
    break;

  case 48:
#line 187 "src/syntactic_analyzer.y"
              { (yyval._factor) = newFactorNode(NULL, NULL, NULL, (yyvsp[0].i_val), 0, 1); }
#line 1758 "src/panelc_parser.c"
    break;

  case 49:
#line 188 "src/syntactic_analyzer.y"
                { (yyval._factor) = newFactorNode(NULL, NULL, NULL, 0, (yyvsp[0].f_val), 2); }
#line 1764 "src/panelc_parser.c"
    break;

  case 50:
#line 190 "src/syntactic_analyzer.y"
                    { (yyval._call) = newCallNode((yyvsp[-1]._args), (yyvsp[-3].id)); }
#line 1770 "src/panelc_parser.c"
    break;

  case 51:
#line 192 "src/syntactic_analyzer.y"
                { (yyval._args) = newArgsNode((yyvsp[0]._args_list)); }
#line 1776 "src/panelc_parser.c"
    break;

  case 52:
#line 193 "src/syntactic_analyzer.y"
        {(yyval._args) = NULL;}
#line 1782 "src/panelc_parser.c"
    break;

  case 53:
#line 195 "src/syntactic_analyzer.y"
                                      { (yyval._args_list) = newArgsListNode((yyvsp[-2]._args_list), NULL, (yyvsp[0]._simple_expr)); }
#line 1788 "src/panelc_parser.c"
    break;

  case 54:
#line 196 "src/syntactic_analyzer.y"
                          { (yyval._args_list) = newArgsListNode(NULL, NULL, (yyvsp[0]._simple_expr)); }
#line 1794 "src/panelc_parser.c"
    break;

  case 55:
#line 198 "src/syntactic_analyzer.y"
                                                  { (yyval._table) = newTableNode((yyvsp[-5]._variable), (yyvsp[-2]._list_table)); }
#line 1800 "src/panelc_parser.c"
    break;

  case 56:
#line 200 "src/syntactic_analyzer.y"
                                                { (yyval._list_table) = newListTableNode((yyvsp[-1]._factor_list), NULL, NULL); }
#line 1806 "src/panelc_parser.c"
    break;

  case 57:
#line 201 "src/syntactic_analyzer.y"
                                        { (yyval._list_table) = newListTableNode(NULL, (yyvsp[-2]._list_table), (yyvsp[0]._list_table)); }
#line 1812 "src/panelc_parser.c"
    break;

  case 58:
#line 202 "src/syntactic_analyzer.y"
              {(yyval._list_table) = NULL;}
#line 1818 "src/panelc_parser.c"
    break;

  case 59:
#line 204 "src/syntactic_analyzer.y"
                               { (yyval._factor_list) = newFactorListNode((yyvsp[-2]._factor), (yyvsp[0]._factor)); }
#line 1824 "src/panelc_parser.c"
    break;

  case 60:
#line 205 "src/syntactic_analyzer.y"
                      {{ (yyval._factor_list) = newFactorListNode((yyvsp[0]._factor), NULL); }}
#line 1830 "src/panelc_parser.c"
    break;

  case 61:
#line 206 "src/syntactic_analyzer.y"
               {(yyval._factor_list) = NULL;}
#line 1836 "src/panelc_parser.c"
    break;


#line 1840 "src/panelc_parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 208 "src/syntactic_analyzer.y"


void transfer_to_symbol_table(){
    StoreVariables *tmp, *elt;
    DL_FOREACH_SAFE(variable_list, elt, tmp) {
        add_symbol(elt->name, elt->type, elt->symbol_type, scope_top());
        DL_DELETE(variable_list, elt);
        free(elt);
    }
}

void add_store_variable(char *name, char* type, char symbol_type) {
    StoreVariables * s;
    s = create_variable(name, type, symbol_type);
    DL_APPEND(variable_list, s);
} 

StoreVariables* create_variable(char *name, char* type, char symbol_type) {
    StoreVariables *s = (StoreVariables *)malloc(sizeof *s);
    s->name = strdup(name);
    s->type = strdup(type);
    s->symbol_type = symbol_type;    
    return s;
}

void free_stack() {
    while(STACK_EMPTY(stack)){
        ScopeStack *s;
        STACK_POP(stack, s);
        free(s);
    }
}

ScopeStack *create_scope(char *name) {
    ScopeStack *s = (ScopeStack *)malloc(sizeof *s);
    strcpy(s->name, name);
    return s;
}

void scope_push(char* scope) {
    ScopeStack *s;
    s = create_scope(scope);
    STACK_PUSH(stack, s);
}

char* scope_top() {
    ScopeStack *s = STACK_TOP(stack);
    return s->name;
}

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 pelo end of string
    strcpy(result, s1);
    strcat(result, "::");
    strcat(result, s2);
    return result;
}

void add_symbol(char *name, char* type, char symbol_type, char* scope) {
    SymbolTable *s;
    char scope_string[100];
    sprintf(scope_string, "%s", scope);
    char *key = concat(name, scope_string);
    HASH_FIND_STR(symbol_table, name, s);
    if(s == NULL){
        s = create_symbol(key, name, type, symbol_type, scope);
        HASH_ADD_STR(symbol_table, name, s);
    }
}

SymbolTable* create_symbol(char* key, char *name, char* type, char symbol_type, char* scope){
    SymbolTable *s = (SymbolTable *)malloc(sizeof *s);
    s->key = strdup(key);
    s->name = strdup(name);
    s->type = strdup(type);
    s->symbol_type = symbol_type;
    s->scope = strdup(scope);
    return s;
}

void print_symbol_table() {
    SymbolTable *s = NULL;
    printf("\n\n------------------------------- BEGIN Symbol Table -----------------------------\n\n");
    for(s=symbol_table; s != NULL; s=s->hh.next) {
        printf("key: %20s | name: %20s | type: %20s | symbol_type: %c | scope: %s\n", s->key, s->name, s->type, s->symbol_type, s->scope);
    }
    printf("\n-------------------------------  END Symbol Table -----------------------------\n\n");
}

void free_symbol_table(){
    SymbolTable *s, *tmp;
    HASH_ITER(hh, symbol_table, s, tmp) {
        HASH_DEL(symbol_table, s);
        free(s);
    }
}

int main(int argc, char **argv) {
    // scope_push("global");
    ++argv, --argc;
    if(argc > 0)
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;
    yyparse();
    yylex_destroy();
    return 0;
}
