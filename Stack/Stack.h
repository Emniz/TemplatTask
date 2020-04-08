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
    void push(T elem)
    {
        if (this->head >= this->size)
            throw out_of_range("Stack is full");
        array[this->head++] = elem;
    }
    void pop()
    {
        if (this->head <= 0)
            throw out_of_range("Stack is empty");
        this->head--;
    }
};

