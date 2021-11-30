//
// Created by ass_kicker54 on 10/20/21.
//

#ifndef FIGURES_VOLUMETRICFIGURE_H
#define FIGURES_VOLUMETRICFIGURE_H

#include "figures.h"

class VolumetricFigure {
private:

public:
    virtual double CalcVolume() = 0;
};
template<class T>
class Cylinder : public VolumetricFigure{
private:
    T* base;
    double h;
public:
    Cylinder(double, T*);

    ~Cylinder();
    double CalcVolume() override;

    double GetH();
    T* GetBaseFigure();

};

#endif //FIGURES_VOLUMETRICFIGURE_H
