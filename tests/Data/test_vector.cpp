#include "src/Internal/Data/Vector.h"
#include <gtest/gtest.h>

TEST(VectorTest, DefaultConstructor)
{
    using Emblate::Vector;

    Vector<int> vector;

    EXPECT_EQ(vector.size(), 0);
    EXPECT_EQ(vector.capacity(), 0);
    EXPECT_TRUE(vector.empty());
}

TEST(VectorTest, SizeInitializedConstructor)
{
    using Emblate::Vector;

    Vector<int> vector(5);

    EXPECT_EQ(vector.size(), 5);
    EXPECT_EQ(vector.capacity(), 5);
    EXPECT_FALSE(vector.empty());

    for (size_t i = 0; i < 5; i++)
    {
        EXPECT_EQ(vector.at(i), int());
    }
}

TEST(VectorTest, ValueInitializedConstructor)
{
    using Emblate::Vector;

    Vector<int> vector(5, 1);

    EXPECT_EQ(vector.size(), 5);
    EXPECT_EQ(vector.capacity(), 5);
    EXPECT_FALSE(vector.empty());

    for (size_t i = 0; i < 5; i++)
    {
        EXPECT_EQ(vector.at(i), 1);
    }
}

TEST(VectorTest, ArrayInitializedConstructor)
{
    using Emblate::Vector;

    int arr[5] = { 1, 2, 3, 4, 5 };
    Vector<int> vector(arr, 5);

    EXPECT_EQ(vector.size(), 5);
    EXPECT_EQ(vector.capacity(), 5);
    EXPECT_FALSE(vector.empty());

    for (size_t i = 0; i < 5; i++)
    {
        EXPECT_EQ(vector.at(i), arr[i]);
    }
}

TEST(VectorTest, CopyConstructor)
{
    using Emblate::Vector;

    Vector<int> vector1(5, 1);
    Vector<int> vector2(vector1);

    EXPECT_EQ(vector2.size(), 5);
    EXPECT_EQ(vector2.capacity(), 5);
    EXPECT_FALSE(vector2.empty());

    for (size_t i = 0; i < 5; i++)
    {
        EXPECT_EQ(vector2.at(i), 1);
    }
}

TEST(VectorTest, At)
{
    using Emblate::Vector;
    using Emblate::out_of_range;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector.at(0), 1);
    EXPECT_EQ(vector.at(1), 2);
    EXPECT_THROW(vector.at(2), out_of_range);
}

TEST(VectorTest, AtOperator)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector[0], 1);
    EXPECT_EQ(vector[1], 2);
    EXPECT_EQ(vector[2], 1);
}

TEST(VectorTest, Front)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector.front(), 1);
}

TEST(VectorTest, Back)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector.back(), 2);
}

TEST(VectorTest, Data)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector.data()[0], 1);
    EXPECT_EQ(vector.data()[1], 2);
}

TEST(VectorTest, Clear)
{
    using Emblate::Vector;

    Vector<int> vector(5, 1);
    vector.clear();

    EXPECT_EQ(vector.size(), 0);
    EXPECT_TRUE(vector.empty());
}

TEST(VectorTest, PushBack)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    EXPECT_EQ(vector.size(), 2);
    EXPECT_EQ(vector.front(), 1);
    EXPECT_EQ(vector.back(), 2);
}

TEST(VectorTest, PopBack)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);

    int last = vector.pop_back();

    EXPECT_EQ(last, 2);
    EXPECT_EQ(vector.size(), 1);
    EXPECT_EQ(vector.back(), 1);
}

TEST(VectorTest, Swap)
{
    using Emblate::Vector;

    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    vector.swap(0, 2);

    EXPECT_EQ(vector.front(), 3);
    EXPECT_EQ(vector.back(), 1);
}
