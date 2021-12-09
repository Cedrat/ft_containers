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

template<class T>
void print_element_i_vector(NAMESPACE::vector<T> const & the_vector, size_t index)
{
    std::cout << "value for index " << index << " : " << the_vector[index] << std::endl;
}

template<class T>
void print_vector(NAMESPACE::vector<T> const &the_vector)
{
    std::cout << "size : " << the_vector.size() << std::endl;
    std::cout << "max_size : " << the_vector.max_size() << std::endl;
    std::cout << "capacity : " << the_vector.capacity() << std::endl;
    std::cout << "empty : " << the_vector.empty() << std::endl;
    if (the_vector.empty() == FALSE)
    {
        std::cout << "front_value " << the_vector.front() << std::endl;
        std::cout << "back_value " << the_vector.back() << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
};

template<class T>
void print_all_vectors_elements(NAMESPACE::vector<T>  const &the_vector)
{
    for (size_t i = 0 ; i < the_vector.size(); i++)
    {
        print_vector(the_vector);
        print_element_i_vector(the_vector, i);
    }
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void test_constructor()
{
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

}

void test_insert()
{
    NAMESPACE::map<int, std::string> first;

    first.insert(NAMESPACE::pair<int, std::string>(5, "coucou"));

}

// void test_count()
// {
//     NAMESPACE::map<int, std::string> first;

//     first.insert(ft::pair<int, std::string>(5, "coucou"));

//     std::cout << first.count(5) << std::endl;
//     std::cout << first.count(3) << std::endl;

// }

void travel_in_tree()
{
    NAMESPACE::map<int, std::string> first;

    first.insert(NAMESPACE::pair<int, std::string>(50, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(49, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(51, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(48, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(40, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(43, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(42, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(45, "coucou"));

    NAMESPACE::map<int, std::string>::iterator it = first.begin();
    NAMESPACE::map<int, std::string>::iterator it_end = first.end();
    int i = 0;
    while (it != it_end)
    {
        std::cout << "ELEMENT["<<i<<"] = " << it->first << std::endl;
        it++;
        i++;
    }



}

void test_begin()
{
    NAMESPACE::map<int, std::string> first;

    first.insert(NAMESPACE::pair<int, std::string>(50, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(49, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(51, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(48, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(40, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(43, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(42, "coucou"));
    first.insert(NAMESPACE::pair<int, std::string>(45, "coucou"));

    NAMESPACE::map<int, std::string>::iterator it = first.begin();
    NAMESPACE::map<int, std::string>::iterator it_end = first.end();

    std::cout << "it->value->first = " << it->first << std::endl;
    std::cout << "it->value->first = " << (++it)->first << std::endl;
    std::cout << "it->value->first = " << (it++)->first << std::endl;

    while (it != it_end)
    {
        std::cout << "it->value->first = " << it->first << std::endl;
        ++it;
    }
    it = first.begin();
    it_end--;
    // while (it != it_end)
    // {
    //     std::cout << "it->value->first = " << it_end->first << std::endl;
    //     --it_end;
    // }
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

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void    test_hook()
{
  NAMESPACE::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void test_erase()
{
    NAMESPACE::map<char,int> mymap;
    NAMESPACE::map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range

    //show content:


   for (it = mymap.begin(); it!=mymap.end() ; it++)
   {
        std::cout << it->first << " => " << it->second << '\n';
   }
}

void test_lower_upper_bound_string ()
{
  NAMESPACE::map<char,std::string> mymap;
  NAMESPACE::map<char,std::string>::iterator itlow,itup;

//   std::cout << "CRASH" << std::endl;
  mymap['f']="20";
  mymap['b']="40";
  mymap['c']="60";
  mymap['r']="80";
  mymap['e']="100";
  std::cout << mymap.lower_bound ('c')->second << mymap.lower_bound ('c')->first << std::endl;
  mymap.lower_bound ('c')->second = "14";  // itlow points to b
  itlow=mymap.upper_bound ('k');   // itup points to e (not d!)


//   mymap.erase(itlow,itup);        // erases [itlow,itup)

// 	printPair(itlow);
// //   // print content:
//   for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
}

void test_lower_upper_bound_int ()
{
  NAMESPACE::map<char,int> mymap;
  NAMESPACE::map<char,int>::iterator itlow,itup;

//   std::cout << "CRASH" << std::endl;
  mymap['f']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['r']=80;
  mymap['e']=100;
  std::cout << mymap.lower_bound ('c')->second << mymap.lower_bound ('c')->first << std::endl;
  mymap.lower_bound ('c')->second = 14;  // itlow points to b
  itlow=mymap.upper_bound ('k');   // itup points to e (not d!)


//   mymap.erase(itlow,itup);        // erases [itlow,itup)

// 	printPair(itlow);
// //   // print content:
//   for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
}

void test_assign()
{
	NAMESPACE::map<int, int> old;

	old.insert(NAMESPACE::make_pair(2, 2));
	old.insert(NAMESPACE::make_pair(3, 2));
	old.insert(NAMESPACE::make_pair(4, 2));
	old.insert(NAMESPACE::make_pair(5, 2));




	for (NAMESPACE::map<int,int>::iterator it=old.begin(); it!=old.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';

	NAMESPACE::map<int, int> recent(old);
	for (NAMESPACE::map<int,int>::iterator it=recent.begin(); it!=recent.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void test_clear()
{
  NAMESPACE::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

// void test_compare ()
// {
//   NAMESPACE::map<char,int> mymap;

//   NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

//   mymap['a']=100;
//   mymap['b']=200;
//   mymap['c']=300;

//   std::cout << "mymap contains:\n";

//   char highest = mymap.rbegin()->first;     // key value of last element

//   NAMESPACE::map<char,int>::iterator it = mymap.begin();
//   do {
//     std::cout << it->first << " => " << it->second << '\n';
//   } while ( mycomp((*it++).first, highest) );

//   std::cout << '\n';

// }
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

int main()
{

    // NAMESPACE::vector<int> myvector;

    // test_constructor();
    // test_const_constructor();
    // copy_constructor_time();
    // test_compare();
    // travel_in_tree();
    // test_begin();
    // push_back_test<int>(myvector);
    // pop_back_test<int>(myvector);
    // test_insert();
    // resize_vector_test();
    // reserve_vector_test();
    // at_vector_test();
    // test_hook();
    // test_find();
    // test_erase();
	// test_lower_upper_bound_int();
    // test_lower_upper_bound_string();
    // test_equal_range();
    // test_clear();
    // test_swap();
    // test_compare():
    // iterator_vector_test();
    // const_iterator_vector_test();
    // assign_vector_test();
    // test_insert();
    // test_insert2();
    // test_str_insert();
    // test_erase();
    // test_char();
    // test_count();
    // test_string();
    // test_assign();
    // test_swap();
    test_clear();

    // test_get_alloc();
    // test_comparison();
    // test_swap_external();
    // test_reverse_iterator();
    // test_comparison_iterator();
    // bidirect_it();
    // ite();
    // rev_ite_construct();
    // test_reverse_iterator();

}

//  std::vector<int> 