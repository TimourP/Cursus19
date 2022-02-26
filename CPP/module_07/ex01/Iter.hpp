/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:08:04 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 13:34:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <string>
#include <iostream>

template <typename Array>
size_t array_size(Array const &array)
{
	return sizeof(array) / sizeof(array[0]);
}

template <typename T>
void ft_print(T const &elem)
{
	std::cout << elem << std::endl;
}

template <typename Array>
void iter(Array *ptr, size_t len, void (*fct)(Array x))
{
	for (size_t i = 0; i < len; i++)
		fct(ptr[i]);
}

template <typename Array>
void iter(Array *ptr, size_t len, void (*fct)(Array *x))
{
	for (size_t i = 0; i < len; i++)
		fct(ptr[i]);
}

template <typename Array>
void iter(Array *ptr, size_t len, void (*fct)(Array const &x))
{
	for (size_t i = 0; i < len; i++)
		fct(ptr[i]);
}

#endif // ITER_H
