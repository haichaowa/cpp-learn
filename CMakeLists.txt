cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)

project(CppLearn)
add_executable(twosum leetcode/hot100/01_TwoSum.cpp)

set(HOME build)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(LIBRARY_OUTPUT_PATH ${HOME}/lib)