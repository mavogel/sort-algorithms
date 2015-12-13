#ifndef MINSEARCH
#define MINSEARCH

#include "dataEmptyException.h"
#include "indexOutOfRangeException.h"
#include <array>

/**
 * Determines the index of the minimum in a given array in an optimal way.
 */
template <typename T, size_t SIZE>
size_t optimalMinSearch(const std::array<T, SIZE>& array, const size_t startIndex = 0, const size_t endIndex = SIZE) {
    if(SIZE == 1) return 0;

    size_t minPos = startIndex;
    T min = array[startIndex];
    for(size_t i = (startIndex + 1); i < endIndex; i++) {
       if(array[i] < min) {
           min = array[i];
           minPos = i;
       }
    }
    return minPos;
}

/**
 * Determines the index of the minimum in a given array in a NON-optimal way.
 */
template <typename T, size_t SIZE>
size_t nonOptimalMinSearch(const std::array<T, SIZE>& array, const size_t startIndex = 0) {
    if(SIZE == 1) return 0;

    size_t minPos = (SIZE - 1);
    T min = array[SIZE - 1];
    for(size_t i = (SIZE - 2); i >= startIndex; i--) {
       if(array[i] < min) {
           min = array[i];
           minPos = i;
       }
       if(i == 0) break;
    }
    return minPos;
}

#endif // MINSEARCH

