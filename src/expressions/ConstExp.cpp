#include <expressions/ConstExp.h>

ConstExp::ConstExp(Value* value) {
    this->value = value;
}

ConstExp::~ConstExp() {

}

Value* ConstExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Value* ConstExp::get_value() {
    return value;
}