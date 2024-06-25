#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>

#include <values/Value.h>

class Environment {

    public:
        std::map<std::string, Value*> variables;

        Environment();

        ~Environment();

};

#endif