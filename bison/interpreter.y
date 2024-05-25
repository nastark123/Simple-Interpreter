%language "c++"

%defines
%define api.parser.class {InterpreterParser}

%define api.token.raw
%define api.token.constructor
%define api.value.type variant

%code requires {
    #include <string>
    #include <cstdio>
    class InterpreterDriver;
}

%param {InterpreterDriver& driver}

%locations
%initial-action
{
    // this is supposed to initialize the location
    @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include <cstdio>
    #include <InterpreterDriver.h>

    // use the class definition of yylex instead of the junk one in interpreter.l
    #define yylex driver.lexer.yylex
}

%define api.token.prefix {TOK_}
%token
    END 0 "end of file"
    ASSIGN "="
    MINUS  "-"
    PLUS   "+"
    STAR   "*"
    SLASH  "/"
    LPAREN "("
    RPAREN ")"
    NLINE "\n"
    ;

%token <std::string> IDENTIFIER "identifier"
%token <int> INTEGER "integer"
%nterm <int> exprorassign
%nterm <int> expr
%nterm <int> assign

%left "+" "-"
%left "*" "/"
%%

start : line 
      | start line
      ;

line : exprorassign "\n"
     | exprorassign
     ;

exprorassign : expr {$$ = $1; printf("%d\n", $1);}
             | assign {$$ = $1;}
             ;

expr : expr PLUS expr    {$$ = $1 + $3;}
     | expr MINUS expr    {$$ = $1 - $3;}
     | expr STAR expr    {$$ = $1 * $3;}
     | expr SLASH expr    {$$ = $1 / $3;}
     | LPAREN expr RPAREN {$$ = $2;}
     | INTEGER    {$$ = $1;}
     | IDENTIFIER {$$ = driver.variables[$1];}
     ;

assign : IDENTIFIER ASSIGN expr    {$$ = $3; driver.variables[$1] = $3;}
       ;

%%

void yy::InterpreterParser::error(const location& l, const std::string& m) {
    driver.error(l, m);
}