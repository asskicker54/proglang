//
// Created by ass_kicker54 on 10/20/21.
//

#include "VolumetricFigure.h"
#include <string>


template<class T>
double Cylinder<T>::CalcVolume() {
    return h * (base->CalcArea());
}
template<class T>
Cylinder<T>::Cylinder(double in_h, T* b) {
    if(in_h <= 0) throw std::string("Invalid cylinder height: " + std::to_string(in_h));

    this->h = in_h;
    this->base = static_cast<T*>(b->Clone());
}

template<class T>
Cylinder<T>::~Cylinder() {
    delete base;
}
template<class T>
T* Cylinder<T>::GetBaseFigure() {
    return static_cast<T*>(base->Clone());
}
template<class T>
double Cylinder<T>::GetH() { return h;}

template class Cylinder<Circle>;
template class Cylinder<Rectangle>;
template class Cylinder<Triangle>;