#ifndef EQUALEXP_H
#define EQUALEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class EqualExp : public Expression {

    private:
        Expression* lval;
        Expression* rval;

    public:
        EqualExp(Expression* lval, Expression* rval);

        ~EqualExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif