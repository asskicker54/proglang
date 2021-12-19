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
    int x1, x2, x3;
    int y1, y2, y3;
public:
    Triangle(int, int, int, int, int, int);
    Triangle(double, double, double);

    double CalcPerimetr() override;
    double CalcArea() override;

    Figure *Clone() override;

    double GetA();
    double GetB();
    double GetC();

    void GetCoordinates(int&, int&, int&, int&, int&, int&);
    void SetCoordinates(int, int, int, int, int, int);
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
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
public:
    Rectangle(double, double);
    Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    double CalcPerimetr() override;
    double CalcArea() override;

    Figure *Clone() override;

    double GetA();
    double GetB();

    void GetCoordinates(int&, int&, int&, int&, int&, int&, int&, int&);
    void SetCoordinates(int, int, int, int, int, int, int, int);

};


#endif //FIGURES_FIGURES_H
