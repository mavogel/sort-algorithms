add_definitions(-std=c++14 -Wall -g0 -O3)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
add_executable(timeMeasuring
        generator.cpp testbuilder.cpp main.cpp
        )
target_link_libraries(timeMeasuring algorithms_lab)