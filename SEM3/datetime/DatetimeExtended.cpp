//
// Created by ass_kicker54 on 10/6/21.
//

#include "DatetimeExtended.h"
#include "Datetime.h"
#include <iostream>

DatetimeExtended::DatetimeExtended(unsigned int mls, unsigned int s, unsigned int m,
                                   unsigned int h, unsigned int d, unsigned int mon,
                                   unsigned int y) {
    ms = mls;
    second = s;
    minute = m;
    hour = h;
    day = d;
    month = mon;
    year = y;

}

DatetimeExtended::~DatetimeExtended() {
    std::cout << "symphony of destruction" << std::endl;
}

std::string DatetimeExtended::GenerateString(std::string arg) {
    std::cout << "DatetimeEx" << std::endl;
    char curr[100] = "\0";
    char next[100] = "\0";
    char prev[100] = "\0";
    char format[36] = "\t%02u.%02u.%04u %02u:%02u:%02u.%03u";

    Datetime N, P;

    sprintf(curr, format, day, month, year, hour, minute, second, ms);
    N = GetNext();
    sprintf(next, format, N.Get(0), N.Get(1), N.Get(2), N.Get(3), N.Get(4), N.Get(5));
    P = GetPrev();
    sprintf(prev, format, P.Get(0), P.Get(1), P.Get(2), P.Get(3), P.Get(4), P.Get(5));

    std::string result;
    result = "";

    for (int i = 0; i < arg.length(); i++) {
        switch (arg[i]) {
            case 'c':
                result += curr;
                break;
            case 'n':
                result += next;
                break;
            case 'p':
                result += prev;
                break;
        }
    }

    return result + '\n';
}