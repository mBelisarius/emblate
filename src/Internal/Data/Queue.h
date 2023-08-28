#ifndef EMBLATE_QUEUE_H
#define EMBLATE_QUEUE_H

#include "./Defines.h"
#include "./List.h"
#include "../Core/Exception.h"

namespace Emblate
{
    template<typename T>
    class Queue : List<T>
    {
    public:
        Queue();
        Queue(size_t size, const T& value);
        Queue(const T* array, size_t size, bool reverse = false);
        Queue(Queue& other);
        Queue(const Queue& other);

        ~Queue();

        Queue<T>& operator=(const Queue<T>& other);

        bool empty();
        size_t size();

        T& at(size_t i);
        const T& at(size_t i) const;

        T& operator[](size_t i);
        const T& operator[](size_t i) const;

        T& front();
        const T& front() const;

        T& back();
        const T& back() const;

        T* data();
        const T* data() const;

        void clear();

        void push(T value);
        T pop();

        void slide(T value);
        void slide_limited(T value, size_t maxsize);

    private:
        List<T> m_data;
    };

    /**
     * Default constructor for a new empty queue.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Queue<T>::Queue()
            : m_data() {}

    /**
     * Constructor for a new queue with given size filled with _value_.
     *
     * @tparam T Values data type.
     * @param size Initial size.
     * @param value Initial value.
     */
    template<typename T>
    Queue<T>::Queue(size_t size, const T& value)
            : m_data(size, value) {}

    /**
     * Constructor for a new queue copied from a plain C-style array.
     *
     * @tparam T Values data type.
     * @param array Plain C-style array.
     * @param size Size of the base array.
     * @param reverse Reverse the order in which the elements appear.
     */
    template<typename T>
    Queue<T>::Queue(const T* array, size_t size, bool reverse)
            : m_data(array, size, reverse) {}

    /**
     * Copy constructor for a new queue.
     *
     * @tparam T Values data type.
     * @param other Queue to be copied.
     */
    template<class T>
    Queue<T>::Queue(Queue<T>& other)
            : m_data(other.m_data) {}

    /**
     * Copy constructor for a new queue.
     *
     * @tparam T Values data type.
     * @param other Queue to be copied.
     */
    template<class T>
    Queue<T>::Queue(const Queue<T>& other)
            : m_data(other.m_data) {}

    /**
     * Destructor for a queue object.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Queue<T>::~Queue()
    {
        m_data.~List();
    }

    /**
     * Copy assignment.
     *
     * @tparam T Values data type.
     * @param other Queue to be copied.
     * @return Copied queue.
     */
    template<typename T>
    Queue<T>& Queue<T>::operator=(const Queue<T>& other)
    {
        // Self-assignment
        if (this == &other) return *this;

        // Copy assignment
        delete m_data;
        m_data = new List<T>(other.m_data);

        return *this;
    }

    /**
     * Checks whether the container is empty.
     *
     * @tparam T Values data type.
     * @return True if the container is empty, false otherwise.
     */
    template<class T>
    bool Queue<T>::empty()
    {
        return size() == 0;
    }

    /**
     * Returns the number of elements in the container.
     *
     * @tparam T Values data type.
     * @return The number of elements.
     */
    template<typename T>
    size_t Queue<T>::size()
    {
        return m_data.size();
    }

    /**
     * Access specified element with bounds checking.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    T& Queue<T>::at(size_t i)
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    /**
     * Access specified element with bounds checking.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    const T& Queue<T>::at(size_t i) const
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    /**
     * Access specified element.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    T& Queue<T>::operator[](size_t i)
    {
        return m_data[i];
    }

    /**
     * Access specified element.
     *
     * @tparam T Values data type.
     * @param pos Position of the element to return.
     * @return Reference to the requested element.
     */
    template<class T>
    const T& Queue<T>::operator[](size_t i) const
    {
        return m_data[i];
    }

    /**
     * Returns a reference to the first element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the first element.
     */
    template<class T>
    T& Queue<T>::front()
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
    const T& Queue<T>::front() const
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
    T& Queue<T>::back()
    {
        return m_data[size() - 1];
    }

    /**
     * Returns a reference to the last element in the container.
     *
     * @tparam T Values data type.
     * @return Reference to the last element.
     */
    template<class T>
    const T& Queue<T>::back() const
    {
        return m_data[size() - 1];
    }

    /**
     * Returns a reference to the base container used by the queue.
     *
     * @tparam T Values data type.
     * @return Reference to the base container.
     */
    template<class T>
    T* Queue<T>::data()
    {
        return m_data;
    }

    /**
     * Returns a reference to the base container used by the queue.
     *
     * @tparam T Values data type.
     * @return Reference to the base container.
     */
    template<class T>
    const T* Queue<T>::data() const
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
    void Queue<T>::clear()
    {
        m_data.clear();
    }

    /**
     * Prepends the given element value to the beginning of the container.
     *
     * @tparam T Values data type.
     * @param value Value of the element to prepend.
     */
    template<typename T>
    void Queue<T>::push(T value)
    {
        m_data.push_front(value);
    }

    /**
     * Removes the last element of the container.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    T Queue<T>::pop()
    {
        return m_data.pop_back();
    }

    /**
     * Simultaneously push and pop an element.
     *
     * @tparam T Values data type.
     * @param value Value of the element to push.
     */
    template<typename T>
    void Queue<T>::slide(T value)
    {
        slide_limited(value, 1);
    }

    /**
     * Simultaneously push and pop an element if the size of the container is
     * greater then _maxsize_.
     *
     * @tparam T Values data type.
     * @param value Value of the element to push.
     */
    template<typename T>
    void Queue<T>::slide_limited(T value, size_t maxsize)
    {
        if (size() >= maxsize) { pop(); }

        push(value);
    }
}

#endif /* EMBLATE_QUEUE_H */
