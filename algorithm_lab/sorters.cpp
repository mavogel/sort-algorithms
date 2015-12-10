#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    return ((j - left) < (FACTOR_WORST_QS * (right - i))) || (((j - left) * FACTOR_WORST_QS < (right -i)));
}

void handleNewIndexes(std::queue<size_t>& indexes, size_t bitRunCount, size_t lo, size_t hi, size_t SIZE) {
    if(bitRunCount % 2 != 0) {
        indexes.push(lo);
    }
    indexes.push(hi);
}
