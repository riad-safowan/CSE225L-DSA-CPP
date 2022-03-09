#include "Sortedtype.h"
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    length = 0;
}
template <class ItemType>
bool SortedType<ItemType>::IsFull()
{
    return (length == MAX_ITEMS);
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = -1;
}
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    // int low = 0, high = length - 1;
    // int location;
    // found = false;
    // while (!found && high >= low) {
    //     location = (high + low) / 2;
    //     if (item < info[location]) {
    //         high = location;
    //     }
    //     else if (item > info[location]) {
    //         low = location;
    //     }
    //     else if (item == info[location]) {
    //         found = true;
    //         item = info[location];
    //     }
    // }

    int midPoint, first = 0, last = length - 1;
    bool moreToSearch = (first <= last);
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        if (item < info[midPoint])
        {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (item > info[midPoint])
        {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else
        {
            found = true;
            item = info[midPoint];
        }
    }
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    if (length == 0)
    {
        info[0] = item;
        length++;
        return;
    }

    // int low = 0, high = length - 1;
    // int location = (high + low) / 2;
    // bool found = false;

    // while (!found && low <= high) {
    //     if (item < info[location]) {
    //         high = location - 1;
    //         location = (high + low) / 2;
    //         if (low > high)
    //             location--;
    //     }
    //     else if (item > info[location]) {
    //         low = location + 1;
    //         location = (high + low) / 2;
    //         if (low > high)
    //             location++;
    //     }
    //     else if (item == info[location]) {
    //         found = true;
    //     }
    // }

    int location = 0;
    bool moreToSearch = (location < length);
    while (moreToSearch)
    {
        if (item > info[location])
        {
            location++;
            moreToSearch = (location < length);
        }
        else if (item < info[location])
            moreToSearch = false;
    }


    for (int i = length; i > location; i--)
    {
        info[i] = info[i - 1];
    }
    info[location] = item;
    length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType
    item)
{
    // int low = 0, high = length - 1;
    // int location;
    // bool found = false;

    // while (!found && high >= low) {
    //     location = (high + low) / 2;
    //     if (item < info[location]) {
    //         high = location;
    //     }
    //     else if (item > info[location]) {
    //         low = location;
    //     }
    //     else if (item == info[location]) {
    //         found = true;
    //     }
    // }
    // if (found)
    // {
    //     if (location != length - 1) {
    //         for (int i = location; i <= length - 1; i++)
    //         {
    //             info[i] = info[i + 1];
    //         }
    //     }
    //     length--;
    // }

    int location = 0;
    while (item != info[location])
        location++;
    for (int index = location + 1; index < length;
        index++)
        info[index - 1] = info[index];
    length--;

}

