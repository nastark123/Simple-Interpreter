#include <Program.h>

Program::Program() {
    env = Environment();
    evaluator = Evaluator();
    lines = std::list<AbstractSyntaxTreeNode*>();
}

Program::~Program() {

}

void Program::add_line(AbstractSyntaxTreeNode* line) {
    lines.emplace_back(line);
}

void Program::execute() {
    auto iter = lines.begin();
    for(; iter != lines.end(); iter++) {
        (*iter)->accept(evaluator, env);
    }
}