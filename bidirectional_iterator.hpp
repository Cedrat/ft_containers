#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{   
    template<class T>
    struct bidirectional_iterator_tag
    {

        public :
            typedef bidirectional_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;

            bidirectional_iterator_tag()
            {
            }
            bidirectional_iterator_tag(pointer ptr) : _ptr(ptr)
            {
            }

            reference operator*() const
            {
                return (*_ptr);
            }

            // pointer operator->()
            // {
            //     return (_ptr);
            // }

            bidirectional_iterator_tag& operator++() //preincrement
            {
                _ptr++;
                return (*this);
            }

            bidirectional_iterator_tag operator++(int)
            {
                bidirectional_iterator_tag temp = *this;
                ++(*this);
                
                return (temp);
            }

             bidirectional_iterator_tag& operator--() //preincrement
            {
                _ptr--;
                return (*this);
            }

            bidirectional_iterator_tag operator--(int)
            {
                bidirectional_iterator_tag temp = *this;
                --(*this);
                
                return (temp);
            }

            friend bool operator!=(const bidirectional_iterator_tag<T> &lhs, const bidirectional_iterator_tag<T> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }
            
            friend bool operator==(const bidirectional_iterator_tag<T> &lhs, const bidirectional_iterator_tag<T> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }
            private :
                pointer _ptr;
    };

};

#endif