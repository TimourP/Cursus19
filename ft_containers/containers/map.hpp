/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:35:18 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 14:10:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include "../rbt/RedBlackTree.hpp"
#include "../rbt/RBTNode.hpp"
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{

	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
	class map
	{

		public:

			class value_compare : public std::binary_function<pair<const Key, T>, pair<const Key, T>, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				protected:
					Compare _comp;
					value_compare(Compare c) : _comp(c) {return ;}
		
				public:
					bool operator()(const pair<const Key, T>& x, const pair<const Key, T>& y) const { return _comp(x.first, y.first); }
			};
		public:

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef ft::map_iterator<const key_type, mapped_type, key_compare>				iterator;
			typedef ft::map_iterator<const key_type, const mapped_type, key_compare>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef int											difference_type;
			typedef size_t										size_type;
			typedef RBTNode<const Key, T, Compare>						node_type;
			typedef typename	ft::RBTree<const key_type, mapped_type, key_compare, allocator_type>		tree_type;

			// Constructors
			
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : tree(comp, alloc), _alloc(alloc), key_c(comp), value_c(comp), _size(0) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : tree(comp, alloc), _alloc(alloc), key_c(comp), value_c(comp), _size(0) {
					insert(first, last);
				};

			map (const map& x) : tree(x.key_c, x._alloc), _alloc(x._alloc), key_c(x.key_c), value_c(x.value_c), _size(x.size()) {};

			// Destructor
			~map() {};
			
			map& operator=( const map& other ) {
				clear();
				insert(other.begin(), other.end());
				return *this;
			};
			
			mapped_type& at( const Key& key );
			
			const mapped_type& at( const Key& key ) const;
			
			mapped_type& operator[]( const Key& key ) {
				node_type *tmp = tree.search(ft::make_pair(key, mapped_type()));
				if (tmp != tree.getEnd())
					return tmp->value.second;
				return tree.search(ft::make_pair(key, mapped_type()))->value.second;
			};
			
			iterator begin(void) {
				if (empty())
					return end();
				return iterator(node_type::get_smallest(tree.getRoot()));
			}
			
			const_iterator begin() const {
				if (empty())
					return end();
				return iterator(node_type::get_smallest(tree.getRoot()));
			};
			
			iterator end(void) {
				return iterator(tree.getEnd());
			}
			
			const_iterator end() const {
				return (iterator(tree.getEnd()));
			};
			
			reverse_iterator rbegin() {
				return reverse_iterator(tree.getEnd());
			};
			
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(tree.getEnd());
			};
			
			reverse_iterator rend() {
				if (empty())
					return reverse_iterator(tree.getEnd());
				return reverse_iterator(node_type::get_smallest(tree.getRoot()));
			};
			
			const_reverse_iterator rend() const {
				if (empty())
					return const_reverse_iterator(tree.getEnd());
				return const_reverse_iterator(node_type::get_smallest(tree.getRoot()));
			};
			
			bool empty() const {
				return this->tree.empty();
			};

			size_type size() const {
				return tree.get_size();
			};
			
			size_type max_size() const {
				return _alloc.max_size();
			};

			pair<iterator,bool> insert (const value_type& val) {
				iterator node = this->tree.insert(val);
				return ft::make_pair(node, false);
			};
			
			iterator insert( iterator hint, const value_type& value ) {
				(void)hint;
				iterator node = this->tree.insert(value);
				return node;
			};

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last)
				{
					tree.insert(*first);
					first++;
				}
			};

			void erase (iterator position) {
				tree.deleteIterator(position);
			};

			size_type erase (const key_type& k) {
				if (tree.search(ft::make_pair(k, mapped_type())) == tree.getEnd()) 
					return 0;
				tree.deleteByKey(ft::make_pair(k, mapped_type()));
				return 1;
			};

			void erase (iterator first, iterator last) {
				iterator tmp;

				while (first != last)
				{
					tmp = first;
					first++;
					tree.deleteIterator(tmp);
				}
			}

			void swap (map& x) {
				tree.swap(&x.tree);
			};

			void clear() {
				erase(begin(), end());
			};

			allocator_type get_allocator() const {
				return allocator_type(tree.alloc);
			};


			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			};

			pair<iterator,iterator>             equal_range (const key_type& k) {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			};

			size_type count (const key_type& k) const {
				if (tree.search(ft::make_pair(k, mapped_type())) == tree.getEnd()) {
					return 0;
				}
				return 1;
			};

			iterator find( const Key& key ) {
				return iterator(tree.search(ft::make_pair(key, mapped_type())));
			};
			
			const_iterator find( const Key& key ) const {
				return iterator(tree.search(ft::make_pair(key, mapped_type())));
			};
			
			iterator lower_bound( const Key& key ) {
				return iterator(tree.lower_bound(key));
			};
			
			const_iterator lower_bound( const Key& key ) const {
				return iterator(tree.lower_bound(key));
			};
			
			iterator upper_bound( const Key& key ) {
				return iterator(tree.upper_bound(key));
			};
			
			const_iterator upper_bound( const Key& key ) const {
				return iterator(tree.upper_bound(key));
			};

			value_compare value_comp() const {
				return value_c;
			};

			key_compare key_comp() const {
				return key_c;
			};

		private:
			
			ft::RBTree<key_type, mapped_type, key_compare, Allocator> tree;
			allocator_type _alloc;
			size_type _size;
			size_type _max_size;
			key_compare key_c;
			value_compare value_c;
	};

	template <class Key, class T, class Compare, class Alloc>
  	bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		if (!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())))
			return false;
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif // MAP_H
