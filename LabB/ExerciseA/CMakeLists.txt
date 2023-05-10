cmake_minimum_required(VERSION 3.0.0)
project(ExerciseA VERSION 0.1.0)

# Add Buffer class
add_library(Buffer SHARED Buffer.cpp Buffer.hpp)

# Add Sensor class
add_library(Sensor SHARED Sensor.cpp Sensor.hpp)

# Add Verwerker class
add_library(Verwerker SHARED Verwerker.cpp Verwerker.hpp)

# Add thread support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(ExerciseA main.cpp)

# Link Threads to main
target_link_libraries(ExerciseA PUBLIC Threads::Threads)

# Link Buffer to Sensor
target_link_libraries(ExerciseA PUBLIC Buffer)

# Link Sensor to Verwerker
target_link_libraries(ExerciseA PUBLIC Sensor)

# Link Verwerker to main
target_link_libraries(ExerciseA PUBLIC Verwerker)

target_include_directories(ExerciseA PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
