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
#include "../binary_tree/print_tree.hpp"
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

      private :
        typedef Tree<Key, T, Compare, Alloc> alloc_tree;
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
        typedef map_iterator<Node<Key, T>, Key, T, Tree<Key, T, Compare, Alloc> > iterator;
        typedef const_map_iterator<Node<Key, T>, Key, T, Tree<Key, T, Compare, Alloc> > const_iterator;
        // typedef const_random_access_iterator<value_type> const_iterator;
        // typedef reverse_iterator<const_iterator> const_reverse_iterator;
        // typedef reverse_iterator<iterator> reverse_iterator;
        typedef std::ptrdiff_t difference_type;



        private :
            Tree<Key, T, Compare, Alloc> *_RBT;
        
        public :
            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
              {
                (void) comp;
                (void) alloc;
                std::allocator<alloc_tree> tree_alloc;
                _RBT = tree_alloc.allocate(1);
                tree_alloc.construct(_RBT, alloc_tree());

              }

              map(const map& other)
              {
                *this = other;
              }


              template <class InputIterator>
              map (InputIterator first, InputIterator last,
                  const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type())
              {
                (void) comp;
                (void) alloc;
                std::allocator<alloc_tree> tree_alloc;
                _RBT = tree_alloc.allocate(1);
                tree_alloc.construct(_RBT, alloc_tree());
                while (first != last)
                {
                  insert(*first);
                  first++;
                }
              }

              map& operator= (const map& rhs)
              {
                std::allocator<alloc_tree> tree_alloc;
                _RBT = tree_alloc.allocate(1);
                tree_alloc.construct(_RBT, alloc_tree());
                const_iterator it;

                it = rhs.begin();
                while (it != rhs.end())
                {
                  insert(*it);
                  it++;
                }
                return (*this);
              }

              ft::pair<const iterator,bool> insert (const value_type& val)
              {
                  _RBT->insert_new_node(val.first, val.second);
                  
                  return (ft::pair<const iterator, bool>());
              }

              ~map()
              {
                std::allocator<alloc_tree> tree_alloc;
                tree_alloc.destroy(_RBT);
                tree_alloc.deallocate(_RBT, 1);
                // _RBT->delete_tree();
                // delete _RBT;
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

              const_iterator begin() const
              {
                return (const_iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
              }

              const_iterator end() const
              {
                return (const_iterator(_RBT->getSentry(), _RBT));
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

              size_type max_size() const
              {
                std::allocator<Node<Key, T> > tree_alloc;

                return (tree_alloc.max_size());
              }

              bool empty() const
              {
                return (_RBT->size());
              }

              iterator find (const key_type& k)
              {
                return (iterator(_RBT->find_node(k), _RBT));
              }

              // const_iterator find (const key_type& k) const
              // {
              //   return (const_iterator(_RBT->find_node(k)));
              // }
              void erase (iterator position)
              {
                _RBT->delete_node(position._ptr);
              }

              size_type erase (const key_type& key)
              {
                if (_RBT->find_if_key_exist(key) == FALSE)
                {
                  return (0);
                }
                _RBT->delete_node(_RBT->find_node(key));
                return (1);
              }

              void erase (iterator first, iterator last)
              {
                iterator temp;

                while (first != last)
                {
                  temp = first;
                  temp++;
                  _RBT->delete_node(first._ptr);
                  // delete(first._ptr);
                  first = temp;
                }
              }

              void clear()
              {
                _RBT->delete_tree();
              }

              void swap(map &x)
              {
                Tree<Key, T, Compare, Alloc> *temp;

                temp = _RBT;
                _RBT = x._RBT;
                x._RBT = temp;
              }
              //const_iterator begin() const;     

              key_compare key_comp() const
              {
                return (Compare());
              }

              iterator lower_bound (const key_type& k)
              {

                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair->first))
                {
                  return (begin());
                }
                return (iterator(_RBT->lower_key(k), _RBT));
              }

              const_iterator lower_bound (const key_type& k) const
              {
                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair->first))
                {
                  return (begin());
                }
                return (const_iterator(_RBT->lower_key(k), _RBT));
              }

              iterator upper_bound (const key_type& k)
              {
                if (Compare()(_RBT->val_max(_RBT->getRoot())->_pair->first, k))
                {
                  return (end());
                }
                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair->first))
                  return (iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
                return (iterator(_RBT->upper_key(k), _RBT));
              }

              const_iterator upper_bound (const key_type& k) const 
              {
                if (Compare()(_RBT->val_max(_RBT->getRoot())->_pair->first , k))
                {
                  return (end());
                }
                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair->first))
                  return (const_iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
                return (const_iterator(_RBT->upper_key(k), _RBT));
              }

              pair<iterator,iterator>             equal_range (const key_type& k)
              {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
              }

              pair<const_iterator,const_iterator>             equal_range (const key_type& k) const
              {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
              }

              // value_compare value_comp() const
              // {
              //   return 
              // }

              allocator_type get_allocator() const
              {
                return (Alloc());
              }

};
};
#endif
