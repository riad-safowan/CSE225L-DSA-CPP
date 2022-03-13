#include <iostream>
#include "item_type.cpp"
using namespace std;

const int MAX_ITEM = 100;

class SortedType {
public:
    SortedType();
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

SortedType::SortedType() {
    length = 0;
    currentPos = -1;
}

void SortedType::MakeEmpty() {
    length = 0;
}

bool SortedType::IsFull() const
{
    return (length == MAX_ITEM);
}

int SortedType::GetLength() const
{
    return length;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int low = 0, high = length - 1;
    int location = (length - 1) / 2;
    found = false;
    while (!found) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
            high = location;
            location = (high + low) / 2;
            break;
        case GREATER:
            low = location;
            location = (high + low) / 2;
            break;
        case EQUAL: found = true;
            item = info[location];
            break;
        }
    }
    return item;
}

void SortedType::PutItem(ItemType item)
{
    if (length == 0)
    {
        info[0] = item;
        length++;
        return;
    }

    int low = 0, high = length - 1;
    int location = (length - 1) / 2;
    bool done = false;
    while (!done && low <= high) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
            high = location - 1;
            location = (high + low) / 2;
            break;
        case GREATER:
            low = location + 1;
            location = (high + low) / 2;
            if (low == high && item.ComparedTo(info[location]) == LESS)
                done = true;
            else if (low > high)
                location++;
            break;
        case EQUAL: done = true;
            break;
        }
    }
    for (int i = length; i > location; i--)
    {
        info[i] = info[i - 1];
    }
    info[location] = item;
    length++;
}

void SortedType::DeleteItem(ItemType item)
{
    int low = 0, high = length - 1;
    int location = low + high / 2;
    bool found = false;
    while (!found & low <= high) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
            high = location - 1;
            location = (high + low) / 2;
            break;
        case GREATER:
            low = location + 1;
            location = (high + low) / 2;
            break;
        case EQUAL: found = true;
            break;
        }
    }
    if (found)
    {
        if (location != length - 1) {
            for (int i = location; i <= length - 1; i++)
            {
                info[i] = info[i + 1];
            }
        }
        length--;
    }
}

void SortedType::ResetList()
{
    currentPos = -1;
}

ItemType SortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

void printList(SortedType list) {
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    cout << endl;
    list.ResetList();
}


int main() {
    SortedType list;

    for (int i = 0; i < 20; i++)
    {
        list.PutItem(ItemType(i + 1));
    }
    list.PutItem(0);
    list.PutItem(ItemType(100));
    list.PutItem(ItemType(101));

    printList(list);

    for (int i = 0; i < 20; i += 2)
    {
        list.DeleteItem(ItemType(i));
    }

    list.DeleteItem(ItemType(100));
    list.DeleteItem(ItemType(101));

    printList(list);

    return 0;
}