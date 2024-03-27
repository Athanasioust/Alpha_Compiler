#ifndef _STRUCTS_H_
#define _STRUCTS_H_


enum SymbolType {
    VAR_GLOBAL,
    VAR_LOCAL,
    VAR_FORMAL,
    USERFUNC,
    LIBFUNC
}; 

// struct to store variables on the symtable
typedef struct Variable {
    char *name;
    unsigned int line;
    unsigned int scope;
} Variable;

// struct to store functions on the symtable
typedef struct Function {
    char *name;
    unsigned int line;
    unsigned int scope;
} Function; 

// struct for the symtable
typedef struct SymbolTableEntry {
    int isActive;
    union {
        Function *funcVal;
        Variable *varVal;
    } value;
    enum SymbolType type;
} SymbolTableEntry;

#endif