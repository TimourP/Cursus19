#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <string>
#include <iostream>

const std::string red("\033[0;31m");
const std::string reset("\033[0m");
int node_count = 0;

class RBTNode
{
public:
	RBTNode(void);
	RBTNode(int key, RBTNode *parent);
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

RBTNode::RBTNode(int key, RBTNode *parent) {
	this->key = key;
	this->parent = parent;
	this->is_black = false;
	this->right_child = NULL;
	this->left_child = NULL;
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
		node_count++;
	}
	else
	{
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──");
		std::cout << std::endl;
	}
}

void get_len_real(const RBTNode *node) {
	if (node) {
		node_count++;
		get_len_real(node->left_child);
		get_len_real(node->right_child);
	}
}

class RedBlackTree
{
public:
	RedBlackTree(void);
	~RedBlackTree(void);

	void print(void) { 
		node_count = 0;
		printRBTRec("", this->root, false);
		std::cout << node_count << std::endl;
	};

	void get_len(void){ 
		get_len_real(this->root);
		std::cout << node_count << std::endl;
	};
	void delete_node(int key);
	void destroy(void) { 
		this->destroy(this->root);
		this->root = NULL;
	};
	void insert(int key);
	RBTNode *search(int key) { return this->search(key, this->root); };

private:
	RBTNode *root;

	void destroy(RBTNode *leaf);
	void insert(int key, RBTNode *leaf);
	RBTNode *search(int key, RBTNode *leaf);
	void left_rotate(RBTNode *x);
	void right_rotate(RBTNode *x);
	void balance(RBTNode *newNode);
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


// take parent to make left rotation
void RedBlackTree::left_rotate(RBTNode *x) {
	RBTNode *y = x->right_child;

	x->right_child = y->left_child;
	if (y->left_child) {
	  y->left_child->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent) {
	  this->root = y;
	} else if (x == x->parent->left_child) {
	  x->parent->left_child = y;
	} else {
	  x->parent->right_child = y;
	}
	y->left_child = x;
	x->parent = y;
}

// take parent to make right rotation
void RedBlackTree::right_rotate(RBTNode *x) {
	RBTNode *y = x->left_child;

	x->left_child = y->right_child;
	if (y->right_child) {
	  y->right_child->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent) {
	  this->root = y;
	} else if (x == x->parent->right_child) {
	  x->parent->right_child = y;
	} else {
	  x->parent->left_child = y;
	}
	y->right_child = x;
	x->parent = y;
}

void RedBlackTree::balance(RBTNode *newNode) {
	RBTNode *z;
	RBTNode *p;

	z = newNode;
	p = newNode->parent;
	if (!p || p->is_black)
		return ;
	// if p is the left child of his parent
	if (p->parent && p->parent->left_child == p) {
		// if the right child of the parent of p is a red child
		if (p->parent->right_child && !p->parent->right_child->is_black) {
			p->is_black = true;
			p->parent->right_child->is_black = true;
			p->parent->is_black = false;
			balance(p->parent);
		} else if (p->right_child == z) {
			newNode = p;
			left_rotate(newNode);
			balance(newNode);
		} else if (p->parent) {
			p->is_black = true;
			p->parent->is_black = false;
			right_rotate(p->parent);
			balance(newNode);
		}
	} else {
		if (p->parent && p->parent->left_child && !p->parent->left_child->is_black) {
			p->is_black = true;
			p->parent->left_child->is_black = true;
			p->parent->is_black = false;
			balance(p->parent);
		} else if (p->left_child == newNode) {
			newNode = p;
			right_rotate(p);
			balance(newNode);
		} else {
			p->is_black = true;
			p->parent->is_black = false;
			left_rotate(p->parent);
			balance(newNode);
		}
	}
}

void RedBlackTree::insert(int key, RBTNode *leaf)
{
	int tmp_key;
	if (key < leaf->key)
	{
		if (leaf->left_child != NULL)
			insert(key, leaf->left_child);
		else
		{
			leaf->left_child = new RBTNode(key, leaf);
			balance(leaf->left_child);
			this->root->is_black = true;
		}
	}
	else if (key > leaf->key)
	{
		if (leaf->right_child != NULL)
			insert(key, leaf->right_child);
		else
		{
			leaf->right_child = new RBTNode(key, leaf);
			balance(leaf->right_child);
			this->root->is_black = true;
		}
	}
}

RBTNode *minimum_value(RBTNode *from) {
	if (from->left_child)
		return minimum_value(from->left_child);
	return from;
}

void RedBlackTree::delete_node(int key)
{
	RBTNode *nodeToBeDeleted = this->search(key);
	RBTNode *x;
	RBTNode *y;
	int originalColor = nodeToBeDeleted->is_black;

	if (!nodeToBeDeleted)
		return ;
	if (nodeToBeDeleted == this->root && !nodeToBeDeleted->right_child && !nodeToBeDeleted->left_child) {
		delete nodeToBeDeleted;
		this->root = NULL;
	}
	else if (!nodeToBeDeleted->left_child) {
		if (!nodeToBeDeleted->right_child) {
			if (nodeToBeDeleted->parent->right_child == nodeToBeDeleted)
				nodeToBeDeleted->parent->right_child = NULL;
			else
				nodeToBeDeleted->parent->left_child = NULL;
			delete nodeToBeDeleted;
			return;
		}
		x = nodeToBeDeleted->right_child;
		x->parent = nodeToBeDeleted->parent;
		if (!nodeToBeDeleted->parent)
			this->root = x;
		else if (nodeToBeDeleted->parent->right_child == nodeToBeDeleted)
			nodeToBeDeleted->parent->right_child = x;
		else
			nodeToBeDeleted->parent->left_child = x;
		delete nodeToBeDeleted;
	} else if (!nodeToBeDeleted->right_child) {
		x = nodeToBeDeleted->left_child;
		x->parent = nodeToBeDeleted->parent;
		if (!nodeToBeDeleted->parent)
			this->root = x;
		else if (nodeToBeDeleted->parent->right_child == nodeToBeDeleted)
			nodeToBeDeleted->parent->right_child = x;
		else
			nodeToBeDeleted->parent->left_child = x;
		delete nodeToBeDeleted;
	} else {
		y = minimum_value(nodeToBeDeleted->right_child);
		originalColor = y->is_black;
		x = y->right_child;
		if (y->parent == nodeToBeDeleted) {
			x->parent = y;
			y->left_child = x;
		} else {
			
		}
		
	}
}

#endif // REDBLACKTREE_H