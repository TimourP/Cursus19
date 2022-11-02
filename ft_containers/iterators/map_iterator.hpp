/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:27:42 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 14:16:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_H
#define MAP_ITERATOR_H

#include <iostream>
#include "iterator_traits.hpp"
#include "../rbt/RBTNode.hpp"
#include "../utils/less.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<T> >
	class map_iterator
	{

	public:
		typedef RBTNode<Key, T, Compare>				Node;
		typedef pair<Key, T>							value_type;
		typedef pair<Key, T>&							reference;
		typedef pair<Key, T>*							pointer;
		typedef Node*									node_pointer;
		typedef map_iterator<Key, T, Compare>			iterator;
		typedef ptrdiff_t						difference_type;
		typedef bidirectional_iterator_tag		iterator_category;

	protected:
		node_pointer p;

	public:
		map_iterator(void) {}
		map_iterator(map_iterator const &copy) : p(copy.p) {}
		map_iterator(node_pointer ptr) : p(ptr) {}
		~map_iterator(void) {}
		
		operator			map_iterator<const Key, const T, Compare >() const {
			const iterator &it = *this;
			return reinterpret_cast<const map_iterator<const Key, const T, Compare >& >(it);
		}
		operator			node_pointer() const {
			return this->p;
		}
		
		node_pointer const	&base(void) const {
			return this->p;
		}

		iterator			&operator=(map_iterator const &rhs) {
			p = rhs.p;
			return *this;
		}
		
		reference			operator*(void) const {
			return p->value;
		}
		
		pointer				operator->(void) const {
			return &p->value;
		}
		
		iterator			&operator++(void) {
			p = p->iterate();
			return *this;
		}
		
		iterator			operator++(int) {
			map_iterator	tmp(*this);
			p = p->iterate();
			return tmp;
		}
		
		iterator			&operator--(void) {
			p = p->reverse_iterate();
			return *this;
		}
		
		iterator			operator--(int) {
			map_iterator	tmp(*this);
			p = p->reverse_iterate();
			return tmp;
		}
	};
	
	template <class Key1, class Key2, class T1, class T2, class Compare>
	bool									operator==(const map_iterator<Key1, T1, Compare> &left, const map_iterator<Key2, T2, Compare> &right)
	{
		return left.base() == reinterpret_cast<typename map_iterator<Key1, T1, Compare>::node_pointer>(right.base());
	}

	template <class Key1, class Key2, class T1, class T2, class Compare>
	bool									operator!=(const map_iterator<Key1, T1, Compare> &left, const map_iterator<Key2, T2, Compare> &right)
	{
		return !(left == right);
	}
}

#endif //MAP_ITERATOR_H