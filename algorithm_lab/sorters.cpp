#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    size_t leftSide= (j > left) ? j - left : 0;
    size_t rightSide = (right > i) > 0 ? right - i : 0;
    return (leftSide <= 0 || rightSide <= 0) ? false : (leftSide / rightSide >= FACTOR_WORST_QS) || (rightSide / leftSide >= FACTOR_WORST_QS);
}
