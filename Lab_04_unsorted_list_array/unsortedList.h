#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED
const int MAX_ITEMS = 5;
template <class T>
class UnsortedList
{
public:
    UnsortedList();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    int GetLength();
    void InsertItem(T);
    void DeleteItem(T);
    void RetrieveItem(T&, bool&);
    void ResetList();
    void GetNextItem(T&);
private:
    int length;
    T info[MAX_ITEMS];
    int currentPos;
};
#endif