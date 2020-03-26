#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class CPoint2D {
public:
    double x, y;
    CPoint2D () {
        this->x = 0;
        this->y = 0;
    };
    CPoint2D (double x, double y) {
        this->x = x;
        this->y = y;
    }
};

class IGeoFig {
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class CVector2D {
public:
    CVector2D() {
        length = 0;
    };
    CVector2D(int x1, int y1, int x2, int y2) {
        A = CPoint2D(x1, y1);
        B = CPoint2D(x2, y2);
        length = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    }
    CPoint2D A, B;
    double length;

};

class IPhysObjects {
public:
    virtual double mass() const = 0;
    virtual CPoint2D position() const = 0;
    virtual bool operator==(const IPhysObjects& obj) const = 0;
    virtual bool operator<(const IPhysObjects& obj) const = 0;
};

class IPrintable {
public:
    virtual void draw() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class IBaseCObj {
public:
    virtual const char* classname() const = 0;
    virtual unsigned int size() const = 0;
};
class CFigure : public IBaseCObj, public IDialogInitiable, public IPrintable, public IPhysObjects, public IGeoFig {
protected:
//    CFigure() {
//        _count++;
//    }
    static unsigned int _count;
    static unsigned int _sum_perimeter;
    static unsigned int _sum_square;
    static std::vector<CFigure*> _ObjList;
public:
    CFigure () {
        _count++;
        _ObjList.push_back(this);
    }
//    static std::vector<CFigure>* ObjList() {
//        return _ObjList;
//    }
//    static unsigned int count() {
//        return _count;
//    }
//    static unsigned int sum_perimeter() {
//        return _sum_perimeter;
//    }
//    static unsigned int sum_square() {
//        return _sum_square;
//    }
};
unsigned int CFigure::_count = 0;
unsigned int CFigure::_sum_perimeter = 0;
unsigned int CFigure::_sum_square = 0;
std::vector<CFigure*> CFigure::_ObjList;

class CCircle : public CFigure {
private:
    double mass_;
    CVector2D rad_;
public:
    CCircle() {
        mass_ = 0;
        rad_.A.x = 0;
        rad_.A.y = 0;
        rad_.B.x = 0;
        rad_.B.y = 0;

    }
    CCircle (CVector2D rad, double mass) {
        rad_ = rad;
        mass_ = mass;
    }
    const char* classname() const override {
        return "CCircle";
    }
    void initFromDialog() override {
        std::cout << "Enter parameters of " << classname() << ":" << std::endl;
        std::cout << "Mass = ";
        std::cin >> this->mass_;
        std::cout << std::endl;
        std::cout << "Rad: " << std::endl;
        std::cout << "Center of circle (x;y) = ";
        std::cin >> this->rad_.A.x >> this->rad_.A.y;
        std::cout << std::endl;
        std::cout << "Point on circle (x;y) = ";
        std::cin >> this->rad_.B.x >> this->rad_.B.y;
    }
    double perimeter() const override {
        return 2 * rad_.length * M_PI;
    }
    double square() const override {
        return M_PI * pow(rad_.length, 2);
    }
    CPoint2D position() const override {
        CPoint2D pos(rad_.A.x, rad_.A.y);
        return pos;
    }
    double mass() const override {
        return mass_;
    }
    bool operator==(const IPhysObjects& obj) const override {
        return this->mass_ == obj.mass();
    }
    bool operator<(const IPhysObjects& obj) const override {
        return this->mass_ > obj.mass();
    }
    void draw() const override {
        std::cout << "Parameters of circle:" << std::endl;
        std::cout << "Mass = " << mass_ << std::endl;
        std::cout << "Center of mass = (" << rad_.A.x << ":" << rad_.B.y << ")" << std::endl;
        std::cout << "Radius = " << rad_.length << std::endl;
    }
    unsigned int size() const override {
        return sizeof(mass_) + sizeof(rad_);// esli pole staric to on vxodit v size ili net
    }
};
//private:
//    double mass_;
//    CVector2D side_;
//    CPoint2D position_;
//public:
//
//};