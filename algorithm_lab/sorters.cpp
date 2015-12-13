#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    return ((j - left) < (FACTOR_WORST_QS * (right - i))) || (((j - left) * FACTOR_WORST_QS < (right -i)));
}

bool appendNewIndexesAndSetToggle(std::queue<size_t>& indexes, const bool writeDescendingToggle, const size_t lo, const size_t hi, const size_t maxIndex) {
    if(!writeDescendingToggle) {        // asc
        if(lo == 0)  indexes.push(lo);  // 1st time
        if(hi == maxIndex && lo != 0) indexes.push(hi);
        indexes.push(hi);               // all other times
    }
    else {                              // desc
        indexes.push(hi);
    }
    return hi == maxIndex ? false : (writeDescendingToggle ? false : true);
}