#include <type_traits>

namespace ft
{
    /*
        enable_if

        As i understand, the first struct search an other than correspond a the use of the first.
        if no, no type can be declared and invoke a compilation error.
        example of use :
        template <class T>

        typename ft::enable_if<std::is_trivially_copyable<T>::value>::type f(T) {
        }

        if std::is_trivially_copyable<T>::value is true, the enable_if checked the second struct.
        and can give a type.
        if the value is false, no struct exist, and type doesnt exist.
    */

   template<bool B, class T = void>
    struct enable_if 
    {

    };

    template<class T>
    struct enable_if<true, T> 
    {
        typedef T type; 
    };
    /*
        Iterator traits
    */
    // template< class Iterator >
    // struct iterator_traits
    // {
    //     typedef difference_type     std::incrementable_traits<Iterator>::difference_type
    //     typedef value_type          Iterator::value_type;
    //     typedef pointer             Iterator::pointer;
    //     typedef reference           Iterator::reference;
    //     typedef iterator_category   Iterator::iterator_categorie;
    // };

}
