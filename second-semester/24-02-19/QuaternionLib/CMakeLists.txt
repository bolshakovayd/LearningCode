cmake_minimum_required(VERSION 3.13)
project(QuaternionLib)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ./src)
include_directories(${SRC_DIR})

add_executable(QuaternionLib ${SRC_DIR}/main.cpp ${SRC_DIR}/QuaternionLib.cpp)
