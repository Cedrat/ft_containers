#include <vector>
#include <iostream>
#include <iterator>
#include "is_integral.hpp"



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