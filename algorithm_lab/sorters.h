#ifndef SORTERS_H
#define SORTERS_H

#include <array>
#include <vector>
#include <queue>
#include <cmath>
#include <memory>
#include "minsearch.h"

#define QS_TO_INSERT_THRESHOLD 25
#define FACTOR_WORST_QS 10

#if defined(_STD_TR1_SHARED_PTR)
using std::tr1::shared_ptr;
#else
using std::shared_ptr;
#endif

/**
 * Sorts the given array via optimal 'direct selection' usind cache prefechting.
 *
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaOptimalDirectSelection(std::array<T, SIZE>& array) {
    if(SIZE == 0 || SIZE == 1) return;
    for(size_t i = 0; i < (SIZE - 1); i++) {
        std::swap(array[i], array[optimalMinSearch(array, i, SIZE)]);
    }
}

/**
 *  Sorts the given array via non-optimal 'direct selection' starting from the last index.
 *
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaNonOptimalDirectSelection(std::array<T, SIZE>& array) {
    if(SIZE == 0 || SIZE == 1) return;
    for(size_t i = 0; i < (SIZE - 1); i++) {
        std::swap(array[i], array[nonOptimalMinSearch(array, i, SIZE)]);
    }
}

/**
 *  Sorts the given array via 'direct insert' with a watcher element
 *  starting from startIndex (INCLUSIVE) until endIndex (EXCLUSIVE).
 *
 * @brief Sorts via direct insert
 * @param array the array to sort
 * @param startIndex the index to start from (INCLUSIVE)
 * @param endIndex the endIndex (EXCLUSIVE)
 */
template <typename T, size_t SIZE>
void sortViaDirectInsertWithWatcherElement(std::array<T, SIZE>& array, const size_t startIndex, const size_t endIndex) {
    if(SIZE == 0 || SIZE == 1) return;

    std::swap(array[startIndex], array[optimalMinSearch(array, startIndex, endIndex)]);
    for(size_t i = startIndex+2; i < endIndex; i++) {
        for (size_t j = i; array[j - 1] > array[j]; j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

/**
 *  Sorts the given array via 'direct insert' with a watcher element, by swapping the minimum (using optimal minumum
 *  search) to the beginning first.
 *
 * @brief Sorts via direct insert with a watcher/guard element
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaDirectInsertWithWatcherElement(std::array<T, SIZE>& array) {
    sortViaDirectInsertWithWatcherElement(array, 0, SIZE);
}

/**
 *  Sorts the given array via normal 'direct insert' without a watcher.
 *
 * @brief Sorts via direct insert
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaNormalDirectInsert(std::array<T, SIZE>& array) {
    for(size_t i = 0; i < SIZE; i++) {
        for (size_t j = i; j > 0 && (array[j - 1] > array[j]); j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

/**
 * Finds the indexes of the bitonic runs.
 *
 * Examples:
 * 1) 1,2,3,2,1,2,3     => 0,3,5,7
 * 2) 7,6,5,4,3         => 0,2,5
 * 3) 1,2,3,2,1,2,3,1   => 0,3,5,7,8
 * 4) 1,2,3,4,5,6       => 0,6
 *
 * @param array the array to find the bitonic runs in
 * @return the indexes of the bitonic runs
 */
template<typename T, size_t SIZE>
std::queue<size_t> findIndexesOfBitonicRuns(std::array<T, SIZE>& array) {
    bool wasDescBefore = false;
    std::queue<size_t> indexes;

    indexes.push(0);
    for(size_t i = 1; i < SIZE; i++) {
        if(array[i - 1] < array[i]) {
            if(wasDescBefore) {
                indexes.push(i);
                wasDescBefore = false;
            }
        } else if(array[i - 1] == array[i]) {
            // just do nothing...
        } else {
            if(!wasDescBefore) {
                wasDescBefore = true;
                indexes.push(i);
            }

        }
    }
    if(!wasDescBefore && indexes.size() > 1) indexes.push(SIZE);
    indexes.push(SIZE);

    return indexes;
}

/**
 * Merges the given array ascending from low index (lo (INCLUSIVE)) via middle index (m (EXCLUSIVE))
 * to the high index (hi (EXCLUSIVE))
 *
 * @brief Generic merge function to merge from lo to hi index
 * @param array the array to merge into between the lo and hi index
 * @param tmp the temporal array used to perform the merge from
 * @param lo the lower index
 * @param m the middle index
 * @param hi the high index
 * @param isSecondDesc true if the data from m to hi is presorted descending, false otherwise (ascending)
 * @param writeDesc true if the merged data should be written back descending to the array, false otherwise (ascending)
 */
template <typename T, size_t SIZE>
void merge(std::array<T, SIZE>& array, std::array<T, SIZE>& tmp, const size_t lo, const size_t m, const size_t hi,
             const bool isSecondDesc, const bool writeDesc) {
    if (isSecondDesc) { // already bitonic, so insert into tmp array
        for (size_t i = lo; i < hi; i++) { tmp[i] = array[i]; }
    } else { // lo->mid: ASC; mid+1->hi: DESC => bitonic
        for (size_t i = lo; i < m; i++) { tmp[i] = array[i]; }
        for (size_t i = m, k = hi; m < k; i++) { tmp[i] = array[--k]; }
    }

    size_t readIdxLo = lo, readIdxHi = hi, writeIdx;
    writeDesc ? writeIdx = hi-1 : writeIdx = lo;
    while(readIdxLo < readIdxHi) {
        if (tmp[readIdxLo] < tmp[--readIdxHi]) {
            array[writeIdx] = tmp[readIdxLo++]; readIdxHi++;
        } else {
            array[writeIdx] = tmp[readIdxHi];
        }
        writeDesc ? writeIdx-- : writeIdx++;
    }
}

/**
 * Returns and removes/pops the head values of the queue.
 *
 * @param queue the queue to return and pop the head value
 * @return the head value
 */
template <typename T>
T popFront(std::queue<T>& queue) {
    T retVal = queue.front();
    queue.pop();
    return retVal;
}

/**
 * Appends the new indexes to the queue and returns the new toggle for writing descending or not.
 *
 * @param indexes the indexes to append the new indexes to
 * @param writeDescendingToggle
 * @param lo the current lo index
 * @param hi the current hi index
 * @param maxIndex the value of the maximal index (EXCLUSIVE)
 * @return the new toggle for writing descending
 */
bool appendNewIndexesAndSetToggle(std::queue<size_t>& indexes, const bool writeDescendingToggle, const size_t lo, const size_t hi, const size_t maxIndex);

/**
 * Sorts the given array via 'natural merge sort'.
 *
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaNaturalMergesort(std::array<T, SIZE>& array) {
    std::queue<size_t> indexes = findIndexesOfBitonicRuns(array);

    size_t lo, mid, hi;
    bool writeDescendingToggle = false;
    shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
    while(indexes.size() > 2) {
        lo = popFront(indexes); mid = popFront(indexes);
        indexes.front() == SIZE ? hi = popFront(indexes) : hi = indexes.front();

        merge(array, *tmp, lo, mid, hi, true, writeDescendingToggle);
        writeDescendingToggle = appendNewIndexesAndSetToggle(indexes, writeDescendingToggle, lo, hi, SIZE);
    }
}

/**
 * Sorts the given array via 'bottom-up merge sort'.
 *
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaBottomUpMergesort(std::array<T, SIZE>& array) {
    size_t rounds = 0;
    if(SIZE > 0) {
        double integral, log = std::log2(SIZE);
        if (std::modf(log, &integral) > 0) {
            rounds = (size_t) integral; rounds++;
        } else {
            rounds = (size_t) integral;
        }
    }

    shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
    size_t mid, hi;
    for(size_t round = 1; round <= rounds; round++) {
        for(size_t lo = 0; lo < SIZE; lo+=std::pow(2,round)) {
            mid = (lo+(std::pow(2,round-1))) > (SIZE) ? (SIZE) : lo+(std::pow(2,round-1));
            hi = (lo+(std::pow(2,round))) > (SIZE) ? (SIZE): lo+(std::pow(2,round));
            merge(array, *tmp, lo, mid, hi, false, false);
        }
    }
}

/**
 * Internal implementation of '3-way-partitioning quicksort' with additional depth parameter.
 *
 * @param array the array to sort
 * @param left the left index/boundary of the part to apply the algorithm (INCLUSIVE)
 * @param right corresponding right index/boundary (EXCLUSIVE)
 */
template <typename T, size_t SIZE>
void internal3WayPartitioningQuicksort(std::array<T, SIZE>& array, const size_t left, const size_t right) {
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
    internal3WayPartitioningQuicksort(array, left, j);
    internal3WayPartitioningQuicksort(array, i, right);
}


/**
 * Sorts the given array via '3-way-partitioning quicksort'.
 *
 * @see 'Quicksort is optimal' - R. Sedgewick, J. Bentley
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortVia3WayPartitioningQuicksort(std::array<T, SIZE>& array) {
    internal3WayPartitioningQuicksort(array, 0, SIZE-1);
}

/**
 * Determines the worst case for the Quicksort, if one half is 10 times bigger than the other.
 *
 * |   <p  | =p      |      >p           |
 * left    r         l                   right
 *
 * @param left the left boundary of the left part to sort
 * @param r the right boundary of the left part to sort
 * @param l the left boundary of the right part to sort
 * @param right the right boundary of the right part to sort
 * @return true if the worst case is found, false otherwise
 */
bool isWorstQuickSortCase(const size_t left, const size_t r, const size_t l,const size_t right);

/**
 * Performs an regular quicksort until a size of 25. Then the halfs will be sorted via direct insert. Furthermore it handles
 * the worst case for Quicksort, which is if one half contains more than 10 times the amount of values than the other half of the pivot element.
 *
 * @param array the array to sort
 * @param left the left index/boundary of the part to apply the algorithm (INCLUSIVE)
 * @param right corresponding right index/boundary (EXCLUSIVE)
 */
template <typename T, size_t SIZE>
void internalHybridQuicksort(std::array<T, SIZE>& array, std::array<T, SIZE>& tmp, const size_t left, const size_t right) {
    if((right - left) <= QS_TO_INSERT_THRESHOLD) {
        sortViaDirectInsertWithWatcherElement(array, left, right+1);
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
            size_t mid = (left + right) / 2;
            internalHybridQuicksort(array, tmp, left, mid);
            internalHybridQuicksort(array, tmp, mid+1, right);
            merge(array, tmp, left, mid+1, right+1, false, false);
        } else {
            // == step 6b: next recursion
            internalHybridQuicksort(array, tmp, left, j);
            internalHybridQuicksort(array, tmp, i, right);
        }
    }
}

/**
 * Sorts the given array via a 'hybrid quicksort'.
 * The algorithms of insert sort and merge sort will be used.
 *
 * @brief Implementation of a hybrid quicksort, consisting of 3-way-partitioning quicksort, insert sort and mergesort
 * @param array the array to sort
 */
template <typename T, size_t SIZE>
void sortViaHybridQuicksort(std::array<T, SIZE>& array) {
    shared_ptr<std::array<T, SIZE>> tmp(new std::array<T, SIZE>());
    internalHybridQuicksort(array, *tmp, 0, SIZE-1);
}


#endif // SORTERS_H

