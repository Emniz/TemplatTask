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
	friend class AVLTree<T>;
};
template <class T>
class AVLTree
{
private:
	AVLNode<T>* root;
	int count;
	bool ch;
	void Balance(AVLNode<T>*& index)
	{
		int OldHeight = index->height;
		index->MakeHeight();
		int balance = index->Balance();
		if (balance > 1)
		{
			if (index->right->Balance() < 0)
				this->TurnLeft(index->right);
			this->TurnRight(index);
			if (index->height == OldHeight)
				this->ch = false;
		}
		else if (balance < -1)
		{
			if (index->left->Balance() > 0)
				this->TurnRight(index->left);
			this->TurnLeft(index);
			if (index->height == OldHeight)
				this->ch = false;
		}
	}

	void Insert(AVLNode<T>*& index, T data)
	{
		if (index == nullptr)
		{
			this->ch = true;
			index = new AVLNode<T>(data);
		}
		else
		{
			if (data < index->data)
			{
				this->Insert(index->left, data);
				if (this->ch)
					this->Balance(index);
			}
			else
			{
				this->Insert(index->right, data);
				if (this->ch)
					this->Balance(index);
			}
		}
	}
	void TurnLeft(AVLNode<T>*& index)
	{
		AVLNode<T>* temp;
		temp = index->left;
		index->left = temp->right;
		temp->right = index;
		index->MakeHeight();
		temp->MakeHeight();
		index = temp;
	}

	void TurnRight(AVLNode<T>*& index)
	{
		AVLNode<T>* temp;
		temp = index->right;
		index->right = temp->left;
		temp->left = index;
		index->MakeHeight();
		temp->MakeHeight();
		index = temp;
	}
public:
};
