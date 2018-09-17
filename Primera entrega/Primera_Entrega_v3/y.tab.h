
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
     CONST_INT = 261,
     CONST_REAL = 262,
     CONST_STR = 263,
     REAL = 264,
     INTEGER = 265,
     STRING = 266,
     BEGINP = 267,
     ENDP = 268,
     IF = 269,
     THEN = 270,
     ELSE = 271,
     ENDIF = 272,
     FOR = 273,
     TO = 274,
     DO = 275,
     ENDFOR = 276,
     WHILE = 277,
     ENDW = 278,
     REPEAT = 279,
     UNTIL = 280,
     OP_AND = 281,
     OP_OR = 282,
     OP_NOT = 283,
     ID = 284,
     OP_COMPARACION = 285,
     OP_ASIG = 286,
     OP_DOSP = 287,
     OP_SURES = 288,
     OP_MULTDIV = 289,
     CAR_COMA = 290,
     CAR_PUNTO = 291,
     CAR_PYC = 292,
     CAR_PA = 293,
     CAR_PC = 294,
     CAR_CA = 295,
     CAR_CC = 296,
     LONG = 297,
     BETWEEN = 298,
     IN = 299,
     WRITE = 300,
     READ = 301
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define DECVAR 259
#define ENDDEC 260
#define CONST_INT 261
#define CONST_REAL 262
#define CONST_STR 263
#define REAL 264
#define INTEGER 265
#define STRING 266
#define BEGINP 267
#define ENDP 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define FOR 273
#define TO 274
#define DO 275
#define ENDFOR 276
#define WHILE 277
#define ENDW 278
#define REPEAT 279
#define UNTIL 280
#define OP_AND 281
#define OP_OR 282
#define OP_NOT 283
#define ID 284
#define OP_COMPARACION 285
#define OP_ASIG 286
#define OP_DOSP 287
#define OP_SURES 288
#define OP_MULTDIV 289
#define CAR_COMA 290
#define CAR_PUNTO 291
#define CAR_PYC 292
#define CAR_PA 293
#define CAR_PC 294
#define CAR_CA 295
#define CAR_CC 296
#define LONG 297
#define BETWEEN 298
#define IN 299
#define WRITE 300
#define READ 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


