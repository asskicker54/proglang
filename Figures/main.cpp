#include <iostream>
#include "Figures.h"
#include "VolumetricFigure.h"
#include "CustomFigure.h"

using namespace std;

int main() {
    Triangle T(2, 3, 4);
    //Circle C(3);
    Rectangle R(4, 4);
    /*
    cout << "TP = " << T.CalcPerimetr() << "\nTA = " << T.CalcArea() << endl << endl;
    cout << "CP = " << C.CalcPerimetr() << "\nCA = " << C.CalcArea() << endl << endl;
    cout << "RP = " << R.CalcPerimetr() << "\nRA = " << R.CalcArea() << endl << endl;*/
    /*Figure* ptr = &R;
    Cylinder Cy(5, ptr);
    cout << Cy.CalcVolume();
    */
    Figure *ptr_R = &R;
    Figure *ptr_T = &T;
    CustomFigure cf(ptr_R, ptr_T);
    cout << cf.CalcArea() << endl;
    cout << cf.CalcPerimetr() << endl;
    Figure *ptr_Cyl = &cf;
    Cylinder Cyl(5, ptr_Cyl);
    cout << Cyl.CalcVolume() << endl;
    return 0;
}
