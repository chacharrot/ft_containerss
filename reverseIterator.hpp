/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:50:39 by scha              #+#    #+#             */
/*   Updated: 2022/08/03 23:53:26 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "utils.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template <class Iterator>
	class reverseiterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<Iterator>::value_type  		value_type;
			typedef typename iterator_traits<Iterator>::pointer  			pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
			
		public:
			reverseiterator() : _ptr(u_nullptr) {}
			explicit reverseiterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			reverseiterator (reverseiterator<Iter>& it) : _ptr(it.base()) {}
			template <class Iter>
  			reverseiterator (const reverseiterator<Iter>& it) : _ptr(it.base()) {}
			  
			iterator_type base() const{return _ptr;}
			reference operator*() const{return *(--base());}
			reverseiterator operator+ (difference_type n) const{return reverseiterator(_ptr - n);}
			reverseiterator& operator++()
			{
				--_ptr;
				return (*this);
			}
			reverseiterator operator++(int)
			{
				reverseiterator tmp(*this);
				--(_ptr);
				return (tmp);
			}
			reverseiterator& operator+= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			reverseiterator operator- (difference_type n) const{return reverseiterator(_ptr + n);}
			reverseiterator& operator--()
			{
				++_ptr;
				return (*this);
			}
			reverseiterator operator--(int)
			{
				reverseiterator tmp(*this);
				++(_ptr);
				return (tmp);
			}
			reverseiterator& operator-= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*(--base())));
			}
			reference operator[] (difference_type n) const {return (*(--base() - n));}
	};
	
	template <class Iterator>
	bool operator== (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator== (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator!= (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator< (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator< (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator<= (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator> (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator>= (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverseiterator<Iterator> operator+ (
				typename reverseiterator<Iterator>::difference_type n,
				const reverseiterator<Iterator>& it)
	{
		return (reverseiterator<Iterator>(it.base() - n));
	}

	template <class Iterator>
	typename reverseiterator<Iterator>::difference_type operator- (
				const reverseiterator<Iterator>& lhs,
				const reverseiterator<Iterator>& rhs)
	{
		return(rhs.base() - lhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	typename reverseiterator<Iterator_L>::difference_type operator- (
				const reverseiterator<Iterator_L>& lhs,
				const reverseiterator<Iterator_R>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif