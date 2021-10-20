//
// Created by ass_kicker54 on 10/20/21.
//

#include "VolumetricFigure.h"

double Cylinder::CalcVolume() {
    return h * F->CalcArea();
}

Cylinder::Cylinder(double in_h, Figure *in_f) : h{in_h}, F{in_f}  {
    //constructor
}