/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:02:32 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 14:10:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LESS_H
# define LESS_H

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};
	
	template <class T>
	struct less : public binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y) const { return x < y; }
	};
	
	template <class T>
	struct more : public binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y) const { return x > y; }
	};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{ 
		for (; first1 != last1; ++first1, ++first2)
  		{
    		if (first2 == last2 || *first2 < *first1)
				return false;
    		else if (*first1 < *first2)
				return true;
  		}
  		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
			if (!(*first1 == *first2))
				return false;
		return true;
	}
}

#endif