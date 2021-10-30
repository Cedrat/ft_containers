#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
/* 
    Break meanwhile i create my ft_vector 
*/
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
        typedef typename ft::iterator_traits<Iterator>::difference_type       difference_type;
        typedef typename ft::iterator_traits<Iterator>::value_type            value_type;
        typedef typename ft::iterator_traits<Iterator>::pointer               pointer;             
        typedef typename ft::iterator_traits<Iterator>::reference             reference;  
        typedef typename ft::iterator_traits<Iterator>::iterator_category     iterator_category;

        reverse_iterator()
        {

        };
        explicit reverse_iterator(iterator_type it) : _current(it)
        {
        
        };
        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter>& reverse_it) : _current(reverse_it)
        {

        };

        iterator_type base() const
        {
            iterator_type temp = _current;
            return (--temp);
        }

        reference operator*() const
        {
            Iterator temp = _current;
            return (*temp);
        }

        reverse_iterator operator+ (difference_type n) const
        {
            _current += n;
            return (_current);
        };

        reverse_iterator& operator++()
        {
            //iterator_type temp = base();
            ++_current;
            return (*this);
        };
        
        reverse_iterator operator++ (int) //Post increment
        {
            reverse_iterator temp = (*this);
            ++_current;
            return (temp);
        };

        reverse_iterator& operator--()
        {
            --_current;
            return (*this);
        };
        
        reverse_iterator operator-- (int) 
        {
            reverse_iterator temp = (*this);
            --_current;
            return (temp);
        };
};

template <class Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() != rhs.base());
}





}

#endif