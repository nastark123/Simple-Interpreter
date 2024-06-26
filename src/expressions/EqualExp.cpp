#include <expressions/EqualExp.h>

EqualExp::EqualExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

EqualExp::~EqualExp() {

}

Value* EqualExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& EqualExp::get_lval() {
    return *lval;
}

Expression& EqualExp::get_rval() {
    return *rval;
}