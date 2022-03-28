#include "UnsortedList.h"
template <class T>
UnsortedList<T>::UnsortedList()
{
    length = 0;
    currentPos = -1;
}
template <class T>
void UnsortedList<T>::MakeEmpty()
{
    length = 0;
}
template<class T>
bool UnsortedList<T>::IsEmpty()
{
    return length == 0;
}
template <class T>
bool UnsortedList<T>::IsFull()
{
    return (length == MAX_ITEMS);
}
template <class T>
int UnsortedList<T>::GetLength()
{
    return length;
}
template <class T>
void UnsortedList<T>::ResetList()
{
    currentPos = -1;
}
template <class T>
void UnsortedList<T>::GetNextItem(T& item)
{
    currentPos++;
    item = info[currentPos];
}
template <class T>
void UnsortedList<T>::RetrieveItem(T& item, bool& isFound)
{
      for(int i=0;i<length;i++)
    {
        if(info[i] == item)
        {
            isFound = true;
            return;
        }
    }
}
template <class T>
void UnsortedList<T>::InsertItem(T item)
{
    info[length] = item;
    length++;
}
template <class T>
void UnsortedList<T>::DeleteItem(T
    item)
{
     int location = 0;
    for(int i=0;i<length;i++)
    {
        if(info[i] == item)
        {
            location = i;
            break;
        }
    }
    info[location] = info[length-1];
    length--;
}