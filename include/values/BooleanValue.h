#ifndef BOOLEANVALUE_H
#define BOOLEANVALUE_H

#include <values/Value.h>
#include <values/ErrorValue.h>

class BooleanValue : public Value {

    private:
        bool value;

    public:
        BooleanValue(bool value);

        ~BooleanValue();

        std::string get_type();

        bool get_value();

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