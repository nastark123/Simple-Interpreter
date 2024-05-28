#ifndef ABSTRACTSYNTAXTREENODE_H
#define ABSTRACTSYNTAXTREENODE_H

#include <Environment.h>
#include <values/Value.h>
#include <Visitor.h>

class Visitor;

class Environment;

class AbstractSyntaxTreeNode {

    public:
        virtual Value* accept(Visitor& visitor, Environment& env) = 0;

};

#endif