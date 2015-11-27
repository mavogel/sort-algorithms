#include "dataEmptyException.h"

const char* DataEmptyException::what() const throw() {
    return "The data is empty.";
}
