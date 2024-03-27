#include "../include/rule_handler.h"
#include "../include/symtable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Function to create a new function
Function* makeFunc(char* key, int lineno, int scope){
    Function* temp = malloc(sizeof(struct Function));
    temp->name = malloc(sizeof(key) + 1);
    strcpy(temp->name, key);
    temp->line = lineno;
    temp->scope = scope;

	return temp;
}


// Function to create a new library function
void libFunc(SymTable_T head, char* name){
    SymbolTableEntry* temp_entry = malloc(sizeof(struct SymbolTableEntry));
    Function* temp = makeFunc(name, 0, 0);

    temp_entry->isActive = 1;
    temp_entry->type = LIBFUNC;
    temp_entry->value.funcVal = temp;
    
    SymTable_insert(head, name, temp_entry);
}
// Function to check if a variable is legal
int isLegal(int scope, int func_scope){
    return (scope == 0 || scope > func_scope);
}
// Function to check if a variable is a variable
int isVar(SymbolTableEntry* temp){
    return temp->type == VAR_FORMAL || temp->type == VAR_GLOBAL || temp->type == VAR_LOCAL;
}
// Function to create a new variable
Variable* makeVar(char* key, int lineno, int scope){
    Variable* temp = malloc(sizeof(struct Variable));
    temp->name = malloc(sizeof(key) + 1);
    strcpy(temp->name, key);
    temp->line = lineno;
    temp->scope = scope;

    return temp;
}
// Function to count the digits of a number
int countDigits(int num) {
    if (num == 0)
        return 1;

    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to handle a function call (term to lvalue dec) FIXED
void HANDLE_TERM_TO_LVALUE_DEC(SymbolTableEntry* entry, int func_scope){

    if (!entry || isLegal(entry->value.varVal->scope, func_scope)) return;

    if(!isVar(entry)){
        fprintf(stderr, "The function '%s' cannot be referenced before the decrement operator.\n", entry->value.funcVal->name);
        return;
    }
    
    fprintf(stderr, "The variable '%s' in scope %d cannot be accessed because of a function declaration in scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}
// Function to handle a function call (prim to lvalue) FIXED
void HANDLE_PRIM_TO_LVALUE(SymbolTableEntry* entry, int func_scope){
    if (!entry || !isVar(entry) || isLegal(entry->value.varVal->scope, func_scope)) return;
    fprintf(stderr, "The variable '%s' in scope %d is not accessible due to a function declaration in scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);
    return;
}

// Function to handle a function call (lvalue to global ident) FIXED
SymbolTableEntry* HANDLE_LVALUE_TO_GLOBAL_IDENT(SymTable_T global, char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = SymTable_lookup_here(global, key))) return temp;

    fprintf(stderr, "The name '%s' was referenced as '::%s', but it was not found in the global scope.\n", key, key);

    return NULL;
}

// Function to handle a function call (assignexpr to lvalue assign expression) FIXED
void HANDLE_ASSIGNEXPR_TO_LVALUE_ASSIGN_EXPRESSION(SymbolTableEntry* entry, int func_scope){

    if (!entry || isLegal(entry->value.varVal->scope, func_scope)) return;

    if(!isVar(entry)){
        fprintf(stderr, "The function '%s' cannot be assigned to as an lvalue.\n", entry->value.funcVal->name);
        return;
    }

fprintf(stderr, "The variable '%s' in scope %d is inaccessible due to a function declaration in scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

// Function to handle a function call (lvalue to local ident)
SymbolTableEntry* HANDLE_LVALUE_TO_LOCAL_IDENT(SymTable_T table, SymTable_T global, char* key, int lineno, int scope){

    SymbolTableEntry* temp;
    
    if((temp = SymTable_lookup_here(table, key))) return temp;

    if((temp = SymTable_lookup_here(global, key)) && temp->type == LIBFUNC){
        fprintf(stderr, "The library function '%s' cannot be shadowed by a local variable.\n", temp->value.funcVal->name);
        return NULL;
    }

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = (scope ? VAR_LOCAL : VAR_GLOBAL);
    temp->value.varVal = makeVar(key, lineno, scope);

    return SymTable_insert(table, key, temp);
}
// Function to handle a function call (idlist ident)
char* HANDLE_IDLIST_IDENT(SymTable_T table, char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = SymTable_lookup_here(table, key))){
        fprintf(stderr, "Formal argument %s already defined in the same id_list.\n", key);
        return NULL;
    }

    if((temp = SymTable_lookup(table, key))){
        if(!isVar(temp)){
            fprintf(stderr, "Function with name %s is active, can't initialize formal argument with same name,function already exists.\n", key);
            return NULL;
        }
    }

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = VAR_FORMAL;

    temp->value.varVal = makeVar(key, lineno, scope);

    SymTable_insert(table, key, temp);

    return temp->value.varVal->name;
}

// Function to handle a function call (function without name)
char* HANDLE_FUNCTION_WITHOUT_NAME(SymTable_T table, int anon_count, int lineno, int scope){
    SymbolTableEntry* temp;
    char* funcname = malloc(countDigits(anon_count) + 2);

    sprintf(funcname, "$%d", anon_count);

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = USERFUNC;

    temp->value.funcVal = makeFunc(funcname, lineno, scope);

    SymTable_insert(table, funcname, temp);

	return temp->value.funcVal->name;
}
// Function to handle a function call (term to inc lvalue ) FIXED
void HANDLE_TERM_TO_INC_LVALUE(SymbolTableEntry* entry, int func_scope){
    if (!entry || isLegal(entry->value.varVal->scope, func_scope)) return;

    if(!isVar(entry)){
        fprintf(stderr, "The function '%s' cannot be referenced after the increment operator.\n", entry->value.funcVal->name);
        return;
    }

fprintf(stderr, "The variable '%s' in scope %d is inaccessible because of a function declaration in scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}
// Function to handle a function call (term to lvalue inc) FIXED
void HANDLE_TERM_TO_LVALUE_INC(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "The function '%s' cannot be referenced before the increment operator.\n", entry->value.funcVal->name);
        return;
    }

    if(isLegal(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "The variable '%s' in scope %d is inaccessible because of a function declaration in scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}

// Function to handle a function call (term to dec lvalue) FIXED
void HANDLE_TERM_TO_DEC_LVALUE(SymbolTableEntry* entry, int func_scope){
    if(!entry) return;

    if(!isVar(entry)){
        fprintf(stderr, "The function %s cannot be referenced after the -- operator.\n", entry->value.funcVal->name);
        return;
    }

    if(isLegal(entry->value.varVal->scope, func_scope)) return;

    fprintf(stderr, "Variable %s at scope %d is inaccessible due to function declaration at scope %d.\n", entry->value.varVal->name, entry->value.varVal->scope, func_scope);

    return;
}
// Function to handle a function call (function with name) FIXED
char* HANDLE_FUNCTION_WITH_NAME(SymTable_T table, char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = SymTable_lookup(table, key))){


        if(temp->value.funcVal->scope == scope){
            fprintf(stderr, "Cannot redefine the function %s with the same name.\n", key);
            return NULL;
        }
        
        if(temp->type == LIBFUNC){
            fprintf(stderr, "Cannot overwrite library function %s.\n", key);
            return NULL;
        }

        if(isVar(temp)){
        fprintf(stderr, "Cannot redefine %s as a function because it is already a variable.\n", key);
            return NULL;
        }
    } 

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->type = USERFUNC;
    temp->isActive = 1;
    
    temp->value.funcVal = makeFunc(key, lineno, scope);

    SymTable_insert(table, key, temp);

	return temp->value.funcVal->name;
}

// Function to handle a function call (lvalue to ident) NO CHANGE
SymbolTableEntry* HANDLE_LVALUE_TO_IDENT(SymTable_T table, char* key, int lineno, int scope){
    SymbolTableEntry* temp;

    if((temp = SymTable_lookup(table, key))) return temp;

    temp = malloc(sizeof(struct SymbolTableEntry));
    temp->isActive = 1;
    temp->type = (scope ? VAR_LOCAL : VAR_GLOBAL);

    temp->value.varVal = makeVar(key, lineno, scope);

    return SymTable_insert(table, key, temp);
}