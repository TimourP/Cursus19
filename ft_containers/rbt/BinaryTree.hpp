#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include <iostream>

class BTNode
{
public:
	BTNode(void);
	~BTNode(void);

	int key;
	BTNode *left_child;
	BTNode *right_child;
	BTNode *parent;
	bool is_black;
};

BTNode::BTNode(void)
{
}

BTNode::~BTNode(void)
{
}

class BinaryTree
{
public:
	BinaryTree(void);
	~BinaryTree(void);

	void destroy(void) { this->destroy(this->root); };
	void insert(int key);
	BTNode *search(int key) { return this->search(key, this->root); };

private:
	BTNode *root;

	void destroy(BTNode *leaf);
	void insert(int key, BTNode *leaf);
	BTNode *search(int key, BTNode *leaf);
};

BinaryTree::BinaryTree()
{
	this->root = NULL;
}

BinaryTree::~BinaryTree()
{
	this->destroy();
}

BTNode *BinaryTree::search(int key, BTNode *leaf)
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

void BinaryTree::destroy(BTNode *leaf)
{
	if (leaf != NULL)
	{
		destroy(leaf->left_child);
		destroy(leaf->right_child);
		delete leaf;
	}
}

void BinaryTree::insert(int key)
{
	if (this->root != NULL)
		insert(key, this->root);
	else
	{
		root = new BTNode;
		root->key = key;
		root->left_child = NULL;
		root->right_child = NULL;
		root->parent = NULL;
		root->is_black = true;
	}
}

void BinaryTree::insert(int key, BTNode *leaf)
{
	if (key < leaf->key)
	{
		if (leaf->left_child != NULL)
			insert(key, leaf->left_child);
		else
		{
			leaf->left_child = new BTNode;
			leaf->left_child->key = key;
			leaf->left_child->left_child = NULL;
			leaf->left_child->right_child = NULL;
			leaf->left_child->is_black = false;
			leaf->left_child->parent = leaf;
		}
	}
	else if (key >= leaf->key)
	{
		if (leaf->right_child != NULL)
			insert(key, leaf->right_child);
		else
		{
			leaf->right_child = new BTNode;
			leaf->right_child->key = key;
			leaf->right_child->left_child = NULL;
			leaf->right_child->right_child = NULL;
			leaf->right_child->is_black = false;
			leaf->right_child->parent = leaf;
		}
	}
}

#endif // BINARYTREE_H
