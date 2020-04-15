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
		int balance = index->GetBalance();
		if (balance > 1)
		{
			if (index->right->GetBalance() < 0)
				this->TurnLeft(index->right);
			this->TurnRight(index);
			if (index->height == OldHeight)
				this->ch = false;
		}
		else if (balance < -1)
		{
			if (index->left->GetBalance() > 0)
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
	void FindToDelete(AVLNode<T>*& replac, AVLNode<T>* index, AVLNode<T>*& temp)
	{
		if (replac->right != nullptr)
		{
			this->FindToDelete(replac->right, index, temp);
			this->Balance(replac);
		}
		else
		{
			temp = replac;
			index->data = replac->data;
			replac = replac->left;
		}
	}
	void Delete(AVLNode<T>*& index, T data)
	{
		AVLNode<T>* temp;
		if (index != nullptr)
		{
			if (data < index->data)
			{
				this->Delete(index->left, data);
				this->Balance(index);
			}
			else if (data > index->data)
			{
				this->Delete(index->right, data);
				this->Balance(index);
			}
			else
			{
				temp = index;
				if (index->right == nullptr)
					index = index->left;
				else if (index->left == nullptr)
					index = index->right;
				else
					this->FindToDelete(index->left, index, temp);
				delete temp;
			}
		}
	}
	void Dispose(AVLNode<T>* index)
	{
		if (index != nullptr)
		{
			if (index->left != nullptr)
				this->Dispose(index->left);
			if (index->right != nullptr)
				this->Dispose(index->right);
			delete index;
		}
	}
	bool List(AVLNode<T>* index, T data)
	{
		if (index != nullptr)
		{
			if (data == index->data)
				return true;
			else if (data < index->data)
				return this->List(index->left, data);
			else if (data > index->data)
				return this->List(index->right, data);
		}
		return false;
	}
	void Leaves(AVLNode<T>* indexTree, T* array, int& indexArr)
	{
		if (indexTree->left != nullptr)
			Leaves(indexTree->left, array, indexArr);
		array[indexArr] = indexTree->data;
		indexArr++;
		if (indexTree->right != nullptr)
			Leaves(indexTree->right, array, indexArr);
	}
public:
	AVLTree()
	{
		this->root = nullptr;
		this->ch = false;
		this->count = 0;
	}
	AVLTree(T data)
	{
		this->root = new AVLNode<T>(data);
		this->ch = false;
		this->count = 1;
	}
	~AVLTree()
	{
		this->Dispose(this->root);
	}
	void insert(T data)
	{
		this->Insert(this->root, data);
		this->count++;
	}
	void Del(T data)
	{
		this->Delete(this->root, data);
		this->count--;
	}
	T* Leaves()
	{
		T* array = new T[this->count];
		int indexArray = 0;
		Leaves(this->root, array, indexArray);
		return array;
	}
	int getCount()
	{
		return this->count;
	}
	bool Search(T data)
	{
		return this->List(this->root, data);
	}
};
