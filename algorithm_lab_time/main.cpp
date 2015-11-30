#include "testbuilder.h"

int main() {
    // TODOs:
    // - start field size: (64*10^3)/8 = 8000 rounds. except direct insert DESC sorted (= worst case)
    // - for each algorithm (there are 4) (only double)
    // -- 1) ascending sorted
    // -- 2) descending sorted
    // -- 3) random sorted
    // => 12 scenarios
    // - fill array with 20mb ((20*10^6)/8 = 2.500.000 iterations of 8 byte double value)

    // == init ==
    std::shared_ptr<std::array<double, 125>> KB1_list(new std::array<double, 125>);
    std::shared_ptr<std::array<double, 250>> KB2_list(new std::array<double, 250>);
    std::shared_ptr<std::array<double, 500>> KB4_list(new std::array<double, 500>);
    std::shared_ptr<std::array<double, 1000>> KB8_list(new std::array<double, 1000>);
    std::shared_ptr<std::array<double, 2000>> KB16_list(new std::array<double, 2000>);
    std::shared_ptr<std::array<double, 4000>> KB32_list(new std::array<double, 4000>);
    std::shared_ptr<std::array<double, 8000>> KB64_list(new std::array<double, 8000>);
    std::shared_ptr<std::array<double, 16000>> KB128_list(new std::array<double, 16000>);
    std::shared_ptr<std::array<double, 32000>> KB256_list(new std::array<double, 32000>);
    std::shared_ptr<std::array<double, 64000>> KB512_list(new std::array<double, 64000>);
    std::shared_ptr<std::array<double, 128000>> M1_list(new std::array<double, 128000>);
    std::shared_ptr<std::array<double, 256000>> M2_list(new std::array<double, 256000>);
    std::shared_ptr<std::array<double, 512000>> M4_list(new std::array<double, 512000>);
    std::shared_ptr<std::array<double, 1024000>> M8_list(new std::array<double, 1024000>);
    // for MS and QS only
    std::shared_ptr<std::array<double, 2048000>> M16_list(new std::array<double, 2048000>);
    std::shared_ptr<std::array<double, 4096000>> M32_list(new std::array<double, 4096000>);
    std::shared_ptr<std::array<double, 8192000>> M64_list(new std::array<double, 8192000>);
    std::shared_ptr<std::array<double, 16386000>> M128_list(new std::array<double, 16386000>);
    std::shared_ptr<std::array<double, 32768000>> M256_list(new std::array<double, 32768000>);
    std::shared_ptr<std::array<double, 65536000>> M512_list(new std::array<double, 65536000>);
    std::shared_ptr<std::array<double, 131072000>> G1_list(new std::array<double, 131072000>);
//    std::shared_ptr<std::array<double, 262144000>> G2_list(new std::array<double, 262144000>);
//    std::shared_ptr<std::array<double, 524288000>> G4_list(new std::array<double, 524288000>);
//    std::shared_ptr<std::array<double, 1048576000>> G8_list(new std::array<double, 1048576000>);

    // == go ==

    runSortingAlgorithms(*KB1_list);
    runSortingAlgorithms(*KB2_list);
    runSortingAlgorithms(*KB4_list);
    runSortingAlgorithms(*KB8_list);
    runSortingAlgorithms(*KB16_list);
    runSortingAlgorithms(*KB32_list);
//    runSortingAlgorithms(*KB64_list);
//    runSortingAlgorithms(*KB128_list);
//    runSortingAlgorithms(*KB256_list);
//    runSortingAlgorithms(*KB512_list);
//    runSortingAlgorithms(*M1_list);
//    runSortingAlgorithms(*M2_list);
//    runSortingAlgorithms(*M4_list);
//    runSortingAlgorithms(*M8_list);
//    runSortingAlgorithms(*M16_list);
//    runSortingAlgorithms(*M32_list);
//    runSortingAlgorithms(*M64_list);
//    runSortingAlgorithms(*M128_list);
//    runSortingAlgorithms(*M256_list);
//    runSortingAlgorithms(*M512_list);
//    runSortingAlgorithms(*G1_list);
//    runSortingAlgorithms(*G2_list);
//    runSortingAlgorithms(*G4_list);
//    runSortingAlgorithms(*G8_list);

    return 0;
}
