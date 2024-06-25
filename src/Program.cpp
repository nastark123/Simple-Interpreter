#include <Program.h>

Program::Program() {
    env = Environment();
    evaluator = Evaluator();
    lines = std::list<Statement*>();
}

Program::~Program() {

}

void Program::add_line(Statement* line) {
    lines.emplace_back(line);
}

// void Program::set_var(Value* value) {
//     env.variables[name] = value;
// }

// Value* Program::get_var(std::string name) {
//     return env.variables[name];
// }

void Program::execute() {
    auto iter = lines.begin();
    for(; iter != lines.end(); iter++) {
        (*iter)->accept(evaluator, env);
        // printf("Value type: %s\n", value->get_type().c_str());
        // if(value->get_type() == "int") {
        //     printf("%d\n", ((IntegerValue*) value)->get_value());
        // }
    }
}