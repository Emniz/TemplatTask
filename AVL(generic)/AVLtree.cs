using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVL_generic_
{
    class AVLtree<T> where T : IComparable
    {
        class AVLTree
        {
            public T data;
            public int height;
            public AVLTree left, right;
            public AVLTree(T data)
            {
                this.data = data;
                this.height = 1;
                this.left = null;
                this.right = null;
            }

            public void MakeHeight()
            {
                int leftHeight, rightHeight;
                if (this.left != null)
                    leftHeight = this.left.height;
                else
                    leftHeight = 0;
                if (this.right != null)
                    rightHeight = this.right.height;
                else
                    rightHeight = 0;
                this.height = Math.Max(leftHeight, rightHeight) + 1;
            }

            public int GetBalance()
            {
                int leftHeight, rightHeight;
                if (this.left != null)
                    leftHeight = this.left.height;
                else
                    leftHeight = 0;
                if (this.right != null)
                    rightHeight = this.right.height;
                else
                    rightHeight = 0;
                return rightHeight - leftHeight;
            }
        }
        AVLTree root;
        int count;
        bool ch;
        void Balance(ref AVLTree index)
        {
            int oldHeight = index.height;
            index.MakeHeight();
            int balance = index.GetBalance();
            if (balance > 1)
            {
                if (index.right.GetBalance() < 0)
                    this.TurnLeft(ref index.right);
                this.TurnRight(ref index);
                if (index.height == oldHeight)
                    this.ch = false;
            }
            else if (balance < -1)
            {
                if (index.left.GetBalance() > 0)
                    this.TurnRight(ref index.left);
                this.TurnLeft(ref index);
                if (index.height == oldHeight)
                    this.ch = false;
            }
        }

        void Insert(ref AVLTree index, T data)
        {
            if (index == null)
            {
                this.ch = true;
                index = new AVLTree(data);
            }
            else
            {
                if (data.CompareTo(index.data) == -1)
                {
                    this.Insert(ref index.left, data);
                    if (this.ch)
                        this.Balance(ref index);
                }
                else
                {
                    this.Insert(ref index.right, data);
                    if (this.ch)
                        this.Balance(ref index);
                }
            }
        }
        public AVLtree()
        {
            this.root = null;
            this.ch = false;
            this.count = 0;
        }

        public AVLtree(T data)
        {
            this.root = new AVLTree(data);
            this.ch = false;
            this.count = 1;
        }

        void TurnLeft(ref AVLTree index)
        {
            AVLTree temp = index.left;
            index.left = temp.right;
            temp.right = index;
            index.MakeHeight();
            temp.MakeHeight();
            index = temp;
        }

        void TurnRight(ref AVLTree index)
        {
            AVLTree temp;
            temp = index.right;
            index.right = temp.left;
            temp.left = index;
            index.MakeHeight();
            temp.MakeHeight();
            index = temp;
        }

        void FindToDelete(ref AVLTree replac, AVLTree index, ref AVLTree temp)
        {
            if (replac.right != null)
            {
                this.FindToDelete(ref replac.right, index, ref temp);
                this.Balance(ref replac);
            }
            else
            {
                temp = replac;
                index.data = replac.data;
                replac = replac.left;
            }
        }

        void Delete(ref AVLTree index, T data)
        {
            if (index != null)
            {
                if (data.CompareTo(index.data) == -1)
                {
                    this.Delete(ref index.left, data);
                    this.Balance(ref index);
                }
                else if (data.CompareTo(index.data) == 1)
                {
                    this.Delete(ref index.right, data);
                    this.Balance(ref index);
                }
                else
                {
                    AVLTree temp = index;
                    if (index.right == null)
                        index = index.left;
                    else if (index.left == null)
                        index = index.right;
                    else
                        this.FindToDelete(ref index.left, index, ref temp);
                }
            }
        }
        void Dispose(AVLTree index)
        {
            if (index != null)
            {
                if (index.left != null)
                    this.Dispose(index.left);
                if (index.right != null)
                    this.Dispose(index.right);
            }
        }
        void Leaves(AVLTree indexTree, T[] array, ref int indexArr)
        {
            if (indexTree.left != null)
                Leaves(indexTree.left, array, ref indexArr);
            array[indexArr] = indexTree.data;
            indexArr++;
            if (indexTree.right != null)
                Leaves(indexTree.right, array, ref indexArr);
        }

        bool List(AVLTree index, T data)
        {
            if (index != null)
            {
                if (data.CompareTo(index.data) == 0)
                    return true;
                else if (data.CompareTo(index.data) == -1)
                    return this.List(index.left, data);
                else if (data.CompareTo(index.data) == 1)
                    return this.List(index.right, data);
            }
            return false;
        }

        public void Insert(T data)
        {
            this.Insert(ref this.root, data);
            this.count++;
        }
        public void Del(T data)
        {
            this.Delete(ref this.root, data);
            this.count--;
        }

        bool Includes(AVLTree pointer, T data)
        {
            if (pointer != null)
            {
                if (data.CompareTo(pointer.data) == -1)
                    return this.Includes(pointer.left, data);
                else if (data.CompareTo(pointer.data) == 1)
                    return this.Includes(pointer.right, data);
                else
                    return true;
            }
            return false;
        }

        public int GetCount()
        {
            return this.count;
        }

        public T[] Leaves()
        {
            T[] array = new T[this.count];
            int arrayIndex = 0;
            Leaves(this.root, array, ref arrayIndex);
            return array;
        }
        public bool Seacrh(T data)
        {
            return this.Includes(this.root, data);
        }
    }
}
