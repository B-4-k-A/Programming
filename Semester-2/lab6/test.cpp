#include "test.h"

bool cmp(int x) {
    return x < 6;
}

bool cmp_less(int x, int y) {
    return x < y;
}

bool cmp_equal(int x, int y) {
    return x == y;
}

bool cmp_vector(CVector3D v) {
    return v.length() > 2;
}

bool cmp_vector_less(CVector3D v1, CVector3D v2) {
    return v1.length() < v2.length();
}
bool cmp_vector_equal(CVector3D v1, CVector3D v2) {
    return v1.length() == v2.length();
}

CPoint::CPoint() {
    x_ = 0;
    y_ = 0;
}

CPoint::CPoint(float x, float y) {
    x_ = x;
    y_ = y;
}

CVector3D::CVector3D() {
    A_ = CPoint(0, 0);
    B_ = CPoint(0, 0);
}

CVector3D::CVector3D(CPoint A, CPoint B) {
    A_ = A;
    B_ = B;
}

std::ostream& operator<<(std::ostream& out, CVector3D v) {
    out << "(" << v.A_.get_x() << ":" << v.A_.get_y() << ")->(" << v.B_.get_x() << ":" << v.B_.get_y() << ")";
    return out;
}

double CVector3D::length() {
    return (sqrt(pow(this->A_.get_x() - this->B_.get_x(), 2) +
            pow(this->A_.get_y() - this->B_.get_y(),2)));
}


