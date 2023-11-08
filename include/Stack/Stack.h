#include<iostream>

#ifndef STACK_H
#define STACK_H 

static int MAX = 10;

template <class X>
class Stack
{
    X *arr;

    int top;
    int count;

    public:
        Stack(int size = MAX);
        void push(X newValue);
        X pop();

        ~Stack();
};


template <class X>
Stack<X>::Stack(int size)
{
    arr = new X[size];
    top = -1;
    count = 0;
}

template <class X>
void Stack<X>::push(X newValue)
{
    arr[++top] = newValue;
}

template <class X>
X Stack<X>::pop()
{
    X item = arr[top--];

    return item;
}

template <class X>
Stack<X>::~Stack()
{
    delete[] arr;
}

#endif