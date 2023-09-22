#include "src/Internal/Algorithms/Utils.h"
#include <gtest/gtest.h>

TEST(UtilsTest, SwapValuesInt)
{
    using Emblate::swap;

    int a = 0;
    int b = 5;

    swap(a, b);

    EXPECT_EQ(a, 5);
    EXPECT_EQ(b, 0);
}

TEST(UtilsTest, SwapValuesFloat)
{
    using Emblate::swap;

    float x = 0.0f;
    float y = 5.0f;

    swap(x, y);

    EXPECT_FLOAT_EQ(x, 5.0f);
    EXPECT_FLOAT_EQ(y, 0.0f);
}

TEST(UtilsTest, StrCmpEqualStrings)
{
    using Emblate::strCmp;

    const char* str1 = "hello";
    const char* str2 = "hello";

    bool result = strCmp(str1, str2);

    EXPECT_TRUE(result);
}

TEST(UtilsTest, StrCmpDifferentStrings)
{
    using Emblate::strCmp;

    const char* str1 = "hello";
    const char* str2 = "world";

    bool result = strCmp(str1, str2);

    EXPECT_FALSE(result);
}

TEST(UtilsTest, StrCmpEmptyStrings)
{
    using Emblate::strCmp;

    const char* str1 = "";
    const char* str2 = "";

    bool result = strCmp(str1, str2);

    EXPECT_TRUE(result);
}

TEST(UtilsTest, StrCmpOneEmptyString)
{
    using Emblate::strCmp;

    const char* str1 = "hello";
    const char* str2 = "";

    bool result = strCmp(str1, str2);

    EXPECT_FALSE(result);
}
