#ifndef GENERATOR
#define GENERATOR

#include <random>
#include <cstdint>
#include <limits>
#include <array>
#ifdef _OPENMP
#include <omp.h>
#endif

/**
 * Fills a array with 20mb data
 *
 * @brief preTestFillArrayWith20mb
 */
void preTestFillArrayWith20mb();

/**
 * Generates a random double value between the given boundaries
 *
 * @brief generateRandomDouble
 * @param lowerBound the lower bound
 * @param upperBound the upper bound
 * @return the random double
 */
double generateRandomDouble(const int lowerBound, const int upperBound);

/**
 *  Initializes the given array with random double values in the range [INT_MIN,INT_MAX]
 */
template <size_t SIZE>
void initRandomDoubles(std::array<double, SIZE>& array) {
#ifdef _OPENMP
    #pragma omp parallel for num_threads(2)
#endif
    for(size_t i = 0; i < SIZE/2; i++) {
        array[i] = generateRandomDouble(std::numeric_limits<std::int32_t>::min(),std::numeric_limits<std::int32_t>::max());
        array[SIZE-i-1] = generateRandomDouble(std::numeric_limits<std::int32_t>::min(),std::numeric_limits<std::int32_t>::max());
    }
}

/**
 *  Initializes the given array with DESCENDING sorted double values
 */
template <size_t SIZE>
void initDescendingSortedDoubles(std::array<double, SIZE>& array) {
#ifdef _OPENMP
    #pragma omp parallel for num_threads(2)
#endif
    for(size_t i = 0; i < SIZE/2; i++) {
        array[i] = SIZE-1-i;
        array[SIZE-i-1] = i;
    }
}

/**
 *  Initializes the given array with ASCENDING sorted double values
 */
template <size_t SIZE>
void initAscendingSortedDoubles(std::array<double, SIZE>& array) {
#ifdef _OPENMP
    #pragma omp parallel for num_threads(2)
#endif
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = i;
    }
}

#endif // GENERATOR

