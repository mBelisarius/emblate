#ifndef EMBLATE_TUPLE_H
#define EMBLATE_TUPLE_H

#include "./Defines.h"
#include "../Core/Exception.h"

namespace Emblate
{
    template<typename T>
    class Tuple
    {
    public:
        Tuple();
        Tuple(size_t size);
        Tuple(size_t size, const T& value);
        Tuple(const T* array, size_t size);
        Tuple(const Tuple& other);

        ~Tuple();

        Tuple<T>& operator=(const Tuple<T>& other);

        bool empty() const;
        size_t size();

        T& at(size_t i);
        const T& at(size_t i) const;

        T& operator[](size_t i);
        const T& operator[](size_t i) const;

        T* data();
        const T* data() const;

        void clear();

    private:
        T* m_data;
        size_t m_size;
    };

    template<typename T>
    Tuple<T>::Tuple()
            : m_data(0), m_size(0) {}

    template<typename T>
    Tuple<T>::Tuple(size_t size)
            : m_data(new T[size]), m_size(size)
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = T();
        }
    }

    template<typename T>
    Tuple<T>::Tuple(size_t size, const T& value)
            : m_data(new T[size]), m_size(size)
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = value;
        }
    }

    template<typename T>
    Tuple<T>::Tuple(const T* array, size_t size)
            : m_data(new T[size]), m_size(size)
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = array[i];
        }
    }

    template<class T>
    Tuple<T>::Tuple(const Tuple<T>& other)
            : m_data(new T[other.m_size]), m_size(other.m_size)
    {
        for (size_t i = 0; i < other.m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }

    template<typename T>
    Tuple<T>::~Tuple()
    {
        delete[] m_data;
    }

    template<typename T>
    Tuple<T>& Tuple<T>::operator=(const Tuple<T>& other)
    {
        // Self-assignment
        if (this == &other) return *this;

        // Memory reallocation
        if (other.m_size != m_size)
        {
            delete[] m_data;
            m_data = new T[other.m_size];
            m_size = other.m_size;
        }

        // Copy assignment
        for (size_t i = 0; i < other.m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

    template<class T>
    bool Tuple<T>::empty() const
    {
        return (m_size == 0);
    }

    template<typename T>
    size_t Tuple<T>::size()
    {
        return m_size;
    }

    template<class T>
    T& Tuple<T>::at(size_t i)
    {
        if (i >= m_size) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    const T& Tuple<T>::at(size_t i) const
    {
        if (i >= m_size) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    T& Tuple<T>::operator[](size_t i)
    {
        return m_data[i % m_size];
    }

    template<class T>
    const T& Tuple<T>::operator[](size_t i) const
    {
        return m_data[i % m_size];
    }

    template<class T>
    T* Tuple<T>::data()
    {
        return m_data;
    }

    template<class T>
    const T* Tuple<T>::data() const
    {
        return m_data;
    }

    template<typename T>
    void Tuple<T>::clear()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = T();
        }
    }
}

#endif /* EMBLATE_TUPLE_H */
