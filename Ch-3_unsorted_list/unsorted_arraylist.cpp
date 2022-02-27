#ifndef MY_LIST1
#define MY_LIST1
#include <iostream>
using namespace std;

const int MAX_ITEM = 5;
enum RelationType { LESS, EQUAL, GREATER };

class ItemType
{
private:

public:
    ItemType() {};
    ItemType(int);
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(int number);
    int value;
};
#endif
ItemType::ItemType(int v) {
    value = v;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}
void ItemType::Print() const
{
    cout << value << endl;
}
void ItemType::Initialize(int number)
{
    value = number;
}

template<class T>
class UnsortedType {
public:
    UnsortedType();
    bool isFull() const;
    int getLength() const;
    T getItem(T, bool&);
    void putItem(T);
    void deleteItem(T);
    void resetList();
    T getNextItem();

private:
    int length = 0;
    T info[MAX_ITEM];
    int currentPos = 0;
};

template<class T>
UnsortedType<T>::UnsortedType()
{
    length = 0;
}
template<class T>
void UnsortedType<T>::putItem(T item)
{
    info[length] = item;
    length++;
}
template<class T>
int UnsortedType<T>::getLength() const
{
    return length;
}
template<class T>
bool UnsortedType<T>::isFull() const
{
    return (length == MAX_ITEM);
}
template<class T>
T UnsortedType<T>::getItem(T item, bool& found)
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
template<class T>
void UnsortedType<T>::deleteItem(T item)
{
    int location = 0;
    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
    info[location] = info[length - 1];
    length--;
}
template<class T>
void UnsortedType<T>::resetList()
{
    currentPos = -1;
}
template<class T>
T UnsortedType<T>::getNextItem()
{
    currentPos++;
    return info[currentPos];
}


int main() {
    UnsortedType<ItemType> list;

    ItemType i1(5);
    list.putItem(i1);
    list.putItem(ItemType(10));
    list.putItem(ItemType(15));
    list.putItem(ItemType(20));
    list.putItem(ItemType(25));

    for (int i = 0; i < 5; i++)
    {
        list.getNextItem().Print();
    }
    list.resetList();

    list.deleteItem(ItemType(10));
    list.putItem(ItemType(8888));

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        list.getNextItem().Print();
    }
    list.resetList();

    return 0;
}