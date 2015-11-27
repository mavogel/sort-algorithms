#include <array>
#include <string>
#include <random>
#include "gtest/gtest.h"
#include "testhelper.h"
#include "sorters.h"

class HybridQuickSortWithBiggerSizesTest : public testing::Test {
protected:
    virtual void SetUp() {
        // Code here will be called immediately before each test
        // (right before the constructor -- maybe).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort2kIntegerTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort2kDoubleTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort2kStringTest) {
    // == conditions ==
    const int size = 50;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort10kIntegerTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort10kDoubleTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortWithBiggerSizesTest, sortViaHybridQuickSort10kStringTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

