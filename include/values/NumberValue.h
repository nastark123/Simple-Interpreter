#ifndef NUMBERVALUE_H
#define NUMBERVALUE_H

#include <values/Value.h>

class NumberValue : public Value {
    
    public:
        virtual std::string get_type() = 0;
    
};

#endif