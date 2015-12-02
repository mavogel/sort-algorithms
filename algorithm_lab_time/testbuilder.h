#ifndef TESTBUILDER
#define TESTBUILDER

// Limits
#define MAX_ON2_ROUNDS 1024000
#define ROUNDS_1GB 131072000
#define ROUNDS_8GB 1048576000

#define GB_IN_BYTES 1000000000
#define MB_IN_BYTES 1000000
#define KB_IN_BYTES 1000

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
void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase, std::ostream& os, std::vector<double>& timings);

/**
 * Prints the timings in the desired LaTeX format for copy and paste
 */
void printTimings(std::ostream& os, size_t rounds, std::vector<double>& timings);

/**
 * Calculates and format the corresponding KB, MB or GBs from the rounds
 */
std::string getBytesSizeFromRounds(size_t rounds);

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
void runSortingAlgorithm(void (*sortFunction)(std::array<double, SIZE> &), std::array<double, SIZE> &array,
                         const FILL_MODE fillMode, std::ostream& os, std::vector<double>& timings) {
    pretestFill(array, fillMode);

    // == go ==
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(array);
    auto end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase, os, timings);
}

/**
 * Runs sorting algorithms in the given data
 */
template <size_t SIZE>
void runSortingAlgorithms(std::array<double, SIZE> &array) {
    std::vector<std::tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>> sortFunctions;
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaOptimalDirectSelection, "sortViaOptimalDirectSelection",
                                                                                                       MAX_ON2_ROUNDS));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaNonOptimalDirectSelection, "sortViaNonOptimalDirectSelection",
                                                                                                       MAX_ON2_ROUNDS));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaDirectInsertWithWatcherElement, "sortViaDirectInsertWithWatcherElement",
                                                                                                       MAX_ON2_ROUNDS));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaNormalDirectInsert, "sortViaNormalDirectInsert",
                                                                                                       MAX_ON2_ROUNDS));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaNaturalMergesort, "sortViaNaturalMergesort",
                                                                                                       ROUNDS_1GB));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaBottomUpMergesort, "sortViaBottomUpMergesort",
                                                                                                       ROUNDS_1GB));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortVia3WayPartitioningQuicksort, "sortVia3WayPartitioningQuicksort",
                                                                                                       ROUNDS_1GB));
    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t>(sortViaHybridQuicksort, "sortViaHybridQuicksort",
                                                                                                       ROUNDS_1GB));

    std::string name;
    void (*functionPointer) (std::array<double, SIZE>&);
    size_t maxSize;
    std::vector<double> timings;
    for(auto& sortFunction : sortFunctions) {
        timings.clear();
        if (SIZE <= maxSize) {
            std::tie(functionPointer, name, maxSize) = sortFunction;
            std::cout << name << ": '" << SIZE << "' doubles rounds (=" << getBytesSizeFromRounds(SIZE) << ")\n";
            runSortingAlgorithm(functionPointer, array, FILL_MODE::DESC, std::cout, timings);
            runSortingAlgorithm(functionPointer, array, FILL_MODE::RANDOM, std::cout, timings);
            runSortingAlgorithm(functionPointer, array, FILL_MODE::ASC, std::cout, timings);
            printTimings(std::cout, SIZE, timings);
            std::cout << "------------------------------------\n";
        }
    }
}

#endif // TESTBUILDER

