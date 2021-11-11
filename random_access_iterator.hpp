#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP


#include "iterator_tags.hpp"
namespace ft
{   
    template<class T>
    struct random_access_iterator
    {

        public :
            typedef random_access_iterator_tag iterator_category;
            typedef long difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;

            random_access_iterator()
            {
            }

            random_access_iterator(pointer ptr) : _ptr(ptr)
            {
            }
            
            // random_access_iterator& operator=(random_access_iterator &rhs)
            // {
            //     this->_ptr = rhs._ptr;
            //     return (*this);
            // }
            reference operator*() const
            {
                return (*_ptr);
            }

            pointer operator->()
            {
                return (_ptr);
            }

            const pointer operator->() const
            {
                return (_ptr);
            }

            // value_type operator[](int n) 
            // {
            //     return (_ptr[n]);
            // }

            reference operator[](int n) const
            {
                return (_ptr[n]);
            }

            random_access_iterator& operator++() //preincrement
            {
                _ptr++;
                return (*this);
            }

            random_access_iterator operator++(int)
            {
                random_access_iterator temp = *this;
                ++(*this);
                
                return (temp);
            }

             random_access_iterator& operator--() //preincrement
            {
                _ptr--;
                return (*this);
            }

            random_access_iterator & operator +=(int increment)
            {
                _ptr = _ptr + increment;
                return (*this); 
            }

            random_access_iterator & operator -=(int decrement)
            {
                _ptr = _ptr - decrement;
                return (*this); 
            }

            random_access_iterator operator +(int increment) const
            {
                random_access_iterator temp = _ptr + increment;
                return (temp); 
            }

            random_access_iterator operator -(int decrement) const 
            {
                random_access_iterator temp = _ptr - decrement;
                return (temp); 
            }

            // difference_type operator -(random_access_iterator second)
            // {
            //     return (_ptr - second._ptr); 
            // }

            random_access_iterator operator--(int)
            {
                random_access_iterator temp = *this;
                --(*this);
                
                return (temp);
            }

            friend difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr - rhs._ptr);
            }
            template<class Iterator>
            friend difference_type operator-(const Iterator &lhs, const Iterator &rhs)
            {
                return (lhs - rhs);
            }

            friend random_access_iterator operator+(const random_access_iterator<T>::difference_type &lhs, const random_access_iterator<T> &rhs)
            {
                return (rhs + lhs._ptr);
            }


            friend bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }
            
            friend bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr < rhs._ptr);
            }
            friend bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr > rhs._ptr);
            }
            friend bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr <= rhs._ptr);
            }
            friend bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
            {
                return (lhs._ptr >= rhs._ptr);
            }

            pointer _ptr;

            // pointer getPtr(
                
            // private :
    };

    template<class T>
    struct const_random_access_iterator
    {

        public :
            typedef random_access_iterator_tag iterator_category;
            typedef long difference_type;
            typedef const T value_type;
            typedef const T* pointer;
            typedef const T& reference;

            const_random_access_iterator()
            {
            }

            const_random_access_iterator(random_access_iterator<T> const & iterator) : _ptr(iterator._ptr)
            {
            }
            
            const_random_access_iterator(pointer ptr) : _ptr(ptr)
            {
            }
            
            // const_random_access_iterator& operator=(const const_random_access_iterator &rhs)
            // {
            //     this->_ptr = rhs._ptr;
            //     return (*this);
            // }

            const_random_access_iterator& operator=(const random_access_iterator<T> &rhs)
            {
                this->_ptr = rhs._ptr;
                return (*this);
            }

            reference operator*() const
            {
                return (*_ptr);
            }

            pointer operator->()
            {
                return (_ptr);
            }

            const pointer operator->() const
            {
                return (_ptr);
            }

            // value_type operator[](int n) 
            // {
            //     return (_ptr[n]);
            // }

            reference operator[](int n) const
            {
                return (_ptr[n]);
            }

            const_random_access_iterator& operator++() //preincrement
            {
                _ptr++;
                return (*this);
            }

            const_random_access_iterator operator++(int)
            {
                const_random_access_iterator temp = *this;
                ++(*this);
                
                return (temp);
            }

             const_random_access_iterator& operator--() //preincrement
            {
                _ptr--;
                return (*this);
            }

            const_random_access_iterator & operator +=(int increment)
            {
                _ptr = _ptr + increment;
                return (*this); 
            }

            const_random_access_iterator & operator -=(int decrement)
            {
                _ptr = _ptr - decrement;
                return (*this); 
            }

            const_random_access_iterator operator +(int increment) const
            {
                const_random_access_iterator temp = _ptr + increment;
                return (temp); 
            }

            const_random_access_iterator operator -(int decrement) const 
            {
                const_random_access_iterator temp = _ptr - decrement;
                return (temp); 
            }

            // difference_type operator -(const_random_access_iterator second)
            // {
            //     return (_ptr - second._ptr); 
            // }

            const_random_access_iterator operator--(int)
            {
                const_random_access_iterator temp = *this;
                --(*this);
                
                return (temp);
            }

            friend difference_type operator-(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr - rhs._ptr);
            }

            // friend difference_type operator+(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            // {
            //     return (lhs._ptr + rhs._ptr);
            // }


            friend bool operator!=(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }
            
            friend bool operator==(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator<(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr < rhs._ptr);
            }
            friend bool operator>(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr > rhs._ptr);
            }
            friend bool operator<=(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr <= rhs._ptr);
            }
            friend bool operator>=(const const_random_access_iterator<T> &lhs, const const_random_access_iterator<T> &rhs)
            {
                return (lhs._ptr >= rhs._ptr);
            }
            private :
                pointer _ptr;
    };

};

#endif