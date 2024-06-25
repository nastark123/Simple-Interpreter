#ifndef STATEMENT_H
#define STATEMENT_H

#include <AbstractSyntaxTreeNode.h>
#include <Visitor.h>

class AbstractSyntaxTreeNode;
class Visitor;

class Statement : public AbstractSyntaxTreeNode {

    public:
        virtual void accept(Visitor& visitor, Environment& env) = 0;

};

#endif