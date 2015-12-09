#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class BottomUpMergeSortTest : public testing::Test {
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

TEST_F(BottomUpMergeSortTest, powersOf2Test) {
    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
    sortViaBottomUpMergesort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{6,4, 7,2}});
    sortViaBottomUpMergesort(*list2);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 8>> list3(new std::array<int, 8>{{3,4, 7,2, 2,1, 3,1}});
    sortViaBottomUpMergesort(*list3);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 16>> list4(new std::array<int, 16>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,78, 45,109, 33,11234}});
    sortViaBottomUpMergesort(*list4);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 32>> list5(new std::array<int, 32>{{3,4,  7,2,   2,1,   3,1,     9,22,     77,78, 45,109, 33,11234,
                                                                        2,11, 333,1, 9,222, 77,7668, 415,1091, 2,1,   3,-1,   9,22,    }});
    sortViaBottomUpMergesort(*list5);
    verifySorted(*list5);
}

TEST_F(BottomUpMergeSortTest, DescendingPresortedTest) {
    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
    sortViaBottomUpMergesort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{7,6,4,2}});
    sortViaBottomUpMergesort(*list2);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 8>> list3(new std::array<int, 8>{{18,14,14,13,12,11,11,10}});
    sortViaBottomUpMergesort(*list3);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 16>> list4(new std::array<int, 16>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2}});
    sortViaBottomUpMergesort(*list4);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 32>> list5(new std::array<int, 32>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2,
                                                                        -1,-2,-4,-5,-6,-7,-22,-33,-45,-56,-66,-67,-89,-90,-122,-134}});
    sortViaBottomUpMergesort(*list5);
    verifySorted(*list5);
}

TEST_F(BottomUpMergeSortTest, oddSizeTest) {
    std::shared_ptr<std::array<int, 3>> list(new std::array<int, 3>{{3,4, 1}});
    sortViaBottomUpMergesort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 6>> list2(new std::array<int, 6>{{6,4, 7,2, 9,1}});
    sortViaBottomUpMergesort(*list2);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 9>> list3(new std::array<int, 9>{{2,1, 3,1, 9,10, 18,22, 5}});
    sortViaBottomUpMergesort(*list3);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 15>> list4(new std::array<int, 15>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,51, 45,10}});
    sortViaBottomUpMergesort(*list4);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 22>> list5(new std::array<int, 22>{{3,4,    7,2,   2,1,  3,1, 9,22, 77,51, 45,10, 23,-1,
                                                                        -33,-4, 77,12, 245,1 }});
    sortViaBottomUpMergesort(*list5);
    verifySorted(*list5);

    std::shared_ptr<std::array<int, 33>> list6(new std::array<int, 33>{{3,4,  7,2,   2,1,   3,1,     9,22,     77,78, 45,109, 33,11234,
                                                                        2,11, 333,1, 9,222, 77,7668, 415,1091, 2,1,   3,-1,   9,22,     5}});
    sortViaBottomUpMergesort(*list6);
    verifySorted(*list6);
}

TEST_F(BottomUpMergeSortTest, cornerCasesTest) {
    std::shared_ptr<std::array<int, 0>> list(new std::array<int, 0>);
    sortViaBottomUpMergesort(*list);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 1>> list2(new std::array<int, 1>{{5}});
    sortViaBottomUpMergesort(*list2);
    verifySorted(*list2);
}

TEST_F(BottomUpMergeSortTest, doublesTest) {
    std::shared_ptr<std::array<double, 2>> dList(new std::array<double, 2>{{5.3,4.4}});
    sortViaBottomUpMergesort(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<double, 4>> dList2(new std::array<double, 4>{{6.3,4.4, 7.1,2.22}});
    sortViaBottomUpMergesort(*dList2);
    verifySorted(*dList2);

    std::shared_ptr<std::array<double, 3>> dList3(new std::array<double, 3>{{3.1,4.5, 1.1}});
    sortViaBottomUpMergesort(*dList3);
    verifySorted(*dList3);

    std::shared_ptr<std::array<double, 6>> dList4(new std::array<double, 6>{{6.1,4.4, 7.5,2.6, 9.4,1.1}});
    sortViaBottomUpMergesort(*dList4);
    verifySorted(*dList4);

    std::shared_ptr<std::array<double, 9>> dList5(new std::array<double, 9>{{2.09,1.1, 3.77,1.1, 9.1,10.67, 18.22,22.1, 5.4}});
    sortViaBottomUpMergesort(*dList5);
    verifySorted(*dList5);
}

TEST_F(BottomUpMergeSortTest, stringsTest) {
    std::shared_ptr<std::array<std::string, 2>> dList(new std::array<std::string, 2>{{"a","65"}});
    sortViaBottomUpMergesort(*dList);
    verifySorted(*dList);

    std::shared_ptr<std::array<std::string, 4>> dList2(new std::array<std::string, 4>{{"Z","ab4", "z7","t"}});
    sortViaBottomUpMergesort(*dList2);
    verifySorted(*dList2);

    std::shared_ptr<std::array<std::string, 3>> dList3(new std::array<std::string, 3>{{"gh","HGt", "gh56"}});
    sortViaBottomUpMergesort(*dList3);
    verifySorted(*dList3);

    std::shared_ptr<std::array<std::string, 6>> dList4(new std::array<std::string, 6>{{"fhs","df2", "df","gh", "12b","dsd2"}});
    sortViaBottomUpMergesort(*dList4);
    verifySorted(*dList4);

    std::shared_ptr<std::array<std::string, 9>> dList5(new std::array<std::string, 9>{{"df4","df", "324f","df23", "91","42hall", "324ef","df22", "sdf"}});
    sortViaBottomUpMergesort(*dList5);
    verifySorted(*dList5);

}
