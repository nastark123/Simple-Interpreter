%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <string>
    #include <cstdio>
    
    #include <InterpreterDriver.h>
    #include <InterpreterParser.hpp>

    // the location of the current token
    static yy::location loc;

    // TODO find out what this does, it is unclear from example
    #define YY_USER_ACTION loc.columns(yyleng);

    // allegedly prevent compile issue from isatty() use by generated output
    #define YY_NO_UNISTD_H
%}

%option c++
%option noyywrap

/* These act as abbreviations for regex */
id [a-zA-Z][a-zA-Z_0-9]*
int [0-9]+
blank [ \t\r]

%%

%{
    // according to the example, this code is run every time yylex gets called
    loc.step();
%}

{blank}+ loc.step();
[\n]+    loc.lines(yyleng); loc.step(); // return yy::InterpreterParser::make_NLINE(loc);

"if" return yy::InterpreterParser::make_IF(loc);
"while" return yy::InterpreterParser::make_WHILE(loc);
"-" return yy::InterpreterParser::make_MINUS(loc);
"+" return yy::InterpreterParser::make_PLUS(loc);
"*" return yy::InterpreterParser::make_STAR(loc);
"/" return yy::InterpreterParser::make_SLASH(loc);
"(" return yy::InterpreterParser::make_LPAREN(loc);
")" return yy::InterpreterParser::make_RPAREN(loc);
"{" return yy::InterpreterParser::make_LBRACKET(loc);
"}" return yy::InterpreterParser::make_RBRACKET(loc);
"==" return yy::InterpreterParser::make_EQUAL(loc);
">" return yy::InterpreterParser::make_GREATER(loc);
"<" return yy::InterpreterParser::make_LESS(loc);
"=" return yy::InterpreterParser::make_ASSIGN(loc);
"|" return yy::InterpreterParser::make_PIPE(loc);

{int} {
        errno = 0;
        long n = strtol(yytext, NULL, 10);
        if(n <= INT_MIN || n >= INT_MAX || errno == ERANGE)
            driver.error(loc, "Integer is out of range");
        return yy::InterpreterParser::make_INTEGER(n, loc);
        }

{id} return yy::InterpreterParser::make_IDENTIFIER(yytext, loc);

. driver.error(loc, "Invalid character");

<<EOF>> return yy::InterpreterParser::make_END(loc);

%%

// this is to prevent a linker error if no yylex() implementation exists
int yyFlexLexer::yylex() {
    std::cerr << "'int yyFlexLexer::yylex()' should never be called." << std::endl;
    exit(1);
}