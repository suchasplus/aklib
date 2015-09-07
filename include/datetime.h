#ifndef AK_DATETIME_H
#define AK_DATETIME_H

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include "ak.h"

namespace ak {

class DateTime {

public :
    static std::string stdDate ( time_t t );

    static std::string stdDateLocal ( time_t t );





}; // END of class DateTime

}; // END of namespace ak

#endif // AK_DATETIME_H
