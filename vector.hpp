#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "random_access_iterator.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"

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



        
        T*  _array;
        
        size_type _capacity = 0;
        size_type _size = 0;
        size_type _max_size = 0;

        void reallocate(size_type new_capacity)
        {
            Alloc alloc;

            alloc.deallocate(_array, capacity());
            _capacity = new_capacity;
            _array = alloc.allocate(capacity() * sizeof(T*));
        }
    
    public :

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef random_access_iterator<value_type> iterator;
        typedef std::random_access_iterator_tag const_iterator; 

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
            _capacity = x.size();
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

        iterator begin()
        {
            return (iterator(_array));
        }

        const_iterator begin() const
        {
            return (begin());
        }

        iterator end()
        {
            return (iterator(_array + size()));
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

		void reserve (size_type n)
		{
			if (n > max_size())
				throw(std::length_error("ft::vector reserve max size exceeded"));
			if (n > capacity())
			{
				ft::vector<T> temp(*this);

                reallocate(n);
                for (size_t i = 0; i < temp.size(); i++) // in the future, use range of iterator 
                    _array[i] = temp[i];
			}
		}

        reference front()
        {
            return (_array[0]);
        }

        const_reference front() const
        {
            return front();
        }

        reference back()
        {
            return (_array[size() - 1]);
        }

        const_reference back() const
        {
            return back();
        }



        // template <class InputIterator, ft::enable_if<ft::is_integral<InputIterator>::value> = true>
        // void assign (InputIterator first, InputIterator last)
        // {
        //     while (first != last)
        //     {
        //         push_back(*first);
        //         first++;
        //     }
        // }
        // template <class InputIterator, typename ft::enable_if<InputIterator::iterator_category == iterator::iterator_category>>
        // void assign (InputIterator first, InputIterator last)
        // {
        //     while (first != last)
        //     {
        //         push_back(*first);
        //         first++;
        //     }
        // }

        void assign (size_type n, const T& val)
        {
            for (size_type i(0); i < n; i++)
            {
                push_back(val);
            }
        }

        void push_back(const value_type& val)
        {
            if ((size() + 1) > (capacity()))
            {
                if (capacity() == 0)
                {
                    reallocate(1);
                }
                else
                {
					reserve(capacity() * 2);
                }
            }
            _array[_size] = val;
            _size++;
        }
        void pop_back()
        {
            _array[_size] = T();
            _size--;
        }


        void resize (size_type n, value_type val = value_type())
        {
            if (n < size())
            {
                while (n < size())
                    pop_back();
            }
            if (n > size())
            {
				while (n > size())
					push_back(val);
            }
        }

        reference operator[] (size_type n)
        {
            return (_array[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return (_array[n]);
        }
		reference at (size_type n)
		{
			if (n < 0 || n >= size())
				throw (std::out_of_range("ft::vector at out_of_range"));
			return (_array[n]);
		}
		const_reference at (size_type n) const
		{
			return at(n);
		}
        vector& operator= (const vector& current)
        {
            ft::vector<T> new_vector(current);

            return (new_vector);
        }
};

};

#endif