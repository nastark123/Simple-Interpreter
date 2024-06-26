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