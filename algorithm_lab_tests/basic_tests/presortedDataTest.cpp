#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class PreSortedDataTest : public testing::Test {
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

TEST_F(PreSortedDataTest, basicTest) {
    std::vector<size_t> indexes;

    std::shared_ptr<std::array<int, 3>> list(new std::array<int, 3>{{1,2,3}});
    indexes = findIndexesOfPresortedData(*list);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<int, 3>> list2(new std::array<int, 3>{{1,2,2}});
    indexes = findIndexesOfPresortedData(*list2);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<int, 10>> list3(new std::array<int, 10>{{-1,-1,2,2,3,3,5,6,6,6}});
    indexes = findIndexesOfPresortedData(*list3);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(10ul, indexes[1]);

    std::shared_ptr<std::array<double, 3>> dList(new std::array<double, 3>{{1.1,2.1,3.0}});
    indexes = findIndexesOfPresortedData(*dList);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<double, 3>> dList2(new std::array<double, 3>{{1.1,2.2,2.2}});
    indexes = findIndexesOfPresortedData(*dList2);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<double, 10>> dList3(new std::array<double, 10>{{-1.9,-1.9,2.1,2.32,3.3,3.3,5.3,6.5,6.55,6.55}});
    indexes = findIndexesOfPresortedData(*dList3);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(10ul, indexes[1]);

    std::shared_ptr<std::array<std::string, 3>> sList(new std::array<std::string, 3>{{"1", "A", "a"}});
    indexes = findIndexesOfPresortedData(*sList);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<std::string, 3>> sList2(new std::array<std::string, 3>{{"1", "A", "A"}});
    indexes = findIndexesOfPresortedData(*sList2);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(3ul, indexes[1]);

    std::shared_ptr<std::array<std::string, 6>> sList3(new std::array<std::string, 6>{{"1", "A", "a", "b", "cc", "dd"}});
    indexes = findIndexesOfPresortedData(*sList3);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes[0]);
    EXPECT_EQ(6ul, indexes[1]);
}

TEST_F(PreSortedDataTest, complexTest) {
    std::vector<size_t> indexes;

    std::shared_ptr<std::array<int, 10>> list(new std::array<int, 10>{{-1,-1,2,2, 1,2,3, 2,6,7}});
    indexes = findIndexesOfPresortedData(*list);
    EXPECT_EQ(4ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(4ul, indexes.at(1));
    EXPECT_EQ(7ul, indexes.at(2));
    EXPECT_EQ(10ul, indexes.at(3));

    std::shared_ptr<std::array<int, 10>> list2(new std::array<int, 10>{{-1,-1,2,2, 1,2,3, 2,6,-2}});
    indexes = findIndexesOfPresortedData(*list2);
    EXPECT_EQ(5ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(4ul, indexes.at(1));
    EXPECT_EQ(7ul, indexes.at(2));
    EXPECT_EQ(9ul, indexes.at(3));
    EXPECT_EQ(10ul, indexes.at(4));

    std::shared_ptr<std::array<int, 4>> list3(new std::array<int, 4>{{6,4, 7,2}});
    indexes = findIndexesOfPresortedData(*list3);
    EXPECT_EQ(4ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(1ul, indexes.at(1));
    EXPECT_EQ(3ul, indexes.at(2));
    EXPECT_EQ(4ul, indexes.at(3));

    std::shared_ptr<std::array<double, 10>> dList(new std::array<double, 10>
    {{-1.9,-1.9,2.1, 1.32, 3.3, 3.3, 2.3, 6.5, 6.55, 6.55}});
    indexes = findIndexesOfPresortedData(*dList);
    EXPECT_EQ(4ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(3ul, indexes.at(1));
    EXPECT_EQ(6ul, indexes.at(2));
    EXPECT_EQ(10ul, indexes.at(3));

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"1", "A", "2", "b", "Z", "dd"}});
    indexes = findIndexesOfPresortedData(*sList);
    EXPECT_EQ(4ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(2ul, indexes.at(1));
    EXPECT_EQ(4ul, indexes.at(2));
    EXPECT_EQ(6ul, indexes.at(3));
}

TEST_F(PreSortedDataTest, cornerCasesTest) {
    std::vector<size_t> indexes;

    std::shared_ptr<std::array<int, 10>> list(new std::array<int, 10>{{-1,-2,2,2,1,2,3,2,6,-10}});
    indexes = findIndexesOfPresortedData(*list);
    EXPECT_EQ(6ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(1ul, indexes.at(1));
    EXPECT_EQ(4ul, indexes.at(2));
    EXPECT_EQ(7ul, indexes.at(3));
    EXPECT_EQ(9ul, indexes.at(4));
    EXPECT_EQ(10ul, indexes.at(5));

    std::shared_ptr<std::array<int, 2>> list2(new std::array<int, 2>{{1,2}});
    indexes = findIndexesOfPresortedData(*list2);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(2ul, indexes.at(1));

    std::shared_ptr<std::array<int, 2>> list3(new std::array<int, 2>{{6,2}});
    indexes = findIndexesOfPresortedData(*list3);
    EXPECT_EQ(3ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(1ul, indexes.at(1));
    EXPECT_EQ(2ul, indexes.at(2));

    std::shared_ptr<std::array<int, 1>> list4(new std::array<int, 1>{{-1}});
    indexes = findIndexesOfPresortedData(*list4);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(1ul, indexes.at(1));

    std::shared_ptr<std::array<int, 0>> list5(new std::array<int, 0>);
    indexes = findIndexesOfPresortedData(*list5);
    EXPECT_EQ(2ul, indexes.size());
    EXPECT_EQ(0ul, indexes.at(0));
    EXPECT_EQ(0ul, indexes.at(1));
}
