#include <memory>
#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{

    ft::vector<int> test;

    test.push_back(6);
    test.push_back(6);
    test.push_back(6);

    ft::vector<int>::iterator it_begin = test.begin();
    ft::vector<int>::iterator it_end = test.end();
    std::cout << it_begin - it_end  << std::endl;
}