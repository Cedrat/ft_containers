#ifndef TEST_FUNCTION_HPP
# define TEST_FUNCTION_HPP

#include <iostream>

#define EMOJI_TRUE "\U00002705"
#define  EMOJI_FALSE "\U0000274C"

template<class T>
void verify_equality(T test1, T test2)
{
    if (test1 == test2)
        std::cout << EMOJI_TRUE << std::endl;
    else
        std::cout << EMOJI_FALSE << std::endl;
}

#endif