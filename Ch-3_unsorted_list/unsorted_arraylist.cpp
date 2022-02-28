#include <iostream>
#include "item_type.cpp"
using namespace std;

const int MAX_ITEM = 5;

class UnsortedType {

public:
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType, bool&);
    void PutItem(ItemType);
    void DeleteItem(ItemType);
    void ResetList();
    ItemType GetNextItem();

private:
    int length = 0;
    ItemType info[MAX_ITEM];
    int currentPos = 0;
};

void UnsortedType::MakeEmpty() {
    length = 0;
}

bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEM);
}

int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;
    moreToSearch = (location < length);
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
        case GREATER: location++;
            moreToSearch = (location < length);
            break;
        case EQUAL: found = true;
            item = info[location];
            break;
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
    int location = 0;
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    info[location] = info[length - 1];
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}


int main() {
    UnsortedType list;

    ItemType i1(5);
    list.PutItem(i1);
    list.PutItem(ItemType(10));
    list.PutItem(ItemType(15));
    list.PutItem(ItemType(20));
    list.PutItem(ItemType(25));

    for (int i = 0; i < 5; i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    list.DeleteItem(ItemType(10));
    list.PutItem(ItemType(8888));

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    return 0;
}