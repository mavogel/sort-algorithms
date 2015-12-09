#include "sorters.h"

bool isWorstQuickSortCase(const size_t left, const size_t j, const size_t i,const size_t right) {
    return ((j - left) < (FACTOR_WORST_QS * (right - i))) || (((j - left) * FACTOR_WORST_QS < (right -i)));
}
