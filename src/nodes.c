#include "include/nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Program * newProgramNode (DeclList * decl_list);
DeclList * newDeclListNode (DeclList * decl_list, Decl * decl);

Decl * newDeclNode (DeclVar * decl_var, Function *function);

DeclVar * newDeclVarNode (char* tipo, char* id, int num);

Function * newFunctionNode (char* id, char* tipo, Params *params, CompoundStmt *compound_stmt);

Params * newParamsNode (ParamsList *params_list);

ParamsList * newParamsListNode (ParamsList *params_list, Param *param);

Param *newParamNode (char* id, char* tipo, int is_vector);

LocalDecl *newLocalDeclNode (LocalDecl *local_decl, DeclVar *decl_var);

CompoundStmt *newCompoundStmtNode (LocalDecl *local_decl, StmtList *stmt_list);

StmtList *newStmtListNode (StmtList *stmt_list, Stmt *stmt);

Stmt *newStmtNode (CondBlock *cond_block, Expr *expr, Iter *iter, IterTable *iter_table, Return *retrn);

Expr *newExprNode (Variable *variable, ExprOp *expr_op, SimpleExpr *simple_expr, Table *table);

CondBlock *newCondBlockNode (SimpleExpr *simple_expr, CompoundStmt *compound_stmt, CompoundStmt *compound_stmt_else);

Iter *newIterNode (Expr *expr0, SimpleExpr *simple_expr, Expr *expr1, CompoundStmt *compound_stmt);

IterTable *newIterTableNode (Variable *var0, Variable *var1, CompoundStmt *compound_stmt);

Return *newReturnNode (Expr *expr);

Variable *newVariableNode (SimpleExpr *simple_expr, char* id, int is_vector);

SimpleExpr *newSimpleExprNode (ExprOp *expr_op0,  char* cmdop, ExprOp *expr_op1);

ExprOp *newExprOpNode (ExprOp *expr_op, Term *term);

Term *newTermNode (Term *term, Factor *factor);

Factor *newFactorNode (Expr *expr, Variable *variable, Call *call, int i_val, float f_val, int tag);

Call *newCallNode (Args *args, char * id);

ArgsList *newArgsListNode (ArgsList *args_list, Args *args, SimpleExpr* simple_expr);

Args *newArgsNode (ArgsList *args_list);

ListTable *newListTableNode (FactorList *factor_list, ListTable *list_table0, ListTable *list_table1);

Table *newTableNode (char *id, ListTable *list_table);

FactorList *newFactorListNode (Factor *factor0, Factor *factor1);

Program * newProgramNode (DeclList * decl_list) {
    Program * node = malloc(sizeof(Program));
    node->decl_list = decl_list;

    return node;  
}

DeclList * newDeclListNode (DeclList * decl_list, Decl * decl) {
    DeclList * node = malloc(sizeof(DeclList));
    node->decl_list = decl_list;
    node->decl = decl;

    return node;  
}

Decl * newDeclNode (DeclVar * decl_var, Function *function) {
    Decl * node = malloc(sizeof(Decl));
    node->decl_var = decl_var;
    node->function = function;

    return node;  
}

DeclVar * newDeclVarNode (char* tipo, char* id, int num) {
    DeclVar * node = malloc(sizeof(DeclVar));
    strcpy(node->tipo, tipo);
    strcpy(node->id, id);
    node->num = num;
    /* Alguma operação com a tabela de simbolos */
    return node;  
}

Function * newFunctionNode (char* id, char* tipo, Params *params, CompoundStmt *compound_stmt) {
    Function * node = malloc(sizeof(Function));
    strcpy(node->id, id);
    strcpy(node->tipo, tipo);
    node->params = params;
    node->compound_stmt = compound_stmt;
    
    return node;
}

Params * newParamsNode (ParamsList *params_list) {
    Params * node = malloc(sizeof(Params));
    node->params_list = params_list;
    
    return node;
}

ParamsList * newParamsListNode (ParamsList *params_list, Param *param) {
    ParamsList * node = malloc(sizeof(ParamsList));
    node->params_list = params_list;
    node->param = param;
    
    return node;
}

Param *newParamNode (char* id, char* tipo, int is_vector) {
    Param * node = malloc(sizeof(Param));
    strcpy(node->id, id);
    strcpy(node->tipo, tipo);
    node->is_vector = is_vector;
    
    return node;
}

LocalDecl *newLocalDeclNode (LocalDecl *local_decl, DeclVar *decl_var) {
    LocalDecl * node = malloc(sizeof(LocalDecl));
    node->local_decl = local_decl;
    node->decl_var = decl_var;
    
    return node;
}

CompoundStmt *newCompoundStmtNode (LocalDecl *local_decl, StmtList *stmt_list) {
    CompoundStmt * node = malloc(sizeof(CompoundStmt));
    node->local_decl = local_decl;
    node->stmt_list = stmt_list;
    
    return node;
}

StmtList *newStmtListNode (StmtList *stmt_list, Stmt *stmt) {
    StmtList * node = malloc(sizeof(StmtList));
    node->stmt_list = stmt_list;
    node->stmt = stmt;
    
    return node;
}

Stmt *newStmtNode (CondBlock *cond_block, Expr *expr, Iter *iter, IterTable *iter_table, Return *retrn) {
    Stmt * node = malloc(sizeof(Stmt));
    node->cond_block = cond_block;
    node->expr = expr;
    node->iter = iter;
    node->iter_table = iter_table;
    node->retrn = retrn;
    
    return node;
}

Expr *newExprNode (Variable *variable, ExprOp *expr_op, SimpleExpr *simple_expr, Table *table) {
    Expr * node = malloc(sizeof(Expr));
    node->variable = variable;
    node->expr_op = expr_op;
    node->simple_expr = simple_expr;
    node->table = table;
    
    return node;
}

CondBlock *newCondBlockNode (SimpleExpr *simple_expr, CompoundStmt *compound_stmt, CompoundStmt *compound_stmt_else) {
    CondBlock * node = malloc(sizeof(CondBlock));
    node->simple_expr = simple_expr;
    node->compound_stmt = compound_stmt;
    node->compound_stmt_else = compound_stmt_else;
    
    return node;
}

Iter *newIterNode (Expr *expr0, SimpleExpr *simple_expr, Expr *expr1, CompoundStmt *compound_stmt) {
    Iter *node = malloc(sizeof(Iter));
    node->expr0 = expr0;
    node->simple_expr = simple_expr;
    node->expr1 = expr1;
    node->compound_stmt = compound_stmt;
    
    return node;
}

IterTable *newIterTableNode (Variable *var0, Variable *var1, CompoundStmt *compound_stmt) {
    IterTable *node = malloc(sizeof(IterTable));
    node->variable0 = var0;
    node->variable1 = var1;
    node->compound_stmt = compound_stmt;
    
    return node;
}

Return *newReturnNode (Expr *expr) {
    Return *node = malloc(sizeof(Return));
    node->expr = expr;
    
    return node;
}

Variable *newVariableNode (SimpleExpr *simple_expr, char* id, int is_vector) {
    Variable *node = malloc(sizeof(Variable));
    strcpy(node->id, id);
    node->is_vector = is_vector;
    node->simple_expr = simple_expr;
    
    return node;
}

SimpleExpr *newSimpleExprNode (ExprOp *expr_op0,  char* cmdop, ExprOp *expr_op1) {
    SimpleExpr *node = malloc(sizeof(SimpleExpr));
    node->expr_op0 = expr_op0;
    node->expr_op1 = expr_op1;
    strcpy(node->cmdop, cmdop);
    
    return node;
}

ExprOp *newExprOpNode (ExprOp *expr_op, Term *term) {
    ExprOp *node = malloc(sizeof(ExprOp));
    node->expr_op = expr_op;
    node->term = term;
    
    return node;
}

Term *newTermNode (Term *term, Factor *factor) {
    Term *node = malloc(sizeof(Term));
    node->term = term;
    node->factor = factor;
    
    return node;
}

Factor *newFactorNode (Expr *expr, Variable *variable, Call *call, int i_val, float f_val, int tag) {
    Factor *node = malloc(sizeof(Factor));
    node->expr = expr;
    node->variable = variable;
    node->call = call;
    node->tag = tag;
    node->f_val = f_val;
    node->i_val = i_val;
    
    return node;
}

Call *newCallNode (Args *args, char * id) {
    Call *node = malloc(sizeof(Call));
    strcpy(node->id, id);
    node->args = args;
    
    return node;
}

ArgsList *newArgsListNode (ArgsList *args_list, Args *args, SimpleExpr* simple_expr) {
    ArgsList *node = malloc(sizeof(ArgsList));
    node->args = args;
    node->args_list = args_list;
    node->simple_expr = simple_expr;
    
    return node;
}

Args *newArgsNode (ArgsList *args_list) {
    Args *node = malloc(sizeof(Args));
    node->args_list = args_list;
    
    return node;
}

ListTable *newListTableNode (FactorList *factor_list, ListTable *list_table0, ListTable *list_table1) {
    ListTable *node = malloc(sizeof(ListTable));
    node->factor_list = factor_list;
    node->list_table0 = list_table0;
    node->list_table1 = list_table1;
    
    return node;
}

Table *newTableNode (char *id, ListTable *list_table) {
    Table *node = malloc(sizeof(Table));
    strcpy(node->id, id);
    node->list_table = list_table;
    
    return node;
}

FactorList *newFactorListNode (Factor *factor0, Factor *factor1) {
    FactorList *node = malloc(sizeof(FactorList));
    node->factor0 = factor0;
    node->factor1 = factor1;
    
    return node;
}