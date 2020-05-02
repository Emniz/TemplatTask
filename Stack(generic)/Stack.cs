using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack_generic_
{
    class Stack<T> : ICloneable
    {
        T[] array;
        public int size;
        public int head;

        public Stack(int size)
        {
            this.size = size;
            this.array = new T[this.size];
            this.head = 0;
        }

        public void Push(T elem)
        {
            if (this.head >= this.size)
                throw new InvalidOperationException("Stack is full!");
            array[this.head++] = elem;
        }

        public T Pop()
        {
            if (this.head <= 0)
                throw new InvalidOperationException("Stack is empty!");
            T elem = this.array[--this.head];
            array[head] = default(T);
            return elem;
        }
        public void print()
        {
            for (int i = 0; i < head; i++)
                Console.Write("{0} ",array[i]);
            Console.WriteLine();
        }
        public Stack<T> StackMerge(Stack<T> second)
        {
            Stack<T> merge = new Stack<T>(head + second.head);
            int index = 0;
            while (merge.head != head)
            {
                merge.Push(array[merge.head]);
            }
            while (merge.head != second.head + head)
            {
                merge.Push(second.array[index]);
                index++;
            }
            return merge;
        }
        public object Clone()
        {
            Stack<T> stack = new Stack<T>(this.array.Length);
            stack.array = (T[])this.array.Clone();
            stack.head = this.head;
            stack.size = this.size;
            return stack;
        }
    }
}
