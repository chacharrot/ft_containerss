/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:50:24 by scha              #+#    #+#             */
/*   Updated: 2022/08/03 23:50:26 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	Container								container_type;
			typedef	typename container_type::value_type		value_type;
			typedef	typename container_type::size_type		size_type;
		protected:
			container_type c;
		public:
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
			bool empty() const {return (this->c.empty());}
			size_type size() const {return (this->c.size());}
			value_type& top() {return (this->c.back());}
			const value_type& top() const {return (this->c.back());}
			
			void push (const value_type& val)
			{
				this->c.push_back(val);
			}

			void pop()
			{
				this->c.pop_back();
			}

			template <class T1, class Container1>
			friend	bool operator== (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator!= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator<  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator<=  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator>  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
			template <class T1, class Container1>
			friend	bool operator>=  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
	};
	
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool operator>=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif