#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "random_access_iterator.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include "reverse_iterator.hpp"
#include "ft_distance.hpp"


#define FALSE 0
#define TRUE 1

namespace ft
{

template <class T, class Alloc = std::allocator<T> > 
class vector
{
      public :

        typedef T value_type;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef random_access_iterator<value_type> iterator;
        typedef const_random_access_iterator<value_type> const_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
        typedef std::ptrdiff_t difference_type;

    private :
        
        T*  _array;
        
        size_type _capacity ;
        size_type _size ;
        size_type _max_size ;
        bool      never_allocated;

        void reallocate(size_type new_capacity)
        {
            Alloc alloc;
            if (never_allocated == false)
                alloc.deallocate(_array, capacity());
            _capacity = new_capacity;
            _array = alloc.allocate(capacity());

        }
        template<class Iterator>
        void assign(Iterator first, Iterator last, ft::false_type)
        {
            Alloc alloc;
            _size = ft::distance(first, last);
            if (_size > _capacity)
                reallocate(_size);
            int i(0);
            while (first != last)
            {
                alloc.construct(&_array[i], *first);
                first++;
                i++;
            }

        }

        void assign(size_type n, const T& val, ft::true_type)
        {
             Alloc alloc;
            if (n > _capacity)
                reallocate(n);
            for (size_type i(0); i < n; i++)
            {
                alloc.construct(&_array[i], val);
            }
            _size = n;
        }

        void insert (iterator position, size_type n, const value_type& val,  ft::true_type)
        {
            size_t pos;
            pos = position - begin();
            if ((_size + n) > _capacity)
            {
                _capacity = _size + n;
                reserve(_capacity);
            }
            
            iterator it_end = end();
            _size+=n;
            while ((position) != (it_end))
            {
                _array[it_end - begin() + n - 1] = *(it_end - 1);
                it_end--;
            }
            for (size_t i = 0; i < pos; i++)
            {
                _array[i] = *(begin() + i);
            }   
            for (size_t i = 0; i < n; i++)
            {
                _array[pos + i] = val; 
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, ft::false_type)
        {
            size_t pos;
            size_t range;

            range = ft::distance(first, last);
            pos = position - begin();
            if ((_size + range) > _capacity)
            {
                _capacity = _size + range;
                reserve(_capacity);
            }
            
            iterator it_end = end();
            _size+=range;
            while ((position) != (it_end))
            {
                _array[it_end - begin() + range - 1] = *(it_end - 1);
                it_end--;
            }
            for (size_t i = 0; i < pos; i++)
            {
                _array[i] = *(begin() + i);
            }
            for (size_t i = 0; i < range; i++)
            {
                _array[pos + i] = *first;
                first++; 
            }
        }
    
        void initialize()
        {
            _capacity = 0;
            _size = 0;
            _max_size = 0;
            never_allocated = false;
            _array = NULL;
        }

    public :

        vector ()
        {
            initialize();
             Alloc alloc;
            _array = alloc.allocate(0);
            _max_size = alloc.max_size();
        }

        vector (size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type())
        {
            initialize();
            never_allocated = true;
            assign(n, val);
            never_allocated = false;
            _capacity = _size;
            _max_size = alloc.max_size();
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type())
        {
            initialize();
            never_allocated = true;
            assign(first, last);
            never_allocated = false;
            _capacity = _size;
            _max_size = alloc.max_size();
        }
        vector (const vector& x)
        {
            initialize();
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


        reverse_iterator rbegin()
        {
            return (reverse_iterator(_array + size() - 1));
        }

        // const_reverse_iterator rbegin() const
        // {
        //     return (iterator(_array));
        // }
        iterator begin()
        {
            return (iterator(_array));
        }

        const_iterator begin() const
        {
            return (const_iterator(_array));
        }

        iterator end()
        {
            return (iterator(_array + size()));
        }

        const_iterator end() const
        {
             return (const_iterator(_array + size()));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(_array - 1));
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
            Alloc alloc;
			if (n > max_size())
				throw(std::length_error("ft::vector reserve max size exceeded"));
			if (n > capacity())
			{
				ft::vector<T> temp(*this);

                reallocate(n);
                for (size_t i = 0; i < temp.size(); i++) // in the future, use range of iterator 
                {
                    alloc.construct(&_array[i], temp[i]);
                }
			}
		}

        reference front()
        {
            return (_array[0]);
        }

        const_reference front() const
        {
            return (_array[0]);
        }

        reference back()
        {
            return (_array[size() - 1]);
        }

        const_reference back() const
        {
            return (_array[size() - 1]);
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
            Alloc alloc;
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
            alloc.construct(&_array[_size], val);
            _size++;
        }
        void pop_back()
        {
            _array[_size] = T();
            _size--;
        }

        iterator insert (iterator position, const value_type& val)
        {
            size_t temp_pos;
            iterator temp = position;
            temp_pos = position - begin(); // == 0
            if (_size == _capacity)
            {
                reserve(_capacity * 2);
            }
            _size++;
            iterator it_end = end() - 1;
            while (position  != it_end)
            {
                _array[it_end - begin() + 1] = *it_end;
                it_end--;
            }
            _array[temp_pos] = val;
            

            return (temp);
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            size_t pos;
            pos = position - begin();
            if ((_size + n) > _capacity)
            {
                _capacity = _size + n;
                reserve(_capacity);
            }
            
            iterator it_end = end();
            _size+=n;
            while ((position) != (it_end))
            {
                _array[it_end - begin() + n - 1] = *(it_end - 1);
                it_end--;
            }
            for (size_t i = 0; i < pos; i++)
            {
                _array[i] = *(begin() + i);
            }
            for (size_t i = 0; i < n; i++)
            {
                _array[pos + i] = val; 
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
            insert(position, first, last, ft::is_integral<InputIterator>());
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

        iterator erase (iterator position)
        {
            iterator it_end = end();
            iterator temp = position;
            Alloc alloc;

            while (temp != (it_end - 1))
            {
                _array[temp - begin()] = *(temp + 1); 
                temp++;
            }
            alloc.destroy(&_array[temp - begin()]);
            _size--;
            return (position);
        }

        iterator erase (iterator first, iterator last)
        {
            iterator temp = first;
            size_t range = last - first;
            iterator it_end = end();
            _size -= range;
            if (last == it_end)
                return (end());
            while (first != (it_end))
            {
                _array[first - begin()] = *(first + range);
                first++;
            }
            return (temp);
        }

        void swap (vector &swapped)
        {
            vector<T> temp(swapped);

            swapped.reallocate(this->capacity());
            swapped = vector<T>(*this);
            this->reallocate(temp.capacity());
            *this = temp;
        }

        void clear()
        {
            while(_size)
            {
                Alloc alloc;
                alloc.destroy(&_array[_size - 1]);
                _size--;
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
			if (n < 0 || n >= size())
				throw (std::out_of_range("ft::vector at out_of_range"));
			return (_array[n]);
		}
        vector& operator= (const vector& current)
        {
            // reallocate(current.capacity());
            this->assign(current.begin(), current.end());

            return (*this);
        }

        allocator_type get_allocator() const
        {
            return (Alloc());
        }
};
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
        {
            for (size_t i = 0; i < lhs.size() ; i++)
            {
                if (lhs[i] != rhs[i])
                    return (false);
            }
        }
        else
            return (false);
        return (true);
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T, class Alloc>
    bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    
    template <class T, class Alloc>
    bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs > lhs));
    }
    
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

};

#endif