/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:52:05 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 10:23:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <string>
#include <iostream>
#include <stack>

// stack definition: template <class T, class Container = deque<T> > class stack;

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void) : std::stack<T>(){};
	~MutantStack(void){};
	MutantStack(MutantStack const &copy) : std::stack<T, Container>(copy) {
		
	}

	MutantStack &operator=(MutantStack const &rhs)
	{
		this->c = rhs.c;
		return *this;
	}

	typedef typename Container::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif // MUTANTSTACK_H