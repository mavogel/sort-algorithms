#ifndef MINSEARCH
#define MINSEARCH

#include <array>

/**
 * Determines the index of the minimum in a given array in an optimal way.
 *
 * @param array the array to find the minimum in
 * @param lo the lower bound (INCLUSIVE)
 * @param hi the higher bound (EXCLUSIVE)
 * @return the index of the minimum
 */
template <typename T, size_t SIZE>
size_t optimalMinSearch(const std::array<T, SIZE>& array, const size_t lo = 0, const size_t hi = SIZE) {
    if((hi - lo) == 1) return lo;

    size_t minPos = lo;
    for(size_t i = (lo + 1); i < hi; i++) {
       if(array[i] < array[minPos]) minPos = i;
    }
    return minPos;
}

/**
 * Determines the index of the minimum in a given array in a NON-optimal way.
 *
 * @param array the array to find the minimum in
 * @param lo the lower bound (INCLUSIVE)
 * @param hi the higher bound (EXCLUSIVE)
 * @return the index of the minimum
 */
template <typename T, size_t SIZE>
size_t nonOptimalMinSearch(const std::array<T, SIZE>& array, const size_t lo = 0, const size_t hi = SIZE) {
    if((hi - lo) == 1) return lo;

    size_t minPos = hi - 1;
    for(size_t i = (hi - 1); i > lo;) {
       if(array[--i] < array[minPos]) minPos = i;
    }
    return minPos;
}

#endif // MINSEARCH

