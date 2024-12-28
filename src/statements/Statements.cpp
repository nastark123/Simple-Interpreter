#include <statements/Statements.h>

Statements::Statements(Statement* statement, Statements* statements) {
    this->statement = statement;
    this->statements = statements;
}

Statements::~Statements() {

}

void Statements::accept(Visitor& visitor, Environment& env) {
    visitor.visit(*this, env);
}

Statement* Statements::get_statement() {
    return statement;
}

Statements* Statements::get_next() {
    return statements;
}