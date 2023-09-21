#include "src/Internal/Algorithms/Utils.h"
#include <gtest/gtest.h>

TEST(UtilsTest, SwapValuesInt)
{
    int a = 0;
    int b = 5;

    Emblate::swap(a, b);

    EXPECT_EQ(a, 5);
    EXPECT_EQ(b, 0);
}

TEST(UtilsTest, SwapValuesFloat)
{
    float x = 0.0f;
    float y = 5.0f;

    Emblate::swap(x, y);

    EXPECT_FLOAT_EQ(x, 5.0f);
    EXPECT_FLOAT_EQ(y, 0.0f);
}

TEST(UtilsTest, StrCmpEqualStrings)
{
    const char* str1 = "hello";
    const char* str2 = "hello";

    bool result = Emblate::strCmp(str1, str2);

    ASSERT_TRUE(result);
}

TEST(UtilsTest, StrCmpDifferentStrings)
{
    const char* str1 = "hello";
    const char* str2 = "world";

    bool result = Emblate::strCmp(str1, str2);

    ASSERT_FALSE(result);
}

TEST(UtilsTest, StrCmpEmptyStrings)
{
    const char* str1 = "";
    const char* str2 = "";

    bool result = Emblate::strCmp(str1, str2);

    ASSERT_TRUE(result);
}

TEST(UtilsTest, StrCmpOneEmptyString)
{
    const char* str1 = "hello";
    const char* str2 = "";

    bool result = Emblate::strCmp(str1, str2);

    ASSERT_FALSE(result);
}
