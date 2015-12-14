#ifndef MINSEARCH
#define MINSEARCH

#include <array>

/**
 * Determines the index of the minimum in a given array in an optimal way.
 *
 * @param array the array to find the minimum in
 * @param startIndex the start index (INCLUSIVE)
 * @param endIndex the end index (EXCLUSIVE)
 * @return the index of the minimum
 */
template <typename T, size_t SIZE>
size_t optimalMinSearch(const std::array<T, SIZE>& array, const size_t startIndex = 0, const size_t endIndex = SIZE) {
    if(SIZE == 1) return 0;

    size_t minPos = startIndex;
    for(size_t i = (startIndex + 1); i < endIndex; i++) {
       if(array[i] < array[minPos]) minPos = i;
    }
    return minPos;
}

/**
 * Determines the index of the minimum in a given array in a NON-optimal way.
 *
 * @param array the array to find the minimum in
 * @param startIndex the start index (INCLUSIVE)
 * @return the index of the minimum
 */
template <typename T, size_t SIZE>
size_t nonOptimalMinSearch(const std::array<T, SIZE>& array, const size_t startIndex = 0, const size_t endIndex = SIZE) {
    if(SIZE == 1) return 0;

    size_t minPos = endIndex - 1;
    for(size_t i = (endIndex - 1); i > startIndex;) {
       if(array[--i] < array[minPos]) minPos = i;
    }
    return minPos;
}

#endif // MINSEARCH

