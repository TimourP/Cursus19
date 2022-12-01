/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:09:09 by tpetit            #+#    #+#             */
/*   Updated: 2022/12/01 11:31:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RBTNode.hpp"
#include "../utils/less.hpp"
#include <memory>
#include "Pair.hpp"
#include "../iterators/map_iterator.hpp"

#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

namespace ft 
{
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");

	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
	class RBTree
	{
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<const Key, T>								value_type;
		typedef RBTNode<const Key, T, Compare>						node_type;
		typedef typename Alloc::template rebind<node_type>::other	allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef Compare												key_compare;
		typedef size_t												size_type;
		typedef ft::map_iterator<const key_type, mapped_type, key_compare>				iterator;

		RBTree(const key_compare &comp = key_compare(), const allocator_type & allocat = allocator_type()) : root(NULL), alloc(allocat), size(0), compare(comp) {
			value_type p;
			end = alloc.allocate(1);
			alloc.construct(end, node_type(p, compare, root));
			end->setEnd(end);
		}

		RBTree(const RBTree<Key, T, Compare, Alloc> & src) : root(NULL), alloc(src.alloc), size(src.size), compare(src.compare) {
			value_type p;
			end = alloc.allocate(1);
			alloc.construct(end, node_type(p, compare, root));
			end->setEnd(end);
			if (!size)
				return;
			for (node_type *node = node_type::get_smallest(src.root); node != src.end; node = node->iterate())
				this->insert(node->value, true);
			return ;
		};
		
		~RBTree() {
			clear_tree(root);
			if (end) {
				alloc.destroy(end);
				alloc.deallocate(end, 1);
			}
		}

		void clear_tree(node_type *node) {
			if (!node)
				return;
			if (node->right)
				clear_tree(node->right);
			if (node->left)
				clear_tree(node->left);
			if (node == end)
				end = NULL;
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}

		node_type *getRoot() const
		{
			return root;
		}
		
		node_type *getEnd(void) const
		{
			return end;
		}

		void print(void) const
		{
			printRBTRec("", root, false);
		};

		bool empty(void) const {
			return !this->root;
		}

		// searches for given value
		// if found returns the node (used for delete)
		// else returns the last node while traversing (used in insert)
		node_type *search(const value_type& n) const
		{
			node_type tmp(n, compare, end);
			node_type *temp = root;
			
			while (temp)
			{
				if (tmp == *temp) {
					return temp;
				}
				else if (tmp > *temp)
					temp = temp->right;
				else
					temp = temp->left;
			}
			return end;
		}
		
		void unAttachEnd(void) {
			if (end->parent) {
				end->parent->right = NULL;
			}
			end->parent = NULL;
		}
		
		void attachEnd(void) {
			if (root) {
				node_type *temp = root->get_biggest(root);
				temp->right = end;
				end->parent = temp;
			}
		}
		
		pair<iterator, bool> insert(value_type n, bool flag)
		{
			node_type *newNode = alloc.allocate(1);
			alloc.construct(newNode, node_type(n, compare, end));
			node_type tmp(n, compare, end);

			(void)flag;

			if (root == NULL)
			{
				// when root is null
				// simply insert value at root
				unAttachEnd();
				newNode->color = BLACK;
				root = newNode;
				size = 1;
				attachEnd();
				return ft::make_pair(newNode, true);
			}
			else
			{
				node_type *temp = search(n);
				unAttachEnd();
				if (*temp == tmp && temp != end)
				{
					// return if value already exists
					attachEnd();
					alloc.destroy(newNode);
					alloc.deallocate(newNode, 1);
					return ft::make_pair(temp, false);;
				}
				++size;

				if (temp == end) {
					node_type	*previous = NULL;
					temp = root;
					while (temp && temp != end)
					{
						previous = temp;
						if (tmp < *temp)
							temp = temp->left;
						else
							temp = temp->right;
					}
					temp = previous;
				}

				// if value is not found, search returns the node
				// where the value is to be inserted

				// connect new node to correct node
				newNode->parent = temp;

				if (*newNode < *temp)
					temp->left = newNode;
				else
					temp->right = newNode;

				// fix red red voilaton if exists
				fixRedRed(newNode);
				attachEnd();
				return ft::make_pair(newNode, true);
			}
		}

		// utility function that deletes the node with given value
		bool deleteByKey(const value_type n)
		{
			if (root == NULL || size == 0) {
				// Tree is empty
				return false;
			}
			
			node_type *v = search(n);

			if (v == end || !v)
			{
				return false;
			}
			unAttachEnd();
			bool del = deleteNode(v);
			if (del)
				size--;
			attachEnd();
			return true;
		}

		void deleteIterator(iterator n)
		{
			unAttachEnd();
			bool del = deleteNode(n);
			if (del)
				size--;
			attachEnd();
		}

		size_t get_size( void ) const
		{
			return size;
		}

		void	swap(RBTree& rhs)
		{
			node_type	*tmp_end = end;
			node_type	*tmp_root = root;
			size_t			tmp_size = size;

			this->end = rhs.getEnd();
			this->root = rhs.getRoot();
			this->size = rhs.get_size();

			rhs.end = tmp_end;
			rhs.root = tmp_root;
			rhs.size = tmp_size;
		}

		node_type *lower_bound(key_type k) const {
			node_type *rush_until = root;
			node_type *prev = rush_until;

			while (rush_until && rush_until != end)
			{
				prev = rush_until;
				if (rush_until->value.first == k)
					return rush_until;
				else if (rush_until->value.first < k)
					rush_until = rush_until->right;
				else
					rush_until = rush_until->left;
			}
			if (!prev || prev == end)
				return end;
			else if (prev->value.first < k) {
				return prev->iterate();
			}
			return prev;
		}

		node_type *upper_bound(key_type k) const {
			node_type *rush_until = root;
			node_type *prev = rush_until;

			while (rush_until && rush_until != end)
			{
				prev = rush_until;
				if (rush_until->value.first == k) {
					return rush_until->iterate();
				}
				else if (rush_until->value.first < k)
					rush_until = rush_until->right;
				else
					rush_until = rush_until->left;
			}
			if (!prev || prev == end)
				return end;
			else if (prev->value.first < k) {
				return prev->iterate();
			}
			return prev;
		}

		allocator_type getAlloc(void) const {
			return alloc;
		}
		
	private:

		node_type		*root;	
		node_type		*end;
		allocator_type	alloc;
		size_t			size;
		const key_compare	compare;

		void swapColors(node_type *x1, node_type *x2)
		{
			COLOR temp;
			temp = x1->color;
			x1->color = x2->color;
			x2->color = temp;
		}

		void fixRedRed(node_type *x)
		{
			// if x is root color it black and return
			if (x == root)
			{
				x->color = BLACK;
				return;
			}

			// initialize parent, grandparent, uncle
			node_type *parent = x->parent, *grandparent = parent->parent,
				*uncle = x->uncle();

			if (parent->color != BLACK)
			{
				if (uncle != NULL && uncle->color == RED)
				{
					// uncle red, perform recoloring and recurse
					parent->color = BLACK;
					uncle->color = BLACK;
					grandparent->color = RED;
					fixRedRed(grandparent);
				}
				else
				{
					// Else perform LR, LL, RL, RR
					if (parent->isOnLeft())
					{
						if (x->isOnLeft())
						{
							// for left right
							swapColors(parent, grandparent);
						}
						else
						{
							leftRotate(parent);
							swapColors(x, grandparent);
						}
						// for left left and left right
						rightRotate(grandparent);
					}
					else
					{
						if (x->isOnLeft())
						{
							// for right left
							rightRotate(parent);
							swapColors(x, grandparent);
						}
						else
						{
							swapColors(parent, grandparent);
						}

						// for right right and right left
						leftRotate(grandparent);
					}
				}
			}
		}

		// left rotates the given node
		void leftRotate(node_type *x)
		{
			// new parent will be node's right child
			node_type *nParent = x->right;

			// update root if current node is root
			if (x == root)
				root = nParent;

			x->moveDown(nParent);

			// connect x with new parent's left element
			x->right = nParent->left;
			// connect new parent's left element with node
			// if it is not null
			if (nParent->left != NULL)
				nParent->left->parent = x;

			// connect new parent with x
			nParent->left = x;
		}

		void rightRotate(node_type *x)
		{
			// new parent will be node's left child
			node_type *nParent = x->left;

			// update root if current node is root
			if (x == root)
				root = nParent;

			x->moveDown(nParent);

			// connect x with new parent's right element
			x->left = nParent->right;
			// connect new parent's right element with node
			// if it is not null
			if (nParent->right != NULL)
				nParent->right->parent = x;

			// connect new parent with x
			nParent->right = x;
		}

		

		void replace_node(node_type *parent, node_type *k, node_type *replacer) {
			if (!parent)
				root = replacer;
			else if (k == parent->left)
				parent->left = replacer;
			else
				parent->right = replacer;
			if (replacer)
				replacer->parent = parent;
			alloc.destroy(k);
			alloc.deallocate(k, 1);
			return ;
		}

		void transplant_node(node_type *parent, node_type *k, node_type *replacer) {
			if (!parent)
				root = replacer;
			else if (k == parent->left)
				parent->left = replacer;
			else
				parent->right = replacer;
			if (replacer)
				replacer->parent = parent;
			return ;
		}

		pair<node_type*, bool> create_child(node_type *parent, bool is_left) {
			node_type	*child = (is_left ? parent->left : parent->right);
			if (child)
				return pair<node_type*, bool>(child, false);
			node_type	*new_node = alloc.allocate(1);
			alloc.construct(new_node, node_type(value_type(), compare, end));
			new_node->parent = parent;
			new_node->color = BLACK;
			is_left ? parent->left = new_node : parent->right = new_node;
			return pair<node_type*, bool>(new_node, true);
		}

		bool is_black(node_type *k) {
			if (!k || k->color == BLACK)
				return true;
			return false;
		}

		bool is_red(node_type *k) {
			if (k && k->color == RED)
				return true;
			return false;
		}

		void fix_deletion(node_type *k) {
			while (root != k && this->is_black(k))
			{

				node_type	*parent = k->parent;
				bool		is_left = (k == k->parent->left);
				node_type	*brother = is_left ? parent->right : parent->left;

				if (this->is_red(brother))
				{
					brother->color = BLACK;
					parent->color = RED;
					is_left ? leftRotate(parent) : rightRotate(parent);
					parent = k->parent;
					brother = is_left ? parent->right : parent->left;
				}
				if (this->is_black(brother) && this->is_black(brother->left) && this->is_black(brother->right))
				{
					brother->color = RED;
					k = parent;
					parent = parent->parent;
				}
				else
				{
					if ( (is_left && this->is_black(brother) && this->is_black(brother->right) && this->is_red(brother->left))
						|| (!is_left && this->is_black(brother) && this->is_black(brother->left) && this->is_red(brother->right)) )
					{
						is_left ? brother->left->color = BLACK : brother->right->color = BLACK;
						brother->color = RED;
						is_left ? rightRotate(brother) : leftRotate(brother);
						parent = k->parent;
						brother = ( is_left ? parent->right : parent->left );
					}
					brother->color = parent->color;
					parent->color = BLACK;
					is_left ? brother->right->color = BLACK : brother->left->color = BLACK;
					is_left ? leftRotate(parent) : rightRotate(parent);
					k = root;
				}
			}
			k->color = BLACK;
		}
		
		// deletes the given node
		bool deleteNode(node_type *v)
		{
			node_type				*left = v->left;
			node_type				*right = v->right;
			pair<node_type*, bool>	check = pair<node_type*, bool>(v, true);
			COLOR					color = v->color;
		
			if (v == end || !v)
				return false;
			if (!right)
			{
				check = this->create_child(v, true);
				this->replace_node(v->parent, v, check.first);
			}
			else if (!left)
			{
				check = this->create_child(v, false);
				this->replace_node(v->parent, v, check.first);
			}
			else
			{
				node_type	*smallest = node_type::get_smallest(right);
				color = smallest->color;
				check = this->create_child(smallest, false);
				if (v == smallest->parent)
					check.first->parent = smallest; // attention
				else
				{
					this->transplant_node(smallest->parent, smallest, smallest->right);
					smallest->right = right;
					smallest->right->parent = smallest;
				}
				this->replace_node(v->parent, v, smallest);
				smallest->left = left;
				smallest->left->parent = smallest;
				smallest->color = v->color;
			}
			if (color == BLACK) {
				this->fix_deletion(check.first);
			}
			if (check.second)
			{
				if (check.first->parent)
					check.first == check.first->parent->left ? check.first->parent->left = NULL : check.first->parent->right = NULL;

				if (check.first == root)
					root = NULL;
				alloc.destroy(check.first);
				alloc.deallocate(check.first, 1);
			}
			return true;
		}

		void printRBTRec(const std::string &prefix, node_type *node, bool isLeft) const
		{
			if (node != NULL && node != end)
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──");

				// print the value of the node
				if (node->color == BLACK)
					std::cout << node->value.first << std::endl;
				else
					std::cout << red << node->value.first << reset << std::endl;

				// enter the next tree level - left and right branch
				printRBTRec(prefix + (isLeft ? "│   " : "    "), node->right, true);
				printRBTRec(prefix + (isLeft ? "│   " : "    "), node->left, false);
			}
			else if (node != end)
			{
				std::cout << prefix;
				std::cout << (isLeft ? "├──" : "└──");
				std::cout << std::endl;
			} else
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──");

				// print the value of the node
				std::cout << red << " end" << reset << std::endl;
			}
			
		}

	
	};
}

#endif