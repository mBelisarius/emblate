#ifndef EMBLATE_UTILS_H
#define EMBLATE_UTILS_H

#include "../Data/Defines.h"

namespace Emblate
{
    template<typename T>
    void swap(T& val1, T& val2)
    {
        val1 += val2;
        val2 = val1 - val2;
        val1 -= val2;
    }

    bool strCmp(const char* str1, const char* str2)
    {
        while (*str1 && (*str1 == *str2))
        {
            str1++;
            str2++;
        }

        return *(const unsigned char*)str1 == *(const unsigned char*)str2;
    }
}

#endif /* EMBLATE_UTILS_H */
