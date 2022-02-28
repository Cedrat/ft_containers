#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <string>
#include "random_access_iterator.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "reverse_iterator.hpp"
#include "../utils/ft_distance.hpp"
#include "../utils/iterator_tags.hpp"


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
            if (new_capacity == 0)
                new_capacity = 1;
            if (never_allocated == false)
            {
                for (size_t i = 0; i < _size; i++)
                {
                    alloc.destroy(&_array[i]);
                }
                alloc.deallocate(_array, capacity());
            }
            _capacity = new_capacity;
            _array = alloc.allocate(capacity());
        }
        template<class Iterator>
        void assign(Iterator first, Iterator last, ft::false_type)
        {
            Alloc alloc;
            size_t temp;
            size_type old_size = _size;

            temp = ft::distance(first, last);
            bool realloc = false;
            if (temp > _capacity)
            {
                reallocate(temp);
                realloc = true;
            }
            size_type i(0);
            while (first != last)
            {
                 if (i < old_size && realloc == false)
                    alloc.destroy(&_array[i]);
                alloc.construct(&_array[i], *first);
                first++;
                i++;
            }
            while (i < old_size)
            {
                alloc.destroy(&_array[i]);
                i++;
            }
            _size = temp;

        }

        void assign(size_type n, const T& val, ft::true_type)
        {
            Alloc alloc;
            size_type old_size = _size;
            if (n > _capacity)
                reallocate(n);

            size_type i(0);
            while (i < n)
            {
                if (i < old_size)
                    alloc.destroy(&_array[i]);
                alloc.construct(&_array[i], val);
                i++;
            }
            while (i < old_size)
            {
                alloc.destroy(&_array[i]);
                i++;
            }
            _size = n;
        }

        void insert (iterator position, size_type n, const value_type& val,  ft::true_type)
        {
            size_t range;

            long temp_pos;
            Alloc alloc;
            
            long end_old_vector = end() - begin();
            range = n;
            long end_new_vector = end_old_vector + range;

            int nb_element_to_switch = end() - position;
            temp_pos = position - begin() + range;
            if ((_size + range) > _size)
            {
                resize(_size + range);
            }
            size_t i = 0;
            if (end_old_vector == 0)
            {
                while (i < range)
                {
                    _array[i] = val;
                    i++;
                }
                return ;
            }
            int temp_range = range;

            while (nb_element_to_switch)
            {
                _array[end_new_vector - 1] = _array[end_old_vector - i - 1];
                nb_element_to_switch--;
                end_new_vector--;
                i++;
            }
            temp_range -= i;
            while (temp_range > 0)
            {
                n--;
                _array[end_new_vector - 1] =  val;
                temp_range--;
                end_new_vector--;
            }
            while (n)
            {
                n--;
                _array[end_new_vector - 1] = val;
                end_new_vector--;
            }
        }


        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, ft::false_type)
        {
            size_t range;

            long temp_pos;
            Alloc alloc;
            
            long end_old_vector = end() - begin() - 1;
            range = ft::distance(first, last);
            long end_new_vector = end_old_vector + range;

            int nb_element_to_switch = end() - position;
            temp_pos = position - begin() + range;
            if ((_size + range) > _size)
            {
                resize(_size + range);
            }
            size_t i = 0;
            if (end_old_vector == 0)
            {
                while (i < range)
                {
                    _array[i] = *first;
                    first++;
                    i++;
                }
                return ;
            }
            int temp_range = range;

            while (nb_element_to_switch)
            {
                _array[end_new_vector] = _array[end_old_vector - i];
                nb_element_to_switch--;
                end_new_vector--;
                i++;
            }
            temp_range -= i;
            while (temp_range > 0)
            {
                last--;
                _array[end_new_vector] =  *last;
                temp_range--;
                end_new_vector--;
            }
            while (first != last)
            {
                last--;
                _array[end_new_vector] = *last;
                end_new_vector--;
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
            for (size_t i = 0; i < _size ; i++)
            {
                alloc.destroy(&_array[i]);
            }
            alloc.deallocate(_array, capacity());
        }


        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()));
        }

        const reverse_iterator rbegin() const
        {
            return (reverse_iterator(end()));
        }
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
            return (reverse_iterator(begin()));
        }

        const reverse_iterator rend() const
        {
            return (reverse_iterator(begin()));
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
            if (n == 0)
                n = 1;
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
            Alloc alloc;

            alloc.destroy(&_array[_size - 1]);
            _size--;
        }



        iterator insert (iterator position, const value_type& val)
        {
            long temp_pos;
            Alloc alloc;
            
            temp_pos = position - begin();
            long end_vector = end() - begin();
            if (_size == _capacity)
            {
                reserve(_capacity * 2);
            }
            if (temp_pos == end() - begin())
            {
                 alloc.construct(&_array[end_vector], val);
                _size++;
                return (temp_pos + begin());
            }
            if (end_vector == 0)
            {
                alloc.construct(&_array[end_vector], val);
                _size++;
                return (temp_pos + begin());
            }
            alloc.construct(&_array[end_vector], _array[end_vector - 1]);
            end_vector--;
            while (temp_pos < end_vector)
            {
                _array[end_vector] = _array[end_vector - 1];
                end_vector--;
            }
            _array[end_vector] = val;
            _size++;
            return (temp_pos + begin());
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            insert(position, n, val, ft::true_type());
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

            while (first != last)
            {
                last--;
                erase(last);
            }
            return (temp);
            
        }

        void swap (vector &swapped)
        {
            T* temp_array;
            Alloc alloc;
            size_t temp_size;
            bool temp_never_alloc;

            temp_array = swapped._array;
            swapped._array = _array;
            _array = temp_array;

            temp_size = swapped._size;
            swapped._size = _size;
            _size = temp_size;

            temp_size = swapped._capacity;
            swapped._capacity = _capacity;
            _capacity = temp_size;

            temp_never_alloc = swapped.never_allocated;
            swapped.never_allocated = never_allocated;
            never_allocated = temp_never_alloc;

            temp_size = swapped._max_size;
            swapped._max_size = _max_size;
            _max_size = temp_size;
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