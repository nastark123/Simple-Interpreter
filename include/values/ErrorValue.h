#ifndef ERROR_H
#define ERROR_H

#include <string>

#include <values/Value.h>

class ErrorValue : public Value {

    private:
        std::string value;

    public:
        ErrorValue(std::string value);

        ~ErrorValue();

        std::string get_type();

        std::string get_value();

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