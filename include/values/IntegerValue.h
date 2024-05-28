#ifndef INTEGERVALUE_H
#define INTEGERVALUE_H

#include <values/NumberValue.h>

class IntegerValue : public NumberValue {

    private:
        int value;

    public:
        IntegerValue(int value);

        ~IntegerValue();

        std::string get_type();

        int get_value();

};

#endif