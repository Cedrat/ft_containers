#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

#define FALSE 0
#define TRUE 1

namespace ft
{

template <class T, class Alloc = std::allocator<T>> 
class vector
{
    private :
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        
        T*  _array;
        
        size_type _capacity = 0;
        size_type _size = 0;
        size_type _max_size = 0;
    
    public :
        explicit vector ()
        {
             Alloc alloc;
            _array = alloc.allocate(sizeof(T*) * 0);
            _max_size = alloc.max_size();
        }

        vector (const vector& x)
        {
            Alloc alloc;
            _array = alloc.allocate(sizeof(T*) * x.size());
            _capacity = x.capacity();
            _max_size = alloc.max_size();
            for (size_t i = 0; i < x.size(); i++) // in the future, use range of iterator 
            {
                push_back(x[i]);
            }
        }

        ~vector()
        {
            Alloc alloc;
            alloc.deallocate(_array, capacity());
        }

        size_type capacity() const
        {
            return(_capacity);
        }

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (_max_size);
        }

        bool empty() const
        {
            return (_size == FALSE);
        }

        reference front()
        {
            return (_array[0]);
        }
        const_reference front() const
        {
            return front();
        }

        void push_back(const value_type& val)
        {
            if ((max_size() + 1) > (capacity()))
            {
                Alloc alloc;
                if (capacity() == 0)
                {
                    alloc.deallocate(_array, 0);
                    _array = alloc.allocate(1);
                    _capacity = 1;
                }
                else
                {

                }
            }
            _array[_size] = val;
            _size++;
        }

        reference operator[] (size_type n)
        {
            return (_array[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return (_array[n]);
        }
};


};

#endif