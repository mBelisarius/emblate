#include "src/Internal/Algorithms/Search.h"
#include "src/Data"
#include <gtest/gtest.h>

int sortedArrayInt[] = { -5, -4, -3, -2, -1, 0, 2, 3, 4, 5};
Emblate::Vector<int> sortedVectorInt(sortedArrayInt, 10);

TEST(SearchTest, BinarySearchFoundElementInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, 0, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 5);
}

TEST(SearchTest, BinarySearchLowerBoundInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, -5, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 0);
}

TEST(SearchTest, BinarySearchUpperBoundInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, 5, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 9);
}

TEST(SearchTest, BinarySearchElementNotInArrayLowerInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, -6, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 0);
}

TEST(SearchTest, BinarySearchElementNotInArrayUpperInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, 6, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 9);
}

TEST(SearchTest, BinarySearchElementNotInArrayMiddleInt)
{
    size_t result = Emblate::binarySearch(sortedVectorInt, 1, 0, sortedVectorInt.size() - 1);
    EXPECT_EQ(result, 5);
}

TEST(SearchTest, BinarySearchEmptyArrayInt)
{
    Emblate::Vector<int> emptyVector;
    EXPECT_THROW(Emblate::binarySearch(emptyVector, 0, 0, emptyVector.size() - 1),
                 Emblate::domain_error);
}

float sortedArrayFloat[] = { -5.5f, -4.4f, -3.3f, -2.2f, -1.1f, 0.0f, 2.2f, 3.3f, 4.4f, 5.5f};
Emblate::Vector<float> sortedVectorFloat(sortedArrayFloat, 10);

TEST(SearchTest, BinarySearchFoundElementFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, 0.0f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 5);
}

TEST(SearchTest, BinarySearchLowerBoundFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, -5.5f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 0);
}

TEST(SearchTest, BinarySearchUpperBoundFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, 5.5f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 9);
}

TEST(SearchTest, BinarySearchElementNotInArrayLowerFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, -6.6f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 0);
}

TEST(SearchTest, BinarySearchElementNotInArrayUpperFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, 6.6f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 9);
}

TEST(SearchTest, BinarySearchElementNotInArrayMiddleFloat)
{
    size_t result = Emblate::binarySearch(sortedVectorFloat, 1.1f, 0, sortedVectorFloat.size() - 1);
    EXPECT_EQ(result, 5);
}

TEST(SearchTest, BinarySearchEmptyArrayFloat)
{
    Emblate::Vector<float> emptyVector;
    EXPECT_THROW(Emblate::binarySearch(emptyVector, 0.0f, 0, emptyVector.size() - 1),
                 Emblate::domain_error);
}
