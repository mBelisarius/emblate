#ifndef EMBLATE_MATH_H
#define EMBLATE_MATH_H

namespace Emblate
{
    template<typename T>
    T abs(T val)
    {
        return val >= 0 ? val : -val;
    }
}

#endif /* EMBLATE_MATH_H */
