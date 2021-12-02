#include "RBTree.hpp"
#include <iostream>
#include <cstdlib>
#include <csignal>
#include "print_tree.hpp"
#include "functions.hpp"

int main()
{
    Tree<char, int> test;
    Node<char, int> *node;

    test.insert_new_node('a', 1);
    test.insert_new_node('b', 1);
    test.insert_new_node('c', 1);
    test.insert_new_node('d', 1);
    test.insert_new_node('e', 1);
    test.insert_new_node('f', 1);

    test.delete_node(test.find_node('b'));
    print_tree(test.getRoot());
    node = test.find_node('a');
    node = test.next_node(node);
}