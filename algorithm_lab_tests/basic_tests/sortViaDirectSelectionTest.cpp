#include <array>
#include <string>
#include "gtest/gtest.h"
#include "sorters.h"

class SortViaDirectSelectionTest : public testing::Test {
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


TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionBasicTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaDirectSelection<true>(*list);
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
    sortViaDirectSelection<true>(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(1.1, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaDirectSelection<true>(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a1", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionBasicTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaDirectSelection<true>(*list);
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
    sortViaDirectSelection<false>(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(1.1, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaDirectSelection<false>(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a1", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaDirectSelection<true>(*list);
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
    sortViaDirectSelection<true>(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(2.3, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaDirectSelection<false>(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*list), DataEmptyException);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*dList), DataEmptyException);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*sList), DataEmptyException);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionCornerCasesTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{-5,2,7,8,-4,3,1,10,9}});
    sortViaDirectSelection<false>(*list);
    EXPECT_EQ(-5, (*list)[0]);
    EXPECT_EQ(-4, (*list)[1]);
    EXPECT_EQ(1, (*list)[2]);
    EXPECT_EQ(2, (*list)[3]);
    EXPECT_EQ(3, (*list)[4]);
    EXPECT_EQ(7, (*list)[5]);
    EXPECT_EQ(8, (*list)[6]);
    EXPECT_EQ(9, (*list)[7]);
    EXPECT_EQ(10, (*list)[8]);

    std::shared_ptr<std::array<int, 9>> listOne(new std::array<int, 9>{{-5}});
    sortViaDirectSelection<false>(*listOne);
    EXPECT_EQ(-5, (*listOne)[0]);

    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{-5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaDirectSelection<false>(*dList);
    EXPECT_EQ(-5.2, (*dList)[0]);
    EXPECT_EQ(-0.5, (*dList)[1]);
    EXPECT_EQ(1.1, (*dList)[2]);
    EXPECT_EQ(2.3, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<double,7>> dListOne(new std::array<double,7>{{-5.2}});
    sortViaDirectSelection<false>(*dListOne);
    EXPECT_EQ(-5.2, (*dListOne)[0]);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionCornerCasesTest) {
    std::shared_ptr<std::array<int, 9>> listOne(new std::array<int, 9>{{-5}});
    sortViaDirectSelection<true>(*listOne);
    EXPECT_EQ(-5, (*listOne)[0]);

    std::shared_ptr<std::array<double,7>> dListOne(new std::array<double,7>{{-5.2}});
    sortViaDirectSelection<true>(*dListOne);
    EXPECT_EQ(-5.2, (*dListOne)[0]);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaDirectSelection<false>(*list);
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
    sortViaDirectSelection<false>(*dList);
    EXPECT_EQ(-0.5, (*dList)[0]);
    EXPECT_EQ(2.3, (*dList)[1]);
    EXPECT_EQ(2.3, (*dList)[2]);
    EXPECT_EQ(5.2, (*dList)[3]);
    EXPECT_EQ(9.9, (*dList)[4]);
    EXPECT_EQ(10.8, (*dList)[5]);
    EXPECT_EQ(13.8, (*dList)[6]);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaDirectSelection<false>(*sList);
    EXPECT_EQ("1A", (*sList)[0]);
    EXPECT_EQ("1a", (*sList)[1]);
    EXPECT_EQ("A1", (*sList)[2]);
    EXPECT_EQ("a", (*sList)[3]);
    EXPECT_EQ("a", (*sList)[4]);
    EXPECT_EQ("ab", (*sList)[5]);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*list), DataEmptyException);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*dList), DataEmptyException);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    ASSERT_THROW(sortViaDirectSelection<false>(*sList), DataEmptyException);
}


