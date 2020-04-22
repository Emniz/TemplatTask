﻿#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
    Stack<int> stack(5);
    Stack<int> stackSecond(3);
    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.push(8);
    stack.push(11);
    stack.print();
    stackSecond.push(3);
    stackSecond.push(5);
    stackSecond.push(1);
    stackSecond.print();
    stack.pop();
    stack.StackMerge(stackSecond);
    stack.print();
}