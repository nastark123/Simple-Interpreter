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

Value* IntegerValue::operator_equals(Value* other) {
    // TODO - this will need to be modified later once more number types are supported (i.e. floating point)
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot compare mismatched types");
    }

    return new BooleanValue(this->get_value() == ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_greater(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot compare mismatched types");
    }

    return new BooleanValue(this->get_value() > ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_less(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot compare mismatched types");
    }

    return new BooleanValue(this->get_value() < ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_plus(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot add mismatched types");
    }

    return new IntegerValue(this->get_value() + ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_minus(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot subtract mismatched types");
    }

    return new IntegerValue(this->get_value() - ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_star(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot multiply mismatched types");
    }

    return new IntegerValue(this->get_value() * ((IntegerValue*) other)->get_value());
}

Value* IntegerValue::operator_slash(Value* other) {
    if(other->get_type() != this->get_type()) {
        return new ErrorValue("Error: Cannot divide mismatched types");
    }

    IntegerValue* intOther = (IntegerValue*) other;
    if(intOther->get_value() == 0) {
        return new ErrorValue("Error: Cannot divide by zero");
    }

    return new IntegerValue(this->get_value() / ((IntegerValue*) other)->get_value());
}