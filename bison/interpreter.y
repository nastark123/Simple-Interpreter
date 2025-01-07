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
    #include <expressions/EqualExp.h>
    #include <expressions/GreaterExp.h>
    #include <expressions/LessExp.h>
    #include <expressions/ConstExp.h>
    #include <expressions/VarExp.h>
    #include <statements/Statements.h>
    #include <statements/AssignStatement.h>
    #include <statements/PrintStatement.h>
    #include <statements/IfStatement.h>
    #include <statements/WhileStatement.h>

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
    IF "if"
    WHILE "while"
    EQUAL "=="
    ASSIGN "="
    MINUS  "-"
    PLUS   "+"
    STAR   "*"
    SLASH  "/"
    LPAREN "("
    RPAREN ")"
    LBRACKET "{"
    RBRACKET "}"
    NLINE "\n"
    GREATER ">"
    LESS "<"
    PIPE "|"
    ;

%token <std::string> IDENTIFIER "identifier"
%token <int> INTEGER "integer"
%nterm <AbstractSyntaxTreeNode*> start;
%nterm <Statement*> statement
%nterm <Statements*> statements
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
     | expr EQUAL expr   {$$ = new EqualExp($1, $3);}
     | expr GREATER expr {$$ = new GreaterExp($1, $3);}
     | expr LESS expr    {$$ = new LessExp($1, $3);}
     /*| LPAREN expr RPAREN */
     | INTEGER    {$$ = new ConstExp(new IntegerValue($1));}
     | IDENTIFIER {$$ = new VarExp($1);}
     ;

statement : IDENTIFIER ASSIGN expr    {$$ = new AssignStatement($1, $3);}
          | PIPE expr              {$$ = new PrintStatement($2);}
          | IF LPAREN expr RPAREN LBRACKET statements RBRACKET {$$ = new IfStatement($3, $6);}
          | WHILE LPAREN expr RPAREN LBRACKET statements RBRACKET {$$ = new WhileStatement($3, $6);}
          ;

statements : statement            {$$ = new Statements($1, nullptr);}
           | statement statements {$$ = new Statements($1, $2);}

%%

void yy::InterpreterParser::error(const location& l, const std::string& m) {
    driver.error(l, m);
}