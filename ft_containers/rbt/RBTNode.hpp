/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:14:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 13:58:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RBT_NODE_H
# define RBT_NODE_H

#include "Pair.hpp"

enum COLOR
{
	RED,
	BLACK
};

namespace ft 
{
	template <class Key, class T,class Compare>
	class RBTNode
	{
		
	public:
		typedef ft::pair<const Key, T> value_type;
		typedef ft::RBTNode<const Key, T, Compare> node_type;
		typedef Compare key_compare;
		typedef node_type* pointer;

		RBTNode(const value_type& val, const key_compare &compare, pointer end) : value(val), end(end), compare(compare)
		{
			parent = left = right = NULL;

			// RBTNode is created during insertion
			// RBTNode is red at insertion
			color = RED;
		}
		
		RBTNode(const node_type &copy) : value(copy.value), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent), end(copy.end), compare(copy.compare)
		{
		}

		// returns pointer to uncle
		pointer uncle()
		{
			// If no parent or grandparent, then no uncle
			if (parent == NULL || parent->parent == NULL)
				return NULL;

			if (parent->isOnLeft())
				// uncle on right
				return parent->parent->right;
			else
				// uncle on left
				return parent->parent->left;
		}

		// check if node is left child of parent
		bool isOnLeft() { return this == parent->left; }

		// returns pointer to sibling
		pointer sibling()
		{
			// sibling null if no parent
			if (parent == NULL)
				return NULL;

			if (isOnLeft())
				return parent->right;

			return parent->left;
		}

		// moves node down and moves given node in its place
		void moveDown(pointer nParent)
		{
			if (parent != NULL)
			{
				if (isOnLeft())
				{
					parent->left = nParent;
				}
				else
				{
					parent->right = nParent;
				}
			}
			nParent->parent = parent;
			parent = nParent;
		}

		bool hasRedChild()
		{
			return (left != NULL and left->color == RED) || (right != NULL and right->color == RED);
		}
		
		
		pointer		iterate(void) const {
			const node_type	*k = this;
			node_type		*right = k->right;
			node_type		*parent = k->parent;
			
			if (right)
				return node_type::get_smallest(right);
			while (parent && parent->right == k)
			{
				k = parent;
				parent = k->parent;
			}
			if (parent && parent->left == k)
				return parent;
			return end;
		}
		pointer		reverse_iterate(void) const {
			if (!parent && !left && !right)
				return end;
			const node_type	*k = this;
			node_type	*left = k->left;
			node_type	*parent = k->left;
			if (left)
				return node_type::get_biggest(left);
			while (parent && parent->left == k)
			{
				k = parent;
				parent = k->parent;
			}
			if (parent)
				return parent;
			return end;
		}

		static pointer		get_smallest(pointer ptr) {
			while (ptr && ptr->left)
				ptr = ptr->left;
			return ptr;
		}
		
		static pointer		get_biggest(pointer ptr) {
			while (ptr && ptr->right)
				ptr = ptr->right;
			return ptr;
		}
		
		
		bool	operator==(node_type const &rhs) const {
			return !compare(value.first, rhs.value.first) && !compare(rhs.value.first, value.first);
		}
		
		bool	operator!=(node_type const &rhs) const {
			return !(*this == rhs);
		}
		
		bool	operator<(node_type const &rhs) const {
			return compare(value.first, rhs.value.first);
		}
		
		bool	operator>(node_type const &rhs) const {
			return compare(rhs.value.first, value.first);
		}
		
		bool	operator<=(node_type const &rhs) const {
			return !(this > rhs);
		}
		
		bool	operator>=(node_type const &rhs) const {
			return !(this < rhs);
		}

		value_type value;
		COLOR color;
		pointer left, right, parent, end;
		key_compare compare;
		
	};
}

#endif