//
// Created by ass_kicker54 on 10/25/21.
//
//TODO Clone function for Custom Figure
#ifndef FIGURES_CUSTOMFIGURE_H
#define FIGURES_CUSTOMFIGURE_H

#include "Figures.h"

class CustomFigure : public Figure{
private:
    Figure *mainFigure;
    Figure *cut;
public:
    CustomFigure(Figure *, Figure*);
    virtual ~CustomFigure();
    Figure *Clone() override;
    double CalcArea() override;
    double CalcPerimetr() override;
};

#endif //FIGURES_CUSTOMFIGURE_H