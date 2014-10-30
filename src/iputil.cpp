#include "ak.h"
#include "iputil.h"
#include <unistd.h>

namespace ak {

    std::string IPUtil::getLocalIP ( const std::string & local_eth ) {
        int sock_get_ip;
        char ipaddr[IP_MAX] = {0};
        struct sockaddr_in *sin;
        struct ifreq ifr_ip;
        if ((sock_get_ip = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            return "";
        }
        memset(&ifr_ip, 0, sizeof(ifr_ip));
        strncpy(ifr_ip.ifr_name, local_eth.c_str(), sizeof(ifr_ip.ifr_name) - 1);
        if ( ioctl( sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0 ) {
            return "";
        }
        sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;
        strcpy(ipaddr, inet_ntoa(sin->sin_addr));
        close( sock_get_ip );
        return std::string( ipaddr );
    }

    uint64_t IPUtil::ip2long ( const std::string& ip_str ) {
        struct in_addr ip ;
        if( ip_str.empty() || inet_pton(AF_INET, ip_str.c_str(), &ip) != 1 ) {
            return -1;
        }
        return ntohl(ip.s_addr);
    }
}
