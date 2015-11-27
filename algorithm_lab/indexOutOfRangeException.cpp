#include "indexOutOfRangeException.h"

IndexOutOfRangeException::IndexOutOfRangeException(size_t lowIndex, size_t highIndex, size_t minIndex, size_t maxIndex) {
    this->lowIndex = lowIndex;
    this->highIndex = highIndex;
    this->minIndex = minIndex;
    this->maxIndex = maxIndex;
}

const char* IndexOutOfRangeException::what() const throw() {
    std::string result = "The indexes '[" + std::to_string(lowIndex) + ","+ std::to_string(highIndex) + "]' are out of range. They should be [" + std::to_string(minIndex)  + "," + std::to_string(maxIndex) + "]";
    return result.c_str();
}

