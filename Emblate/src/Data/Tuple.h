#ifndef EMBLATE_TUPLE_H
#define EMBLATE_TUPLE_H

#include "Defines.h"
#include "Exception.h"

namespace Emblate
{
    template<typename T>
    class Tuple
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        Tuple();

        Tuple(size_t size);
        Tuple(size_t size, const T& value);
        Tuple(const T* array, size_t size);

        // Copy constructor
        Tuple(const Tuple& tuple_);

        // Copy Assingment
        Tuple<T>& operator=(const Tuple<T>& tuple_);

        // Destructor
        ~Tuple();

        /*--- Memory ---*/
        // Returns True if this vector is empty
        bool empty() const;

        // Return the size (number of elements)
        size_t size();

        /*--- Data acess ---*/
        // Access elements with bounds checking
        T& at(size_t i);
        const T& at(size_t i) const;

        // Access elements (no bounds checking)
        T& operator[](size_t i);
        const T& operator[](size_t i) const;

        // Returns a pointer to the array used by this vector
        T* data();
        const T* data() const;

        /*--- Modifiers ---*/
        // Removes all elements
        // Size is not changed
        void clear();

    private:
        // Pointer to first element
        T* _data;

        // Number of elements ( = capacity)
        size_t _size;
    };

    template<typename T>
    Tuple<T>::Tuple()
            : _data(0), _size(0)
    {
    }

    template<typename T>
    Tuple<T>::Tuple(size_t size)
            : _data(new T[size]), _size(size)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = T();
        }
    }

    template<typename T>
    Tuple<T>::Tuple(size_t size, const T& value)
            : _data(new T[size]), _size(size)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = value;
        }
    }

    template<typename T>
    Tuple<T>::Tuple(const T* array, size_t size)
            : _data(new T[size]), _size(size)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = array[i];
        }
    }

    template<class T>
    Tuple<T>::Tuple(const Tuple<T>& tuple_)
            : _data(new T[tuple_._size]), _size(tuple_._size)
    {
        for (size_t i = 0; i < tuple_._size; i++)
        {
            _data[i] = tuple_._data[i];
        }
    }

    template<typename T>
    Tuple<T>& Tuple<T>::operator=(const Tuple<T>& tuple_)
    {
        // Self-assignment
        if (this == &tuple_) return *this;

        // Memory reallocation
        if (tuple_._size != _size)
        {
            delete[] _data;
            _data = new T[tuple_._size];
            _size = tuple_._size;
        }

        // Copy assignment
        for (size_t i = 0; i < tuple_._size; i++)
        {
            _data[i] = tuple_._data[i];
        }

        return *this;
    }

    template<typename T>
    Tuple<T>::~Tuple()
    {
        delete[] _data;
    }

    template<class T>
    bool Tuple<T>::empty() const
    {
        return (_size == 0);
    }

    template<typename T>
    size_t Tuple<T>::size()
    {
        return _size;
    }

    template<class T>
    T& Tuple<T>::at(size_t i)
    {
        if (i >= _size) throw out_of_range();
        return _data[i];
    }

    template<class T>
    const T& Tuple<T>::at(size_t i) const
    {
        if (i >= _size) throw out_of_range();
        return _data[i];
    }

    template<class T>
    T& Tuple<T>::operator[](size_t i)
    {
        return _data[i % _size];
    }

    template<class T>
    const T& Tuple<T>::operator[](size_t i) const
    {
        return _data[i % _size];
    }

    template<class T>
    T* Tuple<T>::data()
    {
        return _data;
    }

    template<class T>
    const T* Tuple<T>::data() const
    {
        return _data;
    }

    template<typename T>
    void Tuple<T>::clear()
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = T();
        }
    }
}

#endif /* EMBLATE_TUPLE_H */
