/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:27:42 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/20 12:11:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_H
#define MAP_ITERATOR_H

#include <iostream>
#include "iterator_traits.hpp"
#include "../utils/less.hpp"

namespace ft
{
	template <class T, class Compare = ft::less<T>, class Node = RBTNode<T, Compare> >
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

	public:
		typedef ft::iterator<ft::random_access_iterator_tag, T> iterator_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;

	protected:
		pointer p;

	public:
		random_access_iterator(void) : p(NULL){};
		random_access_iterator(pointer p) : p(p){};
		explicit random_access_iterator(iterator_type it) : p(it.p){};
		~random_access_iterator(){};

		pointer base(void) const
		{
			return this->p;
		}

		operator random_access_iterator<const T>() const { return this->p; };

		reference operator*(void) const
		{
			return *this->p;
		};

		reference operator[](difference_type n) const
		{
			return *(this->p + n);
		};

		random_access_iterator operator+(difference_type n) const
		{
			return this->p + n;
		}

		random_access_iterator operator-(difference_type n) const
		{
			return this->p - n;
		}

		random_access_iterator &operator++(void)
		{
			this->p++;
			return *this;
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator temp = *this;
			++(*this);
			return temp;
		}

		random_access_iterator &operator--(void)
		{
			this->p--;
			return *this;
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator temp = *this;
			--(*this);
			return temp;
		}

		random_access_iterator &operator+=(difference_type n)
		{
			this->p += n;
			return (*this);
		};

		random_access_iterator &operator-=(difference_type n)
		{
			this->p -= n;
			return (*this);
		};

		pointer operator->() const
		{
			return &(operator*());
		}
	};

	template <class Iterator, class Iterator2>
	bool operator==(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator!=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() != rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator<(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator<=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator>(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator>=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	};

	template <class Iterator>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n,
											   const random_access_iterator<Iterator> &it)
	{
		return it + n;
	};

	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator> &lhs,
																		 const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	};

	template <class Iterator, class Iterator2>
	typename ft::random_access_iterator<Iterator>::difference_type operator-(
		const ft::random_access_iterator<Iterator> &lhs,
		const ft::random_access_iterator<Iterator2> &rhs)
	{
		return lhs.base() - rhs.base();
	};
}

#endif //MAP_ITERATOR_H