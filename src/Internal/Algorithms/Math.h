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
        return (int)val;
    }

    template<typename T>
    inline int ceil(T val)
    {
        if (val >= 0 && val - (int)val > 0)
        {
            return (int)(val + 1);
        }

        return (int)(val);
    }

    template<typename T>
    inline T map(T val, T from_low, T from_high, T to_low, T to_high)
    {
        return (x - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
    }
}

#endif /* EMBLATE_MATH_H */
