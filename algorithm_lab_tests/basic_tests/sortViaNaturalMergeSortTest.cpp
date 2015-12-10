#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class NaturalMergeSortTest : public testing::Test {
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

//TEST_F(NaturalMergeSortTest, powersOf2Test) {
//    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
//    sortViaNaturalMergesort(*list);
//    verifySorted(*list);
//
//    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{6,4, 7,2}});
//    sortViaNaturalMergesort(*list2);
//    verifySorted(*list2);
//
//    std::shared_ptr<std::array<int, 8>> list3(new std::array<int, 8>{{3,4, 7,2, 2,1, 3,1}});
//    sortViaNaturalMergesort(*list3);
//    verifySorted(*list3);
//
//    std::shared_ptr<std::array<int, 16>> list4(new std::array<int, 16>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,78, 45,109, 33,11234}});
//    sortViaNaturalMergesort(*list4);
//    verifySorted(*list4);
//
//    std::shared_ptr<std::array<int, 32>> list5(new std::array<int, 32>{{3,4,  7,2,   2,1,   3,1,     9,22,     77,78, 45,109, 33,11234,
//                                                                        2,11, 333,1, 9,222, 77,7668, 415,1091, 2,1,   3,-1,   9,22,    }});
//    sortViaNaturalMergesort(*list5);
//    verifySorted(*list5);
//}
//
//TEST_F(NaturalMergeSortTest, descendingPresortedTest) {
//    std::shared_ptr<std::array<int, 2>> list(new std::array<int, 2>{{5,4}});
//    sortViaNaturalMergesort(*list);
//    verifySorted(*list);
//
//    std::shared_ptr<std::array<int, 4>> list2(new std::array<int, 4>{{7,6,4,2}});
//    sortViaNaturalMergesort(*list2);
//    verifySorted(*list2);
//
//    std::shared_ptr<std::array<int, 8>> list3(new std::array<int, 8>{{18,14,14,13,12,11,11,10}});
//    sortViaNaturalMergesort(*list3);
//    verifySorted(*list3);
//
//    std::shared_ptr<std::array<int, 16>> list4(new std::array<int, 16>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2}});
//    sortViaNaturalMergesort(*list4);
//    verifySorted(*list4);
//
//    std::shared_ptr<std::array<int, 32>> list5(new std::array<int, 32>{{18,14,14,13,12,11,11,10,9,9,9,9,5,4,3,2,
//                                                                        -1,-2,-4,-5,-6,-7,-22,-33,-45,-56,-66,-67,-89,-90,-122,-134}});
//    sortViaNaturalMergesort(*list5);
//    verifySorted(*list5);
//}
//
//TEST_F(NaturalMergeSortTest, oddSizeTest) {
//    std::shared_ptr<std::array<int, 3>> list(new std::array<int, 3>{{3,4, 1}});
//    sortViaNaturalMergesort(*list);
//    verifySorted(*list);
//
//    std::shared_ptr<std::array<int, 6>> list2(new std::array<int, 6>{{6,4, 7,2, 9,1}});
//    sortViaNaturalMergesort(*list2);
//    verifySorted(*list2);
//
//    std::shared_ptr<std::array<int, 9>> list3(new std::array<int, 9>{{2,1, 3,1, 9,10, 18,22, 5}});
//    sortViaNaturalMergesort(*list3);
//    verifySorted(*list3);
//
//    std::shared_ptr<std::array<int, 15>> list4(new std::array<int, 15>{{3,4, 7,2, 2,1, 3,1, 9,22, 77,51, 45,10}});
//    sortViaNaturalMergesort(*list4);
//    verifySorted(*list4);
//
//    std::shared_ptr<std::array<int, 22>> list5(new std::array<int, 22>{{3,4,    7,2,   2,1,  3,1, 9,22, 77,51, 45,10, 23,-1,
//                                                                        -33,-4, 77,12, 245,1 }});
//    sortViaNaturalMergesort(*list5);
//    verifySorted(*list5);
//
//    std::shared_ptr<std::array<int, 33>> list6(new std::array<int, 33>{{3,4,  7,2,   2,1,   3,1,     9,22,     77,78, 45,109, 33,11234,
//                                                                        2,11, 333,1, 9,222, 77,7668, 415,1091, 2,1,   3,-1,   9,22,     5}});
//    sortViaNaturalMergesort(*list6);
//    verifySorted(*list6);
//}

TEST_F(NaturalMergeSortTest, bitonicCasesTest) {
    // case 1: 2 exact bitonic runs
    std::shared_ptr<std::array<int, 16>> list(new std::array<int, 16>{{-1,-1,2,2,3 ,2,1,/**/2,4,6,7,8, 5,2,1,0}});
    sortViaNaturalMergesort(*list);
    verifySorted(*list);
    print(*list, "list: ");

//    // case 2: 2 exact bitonic runs but another asc only at the end
//    std::shared_ptr<std::array<int, 16>> list1(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/5,8}});
//    sortViaNaturalMergesort(*list1);
//    verifySorted(*list1);
//
//    // case 3: 2 exact bitonic runs but another desc only at the end
//    std::shared_ptr<std::array<int, 16>> list2(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/10,8}});
//    sortViaNaturalMergesort(*list2);
//    verifySorted(*list2);
//
//    // case 4: 3 exact bitonic runs
//    std::shared_ptr<std::array<int, 16>> list3(new std::array<int, 16>{{-1,-1,2,3, 1,/**/2,6,7,8, 1,0, /**/5,6,7, 3,1}});
//    sortViaNaturalMergesort(*list3);
//    verifySorted(*list3);
}

//TEST_F(NaturalMergeSortTest, doublesTest) {
//    std::shared_ptr<std::array<double, 2>> dList(new std::array<double, 2>{{5.3,4.4}});
//    sortViaNaturalMergesort(*dList);
//    verifySorted(*dList);
//
//    std::shared_ptr<std::array<double, 4>> dList2(new std::array<double, 4>{{6.3,4.4, 7.1,2.22}});
//    sortViaNaturalMergesort(*dList2);
//    verifySorted(*dList2);
//
//    std::shared_ptr<std::array<double, 3>> dList3(new std::array<double, 3>{{3.1,4.5, 1.1}});
//    sortViaNaturalMergesort(*dList3);
//    verifySorted(*dList3);
//
//    std::shared_ptr<std::array<double, 6>> dList4(new std::array<double, 6>{{6.1,4.4, 7.5,2.6, 9.4,1.1}});
//    sortViaNaturalMergesort(*dList4);
//    verifySorted(*dList4);
//
//    std::shared_ptr<std::array<double, 9>> dList5(new std::array<double, 9>{{2.09,1.1, 3.77,1.1, 9.1,10.67, 18.22,22.1, 5.4}});
//    sortViaNaturalMergesort(*dList5);
//    verifySorted(*dList5);
//}
//
//TEST_F(NaturalMergeSortTest, stringsTest) {
//    std::shared_ptr<std::array<std::string, 2>> dList(new std::array<std::string, 2>{{"a","65"}});
//    sortViaNaturalMergesort(*dList);
//    verifySorted(*dList);
//
//    std::shared_ptr<std::array<std::string, 4>> dList2(new std::array<std::string, 4>{{"Z","ab4", "z7","t"}});
//    sortViaNaturalMergesort(*dList2);
//    verifySorted(*dList2);
//
//    std::shared_ptr<std::array<std::string, 3>> dList3(new std::array<std::string, 3>{{"gh","HGt", "gh56"}});
//    sortViaNaturalMergesort(*dList3);
//    verifySorted(*dList3);
//
//    std::shared_ptr<std::array<std::string, 6>> dList4(new std::array<std::string, 6>{{"fhs","df2", "df","gh", "12b","dsd2"}});
//    sortViaNaturalMergesort(*dList4);
//    verifySorted(*dList4);
//
//    std::shared_ptr<std::array<std::string, 9>> dList5(new std::array<std::string, 9>{{"df4","df", "324f","df23", "91","42hall", "324ef","df22", "sdf"}});
//    sortViaNaturalMergesort(*dList5);
//    verifySorted(*dList5);
//}

