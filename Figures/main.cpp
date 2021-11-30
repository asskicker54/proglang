#include <iostream>
#include "Figures.h"
#include "VolumetricFigure.h"
#include "CustomFigure.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    Circle C(3);
    Circle* ptr = &C;
    Cylinder<Circle> Cyl(3, ptr);
    cout << Cyl.CalcVolume() << endl;
    return 0;
}