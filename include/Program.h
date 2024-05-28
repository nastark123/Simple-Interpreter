#ifndef PROGRAM_H
#define PROGRAM_H

#include <list>

#include <AbstractSyntaxTreeNode.h>
#include <Environment.h>
#include <Evaluator.h>

class Program {

    private:
        Environment env;

        Evaluator evaluator;

        std::list<AbstractSyntaxTreeNode*> lines;

    public:
        Program();

        ~Program();

        void add_line(AbstractSyntaxTreeNode* line);

        void execute();

};

#endif