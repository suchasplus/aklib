#ifndef AK_FILEUTIL_H
#define AK_FILEUTIL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

namespace ak {

    #ifndef S_IRWXUGO
    # define S_IRWXUGO (S_IRWXU | S_IRWXG | S_IRWXO)
    #endif
    
   /** 
    * @brief ���ļ�Ŀ¼�Ļ������� 
    */
    class FileUtil {
        public:
            /** �����༶Ŀ¼ */
            static bool mkdirs(char *szDirPath);
            /** �Ƿ�ΪĿ¼ */
            static bool isDirectory(const char *szDirPath);
            /** �Ƿ�ΪSymLink�ļ� */
            static bool isSymLink(const char *szDirPath);
    };
}

#endif //END OF AK_FILEUTIL_H

