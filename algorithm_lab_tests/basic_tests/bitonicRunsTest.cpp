#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class BitonicRunsTest : public testing::Test {
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

TEST_F(BitonicRunsTest, bitonicRunsBasicTest) {
    std::queue<size_t> indexes;

    std::shared_ptr<std::array<int, 3>> list(new std::array<int, 3>{{1,2,3}});
    indexes = findIndexesOfBitonicRuns(*list);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 3>> list2(new std::array<int, 3>{{1,2,2}});
    indexes = findIndexesOfBitonicRuns(*list2);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 10>> list3(new std::array<int, 10>{{-1,-1,2,2,3,3,5,6,6,6}});
    indexes = findIndexesOfBitonicRuns(*list3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 10>> list4(new std::array<int, 10>{{6,6,6,5,3,3,2,2,-1,-1}});
    indexes = findIndexesOfBitonicRuns(*list4);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 10>> list5(new std::array<int, 10>{{8,7,6,5,3,3,2,2,-1,-1}});
    indexes = findIndexesOfBitonicRuns(*list5);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<double, 3>> dList(new std::array<double, 3>{{1.1,2.1,3.0}});
    indexes = findIndexesOfBitonicRuns(*dList);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<double, 3>> dList2(new std::array<double, 3>{{1.1,2.2,2.2}});
    indexes = findIndexesOfBitonicRuns(*dList2);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<double, 10>> dList3(new std::array<double, 10>{{-1.9,-1.9,2.1,2.32,3.3,3.3,5.3,6.5,6.55,6.55}});
    indexes = findIndexesOfBitonicRuns(*dList3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<std::string, 3>> sList(new std::array<std::string, 3>{{"1", "A", "a"}});
    indexes = findIndexesOfBitonicRuns(*sList);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<std::string, 3>> sList2(new std::array<std::string, 3>{{"1", "A", "A"}});
    indexes = findIndexesOfBitonicRuns(*sList2);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<std::string, 6>> sList3(new std::array<std::string, 6>{{"1", "A", "a", "b", "cc", "dd"}});
    indexes = findIndexesOfBitonicRuns(*sList3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(6ul, indexes.front()); indexes.pop();
    EXPECT_EQ(6ul, indexes.front()); indexes.pop();
}

TEST_F(BitonicRunsTest, bitonicRunsComplexTest) {
    std::queue<size_t> indexes;

    std::shared_ptr<std::array<int, 10>> list(new std::array<int, 10>{{-1,-1,2,2,1,/**/2,3, 2, 6,7}});
    indexes = findIndexesOfBitonicRuns(*list);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());

    EXPECT_EQ(0ul, indexes.front()); indexes.pop(); // 1
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop(); // 2
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop(); // 3
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 10>> list2(new std::array<int, 10>{{-1,-1,2,2,1, 2,3,2, 6,-2}});
    indexes = findIndexesOfBitonicRuns(*list2);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop(); // 1
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop(); // 2
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop(); // 3
    EXPECT_EQ(9ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 4>> list3(new std::array<int, 4>{{6,4, 7,2}});
    indexes = findIndexesOfBitonicRuns(*list3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(6ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop(); // 1
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop(); // 2
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<double, 10>> dList(new std::array<double, 10>
            {{-1.9,-1.9,2.1,1.32, 3.3, 3.3,2.3, 6.5, 6.55, 6.55}});
    indexes = findIndexesOfBitonicRuns(*dList);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop(); // 1
    EXPECT_EQ(3ul, indexes.front()); indexes.pop();
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();
    EXPECT_EQ(4ul, indexes.front()); indexes.pop(); // 2
    EXPECT_EQ(6ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop(); // 3
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();
}

TEST_F(BitonicRunsTest, bitonicRunsCornerCasesTest) {
    std::queue<size_t> indexes;

    std::shared_ptr<std::array<int, 10>> list(new std::array<int, 10>{{-1, -2, 2, 2, 1, 2, 3, 2, 6, -10}});
    indexes = findIndexesOfBitonicRuns(*list);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(12ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop(); // 1
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop(); // 2
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop(); // 3
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop();
    EXPECT_EQ(8ul, indexes.front()); indexes.pop(); // 4
    EXPECT_EQ(9ul, indexes.front()); indexes.pop();
    EXPECT_EQ(10ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 2>> list2(new std::array<int, 2>{{1, 2}});
    indexes = findIndexesOfBitonicRuns(*list2);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 2>> list3(new std::array<int, 2>{{6, 2}});
    indexes = findIndexesOfBitonicRuns(*list3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();
    EXPECT_EQ(2ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 1>> list4(new std::array<int, 1>{{-1}});
    indexes = findIndexesOfBitonicRuns(*list4);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();
    EXPECT_EQ(1ul, indexes.front()); indexes.pop();

    std::shared_ptr<std::array<int, 0>> list5(new std::array<int, 0>);
    indexes = findIndexesOfBitonicRuns(*list5);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
}

TEST_F(BitonicRunsTest, bitonicRunsForNaturalMergeSortTest) {
    std::queue<size_t> indexes;

    // case 1: 2 exact bitonic runs
    std::shared_ptr<std::array<int, 16>> list(new std::array<int, 16>{{-1,-1,2,2,3 ,2,1,/**/2,4,6,7,8, 5,2,1,0}});
    indexes = findIndexesOfBitonicRuns(*list);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(6ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(12ul, indexes.front()); indexes.pop();
    EXPECT_EQ(16ul, indexes.front()); indexes.pop();

    // case 2: 2 exact bitonic runs but another asc only at the end
    std::shared_ptr<std::array<int, 16>> list1(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/5,8}});
    indexes = findIndexesOfBitonicRuns(*list1);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(12ul, indexes.front()); indexes.pop();
    EXPECT_EQ(14ul, indexes.front()); indexes.pop();
    EXPECT_EQ(14ul, indexes.front()); indexes.pop();
    EXPECT_EQ(16ul, indexes.front()); indexes.pop();
    EXPECT_EQ(16ul, indexes.front()); indexes.pop();

    // case 3: 2 exact bitonic runs but another desc only at the end
    std::shared_ptr<std::array<int, 16>> list2(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/10,8}});
    indexes = findIndexesOfBitonicRuns(*list2);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(7ul, indexes.front()); indexes.pop();
    EXPECT_EQ(12ul, indexes.front()); indexes.pop();
    EXPECT_EQ(14ul, indexes.front()); indexes.pop();
    EXPECT_EQ(14ul, indexes.front()); indexes.pop();
    EXPECT_EQ(15ul, indexes.front()); indexes.pop();
    EXPECT_EQ(16ul, indexes.front()); indexes.pop();

    // case 4: 3 exact bitonic runs
    std::shared_ptr<std::array<int, 16>> list3(new std::array<int, 16>{{-1,-1,2,3, 1,/**/2,6,7,8, 1,0, /**/5,6,7, 3,1}});
    indexes = findIndexesOfBitonicRuns(*list3);
    EXPECT_TRUE(indexes.size() % 3 == 0);
    EXPECT_EQ(9ul, indexes.size());
    EXPECT_EQ(0ul, indexes.front()); indexes.pop();
    EXPECT_EQ(4ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(5ul, indexes.front()); indexes.pop();
    EXPECT_EQ(9ul, indexes.front()); indexes.pop();
    EXPECT_EQ(11ul, indexes.front()); indexes.pop();
    EXPECT_EQ(11ul, indexes.front()); indexes.pop();
    EXPECT_EQ(14ul, indexes.front()); indexes.pop();
    EXPECT_EQ(16ul, indexes.front()); indexes.pop();

}