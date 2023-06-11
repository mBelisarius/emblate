#ifndef EMBLATE_COMPARE_H
#define EMBLATE_COMPARE_H

#include "../Data/Defines.h"

namespace Emblate
{
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

#endif /* EMBLATE_COMPARE_H */
