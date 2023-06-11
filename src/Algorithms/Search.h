#ifndef EMBLATE_SEARCH_H
#define EMBLATE_SEARCH_H

#include "Math.h"
#include "../Data/Defines.h"
#include "../Data/Vector.h"

namespace Emblate
{
    template<typename T>
    size_t
    binarySearch(const Vector<T>& x, T t, size_t lowIndex, size_t highIndex)
    {
        while (true)
        {
            if (abs<size_t>(highIndex - lowIndex) <= 1)
            {
                return abs<T>(t - x[highIndex]) > abs<T>(t - x[lowIndex])
                       ? lowIndex
                       : highIndex;
            }

            size_t midIndex = (lowIndex + highIndex) / 2;
            T mid = x[midIndex];

            if (t > mid) { lowIndex = midIndex; }
            if (t < mid) { highIndex = midIndex; }
            if (t == mid) { return midIndex; }
        }
    }
}
#endif /* EMBLATE_SEARCH_H */
