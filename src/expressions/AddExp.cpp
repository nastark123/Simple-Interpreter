#include <expressions/AddExp.h>

AddExp::AddExp(Expression* lval, Expression* rval) {
    this->lval = lval;
    this->rval = rval;
}

AddExp::~AddExp() {

}

Value* AddExp::accept(Visitor& visitor, Environment& env) {
    return visitor.visit(*this, env);
}

Expression& AddExp::get_lval() {
    return *lval;
}

Expression& AddExp::get_rval() {
    return *rval;
}