cmake_minimum_required (VERSION 2.8)
project (Example1)

include_directories (/usr/local/include /usr/local/opt/libxml2/include/libxml2)
link_directories (/usr/local/lib /usr/local/opt/libxml2/lib)

add_definitions(-std=c++14)

add_executable (Example1 example1.cpp)

target_link_libraries (Example1 armadillo mlpack boost_system boost_iostreams boost_filesystem)

set (CMAKE_BUILD_TYPE Release)
