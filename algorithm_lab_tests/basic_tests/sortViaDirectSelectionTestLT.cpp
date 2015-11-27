#include <array>
#include <string>
#include <random>
#include "gtest/gtest.h"
#include "testhelper.h"
#include "sorters.h"

class SelectionSortWithBiggerSizesTest : public testing::Test {
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

TEST_F(SelectionSortWithBiggerSizesTest, sortViaOptimalDirectSelection2kIntegerTest) {
    // == conditions ==
    const int size = 2000;
    const bool optimal = true;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaDirectSelection<optimal>(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(SelectionSortWithBiggerSizesTest, sortViaNonOptimalDirectSelection2kIntegerTest) {
    // == conditions ==
    const int size = 2000;
    const bool optimal = false;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaDirectSelection<optimal>(*list);

    // == verify ==
    verifySorted(*list);
}

//TEST_F(SelectionSortWithBiggerSizesTest, sortViaOptimalDirectSelection10kIntegerTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool optimal = true;

//    // == prepare ==
//    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
//    initRandomIntegers(*list);

//    // == go ==
//    sortViaDirectSelection<optimal>(*list);

//    // == verify ==
//    verifySorted(*list);
//}

//TEST_F(SelectionSortWithBiggerSizesTest, sortViaNonOptimalDirectSelection10kIntegerTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool optimal = false;

//    // == prepare ==
//    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
//    initRandomIntegers(*list);

//    // == go ==
//    sortViaDirectSelection<optimal>(*list);

//    // == verify ==
//    verifySorted(*list);
//}

TEST_F(SelectionSortWithBiggerSizesTest, sortViaOptimalDirectSelection2kDoubleTest) {
    // == conditions ==
    const int size = 2000;
    const bool optimal = true;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
    initRandomDoubles(*dList);

    // == go ==
    sortViaDirectSelection<optimal>(*dList);

    // == verify ==
    verifySorted(*dList);
}

TEST_F(SelectionSortWithBiggerSizesTest, sortViaNonOptimalDirectSelection2kDoubleTest) {
    // == conditions ==
    const int size = 2000;
    const bool optimal = false;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
    initRandomDoubles(*dList);

    // == go ==
    sortViaDirectSelection<optimal>(*dList);

    // == verify ==
    verifySorted(*dList);
}

//TEST_F(SelectionSortWithBiggerSizesTest, sortViaOptimalDirectSelection10kDoubleTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool optimal = true;

//    // == prepare ==
//    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
//    initRandomDoubles(*dList);

//    // == go ==
//    sortViaDirectSelection<optimal>(*dList);

//    // == verify ==
//    verifySorted(*dList);
//}

//TEST_F(SelectionSortWithBiggerSizesTest, sortViaNonOptimalDirectSelection10kDoubleTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool optimal = false;

//    // == prepare ==
//    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
//    initRandomDoubles(*dList);

//    // == go ==
//    sortViaDirectSelection<optimal>(*dList);

//    // == verify ==
//    verifySorted(*dList);
//}

TEST_F(SelectionSortWithBiggerSizesTest, sortViaOptimalDirectSelection2kStringTest) {
    // == conditions ==
    const int size = 500;
    const bool optimal = true;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> sList(new std::array<std::string, size>);
    initRandomStrings(*sList);

    // == go ==
    sortViaDirectSelection<optimal>(*sList);

    // == verify ==
    verifySorted(*sList);
}

TEST_F(SelectionSortWithBiggerSizesTest, sortViaNonOptimalDirectSelection2kStringTest) {
    // == conditions ==
    const int size = 500;
    const bool optimal = false;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> sList(new std::array<std::string, size>);
    initRandomStrings(*sList);

    // == go ==
    sortViaDirectSelection<optimal>(*sList);

    // == verify ==
    verifySorted(*sList);
}
