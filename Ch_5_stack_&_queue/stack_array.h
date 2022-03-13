#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int MAX_ITEMS = 5;

template <class ItemType>
class StackType
{
public:
    StackType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(ItemType);
    void Pop();
    ItemType Top();
private:
    int top;
    ItemType items[MAX_ITEMS];
};

class FullStack {};
class EmptyStack {};

#endif