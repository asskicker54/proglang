#include <iostream>
#include "Figures.h"

using namespace std;

int main() {
    Triangle T(2, 3, 4);
    Circle C(3);
    Rectangle R(2, 3);

    cout << "TP = " << T.CalcPerimetr() << "\nTA = " << T.CalcArea() << endl << endl;
    cout << "CP = " << C.CalcPerimetr() << "\nCA = " << C.CalcArea() << endl << endl;
    cout << "RP = " << R.CalcPerimetr() << "\nRA = " << R.CalcArea() << endl << endl;
    return 0;
}
