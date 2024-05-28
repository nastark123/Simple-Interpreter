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
    #include <expressions/ConstExp.h>

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
%nterm <AbstractSyntaxTreeNode*> start;
%nterm <AbstractSyntaxTreeNode*> line
%nterm <AbstractSyntaxTreeNode*> exprorassign
%nterm <Expression*> expr
%nterm <AbstractSyntaxTreeNode*> assign

%left "+" "-"
%left "*" "/"
%%

start : line       {driver.program.add_line($1);}
      | start line {driver.program.add_line($2);}
      ;

line : exprorassign "\n" {$$ = $1;}
     | exprorassign      {$$ = $1;}
     ;

exprorassign : expr {$$ = $1; printf("%d\n", $1);}
             /*| assign {$$ = $1;}*/
             ;

expr : expr PLUS expr    {$$ = new AddExp($1, $3);}
     /*| expr MINUS expr*/   
     /*| expr STAR expr   */ 
     /*| expr SLASH expr   */
     /*| LPAREN expr RPAREN */
     | INTEGER    {$$ = new ConstExp(new IntegerValue($1));}
     /*| IDENTIFIER {$$ = driver.variables[$1];}*/
     ;

/*assign : IDENTIFIER ASSIGN expr    {$$ = $3; driver.variables[$1] = $3;}*/
       /*;*/

%%

void yy::InterpreterParser::error(const location& l, const std::string& m) {
    driver.error(l, m);
}