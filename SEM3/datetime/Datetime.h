//
// Created by ass_kicker54 on 9/27/21.
//

#ifndef DATETIME_DATETIME_H
#define DATETIME_DATETIME_H

#include <string>

class Datetime {

protected:
    unsigned int second;
    unsigned int minute;
    unsigned int hour;
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
//Constructors
    Datetime(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    Datetime();
    ~Datetime();
//Get
    unsigned int Get(int);

    virtual std::string GenerateString(std::string);
    Datetime GetNext();
    Datetime GetPrev();
    Datetime CurrentTime();
};


#endif //DATETIME_DATETIME_H
