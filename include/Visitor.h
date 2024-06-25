#ifndef VISITOR_H
#define VISITOR_H

// #include <values/Value.h>

// #include <expressions/AddExp.h>
// #include <expressions/ConstExp.h>

class Value;

class AddExp;
class SubExp;
class MultExp;
class DivExp;
class ConstExp;
class VarExp;
class AssignStatement;
class PrintStatement;

class Visitor {

    public:
        virtual Value* visit(AddExp& exp, Environment& env) = 0;

        virtual Value* visit(SubExp& exp, Environment& env) = 0;

        virtual Value* visit(MultExp& exp, Environment& env) = 0;

        virtual Value* visit(DivExp& exp, Environment& env) = 0;

        // virtual Value* visit(AssignExp exp, Environment env) = 0;

        virtual Value* visit(ConstExp& exp, Environment& env) = 0;

        virtual Value* visit(VarExp& exp, Environment& env) = 0;

        virtual void visit(AssignStatement& st, Environment& env) = 0;

        virtual void visit(PrintStatement& st, Environment& env) = 0;

};

#endif