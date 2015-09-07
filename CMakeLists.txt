# CMake build script for AKLib
# Powered by suchasplus

# Name of the project
# Cmake files in this project can refer to the root source dir

# Language "C" is required for find_package(Threads)
project(aklib CXX C)

# Where aklib's .h files can be found
include_directories(
    ${aklib_SOURCE_DIR}/include
    ${aklib_SOURCE_DIR})

# Where aklib's libraries can be found
link_directories(${aklib_BINARY_DIR}/src)
