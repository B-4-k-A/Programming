#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class CPoint2D {
public:
    double x, y;

    CPoint2D() {
        this->x = 0;
        this->y = 0;
    };

    CPoint2D(double x, double y) {
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
        A = CPoint2D(0, 0);
        B = CPoint2D(0, 0);
        length = 0;
    };

    CVector2D(CPoint2D C, CPoint2D D) {
        A = C;
        B = D;
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

    virtual bool operator>(const IPhysObjects& obj) const = 0;
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
    CFigure() {
        _ObjList.push_back(this);
    }

    static double _sum_perimeter;
    static double _sum_square;
    static double _sum_mass;
    static std::vector<CFigure*> _ObjList;
public:
    static std::vector<CFigure*> ObjList() {
        return _ObjList;
    }

    static const CFigure* get_figure(unsigned int i) {
        return _ObjList[i * 2];
    }

    static unsigned count() {
        return _ObjList.size() / 2;
    }

    static double sum_mass() {
        return _sum_mass;
    }

    static double sum_perimeter() {
        return _sum_perimeter;
    }

    static double sum_square() {
        return _sum_square;
    }
};

double CFigure::_sum_perimeter = 0;
double CFigure::_sum_square = 0;
double CFigure::_sum_mass = 0;
std::vector<CFigure*> CFigure::_ObjList;

class CCircle : public CFigure {
private:
    double mass_;
    CVector2D rad_;
public:
    CCircle() {
        rad_ = CVector2D(CPoint2D(0, 0), CPoint2D(0, 0));
        mass_ = 0;
        _ObjList.push_back(this);
    }

    CCircle(CVector2D rad, double mass) {
        rad_ = rad;
        mass_ = mass;
        _sum_mass += mass;
        _sum_perimeter += 2 * rad_.length * M_PI;
        _sum_square += M_PI * pow(rad_.length, 2);
        _ObjList.push_back(this);
    }

    const char* classname() const override {
        return "CCircle";
    }

    void initFromDialog() override {
        std::cout << "Enter parameters of " << classname() << ":" << std::endl;
        std::cout << "Mass =";
        std::cin >> this->mass_;
        _sum_mass += mass_;
        std::cout << "Rad: " << std::endl;
        std::cout << "Center of circle (x;y)" << std::endl;
        CPoint2D A;
        std::cin >> A.x >> A.y;
        std::cout << "Point on circle (x;y)" << std::endl;
        CPoint2D B;
        std::cin >> B.x >> B.y;
        rad_ = CVector2D(A, B);
        _sum_perimeter += sum_perimeter();
        _sum_square += sum_square();
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
        return this->mass_ < obj.mass();
    }

    bool operator>(const IPhysObjects& obj) const override {
        return this->mass_ > obj.mass();
    }

    void draw() const override {
        std::cout << "Parameters of circle:" << std::endl;
        std::cout << "Mass = " << mass_ << std::endl;
        std::cout << "Center of mass = (" << rad_.A.x << ":" << rad_.B.y << ")" << std::endl;
        std::cout << "Radius = " << rad_.length << std::endl;
        std::cout << "Perimter = " << perimeter() << std::endl;
        std::cout << "Square = " << square() << std::endl;
        std::cout << "Size = " << size() << "bayt" << std::endl;
    }

    unsigned int size() const override {
        return sizeof(mass_) + sizeof(rad_);// esli pole staеic to on vxodit v size ili net
    }
};

class CEquilateralTriangle : public CFigure {
private:
    double mass_;
    CPoint2D position_;
    double side_;
public:
    CEquilateralTriangle() {
        mass_ = 0;
        position_ = CPoint2D(0, 0);
        side_ = 0;
        _ObjList.push_back(this);
    }

    CEquilateralTriangle(double side, CPoint2D position, double mass) {
        this->mass_ = mass;
        this->side_ = side;
        position_ = position;
        _sum_mass += mass;
        _sum_perimeter += side_ * 3;
        _sum_square += pow(side_, 2) * sqrt(3) / 4;
        _ObjList.push_back(this);
    }

    void initFromDialog() override {
        std::cout << "Enter parameters of " << classname() << ":" << std::endl;
        std::cout << "Mass =";
        std::cin >> mass_;
        _sum_mass += mass_;
        std::cout << "Enter center of Equilateral Triangle (x;y)" << std::endl;
        std::cin >> position_.x >> position_.y;
        std::cout << "Side = ";
        std::cin >> side_;
        _sum_perimeter += perimeter();
        _sum_square += square();
    }

    double square() const override {
        return pow(side_, 2) * sqrt(3) / 4;
    }

    double perimeter() const override {
        return side_ * 3;
    }

    const char* classname() const override {
        return "Equilateral Triangle";
    }

    unsigned int size() const override {
        return sizeof(this->mass_) + sizeof(position_) + sizeof(this->side_);
    }

    double mass() const override {
        return mass_;
    }

    CPoint2D position() const override {
        return position_;
    }

    bool operator==(const IPhysObjects& obj) const override {
        return this->mass_ == obj.mass();
    }

    bool operator<(const IPhysObjects& obj) const override {
        return this->mass_ < obj.mass();
    }

    bool operator>(const IPhysObjects& obj) const override {
        return mass_ > obj.mass();
    }

    void draw() const override {
        std::cout << classname() << ":" << std::endl;
        std::cout << "Mass = " << mass_ << "kg" << std::endl;
        std::cout << "Center = (" << position().x << ", " << position().y << ")" << std::endl;
        std::cout << "Side = " << side_ << std::endl;
        std::cout << "Square = " << square() << std::endl;
        std::cout << "Perimeter = " << perimeter() << std::endl;
        std::cout << "Size = " << size() << "bayt" << std::endl;
    }
};
