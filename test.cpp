#include "vector.hpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>


#ifndef NAMESPACE
# define NAMESPACE ft
#endif


#define NB_OF_ELEMENTS 2000000
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
void print_element_i_vector(NAMESPACE::vector<T> the_vector, size_t index)
{
    std::cout << "value for index " << index << " : " << the_vector[index] << std::endl;
}

template<class T>
void print_vector(NAMESPACE::vector<T> &the_vector)
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
void push_back_test(NAMESPACE::vector<T> &the_vector)
{
    size_t start = chrono_init();
    
    // print_vector<int>(the_vector);
    for (int i=0; i < NB_OF_ELEMENTS; i++)
    {
        print_vector<int>(the_vector);
        the_vector.push_back(i);
        // print_element_i_vector(the_vector, i);
    }
    std::cout << "time : " << stamp_time(start)<< std::endl;
}

template<class T>
void pop_back_test(NAMESPACE::vector<T> &the_vector)
{
    size_t start = chrono_init();
    
    print_vector<int>(the_vector);
    for (int i=0; i < NB_OF_ELEMENTS; i++)
    {
        print_vector<int>(the_vector);
        the_vector.pop_back();
    }
    std::cout << "time : " << stamp_time(start)<< std::endl;
}

template<class T>
void push_back_test_with_copy_constructor(NAMESPACE::vector<T> the_vector)
{
    size_t start = chrono_init();
    
    print_vector<int>(the_vector);
    for (int i=0; i < NB_OF_ELEMENTS; i++)
    {
        print_vector<int>(the_vector);
        the_vector.push_back(i);
        print_element_i_vector(the_vector, i);
    }
    std::cout << "time : " << stamp_time(start)<< std::endl;
}

void resize_vector_test()
{
    NAMESPACE::vector<int> myvector;

    // set some initial content:
    for (int i = 0 ; i < NB_OF_ELEMENTS ; i++) 
        myvector.push_back(i);

    myvector.resize(5);
    std::cout << "resize(5) :\n " << std::endl;
    print_vector(myvector);
    std::cout << "resize(8, 100) :\n " << std::endl;
    myvector.resize(8,100);
    print_vector(myvector);
    std::cout << "resize(12) :\n "<< std::endl;
    myvector.resize(12);
    print_vector(myvector);

    std::cout << "myvector contains :\n";
    for (size_t i = 0 ; i < myvector.size(); i++)
    {
        print_vector(myvector);
        print_element_i_vector(myvector, i);
    }
}

void reserve_vector_test()
{
    NAMESPACE::vector<int> myvector;

    // set some initial content:
    for (int i = 0 ; i < NB_OF_ELEMENTS ; i++) 
        myvector.push_back(i);

    myvector.reserve(NB_OF_ELEMENTS / 2);
    std::cout << "reserve(5) :\n " << std::endl;
    print_vector(myvector);
    std::cout << "reserve(8) :\n " << std::endl;
    myvector.reserve(NB_OF_ELEMENTS * 2);
    print_vector(myvector);
    std::cout << "reserve(12) :\n "<< std::endl;
    myvector.reserve(NB_OF_ELEMENTS * 4);
    print_vector(myvector);

    for (int i = 0 ; i < NB_OF_ELEMENTS * 8 ; i++) 
        myvector.push_back(i);

    std::cout << "myvector contains :\n";
    for (size_t i = 0 ; i < myvector.size(); i++)
    {
        print_vector(myvector);
        print_element_i_vector(myvector, i);
    }
}

void at_vector_test()
{
    NAMESPACE::vector<int> myvector;
    for (int i = 0 ; i < NB_OF_ELEMENTS ; i++) 
        myvector.push_back(i);

    for (int i = -1; i < NB_OF_ELEMENTS + 1 ; i++)
    {
        try
        {
            std::cout << "value number : " << myvector.at(i) << std::endl;
        }
        catch(std::out_of_range const &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void iterator_vector_test()
{
    std::cout << "iterator_test" << std::endl;
    NAMESPACE::vector<int> myvector;
    for (int i = 1 ; i < NB_OF_ELEMENTS ; i++) 
        myvector.push_back(i);

    NAMESPACE::vector<int>::iterator it_begin;
    NAMESPACE::vector<int>::iterator it_end;

    it_begin = myvector.begin();
    it_end = myvector.end();


    std::cout << "increment test and while (it_begin != it_end)" << std::endl;
    std::cout << *it_begin << std::endl;
    while (it_begin != it_end)
    {
        // *it_begin = 5;
        std::cout << *it_begin << std::endl;
        it_begin++;
    }
    it_begin = myvector.begin();
    it_end--;
    std::cout << "decrement test and while (it_begin != it_end)" << std::endl;
    while (it_begin != it_end)
    {
        // *it_begin = 5;
        std::cout << *--it_end << std::endl;
    }

    it_end = myvector.end();

    it_begin += 2;
    std::cout << *(it_begin) << std::endl;
    it_begin += 5;
    std::cout << *(it_begin) << std::endl;
    it_begin -= 3;
    std::cout << *(it_begin) << std::endl;
    std::cout << *(it_begin + 3) << std::endl;
    std::cout << *(it_begin - 3) << std::endl;
    std::cout << it_begin[1] << std::endl;
    std::cout << (it_begin[1] > it_begin[0]) << std::endl;
    std::cout << (it_begin[1] < it_begin[0]) << std::endl;
    std::cout << (it_begin[1] >= it_begin[0]) << std::endl;
    std::cout << (it_begin[0] >= it_begin[0]) << std::endl;
    std::cout << (it_begin[1] <= it_begin[0]) << std::endl;
    std::cout << (it_begin[0] <= it_begin[0]) << std::endl;


}

void copy_constructor_time()
{
    NAMESPACE::vector<int> my_vector;

    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        my_vector.push_back(i);
    }
    size_t start = chrono_init();
    NAMESPACE::vector<int> copy_vector(my_vector);
    std::cout << "time : " << stamp_time(start)<< std::endl;
}

void assign_vector_test()
{
    NAMESPACE::vector<int> first;
    NAMESPACE::vector<int> second;
    NAMESPACE::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    NAMESPACE::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end()-1); // the 5 central values of first

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';

}
int main()
{

    // NAMESPACE::vector<int> myvector;


    // copy_constructor_time();
    // push_back_test<int>(myvector);
    // pop_back_test<int>(myvector);
    
    // resize_vector_test();
    // reserve_vector_test();
    // at_vector_test();
    // iterator_vector_test();
    assign_vector_test();
}

 //std::vector<int>