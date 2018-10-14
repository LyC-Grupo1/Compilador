
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 33 "Sintactico.y"

int intval;
char *str_val;



/* Line 1676 of yacc.c  */
#line 159 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


