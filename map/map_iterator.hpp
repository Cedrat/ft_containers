#ifndef MAP_ITERATOR
# define MAP_ITERATOR

#include "../iterator_tags.hpp"
#include "../binary_tree/RBTree.hpp"
namespace ft
{
    template<class Node, class Key, class Mapped, class Tree>
    struct map_iterator 
    {
        public :
            typedef bidirectional_iterator_tag iterator_category;
            typedef long difference_type;
            // typedef Node<Key, Mapped> value_type; //tree<Key, T>
            typedef Node value_type;
            typedef Node *pointer;
            typedef ft::pair<const Key, Mapped> *pointer_pair;
            typedef ft::pair<const Key, Mapped> &pair;
            typedef Node& reference;
            

            pointer _ptr;
            Tree    *_tree;


            map_iterator()
            {

            }

            map_iterator(pointer ptr, Tree *tree) : _ptr(ptr), _tree(tree)
            {

            }

            // map_iterator(pointer ptr) : _ptr(ptr)
            // {

            // }

            // map_iterator(ft::pair<const Key,Mapped> *xd) : _ptr(NULL)
            // {
            // }

            // map_iterator(typename T::Node tree) : _ptr(NULL)
            // {
            // }

            // map_iterator(typename _ptr->_pair) : _ptr(tree->_pair)
            // {
            // }

            pointer_pair operator->()
            {
                return (_ptr->_pair);
            }

            pair operator*()
            {
                return (*_ptr->_pair);
            }

            map_iterator& operator--() //preincrement
            {
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = previous_node(_ptr);
                return (*this);
            }

             map_iterator operator--(int) //postincrement
            {
                map_iterator temp = *this;
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = previous_node(_ptr);
                return (temp);
            }

            map_iterator& operator++() //preincrement
            {
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                    _ptr = _tree->next_node(_ptr);
                return (*this);
            }

             map_iterator operator++(int) //postincrement
            {
                map_iterator temp = *this;
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                {
                    _ptr = _tree->next_node(_ptr);
                }
                return (temp);
            }

            friend bool operator!=(const map_iterator<Node, Key, Mapped, Tree> &lhs, const map_iterator<Node, Key, Mapped, Tree> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }

            friend bool operator==(const map_iterator<Node, Key, Mapped, Tree> &lhs, const map_iterator<Node, Key, Mapped, Tree> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }
        
    };
};

#endif
