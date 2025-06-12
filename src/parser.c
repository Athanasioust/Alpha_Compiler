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
#line 1 "parser.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <assert.h>
	#include <stdbool.h>
	#include "../include/symtable.h"
	#include "../include/structs.h"
	#include "../include/stack.h"
	#include "../include/rule_handler.h"
	#include "../include/parser.h"
    #include "../include/target.h"

    int yyerror(char* message);
    int yylex(void);
    
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;

#line 92 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_LOCAL = 17,                     /* LOCAL  */
  YYSYMBOL_TRUE = 18,                      /* TRUE  */
  YYSYMBOL_FALSE = 19,                     /* FALSE  */
  YYSYMBOL_NIL = 20,                       /* NIL  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_EQUAL = 27,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 28,                    /* NEQUAL  */
  YYSYMBOL_INC = 29,                       /* INC  */
  YYSYMBOL_DEC = 30,                       /* DEC  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GET = 33,                       /* GET  */
  YYSYMBOL_LET = 34,                       /* LET  */
  YYSYMBOL_BRACKET_OPEN = 35,              /* BRACKET_OPEN  */
  YYSYMBOL_BRACKET_CLOSED = 36,            /* BRACKET_CLOSED  */
  YYSYMBOL_SQUARE_OPEN = 37,               /* SQUARE_OPEN  */
  YYSYMBOL_SQUARE_CLOSED = 38,             /* SQUARE_CLOSED  */
  YYSYMBOL_PAR_OPEN = 39,                  /* PAR_OPEN  */
  YYSYMBOL_PAR_CLOSED = 40,                /* PAR_CLOSED  */
  YYSYMBOL_SEMI_COLON = 41,                /* SEMI_COLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_DOUBLE_COLON = 44,              /* DOUBLE_COLON  */
  YYSYMBOL_DOT = 45,                       /* DOT  */
  YYSYMBOL_DOUBLE_DOT = 46,                /* DOUBLE_DOT  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 48,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_stmts = 51,                     /* stmts  */
  YYSYMBOL_stmts_other = 52,               /* stmts_other  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_assignexpr = 56,                /* assignexpr  */
  YYSYMBOL_prim = 57,                      /* prim  */
  YYSYMBOL_lvalue = 58,                    /* lvalue  */
  YYSYMBOL_member = 59,                    /* member  */
  YYSYMBOL_call = 60,                      /* call  */
  YYSYMBOL_callsuffix = 61,                /* callsuffix  */
  YYSYMBOL_normcall = 62,                  /* normcall  */
  YYSYMBOL_methodcall = 63,                /* methodcall  */
  YYSYMBOL_elist = 64,                     /* elist  */
  YYSYMBOL_objectdef = 65,                 /* objectdef  */
  YYSYMBOL_indexed = 66,                   /* indexed  */
  YYSYMBOL_indexedelem = 67,               /* indexedelem  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_funcdef = 70,                   /* funcdef  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_funcbody = 72,                  /* funcbody  */
  YYSYMBOL_funcprefix = 73,                /* funcprefix  */
  YYSYMBOL_funcargs = 74,                  /* funcargs  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_funcname = 77,                  /* funcname  */
  YYSYMBOL_const = 78,                     /* const  */
  YYSYMBOL_idlist = 79,                    /* idlist  */
  YYSYMBOL_ifprefix = 80,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 81,                /* elseprefix  */
  YYSYMBOL_ifstmt = 82,                    /* ifstmt  */
  YYSYMBOL_whileprefix = 83,               /* whileprefix  */
  YYSYMBOL_whileargs = 84,                 /* whileargs  */
  YYSYMBOL_whilestmt = 85,                 /* whilestmt  */
  YYSYMBOL_N = 86,                         /* N  */
  YYSYMBOL_M = 87,                         /* M  */
  YYSYMBOL_forprefix = 88,                 /* forprefix  */
  YYSYMBOL_89_5 = 89,                      /* $@5  */
  YYSYMBOL_forstmt = 90,                   /* forstmt  */
  YYSYMBOL_returnstmt = 91,                /* returnstmt  */
  YYSYMBOL_break = 92,                     /* break  */
  YYSYMBOL_continue = 93                   /* continue  */
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
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   541

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    76,    77,    80,    81,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   117,   118,   119,   120,   121,   122,   123,   124,
     127,   129,   130,   131,   132,   133,   136,   137,   138,   139,
     142,   143,   144,   145,   148,   149,   150,   153,   154,   157,
     159,   161,   162,   163,   167,   170,   173,   177,   178,   181,
     183,   183,   186,   185,   200,   205,   208,   213,   207,   224,
     225,   228,   229,   230,   231,   232,   235,   236,   237,   240,
     242,   244,   245,   253,   255,   257,   259,   260,   262,   262,
     264,   266,   273,   283,   291
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "IDENT",
  "STRING", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK",
  "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE", "FALSE", "NIL",
  "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQUAL", "NEQUAL", "INC",
  "DEC", "GT", "LT", "GET", "LET", "BRACKET_OPEN", "BRACKET_CLOSED",
  "SQUARE_OPEN", "SQUARE_CLOSED", "PAR_OPEN", "PAR_CLOSED", "SEMI_COLON",
  "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT", "UMINUS",
  "LOWER_THAN_ELSE", "$accept", "program", "stmts", "stmts_other", "stmt",
  "expr", "term", "assignexpr", "prim", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "block", "$@1", "funcdef", "$@2", "funcbody",
  "funcprefix", "funcargs", "$@3", "$@4", "funcname", "const", "idlist",
  "ifprefix", "elseprefix", "ifstmt", "whileprefix", "whileargs",
  "whilestmt", "N", "M", "forprefix", "$@5", "forstmt", "returnstmt",
  "break", "continue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,  -168,  -168,  -168,   -29,  -168,  -168,     9,   130,   -27,
     -24,   197,    20,  -168,  -168,  -168,   197,    15,    15,  -168,
      93,   174,  -168,    24,    31,  -168,    33,  -168,   264,  -168,
    -168,  -168,   377,  -168,   -10,  -168,  -168,  -168,  -168,  -168,
      33,  -168,    -9,  -168,  -168,  -168,  -168,  -168,  -168,   197,
      -6,  -168,  -168,  -168,   285,  -168,  -168,  -168,  -168,  -168,
      37,    30,   -10,    30,    33,   197,  -168,   243,    -4,    17,
      16,   327,    51,  -168,  -168,  -168,  -168,  -168,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,  -168,
     197,  -168,  -168,   197,   197,    53,    56,  -168,  -168,  -168,
     197,   197,    69,    60,    85,   197,    33,   197,   348,   197,
    -168,    55,    68,   221,   197,  -168,  -168,    72,  -168,    70,
     197,   197,    77,    77,  -168,  -168,  -168,   494,   494,   199,
     199,   199,   199,   466,   403,    74,  -168,    76,   424,    78,
    -168,  -168,    82,  -168,    33,   369,  -168,    79,  -168,    83,
      70,  -168,   197,  -168,  -168,   197,   507,   481,  -168,  -168,
     197,  -168,  -168,   121,  -168,  -168,  -168,  -168,  -168,  -168,
     445,    86,    89,    94,  -168,    33,   197,  -168,  -168,  -168,
     121,    98,  -168,   306,  -168,  -168,  -168,  -168
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    81,    46,    82,     0,    93,    98,    80,     0,     0,
       0,     0,     0,    84,    85,    83,     0,     0,     0,    70,
       0,     0,    16,     0,     0,     2,     3,     5,     0,    31,
      17,    39,    41,    49,    42,    43,    14,    15,    72,    45,
       0,     8,     0,     9,    96,    10,    11,    13,    12,     0,
       0,    79,    75,   101,     0,   103,   104,    34,    47,    33,
       0,    35,     0,    37,     4,     0,    64,    61,     0,     0,
      67,     0,     0,    48,     1,     6,    97,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,    36,    38,     0,    63,     0,     0,    55,    57,    58,
       0,    63,     0,     0,    91,     0,     0,    63,     0,    63,
     102,     0,     0,     0,    63,    65,    66,     0,    32,    44,
       0,     0,    18,    19,    20,    21,    22,    27,    28,    23,
      25,    24,    26,    40,     0,     0,    50,     0,     0,     0,
      52,    76,     0,    90,     0,     0,    95,     0,    89,     0,
       0,    71,     0,    62,    68,    63,    29,    30,    51,    59,
      63,    53,    54,    88,    74,    73,    92,    94,    96,    97,
       0,     0,     0,    86,    77,     0,     0,    69,    56,    60,
      88,     0,    96,     0,    87,    78,   100,    99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,    75,  -168,   -17,     0,  -168,  -168,  -168,   -14,
    -168,   -11,  -168,  -168,  -168,   -89,  -168,    23,  -168,    -1,
    -168,     1,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
     -38,  -168,  -168,  -168,  -168,  -168,  -168,  -167,   -75,  -168,
    -168,  -168,  -168,  -168,  -168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    24,    25,    26,    27,    67,    29,    30,    31,    32,
      33,    34,    97,    98,    99,    68,    35,    69,    70,    36,
      64,    37,   103,   165,    38,   142,   163,   181,    52,    39,
     174,    40,   144,    41,    42,   106,    43,   107,   120,    44,
      50,    45,    46,    47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   175,   121,    61,    63,   135,    62,    62,    54,    75,
      49,    57,   139,    51,    55,   186,    59,    56,   147,     2,
     149,    71,    72,   104,    58,   153,    28,   100,    73,   101,
     105,    74,    12,   109,   115,   102,     1,     2,     3,     4,
      28,     5,     6,     7,     8,     9,    10,     7,    11,   108,
      12,    13,    14,    15,    60,   116,    16,   136,   117,    23,
     137,   111,    17,    18,    28,   113,   171,    93,    19,    94,
      20,   172,    21,   140,    22,    95,    96,    23,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   146,
     133,   119,   143,   134,   176,   150,     1,     2,     3,   141,
     138,    80,    81,    82,   151,   145,    28,    65,    11,   155,
      12,    13,    14,    15,   159,   160,    16,    19,   162,   168,
     156,   157,    17,    18,   169,   173,   178,   166,    65,   179,
      20,    66,    21,     1,     2,     3,   180,    23,   185,   112,
     154,   164,   184,     0,    28,    11,     0,    12,    13,    14,
      15,     0,   170,    16,     0,     0,     0,     0,   182,    17,
      18,     0,     0,     0,     0,     0,     0,    20,     0,    21,
       0,    53,     0,     0,    23,    28,   183,     1,     2,     3,
       0,     0,     0,     0,     7,     0,     0,     0,     0,    11,
       0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
       1,     2,     3,    17,    18,     0,     0,     0,     0,     0,
       0,    20,    11,    21,    12,    13,    14,    15,    23,     0,
      16,    78,    79,    80,    81,    82,    17,    18,     0,     0,
      -1,    -1,    -1,    -1,    20,    76,    21,    77,     0,     0,
       0,    23,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    85,    86,    87,    88,     0,    76,     0,    77,
       0,     0,     0,     0,   152,    78,    79,    80,    81,    82,
      83,    84,     0,     0,    85,    86,    87,    88,    76,     0,
      77,     0,     0,     0,     0,   114,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    85,    86,    87,    88,    76,
       0,    77,     0,     0,     0,    89,     0,    78,    79,    80,
      81,    82,    83,    84,     0,     0,    85,    86,    87,    88,
      76,     0,    77,     0,     0,     0,   110,     0,    78,    79,
      80,    81,    82,    83,    84,     0,     0,    85,    86,    87,
      88,    76,     0,    77,     0,     0,     0,   187,     0,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    85,    86,
      87,    88,    76,     0,    77,     0,     0,   118,     0,     0,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    85,
      86,    87,    88,    76,     0,    77,     0,     0,   148,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    90,     0,
      85,    86,    87,    88,     0,     0,    91,    92,     0,   167,
       0,     0,     0,     0,    93,     0,    94,    76,     0,    77,
       0,     0,    95,    96,     0,    78,    79,    80,    81,    82,
      83,    84,     0,     0,    85,    86,    87,    88,    76,     0,
      77,   158,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    85,    86,    87,    88,    76,
       0,    77,   161,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,     0,     0,    85,    86,    87,    88,
      76,   177,    77,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    76,     0,    85,    86,    87,
      88,     0,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    85,    86,    87,    88,    78,    79,    80,    81,
      82,    -1,    -1,     0,     0,    85,    86,    87,    88,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    85,    86,
      87,    88
};

static const yytype_int16 yycheck[] =
{
       0,   168,    77,    17,    18,    94,    17,    18,     8,    26,
      39,    11,   101,     4,    41,   182,    16,    41,   107,     4,
     109,    21,    21,    40,     4,   114,    26,    37,     4,    39,
      39,     0,    17,    39,    38,    45,     3,     4,     5,     6,
      40,     8,     9,    10,    11,    12,    13,    10,    15,    49,
      17,    18,    19,    20,    39,    38,    23,     4,    42,    44,
       4,    60,    29,    30,    64,    65,   155,    37,    35,    39,
      37,   160,    39,     4,    41,    45,    46,    44,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   106,
      90,    40,     7,    93,   169,    40,     3,     4,     5,    39,
     100,    24,    25,    26,    36,   105,   106,    35,    15,    39,
      17,    18,    19,    20,    40,    39,    23,    35,    40,    40,
     120,   121,    29,    30,    41,     4,    40,   144,    35,    40,
      37,    38,    39,     3,     4,     5,    42,    44,    40,    64,
     117,   142,   180,    -1,   144,    15,    -1,    17,    18,    19,
      20,    -1,   152,    23,    -1,    -1,    -1,    -1,   175,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    44,   175,   176,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    -1,    23,    -1,    -1,
       3,     4,     5,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    15,    39,    17,    18,    19,    20,    44,    -1,
      23,    22,    23,    24,    25,    26,    29,    30,    -1,    -1,
      31,    32,    33,    34,    37,    14,    39,    16,    -1,    -1,
      -1,    44,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    -1,    14,    -1,    16,
      -1,    -1,    -1,    -1,    43,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    14,    -1,
      16,    -1,    -1,    -1,    -1,    42,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    14,
      -1,    16,    -1,    -1,    -1,    41,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      14,    -1,    16,    -1,    -1,    -1,    41,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    14,    -1,    16,    -1,    -1,    -1,    41,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    14,    -1,    16,    -1,    -1,    40,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    14,    -1,    16,    -1,    -1,    40,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    21,    -1,
      31,    32,    33,    34,    -1,    -1,    29,    30,    -1,    40,
      -1,    -1,    -1,    -1,    37,    -1,    39,    14,    -1,    16,
      -1,    -1,    45,    46,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    14,    -1,
      16,    38,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    14,
      -1,    16,    38,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      14,    36,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    14,    -1,    31,    32,    33,
      34,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    12,
      13,    15,    17,    18,    19,    20,    23,    29,    30,    35,
      37,    39,    41,    44,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    65,    68,    70,    73,    78,
      80,    82,    83,    85,    88,    90,    91,    92,    93,    39,
      89,     4,    77,    41,    54,    41,    41,    54,     4,    54,
      39,    58,    60,    58,    69,    35,    38,    54,    64,    66,
      67,    54,    70,     4,     0,    53,    14,    16,    22,    23,
      24,    25,    26,    27,    28,    31,    32,    33,    34,    41,
      21,    29,    30,    37,    39,    45,    46,    61,    62,    63,
      37,    39,    45,    71,    53,    39,    84,    86,    54,    39,
      41,    70,    51,    54,    42,    38,    38,    42,    40,    40,
      87,    87,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    64,     4,     4,    54,    64,
       4,    39,    74,     7,    81,    54,    53,    64,    40,    64,
      40,    36,    43,    64,    66,    39,    54,    54,    38,    40,
      39,    38,    40,    75,    68,    72,    53,    40,    40,    41,
      54,    64,    64,     4,    79,    86,    87,    36,    40,    40,
      42,    76,    53,    54,    79,    40,    86,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    60,    60,    60,    61,    61,    62,
      63,    64,    64,    64,    65,    65,    65,    66,    66,    67,
      69,    68,    71,    70,    72,    73,    75,    76,    74,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    79,    80,
      81,    82,    82,    83,    84,    85,    86,    87,    89,    88,
      90,    91,    91,    92,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     3,
       5,     1,     3,     0,     2,     3,     3,     1,     3,     5,
       0,     4,     0,     4,     1,     2,     0,     0,     5,     1,
       0,     1,     1,     1,     1,     1,     1,     3,     0,     4,
       1,     2,     4,     1,     3,     3,     0,     0,     0,     8,
       7,     2,     3,     2,     2
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
  case 3: /* stmts: stmts_other  */
#line 76 "parser.y"
                                { (yyval.stmtval) = (yyvsp[0].stmtval); }
#line 1376 "parser.c"
    break;

  case 4: /* stmts: %empty  */
#line 77 "parser.y"
                                        { (yyval.stmtval) = (stmt_t*) 0;}
#line 1382 "parser.c"
    break;

  case 5: /* stmts_other: stmt  */
#line 80 "parser.y"
                                                  { (yyval.stmtval) = (yyvsp[0].stmtval); }
#line 1388 "parser.c"
    break;

  case 6: /* stmts_other: stmts_other stmt  */
#line 81 "parser.y"
                                   {  // Remove {resetTemp();}
                                            if((yyvsp[-1].stmtval)) (yyval.stmtval) = (yyvsp[-1].stmtval);
                                            else if((yyvsp[0].stmtval)) (yyval.stmtval) = (yyvsp[0].stmtval);
                                            else (yyval.stmtval) = (stmt_t*) 0;
                                        }
#line 1398 "parser.c"
    break;

  case 7: /* stmt: expr SEMI_COLON  */
#line 88 "parser.y"
                             { (yyval.stmtval) = (stmt_t*) 0; makeBoolStmt((yyvsp[-1].exprval));}
#line 1404 "parser.c"
    break;

  case 8: /* stmt: ifstmt  */
#line 89 "parser.y"
                                        {(yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1410 "parser.c"
    break;

  case 9: /* stmt: whilestmt  */
#line 90 "parser.y"
                                        {(yyval.stmtval) = (stmt_t*) 0;}
#line 1416 "parser.c"
    break;

  case 10: /* stmt: forstmt  */
#line 91 "parser.y"
                                        {(yyval.stmtval) = (stmt_t*) 0;}
#line 1422 "parser.c"
    break;

  case 11: /* stmt: returnstmt  */
#line 92 "parser.y"
                                        {(yyval.stmtval) = (stmt_t*) 0;}
#line 1428 "parser.c"
    break;

  case 12: /* stmt: continue  */
#line 93 "parser.y"
                                        {(yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1434 "parser.c"
    break;

  case 13: /* stmt: break  */
#line 94 "parser.y"
                                        {(yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1440 "parser.c"
    break;

  case 14: /* stmt: block  */
#line 95 "parser.y"
                                        {(yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1446 "parser.c"
    break;

  case 15: /* stmt: funcdef  */
#line 96 "parser.y"
                                        {(yyval.stmtval) = (stmt_t*) 0;}
#line 1452 "parser.c"
    break;

  case 16: /* stmt: SEMI_COLON  */
#line 97 "parser.y"
                                        {(yyval.stmtval) = (stmt_t*) 0;}
#line 1458 "parser.c"
    break;

  case 17: /* expr: assignexpr  */
#line 100 "parser.y"
                                          {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1464 "parser.c"
    break;

  case 18: /* expr: expr PLUS expr  */
#line 101 "parser.y"
                                    {(yyval.exprval) = HANDLE_ARITH_OP(add, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1470 "parser.c"
    break;

  case 19: /* expr: expr MINUS expr  */
#line 102 "parser.y"
                                    {(yyval.exprval) = HANDLE_ARITH_OP(sub, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1476 "parser.c"
    break;

  case 20: /* expr: expr MUL expr  */
#line 103 "parser.y"
                                    {(yyval.exprval) = HANDLE_ARITH_OP(mul, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1482 "parser.c"
    break;

  case 21: /* expr: expr DIV expr  */
#line 104 "parser.y"
                                    {(yyval.exprval) = HANDLE_ARITH_OP(mydiv, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1488 "parser.c"
    break;

  case 22: /* expr: expr MOD expr  */
#line 105 "parser.y"
                                    {(yyval.exprval) = HANDLE_ARITH_OP(mod, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1494 "parser.c"
    break;

  case 23: /* expr: expr GT expr  */
#line 106 "parser.y"
                                    {(yyval.exprval) = HANDLE_REL_OP(if_greater, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1500 "parser.c"
    break;

  case 24: /* expr: expr GET expr  */
#line 107 "parser.y"
                                    {(yyval.exprval) = HANDLE_REL_OP(if_geatereq, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1506 "parser.c"
    break;

  case 25: /* expr: expr LT expr  */
#line 108 "parser.y"
                                    {(yyval.exprval) = HANDLE_REL_OP(if_less, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1512 "parser.c"
    break;

  case 26: /* expr: expr LET expr  */
#line 109 "parser.y"
                                    {(yyval.exprval) = HANDLE_REL_OP(if_lesseq, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1518 "parser.c"
    break;

  case 27: /* expr: expr EQUAL expr  */
#line 110 "parser.y"
                                    {makeBoolStmt((yyvsp[-2].exprval)); makeBoolStmt((yyvsp[0].exprval)); (yyval.exprval) = HANDLE_REL_OP(if_eq, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1524 "parser.c"
    break;

  case 28: /* expr: expr NEQUAL expr  */
#line 111 "parser.y"
                                    {makeBoolStmt((yyvsp[-2].exprval)); makeBoolStmt((yyvsp[0].exprval)); (yyval.exprval) = HANDLE_REL_OP(if_noteq, (yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1530 "parser.c"
    break;

  case 29: /* expr: expr AND M expr  */
#line 112 "parser.y"
                                    {(yyval.exprval) = HANDLE_BOOL_OP(and, (yyvsp[-3].exprval), (yyvsp[0].exprval), (yyvsp[-1].labelval));}
#line 1536 "parser.c"
    break;

  case 30: /* expr: expr OR M expr  */
#line 113 "parser.y"
                                    {(yyval.exprval) = HANDLE_BOOL_OP(or, (yyvsp[-3].exprval), (yyvsp[0].exprval), (yyvsp[-1].labelval));}
#line 1542 "parser.c"
    break;

  case 31: /* expr: term  */
#line 114 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1548 "parser.c"
    break;

  case 32: /* term: PAR_OPEN expr PAR_CLOSED  */
#line 117 "parser.y"
                                          {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1554 "parser.c"
    break;

  case 33: /* term: MINUS expr  */
#line 118 "parser.y"
                                          {(yyval.exprval) = HANDLE_TERM_TO_UMINUS_EXPR((yyvsp[0].exprval));}
#line 1560 "parser.c"
    break;

  case 34: /* term: NOT expr  */
#line 119 "parser.y"
                                          {(yyval.exprval) = HANDLE_TERM_TO_NOT_EXPR((yyvsp[0].exprval));}
#line 1566 "parser.c"
    break;

  case 35: /* term: INC lvalue  */
#line 120 "parser.y"
                                                {(yyval.exprval) = HANDLE_TERM_TO_INC_LVALUE((yyvsp[0].exprval), yylineno);}
#line 1572 "parser.c"
    break;

  case 36: /* term: lvalue INC  */
#line 121 "parser.y"
                                                {(yyval.exprval) = HANDLE_TERM_TO_LVALUE_INC((yyvsp[-1].exprval), yylineno);}
#line 1578 "parser.c"
    break;

  case 37: /* term: DEC lvalue  */
#line 122 "parser.y"
                                                {(yyval.exprval) = HANDLE_TERM_TO_DEC_LVALUE((yyvsp[0].exprval), yylineno);}
#line 1584 "parser.c"
    break;

  case 38: /* term: lvalue DEC  */
#line 123 "parser.y"
                                                {(yyval.exprval) = HANDLE_TERM_TO_LVALUE_DEC((yyvsp[-1].exprval), yylineno);}
#line 1590 "parser.c"
    break;

  case 39: /* term: prim  */
#line 124 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1596 "parser.c"
    break;

  case 40: /* assignexpr: lvalue ASSIGN expr  */
#line 127 "parser.y"
                                          {makeBoolStmt((yyvsp[0].exprval)); (yyval.exprval) = HANDLE_ASSIGNEXPR_TO_LVALUE_ASSIGN_EXPRESSION((yyvsp[-2].exprval), (yyvsp[0].exprval), yylineno);}
#line 1602 "parser.c"
    break;

  case 41: /* prim: lvalue  */
#line 129 "parser.y"
                                                {(yyval.exprval) = HANDLE_PRIM_TO_LVALUE((yyvsp[0].exprval), yylineno);}
#line 1608 "parser.c"
    break;

  case 42: /* prim: call  */
#line 130 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1614 "parser.c"
    break;

  case 43: /* prim: objectdef  */
#line 131 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1620 "parser.c"
    break;

  case 44: /* prim: PAR_OPEN funcdef PAR_CLOSED  */
#line 132 "parser.y"
                                                {(yyval.exprval) = HANDLE_PRIM_TO_FUNCDEF((yyvsp[-1].symval));}
#line 1626 "parser.c"
    break;

  case 45: /* prim: const  */
#line 133 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1632 "parser.c"
    break;

  case 46: /* lvalue: IDENT  */
#line 136 "parser.y"
                                        {(yyval.exprval) = HANDLE_LVALUE_TO_IDENT((yyvsp[0].sval), yylineno);}
#line 1638 "parser.c"
    break;

  case 47: /* lvalue: LOCAL IDENT  */
#line 137 "parser.y"
                                        {(yyval.exprval) = HANDLE_LVALUE_TO_LOCAL_IDENT((yyvsp[0].sval), yylineno);}
#line 1644 "parser.c"
    break;

  case 48: /* lvalue: DOUBLE_COLON IDENT  */
#line 138 "parser.y"
                                        {(yyval.exprval) = HANDLE_LVALUE_TO_GLOBAL_IDENT((yyvsp[0].sval), yylineno);}
#line 1650 "parser.c"
    break;

  case 49: /* lvalue: member  */
#line 139 "parser.y"
                                        {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1656 "parser.c"
    break;

  case 50: /* member: lvalue DOT IDENT  */
#line 142 "parser.y"
                                                                {(yyval.exprval) = HANDLE_MEMBER_TO_LVALUE_DOT_IDENT((yyvsp[-2].exprval), (yyvsp[0].sval));}
#line 1662 "parser.c"
    break;

  case 51: /* member: lvalue SQUARE_OPEN expr SQUARE_CLOSED  */
#line 143 "parser.y"
                                                          {(yyval.exprval) = HANDLE_MEMBER_TO_LVALUE_SQUARE_EXPR((yyvsp[-3].exprval), (yyvsp[-1].exprval));}
#line 1668 "parser.c"
    break;

  case 52: /* member: call DOT IDENT  */
#line 144 "parser.y"
                                                                {(yyval.exprval) = HANDLE_MEMBER_TO_LVALUE_DOT_IDENT((yyvsp[-2].exprval), (yyvsp[0].sval));}
#line 1674 "parser.c"
    break;

  case 53: /* member: call SQUARE_OPEN expr SQUARE_CLOSED  */
#line 145 "parser.y"
                                                          {(yyval.exprval) = HANDLE_MEMBER_TO_LVALUE_SQUARE_EXPR((yyvsp[-3].exprval), (yyvsp[-1].exprval));}
#line 1680 "parser.c"
    break;

  case 54: /* call: call PAR_OPEN elist PAR_CLOSED  */
#line 148 "parser.y"
                                                                            {(yyval.exprval) = HANDLE_CALL_ELIST((yyvsp[-3].exprval), (yyvsp[-1].exprval));}
#line 1686 "parser.c"
    break;

  case 55: /* call: lvalue callsuffix  */
#line 149 "parser.y"
                                                                            {(yyval.exprval) = HANDLE_CALL_LVALUE_SUFFIX((yyvsp[-1].exprval), (yyvsp[0].callval));}
#line 1692 "parser.c"
    break;

  case 56: /* call: PAR_OPEN funcdef PAR_CLOSED PAR_OPEN elist PAR_CLOSED  */
#line 150 "parser.y"
                                                                            {(yyval.exprval) = HANDLE_CALL_FUNCDEF_ELIST((yyvsp[-4].symval), (yyvsp[-1].exprval));}
#line 1698 "parser.c"
    break;

  case 57: /* callsuffix: normcall  */
#line 153 "parser.y"
                                {(yyval.callval) = (yyvsp[0].callval);}
#line 1704 "parser.c"
    break;

  case 58: /* callsuffix: methodcall  */
#line 154 "parser.y"
                                {(yyval.callval) = (yyvsp[0].callval);}
#line 1710 "parser.c"
    break;

  case 59: /* normcall: PAR_OPEN elist PAR_CLOSED  */
#line 157 "parser.y"
                                                               {(yyval.callval) = HANDLE_NORMCALL((yyvsp[-1].exprval));}
#line 1716 "parser.c"
    break;

  case 60: /* methodcall: DOUBLE_DOT IDENT PAR_OPEN elist PAR_CLOSED  */
#line 159 "parser.y"
                                                               {(yyval.callval) = HANDLE_METHODCALL((yyvsp[-3].sval), (yyvsp[-1].exprval));}
#line 1722 "parser.c"
    break;

  case 61: /* elist: expr  */
#line 161 "parser.y"
                                      {makeBoolStmt((yyvsp[0].exprval)); (yyval.exprval) = (yyvsp[0].exprval); (yyval.exprval)->next = NULL;}
#line 1728 "parser.c"
    break;

  case 62: /* elist: expr COMMA elist  */
#line 162 "parser.y"
                                      {(yyval.exprval) = HANDLE_ELIST_ADD((yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1734 "parser.c"
    break;

  case 63: /* elist: %empty  */
#line 163 "parser.y"
                                                            {(yyval.exprval) = (Expr*) 0;}
#line 1740 "parser.c"
    break;

  case 64: /* objectdef: SQUARE_OPEN SQUARE_CLOSED  */
#line 168 "parser.y"
        { (yyval.exprval) = HANDLE_OBJECTDEF_TO_ELIST(NULL); }
#line 1746 "parser.c"
    break;

  case 65: /* objectdef: SQUARE_OPEN elist SQUARE_CLOSED  */
#line 171 "parser.y"
        { (yyval.exprval) = HANDLE_OBJECTDEF_TO_ELIST((yyvsp[-1].exprval)); }
#line 1752 "parser.c"
    break;

  case 66: /* objectdef: SQUARE_OPEN indexed SQUARE_CLOSED  */
#line 174 "parser.y"
        { (yyval.exprval) = HANDLE_OBJECTDEF_TO_INDEXED((yyvsp[-1].exprval)); }
#line 1758 "parser.c"
    break;

  case 67: /* indexed: indexedelem  */
#line 177 "parser.y"
                                                {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1764 "parser.c"
    break;

  case 68: /* indexed: indexedelem COMMA indexed  */
#line 178 "parser.y"
                                                {(yyval.exprval) = HANDLE_INDEXED_ADD((yyvsp[-2].exprval), (yyvsp[0].exprval));}
#line 1770 "parser.c"
    break;

  case 69: /* indexedelem: BRACKET_OPEN expr COLON expr BRACKET_CLOSED  */
#line 181 "parser.y"
                                                            {makeBoolStmt((yyvsp[-1].exprval)); (yyval.exprval) = HANDLE_INDEXELEM((yyvsp[-3].exprval), (yyvsp[-1].exprval));}
#line 1776 "parser.c"
    break;

  case 70: /* $@1: %empty  */
#line 183 "parser.y"
                             {scope++; current_table = SymTable_next(current_table);}
#line 1782 "parser.c"
    break;

  case 71: /* block: BRACKET_OPEN $@1 stmts BRACKET_CLOSED  */
#line 183 "parser.y"
                                                                                                           {scope--; SymTable_hide(current_table); current_table = SymTable_prev(current_table); (yyval.stmtval) = (yyvsp[-1].stmtval);}
#line 1788 "parser.c"
    break;

  case 72: /* $@2: %empty  */
#line 186 "parser.y"
                                {
					funcCounter++;
					loopCounterStack = stack_push(loopCounterStack, loopCounter);
					loopCounter = 0;
				}
#line 1798 "parser.c"
    break;

  case 73: /* funcdef: funcprefix $@2 funcargs funcbody  */
#line 193 "parser.y"
                                {
					(yyval.symval) = HANDLE_FUNCDEF((yyvsp[-3].symval), (yyvsp[0].func_addr), yylineno);
					funcCounter--;
					loopCounter = stack_top(loopCounterStack);
					loopCounterStack = stack_pop(loopCounterStack);
				}
#line 1809 "parser.c"
    break;

  case 74: /* funcbody: block  */
#line 200 "parser.y"
                      {
                    (yyval.func_addr) = currScopeOffset();
                    exitScopeSpace();
                }
#line 1818 "parser.c"
    break;

  case 75: /* funcprefix: FUNCTION funcname  */
#line 205 "parser.y"
                                  {(yyval.symval) = HANDLE_FUNCPREFIX((yyvsp[0].sval), yylineno);}
#line 1824 "parser.c"
    break;

  case 76: /* $@3: %empty  */
#line 208 "parser.y"
                {
                    scope++; 
                    current_table = SymTable_next(current_table);
                }
#line 1833 "parser.c"
    break;

  case 77: /* $@4: %empty  */
#line 213 "parser.y"
                {
                    scope--;
                    current_table = SymTable_prev(current_table); 
                    functionScopeStack = stack_push(functionScopeStack, scope);
                }
#line 1843 "parser.c"
    break;

  case 78: /* funcargs: PAR_OPEN $@3 idlist $@4 PAR_CLOSED  */
#line 219 "parser.y"
                {
                    enterScopeSpace();
                    resetFunctionLocalOffset();
                }
#line 1852 "parser.c"
    break;

  case 79: /* funcname: IDENT  */
#line 224 "parser.y"
                               {(yyval.sval) = HANDLE_FUNCTION_WITH_NAME((yyvsp[0].sval), yylineno);}
#line 1858 "parser.c"
    break;

  case 80: /* funcname: %empty  */
#line 225 "parser.y"
                               {(yyval.sval) = HANDLE_FUNCTION_WITHOUT_NAME(yylineno);}
#line 1864 "parser.c"
    break;

  case 81: /* const: NUM  */
#line 228 "parser.y"
                            {(yyval.exprval) = newExprConstNum((yyvsp[0].nval));}
#line 1870 "parser.c"
    break;

  case 82: /* const: STRING  */
#line 229 "parser.y"
                            {(yyval.exprval) = newExprConstString((yyvsp[0].sval));}
#line 1876 "parser.c"
    break;

  case 83: /* const: NIL  */
#line 230 "parser.y"
                            {(yyval.exprval) = newExpr(nil_e);}
#line 1882 "parser.c"
    break;

  case 84: /* const: TRUE  */
#line 231 "parser.y"
                            {(yyval.exprval) = newExprConstBool(1);}
#line 1888 "parser.c"
    break;

  case 85: /* const: FALSE  */
#line 232 "parser.y"
                            {(yyval.exprval) = newExprConstBool(0);}
#line 1894 "parser.c"
    break;

  case 86: /* idlist: IDENT  */
#line 235 "parser.y"
                                        {HANDLE_IDLIST_IDENT((yyvsp[0].sval), yylineno);}
#line 1900 "parser.c"
    break;

  case 87: /* idlist: IDENT COMMA idlist  */
#line 236 "parser.y"
                                        {HANDLE_IDLIST_IDENT((yyvsp[-2].sval), yylineno);}
#line 1906 "parser.c"
    break;

  case 89: /* ifprefix: IF PAR_OPEN expr PAR_CLOSED  */
#line 240 "parser.y"
                                              {makeBoolStmt((yyvsp[-1].exprval)); (yyval.labelval) = HANDLE_IFPREFIX((yyvsp[-1].exprval));}
#line 1912 "parser.c"
    break;

  case 90: /* elseprefix: ELSE  */
#line 242 "parser.y"
                                                    {(yyval.labelval) = HANDLE_ELSEPREFIX(yylineno);}
#line 1918 "parser.c"
    break;

  case 91: /* ifstmt: ifprefix stmt  */
#line 244 "parser.y"
                              {patchLabel((yyvsp[-1].labelval), nextQuadLabel()); (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1924 "parser.c"
    break;

  case 92: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 245 "parser.y"
                                                {
                    patchLabel((yyvsp[-3].labelval), (yyvsp[-1].labelval) + 1);
                    patchLabel((yyvsp[-1].labelval), nextQuadLabel());
                    (yyval.stmtval) = (yyvsp[-2].stmtval);
                    if(!(yyval.stmtval)) (yyval.stmtval) = (yyvsp[0].stmtval);
                }
#line 1935 "parser.c"
    break;

  case 93: /* whileprefix: WHILE  */
#line 253 "parser.y"
                                                    {(yyval.labelval) = nextQuadLabel(); loopCounter++;}
#line 1941 "parser.c"
    break;

  case 94: /* whileargs: PAR_OPEN expr PAR_CLOSED  */
#line 255 "parser.y"
                                              {makeBoolStmt((yyvsp[-1].exprval)); (yyval.labelval) = HANDLE_WHILEARGS((yyvsp[-1].exprval));}
#line 1947 "parser.c"
    break;

  case 95: /* whilestmt: whileprefix whileargs stmt  */
#line 257 "parser.y"
                                                        {HANDLE_WHILE((yyvsp[-2].labelval), (yyvsp[-1].labelval), (yyvsp[0].stmtval)); loopCounter--;}
#line 1953 "parser.c"
    break;

  case 96: /* N: %empty  */
#line 259 "parser.y"
                {(yyval.labelval) = nextQuadLabel(); emit(jump, NULL, NULL, NULL, 0, yylineno);}
#line 1959 "parser.c"
    break;

  case 97: /* M: %empty  */
#line 260 "parser.y"
                {(yyval.labelval) = nextQuadLabel();}
#line 1965 "parser.c"
    break;

  case 98: /* $@5: %empty  */
#line 262 "parser.y"
                    {loopCounter++;}
#line 1971 "parser.c"
    break;

  case 99: /* forprefix: FOR $@5 PAR_OPEN elist SEMI_COLON M expr SEMI_COLON  */
#line 262 "parser.y"
                                                                                 {makeBoolStmt((yyvsp[-1].exprval)); (yyval.forprefixval) = HANDLE_FORPREFIX((yyvsp[-2].labelval), (yyvsp[-1].exprval));}
#line 1977 "parser.c"
    break;

  case 100: /* forstmt: forprefix N elist PAR_CLOSED N stmt N  */
#line 264 "parser.y"
                                                      {HANDLE_FORSTMT((yyvsp[-6].forprefixval), (yyvsp[-5].labelval), (yyvsp[-2].labelval), (yyvsp[0].labelval), (yyvsp[-1].stmtval)); loopCounter--;}
#line 1983 "parser.c"
    break;

  case 101: /* returnstmt: RETURN SEMI_COLON  */
#line 266 "parser.y"
                                                        {
                                                    if(funcCounter == 0) {
                                                        fprintf(stderr, "Line %d: Return used outside function", yylineno);
                                                        exit(1);
                                                    }
                                                    emit(ret, NULL, NULL, NULL, 0, yylineno);
                                                }
#line 1995 "parser.c"
    break;

  case 102: /* returnstmt: RETURN expr SEMI_COLON  */
#line 273 "parser.y"
                                          {
                                                    makeBoolStmt((yyvsp[-1].exprval));
                                                    if(funcCounter == 0) {
                                                        fprintf(stderr, "Line %d: Return used outside function", yylineno);
                                                        exit(1);
                                                    }
                                                    emit(ret, NULL, NULL, (yyvsp[-1].exprval), 0, yylineno);
                                                }
#line 2008 "parser.c"
    break;

  case 103: /* break: BREAK SEMI_COLON  */
#line 283 "parser.y"
                                         { 
                        if(loopCounter > 0) (yyval.stmtval) = HANDLE_BREAK(); 
                        else {
                            fprintf(stderr, "Line %d: Break outside loop\n", yylineno);
                            exit(1);
                        }
                    }
#line 2020 "parser.c"
    break;

  case 104: /* continue: CONTINUE SEMI_COLON  */
#line 291 "parser.y"
                                            {
                        if(loopCounter > 0) (yyval.stmtval) = HANDLE_CONTINUE(); 
                        else {
                            fprintf(stderr, "Line %d: Continue outside loop\n", yylineno);
                            exit(1);
                        }
                }
#line 2032 "parser.c"
    break;


#line 2036 "parser.c"

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

#line 299 "parser.y"


int yyerror(char *message){
    printf("Error on line %d: %s\n", yylineno, message);
    return -1;
}

int main(int argc, char **argv) {
    head = SymTable_new();
    current_table = head;

    // Reserve space for temporary variables (0-99)
    programVarOffset = 100;  // Start regular globals at offset 100

    // Add library functions
    libFunc(head, "print");
    libFunc(head, "input");
    libFunc(head, "objectmemberkeys");
    libFunc(head, "objecttotalmembers");
    libFunc(head, "objectcopy");
    libFunc(head, "totalarguments");
    libFunc(head, "argument");
    libFunc(head, "typeof");
    libFunc(head, "strtonum");
    libFunc(head, "sqrt");
    libFunc(head, "cos");
    libFunc(head, "sin");


    // Check for correct number of arguments
	if(argc > 3) {
		fprintf(stderr, "Invalid argument format\n");
		exit(0);
	}

    // Open input file
    if(argc == 1) {
		yyin = stdin;
    }
	else {
		if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr, "Error opening input file %s\n", argv[1]);
            exit(0);
        }
	}

    // Open output file
	if(argc == 3 && !freopen(argv[2], "w", stdout)) {
		fprintf(stderr, "Error opening output file \n");
		exit(0);
	}
	printf("DEBUG: Starting yyparse\n");
    yyparse();
    printf("DEBUG: yyparse completed, calling printQuads\n");
    printQuads();
    printf("DEBUG: printQuads completed, calling generate\n");
    generate();
    printf("DEBUG: generate completed\n");
    print_target_code();
    print_binary_file("binary.abc");
    return 0;
}
