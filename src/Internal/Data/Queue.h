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
        /*--- Constructors ---*/
        // Default constructor
        Queue();

        Queue(size_t size, const T& value);
        Queue(const T* array, size_t size, bool reverse = false);

        // Copy constructor
        Queue(Queue& other);
        Queue(const Queue& other);

        // Copy Assingment
        Queue<T>& operator=(const Queue<T>& other);

        // Destructor
        ~Queue();

        /*--- Memory ---*/
        // Returns True if this queue is empty
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

        // Returns a reference to the first element
        T& front();
        const T& front() const;

        // Returns a reference to the last element
        T& back();
        const T& back() const;

        // Returns a pointer to the array used by this queue
        T* data();
        const T* data() const;

        /*--- Modifiers ---*/
        // Removes all elements
        void clear();

        // Enqueue element
        void enqueue(T value);

        // Dequeue element
        T dequeue();

        // Enqueue element and dequeue
        void endequeue(T value);

        // Enqueue element and dequeue to maintain size < maxsize(
        void endequeue_limited(T value, size_t maxsize);

        // Inserts element at the back
        void push_back(T value);

    private:
        List<T> m_data;
    };

    template<typename T>
    Queue<T>::Queue()
            : m_data()
    {
    }

    template<typename T>
    Queue<T>::Queue(size_t size, const T& value)
            : m_data(size, value)
    {
    }

    template<typename T>
    Queue<T>::Queue(const T* array, size_t size, bool reverse)
            : m_data(array, size, reverse)
    {
    }

    template<class T>
    Queue<T>::Queue(Queue<T>& other)
            : m_data(other.m_data)
    {
    }

    template<class T>
    Queue<T>::Queue(const Queue<T>& other)
            : m_data(other.m_data)
    {
    }

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

    template<typename T>
    Queue<T>::~Queue()
    {
        m_data.~List();
    }

    template<class T>
    bool Queue<T>::empty() const
    {
        return size() == 0;
    }

    template<typename T>
    size_t Queue<T>::size()
    {
        return m_data.size();
    }

    template<class T>
    T& Queue<T>::at(size_t i)
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    const T& Queue<T>::at(size_t i) const
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    T& Queue<T>::operator[](size_t i)
    {
        return m_data[i];
    }

    template<class T>
    const T& Queue<T>::operator[](size_t i) const
    {
        return m_data[i];
    }

    template<class T>
    T& Queue<T>::front()
    {
        return m_data[0];
    }

    template<class T>
    const T& Queue<T>::front() const
    {
        return m_data[0];
    }

    template<class T>
    T& Queue<T>::back()
    {
        return m_data[size() - 1];
    }

    template<class T>
    const T& Queue<T>::back() const
    {
        return m_data[size() - 1];
    }

    template<class T>
    T* Queue<T>::data()
    {
        return m_data;
    }

    template<class T>
    const T* Queue<T>::data() const
    {
        return m_data;
    }

    template<typename T>
    void Queue<T>::clear()
    {
        m_data.clear();
    }

    template<typename T>
    void Queue<T>::enqueue(T value)
    {
        m_data.push_front(value);
    }

    template<typename T>
    T Queue<T>::dequeue()
    {
        return m_data.pop_back();
    }

    template<typename T>
    void Queue<T>::endequeue(T value)
    {
        endequeue_limited(value, 1);
    }

    template<typename T>
    void Queue<T>::endequeue_limited(T value, size_t maxsize)
    {
        if (size() >= maxsize)
            dequeue();

        enqueue(value);
    }

    template<typename T>
    void Queue<T>::push_back(T value)
    {
        m_data.push_back(value);
    }
}
#endif /* EMBLATE_QUEUE_H */
