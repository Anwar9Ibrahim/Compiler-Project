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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 29 "D:\\compiler\\YamenBasel\\compilers last homework\\parser.y"
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
/* Line 1447 of yacc.c.  */
#line 127 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



