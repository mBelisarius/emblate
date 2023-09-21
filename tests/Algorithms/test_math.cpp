#include "src/Internal/Algorithms/Math.h"
#include <gtest/gtest.h>

TEST(MathTest, AbsReturnTypeInt)
{
    int x = 0;

    EXPECT_EQ(typeid(int), typeid(Emblate::abs(x)));
}

TEST(MathTest, AbsPositiveInt)
{
    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsNegativeInt)
{
    int x = -1;
    int expected = 1;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsPositiveZeroInt)
{
    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsNegativeZeroInt)
{
    int x = -0;
    int expected = 0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsReturnTypeFloat)
{
    float x = 0;

    EXPECT_EQ(typeid(float), typeid(Emblate::abs(x)));
}

TEST(MathTest, AbsPositiveFloat)
{
    float x = 1.0;
    float expected = 1.0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsNegativeFloat)
{
    float x = -1.0;
    float expected = 1.0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsPositiveZeroFloat)
{
    float x = 0.0;
    float expected = 0.0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, AbsNegativeZeroFloat)
{
    float x = -0.0;
    float expected = 0.0;

    EXPECT_EQ(expected, Emblate::abs(x));
}

TEST(MathTest, FloorReturnTypeInt)
{
    int x = 0;

    EXPECT_EQ(typeid(int), typeid(Emblate::floor(x)));
}

TEST(MathTest, FloorPositiveInt)
{
    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorNegativeInt)
{
    int x = -1;
    int expected = -1;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorPositiveZeroInt)
{
    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorNegativeZeroInt)
{
    int x = -0;
    int expected = -0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorReturnTypeFloat)
{
    float x = 0;

    EXPECT_EQ(typeid(float), typeid(Emblate::floor(x)));
}

TEST(MathTest, FloorPositiveFloat)
{
    float x = 1.9;
    float expected = 1.0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorNegativeFloat)
{
    float x = -0.1;
    float expected = -1.0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorPositiveZeroFloat)
{
    float x = 0.0;
    float expected = 0.0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, FloorNegativeZeroFloat)
{
    float x = -0.0;
    float expected = -0.0;

    EXPECT_EQ(expected, Emblate::floor(x));
}

TEST(MathTest, CeilReturnTypeInt)
{
    int x = 0;

    EXPECT_EQ(typeid(int), typeid(Emblate::ceil(x)));
}

TEST(MathTest, CeilPositiveInt)
{
    int x = 1;
    int expected = 1;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilNegativeInt)
{
    int x = -1;
    int expected = -1;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilPositiveZeroInt)
{
    int x = 0;
    int expected = 0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilNegativeZeroInt)
{
    int x = -0;
    int expected = -0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilReturnTypeFloat)
{
    float x = 0;

    EXPECT_EQ(typeid(float), typeid(Emblate::ceil(x)));
}

TEST(MathTest, CeilPositiveFloat)
{
    float x = 0.1;
    float expected = 1.0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilNegativeFloat)
{
    float x = -1.9;
    float expected = -1.0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilPositiveZeroFloat)
{
    float x = 0.0;
    float expected = 0.0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, CeilNegativeZeroFloat)
{
    float x = -0.0;
    float expected = -0.0;

    EXPECT_EQ(expected, Emblate::ceil(x));
}

TEST(MathTest, MapReturnTypeInt)
{
    EXPECT_EQ(typeid(int), typeid(Emblate::map<int>(5, 0, 10, 0, 100)));
}

TEST(MathTest, MapValuesInt)
{
    EXPECT_EQ(50, Emblate::map<int>(5, 0, 10, 0, 100));

    EXPECT_EQ(50, Emblate::map<int>(0, -10, 10, 0, 100));

    EXPECT_EQ(25, Emblate::map<int>(-5, -10, 10, 0, 100));
}

TEST(MathTest, MapReturnTypeFloat)
{
    EXPECT_EQ(typeid(float), typeid(Emblate::map<float>(5.0, 0.0, 10.0, 0.0, 100.0)));
}

TEST(MathTest, MapValuesFloat)
{
    EXPECT_EQ(50, Emblate::map<float>(5.0, 0.0, 10.0, 0.0, 100.0));

    EXPECT_EQ(50, Emblate::map<float>(0.0, -10.0, 10.0, 0.0, 100.0));

    EXPECT_EQ(25, Emblate::map<float>(-5.0, -10.0, 10.0, 0.0, 100.0));
}
