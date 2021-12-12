#ifndef MAP_HPP
# define MAP_HPP

#include "../binary_tree/RBTree.hpp"
#include <memory>
#include <iostream>
#include "../utils/is_integral.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/ft_distance.hpp"
#include "map_iterator.hpp"
#include "../binary_tree/print_tree.hpp"
#include <map>
#include "reverse_map_iterator.hpp"


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
        
        typedef reverse_map_iterator<const_iterator>  const_reverse_iterator;
        typedef reverse_map_iterator<iterator> reverse_iterator;
        typedef std::ptrdiff_t difference_type;



        private :
            Tree<Key, T, Compare, Alloc> *_RBT;

        class value_compare
        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        friend class map;
        protected:
          Compare comp;
          value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
        public:
          typedef bool result_type;
          typedef value_type first_argument_type;
          typedef value_type second_argument_type;
          bool operator() (const value_type& x, const value_type& y) const
          {
            return comp(x.first, y.first);
          }   
        };
        
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
                std::allocator<alloc_tree> tree_alloc;
                _RBT = tree_alloc.allocate(1);
                tree_alloc.construct(_RBT, alloc_tree());
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
                insert(first, last);
                // print_tree(_RBT->getRoot());
              }

              map& operator= (const map& rhs)
              {
                *this->_RBT = *rhs._RBT;
                return (*this);
              }

              ft::pair<const iterator,bool> insert (const value_type& val)
              {
                  bool exist = _RBT->find_if_key_exist(val.first);
                  
                  if (!exist)
                    _RBT->insert_new_node(val.first, val.second);

                  const iterator it = iterator(_RBT->find_node(val.first), _RBT);
                  

                  return (ft::pair<const iterator, bool>(it, !exist));
              }

              iterator insert (iterator position, const value_type& val)
              {
                _RBT->insert_new_node(val.first, val.second);
                  position = iterator(_RBT->find_node(val.first),_RBT);
                 return (position);
              }

              template <class InputIterator>
              void insert (InputIterator first, InputIterator last)
              {
                while (first != last)
                {
                  _RBT->insert_new_node(first->first, first->second);
                  first++;
                }
              }

              ~map()
              {
                std::allocator<alloc_tree> tree_alloc;
                // _RBT->delete_tree();
                tree_alloc.destroy(_RBT);
                tree_alloc.deallocate(_RBT, 1);
                // delete _RBT;
              }

              size_type count (const key_type& k) const
              {
                return (_RBT->find_if_key_exist(k));
              }

              template< class K >
              size_type count( const K& x ) const
              {
                return (_RBT->find_if_key_exist(x));
              }


              iterator begin()
              {
                return (iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
              }

              iterator end()
              {
                return (iterator(_RBT->getSentry(), _RBT));
              }

              reverse_iterator rend()
              {
                return (reverse_iterator(begin()));
              }

              reverse_iterator rbegin()
              {
                return (reverse_iterator(iterator(_RBT->getSentry(), _RBT)));
              }

              const_iterator begin() const
              {
                return (const_iterator(_RBT->val_min(_RBT->getRoot()), _RBT));
              }

              const_iterator end() const
              {
                return (const_iterator(_RBT->getSentry(), _RBT));
              }

              const_reverse_iterator rend() const
              {
                return (const_reverse_iterator(begin()));
              }

              const_reverse_iterator rbegin() const
              {
                return (const_reverse_iterator(_RBT->getSentry()), _RBT);
              }

              

              mapped_type& operator[] (const key_type& key)
              {
                if (_RBT->find_node(key) == _RBT->getSentry())
                {
                  _RBT->insert_new_node(key, mapped_type());
                }
                return (_RBT->find_node(key)->_pair.second);
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
                return (!_RBT->size());
              }

              iterator find (const key_type& k)
              {
                return (iterator(_RBT->find_node(k), _RBT));
              }

              const_iterator find (const key_type& k) const
              {
                return (const_iterator(_RBT->find_node(k), _RBT));
              }
              void erase (iterator position)
              {
                (void) position;
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
                if (size() != 0)
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

                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair.first))
                {
                  return (begin());
                }
                return (iterator(_RBT->lower_key(k), _RBT));
              }

              const_iterator lower_bound (const key_type& k) const
              {
                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair.first))
                {
                  return (begin());
                }
                return (const_iterator(_RBT->lower_key(k), _RBT));
              }

              iterator upper_bound (const key_type& k)
              {

                if (Compare()(_RBT->val_max(_RBT->getRoot())->_pair.first, k))
                {
                  return (end());
                }
                Node<Key,T> *lower_val = _RBT->val_min(_RBT->getRoot());
                if (Compare()(k, lower_val->_pair.first))
                  return (iterator(lower_val, _RBT));
                return (iterator(_RBT->upper_key(k), _RBT));
              }

              const_iterator upper_bound (const key_type& k) const 
              {
                if (Compare()(_RBT->val_max(_RBT->getRoot())->_pair.first , k))
                {
                  return (end());
                }
                if (Compare()(k, _RBT->val_min(_RBT->getRoot())->_pair.first))
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

              value_compare value_comp() const
              {
                return (value_compare(Compare()));
              }

              allocator_type get_allocator() const
              {
                return (Alloc());
              }

              

};
            template <class Key, class T, class Compare, class Alloc>
              bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {

                typename ft::map<Key,T,Compare,Alloc>::const_iterator lhs_itbegin = lhs.begin();
                typename ft::map<Key,T,Compare,Alloc>::const_iterator rhs_itbegin = rhs.begin();
                if (lhs.size() == rhs.size())
                {
                  while (lhs_itbegin != lhs.end())
                  {
                    if (*lhs_itbegin != *rhs_itbegin)
                      return (false);
                    lhs_itbegin++;
                    rhs_itbegin++;
                  }
                }
                else
                  return (false);
                return (true);
              }

              template <class Key, class T, class Compare, class Alloc>
              bool operator!= (const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {
                  return (!(lhs == rhs));
              }

              template <class Key, class T, class Compare, class Alloc>
              bool operator< (const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {
                  return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
              }

              template <class Key, class T, class Compare, class Alloc>
              bool operator> (const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {
                return (rhs < lhs);
              }

              template <class Key, class T, class Compare, class Alloc>
              bool operator>= (const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {
                return (!(rhs > lhs));
              }

              template <class Key, class T, class Compare, class Alloc>
              bool operator<= (const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
              {
                return (!(rhs < lhs));
              }
              template <class Key, class T, class Compare, class Alloc>
              void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
              {
                  x.swap(y);
              }
};
#endif
