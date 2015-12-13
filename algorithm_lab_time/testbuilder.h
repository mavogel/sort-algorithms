#ifndef TESTBUILDER
#define TESTBUILDER

#define ROUNDS_K1              125
#define ROUNDS_K2              250
#define ROUNDS_K4              500
#define ROUNDS_K8            1'000
#define ROUNDS_K16           2'000
#define ROUNDS_K32           4'000
#define ROUNDS_K64           8'000
#define ROUNDS_K128         16'000
#define ROUNDS_K256         32'000
#define ROUNDS_K512         64'000
#define ROUNDS_M1          128'000
#define ROUNDS_M2          256'000
#define ROUNDS_M4          512'000
#define ROUNDS_M8        1'024'000
#define ROUNDS_M16       2'048'000
#define ROUNDS_M32       4'096'000
#define ROUNDS_M64       8'192'000
#define ROUNDS_M128     16'384'000
#define ROUNDS_M256     32'768'000
#define ROUNDS_M512     65'536'000
#define ROUNDS_G1       131'072'000
#define ROUNDS_G2       262'144'000
#define ROUNDS_G4       524'288'000

#define GB_IN_BYTES 1024000000
#define MB_IN_BYTES 1024000
#define KB_IN_BYTES 1024

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
void afterTestEvaluation(std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& end, std::string& testCase, std::ostream& os, std::vector<double>& timings);

/**
 * Prints the timings in the desired LaTeX format for copy and paste
 *
 * @param os the output stream
 * @param rounds the rounds/size of the current run
 * @param timings the timings to print
 */
void printTimingsForTex(std::ostream& os, size_t rounds, std::vector<double>& timings);

/**
 * Prints the duration in seconds and ms with the given prompt if not empty
 *
 * @param os the output stream
 * @param prompt the possible empty prompt before the output
 * @start the timepoint of the start of the measuring
 * @end the timepoint of the end of the measuring
 */
void printDuration(std::ostream& os, std::string& prompt, std::chrono::high_resolution_clock::time_point& start, std::chrono::high_resolution_clock::time_point& end);

/**
 * Calculates and format the corresponding KB, MB or GBs from the rounds
 *
 * @param rounds the rounds
 */
std::string getBytesSizeFromRounds(size_t rounds);

/**
 * Fills the array in the given mode.
 *
 * @param array the array to fill
 * @param fillMode the mode how the array is filled
 * @os the output stream
 */
template <size_t SIZE>
void pretestFill(std::array<double, SIZE>& array, const FILL_MODE fillMode, std::ostream& os) {
    std::chrono::high_resolution_clock::time_point preFillStart = std::chrono::high_resolution_clock::now();
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
    std::chrono::high_resolution_clock::time_point preFillEnd = std::chrono::high_resolution_clock::now();
    std::string prompt = "prefill ("  + toString(fillMode) + ")";
    printDuration(os, prompt, preFillStart, preFillEnd);

    // clears L2 & 3 Cache
    preTestFillArrayWith20mb();
}

/**
 * Tests the given sortFunction with the data of the array which will be filled in the desired mode
 *
 * @param sortFunction the function pointer to the sort algorithm
 * @param array the array to apply the sort algorithm on
 * @param fillMode the mode how the array is filled
 * @param os the output stream
 * @timings the timings of each round
 */
template <size_t SIZE>
void runSortingAlgorithm(void (*sortFunction)(std::array<double, SIZE> &), std::array<double, SIZE> &array,
                         const FILL_MODE fillMode, std::ostream& os, std::vector<double>& timings) {

    // == prepare ==
    pretestFill(array, fillMode, os);

    // == go ==
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    sortFunction(array);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // == evaluate ==
    std::string testCase = toString(fillMode);
    afterTestEvaluation(start, end, testCase, os, timings);
}

/**
 * Runs sorting algorithms in the given data
 *
 * @param array the data array to run the sort algorithm on
 */
template <size_t SIZE>
void runSortingAlgorithms(std::array<double, SIZE> &array) {
    std::vector<std::tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>> sortFunctions;

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaOptimalDirectSelection, "sortViaOptimalDirectSelection", ROUNDS_K1, ROUNDS_M8, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaNonOptimalDirectSelection, "sortViaNonOptimalDirectSelection", ROUNDS_K1, ROUNDS_M8, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaDirectInsertWithWatcherElement, "sortViaDirectInsertWithWatcherElement", ROUNDS_K1, ROUNDS_M8, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaNormalDirectInsert, "sortViaNormalDirectInsert", ROUNDS_K1, ROUNDS_M8, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaNaturalMergesort, "sortViaNaturalMergesort", ROUNDS_K1, ROUNDS_M8, true));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaBottomUpMergesort, "sortViaBottomUpMergesort", ROUNDS_K1, ROUNDS_M1, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortVia3WayPartitioningQuicksort, "sortVia3WayPartitioningQuicksort", ROUNDS_K1, ROUNDS_G4, false));

    sortFunctions.push_back(std::make_tuple<void (*) (std::array<double, SIZE>&), std::string, size_t, size_t, bool>(
            sortViaHybridQuicksort, "sortViaHybridQuicksort", ROUNDS_K1, ROUNDS_M1, true));

    std::string name;
    void (*functionPointer) (std::array<double, SIZE>&);
    size_t minSize = 0, maxSize = ROUNDS_G4;
    std::vector<double> timings;
    bool isActive = true;
    for(auto& sortFunction : sortFunctions) {
        timings.clear();
        std::tie(functionPointer, name, minSize, maxSize, isActive) = sortFunction;
        if (isActive && SIZE >= minSize && SIZE <= maxSize) {
            std::cout << name << ": '" << SIZE << "' doubles rounds (=" << getBytesSizeFromRounds(SIZE) << ")\n";
            runSortingAlgorithm(functionPointer, array, FILL_MODE::DESC, std::cout, timings);
            runSortingAlgorithm(functionPointer, array, FILL_MODE::RANDOM, std::cout, timings);
            runSortingAlgorithm(functionPointer, array, FILL_MODE::ASC, std::cout, timings);
            printTimingsForTex(std::cout, SIZE, timings);
            std::cout << "------------------------------------\n";
        }
    }
}

#endif // TESTBUILDER

