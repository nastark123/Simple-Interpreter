#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <cstdio>

#include <Environment.h>
#include <expressions/AddExp.h>
#include <expressions/SubExp.h>
#include <expressions/MultExp.h>
#include <expressions/DivExp.h>
#include <expressions/EqualExp.h>
#include <expressions/GreaterExp.h>
#include <expressions/LessExp.h>
#include <expressions/ConstExp.h>
#include <expressions/VarExp.h>
#include <statements/Statements.h>
#include <statements/AssignStatement.h>
#include <statements/PrintStatement.h>
#include <statements/IfStatement.h>
#include <statements/WhileStatement.h>
#include <values/ErrorValue.h>
#include <values/IntegerValue.h>
#include <values/BooleanValue.h>
#include <Visitor.h>

class Visitor;

class Evaluator : public Visitor {

    public:
        Value* visit(AddExp& exp, Environment& env);

        Value* visit(SubExp& exp, Environment& env);

        Value* visit(MultExp& exp, Environment& env);

        Value* visit(DivExp& exp, Environment& env);

        Value* visit(EqualExp& exp, Environment& env);

        Value* visit(GreaterExp& exp, Environment& env);

        Value* visit(LessExp& exp, Environment& env);

        Value* visit(ConstExp& exp, Environment& env);

        Value* visit(VarExp& exp, Environment& env);

        void visit(Statements& st, Environment& env);

        void visit(AssignStatement& st, Environment& env);

        void visit(PrintStatement& st, Environment& env);

        void visit(IfStatement& st, Environment& env);

        void visit(WhileStatement& st, Environment& env);

};

#endif