#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <AbstractSyntaxTreeNode.h>
#include <statements/Statement.h>
#include <Visitor.h>

class Statement;
class AbstractSyntaxTreeNode;
class Visitor;

class Statements : public AbstractSyntaxTreeNode {

    private:
        Statement* statement;
        Statements* statements;

    public:
        Statements(Statement* statement, Statements* statements);

        ~Statements();

        void accept(Visitor& visitor, Environment& env);

        Statement* get_statement();

        Statements* get_next();

};

#endif