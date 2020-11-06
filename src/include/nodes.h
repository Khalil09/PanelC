#ifndef INC_NODES
#define INC_NODES

// typedef struct Program Program;
// typedef struct DeclList DeclList;
// typedef struct Decl Decl;
// typedef struct DeclVar DeclVar;
// typedef struct Function Function;
// typedef struct Params Params;
// typedef struct Param Param;
// typedef struct ParamsList ParamsList;
// typedef struct LocalDecl LocalDecl;
// typedef struct CompoundStmt CompoundStmt;
// typedef struct StmtList StmtList;
// typedef struct Stmt Stmt;
// typedef struct Expr Expr;
// typedef struct CondBlock CondBlock;
// typedef struct Iter Iter;
// typedef struct Return Return;
// typedef struct IterTable IterTable;
// typedef struct Variable Variable;
// typedef struct SimpleExpr SimpleExpr;
// typedef struct ExprOp ExprOp;
// typedef struct Term Term;
// typedef struct Factor Factor;
// typedef struct Call Call;
// typedef struct Args Args;
// typedef struct ArgsList ArgsList;
// typedef struct Table Table;
// typedef struct ListTable ListTable;
// typedef struct FactorList FactorList;

typedef struct Program {
    struct DeclList* decl_list;
} Program;

typedef struct DeclList {
    struct DeclList* decl_list;
    struct Decl* decl;
} DeclList;

typedef struct Decl {
    struct DeclVar* decl_var;
    struct Function* function;
} Decl;

typedef struct DeclVar {
    char tipo[50];
    char id[50];
    int num;
} DeclVar;

typedef struct Function {
    char tipo[50];
    char id[50];
    struct Params * params;
    struct CompoundStmt *compound_stmt;
} Function;

typedef struct Params {
    struct ParamsList * params_list;
} Params;

typedef struct ParamsList {
    struct ParamsList * params_list;
    struct Param * param;
} ParamsList;

typedef struct Param {
    char tipo[50];
    char id[50];
    int is_vector;
} Param;

typedef struct LocalDecl {
    struct LocalDecl *local_decl;
    struct DeclVar *decl_var;
} LocalDecl;

typedef struct CompoundStmt {
    struct LocalDecl *local_decl;
    struct StmtList *stmt_list;
} CompoundStmt;

typedef struct StmtList {
    struct StmtList *stmt_list;
    struct Stmt *stmt;
} StmtList;

typedef struct Stmt {
    struct CondBlock *cond_block;
    struct Expr *expr;
    struct Iter *iter;
    struct IterTable *iter_table;
    struct Return *retrn;
} Stmt;

typedef struct Expr {
    struct Variable *variable;
    struct ExprOp *expr_op;
    struct SimpleExpr *simple_expr;
    struct Table *table;
} Expr;

typedef struct CondBlock {
    struct SimpleExpr *simple_expr;
    struct CompoundStmt *compound_stmt;
    struct CompoundStmt *compound_stmt_else;
} CondBlock;

typedef struct Iter {
    struct Expr *expr0;
    struct SimpleExpr *simple_expr;
    struct Expr *expr1;
    struct CompoundStmt *compound_stmt;
} Iter;

typedef struct Return {
    struct Expr *expr;
} Return;

typedef struct IterTable {
    struct Expr *expr;
    struct Variable *variable0;
    struct Variable *variable1;
    struct CompoundStmt *compound_stmt;
} IterTable;

typedef struct Variable {
    struct SimpleExpr *simple_expr;
    char id[50];
    int is_vector;
} Variable;

typedef struct SimpleExpr {
    struct ExprOp *expr_op0;
    char cmdop[3];
    struct ExprOp *expr_op1;
} SimpleExpr;

typedef struct ExprOp {
    struct ExprOp *expr_op;
    struct Term *term;
} ExprOp;

typedef struct Term {
    struct Term *term;
    struct Factor *factor;
} Term;

typedef struct Factor {
    struct ExprOp *exprOp;
    struct Variable *variable;
    struct Call *call;
    int i_val;
    float f_val;
    int tag;
} Factor;

typedef struct Call {
    struct Args *args;
    char id[50];
} Call;

typedef struct ArgsList {
    struct ArgsList *args_list;
    struct Args *args;
    struct SimpleExpr *simple_expr;
} ArgsList;

typedef struct Args {
    struct ArgsList *args_list;
} Args;

typedef struct Table {
    struct Variable* variable;
    struct ListTable *list_table;
} Table;

typedef struct ListTable {
    struct FactorList *factor_list;
    struct ListTable *list_table0;
    struct ListTable *list_table1;
} ListTable;

typedef struct FactorList {
    struct Factor *factor0;
    struct Factor *factor1;
} FactorList;

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

Factor *newFactorNode (ExprOp *exprOp, Variable *variable, Call *call, int i_val, float f_val, int tag);

Call *newCallNode (Args *args, char * id);

ArgsList *newArgsListNode (ArgsList *args_list, Args *args, SimpleExpr* simple_expr);

Args *newArgsNode (ArgsList *args_list);

ListTable *newListTableNode (FactorList *factor_list, ListTable *list_table0, ListTable *list_table1);

Table *newTableNode (Variable *variable, ListTable *list_table);

FactorList *newFactorListNode (Factor *factor0, Factor *factor1);

#endif