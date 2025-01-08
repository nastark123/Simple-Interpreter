#include <Evaluator.h>

Value* Evaluator::visit(AddExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_plus(rval);
}

Value* Evaluator::visit(SubExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_minus(rval);
}

Value* Evaluator::visit(MultExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_star(rval);
}

Value* Evaluator::visit(DivExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_slash(rval);
}

Value* Evaluator::visit(EqualExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_equals(rval);
}

Value* Evaluator::visit(GreaterExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_greater(rval);
}

Value* Evaluator::visit(LessExp& exp, Environment& env) {
    Value* lval = exp.get_lval().accept(*this, env);
    Value* rval = exp.get_rval().accept(*this, env);

    return lval->operator_less(rval);
}

Value* Evaluator::visit(ConstExp& exp, Environment& env) {
    return exp.get_value();
}

Value* Evaluator::visit(VarExp& exp, Environment& env) {
    return env.variables[exp.get_name()];
}

void Evaluator::visit(Statements& st, Environment& env) {
    Statements* statements = &st;
    while(statements != nullptr) {
        statements->get_statement()->accept(*this, env);
        statements = statements->get_next();
    }
}

void Evaluator::visit(AssignStatement& st, Environment& env) {
    env.variables[st.get_name()] = st.get_exp()->accept(*this, env);
}

void Evaluator::visit(PrintStatement& st, Environment& env) {
    IntegerValue* val = (IntegerValue*) st.get_exp()->accept(*this, env);

    printf("%d\n", val->get_value());
}

void Evaluator::visit(IfStatement& st, Environment& env) {
    BooleanValue* val = (BooleanValue*) st.get_exp()->accept(*this, env);

    if(val->get_value()) {
        st.get_statements()->accept(*this, env);
    }
}

void Evaluator::visit(WhileStatement& st, Environment& env) {
    BooleanValue* val = (BooleanValue*) st.get_exp()->accept(*this, env);

    while(val->get_value()) {
        st.get_statements()->accept(*this, env);
        val = (BooleanValue*) st.get_exp()->accept(*this, env);
    }
}