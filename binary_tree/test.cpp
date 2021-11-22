#include "RBTree.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    Node<int> *tree;
    Node<int> *test;

	std::srand(time(0));
    tree = init_new_node(std::rand() % 100);
	for (int i = 0; i < 50; i++)
	{
    	test = init_new_node(std::rand() % 100);
		insertion<int>(tree, test);
	}

    print_tree<int>(tree);
    std::cout << "DEPTH TREE = " << depth_tree<int>(tree) << std::endl;
}