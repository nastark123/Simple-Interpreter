#include <expressions/GreaterExp.h>

GreaterExp::GreaterExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

GreaterExp::~GreaterExp() {

}

Value* GreaterExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& GreaterExp::get_lval() {
    return *lval;
}

Expression& GreaterExp::get_rval() {
    return *rval;
}