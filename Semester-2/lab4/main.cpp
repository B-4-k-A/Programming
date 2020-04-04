#include <iostream>
#include "figure.h"


int main() {
    CCircle A(CVector2D(CPoint2D(0, 0), CPoint2D(5, 0)), 5);
    CEquilateralTriangle B(5, CPoint2D(0, 0), 15);
    CCircle C;
    C.initFromDialog();
    CEquilateralTriangle D;
    D.initFromDialog();
    for(int i = 0; i < A.count(); i++) {
        std::cout << "---------------" << std::endl;
        A.get_figure(i)->draw();
    }
    std::cout << A.count() << std::endl;
    std::cout << A.sum_mass() << std::endl;
    std::cout << A.sum_perimeter() << std::endl;
    std::cout << A.sum_square() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    if(A > B)
        std::cout << "A (" << A.classname() << ") > " << "B (" << B.classname() << ")" << std::endl;
    else if(A == B)
        std::cout << "A (" << A.classname() << ") = " << "B (" << B.classname() << ")" << std::endl;
    else
        std::cout << "A (" << A.classname() << ") < " << "B (" << B.classname() << ")" << std::endl;
    return 0;
}