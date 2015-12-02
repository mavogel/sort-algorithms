cmake_minimum_required(VERSION 3.3)
project(algorithm_lab)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g0 -O3")

set(SOURCE_FILES main.cpp)
add_executable(algorithm_lab_run ${SOURCE_FILES})

include_directories(algorithm_lab)

add_subdirectory(algorithm_lab)
add_subdirectory(algorithm_lab_tests)
add_subdirectory(algorithm_lab_time)

target_link_libraries(algorithm_lab_run algorithms_lab)