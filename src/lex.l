/* Flex options */
%option yylineno
%option noyywrap

%{
    #include <stdlib.h>
    #include <stdio.h>
	#include <string.h>
	#include <assert.h>
	#include <stdbool.h>
    #include "../include/parser.h"
	#include "../include/lex.h"
	
	#ifdef __linux__
	#	define FILE_EOF '\0'
	#else
	#	define FILE_EOF EOF
	#endif
	
	#ifdef DEBUG
	#	define DPRINTF(...) fprintf(stderr, __VA_ARGS__)
	#else
	#	define DPRINTF(...)
	#endif

	
%}

digit   [0-9]
space   [\r\n \t\v]
id      [a-zA-Z][a-zA-Z_0-9]*
string  \"[^\"\\]*(\\.[^\"\\]*)*\"
comment "//".*
multicomment \/\*

%%

"if"            {return IF;}
"else"          {return ELSE;}
"while"         {return WHILE;}
"for"           {return FOR;}
"function"      {return FUNCTION;}
"return"        {return RETURN;}
"break"         {return BREAK;}
"continue"      {return CONTINUE;}
"and"           {return AND;}
"not"           {return NOT;}
"or"            {return OR;}
"local"         {return LOCAL;}
"true"          {return TRUE;}
"false"         {return FALSE;}
"nil"           {return NIL;}
"="             {return ASSIGN;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"%"             {return MOD;}
"=="            {return EQUAL;}
"!="            {return NEQUAL;}
"++"            {return INC;}
"--"            {return DEC;}
">"             {return GT;}
"<"             {return LT;}
">="            {return GET;}
"<="            {return LET;}
"{"             {return BRACKET_OPEN;}
"}"             {return BRACKET_CLOSED;}
"["             {return SQUARE_OPEN;}
"]"             {return SQUARE_CLOSED;}
"("             {return PAR_OPEN;}
")"             {return PAR_CLOSED;}
";"             {return SEMI_COLON;}
","             {return COMMA;}
":"             {return COLON;}
"::"            {return DOUBLE_COLON;}
"."             {return DOT;}
".."            {return DOUBLE_DOT;}


{multicomment} {
	parseMulticomment("COMMENT");
}

{id} {
	yylval.sval = strdup(yytext);
	return IDENT;
}

{string} {
	yylval.sval = strdup(yytext);
	return STRING;
}

{comment} {}

{digit}+ {
	sscanf(yytext, "%lf", &yylval.nval);
	return NUM;
}

{digit}*\.{digit}+ {
	sscanf(yytext, "%lf", &yylval.nval);
	return NUM;
}

{space} {}

. {
	fprintf(stderr, "%d : %s : Unrecognised token\n", yylineno, yytext);
}

%%

void parseMulticomment(char * type) {
    char next;

  //look for the end of the comment
    while(1){
        next = input();

        if(next == EOF){
            printf("EOF, not closing comment");
            exit(0);
        }
    
        char look_ahead;
        if(next == '*'){
            look_ahead = input();

            if(look_ahead == EOF){
              printf("EOF, not closing comment");
                exit(0);
            }

            if(look_ahead == '/'){// end of the comment
        break;
            }
        } else if (next == '/'){//check for nested comments
            look_ahead = input();

            if(look_ahead == EOF){
              printf("EOF, not closing comment");
                exit(0);
            }

            if(look_ahead == '*'){
                parseMulticomment("NESTED_COMMENT");
            }
        }
    }
}