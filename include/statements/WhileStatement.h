#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <statements/Statements.h>
#include <Visitor.h>

class Expression;
class Statements;
class Visitor;

class WhileStatement : public Statement {

    private:
        Expression* exp; // expression for the while loop condition
        Statements* st; // statement(s) to be executed in the while loop

    public:
        WhileStatement(Expression* exp, Statements* st);

        ~WhileStatement();

        void accept(Visitor& visitor, Environment& env);

        Expression* get_exp();

        Statements* get_statements();
        
};

#endif