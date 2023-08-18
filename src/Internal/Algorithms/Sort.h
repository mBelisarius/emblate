#ifndef EMBLATE_SORT_H
#define EMBLATE_SORT_H

#include "./Math.h"
#include "./Utils.h"
#include "../Data/Vector.h"

namespace Emblate
{
    template<typename T>
    class HeapSort
    {
    public:
        explicit HeapSort(Vector<T>& a);
        size_t iParent(size_t i);
        size_t iLeftChild(size_t i);
        size_t iRightChild(size_t i);
        size_t leafSearch(size_t start, size_t end);
        void siftDown(size_t start, size_t end);
        void heapify();
        void sort();

    private:
        Vector<T>& m_a;
    };

    template<typename T>
    HeapSort<T>::HeapSort(Vector<T>& a)
            : m_a(a)
    {
    }

    template<typename T>
    inline size_t HeapSort<T>::iParent(size_t i)
    {
        return floor((i - 1) / 2);
    }

    template<typename T>
    inline size_t HeapSort<T>::iLeftChild(size_t i)
    {
        return 2 * i + 1;
    }

    template<typename T>
    inline size_t HeapSort<T>::iRightChild(size_t i)
    {
        return 2 * i + 2;
    }

    template<typename T>
    inline size_t HeapSort<T>::leafSearch(size_t start, size_t end)
    {
        size_t j = start;
        while (iRightChild(j) <= end)
        {
            if (m_a[iRightChild(j)] > m_a[iLeftChild(j)])
            {
                j = iRightChild(j);
            }
            else
            {
                j = iLeftChild(j);
            }
        }

        if (iLeftChild(j) <= end) { j = iLeftChild(j); }

        return j;
    }

    template<typename T>
    void HeapSort<T>::siftDown(size_t start, size_t end)
    {
        size_t j = leafSearch(start, end);

        while (m_a[start] > m_a[j]) { j = iParent(j); }

        T tmp = m_a[j];
        m_a[j] = m_a[start];
        while (j > start)
        {
            swap(m_a[iParent(j)], tmp);
            j = iParent(j);
        }
    }

    template<typename T>
    void HeapSort<T>::heapify()
    {
        for (size_t start = m_a.size(); start > 0; start--)
        {
            siftDown(start - 1, m_a.size() - 1);
        }
    }

    template<typename T>
    void HeapSort<T>::sort()
    {
        heapify();

        for (size_t end = m_a.size() - 1; end > 0; end--)
        {
            m_a.swap(end, 0);
            siftDown(0, end - 1);
        }
    }
}

#endif /* EMBLATE_SORT_H */
