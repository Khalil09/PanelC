%option noinput nounput
%option noyywrap
%option bison-bridge

%{
#include "panelc_parser.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ERRORS_COUNT = 0;
int MAX_ERRORS = 500;
int error_cnt = 0;
int current_col = 1; int current_line = 1;
int current_token = 0;
int str_size = 1;
char string_f[] = "\0";

void appendString(char * c) {
    strcat(string_f, c);
}

void resetString() {
    strcpy(string_f, "");
}

%}
%option yylineno
%option noinput nounput
%option noyywrap
%option bison-bridge
%x STRING
%x COMMENT

EOL \n

DIGITO     [0-9]
INT        [+-]?{DIGITO}+
FLOAT      [+-]?{DIGITO}+"."({DIGITO}*)?
LETRA      [a-zA-Z]
TIPO       "int"|"float"|"char"|"panel"|"string"|"bool"
FLUX       "if"|"while"|"else"|"return"|"for"
OP         "+"|"-"|"*"|"/"|"->"
CMDOP      "<="|"=="|">="|">"|"<"|"!="
ID         {LETRA}({LETRA}|{DIGITO})*

%%

{TIPO} { 
    current_col += yyleng;
    strcpy(yylval->tipo, yytext);
    return TIPO;
} 

{FLOAT} { 
    current_col += yyleng;
    yylval->f_val = atof(yytext);
    return FLOAT;
}

{INT} { 
    current_col += yyleng;
    yylval->i_val = atoi(yytext);
    return INT;
}

\" {
    current_col += yyleng;
    resetString();
    BEGIN(STRING);
}

<STRING>\" {
    current_col += yyleng;
    strcpy(yylval->str_val, string_f);
    BEGIN(INITIAL);
    return STR_VAL;
}

<STRING>\n {
    current_line++;
    current_col = 0;
    appendString(yytext);
}

<STRING>\\\" {
    current_col += yyleng;
    appendString(yytext);
}

<STRING><<EOF>> {
    ERRORS_COUNT++;
    printf("------ERROR %d--------\n", error_cnt+1);
    printf("Simbolo: %s\n", "END_OF_STRING");
    printf("%s\n", "End of the string doesn't found");
    printf("Line: %d\n", current_line);
    printf("Column: %d\n", current_col);
    printf("----------------------\n");
    error_cnt++;
    BEGIN(INITIAL);
}

<STRING>. {
    appendString(yytext);
}

"/*" {
    current_col += yyleng;
    BEGIN(COMMENT);
}

<COMMENT>EOL {
    current_line += 1;
}

<COMMENT>"*/" {
    current_col += yyleng;
    BEGIN(INITIAL);
}

<COMMENT>. {
    current_col += yyleng;
}

<COMMENT><<EOF>> {
    ERRORS_COUNT++;
    printf("------ERROR %d--------\n", error_cnt+1);
    printf("Simbolo: %s\n", "END OF COMMMENT");
    printf("%s\n", "End of the comment doesn't found");
    printf("Line: %d\n", current_line);
    printf("Column: %d\n", current_col);
    printf("----------------------\n");
    error_cnt++;
    BEGIN(INITIAL);
}

"if"      { current_col += yyleng; return IF; }
"else"    { current_col += yyleng; return ELSE; }
"while"   { current_col += yyleng; return WHILE; }
"for"     { current_col += yyleng; return FOR; }
"return"  { current_col += yyleng; return RETURN; }
"rows"    { current_col += yyleng; return ROWS; }
"columns" { current_col += yyleng; return COLUMNS; }
"cells"   { current_col += yyleng; return CELLS; }
"false"   { current_col += yyleng; return BOOLCONST; }
"true"    { current_col += yyleng; return BOOLCONST; }
{ID}      { current_col += yyleng; strcpy(yylval->id, yytext); return ID; }
{OP}      { current_col += yyleng; strcpy(yylval->op, yytext); return OP; }
{CMDOP}   { current_col += yyleng; strcpy(yylval->cmdop, yytext); return CMDOP; }
"("       { current_col += yyleng; return LP; }
")"       { current_col += yyleng; return RP; }
"{"       { current_col += yyleng; return LCH; }
"}"       { current_col += yyleng; return RCH; }
"["       { current_col += yyleng; return LC; }
"]"       { current_col += yyleng; return RC; }
";"       { current_col += yyleng; return SEMI_COL; }
":"       { current_col += yyleng; return DOUBLEDOT; }
","       { current_col += yyleng; return COL; }
"="       { current_col += yyleng; return ATRIB; }
{EOL}     { current_line++; current_col = 1; }
\t*       { current_col += yyleng; }
" "*      { current_col += yyleng; }

. {
    current_col += yyleng;
    ERRORS_COUNT++;
    printf("------ERROR %d--------\n", error_cnt+1);
    printf("Simbolo: %s\n", yytext);
    printf("%s\n", "Symbol does not belong to the grammar");
    printf("Line: %d\n", current_line);
    printf("Column: %d\n", current_col);
    printf("----------------------\n");
    error_cnt++;
}

%%

void yyerror(const char *s) {
  fprintf(stderr, "%d: %s\n", yylineno, s);
}