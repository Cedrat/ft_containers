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
            if (capacity() != 0)
                alloc.deallocate(_array, capacity());
            _capacity = new_capacity;
            _array = alloc.allocate(capacity());
        }
        template<class Iterator>
        void assign(Iterator first, Iterator last, ft::false_type)
        {
            reallocate(last - first);
            _size = (last - first);
            int i(0);
            while (first != last)
            {
                _array[i] = *first;
                first++;
                i++;
            }

        }

        void assign(size_type n, const T& val, ft::true_type)
        {
            reallocate(n);
            for (size_type i(0); i < n; i++)
            {
                _array[i] = val;
            }
            _size = n;
        }
    
    public :

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef random_access_iterator<value_type> iterator;
        typedef random_access_iterator<value_type> const_iterator;
        typedef std::ptrdiff_t difference_type;

        explicit vector ()
        {
             Alloc alloc;
            _array = alloc.allocate(sizeof(T*) * 0);
            _max_size = alloc.max_size();
        }

        explicit vector (size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type())
        {
            assign(n, val);
            _capacity = _size;
            _max_size = alloc.max_size();
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type())
        {
            assign(first, last);
            _capacity = _size;
            _max_size = alloc.max_size();
        }
        vector (const vector& x)
        {
            Alloc alloc;
            _array = alloc.allocate(x.size());
            _capacity = x.size();
            _max_size = alloc.max_size();
            assign(x.begin(), x.end());
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
            return (iterator(_array));
        }

        iterator end()
        {
            return (iterator(_array + size()));
        }

        const_iterator end() const
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




        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            assign(first, last, ft::is_integral<InputIterator>());
        }

        void assign (size_type n, const T& val)
        {
            assign(n, val, true_type());
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

        iterator insert (iterator position, const value_type& val)
        {
            size_t pos;
            iterator temp = position;
            if (_size == _capacity)
            {
                std::cout << "REALLOC" << std::endl;
                reserve(_capacity * 2);
            }
            pos = position - begin();

            while (position != end())
            {
                std::cerr << position - begin() << std::endl;
                _array[position - begin()] = *position;
                position++;
            }
            _array[pos] = val;
            _size++;
            return (temp);
        }

        // void insert (iterator position, size_type n, const value_type& val)
        // {
        //     size_t pos;
        //     //iterator temp = position;
        //     if ((_size + n) > _capacity)
        //     {
        //         while ((_size + n) > _capacity)
        //         {
        //             _capacity *=2;
        //         }
        //         reserve(_capacity);
        //     }
        //     pos = position - begin();

        //     while (position != end())
        //     {
        //         _array[end() - position + n] = *position;
        //         position++;
        //     }
        //     for (size_t i = 0; i < n; i++)
        //     {
        //         _array[pos + i] = val; 
        //     }
        //     _size += n;
        // }


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