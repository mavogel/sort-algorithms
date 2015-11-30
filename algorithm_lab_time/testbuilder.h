#ifndef TESTBUILDER
#define TESTBUILDER

#define MAX_ON2_ROUNDS 1024000
#define SIZE_1GB 131072000
#define SIZE_8GB 1048576000

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
template <size_t SIZE>
void testOptimalDirectSelection(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
    if(SIZE <= MAX_ON2_ROUNDS) {
        pretestFill(array, fillMode);

        // == go ==
        auto start = std::chrono::high_resolution_clock::now();
        sortViaOptimalDirectSelection(array);
        auto end = std::chrono::high_resolution_clock::now();

        // == evaluate ==
        std::string testCase = toString(fillMode) + " - optimal: true";
        afterTestEvaluation(start, end, testCase);
    }
}

/**
 * Tests the direct selection sort in different fill modes.
 */
template <size_t SIZE>
void testNonOptimalDirectSelection(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
    if(SIZE <= MAX_ON2_ROUNDS) {
        pretestFill(array, fillMode);

        // == go ==
        auto start = std::chrono::high_resolution_clock::now();
        sortViaNonOptimalDirectSelection(array);
        auto end = std::chrono::high_resolution_clock::now();

        // == evaluate ==
        std::string testCase = toString(fillMode) + " - optimal: true";
        afterTestEvaluation(start, end, testCase);
    }
}

/**
 * Test direct insertion sort in different fill modes.
 */
template <size_t SIZE>
void testDirectInsertWithWatcher(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
    if(SIZE <= MAX_ON2_ROUNDS) {
        pretestFill(array, fillMode);

        // == go ==
        auto start = std::chrono::high_resolution_clock::now();
        sortViaDirectInsertWithWatcherElement(array);
        auto end = std::chrono::high_resolution_clock::now();

        // == evaluate ==
        std::string testCase = toString(fillMode) + " - watcher: true";
        afterTestEvaluation(start, end, testCase);
    }
}

/**
 * Test direct insertion sort in different fill modes.
 */
template <size_t SIZE>
void testNormalDirectInsert(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
    if(SIZE <= MAX_ON2_ROUNDS) {
        pretestFill(array, fillMode);

        // == go ==
        auto start = std::chrono::high_resolution_clock::now();
        sortViaDirectInsertWithWatcherElement(array);
        auto end = std::chrono::high_resolution_clock::now();

        // == evaluate ==
        std::string testCase = toString(fillMode) + " - watcher: false";
        afterTestEvaluation(start, end, testCase);
    }
}

/**
 * Test natural merge sort in different fill modes.
 */
template <size_t SIZE>
void testNaturalMergeSort(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
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
void testBottomUpMergeSort(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
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
void test3WayPartitioningQuickSort(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
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
void testHybrid3WayPartitioningQuickSort(std::array<double, SIZE>& array, const FILL_MODE fillMode, const bool printTexTable) {
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortViaHybridQuicksort(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase);
}

template <size_t SIZE>
void runCombination2(std::array<double, SIZE>& array) {
    //auto
}

/**
 * Runs all possible combinations of algorithms and fill modes
 */
template <size_t SIZE>
void runCombination(std::array<double, SIZE>& array) {
    bool printTexTable = false;
    if(SIZE == SIZE_1GB) printTexTable = true;

    std::cout << "Direct Selection Sort: '" << SIZE << "' doubles rounds" << std::endl;
    testOptimalDirectSelection(array, DESC, printTexTable);
    testOptimalDirectSelection(array, RANDOM, printTexTable);
    testOptimalDirectSelection(array, ASC, printTexTable);
    testNonOptimalDirectSelection(array, DESC, printTexTable);
    testNonOptimalDirectSelection(array, RANDOM, printTexTable);
    testNonOptimalDirectSelection(array, ASC, printTexTable);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "Direct Insert Sort: '" << SIZE << "' doubles rounds" << std::endl;
    testDirectInsertWithWatcher(array, DESC, printTexTable);
    testDirectInsertWithWatcher(array, RANDOM, printTexTable);
    testDirectInsertWithWatcher(array, ASC, printTexTable);
    testNormalDirectInsert(array, DESC, printTexTable);
    testNormalDirectInsert(array, RANDOM, printTexTable);
    testNormalDirectInsert(array, ASC, printTexTable);
    std::cout << "------------------------------------" << std::endl;


    std::cout << "Natural Mergesort: '" << SIZE << "' doubles rounds" << std::endl;
    testNaturalMergeSort(array, DESC, printTexTable);
    testNaturalMergeSort(array, RANDOM, printTexTable);
    testNaturalMergeSort(array, ASC, printTexTable);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "Bottom-Up Mergesort: '" << SIZE << "' doubles rounds" << std::endl;
    testBottomUpMergeSort(array, DESC, printTexTable);
    testBottomUpMergeSort(array, RANDOM, printTexTable);
    testBottomUpMergeSort(array, ASC, printTexTable);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "3-way-partitioning Quicksort: '" << SIZE << "' doubles rounds" << std::endl;
    test3WayPartitioningQuickSort(array, DESC, printTexTable);
    test3WayPartitioningQuickSort(array, RANDOM, printTexTable);
    test3WayPartitioningQuickSort(array, ASC, printTexTable);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "HYBRID 3-way-partitioning Quicksort: '" << SIZE << "' doubles rounds" << std::endl;
    testHybrid3WayPartitioningQuickSort(array, DESC, printTexTable);
    testHybrid3WayPartitioningQuickSort(array, RANDOM, printTexTable);
    testHybrid3WayPartitioningQuickSort(array, ASC, printTexTable);
}

#endif // TESTBUILDER

