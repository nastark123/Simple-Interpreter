#ifndef BOOLEANVALUE_H
#define BOOLEANVALUE_H

#include <values/Value.h>

class BooleanValue : public Value {

    private:
        bool value;

    public:
        BooleanValue(bool value);

        ~BooleanValue();

        std::string get_type();

        bool get_value();

};

#endif