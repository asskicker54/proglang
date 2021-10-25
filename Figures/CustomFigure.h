//
// Created by ass_kicker54 on 10/25/21.
//
//TODO Clone function for Custom Figure
#ifndef FIGURES_CUSTOMFIGURE_H
#define FIGURES_CUSTOMFIGURE_H

#include "Figures.h"

class CustomFigure {
private:
    Figure *mainFigure;
    Figure *cut;
public:
    CustomFigure(Figure *, Figure*);
    ~CustomFigure();
    double CalcArea();
};

#endif //FIGURES_CUSTOMFIGURE_H
