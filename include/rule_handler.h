#ifndef _RULE_HANDLERS_H_
#define _RULE_HANDLERS_H_

#include "symbol_table.h"

SymbolTableEntry* HANDLE_LVALUE_TO_IDENT(char*, int, int);
SymbolTableEntry* HANDLE_LVALUE_TO_LOCAL_IDENT(char*, int, int);
SymbolTableEntry* HANDLE_LVALUE_TO_GLOBAL_IDENT(char*, int, int);
void HANDLE_ASSIGNEXPR_TO_LVALUE_ASSIGN_EXPRESSION(SymbolTableEntry* entry, int func_scope);
char* HANDLE_IDLIST_IDENT(char* key, int lineno, int scope);
char* HANDLE_FUNCTION_WITH_NAME(char* key, int lineno, int scope);
char* HANDLE_FUNCTION_WITHOUT_NAME(int anon_count, int lineno, int scope);
void HANDLE_TERM_TO_INC_LVALUE(SymbolTableEntry* entry, int func_scope);
void HANDLE_TERM_TO_LVALUE_INC(SymbolTableEntry* entry, int func_scope);
void HANDLE_TERM_TO_DEC_LVALUE(SymbolTableEntry* entry, int func_scope);
void HANDLE_TERM_TO_LVALUE_DEC(SymbolTableEntry* entry, int func_scope);
void HANDLE_PRIM_TO_LVALUE(SymbolTableEntry* entry, int func_scope);

#endif  // _RULE_HANDLERS_H_