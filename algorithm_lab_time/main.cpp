#include <memory>
#include "testbuilder.h"

#if defined(_STD_TR1_SHARED_PTR)
using std::tr1::shared_ptr;
#else
using std::shared_ptr;
#endif

int main() {
    // == init ==
    shared_ptr<std::array<double, ROUNDS_K1>>   KB1_list(new std::array<double, ROUNDS_K1>);
    shared_ptr<std::array<double, ROUNDS_K2>>   KB2_list(new std::array<double, ROUNDS_K2>);
    shared_ptr<std::array<double, ROUNDS_K4>>   KB4_list(new std::array<double, ROUNDS_K4>);
    shared_ptr<std::array<double, ROUNDS_K8>>   KB8_list(new std::array<double, ROUNDS_K8>);
    shared_ptr<std::array<double, ROUNDS_K16>>  KB16_list(new std::array<double, ROUNDS_K16>);
    shared_ptr<std::array<double, ROUNDS_K32>>  KB32_list(new std::array<double, ROUNDS_K32>);
    shared_ptr<std::array<double, ROUNDS_K64>>  KB64_list(new std::array<double, ROUNDS_K64>);
    shared_ptr<std::array<double, ROUNDS_K128>> KB128_list(new std::array<double, ROUNDS_K128>);
    shared_ptr<std::array<double, ROUNDS_K256>> KB256_list(new std::array<double, ROUNDS_K256>);
    shared_ptr<std::array<double, ROUNDS_K512>> KB512_list(new std::array<double, ROUNDS_K512>);
    shared_ptr<std::array<double, ROUNDS_M1>>   M1_list(new std::array<double, ROUNDS_M1>);
    shared_ptr<std::array<double, ROUNDS_M2>>   M2_list(new std::array<double, ROUNDS_M2>);
    shared_ptr<std::array<double, ROUNDS_M4>>   M4_list(new std::array<double, ROUNDS_M4>);
    shared_ptr<std::array<double, ROUNDS_M8>>   M8_list(new std::array<double, ROUNDS_M8>);
    // for MS and QS only
    shared_ptr<std::array<double, ROUNDS_M16>>   M16_list(new std::array<double, ROUNDS_M16>);
    shared_ptr<std::array<double, ROUNDS_M32>>   M32_list(new std::array<double, ROUNDS_M32>);
    shared_ptr<std::array<double, ROUNDS_M64>>   M64_list(new std::array<double, ROUNDS_M64>);
    shared_ptr<std::array<double, ROUNDS_M128>>   M128_list(new std::array<double, ROUNDS_M128>);
    shared_ptr<std::array<double, ROUNDS_M256>>   M256_list(new std::array<double, ROUNDS_M256>);
    shared_ptr<std::array<double, ROUNDS_M512>>   M512_list(new std::array<double, ROUNDS_M512>);
    shared_ptr<std::array<double, ROUNDS_G1>>   G1_list(new std::array<double, ROUNDS_G1>);
    shared_ptr<std::array<double, ROUNDS_G2>>   G2_list(new std::array<double, ROUNDS_G2>);
    shared_ptr<std::array<double, ROUNDS_G4>>   G4_list(new std::array<double, ROUNDS_G4>);

    // == go ==
    runSortingAlgorithms(*KB1_list);
    runSortingAlgorithms(*KB2_list);
    runSortingAlgorithms(*KB4_list);
    runSortingAlgorithms(*KB8_list);
    runSortingAlgorithms(*KB16_list);
    runSortingAlgorithms(*KB32_list);
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
