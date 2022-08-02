
#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template <bool, class T = void> //NOTE - Main template struct
	struct enable_if {};

	template <class T> //NOTE - Specialized template struct
	struct enable_if<true, T> //ANCHOR - in case of true
	{
		typedef T type;
	};

	template <class T> //NOTE - Main template struct
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
}

#endif