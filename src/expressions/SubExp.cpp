#include <expressions/SubExp.h>

SubExp::SubExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

SubExp::~SubExp() {

}

Value* SubExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& SubExp::get_lval() {
    return *lval;
}

Expression& SubExp::get_rval() {
    return *rval;
}