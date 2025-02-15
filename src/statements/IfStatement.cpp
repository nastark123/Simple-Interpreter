#include <statements/IfStatement.h>

IfStatement::IfStatement(Expression* exp, Statements* st) {
    this->exp = exp;
    this->st = st;
}

IfStatement::~IfStatement() {

}

void IfStatement::accept(Visitor& visitor, Environment& env) {
    visitor.visit(*this, env);
}

Expression* IfStatement::get_exp() {
    return exp;
}

Statements* IfStatement::get_statements() {
    return st;
}