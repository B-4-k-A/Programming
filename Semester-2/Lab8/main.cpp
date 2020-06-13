#include <iostream>
#include <algorithm>
#include "CircularBuffer.h"

int main() {
    CircularBuffer <int> buffer(9);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.push_back(4);
    buffer.push_back(5);
    buffer.push_front(6);
    buffer.push_front(7);
    buffer.push_front(8);
    buffer.push_front(9);
    print(buffer);


    //-------------------------------
    std::cout << "buffer resize(5): ";
    buffer.resize(5);
    print(buffer);

    std::cout << "Erase second: ";
    buffer.pop_it(buffer.begin() + 1);
    print(buffer);

    std::cout << "Insert thirds: ";
    buffer.push_it(buffer.begin() + 2, 999);
    print(buffer);

    std::cout << "STD::REVERSE(): ";
    std::reverse(buffer.begin(), buffer.end());
    print(buffer);

    std::cout << "STS::SORT(): ";
    std::sort(buffer.begin(), buffer.end());
    print(buffer);
    return 0;
}