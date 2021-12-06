#ifndef REVERSE_MAP_ITERATOR
# define REVERSE_MAP_ITERATOR

#include "map_iterator.hpp"

namespace ft
{
/*
    This class reverses the direction in which a iterator
    iterates trough a range.
*/

    template <class Iterator>
    class reverse_map_iterator
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
            typedef const reference const_reference;
            typedef const value_type const_value_type;
            typedef const pointer const_pointer;
            


            reverse_map_iterator()
            {
            };

            reverse_map_iterator(iterator_type it) : _current(it)
            {
                // _current--;
            };

            // reverse_map_iterator(iterator_type it) : _current(it)
            // {

            // };
        
            template<class Iter>
            reverse_map_iterator(const reverse_map_iterator<Iter>& reverse_it) : _current(reverse_it.base())
            {
            };
             
             iterator_type base() const
            {
                return (_current) ;
            }

            value_type operator*()
            {
                // iterator_type temp = base();
                return (*_current);
            }

            // const_value_type operator*() const
            // {
            //     // iterator_type temp = base();
            //     return (*_current);
            // }



            // const pointer operator->() const
            // {
            //     return (&(*_current));
            // }


            pointer operator->()
            {
                    return (_current.operator->());
            }


            // const_pointer operator->() const
            // {
            //         return (const_cast<const_pointer>(_current.operator->()));
            // }

            reverse_map_iterator& operator++()
            {
                //iterator_type temp = base();
                --_current;
                return (*this);
            };

            reverse_map_iterator operator++ (int) //Post increment
            {
                reverse_map_iterator temp = (*this);
                --_current;
                return (temp);
            };

            reverse_map_iterator& operator--()
            {
                ++_current;
                return (*this);
            };
            
            reverse_map_iterator operator-- (int) 
            {
                reverse_map_iterator temp = (*this);
                ++_current;
                return (temp);
            };  
    };

};
#endif