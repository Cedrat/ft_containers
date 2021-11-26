#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <cstdlib>
#include <iostream>
#include "../vector.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>

#define RED 1
#define BLACK 0
#define LEAF NULL
#define SPACE_FIT 6 // min 5

template<class T>
struct Node
{
    Node *_left;
    Node *_right;
    Node *_parent;
    bool    _color;
    T     _key;
};


template<class T>
Node<T>* parent(Node<T> *current)
{
    return (current->_parent);
}

template<class T>
Node<T>* grand_parent(Node<T> *current)
{
    if (parent(current))
    {
        return (current->_parent->_parent);
    }
    return (NULL);
}

template<class T>
Node<T>* brother(Node<T> *current)
{
    if (parent(current))
    {
        if (current == current->_parent->_right)
            return (current->_parent->_left);
        else
            return (current->_parent->_right);
    }
    return (NULL);
}

template<class T>
Node<T>* uncle(Node<T> *current)
{
    return (brother(parent(current)));
}


template<class T>
Node<T> * init_new_node(T key)
{
    Node<T>* new_node = new Node<T>;

    new_node->_left = LEAF;
    new_node->_right = LEAF;
    new_node->_parent = NULL;
    new_node->_color = RED;
    new_node->_key = key;

    return (new_node);
};

template<class T>
Node<T> *search_head(Node<T> *node)
{
    if (node->_parent && node->_parent->_parent)
        std::cerr << node << "|" << node->_parent  << "|" << node->_parent->_parent << "|" << node->_parent->_parent->_parent << std::endl;

    while(node->_parent != NULL)
    {
        node = node->_parent;        // sleep(1);
    }
   return (node);
}

template<class T>
bool is_black(Node<T> *node)
{
    if (node == LEAF || node->_color == BLACK)
        return (true);
    return false;
}

template<class T>
void left_rotate(Node<T> *relegate)
{
    std::cout << "left_rotate : \nrelegate key = " << relegate->_key << std::endl;
    Node<T> *promote = relegate->_right; //1
    std::cout << "promote key = " << promote->_key << std::endl;

    if (relegate->_parent != NULL)
    {
        promote->_parent = relegate->_parent;
        if (relegate->_parent->_right == relegate)
        {
            relegate->_parent->_right = promote;
        }
        else
        {
            relegate->_parent->_left = promote;
        }
    }
    else
    {
        promote->_parent = NULL;
    }
    

    if (relegate->_left == promote)
    {
        relegate->_left = NULL;
    }
    else
    {
        relegate->_right = promote->_left;
        if (promote->_left)
        {
            promote->_left->_parent = relegate;
        }
    }
    relegate->_parent = promote;
    promote->_left = relegate;
    // std::cerr << promote->_parent->_key << std::endl;
}


template<class T>
void right_rotate(Node<T> *relegate)
{
    std::cout << "rigth rotate = \nrelegate key = " << relegate->_key << std::endl;
    Node<T> *promote = relegate->_left; //1
    std::cout << "promote key = " << promote->_key << std::endl;

    if (relegate->_parent != NULL)
    {
        promote->_parent = relegate->_parent;
        if (relegate->_parent->_right == relegate)
        {
            relegate->_parent->_right = promote;
        }
        else
        {
            relegate->_parent->_left = promote;
        }
    }
    else
    {
        promote->_parent = NULL;
    }


    if (relegate->_left == promote)
    {
        relegate->_left = promote->_right;
        if (promote->_right)
        {
            promote->_left->_parent = relegate;
        }
    }
    else
    {
        relegate->_right = NULL;
    }
        relegate->_parent = promote;
    promote->_right = relegate;
};

template<class T>
Node<T> *insert_new_node(Node<T> *head, T value_to_insert)
{
    Node<T> *new_node;
    new_node = init_new_node(value_to_insert);
    insertion(head, new_node);
    std::cout << new_node->_key << std::endl;
    balance(new_node);
    // print_tree(search_head(new_node));
    return (search_head(new_node));
    // return (head);
}

template<class T>
void color_elder_family(Node<T> *son)
{
    parent(son)->_color = BLACK;
    uncle(son)->_color = BLACK;
    Node<T> *grand_p = grand_parent(son);
    
    grand_p->_color = RED;
    balance(grand_p);
}

template<class T>
void re_balance(Node<T> *son)
{
    Node<T> *grand_p = grand_parent(son);
    Node<T> *parent_ = parent(son);

    if (grand_p)
    {    
        if (grand_p->_left != NULL && son == grand_p->_left->_right)
        {
            left_rotate(parent_);
            son = son->_left;
        }
        else if (grand_p->_right != NULL && son == grand_p->_right->_left)
        {
            right_rotate(parent_);
            son = son->_right;
        }
    }
    rotate_for_respect_balance(son);
}

template<class T>
void rotate_for_respect_balance(Node<T> *son)
{
    Node<T> *grand_p = grand_parent(son);
    Node<T> *parent_ = parent(son);
        if (son == parent(son)->_left)
        {
            right_rotate(grand_parent(son));
        }
        else
        {
            left_rotate(grand_parent(son));
        }
        parent_->_color = BLACK;
        grand_p->_color = RED;


}

template<class T>
void balance(Node<T> *current_node)
{
    print_tree(search_head(current_node));
    std::cout << "balance = " << current_node->_key << std::endl;
    if (current_node->_parent == NULL)
    {
        current_node->_color = BLACK;
    }
    else if (parent(current_node)->_color == BLACK) 
    {
        // tree well bicolored
    }
    else if (uncle(current_node) && uncle(current_node)->_color == RED)
    {
        color_elder_family(current_node);
    }
    else
    {
        re_balance(current_node);
    }   
}

// void 

template<class T>
void delete_node(Node<T> *head, T value)
{

}

template<class T>
void insertion(Node<T> *head, Node<T> *to_insert)
{

    if (head != NULL)
    {
        if (head->_key > to_insert->_key)
        {
            if (head->_left != NULL)
            {
                insertion(head->_left, to_insert);
                return ;
            }
            else
            {
                head->_left = to_insert;
            }
        }
        else if (head->_key <= to_insert->_key)
        {
            if (head->_right != NULL)
            {
                insertion(head->_right, to_insert);
                return ;
            }
            else
            {
                head->_right = to_insert;
            }
        }
    }
    to_insert->_parent = head;
}


template<class T>
std::string child(Node<T> *head)
{
    if (head != NULL)
        return ("1");
    return ("0");
}

template<class T>
void delete_tree(Node<T> *head)
{
    if (head == NULL)
        return ;
    if (head->_left)
    {
        delete_tree(head->_left);
    }
    if (head->_right)
    {
        delete_tree(head->_right);
    }
    delete (head);
}


#endif