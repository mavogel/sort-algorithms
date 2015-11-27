#include <array>
#include <string>
#include <random>
#include "gtest/gtest.h"
#include "testhelper.h"
#include "sorters.h"

class ThreeWayPartitioningQuickSortWithBiggerSizesTest : public testing::Test {
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

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort2kIntegerTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort2kDoubleTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort2kStringTest) {
    // == conditions ==
    const int size = 50;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort10kIntegerTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort10kDoubleTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(ThreeWayPartitioningQuickSortWithBiggerSizesTest, sortVia3WayPartitioningQuickSort10kStringTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortVia3WayPartitioningQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

