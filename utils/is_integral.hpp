#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include "remove_cv.hpp"

namespace ft
{
    template <class T, T v>
    struct integral_constant
    {
        static const    T value = v;
        
        typedef T value_type;
        typedef integral_constant<T,v> type;
        
        const T operator()() const
        {
            return value; 
        }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
    
    template< class T >
    struct is_integral_no_cv : public false_type
    {};
    
    template<class T>
    struct is_integral : public is_integral_no_cv<typename remove_cv<T>::type>
    {};

    template<>
    struct is_integral_no_cv<bool> : public true_type
    {};

    template<>
    struct is_integral_no_cv<char> : public true_type
    {};

    template<>
    struct is_integral_no_cv<wchar_t> : public true_type
    {};

    template<>
    struct is_integral_no_cv<signed char> : public true_type
    {};

    template<>
    struct is_integral_no_cv<short int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<long int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<long long int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<unsigned char> : public true_type
     {}; 	

    template<>
    struct is_integral_no_cv<unsigned short int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<unsigned int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<unsigned long int> : public true_type
    {};

    template<>
    struct is_integral_no_cv<unsigned long long int> : public true_type
     {};

}

#endif
