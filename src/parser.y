%{
    #include <stdlib.h>
    #include <stdio.h>
	#include <string.h>
	#include <assert.h>
	#include <stdbool.h>
    #include "symtable.h"
    #include "structs.h"
    #include "func_stack.h"
	#include "rule_handler.h"
	#include "parser.h"

    int yyerror(char* message);
    int yylex(void);
    
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;

    SymTable_T head;
    SymTable_T current_table;

    int scope = 0;
    int anon_counter = 0;
%}


%start program

%union {
    double nval;
    char* sval;
    struct SymbolTableEntry* exprval;
}

%token<nval> NUM
%token<sval> IDENT STRING IF ELSE WHILE FOR FUNCTION RETURN BREAK
             CONTINUE AND NOT OR LOCAL TRUE FALSE NIL ASSIGN PLUS
             MINUS MUL DIV MOD EQUAL NEQUAL INC DEC GT LT GET LET
             BRACKET_OPEN BRACKET_CLOSED SQUARE_OPEN SQUARE_CLOSED
             PAR_OPEN PAR_CLOSED SEMI_COLON COMMA COLON DOUBLE_COLON
             DOT DOUBLE_DOT UMINUS
%type<sval> funcname
%type<exprval> lvalue



%left OR
%left AND
%right ASSIGN
%nonassoc EQUAL NEQUAL
%nonassoc GT GET LT LET
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left PLUS MINUS
%left MUL DIV MOD
%left DOT DOUBLE_DOT
%left PAR_OPEN PAR_CLOSED
%left SQUARE_OPEN SQUARE_CLOSED 
%left UMINUS
%right NOT INC DEC

%%

program:        stmts ;

stmts:     stmts stmt 
                |
                ;

stmt:      expr SEMI_COLON
                | ifstmt
                | whilestmt
                | forstmt
                | returnstmt
                | BREAK SEMI_COLON
                | CONTINUE SEMI_COLON
                | block
                | funcdef
                | SEMI_COLON
                ;

expr:     assignexpr
                | expr PLUS expr
                | expr MINUS expr
                | expr MUL expr
                | expr DIV expr
                | expr MOD expr
                | expr GT expr
                | expr GET expr
                | expr LT expr
                | expr LET expr
                | expr EQUAL expr
                | expr NEQUAL expr
                | expr AND expr
                | expr OR expr
                | term
                ;

term:           PAR_OPEN expr PAR_CLOSED
                | UMINUS expr
                | NOT expr
                | INC lvalue            {HANDLE_TERM_TO_INC_LVALUE($2, func_stack_top());}
                | lvalue INC            {HANDLE_TERM_TO_LVALUE_INC($1, func_stack_top());}
                | DEC lvalue            {HANDLE_TERM_TO_DEC_LVALUE($2, func_stack_top());}
                | lvalue DEC            {HANDLE_TERM_TO_LVALUE_DEC($1, func_stack_top());}
                | prim
                ;
    
assignexpr:     lvalue ASSIGN expr{HANDLE_ASSIGNEXPR_TO_LVALUE_ASSIGN_EXPRESSION($1, func_stack_top());};

prim:           lvalue                  {HANDLE_PRIM_TO_LVALUE($1, func_stack_top());}
                | call
                | objectdef
                | PAR_OPEN funcdef PAR_CLOSED
                | const
                ;

lvalue:         IDENT                   {$$ = HANDLE_LVALUE_TO_IDENT(current_table, $1, yylineno, scope);}
                | LOCAL IDENT           {$$ = HANDLE_LVALUE_TO_LOCAL_IDENT(current_table, head, $2, yylineno, scope);}
                | DOUBLE_COLON IDENT    {$$ = HANDLE_LVALUE_TO_GLOBAL_IDENT(head, $2, yylineno, scope);}
                | member                {}
                ;

member:         lvalue DOT IDENT
                | lvalue SQUARE_OPEN expr SQUARE_CLOSED
                | call DOT IDENT
                | call SQUARE_OPEN expr SQUARE_CLOSED
                ;   

call:           call PAR_OPEN elist PAR_CLOSED
                | lvalue callsuffix     
                | PAR_OPEN funcdef PAR_CLOSED PAR_OPEN elist PAR_CLOSED
                ;

callsuffix:     normcall
                | methodcall
                ;

normcall:       PAR_OPEN elist PAR_CLOSED;

methodcall:     DOUBLE_DOT IDENT PAR_OPEN elist PAR_CLOSED ;

elist:          expr elist_alt
                |
                ;

elist_alt:      COMMA expr elist_alt
                | 
                ;

objectdef:      SQUARE_OPEN expr SQUARE_CLOSED
                | SQUARE_OPEN expr COMMA elist SQUARE_CLOSED
                | SQUARE_OPEN indexedelem SQUARE_CLOSED
                | SQUARE_OPEN indexedelem COMMA indexed SQUARE_CLOSED
                | SQUARE_OPEN SQUARE_CLOSED
                ;

indexed:        indexedelem indexed_alt
                |
                ;

indexed_alt:    COMMA indexedelem indexed_alt
                |
                ;

indexedelem:    BRACKET_OPEN expr COLON expr BRACKET_CLOSED ;

block:          BRACKET_OPEN {scope++; current_table = SymTable_next(current_table);} stmts BRACKET_CLOSED {scope--; SymTable_hide(current_table); current_table = SymTable_prev(current_table);};

funcdef:        funcname PAR_OPEN {scope++; current_table = SymTable_next(current_table);} idlist PAR_CLOSED {scope--; current_table = SymTable_prev(current_table); func_stack_push(scope);} block {func_stack_pop();} ;

funcname:       FUNCTION IDENT          {$$ = HANDLE_FUNCTION_WITH_NAME(current_table, $2, yylineno, scope);}
                | FUNCTION              {$$ = HANDLE_FUNCTION_WITHOUT_NAME(current_table, anon_counter++, yylineno, scope);}
                ;

const:          NUM | STRING | NIL | TRUE | FALSE ;

idlist:         IDENT idlist_alt        {HANDLE_IDLIST_IDENT(current_table, $1, yylineno, scope);}
                |
                ;

idlist_alt:     COMMA IDENT idlist_alt  {HANDLE_IDLIST_IDENT(current_table, $2, yylineno, scope);}
                |
                ;

ifstmt:         IF PAR_OPEN expr PAR_CLOSED stmt %prec LOWER_THAN_ELSE
                | IF PAR_OPEN expr PAR_CLOSED stmt ELSE stmt
                ;

whilestmt:      WHILE PAR_OPEN expr PAR_CLOSED stmt       

forstmt:        FOR PAR_OPEN elist SEMI_COLON expr SEMI_COLON elist PAR_CLOSED stmt ;

returnstmt:     RETURN SEMI_COLON
                | RETURN expr SEMI_COLON
                ;

%%

int yyerror(char *message){
    printf("Error at line %d: %s\n", yylineno, message);
    return -1;
}

int main(int argc, char **argv) {
    // Initialize the symbol table
    head = SymTable_new();
    // Set the current table to the head
    current_table = head;

    // Add the library functions to the symbol table
    libFunc(head, "print");
    libFunc(head, "input");
    libFunc(head, "objectmemberkeys");
    libFunc(head, "objecttotalmembers");
    libFunc(head, "totalarguments");
    libFunc(head, "objectcopy");
    libFunc(head, "argument");
    libFunc(head, "typeof");
    libFunc(head, "strtonum");
    libFunc(head, "sin");
    libFunc(head, "sqrt");
    libFunc(head, "cos");
    


	if(argc > 3) {
		fprintf(stderr, "Too many arguments given, please provide only the input and output file");
		exit(0);
	}

    if(argc == 1) {
		yyin = stdin;
    }
	else {
		if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr, "There was an error opening the file, make sure the path is written correctly");
            exit(0);
        }
	}

	if(argc == 3) {
        if(!freopen(argv[2], "w", stdout)) {
            fprintf(stderr, "There was an error writing to the output file, make sure the path is written correctly");
            exit(0);
        }
    }

	yyparse();
    SymTable_print(head);
    return 0;	
}