#include<iostream>

#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

template <class X>
class queue
{
    X *arr;

    int rear;
    int count;

    public:
        queue(int size = MAX);
        void enqueue(X newValue);

        int size();
        bool isEmpty();
};

template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    rear = -1;
    count = 0;
}

template <class X>
void queue<X>::enqueue(X newValue)
{
    rear++;
    arr[rear] = newValue;
    count++;
}

template <class X>
int queue<X>::size()
{
    return count;
}

template <class X>
bool queue<X>::isEmpty()
{
    return (size() == 0);
}

#endif