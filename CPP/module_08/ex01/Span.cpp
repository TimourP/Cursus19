/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:09:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 17:36:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0)
{
}

Span::~Span(void)
{
	delete this->_nbrs;
}

Span::Span(unsigned int const N) : _N(N)
{
	this->_nbrs = new std::list<int>;
};

Span::Span(Span const &to_copy) : _N(to_copy._N){};

Span &Span::operator=(Span const &rhs)
{
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_nbrs->size() == this->_N)
		throw std::out_of_range("Index out of range");
	this->_nbrs->push_back(n);
}

unsigned int Span::shortestSpan(void) const
{
	unsigned int shortest_span = -1;
	int last_num = 0;
	bool unset = true;

	this->_nbrs->sort();
	for (int i : *this->_nbrs)
	{
		if (unset)
		{
			last_num = i;
			unset = false;
		}
		else if (i - last_num < shortest_span || shortest_span == -1)
		{
			shortest_span = i - last_num;
		}
		last_num = i;
	}
	return shortest_span;
}

unsigned int Span::longestSpan(void) const
{
	bool unset = true;
	int lowest_num = 0;
	int biggest_num = 0;

	for (int i : *this->_nbrs)
	{
		if (unset || i < lowest_num)
			lowest_num = i;
		if (unset || i > biggest_num)
			biggest_num = i;
		if (unset)
			unset = false;
	}

	return biggest_num - lowest_num;
}