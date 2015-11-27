cmake_minimum_required(VERSION 3.3)
project(algorithm_lab)

add_definitions(-std=c++14 -Wall -g0 -O3)

set(HEADER_FILES
        dataEmptyException.h
        indexOutOfRangeException.h
        notSortedException.h
        minsearch.h
        sorters.h
        )

set(SOURCE_FILES
        dataEmptyException.cpp
        indexOutOfRangeException.cpp
        notSortedException.cpp
        sorters.cpp
        )

add_library(algorithms_lab STATIC ${SOURCE_FILES} ${HEADER_FILES})