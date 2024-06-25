#ifndef VAREXP_H
#define VAREXP_H

#include <string>

#include <Environment.h>
#include <expressions/Expression.h>
#include <values/Value.h>
#include <Visitor.h>

class Expression;
class Visitor;

class VarExp : public Expression {

    private:
        std::string name;

    public:
        VarExp(std::string name);

        ~VarExp();

        Value* accept(Visitor& visitor, Environment& env);

        std::string get_name();

};

#endif