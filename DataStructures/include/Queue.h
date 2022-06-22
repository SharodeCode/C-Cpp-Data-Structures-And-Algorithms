#include<iostream>

#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

template <class X>
class queue
{
    int capacity;
    int rear;

    public:
        queue(int size = MAX);
        bool isEmpty();
};

template <class X>
queue<X>::queue(int size)
{
    capacity = size;
}

template <class X>
bool queue<X>::isEmpty()
{
    return true;
}

#endif