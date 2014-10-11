#ifndef AK_STRINGUTIL_H
#define AK_STRINGUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <time.h>
#include <vector>

namespace ak {

	/** 
	 * @brief 字符串操作，以及转换的封装
	 */
    class StringUtil {
        public:
            // 把string转成int
            static int strToInt(const char *str, int d);

            // 是整数
            static int isInt(const char *str);

            // 转成小写
            static char *strToLower(char *str);

            // 转成大写
            static char *strToUpper(char *str);

            // trim
            static char *trim(char *str, const char *what = " ", int mode = 3);

            // hash_value
            static int hashCode(const char *str);

            // 得到一个str的hash值的素数
            static int getPrimeHash(const char *str);

            // 把string以delim分隔开,放到list中
            static void split(char *str, const char *delim, std::vector<char*> &list);

            // urldecode
            static char *urlDecode(const char *src, char *dest);

            static unsigned int murMurHash(const void *key, int len);
            // 把bytes转成可读的, 如 10K 12M 等
            static std::string formatByteSize(double bytes);
            
            // startsWith
            static bool startsWith (const std::string & s, char pfx);

            static bool startsWith (const std::string & s, const char * pfx, size_t len);

            static bool startsWith (const std::string & s, const char * pfx);

            static bool startsWith (const std::string & s, const std::string & pfx);

            // endsWith
            static bool endsWith   (const std::string & s, char sfx);

            static bool endsWith   (const std::string & s, const char * sfx, size_t len);

            static bool endsWith   (const std::string & s, const char * sfx);

            static bool endsWith   (const std::string & s, const std::string & sfx);

            // 计算相同的prefix长度
            static std::string::size_type samePrefixLength(const std::string &a, const std::string &b);


    };   
}

#endif
