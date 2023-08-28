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
        Vector();
        Vector(size_t size);
        Vector(size_t size, const T& value);
        Vector(const T* array, size_t size);
        Vector(const Vector& other);

        ~Vector();

        Vector<T>& operator=(const Vector<T>& other);

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
        T& at(size_t pos);
        const T& at(size_t pos) const;

        // Access elements (no bounds checking)
        T& operator[](size_t pos);
        const T& operator[](size_t pos) const;

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
        void swap(size_t pos1, size_t pos2);

    private:
        T* m_data;
        size_t m_size;
        size_t m_capacity;
    };

    /**
     * Default constructor for a new empty vector.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Vector<T>::Vector()
            : m_data(), m_size(), m_capacity() {}

    /**
     * Constructor for a new list with given size and unitialized elements.
     *
     * @tparam T Values data type.
     * @param size Initial size.
     */
    template<typename T>
    Vector<T>::Vector(size_t size)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_capacity; i++)
        {
            m_data[i] = T();
        }
    }

    /**
     * Constructor for a new vector with given size filled with _value_.
     *
     * @tparam T Values data type.
     * @param size Initial size.
     * @param value Initial value.
     */
    template<typename T>
    Vector<T>::Vector(size_t size, const T& value)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_capacity; i++)
        {
            m_data[i] = value;
        }
    }

    /**
     * Constructor for a new vector copied from a plain C-style array.
     *
     * @tparam T Values data type.
     * @param array Plain C-style array.
     * @param size Size of the base array.
     * @param reverse Reverse the order in which the elements appear.
     */
    template<typename T>
    Vector<T>::Vector(const T* array, size_t size)
            : m_data(new T[size]), m_size(size), m_capacity(size)
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = array[i];
        }
    }

    /**
     * Copy constructor for a new vector.
     *
     * @tparam T Values data type.
     * @param other Vector to be copied.
     */
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

    /**
     * Destructor for a vector object.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Vector<T>::~Vector()
    {
        delete[] m_data;
    }

    /**
     * Copy assignment.
     *
     * @tparam T Values data type.
     * @param other Vector to be copied.
     * @return Copied vector.
     */
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

    /**
     * Increase the capacity of the vector (the total number of elements that
     * the vector can hold without requiring reallocation) to a value that's
     * greater or equal to new_cap.
     *
     * @tparam T Values data type.
     * @param capacity	New capacity of the vector, in number of elements.
     */
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

    /**
     * Requests the removal of unused capacity.
     *
     * @tparam T Values data type.
     */
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

    /**
     * Checks whether the container is empty.
     *
     * @tparam T Values data type.
     * @return True if the container is empty, false otherwise.
     */
    template<class T>
    bool Vector<T>::empty() const
    {
        return (m_size == 0);
    }

    /**
     * Returns the number of elements in the container.
     *
     * @tparam T Values data type.
     * @return The number of elements.
     */
    template<typename T>
    size_t Vector<T>::size()
    {
        return m_size;
    }

    /**
     * Returns the number of elements that the container has currently
     * allocated space for.
     *
     * @tparam T Values data type.
     * @return The number of elements that can be held in currently allocated
     * storage.
     */
    template<typename T>
    size_t Vector<T>::capacity()
    {
        return m_capacity;
    }

    /**
     * Access specified element with bounds checking.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    T& Vector<T>::at(size_t pos)
    {
        if (pos >= m_size) { throw out_of_range(); }
        return m_data[pos];
    }

    /**
     * Access specified element with bounds checking.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    const T& Vector<T>::at(size_t pos) const
    {
        if (pos >= m_size) { throw out_of_range(); }
        return m_data[pos];
    }

    /**
     * Access specified element.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    T& Vector<T>::operator[](size_t pos)
    {
        return m_data[pos % m_size];
    }

    /**
     * Access specified element.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    const T& Vector<T>::operator[](size_t pos) const
    {
        return m_data[pos % m_size];
    }

    /**
     * Returns a reference to the first element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the first element.
     */
    template<class T>
    T& Vector<T>::front()
    {
        return m_data[0];
    }

    /**
     * Returns a reference to the first element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the first element.
     */
    template<class T>
    const T& Vector<T>::front() const
    {
        return m_data[0];
    }

    /**
     * Returns a reference to the last element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the last element.
     */
    template<class T>
    T& Vector<T>::back()
    {
        return m_data[m_size - 1];
    }

    /**
     * Returns a reference to the last element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the last element.
     */
    template<class T>
    const T& Vector<T>::back() const
    {
        return m_data[m_size - 1];
    }

    /**
     * Direct access to the underlying array serving as element storage.
     *
     * @tparam T Values data type.
     * @return Pointer to the underlying element storage. For non-empty
     * containers, the returned pointer compares equal to the address of the
     * first element.
     */
    template<class T>
    T* Vector<T>::data()
    {
        return m_data;
    }

    /**
     * Direct access to the underlying array serving as element storage.
     *
     * @tparam T Values data type.
     * @return Pointer to the underlying element storage. For non-empty
     * containers, the returned pointer compares equal to the address of the
     * first element.
     */
    template<class T>
    const T* Vector<T>::data() const
    {
        return m_data;
    }

    /**
     * Erases all elements from the container. After this call, size() returns
     * zero.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    void Vector<T>::clear()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i] = T();
        }
    }

    /**
     * Appends the given element value to the end of the container.
     *
     * @tparam T Values data type.
     * @param value Value of the element to append.
     */
    template<typename T>
    void Vector<T>::push_back(T value)
    {
        if (m_capacity == 0) { reserve(8); }
        else if (m_size == m_capacity) { reserve(2 * m_capacity); }

        m_data[m_size] = value;
        m_size++;
    }

    /**
     * Removes the last element of the container.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    T Vector<T>::pop_back()
    {
        m_size--;
        return m_data[m_size];
    }

    /**
     * Swaps two elements in the container.
     *
     * @tparam T Values data type.
     * @param pos1 Position of the first element to swap.
     * @param pos2 Position of the second element to swap.
     */
    template<typename T>
    void Vector<T>::swap(size_t pos1, size_t pos2)
    {
        m_data[pos1] += m_data[pos2];
        m_data[pos2] = m_data[pos1] - m_data[pos2];
        m_data[pos1] -= m_data[pos2];
    }
}

#endif /* EMBLATE_VECTOR_H */
