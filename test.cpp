#include "vector.hpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>


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
    while (it_begin != myvector.end())
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

// void const_iterator_vector_test()
// {
    // std::cout << "iterator_test" << std::endl;
    // NAMESPACE::vector<int> myvector;
    // for (int i = 1 ; i < NB_OF_ELEMENTS ; i++) 
    //     myvector.push_back(i);

    // NAMESPACE::vector<int>::const_iterator it_begin;
    // NAMESPACE::vector<int>::const_iterator it_end;

    // it_begin = myvector.begin();
    // it_end = myvector.end();


    // std::cout << "increment test and while (it_begin != it_end)" << std::endl;
    // std::cout << *it_begin << std::endl;
    // while (it_begin != myvector.end())
    // {
    //     // *it_begin = 5;
    //     std::cout << *it_begin << std::endl;
    //     it_begin++;
    // }
    // it_begin = myvector.begin();
    // it_end--;
    // std::cout << "decrement test and while (it_begin != it_end)" << std::endl;
    // while (it_begin != it_end)
    // {
    //     // *it_begin = 5;
    //     std::cout << *--it_end << std::endl;
    // }

    // it_end = myvector.end();

    // it_begin += 2;
    // std::cout << *(it_begin) << std::endl;
    // it_begin += 5;
    // std::cout << *(it_begin) << std::endl;
    // it_begin -= 3;
//     std::cout << *(it_begin) << std::endl;
//     std::cout << *(it_begin + 3) << std::endl;
//     std::cout << *(it_begin - 3) << std::endl;
//     std::cout << it_begin[1] << std::endl;
//     std::cout << (it_begin[1] > it_begin[0]) << std::endl;
//     std::cout << (it_begin[1] < it_begin[0]) << std::endl;
//     std::cout << (it_begin[1] >= it_begin[0]) << std::endl;
//     std::cout << (it_begin[0] >= it_begin[0]) << std::endl;
//     std::cout << (it_begin[1] <= it_begin[0]) << std::endl;
//     std::cout << (it_begin[0] <= it_begin[0]) << std::endl;


// }

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
    size_t start = chrono_init();

    NAMESPACE::vector<int> first;
    NAMESPACE::vector<int> second;
    NAMESPACE::vector<int> third;

    first.assign (NB_OF_ELEMENTS,100);             // 7 ints with a value of 100
    print_vector(first);
    NAMESPACE::vector<int>::iterator it;
    it=first.begin()+1;

    std::cout << "Second assign" << std::endl;
    second.assign (it,first.end()-1); // the 5 central values of first
    print_vector(second);

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.
    print_vector(third);

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';

    std::cout << "time : " << stamp_time(start)<< std::endl;

}

void test_insert()
{
    NAMESPACE::vector<int> myvector (5,100);
    NAMESPACE::vector<int> tyvector;
    NAMESPACE::vector<int>::iterator it;

    myvector.push_back(5);
    // it = myvector.begin();
    // it = myvector.insert ( it , 200 );

    // std::cout << myvector.end() - it << std::endl;
    // myvector.clear();
    for (int i = 0; i < 8; i++)
    {
        tyvector.push_back(i);
    }
    it = tyvector.end();
    //print_all_vectors_elements(tyvector);
    // print_all_vectors_elements(tyvector);

    tyvector.insert (it,11,300);
    print_all_vectors_elements(tyvector);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    NAMESPACE::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    print_all_vectors_elements(anothervector);
    myvector.insert(myvector.begin(), tyvector.begin(), tyvector.end());
    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
    std::cout << '\n';
}


void test_constructor()
{
    
  // constructors used in the same order as described above:
  NAMESPACE::vector<int> first;                                // empty vector of ints
  NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
  NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
  NAMESPACE::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  print_all_vectors_elements(second);
  print_all_vectors_elements(third);
  NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void test_const_constructor()
{
    
  // constructors used in the same order as described above:
    const NAMESPACE::vector<int> first;                                // empty vector of ints
    const NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
    const NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
    const NAMESPACE::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  print_all_vectors_elements(second);
  print_all_vectors_elements(third);
  NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void test_erase()
{

    NAMESPACE::vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=20; i++) 
        myvector.push_back(i);

    // erase the 6th element
    std::cout << *myvector.erase (myvector.begin()+5) << std::endl;
    print_all_vectors_elements(myvector);
    std::cout << *myvector.erase (myvector.begin()) << std::endl;
    print_all_vectors_elements(myvector);
    std::cout << *myvector.erase (myvector.end() - 1) << std::endl;
    print_all_vectors_elements(myvector);



  // erase the first 3 elements:
    std::cout <<  *myvector.erase (myvector.begin(),myvector.begin()+3) << std::endl;
     print_all_vectors_elements(myvector);
    //erase the two last
     std::cout <<  *myvector.erase (myvector.end() - 2,myvector.end()) << std::endl;
     print_all_vectors_elements(myvector);

    std::cout << * myvector.erase (myvector.begin() + 3, myvector.end() - 3) << std::endl;
     print_all_vectors_elements(myvector);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
}
void test_swap()
{
    NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
    NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);
    print_all_vectors_elements(foo);
    print_all_vectors_elements(bar);

}

void test_assign()
{
    NAMESPACE::vector<int> foo (3,0);
    NAMESPACE::vector<int> bar (5,0);

    // print_all_vectors_elements(bar);
    bar = foo;
    // foo = NAMESPACE::vector<int>();
    // print_all_vectors_elements(foo);
    print_all_vectors_elements(bar);
}

void test_clear()
{
    NAMESPACE::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    std::cout << "myvector contains:";
    print_all_vectors_elements(myvector);


    myvector.clear();
    myvector.push_back (1101);
    myvector.push_back (2202);

    std::cout << "myvector contains:";
    print_all_vectors_elements(myvector);
}

void test_get_alloc()
{
    std::vector<int> myvector;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
}

void test_comparison()
{
    NAMESPACE::vector<int> foo (3,100); 
    NAMESPACE::vector<int> bar (2,200);
    NAMESPACE::vector<int> truite(2, 100);
    NAMESPACE::vector<int> saumon(2, 100);

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

void test_swap_external()
{
    NAMESPACE::vector<int> foo (5,100);   // three ints with a value of 100
    NAMESPACE::vector<int> bar (3,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    print_all_vectors_elements(foo);

    std::cout << "bar contains:";
    print_all_vectors_elements(bar);

}


void test_reverse_iterator()
{
    NAMESPACE::vector<int> myvector;

    for (int i = 0; i < 20; i++)
    {
        myvector.push_back(i);
    }

    NAMESPACE::vector<int>::reverse_iterator rit_begin = myvector.rbegin();
    NAMESPACE::vector<int>::reverse_iterator rit_end = myvector.rend();

    while (rit_begin != rit_end)
    {
        std::cout << *rit_begin << std::endl;
        rit_begin++;
    }
    rit_begin = myvector.rbegin();
    // while (rit_begin != rit_end)
    // {
    //     std::cout << *rit_begin << std::endl;
    //     rit_begin++;
    // }
    while (rit_begin != rit_end)
    {
        rit_end--;
        std::cout << *rit_end << std::endl;
    }
    rit_end = myvector.rend();
    while (rit_begin != rit_end)
    {
        rit_begin = rit_begin + 1;
        std::cout << *rit_begin << std::endl;
    }
    rit_begin = myvector.rbegin();
    while (rit_begin != rit_end)
    {
        rit_end = rit_end - 1;
        std::cout << *rit_end << std::endl;
    }

    rit_end = myvector.rend();
    while (rit_begin != rit_end)
    {
        rit_begin +=1;
        std::cout << *rit_begin << std::endl;
    }

    // rit_begin = myvector.rbegin();
    // while (rit_begin != rit_end)
    // {
    //     rit_end -= 1;
    //     std::cout << rit_end[0] << std::endl;
    // }
    // rit_end = myvector.rend();
    // for (size_t i = 0; i < myvector.size(); i++)
    // {
    //     std::cout << rit_begin[i] << std::endl;
    // }

}

void test_comparison_iterator()
{

}

int main()
{

    NAMESPACE::vector<int> myvector;

    test_constructor();
    test_const_constructor();
    copy_constructor_time();
    push_back_test<int>(myvector);
    pop_back_test<int>(myvector);
    test_insert();
    resize_vector_test();
    reserve_vector_test();
    at_vector_test();
    iterator_vector_test();
    // const_iterator_vector_test();
    assign_vector_test();
    test_insert();
    test_erase();
    test_assign();
    test_swap();
    test_clear();

    test_get_alloc();
    test_comparison();
    test_swap_external();
    test_reverse_iterator();
    test_comparison_iterator();

}

//  std::vector<int>