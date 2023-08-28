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
        Stack();
        Stack(size_t size, const T& value);
        Stack(const T* array, size_t size, bool reverse = false);
        Stack(Stack& other);
        Stack(const Stack& other);

        ~Stack();

        Stack<T>& operator=(const Stack<T>& other);

        bool empty() const;
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

    private:
        List<T> m_data;
    };

    /**
     * Default constructor for a new empty stack.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Stack<T>::Stack()
            : m_data() {}

    /**
     * Constructor for a new stack with given size filled with _value_.
     *
     * @tparam T Values data type.
     * @param size Initial size.
     * @param value Initial value.
     */
    template<typename T>
    Stack<T>::Stack(size_t size, const T& value)
            : m_data(size, value) {}

    /**
     * Constructor for a new stack copied from a plain C-style array.
     *
     * @tparam T Values data type.
     * @param array Plain C-style array.
     * @param size Size of the base array.
     * @param reverse Reverse the order in which the elements appear.
     */
    template<typename T>
    Stack<T>::Stack(const T* array, size_t size, bool reverse)
            : m_data(array, size, reverse) {}

    /**
     * Copy constructor for a new stack.
     *
     * @tparam T Values data type.
     * @param other Stack to be copied.
     */
    template<class T>
    Stack<T>::Stack(Stack<T>& other)
            : m_data(other.m_data) {}

    /**
     * Copy constructor for a new stack.
     *
     * @tparam T Values data type.
     * @param other Stack to be copied.
     */
    template<class T>
    Stack<T>::Stack(const Stack<T>& other)
            : m_data(other.m_data) {}

    /**
     * Destructor for a stack object.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    Stack<T>::~Stack()
    {
        delete m_data;
    }

    /**
     * Copy assignment.
     *
     * @tparam T Values data type.
     * @param other Stack to be copied.
     * @return Copied stack.
     */
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

    /**
     * Checks whether the container is empty.
     *
     * @tparam T Values data type.
     * @return True if the container is empty, false otherwise.
     */
    template<class T>
    bool Stack<T>::empty() const
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
    size_t Stack<T>::size()
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
    T& Stack<T>::at(size_t i)
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
    const T& Stack<T>::at(size_t i) const
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
    T& Stack<T>::operator[](size_t i)
    {
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
    const T& Stack<T>::operator[](size_t i) const
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
    T& Stack<T>::front()
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
    const T& Stack<T>::front() const
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
    T& Stack<T>::back()
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
    const T& Stack<T>::back() const
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
    T* Stack<T>::data()
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
    const T* Stack<T>::data() const
    {
        return m_data;
    }

    /**
     * Erases all elements from the container. After this call, size() returns zero.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    void Stack<T>::clear()
    {
        m_data.clear();
    }

    /**
     * Appends the given element value to the end of the container.
     *
     * @tparam T Values data type.
     * @param value Value of the element to append.
     */
    template<typename T>
    void Stack<T>::push(T value)
    {
        m_data.push_back(value);
    }

    /**
     * Removes the last element of the container.
     *
     * @tparam T Values data type.
     */
    template<typename T>
    T Stack<T>::pop()
    {
        return m_data.pop_back();
    }
}

#endif /* EMBLATE_STACK_H */
