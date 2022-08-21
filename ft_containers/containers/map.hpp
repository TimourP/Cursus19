/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:35:18 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/21 09:06:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include "../rbt/RedBlackTree.hpp"
#include "../rbt/RBTNode.hpp"
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
	class map
	{

		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef ft::map_iterator<const key_type, mapped_type, value_compare>				iterator;
			typedef ft::map_iterator<const key_type, const mapped_type, value_compare>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef int											difference_type;
			typedef size_t										size_type;

			// Constructors
			
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :tree(comp), _alloc(alloc), _size(0) {
				
			};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

			map (const map& x);

			// Destructor
			~map() {};
			
			map& operator=( const map& other );
			
			mapped_type& at( const Key& key );
			
			const mapped_type& at( const Key& key ) const;
			
			mapped_type& operator[]( const Key& key );
			
			iterator begin(void) {
				if (empty())
					return end();
				return iterator(RBTNode<key_type, mapped_type, value_compare>::get_smallest(tree.getRoot()));
			}
			
			const_iterator begin() const;
			
			iterator end(void) {
				return iterator(tree.getEnd());
			}
			
			const_iterator end() const;
			
			reverse_iterator rbegin();
			
			const_reverse_iterator rbegin() const;
			
			reverse_iterator rend();
			
			const_reverse_iterator rend() const;
			
			bool empty() const {
				return this->tree.empty();
			};

			size_type size() const;
			
			size_type max_size() const;

			pair<iterator,bool> void insert (const value_type& val) {
				this->tree.insert(val);
			};
			
			iterator insert( iterator hint, const value_type& value );

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);

			void erase (iterator position);

			size_type erase (const key_type& k);

			void erase (iterator first, iterator last);

			void swap (map& x);

			void clear();

			allocator_type get_allocator() const;


			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			pair<iterator,iterator>             equal_range (const key_type& k);

			size_type count (const key_type& k) const;

			iterator find( const Key& key );
			
			const_iterator find( const Key& key ) const;
			
			iterator lower_bound( const Key& key );
			
			const_iterator lower_bound( const Key& key ) const;
			
			iterator upper_bound( const Key& key );
			
			const_iterator upper_bound( const Key& key ) const;

			value_compare value_comp() const;

			key_compare key_comp() const;

		private:
			
			ft::RBTree<key_type, mapped_type, value_compare, Allocator> tree;
			allocator_type _alloc;
			size_type _size;
			size_type _max_size;
	};
}

#endif // MAP_H
