typedef struct StoreVariables {
    char* name;                     
    char* type;
    char symbol_type;    
    struct StoreVariables *next, *prev;
} StoreVariables;

typedef struct SymbolTable {
    char* key;                      
    char* name;                     
    char* type;                     
    char* scope;   
    char symbol_type;                                 
    UT_hash_handle hh;             
} SymbolTable; 

typedef struct ScopeStack {
    char name[50];
    struct ScopeStack *next;
} ScopeStack;

ScopeStack* create_scope(char* name);
void scope_push(char *);
char *scope_top();
void free_stack();

StoreVariables* create_variable(char *name, char* type, char symbol_type);
void add_store_variable(char *name, char* type, char symbol_type);
void transfer_to_symbol_table();

SymbolTable* create_symbol(char* key, char *name, char* type, char symbol_type, char* scope);
void add_symbol(char *name, char* type, char symbol_type, char* scope);
void print_symbol_table();
void free_symbol_table();
