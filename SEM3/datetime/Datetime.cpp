//
// Created by ass_kicker54 on 9/27/21.
//

#include "Datetime.h"
#include <iostream>

Datetime::Datetime() {

}

Datetime::Datetime(unsigned int d, unsigned int mon, unsigned int y,unsigned int h, unsigned int min, unsigned int s) {
    second = s;
    minute = min;
    hour = h;
    day = d;
    month = mon;
    year = y;
}

Datetime::~Datetime() {
    std::cout << "Symphony of destruction" << std::endl;
}

unsigned int Datetime::Get(int arg)
{
    switch(arg) {
        case 0:
            return day;
        case 1:
            return month;
        case 2:
            return year;
        case 3:
            return hour;
        case 4:
            return minute;
        case 5:
            return second;
        default:
            return 0;
    }
}

std::string Datetime::GenerateString(std::string arg)
{
    std::cout << "Datetime" << std::endl;
    char curr[100] = "\0";
    char next[100] = "\0";
    char prev[100] = "\0";
    char format[31] = "\t%02u.%02u.%04u %02u:%02u:%02u";

    Datetime N, P;

    sprintf(curr, format, day, month, year, hour, minute, second);
    N = GetNext();
    sprintf(next, format, N.day, N.month, N.year, N.hour, N.minute, N.second);
    P = GetPrev();
    sprintf(prev, format, P.day, P.month, P.year, P.hour, P.minute, P.second);

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

namespace
{
    unsigned int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned int daysPrev[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
}

Datetime Datetime::GetNext()
{
    Datetime r (*this);

    bool isLeap = false;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        isLeap = true;
    }

    if (month == 2 && day == 28 && isLeap) {
        r.day += 1;
    } else {
        if (day == days[month-1]) {
            r.day = 1;
            if (month == 12) {
                r.month = 1;
                r.year += 1;
            } else {
                r.month += 1;
            }
        } else {
            r.day += 1;
        }
    }
    return r;
}

Datetime Datetime::GetPrev()
{
    Datetime r (*this);

    bool isLeap = false;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        isLeap = true;
    }

    if (month == 3 && day == 1 && isLeap) {
        r.day = 29;
        r.month = 2;
    } else {
        if (day == 1) {
            r.day = daysPrev[month-1];
            if (month == 1) {
                r.month = 12;
                r.year -= 1;
            } else {
                r.month -= 1;
            }
        } else {
            r.day -= 1;
        }
    }
    return r;
}

Datetime Datetime::CurrentTime()
{
    Datetime r;
    time_t t;
    time(&t);

    tm* ct = localtime(&t);

    r.day = ct->tm_mday;
    r.month = ct->tm_mon + 1;
    r.year = ct->tm_year + 1900;
    r.hour = ct->tm_hour;
    r.minute = ct->tm_min;
    r.second = ct->tm_sec;

    return r;
}
