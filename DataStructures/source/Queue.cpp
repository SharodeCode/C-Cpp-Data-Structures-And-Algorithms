#include <iostream>
#include "Queue.h"

template <class X>
queue<X>::queue(int size)
{
    capacity = size;
}

template <class X>
bool queue<X>::isEmpty()
{
    return false;
}