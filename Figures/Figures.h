//
// Created by ass_kicker54 on 10/19/21.
//

#ifndef FIGURES_FIGURES_H
#define FIGURES_FIGURES_H

const double PI = 3.1415926535;


class Figure {
public:
    virtual double CalcPerimetr() = 0;
    virtual double CalcArea() = 0;
};



class Triangle : public Figure {
private:
    double a, b, c;
public:
    Triangle(double, double, double);
    double CalcPerimetr();
    double CalcArea();
};



class Circle : public Figure {
private:
    double r;
public:
    Circle(double);
    double CalcPerimetr();
    double CalcArea();
};



class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double, double);
    double CalcPerimetr();
    double CalcArea();
};

double CalcVolume(double h, Figure *f);

#endif //FIGURES_FIGURES_H
