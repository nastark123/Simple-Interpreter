#ifndef INTEGERVALUE_H
#define INTEGERVALUE_H

#include <values/BooleanValue.h>
#include <values/NumberValue.h>
#include <values/ErrorValue.h>

class IntegerValue : public NumberValue {

    private:
        int value;

    public:
        IntegerValue(int value);

        ~IntegerValue();

        std::string get_type();

        int get_value();
    
        // Various operators that can be called on values (for comparison, addition, etc)
        virtual Value* operator_equals(Value* other);

        virtual Value* operator_greater(Value* other);

        virtual Value* operator_less(Value* other);

        virtual Value* operator_plus(Value* other);

        virtual Value* operator_minus(Value* other);

        virtual Value* operator_star(Value* other);

        virtual Value* operator_slash(Value* other);

};

#endif