/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:14:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/20 13:38:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RBT_NODE_H
# define RBT_NODE_H

enum COLOR
{
	RED,
	BLACK
};

namespace ft 
{
	template <class T, class Compare>
	class RBTNode
	{
		
	public:
		typedef T value_type;
		typedef ft::RBTNode<value_type, Compare> node_type;
		typedef Compare value_compare;
		typedef node_type* pointer;

		value_type value;
		COLOR color;
		pointer left, right, parent;

		RBTNode(const value_type& val) : value(val)
		{
			parent = left = right = NULL;

			// RBTNode is created during insertion
			// RBTNode is red at insertion
			color = RED;
		}
		
		RBTNode(const node_type &copy) : value(copy.value), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent)
		{
			std::cout << "Copy" << std::endl;
		}

		// returns pointer to uncle
		pointer uncle()
		{
			// If no parent or grandparent, then no uncle
			if (parent == NULL or parent->parent == NULL)
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
			return (left != NULL and left->color == RED) or
				(right != NULL and right->color == RED);
		}
	};
}

#endif