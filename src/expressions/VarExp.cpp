#include <expressions/VarExp.h>

VarExp::VarExp(std::string name) {
    this->name = name;
}

VarExp::~VarExp() {

}

Value* VarExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

std::string VarExp::get_name() {
    return name;
}