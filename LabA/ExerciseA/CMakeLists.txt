cmake_minimum_required(VERSION 3.0.0)
project(ExerciseA VERSION 0.1.0)

include(CTest)
enable_testing()

# Add main.cpp
add_executable(ExerciseA main.cpp)

add_library(timer Timer.cpp)
target_link_libraries(ExerciseA timer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
