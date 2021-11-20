#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> > 
    class stack
    {

        public :
            typedef  T value_type;
            typedef  Container container_type;
            typedef  size_t size_type;
        
        private :

            size_type _size;
        
        protected :
            Container _underlying_container;

        public :
            stack(const container_type & container = container_type())
            {
                _underlying_container = container;
                _size = container.size();
            }

            size_type size() const
            {
                return (_underlying_container.size());
            }

            bool empty() const
            {
                return (_underlying_container.empty());
            }

            value_type& top()
            {
                return (_underlying_container.back());
            }
            const value_type& top() const
            {
                return (_underlying_container.back());
            }

            void push (const value_type& val)
            {
                _underlying_container.push_back(val);
            }

            void pop()
            {
                _underlying_container.pop_back();
            }

          
            template <class T, class Container>
            friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);
        
        };
    template <class T, class Container>
    bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs._underlying_container == rhs._underlying_container);
    }
    template <class T, class Container>
    bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs != rhs);
    }
    template <class T, class Container>
    bool operator < (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs < rhs);
    }
    
    template <class T, class Container>
    bool operator > (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs > rhs);
    }

    template <class T, class Container>
    bool operator <= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs <= rhs);
    }

    template <class T, class Container>
    bool operator >= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs >= rhs);
    }
}