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
	 * @brief �ַ����������Լ�ת���ķ�װ
	 */
    class StringUtil {
        public:
            // ��stringת��int
            static int strToInt(const char *str, int d);

            // ������
            static int isInt(const char *str);

            // ת��Сд
            static char *strToLower(char *str);

            // ת�ɴ�д
            static char *strToUpper(char *str);

            // trim
            static char *trim(char *str, const char *what = " ", int mode = 3);

            // hash_value
            static int hashCode(const char *str);

            // �õ�һ��str��hashֵ������
            static int getPrimeHash(const char *str);

            // ��string��delim�ָ���,�ŵ�list��
            static void split(char *str, const char *delim, std::vector<char*> &list);

            // urldecode
            static char *urlDecode(const char *src, char *dest);

            static unsigned int murMurHash(const void *key, int len);
            // ��bytesת�ɿɶ���, �� 10K 12M ��
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

            // ������ͬ��prefix����
            static std::string::size_type samePrefixLength(const std::string &a, const std::string &b);


    };   
}

#endif
