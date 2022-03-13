#ifndef LSTACKTYPE_H_INCLUDED
#define LSTACKTYPE_H_INCLUDED

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class LinkedStackType
{
public:
    LinkedStackType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(ItemType);
    void Pop();
    ItemType Top();
private:
    NodeType<ItemType>* topPtr;
};

#endif