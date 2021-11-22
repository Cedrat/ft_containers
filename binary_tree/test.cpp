#include "RBTree.hpp"
#include <iostream>

int main()
{
    Node<int> *tree;
    Node<int> *test;

    tree = init_new_node(3);
    test = init_new_node(1);
    insertion<int>(tree, test);
    test = init_new_node(5);
    insertion<int>(tree, test);
    test = init_new_node(7);
    insertion<int>(tree, test);
    test = init_new_node(6);
    insertion<int>(tree, test);
        test = init_new_node(4);
    insertion<int>(tree, test);
            test = init_new_node(2);
    insertion<int>(tree, test);
                test = init_new_node(2);
    insertion<int>(tree, test);

            test = init_new_node(2);
    insertion<int>(tree, test);

            test = init_new_node(2);
    insertion<int>(tree, test);
                test = init_new_node(1);
    insertion<int>(tree, test);
                    test = init_new_node(15);
    insertion<int>(tree, test);


    print_tree<int>(tree);
    std::cout << "DEPTH TREE = " << depth_tree<int>(tree) << std::endl;
}