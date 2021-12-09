#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

/*
    Check if the first input is smaller lexicographically than the second.
    return true if is verified.
    Equality between the two inputs lead to false.
*/

template <class Iterator1, class Iterator2>
bool lexicographical_compare (Iterator1 start1, Iterator1 end1,
                            Iterator2 start2, Iterator2 end2)
{
    while (start1 != end1)
    {
        if (start2 == end2)
        {
            return false;
        }
        else if (*start1 < *start2)
        {
            return true;
        }
        else if (*start1 > *start2)
        {
            return false;
        }
        else if (start2 == end2)
        {
            return false;
        }
        start1++;
        start2++;
    }
    if (start2 != end2)
        return(true);
    return (false);
};
template <class Iterator1, class Iterator2, class Compare>
bool lexicographical_compare (Iterator1 start1, Iterator1 end1,
                            Iterator2 start2, Iterator2 end2, Compare comp)
{
    while (start1 != end1)
    {
        if (start2 == end2)
        {
            return false;
        }
        else if (comp(*start1, *start2))
        {
            return true;
        }
        else if (comp(*start2, *start1) == true)
        {
            return false;
        }
        else if (start2 == end2)
        {
            return false;
        }
        start1++;
        start2++;
    }
    if (start2 != end2)
        return(true);
    return (false);
}







}


#endif