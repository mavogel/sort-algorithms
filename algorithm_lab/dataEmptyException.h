#ifndef DATAEMPTYEXCEPTION
#define DATAEMPTYEXCEPTION

#include <exception>

class DataEmptyException : public std::exception {
    virtual const char* what() const throw();
};

#endif // DATAEMPTYEXCEPTION

