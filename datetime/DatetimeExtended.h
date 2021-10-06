//
// Created by ass_kicker54 on 10/6/21.
//

#ifndef DATETIME_DATETIMEEXTENDED_H
#define DATETIME_DATETIMEEXTENDED_H
#include "Datetime.h"
#include <string>


class DatetimeExtended:public Datetime {
private:
    unsigned int ms;
public:
    DatetimeExtended(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    ~DatetimeExtended();
    DatetimeExtended() {};

    std::string GenerateString(std::string arg);
};


#endif //DATETIME_DATETIMEEXTENDED_H
