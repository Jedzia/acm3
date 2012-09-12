/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 118 "cs.y"

  int number;
  char *string;
  treenode *node;



/* Line 1685 of yacc.c  */
#line 126 "cs.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


