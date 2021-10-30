#include "vector.hpp"
#include <vector>
#include <iostream>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define FALSE 0

template<class T>
void print_vector(NAMESPACE::vector<T> the_vector)
{
    std::cout << "size : " << the_vector.size() << std::endl;
    std::cout << "max_size : " << the_vector.max_size() << std::endl;
    std::cout << "capacity : " << the_vector.capacity() << std::endl;
    std::cout << "empty : " << the_vector.empty() << std::endl;
    if (the_vector.empty() == FALSE)
    {
        std::cout << "front_value " << the_vector.front() << std::endl;
        // std::cout << the_vector.back() << std::endl;
    }
};

int main()
{
    NAMESPACE::vector<int> myvector;
    print_vector<int>(myvector);
    for (int i=0; i<100; i++)
    {
        print_vector<int>(myvector);
        myvector.push_back(i);
        std::cout << myvector[i] << std::endl;
    }

    // NAMESPACE::vector<int>::iterator it_begin = myvector.begin();
    // for (int i=0; i<10; i++)
    // {
    //     //print_vector<int>(myvector);
    //     //myvector.erase(it_begin);
    // }
}