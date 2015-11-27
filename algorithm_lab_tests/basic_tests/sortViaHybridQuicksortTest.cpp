#include <array>
#include <string>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class HybridQuickSortTest : public testing::Test {
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

TEST_F(HybridQuickSortTest, basicTest) {
    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
    sortViaHybridQuicksort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 3>> list1(new std::array<int, 3>{{33, 22, 11}});
    sortViaHybridQuicksort(*list1);
    verifySorted(*list1);

    std::shared_ptr<std::array<int, 3>> list11(new std::array<int, 3>{{3, 4, 1}});
    sortViaHybridQuicksort(*list11);
    verifySorted(*list11);

    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{6,4, 7,2}});
    sortViaHybridQuicksort(*list2);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 6>> list3(new std::array<int, 6>{{6,4, 7,2, 9,1}});
    sortViaHybridQuicksort(*list3);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 8>> list4(new std::array<int, 8>{{3,4, 7,2, 2,1, 3,1}});
    sortViaHybridQuicksort(*list4);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 9>> list5(new std::array<int, 9>{{2,1, 3,1, 9,10, 18,22, 5}});
    sortViaHybridQuicksort(*list5);
    verifySorted(*list5);

    std::shared_ptr<std::array<int, 15>> list6(new std::array<int, 15>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,51, 45,10}});
    sortViaHybridQuicksort(*list6);
    verifySorted(*list6);


    std::shared_ptr<std::array<int, 22>> list8(new std::array<int, 22>{{3,4,    7,2,   2,1,  3,1, 9,22, 77,51, 45,10, 23,-1,
                                                                        -33,-4, 77,12, 245,1 }});
    sortViaHybridQuicksort(*list8);
    verifySorted(*list8);

}

TEST_F(HybridQuickSortTest, worstCaseTestWithMerge) {
    std::shared_ptr<std::array<int, 16>> list7(new std::array<int, 16>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,78, 45,109, 33,11234}});
    sortViaHybridQuicksort(*list7);
    verifySorted(*list7);

    std::shared_ptr<std::array<int, 33>> list9(new std::array<int, 33>{{3,4,  7,2,   2,1,   3,1,     9,22,     77,78, 45,109, 33,11234,
                                                                        2,11, 333,1, 9,222, 77,7668, 415,1091, 2,1,   3,-1,   9,22,     5}});
    sortViaHybridQuicksort(*list9);
    verifySorted(*list9);
}

TEST_F(HybridQuickSortTest, depthLimit50kIntegerTest) {
    // == conditions ==
    const int size = 50000;

    // == prepare ==
    std::shared_ptr<std::array<int, size>> list(new std::array<int, size>);
    initRandomIntegers(*list);

    // == go ==
    sortViaHybridQuicksort(*list);

    // == verify ==
    verifySorted(*list);
}

TEST_F(HybridQuickSortTest, DescendingPresortedTest) {
    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
    sortViaHybridQuicksort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{7,6,4,2}});
    sortViaHybridQuicksort(*list2);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 8>> list3(new std::array<int, 8>{{18,14,14,13,12,11,11,10}});
    sortViaHybridQuicksort(*list3);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 16>> list4(new std::array<int, 16>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2}});
    sortViaHybridQuicksort(*list4);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 32>> list5(new std::array<int, 32>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2,
                                                                        -1,-2,-4,-5,-6,-7,-22,-33,-45,-56,-66,-67,-89,-90,-122,-134}});
    sortViaHybridQuicksort(*list5);
    verifySorted(*list5);
}
