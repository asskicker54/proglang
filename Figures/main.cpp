#include <iostream>
#include "Figures.h"
#include "VolumetricFigure.h"
#include "CustomFigure.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    /*Triangle T(2, 3, 4);
    //Circle C(3);
    Rectangle R(4, 4);

    cout << "TP = " << T.CalcPerimetr() << "\nTA = " << T.CalcArea() << endl << endl;
    cout << "CP = " << C.CalcPerimetr() << "\nCA = " << C.CalcArea() << endl << endl;
    cout << "RP = " << R.CalcPerimetr() << "\nRA = " << R.CalcArea() << endl << endl;*/
    /*Figure* ptr = &R;
    Cylinder Cy(5, ptr);
    cout << Cy.CalcVolume();

    Figure *ptr_R = &R;
    Figure *ptr_T = &T;
    CustomFigure cf(ptr_R, ptr_T);
    cout << cf.CalcArea() << endl;
    cout << cf.CalcPerimetr() << endl;
    Figure *ptr_Cyl = &cf;
    Cylinder Cyl(5, ptr_Cyl);
    cout << Cyl.CalcVolume() << endl;*/
    return 0;
}