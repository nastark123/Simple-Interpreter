#ifndef ADDEXP_H
#define ADDEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class AddExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        AddExp(Expression* lval, Expression* rval);

        ~AddExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif