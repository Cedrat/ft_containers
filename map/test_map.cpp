#include "map.hpp"
#include "../iterator_traits.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>
#include <string>


#ifndef NAMESPACE
# define NAMESPACE ft
#endif


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

template<class T, class V>
void test_constructor()
{
    NAMESPACE::map<int, int> first;
}

void test_insert()
{
    NAMESPACE::map<int, std::string> first;

    first.insert(std::pair<int, std::string>(5, "coucou"));

}

void test_count()
{
    NAMESPACE::map<int, std::string> first;

    first.insert(std::pair<int, std::string>(5, "coucou"));

    std::cout << first.count(5) << std::endl;
    std::cout << first.count(3) << std::endl;

}

int main()
{

    // NAMESPACE::vector<int> myvector;

    // test_constructor();
    // test_const_constructor();
    // copy_constructor_time();
    // push_back_test<int>(myvector);
    // pop_back_test<int>(myvector);
    // test_insert();
    // resize_vector_test();
    // reserve_vector_test();
    // at_vector_test();
    // iterator_vector_test();
    // const_iterator_vector_test();
    // assign_vector_test();
    // test_insert();
    // test_insert2();
    // test_str_insert();
    // test_erase();
    // test_char();
    test_count();
    // test_string();
    // test_assign_str();
    // test_swap();
    // test_clear();

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