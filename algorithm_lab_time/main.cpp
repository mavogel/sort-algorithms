#include <memory>
#include "testbuilder.h"

#if defined(_STD_TR1_SHARED_PTR)
using std::tr1::shared_ptr;
#else
using std::shared_ptr;
#endif

int main() {
    // == init ==
//    shared_ptr<std::array<double, 125>> KB1_list(new std::array<double, 125>);
//    shared_ptr<std::array<double, 250>> KB2_list(new std::array<double, 250>);
//    shared_ptr<std::array<double, 500>> KB4_list(new std::array<double, 500>);
//    shared_ptr<std::array<double, 1000>> KB8_list(new std::array<double, 1000>);
//    shared_ptr<std::array<double, 2000>> KB16_list(new std::array<double, 2000>);
//    shared_ptr<std::array<double, 4000>> KB32_list(new std::array<double, 4000>);
    shared_ptr<std::array<double, 8000>> KB64_list(new std::array<double, 8000>);
    shared_ptr<std::array<double, 16000>> KB128_list(new std::array<double, 16000>);
    shared_ptr<std::array<double, 32000>> KB256_list(new std::array<double, 32000>);
    shared_ptr<std::array<double, 64000>> KB512_list(new std::array<double, 64000>);
    shared_ptr<std::array<double, 128000>> M1_list(new std::array<double, 128000>);
    shared_ptr<std::array<double, 256000>> M2_list(new std::array<double, 256000>);
    shared_ptr<std::array<double, 512000>> M4_list(new std::array<double, 512000>);
    shared_ptr<std::array<double, 1024000>> M8_list(new std::array<double, 1024000>);
    // for MS and QS only
    shared_ptr<std::array<double, 2048000>> M16_list(new std::array<double, 2048000>);
    shared_ptr<std::array<double, 4096000>> M32_list(new std::array<double, 4096000>);
    shared_ptr<std::array<double, 8192000>> M64_list(new std::array<double, 8192000>);
    shared_ptr<std::array<double, 16386000>> M128_list(new std::array<double, 16386000>);
    shared_ptr<std::array<double, 32768000>> M256_list(new std::array<double, 32768000>);
    shared_ptr<std::array<double, 65536000>> M512_list(new std::array<double, 65536000>);
    shared_ptr<std::array<double, 131072000>> G1_list(new std::array<double, 131072000>);
    shared_ptr<std::array<double, 262144000>> G2_list(new std::array<double, 262144000>);
    shared_ptr<std::array<double, 524288000>> G4_list(new std::array<double, 524288000>);

    // == go ==
//    runSortingAlgorithms(*KB1_list);
//    runSortingAlgorithms(*KB2_list);
//    runSortingAlgorithms(*KB4_list);
//    runSortingAlgorithms(*KB8_list);
//    runSortingAlgorithms(*KB16_list);
//    runSortingAlgorithms(*KB32_list);
    runSortingAlgorithms(*KB64_list);
    runSortingAlgorithms(*KB128_list);
    runSortingAlgorithms(*KB256_list);
    runSortingAlgorithms(*KB512_list);
    runSortingAlgorithms(*M1_list);
    runSortingAlgorithms(*M2_list);
    runSortingAlgorithms(*M4_list);
    runSortingAlgorithms(*M8_list);
    runSortingAlgorithms(*M16_list);
    runSortingAlgorithms(*M32_list);
    runSortingAlgorithms(*M64_list);
    runSortingAlgorithms(*M128_list);
    runSortingAlgorithms(*M256_list);
    runSortingAlgorithms(*M512_list);
    runSortingAlgorithms(*G1_list);
    runSortingAlgorithms(*G2_list);
    runSortingAlgorithms(*G4_list);

    return 0;
}
