#include <Environment.h>

Environment::Environment() {
    variables = std::map<std::string, Value*>();
}

Environment::~Environment() {

}