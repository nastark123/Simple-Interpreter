#ifndef CONSTEXP_H
#define CONSTEXP_H

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/Value.h>
#include <Visitor.h>

class Expression;
class Visitor;

class ConstExp : public Expression {

    private:
        Value* value;

    public:
        ConstExp(Value* value);

        ~ConstExp();

        Value* accept(Visitor& visitor, Environment& env);

        Value* get_value();

};

#endif