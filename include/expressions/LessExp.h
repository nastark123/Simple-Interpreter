#ifndef LESSEXP_H
#define LESSEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/NumberValue.h>
#include <Visitor.h>

class Expression;
class Visitor;

class LessExp : public Expression {
    
    private:
        Expression* lval;
        Expression* rval;

    public:
        LessExp(Expression* lval, Expression* rval);

        ~LessExp();

        Value* accept(Visitor& visitor, Environment& env);

        Expression& get_lval();

        Expression& get_rval();

};

#endif