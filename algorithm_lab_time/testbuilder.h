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
enum class FILL_MODE {
    ASC,
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
 * @param os the outputstream
 */
void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase, std::ostream& os);

/**
 * Fills the array in the given mode
 */
template <size_t SIZE>
void pretestFill(std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    switch (fillMode) {
        case FILL_MODE::ASC:
            initAscendingSortedDoubles(array);
        break;
        case FILL_MODE::DESC:
            initDescendingSortedDoubles(array);
        case FILL_MODE::RANDOM:
        default:
            initRandomDoubles(array);
        break;
    }

    // clears L2 & 3 Cache
    preTestFillArrayWith20mb();
}

/**
 * Tests the given sortFunction with the data of the array which will be filled in the desired mode
 */
template <size_t SIZE>
void testSortFunction(void (*sortFunction) (std::array<double, SIZE>&), std::array<double, SIZE>& array, const FILL_MODE fillMode) {
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase, std::cout);
}

/**
 * Runs sorting algorithms in the given data
 */
template <size_t SIZE>
void runSortingAlgorithms(std::array<double, SIZE> &array) {
    std::vector<std::pair<void (*) (std::array<double, SIZE>&), std::string>> sortFunctions;
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaOptimalDirectSelection, "sortViaOptimalDirectSelection"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaNonOptimalDirectSelection, "sortViaNonOptimalDirectSelection"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaDirectInsertWithWatcherElement, "sortViaDirectInsertWithWatcherElement"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaNormalDirectInsert, "sortViaNormalDirectInsert"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaNaturalMergesort, "sortViaNaturalMergesort"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaBottomUpMergesort, "sortViaBottomUpMergesort"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortVia3WayPartitioningQuicksort, "sortVia3WayPartitioningQuicksort"));
    sortFunctions.push_back(std::make_pair<void (*) (std::array<double, SIZE>&), std::string>(sortViaHybridQuicksort, "sortViaHybridQuicksort"));

    for(auto&sortFunction : sortFunctions) {
        std::cout << sortFunction.second << ": '" << SIZE << "' doubles rounds\n";
        testSortFunction(sortFunction.first, array, FILL_MODE::DESC);
        testSortFunction(sortFunction.first, array, FILL_MODE::RANDOM);
        testSortFunction(sortFunction.first, array, FILL_MODE::ASC);
        std::cout << "------------------------------------\n";
    }
}

#endif // TESTBUILDER

