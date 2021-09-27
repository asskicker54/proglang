//
// Created by ass_kicker54 on 9/27/21.
//

#ifndef DATETIME_APPLICATION_H
#define DATETIME_APPLICATION_H

#include "Datetime.h"

class Application {
public:
    void Start();
private:
    void ReadFile(Datetime*&, int&);
};


#endif //DATETIME_APPLICATION_H
