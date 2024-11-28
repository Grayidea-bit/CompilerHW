%{
    #include "y.tab.h" // Ensure this includes the yylval declaration
%}

%%
"-"     { return Minus; }
-?[0-9]+  {
            yylval.intValue = atoi(yytext); // Convert string to integer
            return Realnumber;
         }
"+"     { return Plus; }
"*"     { return Mult; }
"/"     { return Div; }
"("     { return Left; }
")"     { return Right; }
[ \t]   { /* Ignore whitespace */ }
\n      { return '\n'; }
.       { printf("Unknown character: %s\n", yytext); }

%%
int yywrap() {
    return 1;
}
