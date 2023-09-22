#include "src/Internal/Algorithms/Math.h"
#include <gtest/gtest.h>

TEST(MathTest, AbsReturnTypeInt)
{
    using Emblate::abs;

    int x = 0;

    EXPECT_EQ(typeid(int), typeid(abs(x)));
}

TEST(MathTest, AbsPositiveInt)
{
    using Emblate::abs;

    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, abs(x));
}

TEST(MathTest, AbsNegativeInt)
{
    using Emblate::abs;

    int x = -1;
    int expected = 1;

    EXPECT_EQ(expected, abs(x));
}

TEST(MathTest, AbsPositiveZeroInt)
{
    using Emblate::abs;

    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, abs(x));
}

TEST(MathTest, AbsNegativeZeroInt)
{
    using Emblate::abs;

    int x = -0;
    int expected = 0;

    EXPECT_EQ(expected, abs(x));
}

TEST(MathTest, AbsReturnTypeFloat)
{
    using Emblate::abs;

    float x = 0.0f;

    EXPECT_EQ(typeid(float), typeid(abs(x)));
}

TEST(MathTest, AbsPositiveFloat)
{
    using Emblate::abs;

    float x = 1.0f;
    float expected = 1.0f;

    EXPECT_FLOAT_EQ(expected, abs(x));
}

TEST(MathTest, AbsNegativeFloat)
{
    using Emblate::abs;

    float x = -1.0f;
    float expected = 1.0f;

    EXPECT_FLOAT_EQ(expected, abs(x));
}

TEST(MathTest, AbsPositiveZeroFloat)
{
    using Emblate::abs;

    float x = 0.0f;
    float expected = 0.0f;

    EXPECT_FLOAT_EQ(expected, abs(x));
}

TEST(MathTest, AbsNegativeZeroFloat)
{
    using Emblate::abs;

    float x = -0.0f;
    float expected = 0.0f;

    EXPECT_FLOAT_EQ(expected, abs(x));
}

TEST(MathTest, FloorReturnTypeInt)
{
    using Emblate::floor;

    int x = 0;

    EXPECT_EQ(typeid(int), typeid(floor(x)));
}

TEST(MathTest, FloorPositiveInt)
{
    using Emblate::floor;

    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, floor(x));
}

TEST(MathTest, FloorNegativeInt)
{
    using Emblate::floor;

    int x = -1;
    int expected = -1;

    EXPECT_EQ(expected, floor(x));
}

TEST(MathTest, FloorPositiveZeroInt)
{
    using Emblate::floor;

    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, floor(x));
}

TEST(MathTest, FloorNegativeZeroInt)
{
    using Emblate::floor;

    int x = -0;
    int expected = -0;

    EXPECT_EQ(expected, floor(x));
}

TEST(MathTest, FloorReturnTypeFloat)
{
    using Emblate::floor;

    float x = 0;

    EXPECT_EQ(typeid(float), typeid(floor(x)));
}

TEST(MathTest, FloorPositiveFloat)
{
    using Emblate::floor;

    float x = 1.9f;
    float expected = 1.0f;

    EXPECT_FLOAT_EQ(expected, floor(x));
}

TEST(MathTest, FloorNegativeFloat)
{
    using Emblate::floor;

    float x = -0.1f;
    float expected = -1.0f;

    EXPECT_FLOAT_EQ(expected, floor(x));
}

TEST(MathTest, FloorPositiveZeroFloat)
{
    using Emblate::floor;

    float x = 0.0f;
    float expected = 0.0f;

    EXPECT_FLOAT_EQ(expected, floor(x));
}

TEST(MathTest, FloorNegativeZeroFloat)
{
    using Emblate::floor;

    float x = -0.0f;
    float expected = -0.0f;

    EXPECT_FLOAT_EQ(expected, floor(x));
}

TEST(MathTest, CeilReturnTypeInt)
{
    using Emblate::ceil;

    int x = 0;

    EXPECT_EQ(typeid(int), typeid(ceil(x)));
}

TEST(MathTest, CeilPositiveInt)
{
    using Emblate::ceil;

    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilNegativeInt)
{
    using Emblate::ceil;

    int x = -1;
    int expected = -1;

    EXPECT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilPositiveZeroInt)
{
    using Emblate::ceil;

    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilNegativeZeroInt)
{
    using Emblate::ceil;

    int x = -0;
    int expected = -0;

    EXPECT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilReturnTypeFloat)
{
    using Emblate::ceil;

    float x = 0;

    EXPECT_EQ(typeid(float), typeid(ceil(x)));
}

TEST(MathTest, CeilPositiveFloat)
{
    using Emblate::ceil;

    float x = 0.1f;
    float expected = 1.0f;

    EXPECT_FLOAT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilNegativeFloat)
{
    using Emblate::ceil;

    float x = -1.9f;
    float expected = -1.0f;

    EXPECT_FLOAT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilPositiveZeroFloat)
{
    using Emblate::ceil;

    float x = 0.0f;
    float expected = 0.0f;

    EXPECT_FLOAT_EQ(expected, ceil(x));
}

TEST(MathTest, CeilNegativeZeroFloat)
{
    using Emblate::ceil;

    float x = -0.0f;
    float expected = -0.0f;

    EXPECT_FLOAT_EQ(expected, ceil(x));
}

TEST(MathTest, MapReturnTypeInt)
{
    using Emblate::map;

    EXPECT_EQ(typeid(int), typeid(map<int>(5, 0, 10, 0, 100)));
}

TEST(MathTest, MapValuesInt)
{
    using Emblate::map;

    EXPECT_EQ(50, map<int>(5, 0, 10, 0, 100));

    EXPECT_EQ(50, map<int>(0, -10, 10, 0, 100));

    EXPECT_EQ(25, map<int>(-5, -10, 10, 0, 100));
}

TEST(MathTest, MapReturnTypeFloat)
{
    using Emblate::map;

    EXPECT_EQ(typeid(float),
              typeid(map<float>(5.0f, 0.0f, 10.0f, 0.0f, 100.0f)));
}

TEST(MathTest, MapValuesFloat)
{
    using Emblate::map;

    EXPECT_FLOAT_EQ(50, map<float>(5.0f, 0.0f, 10.0f, 0.0f, 100.0f));

    EXPECT_FLOAT_EQ(50, map<float>(0.0f, -10.0f, 10.0f, 0.0f, 100.0f));

    EXPECT_FLOAT_EQ(25, map<float>(-5.0f, -10.0f, 10.0f, 0.0f, 100.0f));
}
