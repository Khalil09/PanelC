%{
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ERRORS_COUNT = 0;
int MAX_ERRORS = 500;
int error_cnt = 0;
int current_col = 1; int current_line = 1;

struct LexicalErrors {
    char error_type[50];
    char error_message[100];
    int line;
    int column;
};

struct LexicalErrors error;

void showError(char text[]){
    printf("------ERROR %d--------\n", error_cnt+1);
    printf("Simbolo: %s\n", text);
    printf("%s\n", error.error_message);
    printf("Line: %d\n", error.line);
    printf("Column: %d\n", error.column);
    printf("----------------------\n");
}

%}

%x STRING

EOL \n
SEP [<>,.;:]

PAREN      [()] 
CHAVES     [{}]
COLCH      [\[\]]

DIGITO     [0-9]
INT        [+-]?{DIGITO}+
FLOAT      [+-]?{DIGITO}+"."({DIGITO}*)?
LETRA      [a-zA-Z]
TIPO       "int"|"float"|"char"|"panel"|"string"
FLUX       "if"|"while"|"else"|"return"|"for"
OPERADORES "+"|"-"|"*"|"/"|"->"
CMDOP      "<="|"=="|">="|">"|"<"|"!="
ID         {LETRA}({LETRA}|{DIGITO})*
NUM        {DIGITO}+?("."{DIGITO}*)

%%

{TIPO} { 
    current_col += yyleng;
    printf("TIPO      (%s) tamanho %d\n", yytext, yyleng);
}

{INT} { 
    current_col += yyleng;
    printf("INT       (%s) tamanho %d\n", yytext, yyleng ); 
}

{FLOAT} { 
    current_col += yyleng;
    printf("FLOAT     (%s) tamanho %d\n", yytext, yyleng ); 
}

\" {
    current_col += yyleng;
    printf("Iniciando String\n");
    BEGIN(STRING);
}

<STRING>\" {
    current_col += yyleng;
    printf("Fim da String\n");
    BEGIN(INITIAL);
}

<STRING>\n {
    current_line++;
    current_col = 0;
    BEGIN(INITIAL);
}

<STRING>\\\" {
    current_col += yyleng;
    BEGIN(INITIAL);
}

<STRING><<EOF>> {
    ERRORS_COUNT++;
    printf("Fim da String\n");
    BEGIN(INITIAL);
}

<STRING>. {
    printf("Ainda na String\n");
}

{ID} {
    current_col += yyleng;
    printf("ID (%s) tamanho %d\n", yytext, yyleng ); 
}

{OPERADORES} {
    current_col += yyleng;
    printf("OPERADOR  (%s) tamanho %d\n", yytext, yyleng);
}

{PAREN} {
    current_col += yyleng;
    printf("PARENTESE (%s) tamanho %d\n", yytext, yyleng);
}

{COLCH} {
    current_col += yyleng;
    printf("COLCHETE  (%s) tamanho %d\n", yytext, yyleng);
}

{CHAVES} {
    current_col += yyleng;
    printf("CHAVES    (%s) tamanho %d\n", yytext, yyleng);
}

{SEP} {
    current_col += yyleng;  
}

= {
    
}

{EOL} {
    current_line++;
    current_col = 1;
}

\t* {
    current_col += yyleng;   
}

" "* {
    current_col += yyleng;
}

. { 
    ERRORS_COUNT++;
    strcpy(error.error_type, "NO_SIMBOL");
    strcpy(error.error_message, "Simbolo nao reconhecido pela analise lexica");
    error.line = current_line;
    error.column = current_col;
    showError(yytext);
    error_cnt++;
}

%%

int main( int argc, char **argv ) {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}