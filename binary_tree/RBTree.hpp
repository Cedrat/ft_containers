#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <cstdlib>
#include <iostream>
#include "../vector/vector.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include "../utils/pair.hpp"
#include <memory>


#define RED 1
#define BLACK 0
#define LEAF NULL
#define SPACE_FIT 6 // min 5

template<class T, class V>
struct Node
{
    Node *_left;
    Node *_right;
    Node *_parent;
    ft::pair<const T, V> _pair;
    size_t    _color;


    Node(T first, V second) : _pair(first, second)
    {

    }
    bool operator==(const Node<T,V> &rhs)
    {
        if (_right == rhs._right 
            && _left == rhs._left
            && _parent == rhs._parent
            && _color == rhs._color)
            return (TRUE);  
        return (FALSE);        
    }

        bool operator!=(const Node<T,V> &rhs)
    {
        return (!(*this == rhs));
    }

    bool isSentry()
    {
        if (_right == LEAF &&
            _left == LEAF &&
            _parent == LEAF &&
            _color == BLACK)
        {
            return (TRUE);
        }
        return (FALSE);
    }
};

template<class T, class V, class Compare = std::less<T>, class Alloc = std::allocator<Node<const T, V> > >
class Tree
{
    private :
        Node<T,V> *_sentry;
        Node<T,V> *_root;
        size_t _size;


    public :
        typedef T Key;
        typedef V Mapped_value;
        Tree() : _size(0)
        {
             Alloc alloc_node;
            _sentry = alloc_node.allocate(1);
            alloc_node.construct(_sentry, Node<T,V>(T(), V()));



            _sentry->_right = LEAF;
            _sentry->_left = LEAF;
            _sentry->_parent = LEAF;
            _sentry->_color = BLACK;
            
            _root = _sentry;
        }

         Tree(Tree const &x) : _size(0) 
        {
            Alloc alloc_node;
            _sentry = alloc_node.allocate(1);
            alloc_node.construct(_sentry, Node<T,V>(T(),V()));


            _sentry->_right = LEAF;
            _sentry->_left = LEAF;
            _sentry->_parent = LEAF;
            _sentry->_color = BLACK;

            Node<T, V> *current;
            if (x.size())
                current = val_min(x.getRoot());
            else 
                current = _sentry;
            if (current == _sentry)
            {
                _root = current;
            }
            while (current != _sentry)
            {
               insert_new_node(current->_pair.first, current->_pair.second);
               current = next_node(current);
            }
            _size = x._size;
        }
        Tree& operator=(Tree const & rhs)
        {
            this->delete_tree();


            Node<T, V> *current;
            if (rhs.size())
                current = rhs.val_min(rhs.getRoot());
            else 
                current = _sentry;
            if (current == rhs.getSentry())
            {
                _root = current;
            }
            if ( current == _sentry)
            {
                _size = rhs._size;
                return (*this);
            }
            while (current != rhs.getSentry())
            {
               insert_new_node(current->_pair.first, current->_pair.second);
               current = rhs.next_node(current);
            }
            _size = rhs._size;
            return (*this);
        }

        

        ~Tree()
        {
            Alloc alloc_node;
            Alloc alloc;
            if (_root != _sentry)
                delete_tree(_root);
            alloc_node.destroy(_sentry);
            alloc_node.deallocate(_sentry , 1);

        };

        size_t size() const
        {
            return (_size);
        }

        Node<T,V> * getRoot() const
        {
            return (_root);
        }

        Node<T,V> *getSentry() const
        {
            return (_sentry);
        }


        void delete_tree()
        {
            if (_root != _sentry) 
                delete_tree(_root);
            _root = _sentry;
            _size = 0;
        }

        void delete_tree(Node<T,V> *head)
        {
            Alloc alloc;
            Alloc alloc_pair;

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
            alloc.destroy(head);
            alloc.deallocate(head , 1);
        }

        bool is_sentry(Node<T,V> * node) const
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

        Node<T,V> *minimal(Node<T,V> *current_node) const
        {
            Node<T,V> *temp;
            temp = current_node;
            while (temp->_left != _sentry)
            {
                temp = temp->_left;
            }
            return (temp);
        }

        Node<T,V> *insert_new_node(T value_to_insert, V value)
        {
            Node<T,V> *new_node;
            new_node = init_new_node(value_to_insert, value);
            if (insertion(_root, new_node) == FALSE)
            {
                Alloc alloc;

                alloc.destroy(new_node);
                alloc.deallocate(new_node , 1);

                return (_root);
            }
            balance(new_node);
            _size++;
            return (_root);
        }

        Node<T,V> * init_new_node(T key, V value = V())
        {
            Node<T,V>* new_node;
            Alloc alloc;
            Alloc alloc_pair;
            
            new_node = alloc.allocate(1);
            alloc.construct(new_node, Node<T,V>(key, value));


            new_node->_left = _sentry;
            new_node->_right = _sentry;
            new_node->_parent = _sentry;
            new_node->_color = RED;
            
            return (new_node);
        }




        Node<T,V> *next_node(Node<T,V> *current_node) const
        {
            Node<T,V>  *temp;
            temp = current_node; 

            if (temp->_right != _sentry)
            {
                return (minimal(temp->_right));
            }
            while (temp->_parent && temp == temp->_parent->_right)
            {
                temp = temp->_parent;
            }
            return (temp->_parent);
        }


        bool insertion(Node<T,V> *head ,Node<T,V> *to_insert)
        {

            if (head != _sentry)
            {
                if (to_insert->_pair.first == head->_pair.first)
                {
                    return (FALSE);
                }
                else if (!Compare()(head->_pair.first,to_insert->_pair.first))
                {
                    if (head->_left != _sentry)
                    {
                        return (insertion(head->_left, to_insert));
                    }
                    else
                    {
                        head->_left = to_insert;
                    }
                }
                else
                {
                    if (head->_right != _sentry)
                    {
                        return (insertion(head->_right, to_insert));
                    }
                    else
                    {
                        head->_right = to_insert;
                    }
                }
            }
            to_insert->_parent = head;
            if (head == _sentry)
            {
                _root = to_insert;
            }
            return (TRUE);
        }
    void balance(Node<T,V> *current_node)
    {
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

    void left_rotate(Node<T,V> *relegate)
    {
        Node<T,V> *promote = relegate->_right; //1

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
    }

    void right_rotate(Node<T,V> *relegate)
    {
        Node<T,V> *promote = relegate->_left; //1

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



    void color_elder_family(Node<T,V> *son)
    {
        parent(son)->_color = BLACK;
        uncle(son)->_color = BLACK;
        Node<T,V> *grand_p = grand_parent(son);
        
        grand_p->_color = RED;
        balance(grand_p);
    }


    void    re_balance(Node<T,V> *son)
    {
        Node<T,V> *grand_p = grand_parent(son);
        Node<T,V> *parent_ = parent(son);

        if (son == grand_p->_left->_right)
        {
            left_rotate(parent_);
            son = son->_left;
        }
        else if (son == grand_p->_right->_left)
        {
            right_rotate(parent_);
            son = son->_right;
        }
        rotate_for_respect_balance(son);
    }


    void rotate_for_respect_balance(Node<T,V> *son)
    {
        Node<T,V> *grand_p = grand_parent(son);
        Node<T,V> *parent_ = parent(son);

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

    void transplante(Node<T,V> *old, Node<T,V> *newcomer)
    {
        if (old->_parent == _sentry)
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

    Node<T,V> * find_node(T const & key)
    {
        Node<T,V> *temp = _root;

        while (temp != _sentry)
        {
            if (key == temp->_pair.first)
            {
                return (temp);
            }
            else if (Compare()(key, temp->_pair.first))
            {
                temp = temp->_left;
            }
            else
            {
                temp = temp->_right;
            }
        }
        return (_sentry);
    }
    bool find_if_key_exist(T const & key) const
    {
        Node<T,V> *temp = _root;

        while (temp != _sentry)
        {
            if (key == temp->_pair.first)
            {
                return (TRUE);
            }
            else if (Compare()(key, temp->_pair.first))
            {
                temp = temp->_left;
            }
            else
            {
                temp = temp->_right;
            }
        }
        return (FALSE);
    }

    Node<T,V> *val_min(Node<T,V> *current_node) const
    {
        Node<T,V> *temp;
        if (current_node == _sentry)
        {
            return (_sentry);
        }
        temp = current_node;

        while (temp->_left != _sentry)
        {
            temp = temp->_left;
        }
        return (temp);
    }

    Node<T,V> *val_max(Node<T,V> *current_node)
    {
        Node<T,V> *temp;

        temp = current_node;

        while (temp->_right != _sentry)
        {
            temp = temp->_right;
        }
        return (temp);
    }

    ft::pair<const T, V>* pair_min(Node<T,V> *current_node)
    {
        Node<T,V> *temp;

        temp = current_node;

        while (temp->_left != _sentry)
        {
            temp = temp->_left;
        }
        return (temp->_pair);
    }

    
    Node<T, V> * upper_key(const T& key)
    {
        Node<T,V> *temp = _root;
        while (temp != _sentry)
        {
            if (Compare()(key , temp->_pair.first) == TRUE &&
                Compare()(key, temp->_left->_pair.first) == FALSE)
            {
                return (temp);
            }
            else if (Compare()(key, temp->_pair.first))
                temp = temp->_left;
            else 
            {
                temp = temp->_right;
            }
        }
        return (temp);
    }

    Node<T, V> * lower_key(const T& key)
    {
        Node<T,V> *temp = _root;
        temp = getRoot();
        while (temp != _sentry)
        {
            if (Compare()(temp->_pair.first, key) == FALSE && 
                ( temp->_left == _sentry || Compare()(val_max(temp->_left)->_pair.first, key) == TRUE))
            {
                return (temp);
            }
            else if (Compare()(key, temp->_pair.first))
                temp = temp->_left;
            else 
            {
                temp = temp->_right;
            }
        }
        return (temp);
    }


    void balance_after_delete(Node<T,V> *current_node)
    {
        Node<T,V> *brother; 
       
        while (current_node != _root && current_node->_color == BLACK)
        {
            brother = getBrother(current_node);
            if (current_node == current_node->_parent->_left)
            {
                if (brother->_color == RED)
                {
                    brother->_color = BLACK;
                    brother->_parent->_color = RED;
                    left_rotate(current_node->_parent);
                    brother = current_node->_parent->_right;
                }
                if (brother->_left->_color == BLACK && brother->_right->_color == BLACK) 
                {
                    brother->_color = RED;
                    current_node = current_node->_parent;
                }
                else if (brother->_right->_color == BLACK)
                {
                    brother->_color = RED;
                    brother->_left->_color = BLACK;
                    right_rotate(brother);
                    brother = current_node->_parent->_right;
                }
                else
                {
                    brother->_color = current_node->_parent->_color;
                    current_node->_parent->_color = BLACK;
                    brother->_right->_color = BLACK;
                    left_rotate(current_node->_parent);
                    current_node = _root;
                }
            }
            else
            {
                if (brother->_color == RED)
                {
                    brother->_color = BLACK;
                    current_node->_parent->_color = RED;
                    right_rotate(current_node->_parent);
                    brother = current_node->_parent->_left;
                }
                if (brother->_right->_color == BLACK && brother->_left->_color == BLACK) 
                {
                    brother->_color = RED;
                    current_node = current_node->_parent;
                }
                else if (brother->_left->_color == BLACK)
                {
                    brother->_color = RED;
                    brother->_right->_color = BLACK;
                    left_rotate(brother);
                    brother = current_node->_parent->_left;
                }
                else
                {
                    brother->_color = current_node->_parent->_color;
                    current_node->_parent->_color = BLACK;
                    brother->_left->_color = BLACK;
                    right_rotate(current_node->_parent);
                    current_node = _root;
                }
            }
        }
        current_node->_color = BLACK;
    }


    void delete_node(Node<T,V> *node_to_delete)
    {
        Node<T,V>* temp;
        bool original_color = node_to_delete->_color;
        Node<T,V>* node_begin_correction;

        if (node_to_delete == _sentry)
            return ;
        temp = node_to_delete;
        if (node_to_delete->_left == _sentry)
        {
            node_begin_correction = node_to_delete->_right;
            transplante(node_to_delete, node_to_delete->_right);
        }
        else if (node_to_delete->_right == _sentry)
        {
            node_begin_correction = node_to_delete->_left;
            transplante(node_to_delete, node_to_delete->_left);
        }
        else
        {
            temp = val_min(node_to_delete->_right);
            original_color = temp->_color;
            node_begin_correction = temp->_right;
            if (temp->_parent == node_to_delete)
            {
                node_begin_correction->_parent = temp;
            }
            else
            {
                transplante(temp, temp->_right);
                temp->_right = node_to_delete->_right;
                temp->_right->_parent = temp;
            }
            transplante(node_to_delete, temp);
            temp->_left = node_to_delete->_left;
            temp->_left->_parent = temp;
            temp->_color = node_to_delete->_color;
        }
        _size--;
        if (original_color == BLACK)
        {
            balance_after_delete(node_begin_correction);
        }
        Alloc alloc_pair;
        Alloc alloc_node;
        
        alloc_node.destroy(node_to_delete);
        alloc_node.deallocate(node_to_delete , 1);
    }

    Node<T,V> *previous_node(Node<T,V> *current_node)
    {
        Node<T,V>  *temp = current_node; 

        if (temp->_left != _sentry)
        {
            temp = temp->_left;
            while (temp->_right != _sentry)
            {
                temp = temp->_right;
            }
            return (temp);
        }
        else if (temp->_parent != _sentry)
        {
            if (temp->_parent->_right == temp)
                return (temp->_parent);
            if (temp->_parent->_left == temp)
            {
                while (temp->_parent != _sentry && temp->_parent->_left == temp)
                {
                    temp = temp->_parent;
                }
                if (temp == _root)
                {
                    return (_sentry);
                }
                else
                {
                    return (temp->_parent);
                }
            }
        }
        return (_sentry);
    }

};



template<class T, class V>
Node<T,V>* parent(Node<T,V> *current)
{
    return (current->_parent);
}

template<class T, class V>
Node<T,V>* grand_parent(Node<T,V> *current)
{
    if (parent(current))
    {
        return (current->_parent->_parent);
    }
    return (NULL);
}

    template<class T, class V>
    Node<T,V> *minimal(Node<T,V> *current_node)
    {
        Node<T,V> *temp;
        temp = current_node;
        while (temp->_left->isSentry() == FALSE)
        {
            temp = temp->_left;
        }
        return (temp);
    }


template<class T, class V>
Node<T,V> *next_node(Node<T,V> *current_node)
{
    Node<T,V>  *temp;
    temp = current_node; 

    if (temp->_right->isSentry() == FALSE)
    {
        return (minimal(temp->_right));
    }

    return (temp->_parent);
}



template<class T, class V>
Node<T,V>* getBrother(Node<T,V> *current)
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

template<class T, class V>
Node<T,V>* uncle(Node<T,V> *current)
{
    return (getBrother(parent(current)));
}


template<class T, class V>
Node<T,V> *search_head(Node<T,V> *node)
{
    while(node->_parent != NULL)
    {
        node = node->_parent;      
    }
   return (node);
}

template<class T, class V>
bool is_black(Node<T,V> *node)
{
    if (node == LEAF || node->_color == BLACK)
        return (true);
    return false;
}

template<class T, class V>
std::string child(Node<T,V> *head)
{
    if (head != NULL)
        return ("1");
    return ("0");
}

#endif