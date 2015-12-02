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

void afterTestEvaluation(std::chrono::steady_clock::time_point& start, std::chrono::steady_clock::time_point& end, std::string& testCase, std::ostream& os, std::vector<double>& timings) {
    using namespace std::chrono;
    const unsigned int width = 12;

    unsigned long nanos = duration_cast<nanoseconds>(end-start).count();
    unsigned long micros = duration_cast<microseconds>(end-start).count();
    unsigned long millis = duration_cast<milliseconds>(end-start).count();
    unsigned long seconds = millis / (1000);
    timings.push_back(micros / 1000.0);

    os << std::boolalpha << std::setprecision(width);
    os << ">> " <<  testCase <<"\t-> "
    << std::setfill('0') << std::setw(width) << seconds << "s\t"
    << std::setfill('0') << std::setw(width) << millis << "ms\t"
    << std::setfill('0') << std::setw(width)<< micros << "us\t"
    << std::setfill('0') << std::setw(width)<< nanos << "ns\n";
}

std::string getBytesSizeFromRounds(size_t rounds) {
    size_t bytes = rounds * sizeof(double);
    if(bytes / GB_IN_BYTES != 0) {
        return std::to_string(bytes / GB_IN_BYTES) + "GB";
    } else if(bytes / MB_IN_BYTES != 0) {
        return std::to_string(bytes / MB_IN_BYTES) + "MB";
    } else {
        return std::to_string(bytes / KB_IN_BYTES) + "KB";
    }
}

void printTimings(std::ostream& os, size_t rounds, std::vector<double>& timings) {
    os << "TeX: "<< getBytesSizeFromRounds(rounds) << " & " << rounds << " & ";
    for(size_t i = 0; i < timings.size(); i++) {
        os << timings[i];
        if(i < (timings.size() - 1)) {
            os << " & ";
        } else {
            os << " \\\\ \\hline\n";
        }
    }
}
