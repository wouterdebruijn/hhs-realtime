cmake_minimum_required(VERSION 3.0.0)
project(ExerciseC VERSION 0.1.0)

# Use C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add thread support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Add Buffer class
add_library(Buffer SHARED Buffer.cpp Buffer.hpp)

# Add Sensor class
add_library(Sensor SHARED Sensor.cpp Sensor.hpp)

# Add Verwerker class
add_library(Verwerker SHARED Verwerker.cpp Verwerker.hpp)

add_executable(ExerciseC main.cpp)

# Link Threads to main
target_link_libraries(ExerciseC PUBLIC Threads::Threads)

# Link Buffer to Sensor
target_link_libraries(ExerciseC PUBLIC Buffer)

# Link Sensor to Verwerker
target_link_libraries(ExerciseC PUBLIC Sensor)

# Link Verwerker to main
target_link_libraries(ExerciseC PUBLIC Verwerker)

target_include_directories(ExerciseC PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
