#include "stack_linked.h"
#include<iostream>
using namespace std;

template <class ItemType>
LinkedStackType<ItemType>::LinkedStackType()
{
    topPtr = NULL;
}

template <class ItemType>
void LinkedStackType<ItemType>::MakeEmpty()
{
    topPtr = NULL;
}

template <class ItemType>
bool LinkedStackType<ItemType>::IsEmpty()
{
    return topPtr == NULL;
}

template <class ItemType>
bool LinkedStackType<ItemType>::IsFull()
{

    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
void LinkedStackType<ItemType>::Push(ItemType newItem)
{
    NodeType<ItemType>* location;
    location = new NodeType<ItemType>;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
}

template <class ItemType>
void LinkedStackType<ItemType>::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    else
    {
        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
ItemType LinkedStackType<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}
