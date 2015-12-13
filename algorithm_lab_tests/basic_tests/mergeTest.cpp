#include <array>
#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "sorters.h"
#include "testhelper.h"

class MergeTest : public testing::Test {
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

TEST_F(MergeTest, basicTest) {
    std::shared_ptr<std::array<int, 10>> tmp10(new std::array<int, 10>());
    std::shared_ptr<std::array<int, 11>> tmp11(new std::array<int, 11>());
    std::shared_ptr<std::array<double, 10>> tmp10D(new std::array<double, 10>());
    std::shared_ptr<std::array<double, 11>> tmp11D(new std::array<double, 11>());
    std::shared_ptr<std::array<std::string, 10>> tmp10S(new std::array<std::string, 10>());
    std::shared_ptr<std::array<std::string, 11>> tmp11S(new std::array<std::string, 11>());

    std::shared_ptr<std::array<int, 10>> list(new std::array<int, 10>{{3,4,5,7,12, 2,8,8,9,10}});
    merge(*list, *tmp10, 0, 5, 10, false, false);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 11>> list2(new std::array<int, 11>{{3,4,5,7,12,13, 8,8,9,10,15}});
    merge(*list2, *tmp11, 0, 6, 11, false, false);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 10>> list3(new std::array<int, 10>{{3,4,5,7,12, 13,18,19,20,22}});
    merge(*list3, *tmp10, 0, 5, 10, false, false);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 11>> list4(new std::array<int, 11>{{3,4,5,7,12,13, 17,18,19,20,22}});
    merge(*list4, *tmp11, 0, 6, 11, false, false);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 10>> list5(new std::array<int, 10>{{17,18,19,20,22, 2,4,5,7,12}});
    merge(*list5, *tmp10, 0, 5, 10, false, false);
    verifySorted(*list5);

    std::shared_ptr<std::array<int, 11>> list6(new std::array<int, 11>{{17,18,19,20,22,24, 3,4,5,7,12}});
    merge(*list6, *tmp11, 0, 6, 11, false, false);
    verifySorted(*list6);

    std::shared_ptr<std::array<double, 10>> dList(new std::array<double, 10>{{3.1,4.4,5.5,7.7,12.1, 2.1,8.8,8.8,9.5,10.1}});
    merge(*dList, *tmp10D, 0, 5, 10, false, false);
    verifySorted(*dList);

    std::shared_ptr<std::array<double, 11>> dList2(new std::array<double, 11>{{3.6,4.6,5.4,7.3,12.2,13.9, 8.8,8.99,9.12,10.1,15.45}});
    merge(*dList2, *tmp11D, 0, 6, 11, false, false);
    verifySorted(*dList2);

    std::shared_ptr<std::array<std::string, 10>> sList(new std::array<std::string, 10>{{"a","bc","e","f","y", "1","34","AA","B","g"}});
    merge(*sList, *tmp10S, 0, 5, 10, false, false);
    verifySorted(*sList);

    std::shared_ptr<std::array<std::string, 11>> sList2(new std::array<std::string, 11>{{"a","bc","e","f","y","z", "1","34","AA","B","g"}});
    merge(*sList2, *tmp11S, 0, 6, 11, false, false);
    verifySorted(*sList2);
}

TEST_F(MergeTest, smallTest) {
    std::shared_ptr<std::array<int, 0>> tmp0(new std::array<int, 0>());
    std::shared_ptr<std::array<int, 1>> tmp1(new std::array<int, 1>());
    std::shared_ptr<std::array<int, 2>> tmp2(new std::array<int, 2>());
    std::shared_ptr<std::array<int, 3>> tmp3(new std::array<int, 3>());

    std::shared_ptr<std::array<int, 0>> list0(new std::array<int, 0>);
    merge(*list0, *tmp0, 0, 0, 0, false, false);
    verifySorted(*list0);

    std::shared_ptr<std::array<int, 1>> list(new std::array<int, 1>{{3}});
    merge(*list, *tmp1, 0, 0, 1, false, false);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 2>> list1(new std::array<int, 2>{{3,4}});
    merge(*list1, *tmp2, 0, 1, 2, false, false);
    verifySorted(*list1);

    std::shared_ptr<std::array<int, 2>> list2(new std::array<int, 2>{{6,4}});
    merge(*list2, *tmp2, 0, 1, 2, false, false);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 3>> list3(new std::array<int, 3>{{6,4, 1}});
    merge(*list3, *tmp3, 0, 1, 2, false, false);
    merge(*list3, *tmp3, 2, 2, 3, false, false);
    merge(*list3, *tmp3, 0, 2, 3, false, false);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 3>> list4(new std::array<int, 3>{{6,4, 5}});
    merge(*list4, *tmp3, 0, 1, 2, false, false);
    merge(*list4, *tmp3, 2, 2, 3, false, false);
    merge(*list4, *tmp3, 0, 2, 3, false, false);
    verifySorted(*list4);
}

TEST_F(MergeTest, mixedTest) {
    std::shared_ptr<std::array<int, 4>> tmp4(new std::array<int, 4>());
    std::shared_ptr<std::array<int, 5>> tmp5(new std::array<int, 5>());
    std::shared_ptr<std::array<int, 6>> tmp6(new std::array<int, 6>());
    std::shared_ptr<std::array<int, 7>> tmp7(new std::array<int, 7>());
    std::shared_ptr<std::array<int, 8>> tmp8(new std::array<int, 8>());

    std::shared_ptr<std::array<int, 8>> list(new std::array<int, 8>{{3,4, 7,2, 2,1, 3,8}});
    merge(*list, *tmp8, 0, 1, 2, false, false);
    merge(*list, *tmp8, 2, 3, 4, false, false);
    merge(*list, *tmp8, 4, 5, 6, false, false);
    merge(*list, *tmp8, 6, 7, 8, false, false);

    merge(*list, *tmp8, 0, 2, 4, false, false);
    merge(*list, *tmp8, 4, 6, 8, false, false);

    merge(*list, *tmp8, 0, 4, 8, false, false);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 7>> list2(new std::array<int, 7>{{3,4, 7,2, 2,1, 3}});
    merge(*list2, *tmp7, 0, 1, 2, false, false);
    merge(*list2, *tmp7, 2, 3, 4, false, false);
    merge(*list2, *tmp7, 4, 5, 6, false, false);
    merge(*list2, *tmp7, 6, 6, 7, false, false);

    merge(*list2, *tmp7, 0, 2, 4, false, false);
    merge(*list2, *tmp7, 4, 6, 7, false, false);

    merge(*list2, *tmp7, 0, 4, 7, false, false);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 6>> list3(new std::array<int, 6>{{3,4, 7,2, 2,1}});
    merge(*list3, *tmp6, 0, 1, 2, false, false);
    merge(*list3, *tmp6, 2, 3, 4, false, false);
    merge(*list3, *tmp6, 4, 5, 6, false, false);

    merge(*list3, *tmp6, 0, 2, 4, false, false);
    merge(*list3, *tmp6, 4, 5, 6, false, false);

    merge(*list3, *tmp6, 0, 4, 6, false, false);
    verifySorted(*list3);

    std::shared_ptr<std::array<int, 5>> list4(new std::array<int, 5>{{3,4, 7,2, 2}});
    merge(*list4, *tmp5, 0, 1, 2, false, false);
    merge(*list4, *tmp5, 2, 3, 4, false, false);
    merge(*list4, *tmp5, 4, 4, 5, false, false);

    merge(*list4, *tmp5, 0, 2, 4, false, false);
    merge(*list4, *tmp5, 4, 4, 5, false, false);

    merge(*list4, *tmp5, 0, 4, 5, false, false);
    verifySorted(*list4);

    std::shared_ptr<std::array<int, 4>> list5(new std::array<int, 4>{{3,4, 7,2}});
    merge(*list5, *tmp4, 0, 1, 2, false, false);
    merge(*list5, *tmp4, 2, 3, 4, false, false);

    merge(*list5, *tmp4, 0, 2, 4, false, false);
    verifySorted(*list5);
}


TEST_F(MergeTest, mixedTestForNaturalMergeSort) {
    std::shared_ptr<std::array<int, 7>> tmp7(new std::array<int, 7>());
    std::shared_ptr<std::array<int, 12>> tmp12(new std::array<int, 12>());

    std::shared_ptr<std::array<int, 7>> list(new std::array<int, 7>{{-1,-1,2,2, 1,2,3}});
    merge(*list, *tmp7, 0, 4, 7, false, false);
    verifySorted(*list);

    std::shared_ptr<std::array<int, 12>> list2(new std::array<int, 12>{{-1,-1,1,2,2,2,3,/**/2,6,7, 5,7}});
    merge(*list2, *tmp12, 7, 10,12, false, false);
    merge(*list2, *tmp12, 0, 7, 12, false, false);
    verifySorted(*list2);

    std::shared_ptr<std::array<int, 12>> list3(new std::array<int, 12>{{-1,-1,2,2, 1,2,3,/**/2,6,7, 5,7}});
    merge(*list3, *tmp12, 0, 4, 7, false, false);
    merge(*list3, *tmp12, 7, 10,12, false, false);

    merge(*list3, *tmp12, 0, 7, 12, false, false);
    verifySorted(*list3);
}

TEST_F(MergeTest, basicTestForNaturalMergeSortDesc) {
    std::shared_ptr<std::array<int, 2>> tmp2(new std::array<int, 2>());
    std::shared_ptr<std::array<int, 3>> tmp3(new std::array<int, 3>());
    std::shared_ptr<std::array<int, 7>> tmp7(new std::array<int, 7>());
    std::shared_ptr<std::array<int, 12>> tmp12(new std::array<int, 12>());

    // asc stays asc
    std::shared_ptr<std::array<int, 2>> list0(new std::array<int, 2>{{2,3}});
    merge(*list0, *tmp2, 0, 2, 2, false, false);
    verifySorted(*list0);

    // desc stays desc
    std::shared_ptr<std::array<int, 2>> list1(new std::array<int, 2>{{3,2}});
    merge(*list1, *tmp2, 0, 1, 2, true, true);
    verifySortedDESC(*list1);

    // asc becomes desc
    std::shared_ptr<std::array<int, 2>> list2(new std::array<int, 2>{{2,3}});
    merge(*list2, *tmp2, 0, 2, 2, false, true);
    verifySortedDESC(*list2);

    // desc becomes asc
    std::shared_ptr<std::array<int, 2>> list4(new std::array<int, 2>{{3,2}});
    merge(*list4, *tmp2, 0, 1, 2, true, false);
    verifySorted(*list4);

}

TEST_F(MergeTest, forNaturalMergeSortBitonicCasesTest) {
    std::shared_ptr<std::array<int, 16>> tmp16(new std::array<int, 16>());

    // case 1: 2 exact bitonic runs
    std::shared_ptr<std::array<int, 16>> list(new std::array<int, 16>{{-1,-1,2,2,3 ,2,1,/**/2,4,6,7,8, 5,2,1,0}});
    merge(*list, *tmp16, 0, 5, 7, true, false);
    merge(*list, *tmp16, 7, 12,16, true, true);

    merge(*list, *tmp16, 0, 7, 16, true, false);
    verifySorted(*list);

    // case 2: 2 exact bitonic runs but another asc only at the end
    std::shared_ptr<std::array<int, 16>> list1(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/5,8}});
    merge(*list1, *tmp16, 0, 5, 7, true, false); //asc
    merge(*list1, *tmp16, 7, 12,14, true, true); // desc
    merge(*list1, *tmp16, 14, 16, 16, true, false); // asc

    merge(*list1, *tmp16, 0, 7, 14, true, false); //asc
    merge(*list1, *tmp16, 14, 16, 16, true, true); //desc

    merge(*list1, *tmp16, 0, 14, 16, true, false);
    verifySorted(*list1);

    // case 3: 2 exact bitonic runs but another desc only at the end
    std::shared_ptr<std::array<int, 16>> list2(new std::array<int, 16>{{-1,-1,2,2,3, 2,1,/**/2,4,6,7,8, 5,2,/**/10,8}});
    merge(*list2, *tmp16, 0, 5, 7, true, false); //asc
    merge(*list2, *tmp16, 7, 12,14, true, true); // desc
    merge(*list2, *tmp16, 14, 15, 16, true, false); // asc

    merge(*list2, *tmp16, 0, 7, 14, true, false); //asc
    merge(*list2, *tmp16, 14, 16, 16, true, true); //desc

    merge(*list2, *tmp16, 0, 14, 16, true, false);
    verifySorted(*list2);

    // case 4: 3 exact bitonic runs
    std::shared_ptr<std::array<int, 16>> list3(new std::array<int, 16>{{-1,-1,2,3, 1,/**/2,6,7,8, 1,0, /**/5,6,7, 3,1}});
    merge(*list3, *tmp16, 0 , 4, 5, true, false); // asc
    merge(*list3, *tmp16, 5 , 9,11, true, true); // desc
    merge(*list3, *tmp16, 11, 14, 16, true, false); // asc

    merge(*list3, *tmp16, 0 , 5,11, true, false); // asc
    merge(*list3, *tmp16, 11,16,16, true, true); // desc

    merge(*list3, *tmp16, 0 ,11,16, true, false); // asc
    verifySorted(*list3);
}


TEST_F(MergeTest, mixedDoubleTest) {
    std::shared_ptr<std::array<double, 5>> tmp5(new std::array<double, 5>());

    std::shared_ptr<std::array<double, 5>> dList(new std::array<double, 5>{{3.1,4.5, 7.1,2.2, 2.1}});
    merge(*dList, *tmp5, 0, 1, 2, false, false);
    merge(*dList, *tmp5, 2, 3, 4, false, false);
    merge(*dList, *tmp5, 4, 4, 5, false, false);

    merge(*dList, *tmp5, 0, 2, 4, false, false);
    merge(*dList, *tmp5, 4, 4, 5, false, false);

    merge(*dList, *tmp5, 0, 4, 5, false, false);
    verifySorted(*dList);
}

TEST_F(MergeTest, mixedStringTest) {
    std::shared_ptr<std::array<std::string, 5>> tmp10(new std::array<std::string, 5>());

    std::shared_ptr<std::array<std::string, 5>> dList(new std::array<std::string, 5>{{"a","11", "ZZ","1b", "5bb"}});
    merge(*dList, *tmp10, 0, 1, 2, false, false);
    merge(*dList, *tmp10, 2, 3, 4, false, false);
    merge(*dList, *tmp10, 4, 4, 5, false, false);

    merge(*dList, *tmp10, 0, 2, 4, false, false);
    merge(*dList, *tmp10, 4, 4, 5, false, false);

    merge(*dList, *tmp10, 0, 4, 5, false, false);
    verifySorted(*dList);
}