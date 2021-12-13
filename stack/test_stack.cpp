#include "stack.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <map>
#include <list>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

void test_constructor()
{
    std::deque<int> mydeque (3,100);      
    NAMESPACE::vector<int> myvector (2,200);       

    NAMESPACE::stack<int> first;                    
    NAMESPACE::stack<int> second (myvector);         

    NAMESPACE::stack<int,NAMESPACE::vector<int> > third;  
    NAMESPACE::stack<int,std::deque<int> > fourth (mydeque);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}

int main()
{
    test_constructor();

}