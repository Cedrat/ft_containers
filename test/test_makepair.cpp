#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include "test_function.hpp"
#include "pair.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

int main () 
{
    // {
    //     ft::pair <std::string,double> product1;                     // default constructor
    //     ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    //     ft::pair <std::string,double> product3 (product2);          // copy constructor

    //     product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    //     product2.first = "shoes";                  // the type of first is string
    //     product2.second = 39.90;                   // the type of second is double

    //     std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    //     std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    //     std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    // }
    // {
    //     ft::pair <std::string,int> planet, homeplanet;

    //     planet = ft::make_pair("Earth",6371);

    //     homeplanet = planet;

    //     std::cout << "Home planet: " << homeplanet.first << '\n';
    //     std::cout << "Planet size: " << homeplanet.second << '\n';
    //     return 0;
    // }
    {
        NAMESPACE::pair <int,int> foo;
        NAMESPACE::pair <int,int> bar;

        foo = NAMESPACE::make_pair (10,20);
        bar = NAMESPACE::make_pair (10.5,'c'); // ok: implicit conversion from pair<double,char>

        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

        return 0;
    }
}