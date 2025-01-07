#include <expressions/LessExp.h>

LessExp::LessExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

LessExp::~LessExp() {

}

Value* LessExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& LessExp::get_lval() {
    return *lval;
}

Expression& LessExp::get_rval() {
    return *rval;
}