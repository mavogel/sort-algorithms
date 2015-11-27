#include <array>
#include <string>
#include <random>
#include "gtest/gtest.h"
#include "testhelper.h"
#include "sorters.h"

class NaturalMergeSortWithBiggerSizesTest : public testing::Test {
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

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort2kIntegerTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort2kDoubleTest) {
    // == conditions ==
    const int size = 2000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort2kStringTest) {
    // == conditions ==
    const int size = 50;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort10kIntegerTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort10kDoubleTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> list(new std::array<double, size>);
    initRandomDoubles(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(NaturalMergeSortWithBiggerSizesTest, sortViaNaturalMergeSort10kStringTest) {
    // == conditions ==
    const int size = 10000;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> list(new std::array<std::string, size>);
    initRandomStrings(*list);

    // == go ==
    sortViaNaturalMergesort(*list);

    // == verify ==
    verifySorted(*list);
}

