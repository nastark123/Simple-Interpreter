#include <statements/AssignStatement.h>

AssignStatement::AssignStatement(std::string name, Expression* exp) {
    this->name = name;
    this->exp = exp;
}

AssignStatement::~AssignStatement() {

}

void AssignStatement::accept(Visitor& visitor, Environment& env) {
    visitor.visit(*this, env);
}

std::string AssignStatement::get_name() {
    return name;
}

Expression* AssignStatement::get_exp() {
    return exp;
}