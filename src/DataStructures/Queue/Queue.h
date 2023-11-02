#include<iostream>

#ifndef QUEUE_H
#define QUEUE_H 

static int MAX = 10;

template <class X>
class queue
{
    X *arr;

    int rear;
    int count;

    

    public:
        queue(int size = MAX);
        void enqueue(X newValue);
        X dequeue();

        int size();
        bool isEmpty();
        ~queue();
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
    // If the array is full, resize it
    if (count == MAX) {
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

    rear++;
    arr[rear] = newValue;
    count++;
}

template <class X>
X queue<X>::dequeue()
{
    // If array is empty, return default constructor
    if(count == 0){
         // Assuming X has a default constructor
        return X();
    }

    X dequeuedValue = arr[0];

    // Shift elements to the left to fill the gap
    for (int i = 0; i < count - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Adjust rear and count
    rear--;
    count--;

    return dequeuedValue;
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

template <class X>
queue<X>::~queue()
{
    delete[] arr;
}

#endif