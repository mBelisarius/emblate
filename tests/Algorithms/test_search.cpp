#include "src/Internal/Algorithms/Search.h"
#include "src/Data"
#include <gtest/gtest.h>

int sortedArrayInt[] = { -5, -4, -3, -2, -1, 0, 2, 3, 4, 5 };
Emblate::Vector<int> sortedVectorInt(sortedArrayInt, 10);

TEST(SearchTest, BinarySearchFoundElementInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, 0,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 5;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchLowerBoundInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, -5,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 0;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchUpperBoundInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, 5,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 9;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayLowerInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, -6,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 0;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayUpperInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, 6,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 9;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayMiddleInt)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorInt, 1,
                               0, sortedVectorInt.size() - 1);
    size_t expected = 5;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchEmptyArrayInt)
{
    using Emblate::Vector;
    using Emblate::binarySearch;
    using Emblate::domain_error;

    Vector<int> emptyVector;

    EXPECT_THROW(binarySearch(emptyVector, 0, 0, emptyVector.size() - 1),
                 domain_error);
}

float sortedArrayFloat[] = { -5.5f, -4.4f, -3.3f, -2.2f, -1.1f, 0.0f, 2.2f,
                             3.3f, 4.4f, 5.5f };
Emblate::Vector<float> sortedVectorFloat(sortedArrayFloat, 10);

TEST(SearchTest, BinarySearchFoundElementFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, 0.0f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 5;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchLowerBoundFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, -5.5f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 0;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchUpperBoundFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, 5.5f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 9;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayLowerFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, -6.6f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 0;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayUpperFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, 6.6f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 9;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchElementNotInArrayMiddleFloat)
{
    using Emblate::binarySearch;

    auto result = binarySearch(sortedVectorFloat, 1.1f,
                               0, sortedVectorFloat.size() - 1);
    size_t expected = 5;

    EXPECT_EQ(result, expected);
}

TEST(SearchTest, BinarySearchEmptyArrayFloat)
{
    using Emblate::Vector;
    using Emblate::binarySearch;
    using Emblate::domain_error;

    Vector<float> emptyVector;
    EXPECT_THROW(binarySearch(emptyVector, 0.0f, 0, emptyVector.size() - 1),
                 domain_error);
}
