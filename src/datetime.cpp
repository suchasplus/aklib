#include "datetime.h"

namespace ak {

    std::string DateTime::stdDate ( time_t t ) {
        struct tm *tm1, tmbuf ;
        std::string ret ;
        tm1 = gmtime_r(&t, &tmbuf) ;

        if(!tm1) {
            return ret ;
        }
        char str[81] ;
        str[0] = '\0' ;
        snprintf(str, 80, "%s, %02d %s %04d %02d:%02d:%02d GMT",
                day_short_names[tm1->tm_wday],
                tm1->tm_mday,
                mon_short_names[tm1->tm_mon],
                tm1->tm_year + 1900,
                tm1->tm_hour, tm1->tm_min, tm1->tm_sec) ;
        str[79] = '\0' ;
        ret = str ;
        return ret ;
    };

    std::string DateTime::stdDateLocal ( time_t t ) {
        struct tm *tm1, tmbuf ;
        std::string ret ;
        tm1 = localtime_r(&t, &tmbuf) ;

        if(!tm1) {
            return ret ;
        }
        char str[81] ;
        str[0] = '\0' ;
        snprintf(str, 80, "%s, %02d %s %04d %02d:%02d:%02d",
                day_short_names[tm1->tm_wday],
                tm1->tm_mday,
                mon_short_names[tm1->tm_mon],
                tm1->tm_year + 1900,
                tm1->tm_hour, tm1->tm_min, tm1->tm_sec) ;
        str[79] = '\0' ;
        ret = str ;
        return ret ;
    };

};

#ifdef AK_DATETIME_MAIN

// g++ -o test_datetime -I./ -DAK_DATETIME_MAIN  datetime.cpp

int main(int argc, const char *argv[])
{
    time_t timeT ;
    time ( &timeT ) ;
    std::string std_date = ak::DateTime::stdDate ( timeT ) ;
    std::cout << "GMT : " << std_date << std::endl;

    std::string std_dateLocal = ak::DateTime::stdDateLocal ( timeT ) ;
    std::cout << "CST +08:00 : " << std_dateLocal << std::endl;
    return 0;
}

#endif
