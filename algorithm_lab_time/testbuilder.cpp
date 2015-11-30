#include "testbuilder.h"

std::string toString(const FILL_MODE fillMode) {
    switch (fillMode) {
    case FILL_MODE::ASC:
        return "ASC ";
    case FILL_MODE::DESC:
        return "DESC";
    case FILL_MODE::RANDOM:
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

void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase, std::ostream& os) {
    using namespace std::chrono;
    const unsigned int width = 10;

    unsigned long nanos = duration_cast<nanoseconds>(end-start).count();
    unsigned long micros = nanos / 10e3;
    unsigned long millis = nanos / 10e6;
    unsigned long seconds = nanos / 10e9;

    os << std::boolalpha << std::setprecision(width);
    os << ">> " <<  testCase <<"\t-> "
    << std::setfill('0') << std::setw(width) << seconds << "s\t"
    << std::setfill('0') << std::setw(width) << millis << "ms\t"
    << std::setfill('0') << std::setw(width)<< micros << "us\t"
    << std::setfill('0') << std::setw(width)<< nanos << "ns\n";
}
