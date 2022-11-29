/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:32:59 by Tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 15:40:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	protected:
		container_type c;

	public:
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr){};

		// Returns whether the vector is empty (i.e. whether its size is 0).
		// Constant complexity
		bool empty(void) const
		{
			return c.empty();
		};

		// Returns the number of elements in the stack.
		// Constant complexity because get size attribute
		size_type size(void) const
		{
			return c.size();
		};

		// Returns a reference to the top element in the stack.
		value_type &top(void)
		{
			return c.back();
		};

		const value_type &top(void) const
		{
			return c.back();
		};

		// Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
		void push(const value_type &val)
		{
			c.push_back(val);
		};

		// Removes the element on top of the stack, effectively reducing its size by one.
		void pop(void)
		{
			c.pop_back();
		};

	private:
		template <class T1, class Container1>
		friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		template <class T1, class Container1>
		friend bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		template <class T1, class Container1>
		friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		template <class T1, class Container1>
		friend bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		template <class T1, class Container1>
		friend bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		template <class T1, class Container1>
		friend bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
}

#endif // STACK_H