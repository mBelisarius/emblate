#include "src/Internal/Algorithms/Sort.h"
#include "src/Data"
#include <gtest/gtest.h>

// TODO: Test cases for float type
// TODO: Test cases for different containers
// TODO: Test cases for custom data types

TEST(HeapSortTest, SortPositives)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { 5, 4, 3, 2, 1 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { 1, 2, 3, 4, 5 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortNegatives)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { -1, -2, -3, -4, -5 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { -5, -4, -3, -2, -1 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortSigned)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { 12, -23, 20, 0, -12 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { -23, -12, 0, 12, 20 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroStart)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { 0, 4, 3, 2, 1 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { 0, 1, 2, 3, 4 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroEnd)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { 4, 3, 2, 1, 0 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { 0, 1, 2, 3, 4 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroAll)
{
    using Emblate::Vector;
    using Emblate::HeapSort;

    int unsorted_array[] = { 0, 0, 0, 0, 0 };
    Vector<int> unsorted(unsorted_array, 5);

    HeapSort<int> sorter(unsorted);
    sorter.sort();

    int sorted_array[] = { 0, 0, 0, 0, 0 };
    Vector<int> sorted(sorted_array, 5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortOneElement)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(1);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(1);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}
