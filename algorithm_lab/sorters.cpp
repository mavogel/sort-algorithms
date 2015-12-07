#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    size_t leftSide= (j > left) ? j - left : left;
    size_t rightSide = (right > i) > 0 ? right - i : right;
    return (leftSide < (FACTOR_WORST_QS * rightSide)) || ((leftSide * FACTOR_WORST_QS) < rightSide);
}
