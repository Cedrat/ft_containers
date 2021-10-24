#ifndef TEST_FUNCTION_HPP
# define TEST_FUNCTION_HPP

#include <iostream>

template<class T>
void verify_equality(T test1, T test2)
{
    if (test1 == test2)
        std::cout << "\U00002705" << std::endl;
    else
        std::cout << "\U0000274C" << std::endl;
}

#endif