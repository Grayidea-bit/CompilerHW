%{
    #include<stdio.h>
    int Total_Int=0;
    int Total_Float=0;
    int Total_id=0;
    int Total_Error=0;
%}
%option noyywrap
%%
-?[0-9]+ {
	printf("Find an Int: %s\n",yytext);
	Total_Int++;
}

-?[0-9]+\.[0-9]+ {
	printf("Find a Float: %s\n",yytext);
	Total_Float++;
}

[A-Za-z]+[_A-Za-z0-9]* {
    printf("Find an Identifier(ID): %s\n",yytext);
    Total_id++;
}

.* {
    printf("Find an Error: %s\n",yytext);
    Total_Error++;
}

\n {}

%%
int main()
{
    yylex();
    printf("Total_Int = %d\n",Total_Int);
    printf("Total_Float = %d\n",Total_Float);
    printf("Total_Identifier(ID) = %d\n",Total_id);
    printf("Total_Error = %d\n",Total_Error);
    return 0;
}
