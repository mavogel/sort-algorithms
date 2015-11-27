#include <array>
#include "generator.h"

double generateRandomDouble(const int lowerBound, const int upperBound) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<double> uni(lowerBound, upperBound);

    return uni(rng);
}

void preTestFillArrayWith20mb() {
    std::shared_ptr<std::array<double,2500000>> dList(new std::array<double,2500000>);
    for(unsigned long i = 0; i< dList->size(); i++) {
        (*dList)[i] = i*i;
    }
}
