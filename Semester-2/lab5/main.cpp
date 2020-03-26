#include <iostream>
#include "square.h"
#include "myset.h"

using namespace std;
int main() {
    int x;
    int y;
    int side;
    int angle;

    std::cout << "Enter parameters of  first square:" << std::endl;
    std::cout << "Coordinate of left-up vert:" << std::endl;
    std::cin >> x >> y;
    std::cout << "Long of side of square:" << std::endl;
    std::cin >> side;
    std::cout << "Angel of square and Ox" << std::endl;
    std::cin >> angle;
    square square_1(x, y, side, angle);
    std::cout << "Enter parameters of  second square:" << std::endl;
    std::cout << "Coordinate of left-up vert:" << std::endl;
    std::cin >> x >> y;
    std::cout << "Long of side of square:" << std::endl;
    std::cin >> side;
    std::cout << "Angel of square and Ox" << std::endl;
    std::cin >> angle;
    square square_2(x, y, side, angle);
    if(square_1.get_S() == square_2.get_S()) {
        std::cout << 1 << std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }
    std::cout << "Enter coordinate of vector:" << std::endl;
    std::cout << "Start point of vector:" << std::endl;
    std::cin >> x >> y;
    int x2;
    int y2;
    std::cout << "End point of vector" << std::endl;
    std::cin >> x2 >> y2;
    vect v(x, y, x2, y2);
    square_1.move_square(v);
    std::cout << square_1;
    //------------------------------------------------------------
    std::cout << "------Task - 2------" << std::endl;
    set A;
    A += 0;
    A += 1;
    A += 3;
    A += 9;
    A += 1;
    std::cout << A;
    A -= 0;
    std::cout << A;
    set B;
    B += 4;
    B += 5;
    B += 6;
    B += 7;
    std::cout << B;
    B -= 5;
    std::cout << B;
    if(A == B) {
        std::cout << "A == B" << std::endl;
    }
    else {
        std::cout << "A != B" << std::endl;
    }
    set C = A + B;
    std::cout << C;

    return 0;
}
