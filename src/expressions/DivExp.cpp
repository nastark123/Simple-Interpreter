#include <expressions/DivExp.h>

DivExp::DivExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

DivExp::~DivExp() {

}

Value* DivExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& DivExp::get_lval() {
    return *lval;
}

Expression& DivExp::get_rval() {
    return *rval;
}