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
protected:
    Figure *F;
private:
    double h;
public:
    Cylinder(double);
    ~Cylinder();
    double CalcVolume() override;
};

class CircleCylinder : public Cylinder {
public:
    CircleCylinder(double h, Figure *in_f);
    ~CircleCylinder();
    static Figure *CreateFigure(Figure *);
    double GetRadius();
};

class TriangleCylinder : public Cylinder {
public:
    TriangleCylinder(double , Figure *);
    Figure *CreateFigure(Figure *);
};
#endif //FIGURES_VOLUMETRICFIGURE_H
