#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <Environment.h>
#include <values/ErrorValue.h>
#include <values/IntegerValue.h>
#include <Visitor.h>

class Visitor;

class Evaluator : public Visitor {

    public:
        Value* visit(AddExp& exp, Environment& env);

        Value* visit(ConstExp& exp, Environment& env);

};

#endif