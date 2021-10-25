//
// Created by ass_kicker54 on 10/25/21.
//
#include "CustomFigure.h"

CustomFigure::CustomFigure(Figure *in_mainFigure, Figure *in_cut) {
    this->mainFigure = in_mainFigure->Clone();
    this->cut = in_cut->Clone();
}

CustomFigure::~CustomFigure() {
    delete mainFigure;
    delete cut;
}

double CustomFigure::CalcArea() {
    double s = mainFigure->CalcArea() - cut->CalcArea();
    if(s > 0) {
        return s;
    } else {
        return 0;
    }
}

