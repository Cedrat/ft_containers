#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include "test_function.hpp"
#include "pair.hpp"
#include "list"
#include "iterator_traits.hpp"
#include "iterator"

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename NAMESPACE::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename NAMESPACE::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}
 
int main()
{
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        my_reverse(v.begin(), v.end());
        for (int n : v) {
            std::cout << n << ' ';
        }
        std::cout << '\n';
    
        std::list<int> l{1, 2, 3, 4, 5};
        my_reverse(l.begin(), l.end());
        for (int n : l) {
            std::cout << n << ' ';
        }
        std::cout << '\n';
        std::cout << '\n';
    }
 
//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    my_reverse(i1, i2); // compilation error
    {
        typedef NAMESPACE::iterator_traits<int*> traits;
        if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
            std::cout << "int* is a random-access iterator";
        return 0;
    }
}