#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
    Stack<int> stack(6);
    Stack<int> stackSecond(4);
    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.push(8);
    stack.push(11);
    stack.push(7);
    stackSecond.push(3);
    stackSecond.push(5);
    stackSecond.push(1);
    stackSecond.push(9);
    stack.pop();
    stack.pop();
    stackSecond.pop();
    stack.print();
    stackSecond.print();
    StackMerge(stack,stackSecond);
}