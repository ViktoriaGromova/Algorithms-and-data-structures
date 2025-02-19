#include "binary_search.hpp"

#include <gtest/gtest.h>

std::string BinarySearchOutput(int* arr, const size_t size, int target) {
    testing::internal::CaptureStdout();
    binarySearch(arr, size, target);
    return testing::internal::GetCapturedStdout();
}

TEST(BinarySearch, FindingElementsBelongingToArr) 
{
    // Arange
    const size_t size = 7; 
    int *arr = new int[size]{1, 3, 8, 9, 11, 12, 16}; 

    // Act && Assert
    for(size_t i = 0; i < size; ++i){
        std::string output = BinarySearchOutput(arr, size, arr[i]);
        EXPECT_EQ(output, "Find\n");
    }

    delete[] arr;
}

TEST(BinarySearch, FindingElementsNotBelongingToArr) 
{
    // Arange
    const size_t size = 7; 
    int *arr = new int[size]{1, 3, 8, 9, 11, 12, 16}; 
    int *target = new int[size]{99, 13, 118, 90, 14, 5, 6}; 

    // Act && Assert
    for(size_t i = 0; i < size; ++i){
        std::string output = BinarySearchOutput(arr, size, target[i]);
        EXPECT_EQ(output, "Not Find\n");
    }

    delete[] arr;
    delete[] target;
}

TEST(BinarySearch, OneElementNotBelongingToArr)
{
    // Arange
    const size_t size = 1;
    int arr[size] = {1};
    int target = 99;

    // Act && Assert
    std::string output = BinarySearchOutput(arr, size, target);
    EXPECT_EQ(output, "Not Find\n");
}

TEST(BinarySearch, ThrowsOnEmptyArray) 
{
    int *arr = nullptr;
    size_t size = 0;

    EXPECT_THROW(binarySearch(arr, size, 0), std::invalid_argument); 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}