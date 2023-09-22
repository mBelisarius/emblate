#include "src/Data"
#include "src/Algorithms"
#include <gtest/gtest.h>

TEST(HeapSortTest, SortPositives)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(5);
    unsorted.push_back(4);
    unsorted.push_back(3);
    unsorted.push_back(2);
    unsorted.push_back(1);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);
    sorted.push_back(5);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortNegatives)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(-1);
    unsorted.push_back(-2);
    unsorted.push_back(-3);
    unsorted.push_back(-4);
    unsorted.push_back(-5);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(-5);
    sorted.push_back(-4);
    sorted.push_back(-3);
    sorted.push_back(-2);
    sorted.push_back(-1);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortSigned)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(12);
    unsorted.push_back(-23);
    unsorted.push_back(20);
    unsorted.push_back(0);
    unsorted.push_back(-12);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(-23);
    sorted.push_back(-12);
    sorted.push_back(0);
    sorted.push_back(12);
    sorted.push_back(20);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroStart)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(0);
    unsorted.push_back(4);
    unsorted.push_back(3);
    unsorted.push_back(2);
    unsorted.push_back(1);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(0);
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroEnd)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(4);
    unsorted.push_back(3);
    unsorted.push_back(2);
    unsorted.push_back(1);
    unsorted.push_back(0);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(0);
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);

    for (int i = 0; i < unsorted.size(); i++)
    {
        EXPECT_EQ(unsorted[i], sorted[i]);
    }
}

TEST(HeapSortTest, SortZeroAll)
{
    Emblate::Vector<int> unsorted;
    unsorted.push_back(0);
    unsorted.push_back(0);
    unsorted.push_back(0);
    unsorted.push_back(0);
    unsorted.push_back(0);

    Emblate::HeapSort<int> sorter(unsorted);
    sorter.sort();

    Emblate::Vector<int> sorted;
    sorted.push_back(0);
    sorted.push_back(0);
    sorted.push_back(0);
    sorted.push_back(0);
    sorted.push_back(0);

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