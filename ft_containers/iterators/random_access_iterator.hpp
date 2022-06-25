/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:00:26 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/25 17:56:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESSITERATOR_H
#define RANDOM_ACCESSITERATOR_H

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <class T>
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
		random_access_iterator(void) : p(nullptr){};
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
			return random_access_iterator(this->p + n);
		}

		random_access_iterator operator-(difference_type n) const
		{
			return random_access_iterator(this->p - n);
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
		return (lhs.base() - rhs.base());
	};
}

#endif // RANDOM_ACCESSITERATOR_H