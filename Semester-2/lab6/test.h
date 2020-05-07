#pragma once

#include <iostream>
#include <cmath>
#include <vector>


bool cmp(int x);

bool cmp_less(int x, int y);

bool cmp_equal(int x, int y);

template<class iter>
void print(const iter& begin, const iter& end) {
    std::cout << "{";
    for(auto it = begin; it != end; it = std::next(it)) {
        std::cout << *it;
        if(std::next(it) != end)
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}


class CPoint {
public:
    CPoint();

    CPoint(float x, float y);

    float get_x() {
        return x_;
    }

    float get_y() {
        return y_;
    }

private:
    float x_;
    float y_;
};

class CVector3D {
public:
    CVector3D();

    CVector3D(CPoint A, CPoint B);

    double length();

    friend std::ostream& operator<<(std::ostream& out, CVector3D v);

private:
    CPoint A_;
    CPoint B_;
};

bool cmp_vector(CVector3D v);

bool cmp_vector_less(CVector3D v1, CVector3D v2);

bool cmp_vector_equal(CVector3D v1, CVector3D v2);