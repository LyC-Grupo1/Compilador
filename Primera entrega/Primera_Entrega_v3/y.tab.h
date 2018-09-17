
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
     PROGRAM = 258,
     DECVAR = 259,
     ENDDEC = 260,
     DEFVAR = 261,
     ENDDEF = 262,
     CONST_INT = 263,
     CONST_REAL = 264,
     CONST_STR = 265,
     REAL = 266,
     INTEGER = 267,
     STRING = 268,
     BEGINP = 269,
     ENDP = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     ENDIF = 274,
     FOR = 275,
     TO = 276,
     DO = 277,
     ENDFOR = 278,
     WHILE = 279,
     ENDW = 280,
     REPEAT = 281,
     UNTIL = 282,
     OP_AND = 283,
     OP_OR = 284,
     OP_NOT = 285,
     ID = 286,
     OP_COMPARACION = 287,
     OP_ASIG = 288,
     OP_DOSP = 289,
     OP_SURES = 290,
     OP_MULTDIV = 291,
     CAR_COMA = 292,
     CAR_PUNTO = 293,
     CAR_PYC = 294,
     CAR_PA = 295,
     CAR_PC = 296,
     CAR_CA = 297,
     CAR_CC = 298,
     LONG = 299,
     BETWEEN = 300,
     IN = 301,
     WRITE = 302,
     READ = 303
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define DECVAR 259
#define ENDDEC 260
#define DEFVAR 261
#define ENDDEF 262
#define CONST_INT 263
#define CONST_REAL 264
#define CONST_STR 265
#define REAL 266
#define INTEGER 267
#define STRING 268
#define BEGINP 269
#define ENDP 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define FOR 275
#define TO 276
#define DO 277
#define ENDFOR 278
#define WHILE 279
#define ENDW 280
#define REPEAT 281
#define UNTIL 282
#define OP_AND 283
#define OP_OR 284
#define OP_NOT 285
#define ID 286
#define OP_COMPARACION 287
#define OP_ASIG 288
#define OP_DOSP 289
#define OP_SURES 290
#define OP_MULTDIV 291
#define CAR_COMA 292
#define CAR_PUNTO 293
#define CAR_PYC 294
#define CAR_PA 295
#define CAR_PC 296
#define CAR_CA 297
#define CAR_CC 298
#define LONG 299
#define BETWEEN 300
#define IN 301
#define WRITE 302
#define READ 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


