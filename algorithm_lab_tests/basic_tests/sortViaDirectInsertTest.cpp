#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class SortViaDirectInsertTest : public testing::Test {
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


TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithoutWatcher) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaNormalDirectInsert(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaNormalDirectInsert(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaNormalDirectInsert(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithoutWatcherDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaNormalDirectInsert(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaNormalDirectInsert(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaNormalDirectInsert(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithWatcherEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaNormalDirectInsert(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    sortViaNormalDirectInsert(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    sortViaNormalDirectInsert(*sList);
    verifySorted(*sList);
}


TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithWatcherElement) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaDirectInsertWithWatcherElement(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaDirectInsertWithWatcherElement(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaDirectInsertWithWatcherElement(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWitWatcherDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaDirectInsertWithWatcherElement(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaDirectInsertWithWatcherElement(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaDirectInsertWithWatcherElement(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithoutWatcherEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaNormalDirectInsert(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    sortViaNormalDirectInsert(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    sortViaNormalDirectInsert(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectInsertTest, sortPartiallyViaDirectInsertWithWatcher) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{-1,2,7,8, 10,9,13,8,11}});
    sortViaDirectInsertWithWatcherElement(*list, 4, 9);
    verifySorted(*list);

    //FIX ME
//    std::shared_ptr<std::array<int, 9>> list2(new std::array<int, 9>{{-1,2,5, 8,10,9,13,6, 55}});
//    sortViaDirectInsertWithWatcherElement(*list2, 3, 8);
//    verifySorted(*list2);
//    print(*list2, "list2:");

    std::shared_ptr<std::array<int, 9>> list3(new std::array<int, 9>{{-1, 22,40,8,10,9,13, 41,55}});
    sortViaDirectInsertWithWatcherElement(*list3, 1, 7);
    verifySorted(*list3);
}

