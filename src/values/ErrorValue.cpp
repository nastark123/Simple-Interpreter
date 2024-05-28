#include <values/ErrorValue.h>

ErrorValue::ErrorValue(std::string value) {
    this->value = value;
}

ErrorValue::~ErrorValue() {

}

std::string ErrorValue::get_type() {
    return "error";
}

std::string ErrorValue::get_value() {
    return value;
}