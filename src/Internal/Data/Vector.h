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
        Vector(const Vector& other);

        // Copy Assingment
        Vector<T>& operator=(const Vector<T>& other);

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
        T* m_data;
        size_t m_size;
        size_t m_capacity;
    };

    template<typename T>
    Vector<T>::Vector()
            : m_data(0), m_size(0), m_capacity(0)
    {
    }

    template<typename T>
    Vector<T>::Vector(size_t size)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_capacity; i++)
        {
            m_data[i] = T();
        }
    }

    template<typename T>
    Vector<T>::Vector(size_t size, const T& value)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_capacity; i++)
        {
            m_data[i] = value;
        }
    }

    template<typename T>
    Vector<T>::Vector(const T* array, size_t size)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = array[i];
        }
    }

    template<class T>
    Vector<T>::Vector(const Vector<T>& other)
            : m_data(new T[other.m_size]), m_size(other.m_size),
              m_capacity(other.m_size)
    {
        for (size_t i = 0; i < other.m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }

    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& other)
    {
        // Self-assignment
        if (this == &other) { return *this; }

        // Memory reallocation
        if (other.m_size > m_capacity)
        {
            delete m_data;
            m_data = new T[other.m_size];
            m_capacity = other.m_size;
        }

        // Copy assignment
        m_size = other.m_size;

        for (size_t i = 0; i < other.m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

    template<typename T>
    Vector<T>::~Vector()
    {
        delete[] m_data;
    }

    template<class T>
    void Vector<T>::reserve(size_t capacity)
    {
        // This capacity is already sufficient
        if (capacity <= m_capacity) { return; }

        T* tmp = new T[capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            tmp[i] = m_data[i];
        }

        for (size_t i = m_size; i < capacity; i++)
        {
            tmp[i] = T();
        }

        delete[] m_data;

        m_data = tmp;
        m_capacity = capacity;
    }

    template<class T>
    void Vector<T>::shrink_to_fit()
    {
        // Capacity is already minimal
        if (m_size == m_capacity) { return; }

        T* tmp = new T[m_size];

        for (size_t i = 0; i < m_size; i++)
        {
            tmp[i] = m_data[i];
        }

        delete[] m_data;

        m_data = tmp;
        m_capacity = m_size;
    }

    template<class T>
    bool Vector<T>::empty() const
    {
        return (m_size == 0);
    }

    template<typename T>
    size_t Vector<T>::size()
    {
        return m_size;
    }

    template<typename T>
    size_t Vector<T>::capacity()
    {
        return m_capacity;
    }

    template<class T>
    T& Vector<T>::at(size_t i)
    {
        if (i >= m_size) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    const T& Vector<T>::at(size_t i) const
    {
        if (i >= m_size) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    T& Vector<T>::operator[](size_t i)
    {
        return m_data[i % m_size];
    }

    template<class T>
    const T& Vector<T>::operator[](size_t i) const
    {
        return m_data[i % m_size];
    }

    template<class T>
    T& Vector<T>::front()
    {
        return m_data[0];
    }

    template<class T>
    const T& Vector<T>::front() const
    {
        return m_data[0];
    }

    template<class T>
    T& Vector<T>::back()
    {
        return m_data[m_size - 1];
    }

    template<class T>
    const T& Vector<T>::back() const
    {
        return m_data[m_size - 1];
    }

    template<class T>
    T* Vector<T>::data()
    {
        return m_data;
    }

    template<class T>
    const T* Vector<T>::data() const
    {
        return m_data;
    }

    template<typename T>
    void Vector<T>::clear()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = T();
        }
    }

    template<typename T>
    void Vector<T>::push_back(T value)
    {
        if (m_capacity == 0) { reserve(8); }
        else if (m_size == m_capacity) { reserve(2 * m_capacity); }

        m_data[m_size] = value;
        m_size++;
    }

    template<typename T>
    T Vector<T>::pop_back()
    {
        m_size--;
        return m_data[m_size];
    }

    template<typename T>
    void Vector<T>::swap(size_t i, size_t j)
    {
        m_data[i] += m_data[j];
        m_data[j] = m_data[i] - m_data[j];
        m_data[i] -= m_data[j];
    }
}

#endif /* EMBLATE_VECTOR_H */
