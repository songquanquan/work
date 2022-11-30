cmake_minimum_required(VERSION 3.23)
project(work)

set(CMAKE_CXX_STANDARD 14)

add_executable(work company.cpp apple.cpp)
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()