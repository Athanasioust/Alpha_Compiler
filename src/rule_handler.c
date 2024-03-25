#include "../include/rule_handler.h"
#include "../include/symbol_table.h"
#include "symbol_table.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int anonymous_counter = 0;

int isVar(SymbolTableEntry* temp){
    return temp->type == FORMAL || temp->type == GLOBAL || temp->type == LOCAL;
}

Variable* makeVar(char* key, int lineno, int scope){
    Variable* temp = malloc(sizeof(struct Variable));
    temp->name = malloc(sizeof(key) + 1);
    strcpy(temp->name, key);
    temp->line = lineno;
    temp->scope = scope;

    return temp;
}

Function* makeFunc(char* key, int lineno, int scope){
    Function* temp = malloc(sizeof(struct Function));
    temp->name = malloc(sizeof(key) + 1);
    strcpy(temp->name, key);
    temp->line = lineno;
    temp->scope = scope;

	return temp;
}

int isLegalScope(int scope, int func_scope){
    return (scope == 0 || scope > func_scope);
}

int countDigits(int num){
    int count = 0;
    while(num){
        num /= 10;
        count++;
    }

    return count;
}
// Function to insert a library function token into the symbol table
void insertLibFunction(const char* name) {
    // Create a Function token for the library function
    Function* func = makeFunc(name, 0, 0); // Line number and scope are set to 0 for library functions

    // Create a SymbolTableEntry for the function
    SymbolTableEntry entry;
    entry.isActive = true; // Set the entry as active
    entry.type = LIBFUNC; // Set the type of symbol as LIBFUNC
    entry.value.funcVal = func; // Assign the function to the value field of the entry

    // Insert the token into the symbol table
    insert(entry);
}

SymbolTableEntry* HANDLE_LVALUE_TO_IDENT(char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = lookup(key))) return temp;

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = (scope ? LOCAL : GLOBAL);

    temp->value.varVal = makeVar(key, lineno, scope);

    insert(*temp);
    return temp;
}

SymbolTableEntry* HANDLE_LVALUE_TO_LOCAL_IDENT(char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = lookupScope(key, scope))) return temp;

    if((temp = lookupScope(key, scope)) && temp->type == LIBFUNC){
        fprintf(stderr, "Library function %s can't be shadowed by local variable\n", temp->value.funcVal->name);
        return NULL;
    }

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = (scope ? LOCAL : GLOBAL);

    temp->value.varVal = makeVar(key, lineno, scope);

    insert(*temp);
    return temp;
}

SymbolTableEntry* HANDLE_LVALUE_TO_GLOBAL_IDENT(char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = lookupScope(key, scope))) return temp;

    fprintf(stderr, "Name %s was not found in the global scope but was referenced as ::%s\n", key ,key);

    return NULL;
}

void HANDLE_ASSIGNEXPR_TO_LVALUE_ASSIGN_EXPRESSION(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "Function %s can't be an lvalue to an assignment\n", entry->value.funcVal->name);
        return;
    }

    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

char* HANDLE_IDLIST_IDENT(char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = lookupScope(key, scope))){
        fprintf(stderr, "Formal argument %s already defined in the same id_list\n", key);
        //fprintf(stderr, "Variable %s already declared in scope %d\n", key, scope);
        return NULL;
    }

    if((temp = lookupScope(key, scope))){
        if(!isVar(temp)){
            fprintf(stderr, "Function with name %s is active, can't initialize formal argument with same name\n", key);
            return NULL;
        }
    }

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = FORMAL;

    temp->value.varVal = makeVar(key, lineno, scope);

    insert(*temp);
    return key;
}

char* HANDLE_FUNCTION_WITH_NAME(char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = SymTable_lookup(key, scope))){
        if(isVar(temp)){
            fprintf(stderr, "Can't redefine variable %s as function\n", key);
            return NULL;
        }

        if(temp->type == LIBFUNC){
            fprintf(stderr, "Can't overshadow library function %s\n", key);
            return NULL;
        }

        if(temp->value.funcVal->scope == scope){
            fprintf(stderr, "Can't redefine the same function %s\n", key);
            return NULL;
        }
    }

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = USERFUNC;

    temp->value.funcVal = makeFunc(key, lineno, scope);

    insert(*temp);
    return key;
}

char* HANDLE_FUNCTION_WITHOUT_NAME(int anon_count, int lineno, int scope){
    SymbolTableEntry* temp;
    char* funcname = malloc(countDigits(anon_count) + 2);
    sprintf(funcname, "f%d", anon_count);

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = USERFUNC;

    temp->value.funcVal = makeFunc(funcname, lineno, scope);

    insert(*temp);
    return funcname;
}

void HANDLE_TERM_TO_INC_LVALUE(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "Function %s can't be referenced after ++ operator\n", entry->value.funcVal->name);
        return;
    }

    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

void HANDLE_TERM_TO_LVALUE_INC(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "Function %s can't be referenced before ++ operator\n", entry->value.funcVal->name);
        return;
    }

    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

void HANDLE_TERM_TO_DEC_LVALUE(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "Function %s can't be referenced after -- operator\n", entry->value.funcVal->name);
        return;
    }

    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

void HANDLE_TERM_TO_LVALUE_DEC(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "Function %s can't be referenced before -- operator\n", entry->value.funcVal->name);
        return;
    }

    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

void HANDLE_PRIM_TO_LVALUE(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)) return;


    if(isLegalScope(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}