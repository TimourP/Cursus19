/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:38:49 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 09:51:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class ElemNotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "ElemNotFound.";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	if (container.begin() == container.end())
		throw ElemNotFound();
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw ElemNotFound();
	return it;
}

#endif // EASYFIND_H