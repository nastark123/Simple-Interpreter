#include <values/BooleanValue.h>

BooleanValue::BooleanValue(bool value) {
    this->value = value;
}

BooleanValue::~BooleanValue() {

}

std::string BooleanValue::get_type() {
    return "bool";
}

bool BooleanValue::get_value() {
    return value;
}

Value* BooleanValue::operator_equals(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot compare mismatched types");
    }

    return new BooleanValue(((BooleanValue*) other)->get_value() == this->get_value());
}

Value* BooleanValue::operator_greater(Value* other) {
    return new ErrorValue("Error: Operator \">\" not defined for type BooleanValue");
}

Value* BooleanValue::operator_less(Value* other) {
    return new ErrorValue("Error: Operator \"<\" not defined for type BooleanValue");
}

Value* BooleanValue::operator_plus(Value* other) {
    return new ErrorValue("Error: Operator \"+\" not defined for type BooleanValue");
}

Value* BooleanValue::operator_minus(Value* other) {
    return new ErrorValue("Error: Operator \"-\" not defined for type BooleanValue");
}

Value* BooleanValue::operator_star(Value* other) {
    return new ErrorValue("Error: Operator \"*\" not defined for type BooleanValue");
}

Value* BooleanValue::operator_slash(Value* other) {
    return new ErrorValue("Error: Operator \"/\" not defined for type BooleanValue");
}