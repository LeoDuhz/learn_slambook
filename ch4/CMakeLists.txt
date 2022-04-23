cmake_minimum_required(VERSION 3.0)
project(useSophus)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)

# 为使用 sophus，需要使用find_package命令找到它
# find_package(Sophus REQUIRED)
# find_package(fmt REQUIRED)

set(Sophus_INCLUDE_DIRS "/Users/leo/dhz/slam14/slambook2/ch4/sophus") 
set(Sophus_LIBS "/Users/leo/dhz/slam14/slambook2/ch4/sophus/build/libSophus.dylib")
include_directories(${Sophus_INCLUDE_DIRS})

# Eigen
include_directories("/usr/local/include/eigen3")
# include_directories("/usr/local/include/sophus")
add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus ${Sophus_LIBS})
# target_link_libraries(useSophus fmt::fmt)

add_subdirectory(example)
add_subdirectory(pangolin)
# add_subdirectory(sophus)
