#include "testbuilder.h"

std::string toString(const FILL_MODE fillMode) {
    switch (fillMode) {
    case ASC:
        return "ASC ";
    case DESC:
        return "DESC";
    case RANDOM:
    default:
        return "RAND";
    }
}

std::ostream& operator<<(std::ostream& os, const FILL_MODE fillMode){
    os << toString(fillMode);
    return os;
}

std::string toString(const bool theBool) {
    return theBool ? "true " : "false";
}

void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase) {
    using namespace std::chrono;
    const unsigned int width = 10;

    std::cout << std::boolalpha;
    std::cout  << std::setprecision(width);
    std::cout << ">> " <<  testCase <<"\t-> " << std::setfill('0') << std::setw(width) << duration_cast<nanoseconds>(end-start).count() << "\tnanoseconds" << std::endl;
    std::cout << std::endl;
}
