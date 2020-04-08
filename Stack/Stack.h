#include <iostream>
#include <stack>
using namespace std;
#pragma once
template <typename T>
class Stack
{
private:
    T* array;
    int size;
    int head;
public:
    Stack(int Full) {
        this->size = Full;
        this->array = new T[size];
        this->head = 0;
    }
    Stack(const Stack<T>& stack) {
        this->head = Stack.head;
        this->array = new T[Stack.size];
        this->array = Stack.array;
    }
};

