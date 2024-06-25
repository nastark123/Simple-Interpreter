#include <expressions/MultExp.h>

MultExp::MultExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

MultExp::~MultExp() {

}

Value* MultExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& MultExp::get_lval() {
    return *lval;
}

Expression& MultExp::get_rval() {
    return *rval;
}