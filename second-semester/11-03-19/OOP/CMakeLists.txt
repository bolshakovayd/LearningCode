cmake_minimum_required(VERSION 3.13)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ./src)
include_directories(${SRC_DIR})

add_executable(OOP ${SRC_DIR}/main.cpp ${SRC_DIR}/utils.cpp ${SRC_DIR}/types.cpp)
