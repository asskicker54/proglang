#include "Datetime.h"
#include "DatetimeExtended.h"
#include <iostream>

using namespace std;

int main() 
{
    Datetime *A = new DatetimeExtended(12, 12, 12, 12, 12, 12, 12);
    std::cout << A->GenerateString("c") << std::endl;
    delete A;
}

