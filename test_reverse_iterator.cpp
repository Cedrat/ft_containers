#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "test_function.hpp"
#include "reverse_iterator.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft

#endif

int main () 
{

    std::cout << "test iterator constructor" << std::endl;
    std::vector<int> myvector;
    for (int i=2; i<10; i++) 
        myvector.push_back(i);
    
    

    //typedef std::vector<int>::reverse_iterator iter_type;

    std::reverse_iterator<std::vector<int>::iterator> std_it_begin;

    // NAMESPACE::reverse_iterator<std::vector<int>::iterator> rev_it_begin;

    std_it_begin = myvector.rbegin();
    NAMESPACE::reverse_iterator<std::reverse_iterator<std::vector<int>::iterator>> rev_it_begin(std_it_begin);

    std::cout << *rev_it_begin << std::endl;
    std::cout << *rev_it_begin++ << std::endl;
    std::cout << *++rev_it_begin << std::endl;
    // std::cout << *rev_it_begin << std::endl;
    // std::cout << *rev_it_begin.base() << std::endl;
                                                            
    // iter_type from (myvector.begin());                     
                                                            
    // iter_type until (myvector.end());                      
                                                            
    // NAMESPACE::reverse_iterator<iter_type> rev_until (from);    
                                                            
    // NAMESPACE::reverse_iterator<iter_type> rev_from (until);

    // std::cout << "myvector:";
    // while (rev_from != rev_until)
    //     std::cout << ' ' << *rev_from++;
    // std::cout << '\n';

    // return 0;
}