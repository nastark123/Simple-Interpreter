#include <statements/PrintStatement.h>

PrintStatement::PrintStatement(Expression* exp) {
    this->exp = exp;
}

PrintStatement::~PrintStatement() {

}

void PrintStatement::accept(Visitor& visitor, Environment& env) {
    visitor.visit(*this, env);
}

Expression* PrintStatement::get_exp() {
    return exp;
}