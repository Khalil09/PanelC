#include "include/showTree.h"
#include "include/nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tabPrinter(int tabs){
  char *p = malloc(sizeof(char) * tabs+1);
  memset(p, ' ', tabs);
  p[tabs] = '\0';  
  printf("%s", p);
  free(p);
}

void print_param(Param *root, int tabs) {
    tabPrinter(tabs);
    printf("<param> ");
    printf("ID: %s / ", root->id);
    printf("type: %s / ", root->tipo);
    printf("isvector: %d\n", root->is_vector);
    free(root);
}

void print_paramsList(ParamsList *root, int tabs) {
    tabPrinter(tabs);
    printf("<params-list>\n");
    if (root->params_list != NULL) {
        print_paramsList(root->params_list, tabs+1);
    }
    if (root->param) {
        print_param(root->param, tabs+1);
    }
    free(root);
}

void print_params(Params* root, int tabs) {
    tabPrinter(tabs);
    printf("<params>\n");
    if (root->params_list != NULL) {
        print_paramsList(root->params_list, tabs+1);
    }
    free(root);
}

void print_localDecl(LocalDecl *root, int tabs) {
    tabPrinter(tabs);
    printf("<local-decl>\n");
    if (root->local_decl != NULL) {
        print_localDecl(root->local_decl, tabs+1);
    }
    if (root->decl_var != NULL) {
        print_declVar(root->decl_var, tabs+1);
    }
    free(root);
}

void print_variable(Variable *root, int tabs) {
    tabPrinter(tabs);
    printf("<variable> ");
    printf("ID: %s / ", root->id);
    printf("isvector: %d\n", root->is_vector);
    if (root->simple_expr != NULL) {
        print_simpleExpr(root->simple_expr, tabs+1);
    }
    free(root);
}

void print_argsList(ArgsList *root, int tabs) {
    tabPrinter(tabs);
    printf("<args-list>\n");
    if (root->args_list != NULL) {
        print_argsList(root->args_list, tabs+1);
    }
    if (root->args != NULL) {
        print_args(root->args, tabs+1);
    }
    if (root->simple_expr != NULL) {
        print_simpleExpr(root->simple_expr, tabs+1);
    }
    free(root);
}

void print_args(Args *root, int tabs) {
    tabPrinter(tabs);
    printf("<args>\n");
    if (root->args_list != NULL) {
        print_argsList(root->args_list, tabs+1);
    }
    free(root);
}

void print_call(Call *root, int tabs) {
    tabPrinter(tabs);
    printf("<call> ");
    printf("ID: %s / \n", root->id);
    if (root->args != NULL) {
        print_args(root->args, tabs+1);
    }
    free(root);
}

void print_factor(Factor *root, int tabs) {
    tabPrinter(tabs);
    printf("<term>");
    if (root->expr != NULL) {
        printf("\n");
        print_expr(root->expr, tabs+1);
    }
    if (root->variable) {
        printf("\n");
        print_variable(root->variable, tabs+1);
    }
    if (root->call) {
        printf("\n");
        print_call(root->call, tabs+1);
    }
    if (root->tag == 1) {
        printf(" %d\n", root->i_val);
    } else if (root->tag == 2) {
        printf(" %f\n", root->f_val);
    }
    free(root);
}

void print_term(Term *root, int tabs) {
    tabPrinter(tabs);
    printf("<term>\n");
    if (root->term != NULL) {
        print_term(root->term, tabs+1);
    }
    if (root->factor != NULL) {
        print_factor(root->factor, tabs+1);
    }
    free(root);
}

void print_exprOp(ExprOp *root, int tabs) {
    tabPrinter(tabs);
    printf("<expr-op>\n");
    if (root->expr_op != NULL) {
        print_exprOp(root->expr_op, tabs+1);
    }
    if (root->term != NULL) {
        print_term(root->term, tabs+1);
    }
    free(root);
}

void print_simpleExpr(SimpleExpr *root, int tabs) {
    tabPrinter(tabs);
    printf("<simple-expr>\n");
    if (root->cmdop[0] != '\0') {
        tabPrinter(tabs+1);
        printf("[%s]\n", root->cmdop);
    }
    if (root->expr_op0 != NULL) {
        print_exprOp(root->expr_op0, tabs+2);
    }
    if (root->expr_op1 != NULL) {
        print_exprOp(root->expr_op1, tabs+2);
    }
    free(root);
}

void print_condBlock(CondBlock *root, int tabs) {
    tabPrinter(tabs);
    printf("<cond-block>\n");
    if (root->simple_expr != NULL) {
        print_simpleExpr(root->simple_expr, tabs+1);
    }
    if (root->compound_stmt != NULL) {
        print_compoundStmt(root->compound_stmt, tabs+1);
    }
    if (root->compound_stmt_else != NULL) {
        print_compoundStmt(root->compound_stmt_else, tabs+1);
    }
    free(root);
}

void print_expr(Expr *root, int tabs) {
    tabPrinter(tabs);
    printf("<expr>\n");
    if (root->variable != NULL) {
        tabPrinter(tabs+1);
        printf("[=]\n");
        print_variable(root->variable, tabs+2);
        print_exprOp(root->expr_op, tabs+2);
    } else if (root->simple_expr != NULL) {
        print_simpleExpr(root->simple_expr, tabs+1);
    } else if (root->table != NULL) {
        print_table(root->table, tabs+1);
    }
    free(root);
}

void print_factorList(FactorList *root, int tabs) {
    tabPrinter(tabs);
    printf("<expr>\n");
    if (root->factor0 != NULL) {
        print_factor(root->factor0, tabs+1);
    } 
    if (root->factor1 != NULL) {
        print_factor(root->factor1, tabs+1);
    }
    free(root);
}

void print_listTable(ListTable *root, int tabs) {
    tabPrinter(tabs);
    printf("<list-table>\n");
    if (root->factor_list != NULL) {
        print_factorList(root->factor_list, tabs+1);
    } 
    if (root->list_table0 != NULL) {
        print_listTable(root->list_table0, tabs+1);
    }
    if (root->list_table1 != NULL) {
        print_listTable(root->list_table1, tabs+1);
    }
    free(root);
}

void print_table(Table *root, int tabs) {
    tabPrinter(tabs);
    printf("<table>");
    printf(" ID: %s\n", root->id);
    if (root->list_table != NULL) {
        print_listTable(root->list_table, tabs+1);
    }
    free(root);
}

void print_iterTable(IterTable *root, int tabs) {
    tabPrinter(tabs);
    printf("<iterTable>\n");
    if (root->variable0) {
        print_variable(root->variable0, tabs+1);
    }
    if (root->variable1) {
        print_variable(root->variable1, tabs+1);
    }
    if (root->compound_stmt) {
        print_compoundStmt(root->compound_stmt, tabs+1);
    }
    free(root);
}

void print_iter(Iter *root, int tabs) {
    tabPrinter(tabs);
    printf("<iter>\n");
    if (root->expr0 != NULL) {
        print_expr(root->expr0, tabs+1);
    }
    if (root->simple_expr != NULL) {
        print_simpleExpr(root->simple_expr, tabs+1);
    }
    if (root->expr1 != NULL) {
        print_expr(root->expr1, tabs+1);
    }
    if (root->compound_stmt != NULL) {
        print_compoundStmt(root->compound_stmt, tabs+1);
    }
    free(root);
}

void print_return(Return *root, int tabs) {
    tabPrinter(tabs);
    printf("<return>\n");
    if (root->expr != NULL) {
        print_expr(root->expr, tabs+1);
    }
}

void print_stmt(Stmt *root, int tabs) {
    tabPrinter(tabs);
    printf("<stmt>\n");
    if (root->cond_block != NULL) {
        print_condBlock(root->cond_block, tabs+1);
    } else if (root->expr != NULL) {
        print_expr(root->expr, tabs+1);
    } else if (root->iter != NULL) {
        print_iter(root->iter, tabs+1);
    } else if (root->iter_table != NULL) {
        print_iterTable(root->iter_table, tabs+1);
    } else if (root->retrn != NULL) {
        print_return(root->retrn, tabs+1);
    }
    free(root);
}

void print_stmtList(StmtList *root, int tabs) {
    tabPrinter(tabs);
    printf("<stmt-list>\n");
    if (root->stmt_list != NULL) {
        print_stmtList(root->stmt_list, tabs+1);
    }
    if (root->stmt != NULL) {
        print_stmt(root->stmt, tabs+1);
    }
    free(root);
}

void print_compoundStmt(CompoundStmt *root, int tabs) {
    tabPrinter(tabs);
    printf("<compound-stmt>\n");
    if (root->local_decl != NULL) {
        print_localDecl(root->local_decl, tabs+1);
    }
    if (root->stmt_list != NULL) {
        print_stmtList(root->stmt_list, tabs+1);
    }
    free(root);
}

void print_function(Function *root, int tabs) {
    tabPrinter(tabs);
    printf("<function>");
    printf(" id: %s /", root->id);
    printf(" type: %s \n", root->tipo);
    if (root->params != NULL) {
        print_params(root->params, tabs+1);
    }
    if (root->compound_stmt != NULL) {
        print_compoundStmt(root->compound_stmt, tabs+1);
    }
    free(root);
}

void print_declVar(DeclVar *root, int tabs) {
    tabPrinter(tabs);
    printf("<declVar> ");
    printf("/ type: %s ", root->tipo);
    printf("/ id: %s ", root->id);
    printf("/ is_vector?: %d\n", root->num);
    free(root);
}

void print_decl(Decl *root, int tabs) {
    tabPrinter(tabs);
    printf("<decl>\n");
    if (root->function != NULL) {
        print_function(root->function, tabs+1);
    }
    if (root->decl_var != NULL) {
        print_declVar(root->decl_var, tabs+1);
    }
    free(root);
}

void print_declList(DeclList *root, int tabs) {
    tabPrinter(tabs);
    printf("<decl-list>\n");
    if (root->decl != NULL) {
        print_decl(root->decl, tabs+1);
    }
    if (root->decl_list != NULL) {
        print_declList(root->decl_list, tabs+1);
    }
    free(root);
}