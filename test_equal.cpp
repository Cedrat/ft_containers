#include <vector>
#include <iostream>
#include <iterator>
#include "is_integral.hpp"
#include "equal.hpp"
#include "test_function.hpp"

bool mycomp (char c1, char c2)
{ 
    return std::tolower(c1)<std::tolower(c2);
}

int main () 
{
    {
        char foo[]="apple";
        char bar[]="apartment";

        std::cout << "Test lexicographical without func comp\n" << std::endl;
        verify_equality(std::equal(foo,foo+5,bar), ft::equal(foo,foo+5,bar));
        verify_equality(std::equal(foo,foo,bar), ft::equal(foo,foo,bar));
        verify_equality(std::equal(foo,foo + 1,bar), ft::equal(foo,foo + 1,bar)); 
        verify_equality(std::equal(foo,foo + 1,bar), ft::equal(foo,foo + 1,bar));
        verify_equality(std::equal(foo,foo + 6,foo), ft::equal(foo,foo + 6,foo)); 
        verify_equality(std::equal(foo,foo + 6,foo), ft::equal(foo,foo + 6,foo));
        verify_equality(std::equal(foo,foo + 5,foo), ft::equal(foo,foo + 5,foo));
        std::cout << '\n';
    }

    {
        char foo[]="ApPleer";
        char bar[]="applees";

        std::cout << "Test lexicographical with function comp\n" << std::endl;
        verify_equality(std::equal(foo,foo+5,bar, mycomp), ft::equal(foo,foo+5,bar, mycomp));
        verify_equality(std::equal(foo,foo,bar, mycomp), ft::equal(foo,foo,bar, mycomp));
        verify_equality(std::equal(foo,foo + 1,bar, mycomp), ft::equal(foo,foo + 1,bar, mycomp)); 
        verify_equality(std::equal(foo,foo + 1,bar, mycomp), ft::equal(foo,foo + 1,bar, mycomp));
        verify_equality(std::equal(foo,foo + 6,foo,  mycomp), ft::equal(foo,foo + 6,foo,  mycomp)); 
        verify_equality(std::equal(foo,foo + 6,foo,  mycomp), ft::equal(foo,foo + 6,foo,  mycomp));
        verify_equality(std::equal(foo,foo + 5,foo,  mycomp), ft::equal(foo,foo + 5,foo,  mycomp));
        std::cout << '\n';
    }
}