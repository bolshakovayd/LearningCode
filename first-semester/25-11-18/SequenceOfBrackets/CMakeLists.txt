cmake_minimum_required(VERSION 3.13)
project(SequenceOfBrackets)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ./src)
include_directories(${SRC_DIR})

add_executable(SequenceOfBrackets ${SRC_DIR}/main.cpp ${SRC_DIR}/Stack.cpp)
