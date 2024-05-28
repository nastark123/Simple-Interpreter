#include <values/IntegerValue.h>

IntegerValue::IntegerValue(int value) {
    this->value = value;
}

IntegerValue::~IntegerValue() {

}

std::string IntegerValue::get_type() {
    return "int";
}

int IntegerValue::get_value() {
    return value;
}