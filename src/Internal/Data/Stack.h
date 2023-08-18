#ifndef EMBLATE_STACK_H
#define EMBLATE_STACK_H

#include "./Defines.h"
#include "./List.h"
#include "../Core/Exception.h"

namespace Emblate
{
    template<typename T>
    class Stack : List<T>
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        Stack();

        Stack(size_t size, const T& value);
        Stack(const T* array, size_t size, bool reverse = false);

        // Copy constructor
        Stack(Stack& other);
        Stack(const Stack& other);

        // Copy Assingment
        Stack<T>& operator=(const Stack<T>& other);

        // Destructor
        ~Stack();

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
        // Capacity is not changed
        void clear();

        // Push element
        void push(T value);

        // Pop element
        T pop();

    private:
        List<T> m_data;
    };

    template<typename T>
    Stack<T>::Stack()
            : m_data(0)
    {
    }

    template<typename T>
    Stack<T>::Stack(size_t size, const T& value)
            : m_data(size, value)
    {
    }

    template<typename T>
    Stack<T>::Stack(const T* array, size_t size, bool reverse)
            : m_data(array, size, reverse)
    {
    }

    template<class T>
    Stack<T>::Stack(Stack<T>& other)
            : m_data(other.m_data)
    {
    }

    template<class T>
    Stack<T>::Stack(const Stack<T>& other)
            : m_data(other.m_data)
    {
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& other)
    {
        // Self-assignment
        if (this == &other) return *this;

        // Copy assignment
        delete m_data;
        m_data = new List<T>(other.m_data);

        return *this;
    }

    template<typename T>
    Stack<T>::~Stack()
    {
        delete m_data;
    }

    template<class T>
    bool Stack<T>::empty() const
    {
        return size() == 0;
    }

    template<typename T>
    size_t Stack<T>::size()
    {
        return m_data.size();
    }

    template<class T>
    T& Stack<T>::at(size_t i)
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    const T& Stack<T>::at(size_t i) const
    {
        if (i >= size()) { throw out_of_range(); }
        return m_data[i];
    }

    template<class T>
    T& Stack<T>::operator[](size_t i)
    {
        return m_data[i];
    }

    template<class T>
    const T& Stack<T>::operator[](size_t i) const
    {
        return m_data[i];
    }

    template<class T>
    T& Stack<T>::front()
    {
        return m_data[0];
    }

    template<class T>
    const T& Stack<T>::front() const
    {
        return m_data[0];
    }

    template<class T>
    T& Stack<T>::back()
    {
        return m_data[size() - 1];
    }

    template<class T>
    const T& Stack<T>::back() const
    {
        return m_data[size() - 1];
    }

    template<class T>
    T* Stack<T>::data()
    {
        return m_data;
    }

    template<class T>
    const T* Stack<T>::data() const
    {
        return m_data;
    }

    template<typename T>
    void Stack<T>::clear()
    {
        m_data.clear();
    }

    template<typename T>
    void Stack<T>::push(T value)
    {
        m_data.push_back(value);
    }

    template<typename T>
    T Stack<T>::pop()
    {
        return m_data.pop_back();
    }
}

#endif /* EMBLATE_STACK_H */
