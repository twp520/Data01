cmake_minimum_required(VERSION 3.12)
project(Data01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data01 DynamicArray.h DynamicArray.cpp main.cpp LinkedArray.h LinkedArray.cpp LinkedList.h LinkedList.cpp)