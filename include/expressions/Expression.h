#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <AbstractSyntaxTreeNode.h>
#include <Visitor.h>

class AbstractSyntaxTreeNode;
class Visitor;

class Expression : public AbstractSyntaxTreeNode {

    public:
        virtual Value* accept(Visitor& visitor, Environment& env) = 0;

};

#endif