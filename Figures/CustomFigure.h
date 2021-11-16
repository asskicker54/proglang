//
// Created by ass_kicker54 on 10/25/21.
//

#ifndef FIGURES_CUSTOMFIGURE_H
#define FIGURES_CUSTOMFIGURE_H

#include "Figures.h"

class CustomFigure : public Figure{
private:
    Figure *mainFigure;
    Figure *cut;
public:
    //CustomFigure(Figure *, Figure*);
    virtual ~CustomFigure();
    double CalcArea() override;
    double CalcPerimetr() override;
};

#endif //FIGURES_CUSTOMFIGURE_H
