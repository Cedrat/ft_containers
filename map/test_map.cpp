#include "map.hpp"
#include "../utils/iterator_traits.hpp"
#include <map>
#include <vector>
#include <iostream>
// #include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>
#include <string>


#ifndef NAMESPACE
# define NAMESPACE ft
#endif

template <typename T>
void	printPair(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second;
}

#define NB_OF_ELEMENTS 100
#define FALSE 0

unsigned long int	chrono_init(void)
{
	struct timeval		tv;
	unsigned long int	start_time;

	gettimeofday(&tv, NULL);
	start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (start_time);
}
 
unsigned long int	stamp_time(unsigned long int start_time)
{
	unsigned long int	actual_time;
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	actual_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time;
	return (actual_time);
}


template<class T, class V, class E = std::less<T>()>
void print_map(NAMESPACE::map<T, V, E>  &other)
{
  std::cout << "size = " << other.size() << std::endl;
  std::cout << "max_size = " << other.max_size() << std::endl;
  typename NAMESPACE::map<T,V, E>::iterator it_b = other.begin();
  int i = 0;

  while (it_b != other.end())
  {
    std::cout << "ELEMENT[" << i << "] : first = " << it_b->first << " second = " << it_b->second << std::endl;
    i++;
    it_b++;
  }
}
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp 
{
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


void test_constructor()
{
  NAMESPACE::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;
  print_map<char, int>(first);
  NAMESPACE::map<char,int>second (first.begin(),first.end());
  print_map<char, int>(second);

  NAMESPACE::map<char,int>third (second);
  print_map<char, int>(third);

  NAMESPACE::map<char,int,classcomp> fourth;                 
  print_map<char, int>(fourth);

  bool(*fn_pt)(char,char) = fncomp;
  NAMESPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); 
  
  print_map<char, int>(fifth);
}



void operator_assign ()
{
  std::cout << "Operator assign" << std::endl;
  NAMESPACE::map<int,std::string> first;
  NAMESPACE::map<int,std::string> second;

  std::cout << "empty = " << std::endl;
  second=first;
  print_map(first);
  print_map(second);

  for (int i = 0; i < NB_OF_ELEMENTS; i++)
  {
    first.insert(NAMESPACE::make_pair(i, "same word"));
  }
  std::cout << "not empty" << std::endl;

  second=first;                //
  first=NAMESPACE::map<int,std::string>();  

  print_map(first);
  print_map(second);
}



void test_empty()
{
  std::cout << "Empty test" << std::endl;
  NAMESPACE::map<int, std::string> first;
  NAMESPACE::map<int, std::string> second;
  second.insert(NAMESPACE::make_pair(2, "yolo"));

  std::cout << first.empty() << "\n" << second.empty() << std::endl;
  std::cout << "Clear second map" << std::endl;
  second.clear();
  std::cout << second.empty() << std::endl;
}



void test_insert()
{
    NAMESPACE::map<int, std::string> first;
    NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, bool> little_pair;
    std::cout << "insert with pair return" << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(50, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(49, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(49, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(42, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(45, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;
    little_pair = first.insert(NAMESPACE::pair<int, std::string>(45, "coucou"));
    std::cout << "pair.first = " << little_pair.first->first << " already_present ? " << little_pair.second << std::endl;

    std::cout << "with hint" << std::endl;

    NAMESPACE::map<int, std::string>::iterator it = first.begin();
    std::cout <<  first.insert(it , NAMESPACE::pair<int, std::string>(23, "ZBRAAH"))->first << std::endl;

    NAMESPACE::map<int, std::string> second;
    second.insert(first.begin(), first.end());
    print_map(second);
}

void test_erase()
{
  NAMESPACE::map<char,int> first;
  std::cout << "Erase" << std::endl;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;
  first['e']= 23;

  first.erase(first.begin());
  std::cout << "Erase one element" << std::endl;
  print_map(first);

  std::cout << "Erase one element and check if well erased" << std::endl;
  std::cout << "Erase 'a' who is already erased " << first.erase('a') << std::endl;
  std::cout << "Erase 'b'" << first.erase('b') << std::endl;
  print_map(first);
  std::cout << "Erase with range of iterator" << std::endl;
  first.erase(first.begin(), first.end());
  print_map(first);
}

void test_find()
{

    NAMESPACE::map<char,int> mymap;
    NAMESPACE::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    // if (it != mymap.end())
    //     mymap.erase (it);
    std::cout << "value find " << it->second << std::endl;

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';

}
void test_swap()
{
  NAMESPACE::map<char,int> foo,bar;
  std::cout << "SWAP" << std::endl;
  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  print_map(foo);
  print_map(bar);
}

void    test_hook()
{
  NAMESPACE::map<char,std::string> mymap;
  std::cout << "Hoom test" << std::endl;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';
}


void test_lower_upper_bound_string ()
{
  NAMESPACE::map<char,std::string> mymap;
  NAMESPACE::map<char,std::string>::iterator itlow,itup;
  std::cout << "Test lower upper " << std::endl;

  mymap['f']="20";
  mymap['b']="40";
  mymap['c']="60";
  mymap['r']="80";
  mymap['e']="100";
  std::cout << mymap.lower_bound ('c')->second << mymap.lower_bound ('c')->first << std::endl;
  mymap.lower_bound ('c')->second = "14";  
  itlow=mymap.upper_bound ('k');  

}



void test_clear()
{
  NAMESPACE::map<char,int> mymap;
  std::cout << "Test clear" << std::endl;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  print_map(mymap);

  mymap.clear();
  print_map(mymap);
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  print_map(mymap);
}

void test_equal_range ()
{
    NAMESPACE::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void test_reverse_iterator()
{
  NAMESPACE::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=60;
    mymap['f']=50;
    mymap['g']=320;
    mymap['h']=42340;
    mymap['i']=560;

    NAMESPACE::map<char, int>::reverse_iterator rit_b = mymap.rbegin();
    while (rit_b != mymap.rend())
    {
      std::cout << rit_b->first << std::endl;
      rit_b++;
    }
}

int main()
{
 test_constructor();
  operator_assign();
  test_empty();
  test_hook();
  test_insert();
  test_erase();
  test_swap();
  test_lower_upper_bound_string();
  test_clear();
  test_equal_range();
  test_reverse_iterator();
}

//  std::vector<int> 