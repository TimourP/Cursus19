/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:09:09 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/03 16:22:17 by tpetit           ###   ########.fr       */
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
			for (node_type *node = node_type::get_smallest(src.root); node != src.end; node = node->iterate())
				this->insert(node->value);
			return ;
		};
		
		~RBTree() {
			alloc.destroy(end);
			alloc.deallocate(end, 1);
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

		// inserts the given value to tree
		iterator insert(value_type n)
		{
			node_type *newNode = alloc.allocate(1);
			alloc.construct(newNode, node_type(n, compare, end));
			node_type tmp(n, compare, end);
			unAttachEnd();

			if (root == NULL)
			{
				// when root is null
				// simply insert value at root
				newNode->color = BLACK;
				root = newNode;
				size = 1;
				attachEnd();
				return newNode;
			}
			else
			{
				node_type *temp = search(n);

				if (*temp == tmp && temp != end)
				{
					// return if value already exists
					attachEnd();
					return temp;
				}
				// std::cout << "insert value" << std::endl;
				size++;

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
				return newNode;
			}
		}

		pair<iterator, bool> insert(value_type n, bool flag)
		{
			node_type *newNode = alloc.allocate(1);
			alloc.construct(newNode, node_type(n, compare, end));
			node_type tmp(n, compare, end);
			unAttachEnd();

			if (root == NULL)
			{
				// when root is null
				// simply insert value at root
				newNode->color = BLACK;
				root = newNode;
				size = 1;
				attachEnd();
				return ft::make_pair(newNode, true);
			}
			else
			{
				node_type *temp = search(n);

				if (*temp == tmp && temp != end)
				{
					// return if value already exists
					attachEnd();
					return ft::make_pair(temp, false);;
				}
				// std::cout << "insert value" << std::endl;
				size++;

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
			if (root == NULL)
				// Tree is empty
				return false;
			// std::cout << "try delete: " << n.first << std::endl;
			unAttachEnd();
			node_type *v = search(n);

			if (v == end)
			{
				// std::cout << "diff" <<std::endl;
				attachEnd();
				return false;
			}

			deleteNode(v);
			attachEnd();
			return true;
		}

		void deleteIterator(iterator n)
		{
			unAttachEnd();
			deleteNode(n);
			attachEnd();
		}

		size_t get_size( void ) const
		{
			return size;
		}

		void	swap(RBTree *rhs)
		{
			node_type	*tmp_end = end;
			node_type	*tmp_root = root;
			size_t			tmp_size = size;

			end = rhs->end;
			root = rhs->root;
			size = rhs->size;

			rhs->end = tmp_end;
			rhs->root = tmp_root;
			rhs->size = tmp_size;
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

		void swapColors(node_type *x1, node_type *x2)
		{
			COLOR temp;
			temp = x1->color;
			x1->color = x2->color;
			x2->color = temp;
		}

		// fix red red at given node
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

		// find node that do not have a left child
		// in the subtree of the given node
		node_type *successor(node_type *x)
		{
			node_type *temp = x;

			while (temp->left != NULL)
				temp = temp->left;

			return temp;
		}

		// find node that replaces a deleted node in BST
		node_type *BSTreplace(node_type *x)
		{
			// when node have 2 children
			if (x->left != NULL and x->right != NULL)
				return successor(x->right);

			// when leaf
			if (x->left == NULL and x->right == NULL)
				return NULL;

			// when single child
			if (x->left != NULL)
				return x->left;
			else
				return x->right;
		}

		node_type * swapValues(node_type *u, node_type *v) {

			node_type *newV = alloc.allocate(1);
			alloc.construct(newV, node_type(u->value, compare, end));

			newV->left = v->left;
			if (newV->left)
				newV->left->parent = newV;
			newV->right = v->right;
			if (newV->right)
				newV->right->parent = newV;
			newV->color = v->color;
			newV->parent = v->parent;
			if (newV->parent && v->isOnLeft())
				v->parent->left = newV;
			else if (newV->parent)
				v->parent->right = newV;

			node_type *newU = alloc.allocate(1);
			alloc.construct(newU, node_type(v->value, compare, end));
			newU->left = u->left;
			if (newU->left)
				newU->left->parent = newU;
			newU->right = u->right;
			if (newU->right)
				newU->right->parent = newU;
			newU->color = u->color;
			newU->parent = u->parent;
			if (newU->parent && u->isOnLeft())
				u->parent->left = newU;
			else if (newU->parent)
				u->parent->right = newU;

			if (v == root)
				root = newV;
			if (u == root)
				root = newU;
			
			// alloc.destroy(v);
			// alloc.deallocate(v, 1);
			// alloc.destroy(u);
			// alloc.deallocate(u, 1);
			return newU;
		}

		// deletes the given node
		void deleteNode(node_type *v)
		{
			node_type *u = BSTreplace(v);

			// True when u and v are both black
			bool uvBlack = ((u == NULL || u->color == BLACK) and (v->color == BLACK));
			node_type *parent = v->parent;

			if (u == NULL)
			{
				// u is NULL therefore v is leaf
				if (v == root)
				{
					// v is root, making root null
					root = NULL;
				}
				else
				{
					if (uvBlack)
					{
						// u and v both black
						// v is leaf, fix double black at v
						fixDoubleBlack(v);
					}
					else
					{
						// u or v is red
						if (v->sibling() != NULL)
							// sibling is not null, make it red"
							v->sibling()->color = RED;
					}

					if (v->isOnLeft())
					{
						parent->left = NULL;
					}
					else
					{
						parent->right = NULL;
					}
				}
				size--;
				alloc.destroy(v);
				alloc.deallocate(v, 1);
				return;
			}

			if (v->left == NULL || v->right == NULL)
			{
				// v has 1 child
				if (v == root)
				{
					alloc.destroy(v);
					alloc.deallocate(v, 1);
					root = u;
					root->parent = NULL;
					root->color = BLACK;
				}
				else
				{
					// Detach v from tree and move u up
					if (v->isOnLeft())
					{
						parent->left = u;
					}
					else
					{
						parent->right = u;
					}
					alloc.destroy(v);
					alloc.deallocate(v, 1);
					u->parent = parent;
					if (uvBlack)
					{
						// u and v both black, fix double black at u
						fixDoubleBlack(u);
					}
					else
					{
						// u or v red, color u black
						u->color = BLACK;
					}
				}
				size--;
				return;
			}

			// v has 2 children, swap values with successor and recurse

			deleteNode(swapValues(u, v));
		}

		void fixDoubleBlack(node_type *x)
		{
			if (x == root)
				// Reached root
				return;

			node_type *sibling = x->sibling(), *parent = x->parent;
			if (sibling == NULL)
			{
				// No sibiling, double black pushed up
				fixDoubleBlack(parent);
			}
			else
			{
				if (sibling->color == RED)
				{
					// Sibling red
					parent->color = RED;
					sibling->color = BLACK;
					if (sibling->isOnLeft())
					{
						// left case
						rightRotate(parent);
					}
					else
					{
						// right case
						leftRotate(parent);
					}
					fixDoubleBlack(x);
				}
				else
				{
					// Sibling black
					if (sibling->hasRedChild())
					{
						// at least 1 red children
						if (sibling->left != NULL and sibling->left->color == RED)
						{
							if (sibling->isOnLeft())
							{
								// left left
								sibling->left->color = sibling->color;
								sibling->color = parent->color;
								rightRotate(parent);
							}
							else
							{
								// right left
								sibling->left->color = parent->color;
								rightRotate(sibling);
								leftRotate(parent);
							}
						}
						else
						{
							if (sibling->isOnLeft())
							{
								// left right
								sibling->right->color = parent->color;
								leftRotate(sibling);
								rightRotate(parent);
							}
							else
							{
								// right right
								sibling->right->color = sibling->color;
								sibling->color = parent->color;
								leftRotate(parent);
							}
						}
						parent->color = BLACK;
					}
					else
					{
						// 2 black children
						sibling->color = RED;
						if (parent->color == BLACK)
							fixDoubleBlack(parent);
						else
							parent->color = BLACK;
					}
				}
			}
		}

		node_type *max_node(void) {
			node_type *tmp = root;

			while (tmp->right)
				tmp = tmp->right;
			return tmp;
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