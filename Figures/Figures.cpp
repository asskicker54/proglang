//
// Created by ass_kicker54 on 10/19/21.
//

#include "Figures.h"
#include <math.h>
#include <string>


/*------------------------TRIANGLE-----------------------------------------------------------------*/
Triangle::Triangle(double in_a , double in_b, double in_c) {
    if(in_a <= 0 || in_b <= 0 || in_c <= 0) {
        throw std::string("Invalid triangle sizes: " +
        std::to_string(in_a) + " " + std::to_string(in_b) + " " + std::to_string(in_c));
    }
    this->a = in_a;
    this->b = in_b;
    this->c = in_c;

}

double Triangle::CalcPerimetr() {
    return a + b + c;
}

double Triangle::CalcArea() {
    double p = CalcPerimetr()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

Figure *Triangle::Clone() {
    Figure *f = new Triangle(*this);
    return f;
}

double Triangle::GetA() {return  a;}
double Triangle::GetB() {return  b;}
double Triangle::GetC() {return  c;}


/*------------------------------Circle--------------------------------------------------------------------*/
Circle::Circle(double in_r) {
    if(in_r <= 0){
        throw std::string("Invalid circle radius: " + std::to_string(in_r));
    }
    this->r = in_r;
}

double Circle::CalcPerimetr() {
    return 2 * PI * r;
}

double Circle::CalcArea() {
    return PI * r * r;
}

Figure *Circle::Clone() {
    Figure *f = new Circle(*this);
    return f;
}

double Circle::GetR() {return r;}


/*---------------------------Rectangle-----------------------------------------------------*/
Rectangle::Rectangle(double in_a, double in_b)  {
    if(in_a <=0 || in_b <= 0) throw std::string("Invalid rectangle sizes:" +
    std::to_string(in_a) + std::to_string(in_b));

    this->a = in_a;
    this->b = in_b;
}

double Rectangle::CalcPerimetr() {
    return 2 * (a + b);
}

double Rectangle::CalcArea() {
    return a * b;
}

Figure *Rectangle::Clone() {
    Figure *f = new Rectangle(*this);
    return f;
}

double  Rectangle::GetA() {return a;}
double Rectangle::GetB() {return  b;}
//--------------------------------------------------