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

    bool operator==(const Node<T> &rhs)
    {
        if (_right == rhs._right 
            && _left == rhs._left
            && _key == rhs._key
            && _parent == rhs._parent
            && _color == rhs._color)
            return (TRUE);  
        return (FALSE);        
    }

        bool operator!=(const Node<T> &rhs)
    {
        return (!(*this == rhs));
    }
};

template<class T>
class Tree
{
    private :
        Node<T> *_sentry;
        Node<T> *_root;

    public :
        Tree()
        {
            _sentry = new Node<T>;

            _sentry->_right = LEAF;
            _sentry->_left = LEAF;
            _sentry->_parent = LEAF;
            _sentry->_color = BLACK;
            _sentry->_key = T();
            
            _root = NULL;
        }
        ~Tree()
        {
            delete_tree(_root);
            delete _sentry;
        };

        Node<T> * getRoot()
        {
            return (_root);
        }

        void delete_tree(Node<T> *head)
        {
            if (head == NULL)
                return ;
            if (head->_left != _sentry)
            {
                delete_tree(head->_left);
            }
            if (head->_right != _sentry)
            {
                delete_tree(head->_right);
            }
            delete (head);
        }

        bool is_sentry(Node<T> * node) const
        {
            if (node->_right == LEAF &&
            node->_left == LEAF &&
            node->_parent == LEAF &&
            node->_color == BLACK)
            {
                return (TRUE);
            }
            return (FALSE);
        }

        Node<T> *insert_new_node(T value_to_insert)
        {
            Node<T> *new_node;
            new_node = init_new_node(value_to_insert);
            insertion(_root, new_node);
            balance(new_node);
            std::cout << "root key " << _root->_key << std::endl;
            return (_root);
        }

        Node<T> * init_new_node(T key)
        {
            Node<T>* new_node = new Node<T>;

            new_node->_left = _sentry;
            new_node->_right = _sentry;
            new_node->_parent = _sentry;
            new_node->_color = RED;
            new_node->_key = key;

            return (new_node);
        }

        void insertion(Node<T> *head ,Node<T> *to_insert)
        {

            if (head != NULL)
            {
                if (head->_key > to_insert->_key)
                {
                    if (head->_left != NULL && head->_left != _sentry)
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
                    if (head->_right != NULL && head->_right != _sentry)
                    {
                        insertion(head->_right, to_insert);
                        return ;
                    }
                    else
                    {
                        head->_right = to_insert;
                    }
                }
            to_insert->_parent = head;
            }
            if (head == NULL)
            {
                _root = to_insert;
            }
        }
    void balance(Node<T> *current_node)
    {
        std::cout << "balance = " << current_node->_key << std::endl;
        if (current_node->_parent == _sentry)
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

    void left_rotate(Node<T> *relegate)
    {
        std::cout << "left_rotate : \nrelegate key = " << relegate->_key << std::endl;
        Node<T> *promote = relegate->_right; //1
        std::cout << "promote key = " << promote->_key << std::endl;

        relegate->_right = promote->_left;
        if (promote->_left != _sentry)
        {
            promote->_left->_parent = relegate;
        }
        promote->_parent = relegate->_parent;
        if (relegate->_parent == _sentry)
        {
            _root = promote;
        }
        else if (relegate == relegate->_parent->_left)
        {
            relegate->_parent->_left = promote;
        }
        else
        {
            relegate->_parent->_right = promote;
        }
        promote->_left = relegate;
        relegate->_parent = promote;
        // std::cerr << promote->_parent->_key << std::endl;
    }

    void right_rotate(Node<T> *relegate)
    {
        std::cout << "rigth rotate = \nrelegate key = " << relegate->_key << std::endl;
        Node<T> *promote = relegate->_left; //1
        std::cout << "promote key = " << promote->_key << std::endl;

            relegate->_left = promote->_right;
            if (promote->_right != _sentry)
            {
                promote->_right->_parent = relegate;
            }
            promote->_parent = relegate->_parent;
            if (relegate->_parent == _sentry)
            {
                _root = promote;
            }
            else if (relegate == relegate->_parent->_right)
            {
                relegate->_parent->_right = promote;
            }
            else
            {
                relegate->_parent->_left = promote;
            }
            promote->_right = relegate;
            relegate->_parent = promote;
    };



    void color_elder_family(Node<T> *son)
    {
        parent(son)->_color = BLACK;
        uncle(son)->_color = BLACK;
        Node<T> *grand_p = grand_parent(son);
        
        grand_p->_color = RED;
        balance(grand_p);
    }


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

    void transplante(Node<T> *old, Node<T> *newcomer)
    {
        if (old == _sentry)
        {
            _root = newcomer;
        }
        else if (old == old->_parent->_left)
        {
            old->_parent->_left = newcomer;
        }
        else
        {
            old->_parent->_right = newcomer;
        }
        newcomer->_parent = old->_parent;
    }

    Node<T> * find_node(T key)
    {
        Node<T> *temp = _root;

        while (temp != _sentry)
        {
            if (key == temp->_key)
            {
                std::cout << "Value Find" << std::endl;
                return (temp);
            }
            else if (key >= temp->_key)
            {
                temp = temp->_right;
            }
            else
            {
                temp = temp->_left;
            }
        }
        return (NULL);
    }
    Node<T> *val_min(node<T> *current_node)
    {
        Node<T> *temp;

        temp = current_node;

        while (temp->_left != _sentry)
        {
            temp = temp->_left;
        }
        return (temp);

    }
    void delete_node(Node<T> *node_to_delete)
    {
        Node<T>* temp;
        bool original_color = node_to_delete->_color;

        temp = node_to_delete;
        if (node_to_delete->_left == _sentry)
        {

        }
        else if (node_to_delete->_right == _sentry)
        {

        }
        else
        {
        }

    }
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






// void 

template<class T>
void delete_node(Node<T> *head, T value)
{

}




template<class T>
std::string child(Node<T> *head)
{
    if (head != NULL)
        return ("1");
    return ("0");
}

#endif