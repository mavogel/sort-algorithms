#ifndef INDEXOUTOFRANGE
#define INDEXOUTOFRANGE

#include <exception>
#include <string>

class IndexOutOfRangeException : public std::exception {

private:
    size_t lowIndex, highIndex, minIndex, maxIndex;

public:
    IndexOutOfRangeException(size_t lowIndex, size_t highIndex, size_t minIndex = 0, size_t maxIndex = INT64_MAX);
    virtual const char* what() const throw();
};

#endif // INDEXOUTOFRANGE

