#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>


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

// template<class T>
// void print_element_i_vector(NAMESPACE::vector<T> const & the_vector, size_t index)
// {
//     std::cout << "value for index " << index << " : " << the_vector[index] << std::endl;
// }

// template<class T>
// void print_vector(NAMESPACE::vector<T> const &the_vector)
// {
//     std::cout << "size : " << the_vector.size() << std::endl;
//     std::cout << "max_size : " << the_vector.max_size() << std::endl;
//     std::cout << "capacity : " << the_vector.capacity() << std::endl;
//     std::cout << "empty : " << the_vector.empty() << std::endl;
//     if (the_vector.empty() == FALSE)
//     {
//         std::cout << "front_value " << the_vector.front() << std::endl;
//         std::cout << "back_value " << the_vector.back() << std::endl;
//     }
//     std::cout << "--------------------------------------" << std::endl;
// };

// template<class T>
// void print_all_vectors_elements(NAMESPACE::vector<T>  const &the_vector)
// {
//     for (size_t i = 0 ; i < the_vector.size(); i++)
//     {
//         print_vector(the_vector);
//         print_element_i_vector(the_vector, i);
//     }
// }
void test_top()
{
     ft::vector<int> myvector (2,200); 
    std::vector<int> vector_std (3,100);

    const NAMESPACE::stack<int> first;                    

    const NAMESPACE::stack<int,std::vector<int> > third(vector_std);  
    const NAMESPACE::stack<int,ft::vector<int> > fourth(myvector);

    std::cout << "top of third: " << third.top() << std::endl;
    std::cout << "top of fourth: " << fourth.top() << std::endl;
}

void test_empty()
{
    ft::vector<int> myvector (2,200); 
    std::vector<int> vector_std (2,200);

    const NAMESPACE::stack<int> first;                    

    const NAMESPACE::stack<int,std::vector<int> > third(vector_std);  
    const NAMESPACE::stack<int,ft::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << "and empty: " << first.empty() << std::endl;
    std::cout << "size of third: " << third.size() << "and empty: " << third.empty() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << "and empty: " << fourth.empty() << std::endl;
}

void test_constructor()
{
    ft::vector<int> myvector (2,200); 
    std::vector<int> vector_std (2,200);

    const NAMESPACE::stack<int> first;                    

    const NAMESPACE::stack<int,std::vector<int> > third(vector_std);  
    const NAMESPACE::stack<int,ft::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';
}

void test_comparison()
{
    NAMESPACE::vector<int> v_foo (3,100); 
    NAMESPACE::vector<int> v_bar (2,200);
    NAMESPACE::vector<int> v_truite(2, 100);
    NAMESPACE::vector<int> v_saumon(2, 100);

    NAMESPACE::stack<int> foo (v_foo); 
    NAMESPACE::stack<int> bar (v_bar);
    NAMESPACE::stack<int> truite(v_truite);
    NAMESPACE::stack<int> saumon(v_saumon);

    std::cout << (foo == bar) << std::endl;
    std::cout << (foo == truite) << std::endl;
    std::cout << (foo == saumon) << std::endl;
    std::cout << (bar == truite) << std::endl;
    std::cout << (bar == saumon) << std::endl;
    std::cout << (truite == saumon) << std::endl;

    std::cout << (foo != bar) << std::endl;
    std::cout << (foo != truite) << std::endl;
    std::cout << (foo != saumon) << std::endl;
    std::cout << (bar != truite) << std::endl;
    std::cout << (bar != saumon) << std::endl;
    std::cout << (truite != saumon) << std::endl;

    std::cout << (foo < bar) << std::endl;
    std::cout << (foo < truite) << std::endl;
    std::cout << (foo < saumon) << std::endl;
    std::cout << (bar < truite) << std::endl;
    std::cout << (bar < saumon) << std::endl;
    std::cout << (truite < saumon) << std::endl;

    std::cout << (foo > bar) << std::endl;
    std::cout << (foo > truite) << std::endl;
    std::cout << (foo > saumon) << std::endl;
    std::cout << (bar > truite) << std::endl;
    std::cout << (bar > saumon) << std::endl;
    std::cout << (truite > saumon) << std::endl;

    std::cout << (foo >= bar) << std::endl;
    std::cout << (foo >= truite) << std::endl;
    std::cout << (foo >= saumon) << std::endl;
    std::cout << (bar >= truite) << std::endl;
    std::cout << (bar >= saumon) << std::endl;
    std::cout << (truite >= saumon) << std::endl;

    std::cout << (foo <= bar) << std::endl;
    std::cout << (foo <= truite) << std::endl;
    std::cout << (foo <= saumon) << std::endl;
    std::cout << (bar <= truite) << std::endl;
    std::cout << (bar <= saumon) << std::endl;
    std::cout << (truite <= saumon) << std::endl;
}

void test_pop_push_empty()
{
    NAMESPACE::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
}

int main()
{
    //test_constructor();
    // test_empty();
    // test_pop_push_empty();
    test_comparison();
}

//  std::vector<int> 