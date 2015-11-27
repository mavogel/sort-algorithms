#ifndef TESTBUILDER
#define TESTBUILDER

#include "generator.h"
#include "sorters.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstdarg>

/**
 * The mode of order how the doubles are filled into the array
 * @brief The FILL_MODE enum
 */
enum FILL_MODE {
    ASC = 0,
    DESC,
    RANDOM
};

/**
 * Converts the fillmode enum to a string
 *
 * @brief toString
 * @param fillMode the fill mode
 * @return the corresponding string
 */
std::string toString(const FILL_MODE fillMode);

/**
 * Converts a bool to a string
 *
 * @brief toString
 * @param bool theBool
 * @return the corresponding string
 */
std::string toString(const bool theBool);

/**
 * Overloads the '<<'-operator for printing the name of an FILL_MODE enum
 *
 * @brief operator <<
 * @param os the output stream
 * @param fillMode the value of the FILL_MODE enum
 * @return the string representation of the enum value
 */
std::ostream& operator<<(std::ostream& os, const FILL_MODE fillMode);

/**
 * Evaluates the time measurement results and prints them
 *
 * @brief afterTestEvaluation
 * @param start the start time
 * @param end the end time
 * @param testCase the context of the current test case
 */
void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase);

/**
 * Fills the array in the given mode
 */
template <size_t SIZE>
void pretestFill(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    switch (fillMode) {
        case ASC:
            initAscendingSortedDoubles(array);
        break;
        case DESC:
            initDescendingSortedDoubles(array);
        case RANDOM:
        default:
            initRandomDoubles(array);
        break;
    }

    // clears L2 & 3 Cache
    preTestFillArrayWith20mb();
}

/**
 * Tests the direct selection sort in different fill modes.
 */
template <bool OPTIMAL, size_t SIZE>
void testDirectSelection(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    steady_clock::time_point start = steady_clock::now();
    sortViaDirectSelection<OPTIMAL>(array);
    steady_clock::time_point end = steady_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode) + " - optimal: " + toString(OPTIMAL);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Test direct insertion sort in different fill modes.
 */
template <bool WATCHER, size_t SIZE>
void testDirectInsert(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortViaDirectInsert<WATCHER>(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode) + " - watcher: " + toString(WATCHER);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Test natural merge sort in different fill modes.
 */
template <size_t SIZE>
void testNaturalMergeSort(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortViaNaturalMergesort(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Test bottom-up merge sort in different fill modes.
 */
template <size_t SIZE>
void testBottomUpMergeSort(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortViaBottomUpMergesort(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Test 3-way-partitioning quicksort in different fill modes.
 */
template <size_t SIZE>
void test3WayPartitioningQuickSort(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortVia3WayPartitioningQuicksort(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Test hybrid 3-way-partitioning quicksort in different fill modes.
 */
template <size_t SIZE>
void testHybrid3WayPartitioningQuickSort(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    using namespace std::chrono;
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortViaHybridQuicksort(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase);
}

/**
 * Runs all possible combinations of algorithms and fill modes
 */
template <size_t SIZE>
void runCombination(std::array<double, SIZE>& array) {
//    std::cout << "Direct Selection Sort: '" << SIZE << "' doubles rounds" << std::endl;
//    testDirectSelection<true>(array, DESC);
//    testDirectSelection<true>(array, RANDOM);
//    testDirectSelection<true>(array, ASC);
//    testDirectSelection<false>(array, DESC);
//    testDirectSelection<false>(array, RANDOM);
//    testDirectSelection<false>(array, ASC);
//    std::cout << "------------------------------------" << std::endl;

//    std::cout << "Direct Insert Sort: '" << SIZE << "' doubles rounds" << std::endl;
//    testDirectInsert<true>(array, DESC);
//    testDirectInsert<true>(array, RANDOM);
//    testDirectInsert<true>(array, ASC);
//    testDirectInsert<false>(array, DESC);
//    testDirectInsert<false>(array, RANDOM);
//    testDirectInsert<false>(array, ASC);
//    std::cout << "------------------------------------" << std::endl;

    std::cout << "Natural Mergesort: '" << SIZE << "' doubles rounds" << std::endl;
    testNaturalMergeSort(array, DESC);
    testNaturalMergeSort(array, RANDOM);
    testNaturalMergeSort(array, ASC);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "Bottom-Up Mergesort: '" << SIZE << "' doubles rounds" << std::endl;
    testBottomUpMergeSort(array, DESC);
    testBottomUpMergeSort(array, RANDOM);
    testBottomUpMergeSort(array, ASC);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "3-way-partitioning Quicksort: '" << SIZE << "' doubles rounds" << std::endl;
    test3WayPartitioningQuickSort(array, DESC);
    test3WayPartitioningQuickSort(array, RANDOM);
    test3WayPartitioningQuickSort(array, ASC);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "HYBRID 3-way-partitioning Quicksort: '" << SIZE << "' doubles rounds" << std::endl;
    testHybrid3WayPartitioningQuickSort(array, DESC);
    testHybrid3WayPartitioningQuickSort(array, RANDOM);
    testHybrid3WayPartitioningQuickSort(array, ASC);
}

#endif // TESTBUILDER

