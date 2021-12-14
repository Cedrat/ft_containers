#include "stack.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <map>
#include <stack>
#include <list>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define NB_OF_ELEMENTS 15

void test_constructor()
{
    std::deque<int> mydeque (3,100);      
    NAMESPACE::vector<int> myvector (2,200);       

    NAMESPACE::stack<int> first;                    
    NAMESPACE::stack<int, NAMESPACE::vector<int> > second (myvector);         

    NAMESPACE::stack<int,NAMESPACE::vector<int> > third;  
    NAMESPACE::stack<int,std::deque<int> > fourth (mydeque);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}

void test_empty()
{
    std::deque<int> mydeque (3,100);      
    NAMESPACE::vector<int> myvector (2,200);       

    NAMESPACE::stack<int> first;                    
    NAMESPACE::stack<int, NAMESPACE::vector<int> > second (myvector);           

    NAMESPACE::stack<int,NAMESPACE::vector<int> > third;  
    NAMESPACE::stack<int,std::deque<int> > fourth (mydeque);

    std::cout << "size of first: " << first.empty() << '\n';
    std::cout << "size of second: " << second.empty() << '\n';
    std::cout << "size of third: " << third.empty() << '\n';
    std::cout << "size of fourth: " << fourth.empty() << '\n';
}

void test_push_top_pop()
{
  NAMESPACE::stack<int> mystack;

  for (int i = 0; i < NB_OF_ELEMENTS; i++)
  {
    mystack.push(i);
    std::cout << "mystack.top() is now " << mystack.top() << std::endl;
  }
  for (int i = 0; i < NB_OF_ELEMENTS; i++)
  {
    std::cout << "mystack.top() is now " << mystack.top() << std::endl;
    mystack.pop();
  }
}

void test_relationnal_operator()
{
  NAMESPACE::stack<int> mystack;

  for (int i = 0; i < NB_OF_ELEMENTS; i++)
  {
    mystack.push(i);
  }

  NAMESPACE::stack<int> mystack2;

  for (int i = 0; i < NB_OF_ELEMENTS; i++)
  {
    mystack2.push(i * 2);
  }

  std::cout << "is my stack equal to mystack ? " << (mystack == mystack) << std::endl;
  std::cout << "is my stack inequal to mystack ? " << (mystack != mystack) << std::endl;
  std::cout << "is my stack equal to mystack2 ? " << (mystack == mystack2) << std::endl;
  std::cout << "is my stack inequal to mystack2 ? " << (mystack != mystack2) << std::endl;
  std::cout << "is my stack inferior to mystack2 ? " << (mystack < mystack2) << std::endl;
  std::cout << "is my stack superior to mystack2 ? " << (mystack > mystack2) << std::endl;
  std::cout << "is my stack inferior or equal to mystack ? " << (mystack <= mystack) << std::endl;
  std::cout << "is my stack superior or equal to mystack ? " << (mystack >= mystack) << std::endl;

}
int main()
{
    test_constructor();
    test_empty();
    test_push_top_pop();
    test_relationnal_operator();
}