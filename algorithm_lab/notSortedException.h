#ifndef NOTSORTEDEXCEPTION
#define NOTSORTEDEXCEPTION

#include <exception>
#include <string>

class NotSortedException : public std::exception {

private:
    size_t lowIndex, highIndex;

public:
    NotSortedException(size_t lowIndex, size_t highIndex);
    virtual const char* what() const throw();
};

#endif // NOTSORTEDEXCEPTION

