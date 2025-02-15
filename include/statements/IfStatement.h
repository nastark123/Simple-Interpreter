#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <statements/Statements.h>
#include <Visitor.h>

class Expression;
class Statements;
class Visitor;

class IfStatement : public Statement {

    private:
        Expression* exp;
        Statements* st;

    public:
        IfStatement(Expression* exp, Statements* st);

        ~IfStatement();

        void accept(Visitor& visitor, Environment& env);

        Expression* get_exp();

        Statements* get_statements();

};

#endif