#ifndef EMBLATE_BINARYSORT_H
#define EMBLATE_BINARYSORT_H

#include "Math.h"
#include "../Data/Defines.h"
#include "../Data/Vector.h"

namespace Emblate
{
	template<typename T>
	size_t
	binarySearch(const Vector<T>& x, T t, size_t lowIndex, size_t highIndex)
	{
//		if (highIndex <= lowIndex)
//		{
//			return t > x[lowIndex] ? lowIndex + 1 : lowIndex;
//		}

		if (highIndex - lowIndex <= 1)
		{
			return abs<T>(t - x[highIndex]) > abs<T>(t - x[lowIndex])
				   ? lowIndex
				   : highIndex;
		}

		size_t midIndex = (lowIndex + highIndex) / 2;
		T mid = x[midIndex];

		if (t > mid)
		{
			return binarySearch(x, t, midIndex, highIndex);
		}

		if (t < mid)
		{
			return binarySearch(x, t, lowIndex, midIndex);
		}

		if (t == mid)
		{
			return midIndex;
		}
	}
}
#endif /* EMBLATE_BINARYSORT_H */
