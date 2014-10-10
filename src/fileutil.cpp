#include "fileutil.h"

namespace ak {
    /** 
     * 创建多级目录, 在父目录不存在一同创建
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

    // 是否为目录
    bool FileUtil::isDirectory(const char *szDirPath)
    {
        struct stat stats;
        if (lstat (szDirPath, &stats) == 0 && S_ISDIR (stats.st_mode))
            return true;
        return false;
    }

    // 是否为SymLnk
    bool FileUtil::isSymLink(const char *szDirPath)
    {
        struct stat stats;
        if (lstat (szDirPath, &stats) == 0 && S_ISLNK (stats.st_mode)) 
            return true;
        return false; 
    }

    bool FileUtil::resolveRelativePath(std::string & path, const std::string & base) {

#ifndef __WIN32__
        if (path.empty() || path[0] != '/') {
            // path is relative.
            string::size_type last_slash = base.rfind('/');
            if (last_slash != string::npos) {
                path.insert(0, base, 0, last_slash + 1);
            }
        }
#else
#error "WINDOWS is NOT supported"
#endif
    }


}

