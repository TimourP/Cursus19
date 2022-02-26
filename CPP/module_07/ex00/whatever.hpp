/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:09:51 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 15:20:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <string>
#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &min(T const &x, T const &y)
{
	return (y <= x ? y : x);
}

template <typename T>
T const &max(T const &x, T const &y)
{
	return (y >= x ? y : x);
}

#endif // WHATEVER_H
