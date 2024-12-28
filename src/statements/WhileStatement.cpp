#include <statements/WhileStatement.h>

WhileStatement::WhileStatement(Expression* exp, Statements* st) {
    this->exp = exp;
    this->st = st;
}

WhileStatement::~WhileStatement() {

}

void WhileStatement::accept(Visitor& visitor, Environment& env) {
    visitor.visit(*this, env);
}

Expression* WhileStatement::get_exp() {
    return exp;
}

Statements* WhileStatement::get_statements() {
    return st;
}