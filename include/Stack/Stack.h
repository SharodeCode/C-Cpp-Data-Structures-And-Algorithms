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
        X peek();
        bool isEmpty();
        int size();

        ~Stack();
    
    private:
        void resizeArray();
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
    // If the array is full, resize it
    if (count == MAX) {
        resizeArray();
    }

    arr[++top] = newValue;
    count++;
}

template <class X>
void Stack<X>::resizeArray()
{
    int newSize = 2 * MAX;  // Rezise by doubling previous size
    X *newArr = new X[newSize];

    // Copy elements from the old array to the new one
    for (int i = 0; i < count; ++i) {
        newArr[i] = arr[i];
    }

    // Delete the old array
    delete[] arr;

    // Update the array pointer and size
    arr = newArr;
    MAX = newSize;
}

template <class X>
X Stack<X>::pop()
{
    // If array is empty, return default constructor
    if(count == 0){
         // Assuming X has a default constructor
        return X();
    }

    X item = arr[top--];
    count--;

    return item;
}

template <class X>
X Stack<X>::peek()
{
    // If array is empty, return default constructor
    if(count == 0){
         // Assuming X has a default constructor
        return X();
    }

    return arr[top];
}

template <class X>
int Stack<X>::size()
{
    return count;
}

template <class X>
bool Stack<X>::isEmpty()
{
    return (size() == 0);
}

template <class X>
Stack<X>::~Stack()
{
    delete[] arr;
}

#endif