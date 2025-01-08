#ifndef VALUE_H
#define VALUE_H

#include <string>

class Value {

    private:

    public:
        virtual std::string get_type() = 0;

        // Various operators that can be called on values (for comparison, addition, etc)
        virtual Value* operator_equals(Value* other) = 0;

        virtual Value* operator_greater(Value* other) = 0;

        virtual Value* operator_less(Value* other) = 0;

        virtual Value* operator_plus(Value* other) = 0;

        virtual Value* operator_minus(Value* other) = 0;

        virtual Value* operator_star(Value* other) = 0;

        virtual Value* operator_slash(Value* other) = 0;
        
};

#endif