
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "y.tab.h"
#define TAM_PILA 100
#define TODO_OK 1
#define ERROR 0
#define EXISTE 1
#define NO_EXISTE 0
#define PILA_IF 0
#define PILA_DECLARACION 1
#define PILA_WHILE 2
#define PILA_ASIGNACION 3
#define PILA_REPEAT 4
#define PILA_BETWEEN 5
#define TRUE 1
#define FALSE 0

//DECLARACION FUNCIONES

int yyerror();
int yylex();
int yyparse();

void finAnormal(char *, char * );
void validarDeclaracionTipoDato(char *);
int insertarEnListaAsig(char *);
void debugListaAsignacion();
int insertarEnListaDeclaracion(char *);
int verificarExistencia(char* );
char * valorComparacionCICLO(char * ); // utilizado en repeat
// TABLA DE SIMBOLOS

struct struct_tablaSimbolos
{
	char nombre[100];
	char tipo[100];
	char valor[50];
	char longitud[100];
};

int puntero_ts = 0;
struct struct_tablaSimbolos tablaSimbolos[10000];
////////////////////////////
int insertar_TS(char*, char*);
char * recuperarTipoTS(char* );
int crearArchivoTS();
void debugTS();
char * recuperarValorTS(char* );

int crearArchivoIntermedia();
char * aux;
char valorFactor[5],valorTermino[5],valorElemento[5];
double sumTermino = 0;
double sumElemento = 0;

int cont = 0;
int iPosCondDos;
int insertarEnLista(char*);
void escribirEnLista(int, char*);
char * valorComparacion(char * );
char comparador_usado[2];


// PILAS 
char * pilaIF[TAM_PILA];			// pila 0
char * pilaWhile[TAM_PILA];			// pila 1
char * pilaAsignacion[TAM_PILA];	// pila 3
char * pilaRepeat[TAM_PILA];		// pila 4
char * pilaBetween[TAM_PILA];		// pila 5
int tope_pila_if=0;				// pila 0
int tope_pila_while=0;			// pila 1
int tope_pila_asignacion=0;		// pila 3
int tope_pila_repeat=0;			// pila 4
int tope_pila_between=0;			// pila 5

////////////////////
void apilar(int nroPila, char * val);
int desapilar(int nroPila);
int pilaVacia(int tope);
int pilaLlena(int tope);
void debugPila(int nroPila, int tope);

// LISTAS

char * listaDeclaracion[100];	// lista para declaraciones
char * listaTokens[10000];		// lista de tokens para gci polaca inversa
char * listaAux[100];		// lista de tokens para gci polaca inversa
char * listaAsignacion[30];	// lista para acumular la asignacion multiple
int puntero_declaracion = 0;
int puntero_asignacion = 0;
int puntero_tokens=1; // arranca en uno para comparar en notepad++
int puntero_aux=0;
// DECLARACION DE VARIABLES - FUNCIONES
void debugListaDeclaracion();
int flagWHILE = FALSE;
int flagIFOR = FALSE;
int flagIFAND = FALSE;
int flagWHILEOR = FALSE;
int flagWHILEAND = FALSE;
int flagELSE = FALSE;
int flagPrimero = FALSE;		// para identificar los token en asign multiple
int flagREPEAT = FALSE;
int flagAsigMul = FALSE;
//DECLARACION VARIABLES
char posAuxA[5], posAuxB[5];	// posicion auxiliar para pivotear con la condicion OR
char posTrue[5], posFalse[5],posCondDos[5];
char inicioCuerpoRepeat[5];
char * auxTipoAsignacion;
char * inicioWhilePos;
//int posTrue, posFalse, posCondDos;
int pos_actual=0;
int yystopparser=0;

FILE *yyin;
FILE *fIntermedia; //ARCHIVO CON INTERMEDIA




/* Line 189 of yacc.c  */
#line 196 "y.tab.c"

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
     ID = 258,
     CONST_INT = 259,
     CONST_STR = 260,
     CONST_REAL = 261,
     PROGRAM = 262,
     DECVAR = 263,
     ENDDEC = 264,
     DEFVAR = 265,
     ENDDEF = 266,
     REAL = 267,
     INTEGER = 268,
     STRING = 269,
     BEGINP = 270,
     ENDP = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     ENDIF = 275,
     FOR = 276,
     TO = 277,
     DO = 278,
     ENDFOR = 279,
     WHILE = 280,
     ENDW = 281,
     REPEAT = 282,
     UNTIL = 283,
     OP_AND = 284,
     OP_OR = 285,
     OP_NOT = 286,
     OP_COMPARACION = 287,
     OP_ASIG = 288,
     OP_DOSP = 289,
     OP_SUM = 290,
     OP_RES = 291,
     OP_MUL = 292,
     OP_DIV = 293,
     CAR_COMA = 294,
     CAR_PUNTO = 295,
     CAR_PYC = 296,
     CAR_PA = 297,
     CAR_PC = 298,
     CAR_CA = 299,
     CAR_CC = 300,
     LONG = 301,
     BETWEEN = 302,
     IN = 303,
     WRITE = 304,
     READ = 305
   };
#endif
/* Tokens.  */
#define ID 258
#define CONST_INT 259
#define CONST_STR 260
#define CONST_REAL 261
#define PROGRAM 262
#define DECVAR 263
#define ENDDEC 264
#define DEFVAR 265
#define ENDDEF 266
#define REAL 267
#define INTEGER 268
#define STRING 269
#define BEGINP 270
#define ENDP 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define FOR 276
#define TO 277
#define DO 278
#define ENDFOR 279
#define WHILE 280
#define ENDW 281
#define REPEAT 282
#define UNTIL 283
#define OP_AND 284
#define OP_OR 285
#define OP_NOT 286
#define OP_COMPARACION 287
#define OP_ASIG 288
#define OP_DOSP 289
#define OP_SUM 290
#define OP_RES 291
#define OP_MUL 292
#define OP_DIV 293
#define CAR_COMA 294
#define CAR_PUNTO 295
#define CAR_PYC 296
#define CAR_PA 297
#define CAR_PC 298
#define CAR_CA 299
#define CAR_CC 300
#define LONG 301
#define BETWEEN 302
#define IN 303
#define WRITE 304
#define READ 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 123 "Sintactico.y"

	char * int_val;
	char * real_val;
	char * str_val;
	char * cmp_val;



/* Line 214 of yacc.c  */
#line 341 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 353 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     9,    10,    15,    16,    21,    23,
      26,    30,    34,    38,    40,    44,    45,    50,    53,    55,
      57,    59,    61,    63,    65,    66,    72,    73,    81,    83,
      87,    91,    95,    97,    98,   102,   103,   107,   108,   112,
     113,   122,   123,   134,   136,   138,   140,   143,   144,   149,
     150,   155,   162,   169,   171,   174,   176,   178,   179,   184,
     188,   192,   194,   195,   196,   197,   198,   213,   217,   221,
     223,   225,   227,   229,   231
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,     7,    53,    54,    60,    -1,    -1,
       8,    55,    57,     9,    -1,    -1,    10,    56,    57,    11,
      -1,    58,    -1,    57,    58,    -1,    59,    34,    12,    -1,
      59,    34,    14,    -1,    59,    34,    13,    -1,     3,    -1,
      59,    39,     3,    -1,    -1,    15,    61,    62,    16,    -1,
      62,    63,    -1,    63,    -1,    64,    -1,    74,    -1,    68,
      -1,    70,    -1,    87,    -1,    -1,    27,    65,    62,    28,
      79,    -1,    -1,    25,    66,    42,    79,    43,    62,    67,
      -1,    26,    -1,    69,    33,    86,    -1,    69,    33,    87,
      -1,    69,    33,     3,    -1,     3,    -1,    -1,    50,    71,
       3,    -1,    -1,    49,    72,     3,    -1,    -1,    49,    73,
       5,    -1,    -1,    17,    42,    79,    43,    77,    62,    75,
      20,    -1,    -1,    17,    42,    79,    43,    77,    62,    76,
      78,    62,    20,    -1,    18,    -1,    19,    -1,    84,    -1,
      31,    84,    -1,    -1,    84,    82,    80,    84,    -1,    -1,
      84,    83,    81,    84,    -1,    31,    42,    84,    29,    84,
      43,    -1,    31,    42,    84,    30,    84,    43,    -1,    87,
      -1,    31,    87,    -1,    29,    -1,    30,    -1,    -1,    86,
      32,    85,    86,    -1,    86,    35,    92,    -1,    86,    36,
      92,    -1,    92,    -1,    -1,    -1,    -1,    -1,    88,    47,
      42,     3,    89,    39,    44,    86,    90,    41,    86,    91,
      45,    43,    -1,    92,    37,    93,    -1,    92,    38,    93,
      -1,    93,    -1,     3,    -1,     4,    -1,     6,    -1,     5,
      -1,    42,    86,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   175,   180,   180,   184,   184,   188,   189,
     193,   194,   195,   199,   200,   204,   204,   208,   209,   213,
     214,   215,   216,   217,   222,   221,   245,   244,   255,   306,
     334,   339,   374,   397,   397,   398,   398,   399,   399,   403,
     403,   458,   458,   516,   535,   539,   581,   582,   582,   603,
     603,   624,   625,   626,   627,   630,   667,   705,   705,   709,
     710,   711,   715,   715,   721,   742,   715,   794,   800,   806,
     816,   826,   834,   845,   854
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST_INT", "CONST_STR",
  "CONST_REAL", "PROGRAM", "DECVAR", "ENDDEC", "DEFVAR", "ENDDEF", "REAL",
  "INTEGER", "STRING", "BEGINP", "ENDP", "IF", "THEN", "ELSE", "ENDIF",
  "FOR", "TO", "DO", "ENDFOR", "WHILE", "ENDW", "REPEAT", "UNTIL",
  "OP_AND", "OP_OR", "OP_NOT", "OP_COMPARACION", "OP_ASIG", "OP_DOSP",
  "OP_SUM", "OP_RES", "OP_MUL", "OP_DIV", "CAR_COMA", "CAR_PUNTO",
  "CAR_PYC", "CAR_PA", "CAR_PC", "CAR_CA", "CAR_CC", "LONG", "BETWEEN",
  "IN", "WRITE", "READ", "$accept", "programa", "$@1", "est_declaracion",
  "$@2", "$@3", "declaraciones", "declaracion", "lista_var", "algoritmo",
  "$@4", "bloque", "sentencia", "ciclo", "$@5", "$@6", "endw_",
  "asignacion", "lista_id", "entrada_salida", "$@7", "$@8", "$@9",
  "seleccion", "$@10", "$@11", "then_", "else_", "condicion", "$@12",
  "$@13", "op_and_", "op_or_", "comparacion", "$@14", "expresion",
  "between", "$@15", "$@16", "$@17", "$@18", "termino", "factor", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    55,    54,    56,    54,    57,    57,
      58,    58,    58,    59,    59,    61,    60,    62,    62,    63,
      63,    63,    63,    63,    65,    64,    66,    64,    67,    68,
      68,    69,    69,    71,    70,    72,    70,    73,    70,    75,
      74,    76,    74,    77,    78,    79,    79,    80,    79,    81,
      79,    79,    79,    79,    79,    82,    83,    85,    84,    86,
      86,    86,    88,    89,    90,    91,    87,    92,    92,    92,
      93,    93,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     0,     4,     0,     4,     1,     2,
       3,     3,     3,     1,     3,     0,     4,     2,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     7,     1,     3,
       3,     3,     1,     0,     3,     0,     3,     0,     3,     0,
       8,     0,    10,     1,     1,     1,     2,     0,     4,     0,
       4,     6,     6,     1,     2,     1,     1,     0,     4,     3,
       3,     1,     0,     0,     0,     0,    14,     3,     3,     1,
       1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     4,     6,     0,     0,     0,
      15,     3,    13,     0,     8,     0,     0,    62,     5,     9,
       0,     0,     7,    32,     0,    26,    24,    35,    33,    62,
      18,    19,    21,     0,    22,    20,    23,     0,    10,    12,
      11,    14,    62,     0,    62,     0,     0,     0,    16,    17,
      62,     0,    70,    71,    73,    72,    62,     0,     0,    45,
       0,    53,    61,    69,    62,    62,    36,    38,    34,    70,
      29,    30,     0,     0,    46,    54,     0,     0,    55,    56,
      47,    49,    57,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    74,    43,    62,     0,     0,     0,    59,    60,
      67,    68,    62,    25,     0,     0,     0,    39,    48,    50,
      58,    62,     0,     0,     0,     0,     0,    28,    27,     0,
      51,    52,    40,    44,    62,    64,    62,     0,    42,     0,
      65,     0,     0,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    13,    14,    15,    11,
      17,    29,    30,    31,    44,    43,   118,    32,    33,    34,
      47,    45,    46,    35,   115,   116,    94,   124,    58,    95,
      96,    80,    81,    59,    97,    60,    36,    37,   104,   127,
     131,    62,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int8 yypact[] =
{
      23,   -62,    10,     9,   -62,   -62,   -62,    17,    35,    35,
     -62,   -62,   -62,     4,   -62,   -14,     3,    76,   -62,   -62,
     110,    42,   -62,   -62,    15,   -62,   -62,    55,   -62,     6,
     -62,   -62,   -62,    14,   -62,   -62,   -62,    18,   -62,   -62,
     -62,   -62,    64,    29,    76,    70,    84,    91,   -62,   -62,
     111,    58,   -62,   -62,   -62,   -62,   115,   124,    59,     5,
      72,   -62,    38,   -62,    64,    12,   -62,   -62,   -62,    65,
      97,   -62,   102,   124,   -62,   -62,    56,    93,   -62,   -62,
     -62,   -62,   -62,   124,   124,   124,   124,    98,    64,   -62,
     107,    99,   -62,   -62,    76,   124,   124,   124,    38,    38,
     -62,   -62,    76,   -62,   101,   124,   124,    -1,   -62,   -62,
      97,    60,   100,   103,   104,   123,   126,   -62,   -62,   124,
     -62,   -62,   -62,   -62,    76,    97,    63,   108,   -62,   124,
      97,   105,   109,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -62,   -62,   139,    -5,   -62,   -62,
     -62,   -43,   -29,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -61,   -62,
     -62,   -62,   -62,   -52,   -62,   -45,     8,   -62,   -62,   -62,
     -62,   -42,    53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
      49,    65,    23,    87,    74,    70,    12,    12,    19,    23,
       4,    19,    76,    18,    22,    23,    24,     5,   -41,     6,
      20,    90,    48,    24,    25,    21,    26,   103,    91,    24,
       1,    25,    10,    26,    78,    79,    49,    25,    12,    26,
      88,    98,    99,   108,   109,    41,   -62,    50,    27,    28,
      61,   107,   110,   113,   114,    27,    28,    42,    71,   111,
     -37,    27,    28,    23,    75,    51,    23,    52,    53,    54,
      55,    64,    61,    66,   125,    85,    86,    24,    49,    23,
      24,   126,    49,   128,   130,    25,   117,    26,    25,    67,
      26,    83,    84,    24,    68,    56,    61,    49,   -31,    92,
      72,    25,    77,    26,    82,    89,    57,    83,    84,    27,
      28,    93,    27,    28,    69,    53,    54,    55,    52,    53,
      54,    55,    38,    39,    40,    27,    28,    52,    53,    54,
      55,    82,    83,    84,    83,    84,   105,   106,   100,   101,
     112,   102,    92,   122,   119,   123,   120,   121,    16,   129,
     132,     0,   133,    57,     0,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      29,    44,     3,    64,    56,    50,     3,     3,    13,     3,
       0,    16,    57,     9,    11,     3,    17,     8,    19,    10,
      34,    73,    16,    17,    25,    39,    27,    88,    73,    17,
       7,    25,    15,    27,    29,    30,    65,    25,     3,    27,
      28,    83,    84,    95,    96,     3,    47,    33,    49,    50,
      42,    94,    97,   105,   106,    49,    50,    42,    50,   102,
       5,    49,    50,     3,    56,    47,     3,     3,     4,     5,
       6,    42,    64,     3,   119,    37,    38,    17,   107,     3,
      17,   124,   111,    20,   129,    25,    26,    27,    25,     5,
      27,    35,    36,    17,     3,    31,    88,   126,    33,    43,
      42,    25,    43,    27,    32,     3,    42,    35,    36,    49,
      50,    18,    49,    50,     3,     4,     5,     6,     3,     4,
       5,     6,    12,    13,    14,    49,    50,     3,     4,     5,
       6,    32,    35,    36,    35,    36,    29,    30,    85,    86,
      39,    43,    43,    20,    44,    19,    43,    43,     9,    41,
      45,    -1,    43,    42,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    52,    53,     0,     8,    10,    54,    55,    56,
      15,    60,     3,    57,    58,    59,    57,    61,     9,    58,
      34,    39,    11,     3,    17,    25,    27,    49,    50,    62,
      63,    64,    68,    69,    70,    74,    87,    88,    12,    13,
      14,     3,    42,    66,    65,    72,    73,    71,    16,    63,
      33,    47,     3,     4,     5,     6,    31,    42,    79,    84,
      86,    87,    92,    93,    42,    62,     3,     5,     3,     3,
      86,    87,    42,    42,    84,    87,    86,    43,    29,    30,
      82,    83,    32,    35,    36,    37,    38,    79,    28,     3,
      84,    86,    43,    18,    77,    80,    81,    85,    92,    92,
      93,    93,    43,    79,    89,    29,    30,    62,    84,    84,
      86,    62,    39,    84,    84,    75,    76,    26,    67,    44,
      43,    43,    20,    19,    78,    86,    62,    90,    20,    41,
      86,    91,    45,    43
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

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {printf("\tInicia el COMPILADOR\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {printf("\tFin COMPILADOR ok\n"); if(crearArchivoIntermedia()==TODO_OK){printf("\nArchivo con intermedia generado\n");}else{printf("Hubo un error al generar el archivo de intermedia");}}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf("\t\tDECLARACIONES\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf("\tFin de las Declaraciones\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {printf("\t\tDECLARACIONES DEF\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {printf("\tFin de las Declaraciones DEF\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 193 "Sintactico.y"
    {validarDeclaracionTipoDato("REAL");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    { validarDeclaracionTipoDato("STRING"); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 195 "Sintactico.y"
    { validarDeclaracionTipoDato("INTEGER"); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    {	insertarEnListaDeclaracion(yylval.str_val);	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 200 "Sintactico.y"
    {  insertarEnListaDeclaracion(yylval.str_val);	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {printf("COMIENZO de BLOQUES\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 222 "Sintactico.y"
    { 
		flagREPEAT = TRUE; 
		printf("REPEAT\n");
		
		sprintf(inicioCuerpoRepeat, "CELDA %d", puntero_tokens);
		//itoa(puntero_tokens,sPosActual,10);
		//apilar(PILA_REPEAT,inicioCuerpo);
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 231 "Sintactico.y"
    { 
			//debugPila(PILA_REPEAT,tope_pila_repeat);
			int x;
			char sPosActual[5];
			escribirEnLista(puntero_tokens-1,inicioCuerpoRepeat);
			x = desapilar(PILA_REPEAT);
			
			sprintf(sPosActual, "CELDA %d", puntero_tokens);
			
			escribirEnLista(x,sPosActual);	// %%%%
			
			printf("FIN DEL REPEAT\n");
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 245 "Sintactico.y"
    { 
		 free(inicioWhilePos);
		 inicioWhilePos = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
		 sprintf(inicioWhilePos,"CELDA %d",puntero_tokens);
		
		 flagWHILE = TRUE; 
		 printf("WHILE\n");
	 
	 }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 255 "Sintactico.y"
    {
			int x, i, iPosActual;
			char wPosActual[5], wPosActualTrue[5], wPosCondDos[5];
			// debugPila(PILA_WHILE,tope_pila_while);
			insertarEnLista("BI");
			insertarEnLista(inicioWhilePos);			
			
			x=desapilar(PILA_WHILE); // Primero que desapilo -> apunta a la parte verdadera
			sprintf(wPosActualTrue, "CELDA %s", posTrue);
			escribirEnLista(x,wPosActualTrue);
			
			x=desapilar(PILA_WHILE); // Segundo que desapilo -> apunta al final
			sprintf(wPosActual, "CELDA %d", puntero_tokens);
			escribirEnLista(x,wPosActual);
			//debugPila(PILA_WHILE,tope_pila_while);
			
			if(flagWHILEAND == TRUE){
				
				if(pilaVacia(tope_pila_while) == FALSE){
					
					x=desapilar(PILA_WHILE); // Tercero que desapilo -> apunta a la segunda condicion
					sprintf(wPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,wPosCondDos);
					
					x=desapilar(PILA_WHILE); // Cuarto que desapilo -> apunta al final
					sprintf(wPosActual, "CELDA %d", puntero_tokens);
					escribirEnLista(x,wPosActual);
					//debugPila(PILA_WHILE,tope_pila_while);
				}
			
			} else if (flagWHILEOR == TRUE) {
				
				if(pilaVacia(tope_pila_while) == FALSE){
					
					x=desapilar(PILA_WHILE);// Tercero que desapilo -> apunta a la parte verdadera
					sprintf(wPosActualTrue, "CELDA %s", posTrue);
					escribirEnLista(x,wPosActualTrue);
					
					x=desapilar(PILA_WHILE);// Tercero que desapilo -> apunta a la segunda condicion
					sprintf(wPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,wPosCondDos);
				}			
				
			}
			flagWHILEOR = FALSE;
			flagWHILEAND = FALSE;
			flagWHILE = FALSE;

		}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 307 "Sintactico.y"
    {
				int i,x,limit;
				char sAux[5];
				sprintf(sAux,yylval.str_val);
				//debugPila(PILA_ASIGNACION,tope_pila_asignacion);
				
			
			limit = tope_pila_asignacion;
			for (i=0; i < limit;i++)
			{
				x=desapilar(PILA_ASIGNACION);
				//printf("Voy a escribir en la posiciion %d el valor %s\n",x,valorFactor);
				escribirEnLista(x,valorFactor);
				
			}
			insertarEnLista(":=");
				
			puntero_asignacion = 0;	// reset
			
			// ya se, es horrible esto
			if(flagAsigMul == TRUE){
				puntero_tokens = puntero_tokens -2;
			}
			flagAsigMul = FALSE;
			printf("FIN LINEA ASIGNACION\n");
			
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 339 "Sintactico.y"
    {
				
				// VERIFICO EL TIPO DE DATO
				
				if (strcmp(recuperarTipoTS((yyvsp[(3) - (3)].str_val)),auxTipoAsignacion) != 0)
				{
					finAnormal("Error","No puede asignar IDs con distinto tipo\n");
				}
				
				
				flagAsigMul = TRUE;
				//printf("Lei el ID A %s  \n",$3);
				if(flagPrimero == TRUE){
					insertarEnLista("###");
					char sPos[5];
					sprintf(sPos,"%d",puntero_tokens-1);
					apilar(PILA_ASIGNACION,sPos);
					insertarEnLista(":=");
					flagPrimero = FALSE;
				}
				char * strPos;
				if(verificarExistencia((yyvsp[(3) - (3)].str_val)) == EXISTE)
				{
					strPos = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					insertarEnLista((yyvsp[(3) - (3)].str_val));
					insertarEnLista("###");
					sprintf(strPos,"%d",puntero_tokens-1);
					apilar(PILA_ASIGNACION,strPos);
					insertarEnLista(":=");
					
				} else {
					// No existe en la tabla de simbolos
					finAnormal("Syntax Error","Variable no declarada");
				}
			}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 374 "Sintactico.y"
    {
				//printf("Lei el ID B %s  \n",$1);
				if(verificarExistencia((yyvsp[(1) - (1)].str_val)) == EXISTE)
				{
					insertarEnLista((yyvsp[(1) - (1)].str_val));
					flagPrimero = TRUE;
					// GUARDO EL TIPO DE DATO PARA COMPARAR CON LOS DEMAS IDs
				//	&&&&&&
				
					free(auxTipoAsignacion);
					auxTipoAsignacion = (char *) malloc(sizeof(char) * (sizeof(char) + 1));
					strcpy(auxTipoAsignacion, recuperarTipoTS((yyvsp[(1) - (1)].str_val)));
					printf("TIPO de dato %s\n",auxTipoAsignacion);
					
				} else {
					// No existe en la tabla de simbolos
					finAnormal("Syntax Error","Variable no declarada");
				}
				
			}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 397 "Sintactico.y"
    {printf("\t\tREAD\n"); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 398 "Sintactico.y"
    {printf("\t\tWRITE\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 399 "Sintactico.y"
    {printf("\t\tWRITE\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 403 "Sintactico.y"
    { 
				char sPosActual[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);
			}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 410 "Sintactico.y"
    {
				
				int x, i, iPosActual;
				char sPosActual[5], sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
				
				x=desapilar(PILA_IF); // Primero que desapilo -> apunta a la posicion actual
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
				x=desapilar(PILA_IF);// Segundo que desapilo -> apunta a la parte verdadera
				sprintf(sPosActualTrue, "CELDA %s", posTrue);
				escribirEnLista(x,sPosActualTrue);
				
				x=desapilar(PILA_IF); // Tercero que desapilo -> apunta al final
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
					
				if(flagIFOR == TRUE){
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la parte verdadera
					escribirEnLista(x,sPosActualTrue);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
				} else if (flagIFAND == TRUE){
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
					x=desapilar(PILA_IF);// Quinto que desapilo -> apunta a la parte falsa
					escribirEnLista(x,sPosActualFalse);
				} else {
					// NO HAGO NADA - IF DE CONDICION SIMPLE	
				}
				
				flagIFAND = FALSE;
				flagIFOR = FALSE;
				
				sprintf(sPosActual, "-1");
				sprintf(posCondDos, "-1");
				sprintf(posFalse, "-1");
				sprintf(posTrue, "-1");
				
				printf("FIN DEL IF\n"); 
			}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 458 "Sintactico.y"
    { 
				char sPosActual[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 466 "Sintactico.y"
    {
				int x, i, iPosActual;
				char sPosActual[5], sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
				
				x=desapilar(PILA_IF); // Primero que desapilo -> apunta a la posicion actual
				sprintf(sPosActual, "CELDA %d", puntero_tokens);
				escribirEnLista(x,sPosActual);
				
				x=desapilar(PILA_IF); // Segundo que desapilo -> apunta a la parte verdadera
				sprintf(sPosActualTrue, "CELDA %s", posTrue);
				escribirEnLista(x,sPosActualTrue);
				
				x=desapilar(PILA_IF); // Tercero que desapilo -> apunta a la posicion actual
				sprintf(sPosActualFalse, "CELDA %s", posFalse);
				escribirEnLista(x,sPosActualFalse);
				
				if(flagIFOR == TRUE){
					
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la parte verdadera
					sprintf(sPosActualTrue, "CELDA %s", posTrue);
					escribirEnLista(x,sPosActualTrue);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
				} else if (flagIFAND == TRUE){
					
					x=desapilar(PILA_IF); // Cuarto que desapilo -> apunta a la segunda condicion
					sprintf(sPosCondDos, "CELDA %s", posCondDos);
					escribirEnLista(x,sPosCondDos);
					
					x=desapilar(PILA_IF); // Quinto que desapilo -> apunta a la parte falsa
					sprintf(sPosActualFalse, "CELDA %s", posFalse);
					escribirEnLista(x,sPosActualFalse);
				} else {
					// NO HAGO NADA - IF DE CONDICION SIMPLE	
				}
				
				flagIFAND = FALSE;
				flagIFOR = FALSE;
				sprintf(sPosActual, "-1");
				sprintf(posCondDos, "-1");
				sprintf(posFalse, "-1");
				sprintf(posTrue, "-1");
				
			printf("FIN DEL IF CON ELSE\n");
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 516 "Sintactico.y"
    {
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActual);
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_IF,sPosActualB);	
			
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
					
			}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 535 "Sintactico.y"
    {	sprintf(posFalse, "%d", puntero_tokens); /*guardo la posicion del false*/ }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 539 "Sintactico.y"
    {
			 if(flagWHILE == TRUE){ //Manejo del While
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActual); // usado en el while
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true						
			 
				flagWHILE = FALSE; //agregado lucas (dsp fijate mauro es para q no vuelva a entrar)
			 }
			 
			 if(flagREPEAT == TRUE){
				
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_REPEAT,sPosActual); // usado en el while
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true						
			 
				flagREPEAT = FALSE;
				
			 }
			 
			 
			 
		 }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 581 "Sintactico.y"
    {printf("NOT CONDICION\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 582 "Sintactico.y"
    {sprintf(posCondDos, "%d", puntero_tokens);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 583 "Sintactico.y"
    {
			 
			 if(flagWHILE == TRUE){
				flagWHILEAND = TRUE;
				insertarEnLista("CMP");
				insertarEnLista(valorComparacion(comparador_usado));
				char sPosActual[5];
				insertarEnLista("###");
				sprintf(sPosActual, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActual);
				
				char sPosActualB[5];
				insertarEnLista("BI");
				insertarEnLista("###");
				sprintf(sPosActualB, "%d", puntero_tokens-1);
				apilar(PILA_WHILE,sPosActualB);	
				sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
				//debugPila(PILA_WHILE,tope_pila_while);		
			 }
			}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 603 "Sintactico.y"
    { sprintf(posCondDos, "%d", puntero_tokens); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 604 "Sintactico.y"
    { 
				if(flagWHILE == TRUE){
					// flagWHILEOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);	
					sprintf(posTrue, "%d", puntero_tokens); // guardo la posicion del true				
					//debugPila(PILA_WHILE,tope_pila_while);		
				 }
				printf("CONDICION DOBLE OR\n"); 
			}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 624 "Sintactico.y"
    {printf("NOT CONDICION DOBLE AND\n");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 625 "Sintactico.y"
    {printf("NOT CONDICION DOBLE OR\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 626 "Sintactico.y"
    {insertarEnLista("1");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 627 "Sintactico.y"
    {insertarEnLista("0");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 630 "Sintactico.y"
    {
			
				if(flagWHILE == TRUE){
					flagWHILEAND = TRUE;
					flagWHILEOR = FALSE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);
				} else {
					flagIFAND = TRUE;
					flagIFOR = FALSE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActualB);
				}
			
			}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 667 "Sintactico.y"
    {
				
				if(flagWHILE == TRUE){
					flagWHILEOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_WHILE,sPosActualB);	
				} else {
					flagIFAND = FALSE;
					flagIFOR = TRUE;
					insertarEnLista("CMP");
					insertarEnLista(valorComparacion(comparador_usado));
					char sPosActual[5];
					insertarEnLista("###");
					sprintf(sPosActual, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActual);
					
					char sPosActualB[5];
					insertarEnLista("BI");
					insertarEnLista("###");
					sprintf(sPosActualB, "%d", puntero_tokens-1);
					apilar(PILA_IF,sPosActualB);	
				}
				
			}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 705 "Sintactico.y"
    { strcpy(comparador_usado,yylval.cmp_val);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 709 "Sintactico.y"
    {insertarEnLista("+");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 710 "Sintactico.y"
    {insertarEnLista("-");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 715 "Sintactico.y"
    {printf("INICIO BETWEEN\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 715 "Sintactico.y"
    {
													int iPosID = insertarEnLista(yylval.str_val);
													char * sPosID = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
													itoa(iPosID,sPosID,10);
													apilar(PILA_BETWEEN,sPosID);
												   }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 721 "Sintactico.y"
    {
					int iPosActual, iPosID;
					char * sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
				
					iPosID = desapilar(PILA_BETWEEN);
					insertarEnLista("CMP");
					insertarEnLista("BLT");
					
					iPosActual = insertarEnLista("###");
					sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					itoa(iPosActual,sPosActual,10);
					apilar(PILA_BETWEEN,sPosActual);
					
					insertarEnLista("BI");
					iPosActual = insertarEnLista("###");
					sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
					itoa(iPosActual,sPosActual,10);
					apilar(PILA_BETWEEN,sPosActual);
					iPosCondDos = puntero_tokens;
					insertarEnLista(listaTokens[iPosID]);		
					
					}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 742 "Sintactico.y"
    {
											int x, i, iPosActual, posTrue, posFalse;
											char sPosActualTrue[5], sPosActualFalse[5], sPosCondDos[5];
											char * sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											insertarEnLista("CMP");
											insertarEnLista("BGT");
											
											iPosActual = insertarEnLista("###");
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											
											insertarEnLista("BI");
											iPosActual = insertarEnLista("###");
											sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											
											insertarEnLista("1");
											posTrue = puntero_tokens-1;
											
											insertarEnLista("BI");
											iPosActual = insertarEnLista("###");
											sPosActual = (char *) malloc(sizeof(char) * (sizeof(int) + 1));
											itoa(iPosActual,sPosActual,10);
											apilar(PILA_BETWEEN,sPosActual);
											insertarEnLista("0");
											posFalse = puntero_tokens-1;
											
											x=desapilar(PILA_BETWEEN); // Primero que desapilo -> apunta a la posicion actual
											sprintf(sPosActual, "CELDA %d", puntero_tokens);
											escribirEnLista(x,sPosActual);
											
											x=desapilar(PILA_BETWEEN); // Segundo que desapilo -> apunta a la parte verdadera
											sprintf(sPosActualTrue, "CELDA %d", posTrue);
											escribirEnLista(x,sPosActualTrue);
											
											x=desapilar(PILA_BETWEEN); // Tercero que desapilo -> apunta a la posicion actual
											sprintf(sPosActualFalse, "CELDA %d", posFalse);
											escribirEnLista(x,sPosActualFalse);
											
											x=desapilar(PILA_BETWEEN); // Cuarto que desapilo -> apunta a la segunda condicion
											sprintf(sPosCondDos, "CELDA %d", iPosCondDos);
											escribirEnLista(x,sPosCondDos);
												
											x=desapilar(PILA_BETWEEN); // Quinto que desapilo -> apunta a la parte falsa
											sprintf(sPosActualFalse, "CELDA %d", posFalse);
											escribirEnLista(x,sPosActualFalse);
											
										}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 790 "Sintactico.y"
    {printf("\t\tFIN BETWEEN\n");}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 796 "Sintactico.y"
    {
			   insertarEnLista("*"); 
			   sumTermino = sumTermino * atof(valorFactor);
			}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 802 "Sintactico.y"
    {
				insertarEnLista("/"); 
				sumTermino = sumTermino / atof(valorFactor);
			}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 806 "Sintactico.y"
    { 
			sumTermino = 0;
			sumTermino = atof(valorFactor);
			sprintf(valorTermino,"%f",sumTermino); 
			
			
		   }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 816 "Sintactico.y"
    { 
			if(verificarExistencia(yylval.str_val) == NO_EXISTE)
			{ 
				finAnormal("Syntax Error","Variable no declarada"); 
			} 
			insertarEnLista(yylval.str_val);
			
			
			
		}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 826 "Sintactico.y"
    {
					  if(verificarExistencia(yylval.str_val) == NO_EXISTE)
						{ 
							insertar_TS("CONST_INT",yylval.int_val);
						} 
					  insertarEnLista(yylval.int_val); 
					  sprintf(valorFactor,"%s",yylval.int_val);
				  }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 835 "Sintactico.y"
    {
			if(verificarExistencia(yylval.real_val) == NO_EXISTE)
			{ 
				insertar_TS("CONST_REAL",yylval.real_val);
			} 
			insertarEnLista(yylval.real_val); 
			sprintf(valorFactor,"%s",yylval.real_val);
			//printf("Guarde el valor real %s\n",valorFactor);
		}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 846 "Sintactico.y"
    {
			if(verificarExistencia(yylval.str_val) == NO_EXISTE)
			{ 
				insertar_TS("CONST_STR",yylval.str_val);
			} 
			insertarEnLista(yylval.str_val); 
			sprintf(valorFactor,"%s",yylval.str_val);
		}
    break;



/* Line 1455 of yacc.c  */
#line 2604 "y.tab.c"
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



/* Line 1675 of yacc.c  */
#line 857 "Sintactico.y"

// FUNCIONES DE TABLA DE SIMBOLOS
int insertar_TS(char* tipo, char* nombre)
{
	int i, posicion;
	
	for(i = 0; i < puntero_ts; i++)
	{
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0)
		{
			return i;
		}
	}
	strcpy(tablaSimbolos[puntero_ts].tipo, tipo);
	strcpy(tablaSimbolos[puntero_ts].nombre, nombre);
	
	if(strcmp(tipo,"CONST_STR") == 0)
	{
		int longitud = strlen(tablaSimbolos[i].nombre);
		sprintf(tablaSimbolos[puntero_ts].longitud, "%d", longitud );		
	} 
	else if (strcmp(tipo,"CONST_INT") == 0  || strcmp(tipo,"CONST_REAL") == 0)
	{
		strcpy(tablaSimbolos[puntero_ts].valor, tablaSimbolos[i].nombre);
	}
	
	posicion = puntero_ts;
	puntero_ts++;
	return posicion;
}

int verificarExistencia(char* nombre)
{
	int i;
	for (i=0;i < puntero_ts;i++)
	{
		//printf("Voy a comprar %s con %s \n",nombre, tablaSimbolos[i].nombre);
		if(strcmp(nombre,tablaSimbolos[i].nombre) == 0)
		{
			return EXISTE;
		}
	}
	return NO_EXISTE;
}

char * recuperarValorTS(char* nombre)
{
	int i;
	for (i=0;i < puntero_ts;i++)
	{
		//printf("Voy a comprar %s con %s \n",nombre, tablaSimbolos[i].nombre);
		if(strcmp(nombre,tablaSimbolos[i].nombre) == 0)
		{
			return tablaSimbolos[i].valor;
		}
	}
	finAnormal("Syntax Error","Variable no inicializada");
	return "ERROR";
}

char * recuperarTipoTS(char* nombre)
{
	int i;
	for (i=0;i < puntero_ts;i++)
	{
		//printf("Voy a comprar %s con %s \n",nombre, tablaSimbolos[i].nombre);
		if(strcmp(nombre,tablaSimbolos[i].nombre) == 0)
		{
			return tablaSimbolos[i].tipo;
		}
	}
	finAnormal("Syntax Error","Variable no inicializada");
	return "ERROR";
}

int crearArchivoTS()
{
	FILE *archivo; 
	int i;
	archivo = fopen("ts.txt","w"); 

	if (!archivo){	return ERROR; }

	fprintf(archivo, "Nombre                        Tipo                  Valor                Longitud\n");
	
	for (i = 0; i < puntero_ts; i++)
	{
		if (strcmp(tablaSimbolos[i].tipo, "INTEGER") == 0 || strcmp(tablaSimbolos[i].tipo, "REAL") == 0  || strcmp(tablaSimbolos[i].tipo, "STRING") == 0 )
		{  
			fprintf(archivo,"%-30s%-10s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo);
		}
		else if(strcmp(tablaSimbolos[i].tipo, "CONST_STR") == 0 )
		{
			fprintf(archivo,"%-29s%-10s                                    %-30d\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,strlen(tablaSimbolos[i].nombre));
		}
		else if(strcmp(tablaSimbolos[i].tipo, "CONST_INT") == 0 || strcmp(tablaSimbolos[i].tipo, "CONST_REAL") == 0)
		{
			fprintf(archivo,"_%-29s%-10s           %-30s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,tablaSimbolos[i].valor);
		}
		else 
		{
			fprintf(archivo,"%-30s%-10s                                %-30s\n", tablaSimbolos[i].nombre, tablaSimbolos[i].tipo,tablaSimbolos[i].valor);
		}
	}
	fclose(archivo); 

	return TODO_OK;
}


// FUNCIONES DE PILA
void apilar(int nroPila, char * val)
{
	switch(nroPila){
		case PILA_IF:
			
			
			if(pilaLlena(PILA_IF) == TRUE){
				printf("Error: Se exedio el tamano de la pila de IF.\n");
				system ("Pause");
				exit (1);
			}
			pilaIF[tope_pila_if]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_if++;
			break;
		
		case PILA_WHILE:
		
			if(pilaLlena(PILA_WHILE) == TRUE){
				printf("Error: Se exedio el tamano de la pila de WHILE.\n");
				system ("Pause");
				exit (1);
			}
			pilaWhile[tope_pila_while]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_while++;
			break;
		case PILA_ASIGNACION:
		
			if(pilaLlena(PILA_ASIGNACION) == TRUE){
				printf("Error: Se exedio el tamano de la pila de ASIGNACION.\n");
				system ("Pause");
				exit (1);
			}
			pilaAsignacion[tope_pila_asignacion]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_asignacion++;
			break;	
		case PILA_REPEAT:
			if(pilaLlena(PILA_REPEAT) == TRUE){
				printf("Error: Se exedio el tamano de la pila de REPEAT.\n");
				system ("Pause");
				exit (1);
			}
			pilaRepeat[tope_pila_repeat]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_repeat++;
			break;	
			
		case PILA_BETWEEN:
			if(pilaLlena(PILA_BETWEEN) == TRUE){
				printf("Error: Se exedio el tamano de la pila de BETWEEN.\n");
				system ("Pause");
				exit (1);
			}
			pilaBetween[tope_pila_between]=val;
			printf("\tAPILAR #CELDA ACTUAL -> %s\n",val);
			tope_pila_between++;
			break;	
		
		default:
			printf("\tError: La pila recibida no se reconoce\n",val);
			system ("Pause");
			exit (1);
			break;
	}

}

int desapilar(int nroPila)
{
	switch(nroPila){
		case PILA_IF:
			if(pilaVacia(tope_pila_if) == 0)
			{
				char * dato = pilaIF[tope_pila_if-1];
				tope_pila_if--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				printf("Error: La pila esta vacia.\n");
				system ("Pause");
				exit (1);
			}
			
			break;
		
		case PILA_WHILE:
		
			if(pilaVacia(tope_pila_while) == 0)
			{
				char * dato = pilaWhile[tope_pila_while-1];
				tope_pila_while--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;
		case PILA_ASIGNACION:
		
			if(pilaVacia(tope_pila_asignacion) == 0)
			{
				char * dato = pilaAsignacion[tope_pila_asignacion-1];
				tope_pila_asignacion--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	
		case PILA_REPEAT:
		
			if(pilaVacia(tope_pila_repeat) == 0)
			{
				char * dato = pilaRepeat[tope_pila_repeat-1];
				tope_pila_repeat--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	
		
		case PILA_BETWEEN:
		
			if(pilaVacia(tope_pila_between) == 0)
			{
				char * dato = pilaBetween[tope_pila_between-1];
				tope_pila_between--;	
				printf("\tDESAPILAR #CELDA -> %s\n",dato);
				return atoi(dato);		
			} else {
				finAnormal("Stack Error","La pila esta vacia");
			}
		
			break;	

		default:
			finAnormal("Stack Error","La pila recibida no se reconoce");
			break;
		
	}
	
}

int pilaVacia(int tope)
{
	if (tope-1 == -1){
		return TRUE;
	} 
	return FALSE;
}

int pilaLlena(int tope)
{
	if (tope-1 == TAM_PILA-1){
		return TRUE;
	} 
	return FALSE;
}

void debugPila(int nroPila, int tope)
{
	char * nombre;
	char * pila[TAM_PILA];
	int i;
	printf("====== DEBUG PILA ======\n\n");
	
	switch(nroPila){
		case PILA_IF:
			printf("posCondDos: %s\n",posCondDos);
			printf("posTrue: %s\n",posTrue);
			printf("posFalse: %s\n",posFalse);
			printf("El tope de la pila es %d \n",tope_pila_if);		
			printf("Lista de elementos: \n");		
			for (i=0; i<tope_pila_if;i++){
				printf("%d => %s\n",i,pilaIF[i]);		
			}
			
			break;
		
		case PILA_WHILE:
			printf("posCondDos: %s\n",posCondDos);
			printf("posTrue: %s\n",posTrue);
			printf("posFalse: %s\n",posFalse);
			printf("El tope de la pila es %d \n",tope_pila_while);		
			printf("Lista de elementos: \n");		
			for (i=0; i<tope_pila_while;i++){
				printf("%d => %s\n",i,pilaWhile[i]);		
			}
			
			break;
		case PILA_ASIGNACION:
			
			printf("El tope de la pila es %d \n",tope_pila_asignacion);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_asignacion;i++){
				printf("%d => %s\n",i,pilaAsignacion[i]);		
			}
			
			break;	
		case PILA_BETWEEN:
			
			printf("El tope de la pila es %d \n",tope_pila_between);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_between;i++){
				printf("%d => %s\n",i,pilaBetween[i]);		
			}
			
			break;		
		case PILA_REPEAT:
			
			printf("El tope de la pila es %d \n",tope);		
			printf("Lista de elementos: \n");			
			for (i=0; i<tope_pila_repeat;i++){
				printf("%d => %s\n",i,pilaRepeat[i]);		
			}
			
			break;			
		default:
			printf("Error interno: Pila no reconocida \n");
			system("Pause");
			exit(1);
			break;
	}
	printf("\n====== FIN DEBUG PILA ======\n\n");	
	
}


int insertarEnLista(char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaTokens[puntero_tokens] = aux;
	puntero_tokens++;
	
	//escribo en archivo
	//fprintf(fintermedia,"%s\n",aux);
	
	// DEBUG por consola
	if(strcmp(aux,"###")!=0){
		printf("\tinsertar_en_polaca(%s)\n", aux);
	}
	return (puntero_tokens-1); // devuelvo posicion
}

int insertarEnListaDeclaracion(char * val)
{
	
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaDeclaracion[puntero_declaracion] = aux;
	puntero_declaracion++;
	
	return (puntero_declaracion-1); // devuelvo posicion
	
}

int insertarEnListaAsig(char * val)
{
	
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// Agrego al array de tokens
	listaAsignacion[puntero_asignacion] = aux;
	puntero_asignacion++;
	
	return (puntero_asignacion-1); // devuelvo posicion
	
}

void debugListaDeclaracion()
{
	int i;
	printf("====== DEBUG LISTA DECLARACION ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_declaracion);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_declaracion;i++){
		printf("%d => %s\n",i,listaDeclaracion[i]);		
	}
	
	printf("\n====== FIN DEBUG LISTA DECLARACION ======\n\n");	
	
}

void debugListaAsignacion()
{
	int i;
	printf("====== DEBUG LISTA ASIGNACION ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_asignacion);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_asignacion;i++){
		printf("%d => %s\n",i,listaAsignacion[i]);		
	}
	
	printf("\n====== FIN DEBUG LISTA ASIGNACION ======\n\n");	
	
}

void debugTS()
{
	int i;
	printf("====== DEBUG TABLA SIMBOLOS ======\n\n");
	printf("La cantidad de elementos es %d \n",puntero_ts);		
	printf("Lista de elementos: \n");		
	for (i=0; i < puntero_ts;i++){
		printf("%d => %s | %s | %s | %s \n",i,tablaSimbolos[i].nombre,tablaSimbolos[i].tipo,tablaSimbolos[i].valor,tablaSimbolos[i].longitud );		
	}
	
	printf("\n====== FIN DEBUG TABLA SIMBOLOS ======\n\n");	
	
}

void escribirEnLista(int pos, char * val)
{
	// Convierto en CHAR *
	aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
	
	// escribo en vector
	listaTokens[pos] = aux;
	
	printf("\tEscribio en %i el valor %s\n",pos,aux);
	
}

char * valorComparacionCICLO(char * val){
	if(strcmp("=", val) == 0){
		return "BEQ";
	} else if(strcmp(">=", val) == 0){
		return "BGE";
	} else if(strcmp(">", val) == 0){
		return "BGT";
	} else if(strcmp("<=", val) == 0){
		return "BLE";
	} else if(strcmp("<", val) == 0){
		return "BLT";
	} else if(strcmp("><", val) == 0){
		return "BNE";
	} else {
		// NUNCA DEBERIA CAER ACA
		return val;
	}
}

char * valorComparacion(char * val){
	if(strcmp("=", val) == 0){
		return "BNE";
	} else if(strcmp(">=", val) == 0){
		return "BLT";
	} else if(strcmp(">", val) == 0){
		return "BLE";
	} else if(strcmp("<=", val) == 0){
		return "BGT";
	} else if(strcmp("<", val) == 0){
		return "BGE";
	} else if(strcmp("><", val) == 0){
		return "BEQ";
	} else {
		// NUNCA DEBERIA CAER ACA
		return val;
	}
}

int yyerror()
{
	printf("** FIN DEL PROGRAMA **\n\n");
	system ("Pause");
	exit (1);
}

void finAnormal(char * tipo, char * mensaje)
{
	printf("[ERROR]: %s - %s\n",tipo,mensaje);
	yyerror();
}

int crearArchivoIntermedia()
{
	FILE * archivo; 
	int i;
	archivo = fopen("intermedia.txt", "wt");

	if (!archivo){	return ERROR; }

	for (i = 1; i < puntero_tokens; i++)
	{
		fprintf(archivo,"%s\n", listaTokens[i]);
		//fprintf(archivo,"CELDA %d: %s\n", i, listaTokens[i]);
	}
	fclose(archivo); 

	return TODO_OK;
}

void validarDeclaracionTipoDato(char * tipo)
{
	int i;
	for (i=0; i < puntero_declaracion; i++)
	{
	//printf("Voy a verificar la existencia del elemento %s: \n",listaDeclaracion[i]);
		if(verificarExistencia(listaDeclaracion[i]) == NO_EXISTE)
		{
		//printf("No existe, la inserto en tabla de simbolos \n");
		insertar_TS(tipo,listaDeclaracion[i]);
		//debugListaDeclaracion();
		//debugTS();
		}
		else 
		{
			printf("Syntax error: Variable ya declarada\n");
			system("Pause");
			exit(1);
		}
	}
	// reinicio el contador para leer otro tipo de dato
	puntero_declaracion = 0;
}


int main(int argc,char *argv[])
{
	
	if ((yyin = fopen(argv[1], "rt")) == NULL)
	{	
		printf("\nError al abrir archivo: %s\n", argv[1]); 
	} 
	else
	{ 
		yyparse();
	}
	
	if(crearArchivoTS() == TODO_OK)
	{
		printf("Se genero el archivo de tabla de simbolos\n");
	}
	else 
	{
		printf("ERROR - Syntax error\n");
		system ("Pause");
		exit(1);
	}
	
	fclose(yyin);
	return 0;
}