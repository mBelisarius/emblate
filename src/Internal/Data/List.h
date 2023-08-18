#ifndef EMBLATE_LIST_H
#define EMBLATE_LIST_H

#include "./Defines.h"
#include "../Core/Exception.h"

namespace Emblate
{
    template<class Elem>
    struct Link
    {
        // Constructor
        Link(const Elem& value = Elem(), Link* prev = 0, Link* next = 0)
                : m_prev(prev), m_next(next), m_value(value)
        {
        }

        Link* m_prev;
        Link* m_next;
        Elem m_value;
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
        List(const List<T>& other);

        // Copy Assingment
        List<T>& operator=(const List<T>& other);

        // Destructor
        ~List();

        /*--- Iterators ---*/
        class iterator;

        // Iterator to front (first) element
        iterator begin()
        {
            return iterator(m_front_link->m_next);
        }

        // Iterator to back (last) element
        iterator end()
        {
            return iterator(m_back_link);
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
        void pop_front();

        // Removes the last (back) element
        void pop_back();

    private:
        Link<T>* m_front_link;
        Link<T>* m_back_link;
        size_t m_size;
    };

    template<typename T>
    List<T>::List()
            : m_front_link(new Link<T>(T(), 0, 0)),
              m_back_link(new Link<T>(T(), m_front_link, 0))
    {
        m_front_link->m_next = m_back_link;
        m_size = 0;
    }

    template<typename T>
    List<T>::List(size_t size, const T& value)
            : m_front_link(new Link<T>(T(), 0, 0)),
              m_back_link(new Link<T>(T(), m_front_link, 0))
    {
        m_front_link->m_next = m_back_link;
        m_size = 0;

        for (size_t i = 0; i < size; i++)
        {
            push_back(value);
        }
    }

    template<typename T>
    List<T>::List(const T* array, size_t size, bool reverse)
            : m_front_link(new Link<T>(T(), 0, 0)),
              m_back_link(new Link<T>(T(), m_front_link, 0))
    {
        m_front_link->m_next = m_back_link;
        m_size = 0;

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
    List<T>::List(const List<T>& other)
            : m_front_link(new Link<T>(T(), 0, 0)),
              m_back_link(new Link<T>(T(), m_front_link, 0))
    {
        m_front_link->m_next = m_back_link;
        m_size = 0;

        for (Link<T>* elem = other.m_front_link;
             elem != 0;
             elem = elem->m_next)
        {
            push_back(elem->m_value);
        }
    }

    template<typename T>
    List<T>& List<T>::operator=(const List<T>& other)
    {
        // Self-assignment
        if (this == &other) return *this;

        // Copy assignment
        delete this;

        for (Link<T>* elem = other.m_front_link;
             elem != 0;
             elem = elem->m_next)
        {
            push_back(elem->m_value);
        }

        return *this;
    }

    template<typename T>
    List<T>::~List()
    {
        while (size() > 0) { pop_back(); }
    }

    template<class Elem>
    class List<Elem>::iterator
    {
    public:
        /*--- Constructors ---*/
        // Default constructor
        iterator(Link<Elem>* p)
                : m_curr(p)
        {
        }

        /*--- Operators ---*/
        iterator& operator++()
        {
            m_curr = m_curr->m_next;
            return *this;
        }

        iterator& operator--()
        {
            m_curr = m_curr->m_prev;
            return *this;
        }

        Elem& operator*()
        {
            return m_curr->m_value;
        }

        bool operator==(const iterator& link_) const
        {
            return m_curr == link_.m_curr;
        }

        bool operator!=(const iterator& link_) const
        {
            return m_curr != link_.m_curr;
        }

    private:
        // Current link to iterate from
        Link<Elem>* m_curr;
    };

    template<class T>
    bool List<T>::empty() const
    {
        return (m_size == 0);
    }

    template<typename T>
    size_t List<T>::size()
    {
        return m_size;
    }

    template<class T>
    T& List<T>::at(size_t i)
    {
        if (i >= m_size) { throw out_of_range(); }

        Link<T>* elem;

        if (i < m_size / 2)
        {
            elem = m_front_link->m_next;
            for (size_t _ = 0; _ < i; _++)
            {
                elem = elem->m_next;
            }
        }
        else
        {
            elem = m_back_link->m_prev;
            for (size_t _ = m_size - 1; _ > i; _--)
            {
                elem = elem->m_prev;
            }
        }

        return elem->m_value;
    }

    template<class T>
    const T& List<T>::at(size_t i) const
    {
        if (i >= m_size) throw out_of_range();

        Link<T>* elem;

        if (i < m_size / 2)
        {
            elem = m_front_link->m_next;
            for (size_t _ = 0; _ < i; _++)
            {
                elem = elem->m_next;
            }
        }
        else
        {
            elem = m_back_link->m_prev;
            for (size_t _ = m_size - 1; _ > i; _--)
            {
                elem = elem->m_prev;
            }
        }

        return elem->m_value;
    }

    template<class T>
    T& List<T>::operator[](int i)
    {
        int index = i % (int)m_size;

        if (index < 0) { index += m_size; }

        return at(index);
    }

    template<class T>
    const T& List<T>::operator[](int i) const
    {
        int index = i % (int)m_size;

        if (index < 0) { index += m_size; }

        return at(index);
    }

    template<typename T>
    T& List<T>::front()
    {
        if (m_size == 0) { throw out_of_range(); }
        return m_front_link->m_next->m_value;
    }

    template<typename T>
    T& List<T>::back()
    {
        if (m_size == 0) { throw out_of_range(); }
        return m_back_link->m_prev->m_value;
    }

    template<typename T>
    void List<T>::clear()
    {
        Link<T>* elem = m_front_link->m_next;
        for (size_t i = 0; i < m_size; i++)
        {
            elem->m_value = 0;
            elem = elem->m_next;
        }
    }

    template<typename T>
    void List<T>::push_front(const T value)
    {
        Link<T>* new_link = new Link<T>;
        new_link->m_value = value;
        new_link->m_prev = m_front_link;
        new_link->m_next = m_front_link->m_next;

        m_front_link->m_next->m_prev = new_link;
        m_front_link->m_next = new_link;

        m_size++;
    }

    template<typename T>
    void List<T>::push_back(const T value)
    {
        Link<T>* newLink = new Link<T>;
        newLink->m_value = value;
        newLink->m_prev = m_back_link->m_prev;
        newLink->m_next = m_back_link;

        m_back_link->m_prev->m_next = newLink;
        m_back_link->m_prev = newLink;

        m_size++;
    }

    template<typename T>
    void List<T>::pop_front()
    {
        if (empty()) { return; }

        Link<T>* tmp = m_front_link->m_next;
        tmp->m_next->m_prev = m_front_link;
        m_front_link->m_next = tmp->m_next;
        m_size--;

        delete tmp;
    }

    template<typename T>
    void List<T>::pop_back()
    {
        if (empty()) { return; }

        Link<T>* tmp = m_back_link->m_prev;
        tmp->m_prev->m_next = m_back_link;
        m_back_link->m_prev = tmp->m_prev;
        m_size--;

        delete tmp;
    }
}

#endif /* EMBLATE_LIST_H */
