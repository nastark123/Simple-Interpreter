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

};

#endif