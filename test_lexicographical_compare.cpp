#include <vector>
#include <iostream>
#include <iterator>
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
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
        verify_equality(std::lexicographical_compare(foo,foo+5,bar,bar+9), ft::lexicographical_compare(foo,foo+5,bar,bar+9));
        verify_equality(std::lexicographical_compare(foo,foo,bar,bar), ft::lexicographical_compare(foo,foo,bar,bar));
        verify_equality(std::lexicographical_compare(foo,foo + 1,bar,bar), ft::lexicographical_compare(foo,foo + 1,bar,bar)); 
        verify_equality(std::lexicographical_compare(foo,foo + 1,bar,bar + 1), ft::lexicographical_compare(foo,foo + 1,bar,bar + 1));
        verify_equality(std::lexicographical_compare(foo,foo + 6,foo, foo + 6), ft::lexicographical_compare(foo,foo + 6,foo, foo + 6)); 
        verify_equality(std::lexicographical_compare(foo,foo + 6,foo, foo + 5), ft::lexicographical_compare(foo,foo + 6,foo, foo + 5));
        verify_equality(std::lexicographical_compare(foo,foo + 5,foo, foo + 6), ft::lexicographical_compare(foo,foo + 5,foo, foo + 6));
        std::cout << '\n';
    }

    {
        char foo[]="ApPleer";
        char bar[]="applees";

        std::cout << "Test lexicographical with function comp\n" << std::endl;
        verify_equality(std::lexicographical_compare(foo,foo+5,bar,bar+9, mycomp), ft::lexicographical_compare(foo,foo+5,bar,bar+9, mycomp));
        verify_equality(std::lexicographical_compare(foo,foo,bar,bar, mycomp), ft::lexicographical_compare(foo,foo,bar,bar, mycomp));
        verify_equality(std::lexicographical_compare(foo,foo + 1,bar,bar, mycomp), ft::lexicographical_compare(foo,foo + 1,bar,bar, mycomp)); 
        verify_equality(std::lexicographical_compare(foo,foo + 1,bar,bar + 1, mycomp), ft::lexicographical_compare(foo,foo + 1,bar,bar + 1, mycomp));
        verify_equality(std::lexicographical_compare(foo,foo + 6,foo, foo + 6, mycomp), ft::lexicographical_compare(foo,foo + 6,foo, foo + 6, mycomp)); 
        verify_equality(std::lexicographical_compare(foo,foo + 6,foo, foo + 5, mycomp), ft::lexicographical_compare(foo,foo + 6,foo, foo + 5, mycomp));
        verify_equality(std::lexicographical_compare(foo,foo + 5,foo, foo + 6, mycomp), ft::lexicographical_compare(foo,foo + 5,foo, foo + 6, mycomp));
        std::cout << '\n';
    }
}