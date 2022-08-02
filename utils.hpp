#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>

const class
{
    public:
        template<class T>
        operator T*() const { return (0); }

        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
        void operator&() const;
}u_nullptr = {};

namespace ft
{
    class input_iterator_tag { };

    class output_iterator_tag { };

	class forward_iterator_tag : public input_iterator_tag { };

	class bidirectional_iterator_tag : public forward_iterator_tag { };

	class random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <class T1, class T2, class Result>
    struct binary_function
    {
            typedef T1 first_argument_type;
            typedef T2 second_argument_type;
            typedef Result result_type;
    };

	template <class T>
    struct less : binary_function<T, T, bool>
    {
    	bool operator() (const T& x, const T& y) const { return (x < y); }
    };

    template <typename Iterater_L, typename Iterater_R>
	bool equal(Iterater_L L_begin, Iterater_L L_end, Iterater_R R_begin)
	{
		for (; L_begin != L_end; ++L_begin, ++R_begin)
			if (*L_begin != *R_begin)
				return false;
		return true;
	}

    template <typename Iterater_L,typename IIterater_R,typename Compare>
    bool lexicographical_compare(Iterater_L first1, IIterater_R last1,
								 Iterater_L first2, IIterater_R last2,
								 Compare comp)
	{
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

};

# endif