#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

namespace ft
{   
    template<class T>
    struct input_iterator_tag
    {

        public :
            typedef input_iterator_tag iterator_category;
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef const T& reference;


            input_iterator_tag()
            {
            }
            input_iterator_tag(pointer ptr) : _ptr(ptr)
            {
            }

            reference operator*() const
            {
                return (*_ptr);
            }

            pointer operator->()
            {
                return (_ptr);
            }

            input_iterator_tag& operator++() //preincrement
            {
                _ptr++;
                return (*this);
            }

            input_iterator_tag operator++(int)
            {
                input_iterator_tag temp = *this;
                ++(*this);
                
                return (temp);
            }

            friend bool operator!=(const input_iterator_tag<T> &lhs, const input_iterator_tag<T> &rhs)
            {
                return (lhs._ptr != rhs._ptr);
            }
            
            friend bool operator==(const input_iterator_tag<T> &lhs, const input_iterator_tag<T> &rhs)
            {
                return (lhs._ptr == rhs._ptr);
            }
            private :
                pointer _ptr;
    };

};

#endif