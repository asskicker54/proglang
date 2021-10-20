//
// Created by ass_kicker54 on 10/20/21.
//

#include "VolumetricFigure.h"
#include <string.h>

double Cylinder::CalcVolume() {
    return h * F->CalcArea();
}

Cylinder::Cylinder(double in_h, Figure *in_f) {
    this->h = in_h;
    this->F = in_f->Clone();
}

Cylinder::~Cylinder() {
    delete F;
}
