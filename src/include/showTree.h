#ifndef INC_SHOW_TREE
#define INC_SHOW_TREE

#include "nodes.h"

void print_param(Param *root, int tabs);
void print_paramsList(ParamsList *root, int tabs);
void print_params(Params* root, int tabs);
void print_localDecl(LocalDecl *root, int tabs);
void print_variable(Variable *root, int tabs);
void print_argsList(ArgsList *root, int tabs);
void print_args(Args *root, int tabs);
void print_call(Call *root, int tabs);
void print_factor(Factor *root, int tabs);
void print_term(Term *root, int tabs);
void print_exprOp(ExprOp *root, int tabs);
void print_simpleExpr(SimpleExpr *root, int tabs);
void print_condBlock(CondBlock *root, int tabs);
void print_expr(Expr *root, int tabs);
void print_factorList(FactorList *root, int tabs);
void print_listTable(ListTable *root, int tabs);
void print_table(Table *root, int tabs);
void print_iterTable(IterTable *root, int tabs);
void print_iter(Iter *root, int tabs);
void print_stmt(Stmt *root, int tabs);
void print_stmtList(StmtList *root, int tabs);
void print_compoundStmt(CompoundStmt *root, int tabs);
void print_function(Function *root, int tabs);
void print_declVar(DeclVar *root, int tabs);
void print_decl(Decl *root, int tabs);
void print_declList(DeclList *root, int tabs);

#endif