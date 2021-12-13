#include "../vector/vector.hpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>

void test_insert()
{
    ft::vector<std::string> myvector (3,"100");
    ft::vector<std::string> second;

    second.insert(second.begin() ,  myvector.begin(), myvector.end());
}
int main()
{
    test_insert();
}