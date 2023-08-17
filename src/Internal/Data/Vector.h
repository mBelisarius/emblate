#ifndef EMBLATE_VECTOR_H
#define EMBLATE_VECTOR_H

#include "./Defines.h"
#include "../Core/Exception.h"

namespace Emblate
{
    template<typename T>
    class Vector
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        Vector();

        Vector(size_t size);
        Vector(size_t size, const T& value);
        Vector(const T* array, size_t size);

        // Copy constructor
        Vector(const Vector& vector_);

        // Copy Assingment
        Vector<T>& operator=(const Vector<T>& vector_);

        // Destructor
        ~Vector();

        /*--- Memory ---*/
        // Requests an increase in capacity
        void reserve(size_t capacity);

        // Reduces capacity to fit the size
        void shrink_to_fit();

        // Returns True if this vector is empty
        bool empty() const;

        // Return the size (number of elements)
        size_t size();

        // Return the total capacity (allocated memory)
        size_t capacity();

        /*--- Data acess ---*/
        // Access elements with bounds checking
        T& at(size_t i);
        const T& at(size_t i) const;

        // Access elements (no bounds checking)
        T& operator[](size_t i);
        const T& operator[](size_t i) const;

        // Returns a reference to the first element
        T& front();
        const T& front() const;

        // Returns a reference to the last element
        T& back();
        const T& back() const;

        // Returns a pointer to the array used by this vector
        T* data();
        const T* data() const;

        /*--- Modifiers ---*/
        // Removes all elements
        // Capacity is not changed
        void clear();

        // Inserts element at the back
        void push_back(T value);

        // Removes the last (back) element
        T pop_back();

        // Swap two elements
        void swap(size_t i, size_t j);

    private:
        // Pointer to first element
        T* _data;

        // Number of elements (used capacity)
        size_t _size;

        // Total size (capacity)
        size_t _capacity;
    };

    template<typename T>
    Vector<T>::Vector()
            : _data(0), _size(0), _capacity(0)
    {
    }

    template<typename T>
    Vector<T>::Vector(size_t size)
            : _data(new T[size]), _size(size), _capacity(size)
    {
        for (size_t i = 0; i < _capacity; i++)
        {
            _data[i] = T();
        }
    }

    template<typename T>
    Vector<T>::Vector(size_t size, const T& value)
            : _data(new T[size]), _size(size), _capacity(size)
    {
        for (size_t i = 0; i < _capacity; i++)
        {
            _data[i] = value;
        }
    }

    template<typename T>
    Vector<T>::Vector(const T* array, size_t size)
            : _data(new T[size]), _size(size), _capacity(size)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = array[i];
        }
    }

    template<class T>
    Vector<T>::Vector(const Vector<T>& vector_)
            : _data(new T[vector_._size]), _size(vector_._size),
              _capacity(vector_._size)
    {
        for (size_t i = 0; i < vector_._size; i++)
        {
            _data[i] = vector_._data[i];
        }
    }

    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& vector_)
    {
        // Self-assignment
        if (this == &vector_) return *this;

        // Memory reallocation
        if (vector_._size > _capacity)
        {
            delete _data;
            _data = new T[vector_._size];
            _capacity = vector_._size;
        }

        // Copy assignment
        _size = vector_._size;

        for (size_t i = 0; i < vector_._size; i++)
        {
            _data[i] = vector_._data[i];
        }

        return *this;
    }

    template<typename T>
    Vector<T>::~Vector()
    {
        delete[] _data;
    }

    template<class T>
    void Vector<T>::reserve(size_t capacity)
    {
        // This capacity is already sufficient
        if (capacity <= _capacity) return;

        T* tmp = new T[capacity];

        for (size_t i = 0; i < _size; i++)
        {
            tmp[i] = _data[i];
        }

        for (size_t i = _size; i < capacity; i++)
        {
            tmp[i] = T();
        }

        delete[] _data;

        _data = tmp;
        _capacity = capacity;
    }

    template<class T>
    void Vector<T>::shrink_to_fit()
    {
        // Capacity is already minimal
        if (_size == _capacity) return;

        T* tmp = new T[_size];

        for (size_t i = 0; i < _size; i++)
        {
            tmp[i] = _data[i];
        }

        delete[] _data;

        _data = tmp;
        _capacity = _size;
    }

    template<class T>
    bool Vector<T>::empty() const
    {
        return (_size == 0);
    }

    template<typename T>
    size_t Vector<T>::size()
    {
        return _size;
    }

    template<typename T>
    size_t Vector<T>::capacity()
    {
        return _capacity;
    }

    template<class T>
    T& Vector<T>::at(size_t i)
    {
        if (i >= _size) throw out_of_range();
        return _data[i];
    }

    template<class T>
    const T& Vector<T>::at(size_t i) const
    {
        if (i >= _size) throw out_of_range();
        return _data[i];
    }

    template<class T>
    T& Vector<T>::operator[](size_t i)
    {
        return _data[i % _size];
    }

    template<class T>
    const T& Vector<T>::operator[](size_t i) const
    {
        return _data[i % _size];
    }

    template<class T>
    T& Vector<T>::front()
    {
        return _data[0];
    }

    template<class T>
    const T& Vector<T>::front() const
    {
        return _data[0];
    }

    template<class T>
    T& Vector<T>::back()
    {
        return _data[_size - 1];
    }

    template<class T>
    const T& Vector<T>::back() const
    {
        return _data[_size - 1];
    }

    template<class T>
    T* Vector<T>::data()
    {
        return _data;
    }

    template<class T>
    const T* Vector<T>::data() const
    {
        return _data;
    }

    template<typename T>
    void Vector<T>::clear()
    {
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = T();
        }
    }

    template<typename T>
    void Vector<T>::push_back(T value)
    {
        if (_capacity == 0)
            reserve(8);
        else if (_size == _capacity)
            reserve(2 * _capacity);

        _data[_size] = value;
        _size++;
    }

    template<typename T>
    T Vector<T>::pop_back()
    {
        _size--;
        return _data[_size];
    }

    template<typename T>
    void Vector<T>::swap(size_t i, size_t j)
    {
        _data[i] += _data[j];
        _data[j] = _data[i] - _data[j];
        _data[i] -= _data[j];
    }
}

#endif /* EMBLATE_VECTOR_H */
