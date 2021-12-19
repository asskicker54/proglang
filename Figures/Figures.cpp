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

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (a > 0 and b > 0 and c > 0 and (a + b) > c and (a + c) > b and (b + c) > a)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    } else {
        throw std::string("Invalid triangle sizes: ");
    }
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

void Triangle::GetCoordinates(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3){
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
}

void Triangle::SetCoordinates(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (a > 0 and b > 0 and c > 0 and (a + b) > c and (a + c) > b and (b + c) > a) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }
}

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

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    if (a > 0 and b > 0) {
        this->a = a;
        this->b = b;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->x4 = x4;
        this->y4 = y4;
    } else {
        throw std::string("Invalid rectangle sizes:");
    }
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

void Rectangle::GetCoordinates(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4) {
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
    x4 = this->x4;
    y4 = this->y4;

}

void Rectangle::SetCoordinates(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    if (a > 0 and b > 0) {
        this->a = a;
        this->b = b;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->x4 = x4;
        this->y4 = y4;
    }
}
//--------------------------------------------------
