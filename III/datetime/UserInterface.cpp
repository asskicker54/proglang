//
// Created by ass_kicker54 on 9/27/21.
//

#include "UserInterface.h"
#include "Datetime.h"
#include "Application.h"
#include <iostream>

void UserInterface::print(Datetime *arr, int &n) {
    for(int i{}; i < n; i++) {
        std::cout << i+1 << ":" << arr[i].GenerateString("cnp");
    }
}

void UserInterface::printEx(Datetime *arr, int &n) {
    for(int i{}; i < n; i++) {
        if (arr[i].GetNext().Get(1) == arr[i].GetPrev().Get(1)) {
            std::cout << i + 1 << ":" << arr[i].GenerateString("cnp");

        }
    }
}