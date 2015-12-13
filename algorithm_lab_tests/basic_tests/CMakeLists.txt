include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMinSearchTests
        testhelper.cpp
        minSearchTest.cpp
        )
target_link_libraries(runMinSearchTests gtest gtest_main algorithms_lab)

add_executable(runMergeTests
        testhelper.cpp
        mergeTest.cpp
        )
target_link_libraries(runMergeTests gtest gtest_main algorithms_lab)

add_executable(runPresortedDataTests
        testhelper.cpp
        presortedDataTest.cpp
        )
target_link_libraries(runPresortedDataTests gtest gtest_main algorithms_lab)

add_executable(runBitoniRunsTests
        testhelper.cpp
        bitonicRunsTest.cpp
        )
target_link_libraries(runBitoniRunsTests gtest gtest_main algorithms_lab)

add_executable(runSelectSortTests
        testhelper.cpp
        sortViaDirectSelectionTest.cpp sortViaDirectSelectionTestLT.cpp
        )
target_link_libraries(runSelectSortTests gtest gtest_main algorithms_lab)

add_executable(runInsertSortTests
        testhelper.cpp
        sortViaDirectInsertTest.cpp sortViaDirectInsertTestLT.cpp
        )
target_link_libraries(runInsertSortTests gtest gtest_main algorithms_lab)

add_executable(runNaturalMergesortTests
        testhelper.cpp
        sortViaNaturalMergeSortTest.cpp sortViaNaturalMergeSortTestLT.cpp
        )
target_link_libraries(runNaturalMergesortTests gtest gtest_main algorithms_lab)

add_executable(runBottomUpMergesortTests
        testhelper.cpp
        sortViaBottomUpMergeSortTest.cpp sortViaBottomUpMergeSortTestLT.cpp
        )
target_link_libraries(runBottomUpMergesortTests gtest gtest_main algorithms_lab)

add_executable(run3WayPartitioningQuicksortTests
        testhelper.cpp
        sortVia3WayPartitioningQuicksort.cpp sortVia3WayPartitioningQuicksortLT.cpp
        )
target_link_libraries(run3WayPartitioningQuicksortTests gtest gtest_main algorithms_lab)

add_executable(runHybrid3WayPartitioningQuicksortTests
        testhelper.cpp
        sortViaHybridQuicksortTest.cpp sortViaHybridQuicksortTestLT.cpp
        )
target_link_libraries(runHybrid3WayPartitioningQuicksortTests gtest gtest_main algorithms_lab)

add_executable(runAllTests
        testhelper.cpp
        mergeTest.cpp
        minSearchTest.cpp
        presortedDataTest.cpp
        bitonicRunsTest.cpp
        sortViaDirectSelectionTest.cpp sortViaDirectSelectionTestLT.cpp
        sortViaDirectInsertTest.cpp sortViaDirectInsertTestLT.cpp
        sortViaNaturalMergeSortTest.cpp sortViaNaturalMergeSortTestLT.cpp
        sortViaBottomUpMergeSortTest.cpp sortViaBottomUpMergeSortTestLT.cpp
        sortVia3WayPartitioningQuicksort.cpp sortVia3WayPartitioningQuicksortLT.cpp
        sortViaHybridQuicksortTest.cpp sortViaHybridQuicksortTestLT.cpp
        )
target_link_libraries(runAllTests gtest gtest_main algorithms_lab)