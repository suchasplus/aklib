#ifndef AK_H
#define AK_H

#include <assert.h>
#include <errno.h>
#include <cassert>
#include <iostream>
#include <sstream>
#include <pthread.h>
#include <vector>
#include <string>

#ifndef UNUSED
#define UNUSED(v) ((void)(v))
#endif


namespace ak {

class StringUtil;
class FileUtil;
class IniUtil;
class KVConfUtil;

}

#endif //end AK_H
