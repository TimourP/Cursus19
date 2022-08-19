/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:00:39 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/19 20:32:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENABLE_IF_H
# define ENABLE_IF_H

# include <iostream>

namespace ft
{
	// https://en.cppreference.com/w/cpp/types/enable_if
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
	struct is_integral_struct
	{
		static const bool	value = is_integral;
		typedef T			type;
	};

	template <class T>
	struct is_integral : public is_integral_struct<false, bool> {};

	template <>
	struct is_integral<bool> : public is_integral_struct<true, bool> {};

	template <>
	struct is_integral<char> : public is_integral_struct<true, char> {};

	template <>
	struct is_integral<wchar_t> : public is_integral_struct<true, wchar_t> {};

	template <>
	struct is_integral<signed char> : public is_integral_struct<true, signed char> {};

	template <>
	struct is_integral<short int> : public is_integral_struct<true, short int> {};

	template <>
	struct is_integral<int> : public is_integral_struct<true, int> {};

	template <>
	struct is_integral<long int> : public is_integral_struct<true, long int> {};

	template <>
	struct is_integral<long long int> : public is_integral_struct<true, long long int> {};

	template <>
	struct is_integral<unsigned char> : public is_integral_struct<true, unsigned char> {};

	template <>
	struct is_integral<unsigned short int> : public is_integral_struct<true, unsigned short int> {};

	template <>
	struct is_integral<unsigned int> : public is_integral_struct<true, unsigned int> {};

	template <>
	struct is_integral<unsigned long int> : public is_integral_struct<true, unsigned long int> {};

	template <>
	struct is_integral<unsigned long long int> : public is_integral_struct<true, unsigned long long int> {};
	
}

#endif // ENABLE_IF_H