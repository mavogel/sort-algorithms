#ifndef GENERATOR
#define GENERATOR

#include <random>

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
 * @param lowerBound the lower bound @default INT_MIN
 * @param upperBound the upper bound @default INT_MAX
 * @return the random double
 */
double generateRandomDouble(const int lowerBound = INT_MIN, const int upperBound = INT_MAX);

/**
 *  Initializes the given array with random double values in the range [INT_MIN,INT_MAX]
 */
template <size_t SIZE>
void initRandomDoubles(std::array<double, SIZE>& array) {
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = generateRandomDouble(INT_MIN, INT_MAX);
    }
}

/**
 *  Initializes the given array with DESCENDING sortet double values
 */
template <size_t SIZE>
void initDescendingSortedDoubles(std::array<double, SIZE>& array) {
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = SIZE-1-i;
    }
}

/**
 *  Initializes the given array with ASCENDING sortet double values
 */
template <size_t SIZE>
void initAscendingSortedDoubles(std::array<double, SIZE>& array) {
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = i;
    }
}

#endif // GENERATOR

