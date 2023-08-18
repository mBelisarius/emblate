#ifndef EMBLATE_MATH_H
#define EMBLATE_MATH_H

namespace Emblate
{
    template<typename T>
    T abs(T val)
    {
        return val >= 0 ? val : -val;
    }

    template<typename T>
    inline int floor(T val)
    {
        return static_cast<int>(val);
    }

    template<typename T>
    inline int ceil(T val)
    {
        if ((val >= 0) && (val - (int)val > 0))
        {
            return static_cast<int>(val + 1);
        }

        return static_cast<int>(val);
    }
}

#endif /* EMBLATE_MATH_H */
