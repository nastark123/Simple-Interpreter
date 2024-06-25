#ifndef SUBEXP_H
#define SUBEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class SubExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        SubExp(Expression* lval, Expression* rval);

        ~SubExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif