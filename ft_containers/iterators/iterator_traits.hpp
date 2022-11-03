/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:00:39 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/03 15:00:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

#include <iostream>
#include <stddef.h>

namespace ft
{

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	// https://m.cplusplus.com/reference/iterator/iterator_traits/ for declarations

	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	class iterator_traits<T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class T>
	class iterator_traits<const T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

}

#endif // ITERATOR_TRAITS_H