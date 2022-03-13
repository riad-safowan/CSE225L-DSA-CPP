#include "stacktype.h"
#include<iostream>
using namespace std;

template <class ItemType>
StackType<ItemType>::StackType()
{
    top = -1;
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
    return top == -1;
}

template <class ItemType>
bool StackType<ItemType>::IsFull()
{
    return top == MAX_ITEMS - 1;
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    try {
        if (IsFull()) throw FullStack();
        top++;
        items[top] = newItem;
    }
    catch (FullStack e) {
        cout << "Stack is Already full" << endl;
    }

}

template <class ItemType>
void StackType<ItemType>::Pop()
{
    try {
        if (IsEmpty()) throw EmptyStack();
        top--;
    }
    catch (EmptyStack e) {
        cout << "Stack is Empty" << endl;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::Top()
{
    try {
        if (IsEmpty()) throw EmptyStack();
        return items[top];
    }
    catch (EmptyStack e) {
        cout << "Stack is Empty" << endl;
    }
}
