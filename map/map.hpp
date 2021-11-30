#ifndef MAP_HPP
# define MAP_HPP

#include "../binary_tree/RBTree.hpp"
#include <memory>
#include <iostream>
#include "../is_integral.hpp"
#include "../enable_if.hpp"
#include "../lexicographical_compare.hpp"
#include "../reverse_iterator.hpp"
#include "../ft_distance.hpp"
#include "map_iterator.hpp"
#include <map>

#define FALSE 0
#define TRUE 1

namespace ft
{

template <class Key,
          class T,
          class Compare = std::less<Key>, 
          class Alloc = std::allocator<ft::pair<const Key,T> > >
class map
{
      public :
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef map_iterator<Tree<Key, T> , Key , T> iterator;
        // typedef const_random_access_iterator<value_type> const_iterator;
        // typedef reverse_iterator<const_iterator> const_reverse_iterator;
        // typedef reverse_iterator<iterator> reverse_iterator;
        typedef std::ptrdiff_t difference_type;

        private :
            Tree<Key, T> *_RBT;
        
        public :
            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
              {
                _RBT = new Tree<Key, T>;
              }

              ft::pair<const iterator,bool> insert (const value_type& val)
              {
                  _RBT->insert_new_node(val.first, val.second);
                  
                  return (ft::pair<const iterator, bool>());
              }

              ~map()
              {
                delete _RBT;
              }

              // size_type count (const key_type& k) const
              // {
              //   return (_RBT.find_if_key_exist(k));
              // }


              iterator begin()
              {
                return (iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
              }

              iterator end()
              {
                return (iterator(_RBT->getSentry(), _RBT));
              }

              mapped_type& operator[] (const key_type& key)
              {
                if (_RBT->find_if_key_exist(key) == FALSE)
                {
                  _RBT->insert_new_node(key, mapped_type());
                }
                return (_RBT->find_node(key)->_pair->second);
              }

              size_type size() const
              {
                return (_RBT->size());
              }
              //const_iterator begin() const;     


};
};
#endif
