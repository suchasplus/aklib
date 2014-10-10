#include "fileutil.h"

namespace ak {
    /** 
     * �����༶Ŀ¼, �ڸ�Ŀ¼������һͬ����
     */
    bool FileUtil::mkdirs(char *szDirPath) 
    {
        struct stat stats;
        if (stat (szDirPath, &stats) == 0 && S_ISDIR (stats.st_mode)) 
            return true;
    
        mode_t umask_value = umask (0);
        umask (umask_value);
        mode_t mode = (S_IRWXUGO & (~ umask_value)) | S_IWUSR | S_IXUSR;
        
        char *slash = szDirPath;
    	while (*slash == '/')
    	    slash++;
        
        while (1)
    	{
    	    slash = strchr (slash, '/');
    	    if (slash == NULL)
    	        break;
    	        
            *slash = '\0';
            int ret = mkdir(szDirPath, mode);
            *slash++ = '/';
            if (ret && errno != EEXIST) {
                return false;
            }
            
    	    while (*slash == '/')
    	        slash++;
        }
        if (mkdir(szDirPath, mode)) {
            return false;
        }
        return true;
    }

    // �Ƿ�ΪĿ¼
    bool FileUtil::isDirectory(const char *szDirPath)
    {
        struct stat stats;
        if (lstat (szDirPath, &stats) == 0 && S_ISDIR (stats.st_mode))
            return true;
        return false;
    }

    // �Ƿ�Ϊislnk
    bool FileUtil::isSymLink(const char *szDirPath)
    {
        struct stat stats;
        if (lstat (szDirPath, &stats) == 0 && S_ISLNK (stats.st_mode)) 
            return true;
        return false; 
    }
}
