#ifndef MAP_ITERATOR
# define MAP_ITERATOR

#include "../iterator_tags.hpp"
#include "../binary_tree/RBTree.hpp"
namespace ft
{
    template<class T, class Key, class Mapped>
    struct map_iterator 
    {
        public :
            typedef bidirectional_iterator_tag iterator_category;
            typedef long difference_type;
            typedef Node<Key, Mapped> value_type; //tree<Key, T>
            typedef Node<Key, Mapped> *pointer;
            typedef ft::pair<const Key, Mapped> *pointer_pair;
            typedef Node<Key, Mapped>& reference;

            pointer _ptr;
            T *_tree;

        
            map_iterator()
            {

            }

            map_iterator(pointer ptr, T *tree) : _ptr(ptr) , _tree(tree)
            {

            }

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

            map_iterator& operator--() //preincrement
            {
                if (_ptr->isSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = previous_node(_ptr);
                return (*this);
            }

             map_iterator operator--(int) //postincrement
            {
                map_iterator temp = *this;
                if (_ptr->isSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = previous_node(_ptr);
                return (temp);
            }

            map_iterator& operator++() //preincrement
            {
                if (_ptr->isSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                    _ptr = next_node(_ptr);
                return (*this);
            }

             map_iterator operator++(int) //postincrement
            {
                map_iterator temp = *this;
                if (_ptr->isSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                    _ptr = next_node(_ptr);
                return (temp);
            }

            friend bool operator!=(const map_iterator<T, Key, Mapped> &lhs, const map_iterator<T, Key, Mapped> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }
        
    };
};

#endif