#ifndef EMBLATE_LIST_H
#define EMBLATE_LIST_H

#include "./Defines.h"
#include "./Exception.h"

namespace Emblate
{
    template<class Elem>
    struct Link
    {
        // Constructor
        Link(const Elem& value = Elem(), Link* prev = 0, Link* next = 0)
                : _prev(prev), _next(next), _value(value)
        {
        }

        Link* _prev;
        Link* _next;
        Elem _value;
    };

    template<typename T>
    class List
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        List();
        List(size_t size, const T& value);
        List(const T* array, size_t size, bool reverse = false);

        // Copy constructor
        List(const List<T>& list_);

        // Copy Assingment
        List<T>& operator=(const List<T>& list_);

        // Destructor
        ~List();

        /*--- Iterators ---*/
        class iterator;

        // Iterator to front (first) element
        iterator begin()
        {
            return iterator(_frontLink->_next);
        }

        // Iterator to back (last) element
        iterator end()
        {
            return iterator(_backLink);
        }

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
        T& operator[](int i);
        const T& operator[](int i) const;

        // Returns a reference to the first element
        T& front();
        const T& front() const;

        // Returns a reference to the last element
        T& back();
        const T& back() const;

        /*--- Modifiers ---*/
        // Removes all elements
        void clear();

        // Inserts element at the front
        void push_front(const T value);

        // Inserts element at the back
        void push_back(const T value);

        // Removes the first (front) element
        T pop_front();

        // Removes the last (back) element
        T pop_back();

    private:
        // Front and back links
        Link<T>* _frontLink;
        Link<T>* _backLink;

        // Number of elements (used capacity)
        size_t _size;
    };

    template<typename T>
    List<T>::List()
            : _frontLink(new Link<T>(T(), 0, 0)),
              _backLink(new Link<T>(T(), _frontLink, 0))
    {
        _frontLink->_next = _backLink;
        _size = 0;
    }

    template<typename T>
    List<T>::List(size_t size, const T& value)
            : _frontLink(new Link<T>(T(), 0, 0)),
              _backLink(new Link<T>(T(), _frontLink, 0))
    {
        _frontLink->_next = _backLink;
        _size = 0;

        for (size_t i = 0; i < size; i++)
        {
            push_back(value);
        }
    }

    template<typename T>
    List<T>::List(const T* array, size_t size, bool reverse)
            : _frontLink(new Link<T>(T(), 0, 0)),
              _backLink(new Link<T>(T(), _frontLink, 0))
    {
        _frontLink->_next = _backLink;
        _size = 0;

        // Keep conditional statements out of the loop for optimization
        if (reverse)
        {
            for (size_t i = 0; i < size; i++)
            {
                push_front(array[i]);
            }
        }
        else
        {
            for (size_t i = 0; i < size; i++)
            {
                push_back(array[i]);
            }
        }
    }

    template<typename T>
    List<T>::List(const List<T>& list_)
            : _frontLink(new Link<T>(T(), 0, 0)),
              _backLink(new Link<T>(T(), _frontLink, 0))
    {
        _frontLink->_next = _backLink;
        _size = 0;

        for (Link<T>* elem = list_._frontLink; elem != 0; elem = elem->_next)
        {
            push_back(elem->_value);
        }
    }

    template<typename T>
    List<T>& List<T>::operator=(const List<T>& list_)
    {
        // Self-assignment
        if (this == &list_) return *this;

        // Copy assignment
        delete this;

        for (Link<T>* elem = list_._frontLink; elem != 0; elem = elem->_next)
        {
            push_back(elem->_value);
        }

        return *this;
    }

    template<typename T>
    List<T>::~List()
    {
        // TODO: implementation
        for (size_t i = size(); i > 0; i--)
        {
            pop_back();
        }

        // delete _frontLink;
        // delete _backLink;
    }

    template<class Elem>
    class List<Elem>::iterator
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        iterator(Link<Elem>* p)
                : _curr(p)
        {
        }

        /*--- Operators ---*/
        iterator& operator++()
        {
            _curr = _curr->_next;
            return *this;
        }

        iterator& operator--()
        {
            _curr = _curr->_prev;
            return *this;
        }

        Elem& operator*()
        {
            return _curr->_val;
        }

        bool operator==(const iterator& link_) const
        {
            return _curr == link_._curr;
        }

        bool operator!=(const iterator& link_) const
        {
            return _curr != link_._curr;
        }

    private:
        // Current link to iterate from
        Link<Elem>* _curr;
    };

    template<class T>
    bool List<T>::empty() const
    {
        return (_size == 0);
    }

    template<typename T>
    size_t List<T>::size()
    {
        return _size;
    }

    template<class T>
    T& List<T>::at(size_t i)
    {
        if (i >= _size) throw out_of_range();

        Link<T>* elem;

        if (i < _size / 2)
        {
            elem = _frontLink->_next;
            for (size_t _ = 0; _ < i; _++)
            {
                elem = elem->_next;
            }
        }
        else
        {
            elem = _backLink->_prev;
            for (size_t _ = _size - 1; _ > i; _--)
            {
                elem = elem->_prev;
            }
        }

        return elem->_value;
    }

    template<class T>
    const T& List<T>::at(size_t i) const
    {
        if (i >= _size) throw out_of_range();

        Link<T>* elem;

        if (i < _size / 2)
        {
            elem = _frontLink->_next;
            for (size_t _ = 0; _ < i; _++)
            {
                elem = elem->_next;
            }
        }
        else
        {
            elem = _backLink->_prev;
            for (size_t _ = _size - 1; _ > i; _--)
            {
                elem = elem->_prev;
            }
        }

        return elem->_value;
    }

    template<class T>
    T& List<T>::operator[](int i)
    {
        int index = i % (int)_size;

        if (index < 0)
            index += _size;

        return at(index);
    }

    template<class T>
    const T& List<T>::operator[](int i) const
    {
        int index = i % (int)_size;

        if (index < 0)
            index += _size;

        return at(index);
    }

    template<typename T>
    T& List<T>::front()
    {
        if (_size == 0) throw out_of_range();
        return _frontLink->_next->_value;
    }

    template<typename T>
    T& List<T>::back()
    {
        if (_size == 0) throw out_of_range();
        return _backLink->_prev->_value;
    }

    template<typename T>
    void List<T>::clear()
    {
        Link<T>* elem = _frontLink->_next;
        for (size_t i = 0; i < _size; i++)
        {
            elem->_value = 0;
            elem = elem->_next;
        }
    }

    template<typename T>
    void List<T>::push_front(const T value)
    {
        Link<T>* newLink = new Link<T>;
        newLink->_value = value;
        newLink->_prev = _frontLink;
        newLink->_next = _frontLink->_next;

        _frontLink->_next->_prev = newLink;
        _frontLink->_next = newLink;

        _size++;
    }

    template<typename T>
    void List<T>::push_back(const T value)
    {
        Link<T>* newLink = new Link<T>;
        newLink->_value = value;
        newLink->_prev = _backLink->_prev;
        newLink->_next = _backLink;

        _backLink->_prev->_next = newLink;
        _backLink->_prev = newLink;

        _size++;
    }

    template<typename T>
    T List<T>::pop_front()
    {
        // TODO: throw exception
        if (empty())
            throw;

        Link<T>* tmp = _frontLink->_next->_next;
        tmp->_prev = _frontLink;
        _frontLink->_next = tmp;
        // TODO: delete tmp->_prev

        _size--;
        return tmp->_next->_value;
    }

    template<typename T>
    T List<T>::pop_back()
    {
        // TODO: throw exception
        if (empty())
            throw;

        Link<T>* tmp = _backLink->_prev->_prev;
        tmp->_next = _backLink;
        _backLink->_prev = tmp;
        // TODO: delete tmp->_next

        _size--;
        return tmp->_next->_value;
    }
}

#endif /* EMBLATE_LIST_H */
