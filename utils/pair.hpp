#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{


    template<class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;
        pair()
        {};
        pair(const pair<first_type, second_type>&pair_) : first(pair_.first), second(pair_.second)
        {
        }
        
        pair(first_type first_element, second_type second_element) :
            first(first_element), second(second_element)
        {

        };

        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
        {
        }

        pair &operator=(const pair &rhs)
        {
            first = rhs.first;
            second = rhs.second;

            return (*this);
        };
    };

template< class T1, class T2 >
pair<T1,T2> make_pair(T1 first, T2 second)
{
    pair<T1, T2> ret_value(first, second);
    return ret_value;
};

template< class T1, class T2 >
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    if ((lhs.second == rhs.second) && (lhs.first == rhs.first))
        return true;
    return false;
}

template< class T1, class T2 >
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (!(lhs == rhs));
}

template< class T1, class T2 >
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    if (lhs.first < rhs.first)
    {
        return (true);
    }
    else if (lhs.first > rhs.first)
    {
        return (false);
    }
    else if (lhs.second < rhs.second)
    {
        return (true);
    }
    return (false);
};

template< class T1, class T2 >
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return ((rhs < lhs) == false);
};

template< class T1, class T2 >
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (rhs < lhs);
};

template< class T1, class T2 >
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return ((rhs > lhs) == false);
};






};

#endif
