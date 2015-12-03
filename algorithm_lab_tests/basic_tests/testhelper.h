#ifndef TESTHELPER
#define TESTHELPER

#include <array>
#include <random>
#include <iostream>
#include <cstdint>
#include <limits>
#include "gtest/gtest.h"

/**
 *  Verifies that the given array is sorted ASC.
 */
template <typename T, size_t SIZE>
void verifySorted(std::array<T, SIZE>& array) {
    for(size_t j = 1; j < SIZE; j++) {
        EXPECT_TRUE(array[j - 1] <= array[j]);
    }
}

/**
 * Print the given prompt if not empty
 *
 * @brief promptPrint
 * @param prompt the prompt to print
 */
void promptPrint(std::string prompt);

/**
 * Prints the contents of the array on the command line.
 * An optional prompt can be printed, as well as the marking the middle element
 */
template <typename T, size_t SIZE>
void print(std::array<T, SIZE>& array, std::string prompt = "", const bool showMid = false) {
    promptPrint(prompt);
    for(size_t i = 0; i < SIZE; i++) {
        if(showMid && i == (SIZE/2)) std::cout << "|";
        std::cout << array[i] << ", ";
    }
    std::cout << "\n";
}

/**
 * Prints the contents of the array on the command line.
 * An optional prompt can be printed, as well as the marking the middle element
 */
template <typename T, size_t SIZE>
void print(std::array<T, SIZE>& array, std::string prompt, size_t startIndex, size_t endIndex) {
    promptPrint(prompt);
    for(size_t i = startIndex; i <= endIndex; i++) {
        if(i == ((endIndex-startIndex)/2)) std::cout << "|";
        std::cout << array[i] << ", ";
    }
    std::cout << "\n";
}

/**
 * Prints the contents of the array on the command line
 */
template <typename T>
void print(std::vector<T>& vector, std::string prompt = "") {
    promptPrint(prompt);
    for(size_t i = 0; i < vector.size(); i++) {
        std::cout << "[" << i << "]:" << vector.at(i) << ", ";
    }
    std::cout << "\n";
}

/**
 *  Initializes the given array with random integer values in the range [INT_MIN,INT_MAX]
 */
template <size_t SIZE>
void initRandomIntegers(std::array<int, SIZE>& array) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(std::numeric_limits<std::int32_t>::min(),std::numeric_limits<std::int32_t>::max()); // guaranteed unbiased

    for(size_t i = 0; i < SIZE; i++) {
        auto random_integer = uni(rng);
        array[i] = random_integer;
    }
}

/**
 *  Initializes the given array with random double values in the range [INT_MIN,INT_MAX]
 */
template <size_t SIZE>
void initRandomDoubles(std::array<double, SIZE>& array) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<double> uni(std::numeric_limits<std::int32_t>::min(),std::numeric_limits<std::int32_t>::max());

    for(size_t i = 0; i < SIZE; i++) {
        auto random_double = uni(rng);
        array[i] = random_double;
    }
}

/**
 * Generates a random alphanumeric string with the given length
 * @param length the desired length
 * @return the random string
 */
std::string generateRandomString(size_t length);


/**
 * Initializes the given array with random strings with the size in the range [0, 200]
 */
template <size_t SIZE>
void initRandomStrings(std::array<std::string, SIZE>& array) {
    const int maxStringLength = 200;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,maxStringLength); // guaranteed unbiased

    for(size_t i = 0; i < SIZE; i++) {
        auto randomStringSize = uni(rng);
        array[i] = generateRandomString(randomStringSize);
    }
}


#endif // TESTHELPER

