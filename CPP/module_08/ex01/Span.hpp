/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:09:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 11:48:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
public:
	Span(void);
	Span(unsigned int const N);
	~Span(void);
	Span(Span const &copy);
	Span &operator=(Span const &rhs);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	class NoSpaceException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "This span is full.";
			}
	};

private:
	std::vector<int> *_nbrs;
	unsigned int _N;
};

#endif // SPAN_H
