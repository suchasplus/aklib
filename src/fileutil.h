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
    * @brief 对文件目录的基本操作 
    */
    class FileUtil {
        public:
            /** 创建多级目录 */
            static bool mkdirs(char *szDirPath);
            /** 是否为目录 */
            static bool isDirectory(const char *szDirPath);
            /** 是否为SymLink文件 */
            static bool isSymLink(const char *szDirPath);
    };
}

#endif //END OF AK_FILEUTIL_H

