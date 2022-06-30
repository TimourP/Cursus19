/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:35:18 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/30 16:29:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include "../rbt/RedBlackTree.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
	class map
	{

		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type,mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			// typedef ft::random_access_iterator<T>				iterator;
			// typedef ft::random_access_iterator<const T>			const_iterator;
			// typedef ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef int											difference_type;
			typedef size_t										size_type;

			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0) {
				
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

			map (const map& x);

			~map() {};

			bool empty() const {
				return this->p.empty();
			};

			size_type size() const;
			
			size_type max_size() const;


			mapped_type& operator[] (const key_type& k);


			/*pair<iterator,bool>*/ void insert (const value_type& val) {
				this->p.insert(val);
			};

			//iterator insert (iterator position, const value_type& val);

			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);


			// void erase (iterator position);

			size_type erase (const key_type& k);

			// void erase (iterator first, iterator last);


			void swap (map& x);


			void clear();


			allocator_type get_allocator() const;


			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			// pair<iterator,iterator>             equal_range (const key_type& k);


			size_type count (const key_type& k) const;


			value_compare value_comp() const;


			key_compare key_comp() const;

		private:
			ft::RBTree<Key, T> p;

			allocator_type _alloc;
			size_type _size;
			size_type _max_size;
	};
}

#endif // VECTOR_H
