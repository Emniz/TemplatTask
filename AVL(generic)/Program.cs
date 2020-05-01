using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVL_generic_
{
    class Program
    {
        static void Main(string[] args)
        {
            AVLtree<int> Tree = new AVLtree<int>();
            Tree.Insert(2);
            Tree.Insert(4);
            Tree.Insert(8);
            Tree.Insert(16);
            Tree.Insert(32);
            Tree.Insert(5);
            int[] array = Tree.Leaves();
            for (int i = 0; i < Tree.GetCount(); i++)
                Console.Write("{0} ", array[i]);
            Tree.Del(5);
            Console.WriteLine();
            int[] newarray = Tree.Leaves();
            for (int i = 0; i < Tree.GetCount(); i++)
                Console.Write("{0} ", newarray[i]);
        }
    }
}
