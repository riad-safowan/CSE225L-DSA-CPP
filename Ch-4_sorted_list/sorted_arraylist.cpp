#include <iostream>
#include "item_type.cpp"
using namespace std;

const int MAX_ITEM = 50;

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
    int currentPos = -1;
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

void UnsortedType::PutItem(ItemType item)
{

    if (length == 0)
    {
        info[0] = item;
        length++;
        return;
    }

    int low = 0, high = length - 1;
    int location = (length - 1) / 2;
    bool found = false;
    while (!found && low <= high) {
        switch (item.ComparedTo(info[location])) {
        case LESS:
            high = location - 1;
            location = (high + low) / 2;
            if (low > high)
                location--;
            break;
        case GREATER:
            low = location + 1;
            location = (high + low) / 2;
            if (low > high)
                location++;
            break;
        case EQUAL: found = true;
            break;
        }
    }
    for (int i = length; i >= location; i--)
    {
        info[i + 1] = info[i];
    }

    info[location] = item;
    length++;

}

void UnsortedType::DeleteItem(ItemType item)
{
    int low = 0, high = length - 1;
    int location = (length - 1) / 2;
    bool found = false;
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
            break;
        }
    }
    if (found)
    {
        for (int i = location; i <= length - 1; i++)
        {
            info[i] = info[i + 1];
        }
        length--;
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

    ItemType i1(5);
    list.PutItem(i1);
    list.PutItem(ItemType(10));
    list.PutItem(ItemType(15));
    list.PutItem(ItemType(20));
    list.PutItem(ItemType(25));
    list.PutItem(ItemType(12));
    list.PutItem(ItemType(10));

    cout << "The array: ";
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    list.DeleteItem(ItemType(10));

    cout << endl << "The array: ";
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }

    return 0;
}