include_directories("/usr/include/eigen3")
add_executable(coordinateTransform coordinateTransform.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})

add_library(libDraw SHARED Draw.cpp)
add_executable(plotCamera plotCamera.cpp)
target_link_libraries(plotCamera ${Pangolin_LIBRARIES} libDraw)
