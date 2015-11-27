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
    runCombination(*KB1_list);
    runCombination(*KB2_list);
    runCombination(*KB4_list);
    runCombination(*KB8_list);
    runCombination(*KB16_list);
//    runCombination(*KB32_list);
//    runCombination(*KB64_list);
//    runCombination(*KB128_list);
//    runCombination(*KB256_list);
//    runCombination(*KB512_list);
//    runCombination(*M1_list);
//    runCombination(*M2_list);
//    runCombination(*M4_list);
//    runCombination(*M8_list);
//    runCombination(*M16_list);
//    runCombination(*M32_list);
//    runCombination(*M64_list);
//    runCombination(*M128_list);
//    runCombination(*M256_list);
//    runCombination(*M512_list);
//    runCombination(*G1_list);
//    runCombination(*G2_list);
//    runCombination(*G4_list);
//    runCombination(*G8_list);

    return 0;
}
