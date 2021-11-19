#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "ft_distance.hpp"

namespace ft
{
/*
    This class reverses the direction in which a iterator
    iterates trough a range.
*/

template <class Iterator>
class reverse_iterator
{
    protected :
        Iterator _current;
    public : 
        typedef          Iterator                                             iterator_type;
        // typedef typename ft::reverse_iterator<const Iterator>                 const_reverse_iterator;
        typedef typename ft::iterator_traits<Iterator>::difference_type       difference_type;
        typedef typename ft::iterator_traits<Iterator>::value_type            value_type;
        typedef typename ft::iterator_traits<Iterator>::pointer               pointer;             
        typedef typename ft::iterator_traits<Iterator>::reference             reference;  
        typedef typename ft::iterator_traits<Iterator>::iterator_category     iterator_category;

        reverse_iterator()
        {

        };

        reverse_iterator(iterator_type it) : _current(it)
        {

        };
    
        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter>& reverse_it) : _current(reverse_it.base())
        {

        };



        iterator_type base() const
        {
            return (_current) ;
        }

        reference operator*() const
        {
            // iterator_type temp = base();
            return (*(_current - 1));
        }

        const pointer operator->() const
        {
                return (&(operator*()));
        }


        reference operator[] (difference_type n) const
        {
            return (_current[-n - 1]);
        }

        reverse_iterator operator+ (int n) const
        {
            reverse_iterator temp = _current - n;
            return (temp);
        };


        reverse_iterator operator- (int n) const
        {

            reverse_iterator temp =  _current + n;
            return (temp);
        };

        reverse_iterator& operator++()
        {
            //iterator_type temp = base();
            --_current;
            return (*this);
        };
        
        reverse_iterator operator++ (int) //Post increment
        {
            reverse_iterator temp = (*this);
            --_current;
            return (temp);
        };
        reverse_iterator & operator +=(int increment)
        {
            _current -= increment;
            return (*this); 
        }

        reverse_iterator &operator -=( int decrement)
        {
            _current += decrement;
            return (*this); 
        }

        reverse_iterator& operator--()
        {
            ++_current;
            return (*this);
        };
        
        reverse_iterator operator-- (int) 
        {
            reverse_iterator temp = (*this);
            ++_current;
            return (temp);
        };  
};

template <class Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator- (
    const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs)
    {
        return (rhs.base() - lhs.base());
    }


template <class Iterator1, class Iterator2 >
bool operator!= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator== (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator> (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator< (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs)
{
    return (lhs.base() > rhs.base());
}







}

#endif