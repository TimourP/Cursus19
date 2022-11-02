/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:13:31 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 14:20:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{

	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

	protected:
		Iterator it;

	public:
		reverse_iterator(void) : it(NULL){};

		explicit reverse_iterator(iterator_type it) : it(it){};

		template <class It>
		reverse_iterator(const reverse_iterator<It> &rev_it) : it(rev_it.base()){};

		~reverse_iterator(){};

		iterator_type base(void) const
		{
			return this->it;
		}

		reference operator*() const
        {
			iterator_type tmp = this->it - 1; 
            return *(tmp);
        }

		reference operator[](difference_type n) const
		{
			iterator_type tmp = this->it - n - 1; 
			return *(tmp);
		};

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(this->it - n);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(this->it + n);
		}

		reverse_iterator &operator++(void)
		{
			--this->it;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			std::cout << "hehe" << std::endl;
			reverse_iterator temp = *this;
			--this->it;
			return temp;
		}

		reverse_iterator &operator--(void)
		{
			++this->it;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			++this->it;
			return temp;
		}

		reverse_iterator &operator+=(difference_type n)
		{
			this->it -= n;
			return (*this);
		};

		reverse_iterator &operator-=(difference_type n)
		{
			this->it += n;
			return (*this);
		};

		pointer operator->() const
		{
			return &(operator*());
		}
	};

	template <class Iterator, class Iterator2>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() != rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	};

	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										 const reverse_iterator<Iterator> &it)
	{
		return it + n;
	};

	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs,
																   const reverse_iterator<Iterator2> &rhs)
	{
		return rhs.base() - lhs.base();
	};
}

#endif // REVERSE_ITERATOR_H