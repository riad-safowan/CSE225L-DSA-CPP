#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
const int MAX_ITEMS = 5;
template <class T>
class SortedType
{
public:
    SortedType();
    void MakeEmpty();
    bool IsFull();
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