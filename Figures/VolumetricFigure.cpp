//
// Created by ass_kicker54 on 10/20/21.
//


//TODO: Cylinder constructor
#include "VolumetricFigure.h"

double Cylinder::CalcVolume() {
    return h * F->CalcArea();
}

Cylinder::Cylinder(double in_h) {
    this->h = in_h;
}

Cylinder::~Cylinder() {
    delete F;
}

CircleCylinder::CircleCylinder(double h, Figure *in_f) : Cylinder(h) {
    this->F = CreateFigure(in_f);
}

TriangleCylinder::TriangleCylinder(double h, Figure *in_f) : Cylinder(h) {
    this->F = CreateFigure(in_f);
}

Figure *CircleCylinder::CreateFigure(Figure *f) {
    Figure *c = new Circle(*dynamic_cast<Circle*>(f));
    return  c;
}

Figure *TriangleCylinder::CreateFigure(Figure *f) {
    Figure *t = new Triangle(*dynamic_cast<Triangle*>(f));
    return t;
}
