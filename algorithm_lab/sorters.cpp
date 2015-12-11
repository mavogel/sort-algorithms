#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    return ((j - left) < (FACTOR_WORST_QS * (right - i))) || (((j - left) * FACTOR_WORST_QS < (right -i)));
}

bool appendNewIndexesAndSetToogle(std::queue<size_t>& indexes, size_t writeDescendingToggle, size_t lo, size_t hi, size_t SIZE) {
    if(!writeDescendingToggle) { // asc
        if(lo == 0)  indexes.push(lo); // 1st time
        if(hi == SIZE && lo != 0) indexes.push(hi);
        indexes.push(hi);              // all other times
    }
    else {                       // desc
        indexes.push(hi);
    }
    return hi == SIZE ? false : (writeDescendingToggle ? false : true);
}