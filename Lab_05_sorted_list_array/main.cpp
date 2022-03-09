#include<iostream>
#include "sortedtype.cpp"
using namespace std;

int main() {

    SortedType<int> list;


    cout << list.LengthIs() << endl;

    list.InsertItem(5);
    list.InsertItem(7);
    list.InsertItem(4);
    list.InsertItem(2);
    list.InsertItem(1);


    for (int i = 0; i < list.LengthIs(); i++)
    {
        int item;
        list.GetNextItem(item);
        cout << item << " ";
    }
    list.ResetList();

    int item = 6;
    bool found = false;
    list.RetrieveItem(item, found);

    if (found)
    {
        cout << "item found";
    }
    else {
        cout << "item not found";
    }
    item = 5;
    list.RetrieveItem(item, found);

    if (found)
    {
        cout << "item found";
    }
    else {
        cout << "item not found";
    }


    cout << ((list.IsFull()) ? "Full" : "Not Full") << endl;
    list.DeleteItem(1);
    for (int i = 0; i < list.LengthIs(); i++)
    {
        int item;
        list.GetNextItem(item);
        cout << item << " ";
    }
    list.ResetList();

    return 0;
}