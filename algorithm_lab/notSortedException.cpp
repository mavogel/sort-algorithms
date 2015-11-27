#include "notSortedException.h"

NotSortedException::NotSortedException(size_t lowIndex, size_t highIndex) {
    this->lowIndex = lowIndex;
    this->highIndex = highIndex;
}

const char* NotSortedException::what() const throw() {
    std::string result = "The data between the indexes '[" + std::to_string(lowIndex) + ","+ std::to_string(highIndex) + "]' is not sorted.";
    return result.c_str();
}
