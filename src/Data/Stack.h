#ifndef EMBLATE_STACK_H
#define EMBLATE_STACK_H

#include "Defines.h"
#include "Exception.h"
#include "List.h"

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
        Stack(Stack& stack_);
        Stack(const Stack& queue_);

        // Copy Assingment
        Stack<T>& operator=(const Stack<T>& stack_);

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
        // List containing the data
        List<T> _data;
    };

    template<typename T>
    Stack<T>::Stack()
            : _data(0)
    {
    }

    template<typename T>
    Stack<T>::Stack(size_t size, const T& value)
            : _data(size, value)
    {
    }

    template<typename T>
    Stack<T>::Stack(const T* array, size_t size, bool reverse)
            : _data(array, size, reverse)
    {
    }

    template<class T>
    Stack<T>::Stack(Stack<T>& stack_)
            : _data(stack_._data)
    {
    }

    template<class T>
    Stack<T>::Stack(const Stack<T>& stack_)
            : _data(stack_._data)
    {
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack<T>& stack_)
    {
        // Self-assignment
        if (this == &stack_) return *this;

        // Copy assignment
        delete _data;
        _data = new List<T>(stack_._data);

        return *this;
    }

    template<typename T>
    Stack<T>::~Stack()
    {
        delete _data;
    }

    template<class T>
    bool Stack<T>::empty() const
    {
        return (size() == 0);
    }

    template<typename T>
    size_t Stack<T>::size()
    {
        return _data.size();
    }

    template<class T>
    T& Stack<T>::at(size_t i)
    {
        if (i >= size()) throw out_of_range();
        return _data[i];
    }

    template<class T>
    const T& Stack<T>::at(size_t i) const
    {
        if (i >= size()) throw out_of_range();
        return _data[i];
    }

    template<class T>
    T& Stack<T>::operator[](size_t i)
    {
        return _data[i];
    }

    template<class T>
    const T& Stack<T>::operator[](size_t i) const
    {
        return _data[i];
    }

    template<class T>
    T& Stack<T>::front()
    {
        return _data[0];
    }

    template<class T>
    const T& Stack<T>::front() const
    {
        return _data[0];
    }

    template<class T>
    T& Stack<T>::back()
    {
        return _data[size() - 1];
    }

    template<class T>
    const T& Stack<T>::back() const
    {
        return _data[size() - 1];
    }

    template<class T>
    T* Stack<T>::data()
    {
        return _data;
    }

    template<class T>
    const T* Stack<T>::data() const
    {
        return _data;
    }

    template<typename T>
    void Stack<T>::clear()
    {
        _data.clear();
    }

    template<typename T>
    void Stack<T>::push(T value)
    {
        _data.push_back(value);
    }

    template<typename T>
    T Stack<T>::pop()
    {
        return _data.pop_back();
    }
}
#endif /* EMBLATE_STACK_H */
