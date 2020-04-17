#include <iostream>
#include <string>
#include "Exception.h"


Exception::Exception(std::string problem)
        : _problem(std::move(problem)) {}

const std::string* Exception::what() {
        return &_problem;
}

void Exception::print() {
    system("color 0C");
    std::cout << *this->what() << std::endl;
}
