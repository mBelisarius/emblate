#ifndef EMBLATE_INTERPOLATE_H
#define EMBLATE_INTERPOLATE_H

#include "Search.h"
#include "../Data/Defines.h"
#include "../Data/Vector.h"

namespace Emblate
{
    template<typename T>
    class Interp1d
    {
    public:
        /*--- Constructors ---*/
        Interp1d(const Vector<T>& x, const Vector<T>& y,
                 bool checkBounds = false, bool assumeSorted = false);

        /*--- Methods ---*/
        T linear(T t);

    private:
        Vector<T> _x;
        Vector<T> _y;
        size_t _size;
        bool _checkBounds;
        bool _assumeSorted;

    };

    template<typename T>
    Interp1d<T>::Interp1d(const Vector<T>& x, const Vector<T>& y,
                          bool checkBounds, bool assumeSorted)
            : _x(x), _y(y), _checkBounds(checkBounds),
              _assumeSorted(assumeSorted)
    {
        if (_x.size() != _y.size()) { throw; }
        _size = _x.size();

        // TODO: Implement sorting algorithms
        if (!_assumeSorted)
        {
            throw;
        }
    }

    template<typename T>
    T Interp1d<T>::linear(T t)
    {
        if (t < _x.front() || t > _x.back()) { throw; }

        size_t i = binarySearch<T>(_x, t, 0, _size - 1);
        if ((i == _size - 1) || (i != 0 && t < _x[i])) { i--; }

        T dydx = ((_y[i + 1] - _y[i]) / (_x[i + 1] - _x[i]));
        return _y[i] + dydx * (t - _x[i]);
    }
}

#endif /* EMBLATE_INTERPOLATE_H */
