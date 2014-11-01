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
            return -1 ;
        }
        return ntohl(ip.s_addr) ;
    }

    std::string IPUtil::long2ip ( const uint64_t ipulong ) {
        struct in_addr myaddr ;
        myaddr.s_addr = htonl(ipulong) ;

        char str[40] ; 
        
        if ( inet_ntop(AF_INET, &myaddr, str, sizeof(str) ) ) {
            std::string ret(str);
            return ret;
        }

        return NULL;

    }
}


#ifdef AK_IPUTIL_MAIN

// g++ -o test_iputil -I./ -DAK_IPUTIL_MAIN  iputil.cpp

int main(int argc, const char *argv[])
{

    std::cout << "eth0 ip: " << ak::IPUtil::getLocalIP("eth0") << std::endl ;

    std::cout << "ip 124.207.24.147 : " << ak::IPUtil::ip2long( "124.207.24.147" ) << std::endl ; // 2093947027 from php ip2long

    std::cout << "uint64_t 3232239114 : " << ak::IPUtil::long2ip(3232239114) << std::endl ;  // 192.168.14.10 from php long2ip

    return 0;
}


#endif
