/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:09:09 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/30 16:53:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft 
{

	template <class T1, class T2>
	class pair
	{

		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type first;
			second_type second;

			pair(void) : first(0), second(0) {};
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
			pair (const first_type& a, const second_type& b): first(a), second(b) {};
			
	};

	template <class T1, class T2>
  	pair<T1,T2> make_pair (T1 x, T2 y) {
		return pair<T1,T2>(x, y);
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	enum COLOR
	{
		RED,
		BLACK
	};

	template <class Key, class T>
	class Node
	{
	public:
		typedef pair<const Key, T> value_type;

		value_type value;
		COLOR color;
		Node *left, *right, *parent;

		Node(const Key& key, const T& val) : value(key, val)
		{
			parent = left = right = NULL;

			// Node is created during insertion
			// Node is red at insertion
			color = RED;
		}

		Node(const value_type& val) : value(val)
		{
			parent = left = right = NULL;

			// Node is created during insertion
			// Node is red at insertion
			color = RED;
		}

		// returns pointer to uncle
		Node *uncle()
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
		Node *sibling()
		{
			// sibling null if no parent
			if (parent == NULL)
				return NULL;

			if (isOnLeft())
				return parent->right;

			return parent->left;
		}

		// moves node down and moves given node in its place
		void moveDown(Node *nParent)
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

	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");

	template <class Key, class T>
	class RBTree
	{
		typedef Node<const Key, T> node_type;
		typedef size_t										size_type;

		node_type *root;	
		node_type *end;

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

			node_type *newV = new node_type(u->value);
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

			node_type *newU = new node_type(v->value);
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
			
			delete u;
			delete v;
			return newU;
		}

		// deletes the given node
		void deleteNode(node_type *v)
		{
			node_type *u = BSTreplace(v);

			// True when u and v are both black
			bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
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

					// delete v from the tree
					if (v->isOnLeft())
					{
						parent->left = NULL;
					}
					else
					{
						parent->right = NULL;
					}
				}
				delete v;
				return;
			}

			if (v->left == NULL or v->right == NULL)
			{
				// v has 1 child
				if (v == root)
				{
					// v is root, assign the value of u to v, and delete u
					delete v;
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
					delete v;
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
			if (node != nullptr && node != end)
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

	public:
		// initialize root
		typedef pair<const Key, T> value_type;

		RBTree() {
			root = NULL;
			ft::pair<int, int> p;
			end = new node_type(p);
		}

		node_type *getRoot() {
			return root;
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
		node_type *search(Key n) const
		{
			node_type *temp = root;
			while (temp != NULL)
			{
				if (n < temp->value.first)
				{
					if (temp->left == NULL || temp->left == end)
						break;
					else
						temp = temp->left;
				}
				else if (n == temp->value.first)
				{
					break;
				}
				else
				{
					if (temp->right == NULL || temp->right == end)
						break;
					else
						temp = temp->right;
				}
			}

			return temp;
		}

		// inserts the given value to tree
		void insert(value_type n)
		{
			node_type *newNode = new node_type(n);

			if (root == NULL)
			{
				// when root is null
				// simply insert value at root
				newNode->color = BLACK;
				root = newNode;
			}
			else
			{
				node_type *temp = search(n.first);

				if (temp->value == n)
				{
					// return if value already exists
					return;
				}

				// if value is not found, search returns the node
				// where the value is to be inserted

				// connect new node to correct node
				newNode->parent = temp;

				if (n < temp->value)
					temp->left = newNode;
				else
					temp->right = newNode;

				// fix red red voilaton if exists
				fixRedRed(newNode);
			}

			node_type *max_n = max_node();
			if (newNode == max_n) {
				newNode->right = end;
				end->parent = newNode;
			}
		}

		// utility function that deletes the node with given value
		void deleteByKey(Key n)
		{
			if (root == NULL)
				// Tree is empty
				return;

			node_type *v = search(n);

			if (v->value.first != n)
			{
				return;
			}

			deleteNode(v);
		}
	};
}