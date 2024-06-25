#ifndef MULTEXP_H
#define MULTEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class MultExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        MultExp(Expression* lval, Expression* rval);

        ~MultExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif