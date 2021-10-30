#include <memory>
#include <iostream>

int main()
{
    int *array;

    std::allocator<int> alloc_int;

    array = alloc_int.allocate(5);
    array[0] = 5;
    std::cout << array[0] << std::endl;

    alloc_int.deallocate(array, 5);
}