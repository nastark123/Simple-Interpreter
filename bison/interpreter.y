%language "c++"

%defines
%define api.parser.class {InterpreterParser}

%define api.token.raw
%define api.token.constructor
%define api.value.type variant

%code requires {
    #include <string>
    #include <cstdio>

    #include <AbstractSyntaxTreeNode.h>
    #include <expressions/AddExp.h>
    #include <expressions/SubExp.h>
    #include <expressions/MultExp.h>
    #include <expressions/DivExp.h>
    #include <expressions/ConstExp.h>
    #include <expressions/VarExp.h>
    #include <statements/AssignStatement.h>
    #include <statements/PrintStatement.h>

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
    GREATER ">"
    LESS "<"
    ;

%token <std::string> IDENTIFIER "identifier"
%token <int> INTEGER "integer"
%nterm <AbstractSyntaxTreeNode*> start;
%nterm <Statement*> statement
%nterm <Expression*> expr

%left "+" "-"
%left "*" "/"
%%

start : statement       {driver.program.add_line($1);}
      | start statement {driver.program.add_line($2);}
      ;

expr : expr PLUS expr    {$$ = new AddExp($1, $3);}
     | expr MINUS expr   {$$ = new SubExp($1, $3);}
     | expr STAR expr    {$$ = new MultExp($1, $3);}
     | expr SLASH expr   {$$ = new DivExp($1, $3);}
     /*| LPAREN expr RPAREN */
     | INTEGER    {$$ = new ConstExp(new IntegerValue($1));}
     | IDENTIFIER {$$ = new VarExp($1);}
     ;

statement : IDENTIFIER ASSIGN expr    {$$ = new AssignStatement($1, $3);}
          | GREATER expr              {$$ = new PrintStatement($2);}
          ;

%%

void yy::InterpreterParser::error(const location& l, const std::string& m) {
    driver.error(l, m);
}