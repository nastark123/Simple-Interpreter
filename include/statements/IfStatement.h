#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <statements/Statement.h>
#include <Visitor.h>

class Expression;
class Statement;
class Visitor;

class IfStatement : public Statement {

    private:
        Expression* exp;
        Statement* st;

    public:
        IfStatement(Expression* exp, Statement* st);

        ~IfStatement();

        void accept(Visitor& visitor, Environment& env);

        Expression* get_exp();

        Statement* get_statement();

};

#endif