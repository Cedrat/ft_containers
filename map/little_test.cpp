#include "map.hpp"
#include <iostream>

int main()
{
    ft::map<char, int> mymap;

    mymap['x']=100;
    ft::map<char,int>::iterator it=mymap.begin();

    std::cout << (*it).second << std::endl;
    std::cout << it->first << std::endl;
}