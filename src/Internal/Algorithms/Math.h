#ifndef EMBLATE_MATH_H
#define EMBLATE_MATH_H

namespace Emblate
{
    /**
     * Computes the absolute value of the element.
     *
     * @tparam T The type of the elements.
     * @param val Value to compute the absolute value.
     * @return Absolute value of the element.
     */
    template<typename T>
    T abs(T val)
    {
        return val >= 0 ? val : -val;
    }

    /**
     * Computes the largest integer value not greater than _val_.
     *
     * @tparam T The type of the elements.
     * @param val Value to compute the absolute value.
     * @return Largest integer value not greater than _val_.
     */
    // TODO: Return type must be equal to T.
    template<typename T>
    inline size_t floor(T val)
    {
        return static_cast<size_t>(val);
    }

    /**
     * Computes the least integer value not less than _val_.
     *
     * @tparam T The type of the elements.
     * @param val Value to compute the absolute value.
     * @return Least integer value not less than _val_.
     */
    // TODO: Return type must be equal to T.
    template<typename T>
    inline size_t ceil(T val)
    {
        if ((val >= 0) && (val - static_cast<size_t>(val) > 0))
        {
            return static_cast<size_t>(val + 1);
        }

        return static_cast<size_t>(val);
    }

    template<typename T>
    inline T map(T val, T from_low, T from_high, T to_low, T to_high)
    {
        return (val - from_low) * (to_high - to_low) / (from_high - from_low) + to_low;
    }
}

#endif /* EMBLATE_MATH_H */
