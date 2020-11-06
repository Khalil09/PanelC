/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 52 "src/panelc_parser.h"

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

#line 132 "src/panelc_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_SRC_PANELC_PARSER_H_INCLUDED  */
