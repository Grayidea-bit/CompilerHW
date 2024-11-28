%{
    #include<stdio.h>
    #include<stdlib.h> // Required for atof
    void yyerror(char *msg);
    extern int yylex();
%}

%union {
    int intValue; // Integer type for numbers
}

%token <intValue> Realnumber
%token Plus Minus Mult Div Left Right
%type <intValue> expression factor primary

%%

statement :
    /* empty */
	|	statement expression
	|	statement expression '\n'
	;		

expression :
    expression Plus factor   
        { $$ = $1 + $3; printf("%d add %d is %d\n", $1, $3, $$); }
    | expression Minus factor   
        { $$ = $1 - $3; printf("%d cut %d is %d\n", $1, $3, $$); }
	| factor
		{ $$ = $1; }
    ;

factor :
	factor Mult primary      
        { $$ = $1 * $3; printf("%d mult %d is %d\n", $1, $3, $$); }
	| factor Div primary      
        { $$ = $1 / $3; printf("%d div %d is %d\n", $1, $3, $$); }
	| primary
		{ $$ = $1; }
	;

primary :
	Realnumber
		{ $$ = $1; }
	| Left expression Right
		{ $$ = $2; }
	;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(char *msg) {
    printf("Error: %s\n", msg);
}