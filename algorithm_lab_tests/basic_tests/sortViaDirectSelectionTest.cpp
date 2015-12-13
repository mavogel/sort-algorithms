#include <array>
#include <string>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

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
    sortViaOptimalDirectSelection(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaOptimalDirectSelection(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionBasicTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,10,9}});
    sortViaOptimalDirectSelection(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaNonOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a1", "A1", "1A"}});
    sortViaNonOptimalDirectSelection(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaOptimalDirectSelection(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaNonOptimalDirectSelection(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaOptimalDirectSelection(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    sortViaOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    sortViaOptimalDirectSelection(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionCornerCasesTest) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{-5,2,7,8,-4,3,1,10,9}});
    sortViaNonOptimalDirectSelection(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 9>> listOne(new std::array<int, 9>{{-5}});
    sortViaNonOptimalDirectSelection(*listOne);
    verifySorted(*listOne);

    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{-5.2, 2.3, 13.8, 9.9, 10.8, 1.1, -0.5}});
    sortViaNonOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<double,7>> dListOne(new std::array<double,7>{{-5.2}});
    sortViaNonOptimalDirectSelection(*dListOne);
    verifySorted(*dListOne);
}

TEST_F(SortViaDirectSelectionTest, sortViaOptimalDirectSelectionCornerCasesTest) {
    std::shared_ptr<std::array<int, 9>> listOne(new std::array<int, 9>{{-5}});
    sortViaOptimalDirectSelection(*listOne);
    verifySorted(*listOne);

    std::shared_ptr<std::array<double,7>> dListOne(new std::array<double,7>{{-5.2}});
    sortViaOptimalDirectSelection(*dListOne);
    verifySorted(*dListOne);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionDoubledValues) {
    std::shared_ptr<std::array<int, 9>> list(new std::array<int, 9>{{5,2,7,8,-4,3,1,5,9}});
    sortViaNonOptimalDirectSelection(*list);
    verifySorted(*list);


    std::shared_ptr<std::array<double,7>> dList(new std::array<double,7>{{5.2, 2.3, 13.8, 9.9, 10.8, 2.3, -0.5}});
    sortViaNonOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 6>> sList(new std::array<std::string, 6>{{"a", "1a", "ab", "a", "A1", "1A"}});
    sortViaNonOptimalDirectSelection(*sList);
    verifySorted(*sList);
}

TEST_F(SortViaDirectSelectionTest, sortViaNonOptimalDirectSelectionEmptyData) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaOptimalDirectSelection(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<double,0>> dList(new std::array<double,0>);
    sortViaOptimalDirectSelection(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 0>> sList(new std::array<std::string, 0>);
    sortViaOptimalDirectSelection(*sList);
    verifySorted(*sList);
}


