/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:09:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 17:28:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <string>
#include <iostream>
#include <list>

class Span
{
public:
	Span(void);
	Span(unsigned int const N);
	~Span(void);
	Span(Span const &copy);
	Span &operator=(Span const &rhs);

	void addNumber(int n);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

private:
	std::list<int> *_nbrs;
	unsigned int _N;
	unsigned int _current;
};

#endif // SPAN_H
