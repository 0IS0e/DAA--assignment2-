#include "stack.h"
#include <iostream>

using namespace std;
template <typename T>
Stack<T>::Stack(int size)
{
    this->SIZE = size;
    this->S = new T[this->SIZE];
    this->top = -1;
}

template <typename T>
void Stack<T>::operator+(T item)
{
    if(this->top == this->SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    this->S[++this->top] = item;
}

template <typename T>
void Stack<T>::operator-()
{
    if(this->top == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    this->top--;
}

template <typename T>
T Stack<T>::peek()
{
    if(this->top == -1)
    {
        cout << "Stack is empty" << endl;
        return T();
    }
    return this->S[this->top];
}

template <typename T>
void Stack<T>::print_Stack()
{
    cout << "\nCurrent Stack: ";
    for (int i = 0; i <= this->top; i++)
    {
        cout << this->S[i] << " ";
    }
    cout << endl;
}

template class Stack<int>;