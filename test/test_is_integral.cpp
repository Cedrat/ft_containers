#include <vector>
#include <iostream>
#include <iterator>
#include "is_integral.hpp"


// template <class T>
//     typename ft::enable_if<std::is_trivially_copyable<T>::value>::type f(T) {
//       // ...
//    }
// int main() {
//    using std::vector;
//    vector<int> v;
//    f(v); // serait illégal
// }

// iterator_traits example
// #include <iostream>     // std::cout
// #include <iterator>     // std::iterator_traits
// #include <typeinfo>     // typeid

// int main() {
//   typedef ft::iterator_traits<int*> traits;
//   if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
//     std::cout << "int* is a random-access iterator";
//   return 0;
// }

#include <iostream>
#include <type_traits>

class A {};
 
enum E : int {};
 
template<class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}
 
int main() 
{
    {
        std::cout << std::is_integral<A>::value << '\n';
        std::cout << std::is_integral<E>::value << '\n';
        std::cout << std::is_integral<const E>::value << '\n';
        std::cout << std::is_integral<const volatile E>::value << '\n';
        std::cout << std::is_integral<float>::value << '\n';
        std::cout << std::is_integral<int &>::value << '\n';
        std::cout << std::is_integral<int *>::value << '\n';
        std::cout << std::is_integral<int>::value << '\n';
        std::cout << std::is_integral<int const>::value << '\n';
        std::cout << std::is_integral<const int>::value << '\n';
        std::cout << std::is_integral<const int>::value << '\n';
        std::cout << std::is_integral<volatile const int>::value << '\n';
        std::cout << std::is_integral<const volatile int>::value << '\n';
        std::cout << std::is_integral<bool>::value << '\n';
        std::cout << f(123) << '\n';
    }
    {
        std::cout << std::endl;
        std::cout << ft::is_integral<A>::value << '\n';
        std::cout << ft::is_integral<E>::value << '\n';
        std::cout << ft::is_integral<const E>::value << '\n';
        std::cout << ft::is_integral<const volatile E>::value << '\n';
        std::cout << ft::is_integral<float>::value << '\n';
        std::cout << ft::is_integral<int &>::value << '\n';
        std::cout << ft::is_integral<int *>::value << '\n';
        std::cout << ft::is_integral<int>::value << '\n';
        std::cout << ft::is_integral<int const>::value << '\n';
        std::cout << ft::is_integral<const int>::value << '\n';
        std::cout << ft::is_integral<const int>::value << '\n';
        std::cout << ft::is_integral<volatile const int>::value << '\n';
        std::cout << ft::is_integral<const volatile int>::value << '\n';
        std::cout << ft::is_integral<bool>::value << '\n';
        std::cout << f(123) << '\n';
    }
}