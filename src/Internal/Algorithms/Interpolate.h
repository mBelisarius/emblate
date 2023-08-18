#ifndef EMBLATE_INTERPOLATE_H
#define EMBLATE_INTERPOLATE_H

#include "./Search.h"
#include "./Sort.h"
#include "../Core/Exception.h"
#include "../Data/Defines.h"
#include "../Data/Vector.h"

namespace Emblate
{
    template<typename T>
    class Interp1d
    {
    public:
        Interp1d(Vector<T> x, Vector<T> y,
                 bool check_bounds = false,
                 bool assume_sorted = false);
        T linear(T t);

    private:
        Vector<T> m_x;
        Vector<T> m_y;
        size_t m_size;
        bool m_check_bounds;
        bool m_assume_sorted;

    };

    template<typename T>
    Interp1d<T>::Interp1d(Vector<T> x, Vector<T> y,
                          bool check_bounds,
                          bool assume_sorted)
            : m_x(x), m_y(y),
              m_check_bounds(check_bounds),
              m_assume_sorted(assume_sorted)
    {
        // TODO: Exception
        if (m_x.size() != m_y.size()) { throw; }
        m_size = m_x.size();

        // TODO: Implement sorting algorithms
        if (!m_assume_sorted)
        {
            throw not_implemented();
        }
    }

    template<typename T>
    T Interp1d<T>::linear(T t)
    {
        if (t < m_x.front() || t > m_x.back()) { throw; }

        size_t i = binarySearch<T>(m_x, t, 0, m_size - 1);
        if ((i == m_size - 1) || (i != 0 && t < m_x[i])) { i--; }

        T dydx = ((m_y[i + 1] - m_y[i]) / (m_x[i + 1] - m_x[i]));
        return m_y[i] + dydx * (t - m_x[i]);
    }
}

#endif /* EMBLATE_INTERPOLATE_H */
