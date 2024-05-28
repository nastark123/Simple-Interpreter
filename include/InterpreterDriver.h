#ifndef INTERPRETERDRIVER_H
#define INTERPRETERDRIVER_H

#include <fstream>
#include <string>
#include <map>

// Bison output
#include <InterpreterParser.hpp>

// Lexer subclass
#include <InterpreterFlexLexer.h>

#include <Program.h>

class InterpreterDriver {

    public:
        // constructor and destructor
        InterpreterDriver();

        virtual ~InterpreterDriver();

        // class fields
        Program program;

        int result;

        std::map<std::string, int> variables;

        // lexer object
        InterpreterFlexLexer lexer;

        // input file stream for reading user input
        std::ifstream instream;

        bool trace_scanning;

        // input file
        std::string file;

        bool trace_parsing;

        // functions
        void scan_begin();

        void scan_end();

        // used to parse an input string
        int parse(const std::string& f);

        // error functions
        void error(const yy::location& l, const std::string& m);
        void error(const std::string& m);
};

#endif