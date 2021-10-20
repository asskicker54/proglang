//
// Created by ass_kicker54 on 10/20/21.
//

#ifndef FIGURES_VOLUMETRICFIGURE_H
#define FIGURES_VOLUMETRICFIGURE_H

#include "Figures.h"

class VolumetricFigure {
private:

public:
    virtual double CalcVolume() = 0;
};

class Cylinder : public VolumetricFigure{
private:
    Figure *F;
    double h;
public:
    Cylinder(double, Figure *);
    virtual double CalcVolume();
};

#endif //FIGURES_VOLUMETRICFIGURE_H
