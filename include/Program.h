#ifndef PROGRAM_H
#define PROGRAM_H

#include <cstdio>
#include <list>
#include <string>

#include <statements/Statement.h>
#include <Environment.h>
#include <Evaluator.h>

class Program {

    private:
        Environment env;

        Evaluator evaluator;

        std::list<Statement*> lines;

    public:
        Program();

        ~Program();

        void add_line(Statement* line);

        // void set_var(Value* value);

        // Value* get_var(std::string name);

        void execute();

};

#endif