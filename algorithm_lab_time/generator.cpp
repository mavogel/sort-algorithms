#include <array>
#include <memory>
#include "generator.h"
#if defined(_STD_TR1_SHARED_PTR)
using std::tr1::shared_ptr;
#else
using std::shared_ptr;
#endif

double generateRandomDouble(const int lowerBound, const int upperBound) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<double> uni(lowerBound, upperBound);

    return uni(rng);
}

void preTestFillArrayWith20mb() {
    shared_ptr<std::array<double,2500000>> dList(new std::array<double,2500000>);
    for(unsigned long i = 0; i< dList->size(); i++) {
        (*dList)[i] = i*i;
    }
}
