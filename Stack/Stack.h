#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack;
template<typename T>
Stack<T> StackMerge(const Stack<T>& first, const Stack<T>& second);

template<typename T>
class Stack
{
private:
    T* array;
    int head;
    int size;
public:
    Stack(int size)
    {
        this->size = size;
        this->array = new T[this->size];
        this->head = 0;
    }
    Stack(const Stack& stack)
    {
        this->size = stack.size;
        this->array = new T[this->size];
        this->head = stack.head;
    }
  
    void push(T elem)
    {
        if (this->head == 0)
            throw std::out_of_range("Stack is full!");
        this->head++;
        this->array[this->head] = elem;
    }

    T pop()
    {
        if (this->head == size)
            throw std::out_of_range("Stack is empty!");
        T elem = this->array[this->head];
        this->head--;
        return elem;
    }
 void print()
    {
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
 ~Stack()
 {
     delete[] array;
 }

    friend Stack StackMerge<T>(const Stack<T>& first, const Stack<T>& second);
};

template<typename T>
Stack<T> StackMerge(const Stack<T>& first, const Stack<T>& second)
{
    Stack<T> merge = Stack<T>(first.size + second.size);
    int size = first.size;
    while (size != first.head)
    {
        size = size - 1;
        merge.push(first.array[size]);
    }
    size = second.size;
    while (size != second.head)
    {
        size = size - 1;
        merge.push(second.array[size]);
    }
    return merge;
}

