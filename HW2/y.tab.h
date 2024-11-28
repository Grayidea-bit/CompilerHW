#ifndef _yy_defines_h_
#define _yy_defines_h_

#define Realnumber 257
#define Plus 258
#define Minus 259
#define Mult 260
#define Div 261
#define Left 262
#define Right 263
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int intValue; /* Integer type for numbers*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
