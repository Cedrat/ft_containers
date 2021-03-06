#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../utils/iterator_tags.hpp"
#include "../binary_tree/RBTree.hpp"
namespace ft
{
    template<class Node, class Key, class Mapped, class Tree>
    struct map_iterator 
    {
        public :
            typedef bidirectional_iterator_tag iterator_category;
            typedef long difference_type;

            typedef Node *node;
            typedef ft::pair<const Key, Mapped> *pointer_pair;
            typedef const ft::pair<const Key, Mapped> *const_pointer_pair;
            typedef ft::pair<const Key, Mapped> &pair;
            typedef const ft::pair<const Key, Mapped> &const_pair;
            
            typedef ft::pair<const Key, Mapped> *pointer;
            typedef ft::pair<const Key, Mapped> &reference;
            typedef ft::pair<const Key, Mapped> value_type;

            node _ptr;
            Tree    *_tree;

            map_iterator()
            {

            }

            map_iterator(node ptr, Tree *tree) : _ptr(ptr), _tree(tree)
            {
            }

            pointer_pair operator->()
            {
                return (&_ptr->_pair);
            }

            const_pointer_pair operator->() const
            {
                return (&_ptr->_pair);
            }


            pair operator*()
            {
                return (_ptr->_pair);
            }

            const_pair operator*() const
            {
                return (_ptr->_pair);
            }


            map_iterator& operator--() //preincrement
            {
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = _tree->previous_node(_ptr);
                return (*this);
            }

             map_iterator operator--(int) //postincrement
            {
                map_iterator temp = *this;
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = _tree->previous_node(_ptr);
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
    template<class Node, class Key, class Mapped, class Tree>
    struct const_map_iterator 
    {
        public :
            typedef bidirectional_iterator_tag iterator_category;
            typedef long difference_type;
            typedef Node *node;
            typedef ft::pair<const Key, Mapped> *pointer_pair;
            
            typedef const ft::pair<const Key, Mapped> *const_pointer_pair;
            typedef const ft::pair<const Key, Mapped> &pair;
            typedef const ft::pair<const Key, Mapped> &const_pair;
            typedef const ft::pair<const Key, Mapped> *pointer;
            typedef const ft::pair<const Key, Mapped> &reference;
            typedef const ft::pair<const Key, Mapped> value_type;
            

            node _ptr;
            Tree    *_tree;


            const_map_iterator()
            {

            }

            const_map_iterator(node ptr, Tree *tree) : _ptr(ptr), _tree(tree)
            {
            }

            const_map_iterator(const map_iterator<Node, Key, Mapped, Tree> & iterator) : _ptr(iterator._ptr), _tree(iterator._tree)
            {

            }



            const_pointer_pair operator->() const 
            {
                return (&_ptr->_pair);
            }

            const_pair operator*() const
            {
                return (_ptr->_pair);
            }

            const_map_iterator& operator--() //predecrement
            {

                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr = _tree->previous_node(_ptr);

                return (*this);
            }

             const_map_iterator operator--(int) //postdecrement
            {
                const_map_iterator temp = *this;
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_max(_tree->getRoot());
                else 
                    _ptr =_tree->previous_node(_ptr);
                return (temp);
            }

            const_map_iterator& operator++() //preincrement
            {
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                    _ptr = _tree->next_node(_ptr);
                return (*this);
            }

             const_map_iterator operator++(int) //postincrement
            {
                const_map_iterator temp = *this;
                if (_ptr == _tree->getSentry())
                    _ptr = _tree->val_min(_tree->getRoot());
                else 
                {
                    _ptr = _tree->next_node(_ptr);
                }
                return (temp);
            }

            friend bool operator!=(const const_map_iterator<Node, Key, Mapped, Tree> &lhs, const const_map_iterator<Node, Key, Mapped, Tree> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }

            friend bool operator==(const const_map_iterator<Node, Key, Mapped, Tree> &lhs, const const_map_iterator<Node, Key, Mapped, Tree> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }
        
    };
};

#endif
