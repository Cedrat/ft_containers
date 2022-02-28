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
    
    


    std::reverse_iterator<std::vector<int>::iterator> std_rev_it_begin;


    std_rev_it_begin = myvector.rbegin();
    NAMESPACE::reverse_iterator<std::reverse_iterator<std::vector<int>::iterator>> rev_it_begin(std_rev_it_begin);

    std::cout << *rev_it_begin << std::endl;
    std::cout << *rev_it_begin++ << std::endl;
    std::cout << *++rev_it_begin << std::endl;

}