cmake_minimum_required(VERSION 3.2)

project(ch2)

set(CMAKE_CXX_STANDARD 17)

add_executable(nullptr nullptr.cpp)

add_executable(constexpr constexpr.cpp)

add_executable(initializer_list initializer_list.cpp)

add_executable(tuple tuple.cpp)