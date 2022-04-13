#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include <iostream>

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

class RBTNode
{
public:
	RBTNode(void);
	~RBTNode(void);

	int key;
	RBTNode *left_child;
	RBTNode *right_child;
	RBTNode *parent;
	bool is_black;
};

RBTNode::RBTNode(void)
{
}

RBTNode::~RBTNode(void)
{
}

void printRBTRec(const std::string &prefix, const RBTNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──");

		// print the value of the node
		if (node->is_black)
			std::cout << node->key << std::endl;
		else
			std::cout << red << node->key << reset << std::endl;

		// enter the next tree level - left and right branch
		printRBTRec(prefix + (isLeft ? "│   " : "    "), node->right_child, true);
		printRBTRec(prefix + (isLeft ? "│   " : "    "), node->left_child, false);
	}
	else
	{
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──");
		std::cout << std::endl;
	}
}

class RedBlackTree
{
public:
	RedBlackTree(void);
	~RedBlackTree(void);

	void print(void) { printRBTRec("", this->root, false); };

	void destroy(void) { this->destroy(this->root); };
	void insert(int key);
	RBTNode *search(int key) { return this->search(key, this->root); };

private:
	RBTNode *root;

	void destroy(RBTNode *leaf);
	void insert(int key, RBTNode *leaf);
	RBTNode *search(int key, RBTNode *leaf);
};

RedBlackTree::RedBlackTree()
{
	this->root = NULL;
}

RedBlackTree::~RedBlackTree()
{
	this->destroy();
}

RBTNode *RedBlackTree::search(int key, RBTNode *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key)
			return leaf;
		if (key < leaf->key)
			return search(key, leaf->left_child);
		else
			return search(key, leaf->right_child);
	}
	else
		return NULL;
}

void RedBlackTree::destroy(RBTNode *leaf)
{
	if (leaf != NULL)
	{
		destroy(leaf->left_child);
		destroy(leaf->right_child);
		delete leaf;
	}
}

void RedBlackTree::insert(int key)
{
	if (this->root != NULL)
		insert(key, this->root);
	else
	{
		root = new RBTNode;
		root->key = key;
		root->left_child = NULL;
		root->right_child = NULL;
		root->parent = NULL;
		root->is_black = true;
	}
}

void DoubleRedIfSIsBlack(RBTNode *b)
{
	RBTNode *a;
	RBTNode *c;
	int tmp_key;

	if (b->parent->right_child == b)
	{
		a = b->right_child;
		c = b->parent;

		// b to c
		tmp_key = c->key;
		c->key = b->key;
		b->key = tmp_key;

		c->right_child = a;
		a->parent = c;
		b->right_child = b->left_child;
		b->left_child = c->left_child;
		if (b->left_child)
			b->left_child->parent = b;
		c->left_child = b;
		b->parent = c;
	}
	else
	{
		a = b->left_child;
		c = b->parent;

		// b to c
		tmp_key = c->key;
		c->key = b->key;
		b->key = tmp_key;

		c->left_child = a;
		a->parent = c;
		b->left_child = b->right_child;
		b->right_child = c->right_child;
		if (b->right_child)
			b->right_child->parent = b;
		c->right_child = b;
		b->parent = c;
	}
}

void DoubleRedIfSIsRed(RBTNode *y)
{
	RBTNode *z;
	RBTNode *s;

	z = y->parent;
	s = y->parent->left_child;
	if (s == y)
		s = y->parent->right_child;

	y->is_black = true;
	s->is_black = true;
	z->is_black = false;

	if (!z->parent)
	{
		z->is_black = true;
	}
	else if (!z->parent->is_black)
	{
		if (!z->parent->parent->left_child || z->parent->parent->left_child->is_black || !z->parent->parent->right_child || z->parent->parent->right_child->is_black)
		{
			DoubleRedIfSIsBlack(z->parent);
		}
		else
		{
			DoubleRedIfSIsRed(z->parent);
		}
	}
}

void RedBlackTree::insert(int key, RBTNode *leaf)
{
	if (key < leaf->key)
	{
		if (leaf->left_child != NULL)
			insert(key, leaf->left_child);
		else
		{
			leaf->left_child = new RBTNode;
			leaf->left_child->key = key;
			leaf->left_child->left_child = NULL;
			leaf->left_child->right_child = NULL;
			leaf->left_child->is_black = false;
			leaf->left_child->parent = leaf;
			if (!leaf->is_black)
			{
				if (!leaf->parent->right_child || leaf->parent->right_child->is_black)
					DoubleRedIfSIsBlack(leaf);
				else
					DoubleRedIfSIsRed(leaf);
			}
		}
	}
	else if (key >= leaf->key)
	{
		if (leaf->right_child != NULL)
			insert(key, leaf->right_child);
		else
		{
			leaf->right_child = new RBTNode;
			leaf->right_child->key = key;
			leaf->right_child->left_child = NULL;
			leaf->right_child->right_child = NULL;
			leaf->right_child->is_black = false;
			leaf->right_child->parent = leaf;
			if (!leaf->is_black)
			{
				if (!leaf->parent->left_child || leaf->parent->left_child->is_black)
					DoubleRedIfSIsBlack(leaf);
				else
					DoubleRedIfSIsRed(leaf);
			}
		}
	}
}

#endif // REDBLACKTREE_H
