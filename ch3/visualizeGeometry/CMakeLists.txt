cmake_minimum_required( VERSION 2.8 )
project( visualizeGeometry )

set(CMAKE_CXX_FLAGS "-std=c++11")

# 添加Eigen头文件
include_directories( "/usr/local/include/eigen3" )

# 添加Pangolin依赖
find_package( Pangolin REQUIRED)
# include_directories(  )

add_executable( visualizeGeometry visualizeGeometry.cpp )
# target_link_libraries( visualizeGeometry ${Pangolin_LIBRARIES} )
target_link_libraries( visualizeGeometry pangolin )
