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
    virtual Figure *Clone() = 0;
};



class Triangle : public Figure {
private:
    double a, b, c;
public:
    Triangle(double, double, double);

    double CalcPerimetr() override;
    double CalcArea() override;

    Figure *Clone() override;

    double GetA();
    double GetB();
    double GetC();
};



class Circle : public Figure {
private:
    double r;
public:
    explicit Circle(double);

    double CalcPerimetr() override;
    double CalcArea() override;

    Figure *Clone() override;
    double GetR();
};



class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double, double);

    double CalcPerimetr() override;
    double CalcArea() override;

    Figure *Clone() override;

    double GetA();
    double GetB();
};


#endif //FIGURES_FIGURES_H