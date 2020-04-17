#pragma once

#include <vector>
#include "Exception.h"


template <class T>
class Stack {
public:
    Stack(unsigned size)
            : size_(0) {
        stack_ = std::vector<T>(size);
    }

    T top() {
        try {
            if(size_ == 0)
                throw Exception("Trying to get elem form stack \nError 1 Stack is empty");
            return stack_[size_];
        }
        catch (Exception& ex) {
            ex.print();
        }
        return 0;
    }

    void push(T elem) {
        try {
            if(size_ >= stack_.size())
                throw Exception("Trying to push to stack \nError 2 Stack overflow");
            stack_[++size_] = elem;
        }
        catch (Exception& ex){
            ex.print();
        }
    }
    void pop() {
        try {
            if(size_ == 0)
                throw Exception("Trying to pop element from stack \nError 3 Stack is empty");
            size_--;
        }
        catch (Exception& ex) {
            ex.print();
        }
    }
private:
    std::vector<T> stack_;
    unsigned size_;
};




