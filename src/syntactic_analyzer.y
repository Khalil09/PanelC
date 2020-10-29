%define parse.error verbose
%define api.pure
%code requires {
    #include "include/nodes.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/nodes.h"
#include "include/showTree.h"
#include "include/uthash.h"
#include "include/utstack.h"
#include "include/utlist.h"
#include "include/headerSyntactic.h"

extern int yylineno;
extern int yylex_destroy(void);
extern void yyerror (const char *s);
int yylex();
extern FILE *yyin;
SymbolTable *symbol_table = NULL; 
ScopeStack *stack = NULL; 
StoreVariables *variable_list = NULL;
%}

%union {
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
}

%token <i_val> INT 
%token <f_val> FLOAT
%token <tipo> TIPO 
%token BOOLCONST
%token <str_val> STR_VAL
%token <op> OP
%token <cmdop> CMDOP
%token <teste> SEMI_COL LP RP LCH RCH LC RC COL ATRIB DOUBLEDOT
%token <teste> IF WHILE FOR ELSE ROWS COLUMNS CELLS RETURN
%token <id> ID

%type <_program> program
%type <_decl_list> decl-list
%type <_decl> decl
%type <_decl_var> decl-var
%type <_function> function
%type <_params> params
%type <_params_list> params-list
%type <_param> param
%type <_local_decl> local-decl
%type <_compound_stmt> compound-stmt
%type <_stmt_list> stmt-list
%type <_stmt> stmt
%type <_expr> expr
%type <_cond_block> cond-block
%type <_iter> iter
%type <_retrn> return
%type <_iter_table> iter-table
%type <_variable> variable
%type <_simple_expr> simple-expr
%type <_expr_op> expr-op
%type <_term> term
%type <_factor> factor
%type <_call> call
%type <_args> args
%type <_args_list> args-list
%type <_table> table
%type <_list_table> list-table
%type <_factor_list> factor-list

%left OP CMDOP COL

%start program

%%

program: decl-list { $$ = newProgramNode($1); 
                     print_declList($1, 0); 
                     print_symbol_table(); 
                     free_symbol_table();} ;

decl-list: decl-list decl { $$ = newDeclListNode($1, $2); }
           | decl { $$ = newDeclListNode(NULL, $1); };

decl: decl-var SEMI_COL { $$ = newDeclNode($1,NULL); }
      | function { $$ = newDeclNode(NULL, $1); };

decl-var: TIPO ID SEMI_COL { $$ = newDeclVarNode($1, $2, -1); add_symbol($2, $1, 'V', scope_top()); }
          | TIPO ID LC INT RC SEMI_COL { $$ = newDeclVarNode($1, $2, $4); add_symbol($2, $1, 'A', scope_top()); };

function: TIPO ID LP params RP compound-stmt { scope_push($2); printf("Function %s\n", $2);
                                               $$ = newFunctionNode($2, $1, $4, $6); add_symbol($2, $1, 'F', scope_top()); };

params: params-list { $$ = newParamsNode($1); }
        | {$$ = NULL;};

params-list: params-list COL param { $$ = newParamsListNode($1, $3); }
             | param { $$ = newParamsListNode(NULL, $1); };

param: TIPO ID { $$ = newParamNode($1, $2, 0); add_symbol($2, $1, 'P', scope_top()); } 
       | TIPO ID LC RC { $$ = newParamNode($1, $2, 1); add_symbol($2, $1, 'P', scope_top()); }; 

local-decl: local-decl decl-var { $$ = newLocalDeclNode($1, $2); }
            | {$$ = NULL;};

compound-stmt: LCH local-decl stmt-list RCH { $$ = newCompoundStmtNode($2, $3); };

stmt-list: stmt-list stmt { $$ = newStmtListNode($1, $2); }
           | {$$ = NULL;};

stmt: cond-block { $$ = newStmtNode($1, NULL, NULL, NULL, NULL); }
      | expr SEMI_COL { $$ = newStmtNode(NULL, $1, NULL, NULL, NULL); }
      | iter { $$ = newStmtNode(NULL, NULL, $1, NULL, NULL); }
      | iter-table { $$ = newStmtNode(NULL, NULL, NULL, $1, NULL); }
      | return { $$ = newStmtNode(NULL, NULL, NULL, NULL, $1); };

expr: variable ATRIB expr-op { $$ = newExprNode($1, $3, NULL, NULL);  }
      | simple-expr { $$ = newExprNode(NULL, NULL, $1, NULL); }
      | table { $$ = newExprNode(NULL, NULL, NULL, $1); };

cond-block: IF LP simple-expr RP compound-stmt { $$ = newCondBlockNode($3, $5, NULL); }
            | IF LP simple-expr RP compound-stmt ELSE compound-stmt { $$ = newCondBlockNode($3, $5, $7); };

iter: FOR LP expr SEMI_COL simple-expr SEMI_COL expr RP compound-stmt { $$ = newIterNode($3, $5, $7, $9); };

return: RETURN expr SEMI_COL { $$ = newReturnNode($2); }
        | RETURN SEMI_COL { $$ = newReturnNode(NULL); };

/* Checar a expr do formato da coluna */
iter-table: FOR ROWS LC STR_VAL RC LP variable SEMI_COL variable RP compound-stmt { $$ = newIterTableNode($7, $9, $11); }
            | FOR CELLS LP variable SEMI_COL variable RP compound-stmt { $$ = newIterTableNode($4, $6, $8); };

variable: ID { $$ = newVariableNode(NULL, $1, 0);  }
          | ID LC simple-expr RC  { $$ = newVariableNode($3, $1, 1); };

simple-expr:  expr-op CMDOP expr-op { $$ = newSimpleExprNode($1, $2, $3); }
             | expr-op { char* n_str = "\0"; $$ = newSimpleExprNode($1, n_str, NULL); };

expr-op: expr-op OP term { $$ = newExprOpNode($1, $3); }
         | term { $$ = newExprOpNode(NULL, $1); };

term: term OP factor { $$ = newTermNode($1, $3); }
      | factor { $$ = newTermNode(NULL, $1); };

factor: LP expr RP { $$ = newFactorNode($2, NULL, NULL, 0, 0, 0); }
        | variable { $$ = newFactorNode(NULL, $1, NULL, 0, 0, 0); }
        | call { $$ = newFactorNode(NULL, NULL, $1, 0, 0, 0); }
        | INT { $$ = newFactorNode(NULL, NULL, NULL, $1, 0, 1); }
        | FLOAT { $$ = newFactorNode(NULL, NULL, NULL, 0, $1, 2); };

call: ID LP args RP { $$ = newCallNode($3, $1); };

args: args-list { $$ = newArgsNode($1); }
      | {$$ = NULL;};

args-list: args-list COL args  { $$ = newArgsListNode($1, $3, NULL); }
           | simple-expr  { $$ = newArgsListNode(NULL, NULL, $1); };

table: ID ATRIB LCH list-table RCH SEMI_COL { $$ = newTableNode($1, $4); };

list-table: STR_VAL DOUBLEDOT LC factor-list RC { $$ = newListTableNode($4, NULL, NULL); }
            | list-table COL list-table { $$ = newListTableNode(NULL, $1, $3); } 
            | {$$ = NULL;};   

factor-list: factor COL factor { $$ = newFactorListNode($1, $3); }
             | factor {{ $$ = newFactorListNode($1, NULL); }} 
             | {$$ = NULL;};

%%

void add_store_variable(char *name, char* type, char symbol_type) {
    StoreVariables * s;
    s = create_variable(name, type, symbol_type);
    DL_APPEND(head, name);
} 

StoreVariables* create_variable(char *name, char* type, char symbol_type) {
    StoreVariables *s = (StoreVariables *)malloc(sizeof *s);
    strcpy(s->name, name);
    strcpy(s->type, type);
    strcpy(s->symbol_type, type);
    
    return s;
}

ScopeStack *create_scope(char *name) {
    ScopeStack *s = (ScopeStack *)malloc(sizeof *s);
    strcpy(s->name, name);
    return s;
}

void scope_push(char* scope) {
    ScopeStack *s;
    s = create_scope(scope);
    STACK_PUSH(stack, s);
}

char* scope_top() {
    ScopeStack *s = STACK_TOP(stack);
    char * debug = "NULO";
    if(STACK_EMPTY(stack)) { return debug; }
    return s->name;
}

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 pelo end of string
    strcpy(result, s1);
    strcat(result, "::");
    strcat(result, s2);
    return result;
}

void add_symbol(char *name, char* type, char symbol_type, char* scope) {
    SymbolTable *s;
    char scope_string[100];
    sprintf(scope_string, "%s", scope);
    char *key = concat(name, scope_string);
    HASH_FIND_STR(symbol_table, name, s);
    if(s == NULL){
        s = create_symbol(key, name, type, symbol_type, scope);
        HASH_ADD_STR(symbol_table, name, s);
    }
}

SymbolTable* create_symbol(char* key, char *name, char* type, char symbol_type, char* scope){
    SymbolTable *s = (SymbolTable *)malloc(sizeof *s);
    s->key = strdup(key);
    s->name = strdup(name);
    s->type = strdup(type);
    s->symbol_type = symbol_type;
    s->scope = strdup(scope);
    return s;
}

void print_symbol_table() {
    SymbolTable *s;
    printf("\n\n-------------------------------  Symbol Table -----------------------------\n\n");
    for(s=symbol_table; s != NULL; s=s->hh.next) {
        printf("key: %20s | name: %20s | type: %20s | symbol_type: %c | scope: %s\n", s->key, s->name, s->type, s->symbol_type, s->scope);
    }
}

void free_symbol_table(){
    SymbolTable *s, *tmp;
    HASH_ITER(hh, symbol_table, s, tmp) {
        HASH_DEL(symbol_table, s);
        free(s);
    }
}

int main(int argc, char **argv) {
    scope_push("global");
    ++argv, --argc;
    if(argc > 0)
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;
    yyparse();
    yylex_destroy();
    return 0;
}