add_definitions(-std=c++14 -Wall -g0 -O3)

add_executable(timeMeasuring
        generator.cpp testbuilder.cpp main.cpp
        )
target_link_libraries(timeMeasuring algorithms_lab)