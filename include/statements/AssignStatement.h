#ifndef ASSIGNSTATEMENT_H
#define ASSIGNSTATEMENT_H

#include <string>

#include <Environment.h>
#include <expressions/Expression.h>
#include <statements/Statement.h>
#include <Visitor.h>

class Expression;
class Statement;
class Visitor;

class AssignStatement : public Statement {

    private:
        std::string name;
        Expression* exp;

    public:
        AssignStatement(std::string name, Expression* exp);

        ~AssignStatement();

        void accept(Visitor& visitor, Environment& env);

        std::string get_name();

        Expression* get_exp();

};

#endif