/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:49:24 by scha              #+#    #+#             */
/*   Updated: 2022/08/03 23:49:26 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

#include "utils.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template <class T>
	class iterator
	{
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
		
		private:
			iterator_type	_ptr;
		public:
			iterator() : _ptr(u_nullptr) {}
			explicit iterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
			iterator (iterator<Iter>& it) : _ptr(it.base()) {}
			template <class Iter>
  			iterator (const iterator<Iter>& it) : _ptr(it.base()) {}

			iterator_type base() const{return _ptr;}
			reference operator*() const{return *_ptr;}
			iterator operator+ (difference_type n) const{return iterator(_ptr + n);}
			iterator& operator++()
			{
				++_ptr;
				return (*this);
			}
			iterator operator++(int)
			{
				iterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			iterator& operator+= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			iterator operator- (difference_type n) const{return iterator(_ptr - n);}
			iterator& operator--()
			{
				--_ptr;
				return (*this);
			}
			iterator operator--(int)
			{
				iterator tmp(*this);
				--_ptr;
				return (tmp);
			}
			iterator& operator-= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*_ptr));
			}
			reference operator[] (difference_type n) const {return (_ptr[n]);}
	};
	template <class Iterator>
	bool operator== (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator== (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() == rhs.base());
	}


	template <class Iterator>
	bool operator!= (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator!= (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	
	template <class Iterator>
	bool operator< (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator< (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() < rhs.base());
	}


	template <class Iterator>
	bool operator<= (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator<= (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}


	template <class Iterator>
	bool operator> (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator> (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() > rhs.base());
	}


	template <class Iterator>
	bool operator>= (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator>= (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}


	template <class Iterator>
	iterator<Iterator> operator+ (
			typename iterator<Iterator>::difference_type n,
			const iterator<Iterator>& it)
	{
		return (iterator<Iterator>(it.base() + n));
	}

	template <class Iterator>
	typename iterator<Iterator>::difference_type operator- (
			const iterator<Iterator>& lhs,
			const iterator<Iterator>& rhs)
	{
		return(lhs.base() - rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	typename iterator<Iterator_L>::difference_type operator- (
			const iterator<Iterator_L>& lhs,
			const iterator<Iterator_R>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

}

#endif