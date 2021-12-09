#ifndef FT_DISTANCE_HPP
# define FT_DISTANCE_HPP  

#include "iterator_traits.hpp"  
#include "iterator_tags.hpp"

namespace ft
{   
    
    template<class InputIterator>
    long do_distance (InputIterator first, InputIterator last, std::random_access_iterator_tag)
    {
        return (last - first);
    }

    template<class InputIterator>
    long do_distance (InputIterator first, InputIterator last, random_access_iterator_tag)
    {
        return (last - first);
    }

    template<class InputIterator>
    long do_distance (InputIterator first, InputIterator last, std::input_iterator_tag)
    {
        int sum(0);
        while (first != last)
        {
            first++;
            sum++;
        }
        return (sum);
    }

    template<class InputIterator>
    long do_distance (InputIterator first, InputIterator last, input_iterator_tag)
    {
        int sum(0);
        while (first != last)
        {
            first++;
            sum++;
        }
        return (sum);
    }

    template<class InputIterator>
    long distance (InputIterator first, InputIterator last)
    {
        
        return (do_distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category()));
    };

}

#endif