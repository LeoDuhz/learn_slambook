cmake_minimum_required(VERSION 3.2)

project(ch2)

set(CMAKE_CXX_STANDARD 20)

add_executable(nullptr nullptr.cpp)

add_executable(constexpr constexpr.cpp)

add_executable(initializer_list initializer_list.cpp)

add_executable(tuple tuple.cpp)

# add_executable(auto auto.cpp)

add_executable(decltype decltype.cpp)

add_executable(template1 template1.cpp)

add_executable(template2 template2.cpp)

add_executable(template3 template3.cpp)

add_executable(template4 template4.cpp)