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
    EXPECT_EQ(-4, (*list)[0]);
    EXPECT_EQ(1, (*list)[1]);
    EXPECT_EQ(2, (*list)[2]);
    EXPECT_EQ(3, (*list)[3]);
    EXPECT_EQ(5, (*list)[4]);
    EXPECT_EQ(7, (*list)[5]);
    EXPECT_EQ(8, (*list)[6]);
    EXPECT_EQ(9, (*list)[7]);
    EXPECT_EQ(10, (*list)[8]);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaNormalDirectInsert(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(1.1, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaNormalDirectInsert(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a1", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithoutWatcherDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaNormalDirectInsert(*list);
    EXPECT_EQ(-4, (*list)[0]);
    EXPECT_EQ(1, (*list)[1]);
    EXPECT_EQ(2, (*list)[2]);
    EXPECT_EQ(3, (*list)[3]);
    EXPECT_EQ(5, (*list)[4]);
    EXPECT_EQ(5, (*list)[5]);
    EXPECT_EQ(7, (*list)[6]);
    EXPECT_EQ(8, (*list)[7]);
    EXPECT_EQ(9, (*list)[8]);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaNormalDirectInsert(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(2.3, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaNormalDirectInsert(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithWatcherEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    ASSERT_THROW(sortViaDirectInsertWithWatcherElement(*list), DataEmptyException);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    ASSERT_THROW(sortViaDirectInsertWithWatcherElement(*dList), DataEmptyException);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    ASSERT_THROW(sortViaDirectInsertWithWatcherElement(*sList), DataEmptyException);
}


TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithWatcherElement) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaDirectInsertWithWatcherElement(*list);
    EXPECT_EQ(-4, (*list)[0]);
    EXPECT_EQ(1, (*list)[1]);
    EXPECT_EQ(2, (*list)[2]);
    EXPECT_EQ(3, (*list)[3]);
    EXPECT_EQ(5, (*list)[4]);
    EXPECT_EQ(7, (*list)[5]);
    EXPECT_EQ(8, (*list)[6]);
    EXPECT_EQ(9, (*list)[7]);
    EXPECT_EQ(10, (*list)[8]);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaDirectInsertWithWatcherElement(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(1.1, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaDirectInsertWithWatcherElement(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a1", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWitWatcherDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaDirectInsertWithWatcherElement(*list);
    EXPECT_EQ(-4, (*list)[0]);
    EXPECT_EQ(1, (*list)[1]);
    EXPECT_EQ(2, (*list)[2]);
    EXPECT_EQ(3, (*list)[3]);
    EXPECT_EQ(5, (*list)[4]);
    EXPECT_EQ(5, (*list)[5]);
    EXPECT_EQ(7, (*list)[6]);
    EXPECT_EQ(8, (*list)[7]);
    EXPECT_EQ(9, (*list)[8]);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaDirectInsertWithWatcherElement(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(2.3, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaDirectInsertWithWatcherElement(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectInsertTest, sortViaDirectInsertWithoutWatcherEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaNormalDirectInsert(*list);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    sortViaNormalDirectInsert(*dList);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    sortViaNormalDirectInsert(*sList);
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

