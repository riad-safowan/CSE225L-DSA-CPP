#include "queuetype.h"

template<class T>
QueueType<T>::QueueType()
{
    front = -1;
    rear = -1;
}

template<class T>
void QueueType<T>::MakeEmpty() {
    front = -1;
    rear = -1;
}

template<class T>
bool QueueType<T>::IsEmpty() {
    return front == -1 && rear == -1;
}

template<class T>
bool QueueType<T>::IsFull() {
    return front == (rear + 1) % MAX_SIZE;
}

template<class T>
void QueueType<T>::Enqueue(T value) {
    if (IsFull()) {
        throw FullQueue();
    }
    if (IsEmpty()) {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % MAX_SIZE;
    data[rear] = value;
}
template<class T>
void QueueType<T>::Dequeue() {
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    if (front == rear)
        MakeEmpty();
    else
        front = (front + 1) % MAX_SIZE;
}

template<class T>
T QueueType<T>::Front()
{
    return data[front];
}

