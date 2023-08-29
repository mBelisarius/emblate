#ifndef EMBLATE_MATH_H
#define EMBLATE_MATH_H

namespace Emblate
{
    /**
     * Computes the absolute value of the element.
     *
     * @tparam T The type of the elements.
     * @param elem Element to compute the absolute value.
     * @return Absolute value of the element.
     */
    template<typename T>
    T abs(T elem)
    {
        return elem >= 0 ? elem : -elem;
    }

    // TODO: Fix
    // TODO: Documentation
    template<typename T>
    inline int floor(T val)
    {
        return static_cast<int>(val);
    }

    // TODO: Fix
    // TODO: Documentation
    template<typename T>
    inline int ceil(T val)
    {
        if ((val >= 0) && (val - static_cast<int>(val) > 0))
        {
            return static_cast<int>(val + 1);
        }

        return static_cast<int>(val);
    }
}

#endif /* EMBLATE_MATH_H */
