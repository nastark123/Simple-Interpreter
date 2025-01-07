#ifndef GREATEREXP_H
#define GREATEREXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class GreaterExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        GreaterExp(Expression* lval, Expression* rval);

        ~GreaterExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif