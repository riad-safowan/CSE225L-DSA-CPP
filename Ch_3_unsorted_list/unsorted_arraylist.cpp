#include <iostream>
#include "item_type.cpp"
using namespace std;

const int MAX_ITEM = 100;

class UnsortedType {

public:
    UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType, bool&);
    void PutItem(ItemType);
    void DeleteItem(ItemType);
    void ResetList();
    ItemType GetNextItem();

private:
    int length;
    ItemType info[MAX_ITEM];
    int currentPos;
};

UnsortedType::UnsortedType() {
    length = 0;
    currentPos = -1;
}

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
    for (int i = 0; i < length; i++)
    {
        if (item.ComparedTo(info[i]) == EQUAL) {
            info[i] = info[length - 1];
            length--;
            break;
        }
    }
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

    for (int i = 0; i < 20; i++)
    {
        list.PutItem(ItemType(i));
    }

    list.PutItem(ItemType(100));
    list.PutItem(ItemType(101));

    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }

    for (int i = 0; i < 20; i += 2)
    {
        list.DeleteItem(ItemType(i));
    }

    list.DeleteItem(ItemType(100));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(20));

    cout << endl;
    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    return 0;
}