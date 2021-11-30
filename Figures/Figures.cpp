//
// Created by ass_kicker54 on 10/19/21.
//

#include "Figures.h"
#include <math.h>


/*TRIANGLE*/
Triangle::Triangle(double in_a , double in_b, double in_c) : a{in_a}, b{in_b}, c{in_c} {
    //constructor
}

double Triangle::CalcPerimetr() {
    return a + b + c;
}

double Triangle::CalcArea() {
    double p = CalcPerimetr()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}


/*Circle*/
Circle::Circle(double in_r) : r{in_r} {
    //constructor
}

double Circle::CalcPerimetr() {
    return 2 * PI * r;
}

double Circle::CalcArea() {
    return PI * r * r;
}


/*Rectangle*/
Rectangle::Rectangle(double in_a, double in_b) : a{in_a}, b{in_b} {
    //constructor
}

double Rectangle::CalcPerimetr() {
    return 2 * (a + b);
}

double Rectangle::CalcArea() {
    return a * b;
}

Figure *Triangle::Clone() {
    Figure *f = new Triangle(*this);
    return f;
}

Figure *Circle::Clone() {
    Figure *f = new Circle(*this);
    return f;
}

Figure *Rectangle::Clone() {
    Figure *f = new Rectangle(*this);
    return f;
}