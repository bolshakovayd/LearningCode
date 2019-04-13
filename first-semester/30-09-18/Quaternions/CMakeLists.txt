cmake_minimum_required(VERSION 3.13)
project(Quaternions)

set(CMAKE_CXX_STANDARD 14)

set(SRC_DIR ./src)
include_directories(${SRC_DIR})

add_library(Quaternions ${SRC_DIR}/Quaternion.cpp)
