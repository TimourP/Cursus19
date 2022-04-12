/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:09:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 10:10:19 by tpetit           ###   ########.fr       */
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
	this->_nbrs = new std::vector<int>;
};

Span::Span(Span const &to_copy) : _N(to_copy._N){};

Span &Span::operator=(Span const &rhs)
{
	this->_nbrs = rhs._nbrs;
	this->_N = rhs._N;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_nbrs->size() == this->_N)
		throw std::out_of_range("Index out of range");
	this->_nbrs->push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (this->_nbrs->size() == this->_N)
			throw std::out_of_range("Index out of range");
		this->_nbrs->push_back(*begin);
		begin++;
	}
}

unsigned int Span::shortestSpan(void) const
{
	int shortestSpan = -1;
	int last_number = 0;

	std::sort(this->_nbrs->begin(), this->_nbrs->end());

	last_number = *this->_nbrs->begin();

	for (std::vector<int>::iterator it = this->_nbrs->begin(); it != this->_nbrs->end(); ++it)
	{
		if (it != this->_nbrs->begin())
		{
			if (shortestSpan == -1 || shortestSpan >= *it - last_number)
			{
				shortestSpan = *it - last_number;
				last_number = *it;
			}
		}
	}
	return shortestSpan;
}

unsigned int Span::longestSpan(void) const
{
	int longestSpan;

	longestSpan = *std::max_element(this->_nbrs->begin(), this->_nbrs->end()) - *std::min_element(this->_nbrs->begin(), this->_nbrs->end());
	return longestSpan;
}