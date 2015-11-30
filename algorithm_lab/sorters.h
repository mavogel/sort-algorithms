#ifndef SORTERS_H
#define SORTERS_H

#include <array>
#include <vector>
#include <cmath>
#include "minsearch.h"
#include "notSortedException.h"

#define MAX_QS_DEPTH 25
#define FACTOR_WORST_QS 10

/**
 *  Sorts the given array via optimal 'direct selection'.
 */
template <typename T, size_t SIZE>
void sortViaOptimalDirectSelection(std::array<T, SIZE>& array) {
    size_t minIndex = 0;
    for(size_t i = 0; i < (SIZE - 1); i++) {
        minIndex = optimalMinSearch(array, i);
        std::swap(array[i], array[minIndex]);
    }
}

/**
 *  Sorts the given array via non-optimal 'direct selection'.
 */
template <typename T, size_t SIZE>
void sortViaNonOptimalDirectSelection(std::array<T, SIZE>& array) {
    size_t minIndex = 0;
    for(size_t i = 0; i < (SIZE - 1); i++) {
        minIndex = nonOptimalMinSearch(array, i);
        std::swap(array[i], array[minIndex]);
    }
}

/**
 *  Sorts the given array via 'direct insert' with a watcher element.
 *  Starting from startIndex (inclusive) until endIndex (exclusive)
 */
template <typename T, size_t SIZE>
void sortViaDirectInsertWithWatcherElement(std::array<T, SIZE>& array, const size_t startIndex, const size_t endIndex) {
    size_t minIndex = optimalMinSearch(array, startIndex, endIndex);
    std::swap(array[startIndex], array[minIndex]);

    for(unsigned long i = startIndex+2; i < endIndex; i++) {
        T curr = array[i];
        for (size_t j = i; array[j - 1] > curr; j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

/**
 *  Sorts the given array via 'direct insert' with a watcher element.
 */
template <typename T, size_t SIZE>
void sortViaDirectInsertWithWatcherElement(std::array<T, SIZE>& array) {
    size_t minIndex = optimalMinSearch(array, 0, SIZE);
    std::swap(array[0], array[minIndex]);

    for(unsigned long i = 2; i < SIZE; i++) {
        T curr = array[i];
        for (size_t j = i; array[j - 1] > curr; j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

/**
 *  Sorts the given array via normal 'direct insert' without a watcher.
 */
template <typename T, size_t SIZE>
void sortViaNormalDirectInsert(std::array<T, SIZE>& array) {
    for(unsigned long i = 0; i < SIZE; i++) {
        T curr = array[i];
        for (size_t j = i; j > 0 && array[j - 1] > curr; j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

/**
 * Retrieves the indexes of the presorted data in the given array.
 *
 * Examples:
 * 1) 7 4 6 3 1 2 8 5 => |7| |4 6| |3| |1 2 8| |5|  => Indexes: 0,1,3,4,7,8
 * 2) 1 2 3 4         => |1 2 3 4 5|                => Indexes: 0,4
 * 3) -1              => |-1|                       => Indexes: 0,0
 */
template<typename T, size_t SIZE>
std::vector<size_t> findIndexesOfPresortedData(std::array<T, SIZE>& array) {
    if(SIZE == 0) throw DataEmptyException();

    std::vector<size_t> indexes;
    indexes.push_back(0);
    for(size_t i = 1; i < SIZE; i++) {
        if(array[i - 1] > array[i]) {
            indexes.push_back(i);
        }
    }
    indexes.push_back(SIZE);

    return indexes;
}

/**
 * Determines if the data between both indexes (inclusive) is sorted
 *
 * @brief isDataSorted
 * @param lo the lower index
 * @param hi the higher index
 * @return true if the data is sorted, false otherwise
 */
template <typename T, size_t SIZE>
bool isDataSorted(std::array<T, SIZE>& array, size_t lo, size_t hi) {
    for(size_t i = lo; i < hi; i++) {
        if(array[i] > array[i+1]) return false;
    }
    return true;
}

/**
 * Merges / sorts the given array ascending from low index (lo) to the high index (hi)
 * => both indexes INCLUSIVE
 */
template <typename T, size_t SIZE>
void myMerge(std::array<T, SIZE>& array, std::array<T, SIZE>& tmp, size_t lo, size_t m, size_t hi) {
    if(lo < 0 || hi > (SIZE - 1)) throw IndexOutOfRangeException(lo, hi, 0, SIZE - 1);
    if(SIZE <= 1) return;
    if(!isDataSorted(array, lo, m-1)) throw NotSortedException(lo, m-1);
    if(!isDataSorted(array, m, hi)) throw NotSortedException(m, hi);

    size_t i = lo, j = m, k = hi;

    // == step 1: insert into tmp array: lo->mid: ASC; mid+1->hi: DESC => bitonic
    while(i < j) { tmp[i] = array[i]; i++; }
    while(j <= k) tmp[i++] = array[k--];

    // == step 2: sort and write back until pointers cross
    i = lo, j = lo, k = hi;
    while(j <= k) {
        if(tmp[j] < tmp[k]) {
            array[i++] = tmp[j++];
        } else {
            array[i++] = tmp[k];
            if(k > j) k--;
            else break;
        }
    }
}

/**
 * Sorts the given array via 'natural merge sort'
 */
template <typename T, size_t SIZE>
void sortViaNaturalMergesort(std::array<T, SIZE>& array) {
    if(SIZE == 0) throw DataEmptyException();

    std::vector<size_t> boundaries = findIndexesOfPresortedData(array);

    std::shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
    while(boundaries.size() >=3) {
        for(size_t i = 0; i < boundaries.size() - 2; i+=2) {
            size_t lo, mid, hi;
            lo = boundaries.at(i);
            mid = boundaries.at(i+1);
            hi = boundaries.at(i+2);

            myMerge(array, *tmp, lo, mid, hi-1);
        }
        boundaries = findIndexesOfPresortedData(array);
    }
}

/**
 * Sorts the given array via 'bottom-up merge sort'
 */
template <typename T, size_t SIZE>
void sortViaBottomUpMergesort(std::array<T, SIZE>& array) {
    if(SIZE == 0) throw DataEmptyException();

    size_t rounds;
    double integral, log = std::log2(SIZE);
    if(std::modf(log, &integral) != 0) {
        rounds = (size_t) integral;
        rounds++;
    } else {
        rounds = (size_t) integral;
    }

    std::shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
    for(size_t i = 1; i <= rounds; i++) {
        for(size_t j = 0; j < SIZE; j+=std::pow(2,i)) {
            size_t lo, mid, hi;
            lo = j;
            hi = (j+(std::pow(2,i))-1) > (SIZE-1) ? (SIZE-1): j+(std::pow(2,i))-1;
            mid = (lo+(std::pow(2,i-1))) > (SIZE-1) ? (SIZE-1) : lo+(std::pow(2,i-1));

            myMerge(array, *tmp, lo, mid, hi);
        }
    }
}

/**
 * Internal implementation of '3-way-partitioning quicksort' with additional depth parameter for debug
 */
template <typename T, size_t SIZE>
void internal3WayPartitioningQuicksort(std::array<T, SIZE>& array, const size_t left, const size_t right, const unsigned int depth) {
    size_t i = left-1, j = right;
    size_t p = left, q = right-1;

    // == step 1: use middle element as pivot
    std::swap(array[(left+right) / 2], array[right]);
    T v = array[right];

    if(right <= left) return;
    for(;;) {
        while(array[++i] < v);
        while(v < array[--j]) { if(j==left) break; }
        if(i >= j) break;
        // == step 2: swap
        std::swap(array[i], array[j]);

        // == step 3: move if equal to left or right end
        if(array[i] == v) { std::swap(array[p], array[i]); p++;}
        if(v == array[j]) { std::swap(array[j], array[q]); q--;}
    }

    // == step 4: bring the pivot from right end to the middle
    std::swap(array[i], array[right]);
    i == 0 ? j = 0 : j = i-1;
    i=i+1;

    // == step 5: swap equals to pivot to center
    size_t k = left;
    while(k < p) { std::swap(array[k], array[j]); k++; if(j>0) j--; }
    k = right-1;
    while(k > q){ std::swap(array[i], array[k]); i++; if(k>0) k--; }

    // == step 6: next recursion
    internal3WayPartitioningQuicksort(array, left, j, depth+1);
    internal3WayPartitioningQuicksort(array, i, right, depth+1);
}


/**
 * Sorts the given array via '3-way-partitioning quicksort'
 *
 * @see 'Quicksort is optimal' - R. Sedgewick, J. Bentley
 */
template <typename T, size_t SIZE>
void sortVia3WayPartitioningQuicksort(std::array<T, SIZE>& array) {
    internal3WayPartitioningQuicksort(array, 0, SIZE-1, 0);
}

/**
 * Determines the worst case for the Quicksort, if one half is 10 times bigger than the other
 *
 * @brief isWorstQuickSortCase
 * @return true if the worst case is present, false otherwise
 */
bool isWorstQuickSortCase(const size_t left, const size_t r, const size_t l,const size_t right);

/**
 * Performs an regular quicksort until a recursion depth of 25. Then the halfs will be sorted via direct insert. Furthermore it handles
 * the worst case for Quicksort, which is if one half contains more than 10 times the amount of values than the other half of the pivot element.
 */
template <typename T, size_t SIZE>
void internalHybridQuicksort(std::array<T, SIZE>& array, const size_t left, const size_t right, const unsigned int depth) {
    if(depth >= MAX_QS_DEPTH) {
        sortViaDirectInsertWithWatcherElement(array, left, right+1); //because qs inclusive and insertSort exclusive
    } else {
        size_t i = left-1, j = right;
        size_t p = left, q = right-1;

        // == step 1: use middle element as pivot
        std::swap(array[(left+right) / 2], array[right]);
        T v = array[right];

        if(right <= left) return;
        for(;;) {
            while(array[++i] < v);
            while(v < array[--j]) { if(j==left) break; }
            if(i >= j) break;
            // == step 2: swap
            std::swap(array[i], array[j]);

            // == step 3: move if equal to left or right end
            if(array[i] == v) { std::swap(array[p], array[i]); p++;}
            if(v == array[j]) { std::swap(array[j], array[q]); q--;}
        }

        // == step 4: bring pivot to the end
        std::swap(array[i], array[right]);
        i == 0 ? j = 0 : j = i-1;
        i=i+1;

        // == step 5: swap equals to pivot to center
        size_t k = left;
        while(k < p) { std::swap(array[k], array[j]); k++; if(j>0) j--; }
        k = right-1;
        while(k > q){ std::swap(array[i], array[k]); i++; if(k>0) k--; }


        if(isWorstQuickSortCase(left,j,i,right)) {
            // == step 6a: split recursion and merge
            std::shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
            size_t mid = (left + right) / 2;
            internalHybridQuicksort(array, left, mid, depth+1);
            internalHybridQuicksort(array, mid+1, right, depth+1);
            myMerge(array, *tmp, left, mid+1, right);
        } else {
            // == step 6b: next recursion
            internalHybridQuicksort(array, left, j, depth+1);
            internalHybridQuicksort(array, i, right, depth+1);
        }
    }
}

/**
 * Sorts the given array via 'hybrid quicksort'.
 *
 * The algorithms of insert sort and merge sort will be used and
 * the recursion terminated earlier.
 */
template <typename T, size_t SIZE>
void sortViaHybridQuicksort(std::array<T, SIZE>& array) {
     internalHybridQuicksort(array, 0, SIZE-1, 0);
}


#endif // SORTERS_H

