#include <Evaluator.h>

Value* Evaluator::visit(AddExp& exp, Environment& env) {
    NumberValue* lval = (NumberValue*) exp.get_lval().accept(*this, env);
    NumberValue* rval = (NumberValue*) exp.get_rval().accept(*this, env);

    if(lval->get_type() != rval->get_type()) {
        return new ErrorValue("Error: mismatched types for addition");
    }

    return new IntegerValue(((IntegerValue*) lval)->get_value() + ((IntegerValue*) rval)->get_value());
}

Value* Evaluator::visit(SubExp& exp, Environment& env) {
    NumberValue* lval = (NumberValue*) exp.get_lval().accept(*this, env);
    NumberValue* rval = (NumberValue*) exp.get_rval().accept(*this, env);

    if(lval->get_type() != rval->get_type()) {
        return new ErrorValue("Error: mismatched types for addition");
    }

    return new IntegerValue(((IntegerValue*) lval)->get_value() - ((IntegerValue*) rval)->get_value());
}

Value* Evaluator::visit(MultExp& exp, Environment& env) {
    NumberValue* lval = (NumberValue*) exp.get_lval().accept(*this, env);
    NumberValue* rval = (NumberValue*) exp.get_rval().accept(*this, env);

    if(lval->get_type() != rval->get_type()) {
        return new ErrorValue("Error: mismatched types for addition");
    }

    return new IntegerValue(((IntegerValue*) lval)->get_value() * ((IntegerValue*) rval)->get_value());
}

Value* Evaluator::visit(DivExp& exp, Environment& env) {
    NumberValue* lval = (NumberValue*) exp.get_lval().accept(*this, env);
    NumberValue* rval = (NumberValue*) exp.get_rval().accept(*this, env);

    if(lval->get_type() != rval->get_type()) {
        return new ErrorValue("Error: mismatched types for addition");
    }

    return new IntegerValue(((IntegerValue*) lval)->get_value() / ((IntegerValue*) rval)->get_value());
}

// Value& Evaluator::visit(AssignExp& exp, Environment& env) {

// }

Value* Evaluator::visit(ConstExp& exp, Environment& env) {
    return exp.get_value();
}

Value* Evaluator::visit(VarExp& exp, Environment& env) {
    return env.variables[exp.get_name()];
}

void Evaluator::visit(AssignStatement& st, Environment& env) {
    env.variables[st.get_name()] = st.get_exp()->accept(*this, env);
}

void Evaluator::visit(PrintStatement& st, Environment& env) {
    IntegerValue* val = (IntegerValue*) st.get_exp()->accept(*this, env);

    printf("%d\n", val->get_value());
}