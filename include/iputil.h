#ifndef AK_IPUTIL_H
#define AK_IPUTIL_H
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <string>
#include <stdint.h>
#include "ak.h"

namespace ak {
#define IP_MAX 64
    class IPUtil
    {
        public:
            static std::string getLocalIP(const std::string& local_eth) ;

            static uint64_t ip2long(const std::string& ip_str) ;

            static std::string long2ip(const uint64_t ipulong) ;
    };
}
#endif  // END of AK_IPUTIL_H
