/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:52:05 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 06:24:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <string>
#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void) : std::stack<T, Container>(){};
	~MutantStack(void){};
	MutantStack(MutantStack const &copy) : std::stack<T, Container>(copy) {}

	MutantStack &operator=(MutantStack const &rhs)
	{
		return *this;
	}

	typedef typename Container::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif // MUTANTSTACK_H