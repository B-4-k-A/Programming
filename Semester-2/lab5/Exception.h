#pragma once

#include <string>

class Exception {
public:
    Exception() = default;
    Exception(std::string problem);
    const std::string* what();
    void print();
protected:
    std::string _problem = "Something happened!";
};

