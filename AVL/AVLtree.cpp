#include "AVLtree.h"
#include <iostream>
using namespace std;

int main()
{
	AVLTree<int> Tree = AVLTree<int>();
	Tree.insert(2);
	Tree.insert(4);
	Tree.insert(8);
	Tree.insert(16);
	Tree.insert(32);
	Tree.insert(5);
	Tree.Del(5);
	int* array = Tree.Leaves();
	for (int i = 0; i < Tree.getCount(); i++)
		cout << array[i] << " ";
	delete[] array;
}