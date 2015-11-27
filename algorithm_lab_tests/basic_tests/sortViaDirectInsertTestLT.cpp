#include <array>
#include <string>
#include <random>
#include "gtest/gtest.h"
#include "testhelper.h"
#include "sorters.h"

class InsertSortWithBiggerSizesTest : public testing::Test {
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

// l2: 8k
// l3: 94k
TEST_F(InsertSortWithBiggerSizesTest, sortViaDirectInsertWithWatcher2kIntegerTest) {
    // == conditions ==
    const int size = 2000;
    const bool withWatcher = true;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaDirectInsert<withWatcher>(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(InsertSortWithBiggerSizesTest, sortViaNonDirectInsertWithoutWatcher2kIntegerTest) {
    // == conditions ==
    const int size = 2000;
    const bool withWatcher = false;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaDirectInsert<withWatcher>(*list);

    // == verify ==
    verifySorted(*list);
}

//TEST_F(InsertSortWithBiggerSizesTest, sortViaDirectInsertWithWatcher10kIntegerTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool withWatcher = true;

//    // == prepare ==
//    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
//    initRandomIntegers(*list);

//    // == go ==
//    sortViaDirectInsert<withWatcher>(*list);

//    // == verify ==
//    verifySorted(*list);
//}

//TEST_F(InsertSortWithBiggerSizesTest, sortViaNonDirectInsertWithoutWatcher10kIntegerTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool withWatcher = false;

//    // == prepare ==
//    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
//    initRandomIntegers(*list);

//    // == go ==
//    sortViaDirectInsert<withWatcher>(*list);

//    // == verify ==
//    verifySorted(*list);
//}



TEST_F(InsertSortWithBiggerSizesTest, sortViaDirectInsertWithWatcher2kDoubleTest) {
    // == conditions ==
    const int size = 2000;
    const bool withWatcher = true;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
    initRandomDoubles(*dList);

    // == go ==
    sortViaDirectInsert<withWatcher>(*dList);

    // == verify ==
    verifySorted(*dList);
}

TEST_F(InsertSortWithBiggerSizesTest, sortViaNonDirectInsertWithoutWatcher2kDoubleTest) {
    // == conditions ==
    const int size = 2000;
    const bool withWatcher = false;

    // == prepare ==
    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
    initRandomDoubles(*dList);

    // == go ==
    sortViaDirectInsert<withWatcher>(*dList);

    // == verify ==
    verifySorted(*dList);
}

//TEST_F(InsertSortWithBiggerSizesTest, sortViaDirectInsertWithWatcher10kDoubleTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool withWatcher = true;

//    // == prepare ==
//    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
//    initRandomDoubles(*dList);

//    // == go ==
//    sortViaDirectInsert<withWatcher>(*dList);

//    // == verify ==
//    verifySorted(*dList);
//}

//TEST_F(InsertSortWithBiggerSizesTest, sortViaNonDirectInsertWithoutWatcher10kDoubleTest) {
//    // == conditions ==
//    const int size = 10000;
//    const bool withWatcher = false;

//    // == prepare ==
//    std::shared_ptr<std::array<double, size>> dList(new std::array<double, size>);
//    initRandomDoubles(*dList);

//    // == go ==
//    sortViaDirectInsert<withWatcher>(*dList);

//    // == verify ==
//    verifySorted(*dList);
//}

TEST_F(InsertSortWithBiggerSizesTest, sortViaDirectInsert2kStringTest) {
    // == conditions ==
    const int size = 500;
    const bool withWatcher = true;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> sList(new std::array<std::string, size>);
    initRandomStrings(*sList);

    // == go ==
    sortViaDirectInsert<withWatcher>(*sList);

    // == verify ==
    verifySorted(*sList);
}

TEST_F(InsertSortWithBiggerSizesTest, sortViaNonDirectInsert2kStringTest) {
    // == conditions ==
    const int size = 500;
    const bool withWatcher = false;

    // == prepare ==
    std::shared_ptr<std::array<std::string, size>> sList(new std::array<std::string, size>);
    initRandomStrings(*sList);

    // == go ==
    sortViaDirectInsert<withWatcher>(*sList);

    // == verify ==
    verifySorted(*sList);
}
