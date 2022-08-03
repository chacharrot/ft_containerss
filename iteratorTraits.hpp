/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:49:37 by scha              #+#    #+#             */
/*   Updated: 2022/08/03 23:49:40 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

#include <iostream>
#include "utils.hpp"
namespace ft
{
	//SECTION - ITERATOR TRAITS
	template <class Iterator> //NOTE - Main template class
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T> //NOTE - Specialized template class
	class iterator_traits<T*> //ANCHOR - Specialized for T pointer
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		T*									pointer;
			typedef		T&									reference;
			typedef		ft::random_access_iterator_tag		iterator_category;
	};

	template <class T> //NOTE - Specialized template class
	class iterator_traits<const T*> //ANCHOR - Specialized for T const pointer
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		const T*							pointer;
			typedef		const T&							reference;
			typedef		ft::random_access_iterator_tag		iterator_category;
	};
}

#endif