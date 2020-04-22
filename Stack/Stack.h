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
        this->head = stack.head;
        this->array = new T[Stack.size];
        this->array = stack.array;
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
    void print()
    {
        for (int i = 0; i < head; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    ~Stack()
    {
        delete[] array;
    }
    void StackMerge(const Stack<T>& second);
};
template<typename T>
void Stack<T>::StackMerge(const Stack<T>& second)
{
    T* merge = new T[size + second.size];
    head = 0;
    while (head < size) {
        merge[head] = array[head];
        head++;
    }
    while (head < size + second.size) {
        merge[head] = second.array[head - size];
        head++;
    }
    array = merge;
}
