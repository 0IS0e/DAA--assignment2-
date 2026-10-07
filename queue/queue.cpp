#include "queue.h"
#include <iostream>

using namespace std;

template <typename T>
Queue<T>::Queue(int SIZE)
{
    this->SIZE = SIZE;
    this->q = new T[SIZE];
    this->front = -1;
    this->rear = -1;
}

template <typename T>
void Queue<T>::operator+(T item)
{
    if(rear == SIZE - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if(front == -1)
        front = 0;

    q[++rear] = item;
}

template <typename T>
void Queue<T>::operator-()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
        return;
    }

    front++;
}

template <typename T>
T Queue<T>::peek()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Empty\n";
        return T(); 
    }

    return q[front];
}

template <typename T>
void Queue<T>::print_Queue()
{
    if(front == -1 || front > rear)
    {
        cout << "\nQueue Empty";
        return;
    }

    cout << "\nCurrent Queue: ";

    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
}

template class Queue<int>;