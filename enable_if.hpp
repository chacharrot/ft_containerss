/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:49:18 by scha              #+#    #+#             */
/*   Updated: 2022/08/03 23:49:20 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include "utils.hpp"

namespace ft
{
	template <bool, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> 
	{
		typedef T type;
	};

	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};
	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<short int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short int>
	{
		static const bool value = true;
	};

	template <>
    struct is_integral<long int>
	{
		static const bool value = true;
	};


	template <>
     struct is_integral<unsigned long int>
	{
		static const bool value = true;
	};


	template <>
    struct is_integral<long long int>
	{
		static const bool value = true;
	};


	template <>
    struct is_integral<unsigned long long int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template <class T>
	struct is_random_access_tag
	{
		static const bool value = false;
	};
	template <>
	struct is_random_access_tag<class random_access_iterator_tag>
	{
		static const bool value = true;
	};

		template <>
	struct is_random_access_tag<class bidirectional_iterator_tag>
	{
		static const bool value = false;
	};
}

#endif