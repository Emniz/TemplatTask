#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
template <class T>
class AVLTree;

template <class T>
class AVLNode
{
private:
	T data;
	int height;
	AVLNode* left, * right;
	AVLNode(T data)
	{
		this->data = data;
		this->height = 1;
		this->left = nullptr;
		this->right = nullptr;
	}
	void MakeHeight()
	{
		int leftHeight, rightHeight;
		if (this->left != nullptr)
			leftHeight = this->left->height;
		else
			leftHeight = 0;
		if (this->right != nullptr)
			rightHeight = this->right->height;
		else
			rightHeight = 0;
		this->height = max(leftHeight, rightHeight) + 1;
	}
	int GetBalance()
	{
		int leftHeight, rightHeight;
		if (this->left != nullptr)
			leftHeight = this->left->height;
		else
			leftHeight = 0;
		if (this->right != nullptr)
			rightHeight = this->right->height;
		else
			rightHeight = 0;
		return rightHeight - leftHeight;
	}

public:
	friend class AvlTree<T>;
};

