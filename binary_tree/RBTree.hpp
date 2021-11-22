#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <cstdlib>
#include <iostream>
#include "../vector.hpp"
#include <string>
#include <sstream>
#include <vector>

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
        if (current->key >= current->_parent->_key)
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

ft::vector<std::string> split_string(std::string str, std::string splitter)
{
    ft::vector<std::string> split_str;

    while (str.find(splitter) == 0)
        str.erase(0, splitter.size());
    while (str.size() > 0)
    {
        if (str.find(splitter) != std::string::npos)
        {
            split_str.push_back(str.substr(0, str.find(splitter)));
            str.erase(0, str.find(splitter) + splitter.size());
        }
        else
        {
            split_str.push_back(str.substr(0, str.size()));
            str.erase(0, str.size());
        }
        while (str.find(splitter) == 0)
            str.erase(0, splitter.size());        
    }
    return (split_str);
}

template<class T>
Node<T> *search_head(Node<T> *node)
{

    while(node->_parent != NULL)
    {
        node = parent(node);
    }
   return (node);
}

template<class T>
Node<T> *insert_new_node(Node<T> *head, T value_to_insert)
{
    // if (head == NULL)
    // {
    //     std::cerr << "here" << std::endl;
    //     head = init_new_node(value_to_insert);
    //     return (head);
    // }
    Node<T> *new_node;
    new_node = init_new_node(value_to_insert);
    insertion(head, new_node);
    return (search_head(new_node));
}


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

static std::string bool_color(bool color)
{
    if (color == RED)
    {
        return ("R");
    }

    if (color == BLACK)
    {
        return ("B");
    }
    return ("ERROR");
}

std::string s_substr(std::string str)
{
    return (str.substr(str.find('['), str.find(']') + 3));
}

ft::vector<std::string> tilt_tree(ft::vector<std::string> split_rbt, int depth)
{
    ft::vector<std::string> tilted_tree(depth * 2 - 1, std::string(split_rbt.size() * SPACE_FIT,' '));

    for (int i = 0; i < split_rbt.size() ; i++)
    {
        tilted_tree[(split_rbt[i].find('[')/SPACE_FIT) * 2].insert(i * SPACE_FIT, s_substr(split_rbt[i]));
    }

    for (int i = tilted_tree.size() - 1; i > 0 ; i = i-2)
    {
        for (int letter = 0; letter < tilted_tree[i].size(); letter++)
        {
            if (tilted_tree[i][letter] == ',')
                tilted_tree[i - 1][letter] = '|';
        }
    }
    
    char left_child;
    char right_child;
    int previous_pipe = 0;
    int pos_coma;
    for (int i = 0; i < tilted_tree.size() ; i++)
    {
        for (int letter = 0; letter < tilted_tree[i].size();letter++)
        {
            previous_pipe = 0;
            pos_coma = 0;
            if (tilted_tree[i][letter] == ']')
            {
                left_child = tilted_tree[i][letter+1];
                right_child = tilted_tree[i][letter+2];
                tilted_tree[i][letter+1] = ' ';
                tilted_tree[i][letter+2] = ' ';
                int p = letter;
                while (tilted_tree[i][p] != ',')
                    p--;
                pos_coma = p;
                p--;
                if (left_child == '1')
                {
                    
                    while(tilted_tree[i+1][p] != '|')
                    {
                        tilted_tree[i+1][p] = '-';
                        p--;
                    }
                }
                if (right_child == '1')
                {
                    p+= 2;
                    while(tilted_tree[i+1][p] != '|')
                    {
                        tilted_tree[i+1][p] = '-';
                        p++;
                    }
                }
                if (left_child == '1' || right_child == '1')
                {
                    tilted_tree[i + 1][pos_coma] = '+';
                }
            }
        }
                std::cout << tilted_tree[i] << std::endl;
    }
    return (tilted_tree);
}

template<class T>
void print_tree(Node<T> *head)
{
    if (head == NULL)
        return ;
    std::string RBT = print_tree_str(head);

    ft::vector<std::string> split_rbt = split_string(RBT, "\n");
    tilt_tree(split_rbt, depth_tree(head));
}

template<class T>
std::string child(Node<T> *head)
{
    if (head != NULL)
        return ("1");
    return ("0");
}

template<class T>
std::string print_tree_str(Node<T> *head,  int current_depth = 0 , std::string binary_str = std::string())
{   
    std::stringstream ss;
    if (head->_left)
    {
        binary_str += print_tree_str(head->_left, current_depth + 1);
    }
    ss << std::string(current_depth * SPACE_FIT, ' ') << "[" << head->_key << "," << bool_color(head->_color) << "]" << child(head->_left) << child(head->_right) << "\n";
    binary_str += ss.str();
    if (head->_right)
    {
        binary_str += print_tree_str(head->_right, current_depth + 1);
    }
    return (binary_str);    
}

int max(int one, int two)
{
    if (one > two)
        return (one);
    return (two);
}

template<class T>
int depth_tree(Node<T> *head, int depth = 1)
{
    if (head)
    {
        if (head->_left && head->_right)
        {
            return (max(depth_tree(head->_left , depth + 1), depth_tree(head->_right , depth + 1)));
        }
        else if (head->_left)
        {
            return (depth_tree(head->_left, depth + 1));
        }
        else if (head->_right)
        {
            return (depth_tree(head->_right, depth + 1));
        }
    }
    return (depth);
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