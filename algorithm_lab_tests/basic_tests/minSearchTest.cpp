#include <array>
#include <string>
#include <memory>
#include "gtest/gtest.h"
#include "minsearch.h"

class MinSearchTest : public testing::Test {
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


TEST_F(MinSearchTest, basicTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,9,10}});
    EXPECT_EQ(4ul,optimalMinSearch(*list));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list));

    std::shared_ptr<std::array<int, 10>> list2(new std::array<int, 10> {{-66,5,2,7,8,-4,3,1,9,10}});
    EXPECT_EQ(0ul,optimalMinSearch(*list2));
    EXPECT_EQ(0ul,nonOptimalMinSearch(*list2));

    std::shared_ptr<std::array<double,7>> dList(new std::array<double, 7>{{5.2, 2.3, 9.9, 10.8, 1.1, -0.5, 13.8}});
    EXPECT_EQ(5ul,optimalMinSearch(*dList));
    EXPECT_EQ(5ul,nonOptimalMinSearch(*dList));

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"afbf", "dslsdl", "ab", "cdffg", "oeodod33", "ab2323"}});
    EXPECT_EQ(2ul, optimalMinSearch(*sList));
    EXPECT_EQ(2ul, nonOptimalMinSearch(*sList));
}

TEST_F(MinSearchTest, testWithHighStartIndex) {
    std::shared_ptr<std::array<int, 9>> list (new std::array<int, 9>{{5,2,7,8,-4,3,1,9,10}});
    EXPECT_EQ(6ul,optimalMinSearch(*list,5));
    EXPECT_EQ(8ul,nonOptimalMinSearch(*list,8));
    EXPECT_EQ(7ul,nonOptimalMinSearch(*list,7));
    EXPECT_EQ(6ul,nonOptimalMinSearch(*list,6));
    EXPECT_EQ(6ul,nonOptimalMinSearch(*list,5));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list,4));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list,3));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list,2));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list,1));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list,0));

    std::shared_ptr<std::array<int, 10>> list3(new std::array<int, 10>{{5,2,7,8,-4,-66,3,1,9,10}});
    EXPECT_EQ(5ul,optimalMinSearch(*list3,5));
    EXPECT_EQ(7ul,nonOptimalMinSearch(*list3,6));
    EXPECT_EQ(5ul,nonOptimalMinSearch(*list3,2));

    std::shared_ptr<std::array<double,8>> dList(new std::array<double,8>{{5.2, 2.3, 9.9, 10.8, 1.1, -0.5, 13.8, 3.1}});
    EXPECT_EQ(7ul,optimalMinSearch(*dList, 6));
    EXPECT_EQ(7ul,nonOptimalMinSearch(*dList, 6));
    EXPECT_EQ(5ul,nonOptimalMinSearch(*dList, 2));

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"afbf", "Aslsdl", "ab", "cdffg", "oeodod33", "ab2323"}});
    EXPECT_EQ(5ul, optimalMinSearch(*sList, 3));
    EXPECT_EQ(1ul, nonOptimalMinSearch(*sList, 1));
}

TEST_F(MinSearchTest, testWithCornerCases) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{-9,2,7,8,-4,3,1,9,-10}});
    EXPECT_EQ(8ul,optimalMinSearch(*list,0));
    EXPECT_EQ(8ul,optimalMinSearch(*list,1));
    EXPECT_EQ(8ul,optimalMinSearch(*list,2));
    EXPECT_EQ(8ul,optimalMinSearch(*list,3));
    EXPECT_EQ(8ul,optimalMinSearch(*list,4));
    EXPECT_EQ(8ul,optimalMinSearch(*list,5));
    EXPECT_EQ(8ul,optimalMinSearch(*list,6));
    EXPECT_EQ(8ul,optimalMinSearch(*list,7));
    EXPECT_EQ(8ul,optimalMinSearch(*list,8));

    std::shared_ptr<std::array<int, 9>> list2(new std::array<int, 9>{{-9,2,7,8,-4,3,1,9,10}});
    EXPECT_EQ(6ul,optimalMinSearch(*list2,5));
    EXPECT_EQ(8ul,nonOptimalMinSearch(*list2,8));
    EXPECT_EQ(7ul,nonOptimalMinSearch(*list2,7));
    EXPECT_EQ(6ul,nonOptimalMinSearch(*list2,6));
    EXPECT_EQ(6ul,nonOptimalMinSearch(*list2,5));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list2,4));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list2,3));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list2,2));
    EXPECT_EQ(4ul,nonOptimalMinSearch(*list2,1));
    EXPECT_EQ(0ul,nonOptimalMinSearch(*list2,0));
}

TEST_F(MinSearchTest, testWithEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    ASSERT_THROW(optimalMinSearch(*list,0), DataEmptyException);

    std::shared_ptr<std::array<double, 0>> dList(new std::array<double, 0>);
    ASSERT_THROW(optimalMinSearch(*dList,0), DataEmptyException);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    ASSERT_THROW(optimalMinSearch(*sList,0), DataEmptyException);
}

TEST_F(MinSearchTest, testWithOneElementData) {
    std::shared_ptr<std::array<int, 1>> list(new std::array<int, 1>{{5}});
    EXPECT_EQ(0ul,optimalMinSearch(*list,0));
    EXPECT_EQ(0ul,nonOptimalMinSearch(*list,0));

    std::shared_ptr<std::array<double,1>> dList(new std::array<double, 1>{{1.2}});
    EXPECT_EQ(0ul,optimalMinSearch(*dList,0));
    EXPECT_EQ(0ul,nonOptimalMinSearch(*list,0));

    std::shared_ptr<std::array<std::string, 1>> sList(new std::array<std::string, 1>{{"ab"}});
    EXPECT_EQ(0ul,optimalMinSearch(*sList,0));
    EXPECT_EQ(0ul,nonOptimalMinSearch(*sList,0));
}

TEST_F(MinSearchTest, testStartIndexOutOfRange) {
    std::shared_ptr<std::array<int, 1>> list(new std::array<int, 1>{{5}});
    ASSERT_THROW(optimalMinSearch(*list,-5), IndexOutOfRangeException);
    ASSERT_THROW(optimalMinSearch(*list, 5), IndexOutOfRangeException);

    std::shared_ptr<std::array<double,1>> dList(new std::array<double, 1>{{1.2}});
    ASSERT_THROW(optimalMinSearch(*dList,-5), IndexOutOfRangeException);
    ASSERT_THROW(optimalMinSearch(*dList, 5), IndexOutOfRangeException);

    std::shared_ptr<std::array<std::string, 1>> sList(new std::array<std::string, 1>{{"ab"}});
    ASSERT_THROW(optimalMinSearch(*sList,-5), IndexOutOfRangeException);
    ASSERT_THROW(optimalMinSearch(*sList, 5), IndexOutOfRangeException);
}

TEST_F(MinSearchTest, testWithDoubledValues) {
    std::shared_ptr<std::array<int, 6>> list(new std::array<int, 6>{{5, 4, -1, 3, 4, -1}});
    EXPECT_EQ(2ul,optimalMinSearch(*list,0));
    EXPECT_EQ(5ul,nonOptimalMinSearch(*list,0));

    std::shared_ptr<std::array<double,7>> dList(new std::array<double, 7>{{1.2, 5.5, 6.4, -1.3, -4.3, 5.5, -4.3}});
    EXPECT_EQ(4ul,optimalMinSearch(*dList,0));
    EXPECT_EQ(6ul,nonOptimalMinSearch(*dList,0));

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"afbf", "aslsdl", "ab", "cdffg", "oeodod33", "ab"}});
    EXPECT_EQ(2ul,optimalMinSearch(*sList,0));
    EXPECT_EQ(5ul,nonOptimalMinSearch(*sList,0));
}

TEST_F(MinSearchTest, testWithStartAndEndIndex) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,9,10}});
    EXPECT_EQ(4ul,optimalMinSearch(*list, 0, 8));
    EXPECT_EQ(6ul,optimalMinSearch(*list, 5, 8));
    EXPECT_EQ(1ul,optimalMinSearch(*list, 0, 4));
    EXPECT_EQ(4ul,optimalMinSearch(*list, 3, 6));
    EXPECT_EQ(6ul,optimalMinSearch(*list, 5, 7));
}
