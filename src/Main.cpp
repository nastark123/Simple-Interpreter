#include <iostream>
#include <InterpreterDriver.h>

int main(int argc, char** argv) {

    if(argc < 1) {
        std::cout << "Usage: interpreter <file>" << std::endl;
        return 1;
    }

    InterpreterDriver driver;

    driver.parse(argv[1]);

    return 0;
}