using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack_generic_
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack<int> stack1 = new Stack<int>(5);
            Stack<int> stack2 = new Stack<int>(3);
            Stack<int> stackMerge = new Stack<int>(stack1.size + stack2.size);
            stack1.Push(2);
            stack1.Push(4);
            stack1.Push(6);
            stack1.Push(8);
            stack1.Push(11);
            stack2.Push(3);
            stack2.Push(5);
            stack2.Push(1);
            stack1.print();
            stack2.print();
            Console.WriteLine("После удаления:");
            stack1.Pop();
            stack2.Pop();
            stack1.print();
            stack2.print();
            Console.WriteLine("Слияние:");
            stackMerge = stack1.StackMerge(stack2);
            stackMerge.print();
        }
    }
}
