#ifndef PRINTSTATEMENT_H
#define PRINTSTATEMENT_H

#include <string>

#include <Environment.h>
#include <expressions/Expression.h>
#include <statements/Statement.h>
#include <Visitor.h>

class Expression;
class Statement;
class Visitor;

class PrintStatement : public Statement {

    private:
        std::string name;
        Expression* exp;

    public:
        PrintStatement(Expression* exp);

        ~PrintStatement();

        void accept(Visitor& visitor, Environment& env);

        Expression* get_exp();

};

#endif