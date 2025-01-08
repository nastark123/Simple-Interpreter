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

Value* ErrorValue::operator_equals(Value* other) {
    return new ErrorValue("Error: Operator \"==\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_greater(Value* other) {
    return new ErrorValue("Error: Operator \">\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_less(Value* other) {
    return new ErrorValue("Error: Operator \"<\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_plus(Value* other) {
    return new ErrorValue("Error: Operator \"+\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_minus(Value* other) {
    return new ErrorValue("Error: Operator \"-\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_star(Value* other) {
    return new ErrorValue("Error: Operator \"*\" not defined for type ErrorValue");
}

Value* ErrorValue::operator_slash(Value* other) {
    return new ErrorValue("Error: Operator \"/\" not defined for type ErrorValue");
}