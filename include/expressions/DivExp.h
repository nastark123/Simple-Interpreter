#ifndef DIVEXP_H
#define DIVEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class DivExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        DivExp(Expression* lval, Expression* rval);

        ~DivExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif