#ifndef EMBLATE_SEARCH_H
#define EMBLATE_SEARCH_H

#include "./Math.h"
#include "../Data/Defines.h"
#include "../Data/Vector.h"

namespace Emblate
{
    template<typename T>
    size_t binarySearch(const Vector<T>& x, T t,
                        size_t low_index, size_t high_index)
    {
        while (true)
        {
            if (abs<size_t>(high_index - low_index) <= 1)
            {
                return abs<T>(t - x[high_index]) > abs<T>(t - x[low_index])
                       ? low_index
                       : high_index;
            }

            size_t mid_index = (low_index + high_index) / 2;
            T mid = x[mid_index];

            if (t > mid) { low_index = mid_index; }
            if (t < mid) { high_index = mid_index; }
            if (t == mid) { return mid_index; }
        }
    }
}

#endif /* EMBLATE_SEARCH_H */
