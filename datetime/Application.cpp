//
// Created by ass_kicker54 on 9/27/21.
//

#include "Application.h"
#include "Datetime.h"
#include "UserInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void Application::Start() {
    Datetime* arr;
    int n = 0;
    ReadFile(arr, n);
    UserInterface printer;

    cout << "№\tТекущая\t\t\tСледующая\t\tПредыдущая\n";
    printer.print(arr, n);
    printer.printEx(arr, n);

    Datetime currTime;
    currTime = currTime.CurrentTime();
    cout << "\nСейчас " << currTime.GenerateString("c") << endl;

    delete[] arr;
}

void Application::ReadFile(Datetime*& arr, int& n)
{
    cout << "Enter filename: ";
    string filename;
    cin >> filename;

    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }

    //counting lines
    ifstream counter(filename);
    string c;
    while (getline(counter, c)) {
        n++;
    }
    cout << n << endl;
    arr = new Datetime[n];

    unsigned int day, month, year, hour, minute, second;

    //Datetime a;
    string line;
    int i = 0;
    while (getline(in, line)) {
        istringstream conv(line);
        conv >> day >> month >> year >> hour >> minute >> second;
        Datetime d(day, month, year, hour, minute, second);
        arr[i++] = d;
    }
}