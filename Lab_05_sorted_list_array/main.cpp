#include<iostream>
#include "sortedtype.cpp"
using namespace std;

class TimeStamp {
    friend bool operator==(TimeStamp a, TimeStamp b) {
        return a.hours == b.hours && a.minutes == b.minutes && a.seconds == b.seconds;
    }
    friend bool operator!=(TimeStamp a, TimeStamp b) {
        return a.hours != b.hours || a.minutes != b.minutes || a.seconds != b.seconds;
    }
    friend bool operator>(TimeStamp a, TimeStamp b) {
        if (a.hours > b.hours)
            return true;
        else if (a.hours == b.hours && a.minutes > b.minutes)
            return true;
        else if (a.hours == b.hours && a.minutes == b.minutes && a.seconds > b.seconds)
            return true;
        return false;
    }
    friend bool operator<(TimeStamp a, TimeStamp b) {
        if (a.hours < b.hours)
            return true;
        else if (a.hours == b.hours && a.minutes < b.minutes)
            return true;
        else if (a.hours == b.hours && a.minutes == b.minutes && a.seconds < b.seconds)
            return true;
        return false;
    }


private:
    int seconds, minutes, hours;
public:
    TimeStamp() {}
    TimeStamp(int s, int m, int h) {
        seconds = s;
        minutes = m;
        hours = h;
    }
    void print() {
        cout << seconds << ":" << minutes << ":" << hours;
    }
};


void printList(SortedType<int> list) {
    for (int i = 0; i < list.GetLength(); i++)
    {
        int item;
        list.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;
    list.ResetList();
}

void printList(SortedType<TimeStamp> list) {
    for (int i = 0; i < list.GetLength(); i++)
    {
        TimeStamp item;
        list.GetNextItem(item);
        item.print();
        cout << endl;
    }
    cout << endl;
    list.ResetList();
}

int main() {

    SortedType<int> list;

    cout << list.GetLength() << endl;

    list.InsertItem(5);
    list.InsertItem(7);
    list.InsertItem(4);
    list.InsertItem(2);
    list.InsertItem(1);

    printList(list);

    int item = 6;
    bool found = false;
    list.RetrieveItem(item, found);
    if (found)
        cout << "item found" << endl;
    else
        cout << "item not found" << endl;

    item = 5;
    list.RetrieveItem(item, found);
    if (found)
        cout << "item is found" << endl;
    else
        cout << "item is not found" << endl;

    cout << ((list.IsFull()) ? "List is full" : "List is not full") << endl;

    list.DeleteItem(1);

    printList(list);

    cout << ((list.IsFull()) ? "List is full" : "List is not full") << endl;

    SortedType<TimeStamp> timeList;
    timeList.InsertItem(TimeStamp(15, 34, 23));
    timeList.InsertItem(TimeStamp(13, 13, 02));
    timeList.InsertItem(TimeStamp(43, 45, 12));
    timeList.InsertItem(TimeStamp(25, 36, 17));
    timeList.InsertItem(TimeStamp(52, 02, 20));

    timeList.DeleteItem(TimeStamp(25, 36, 17));

    printList(timeList);

    return 0;
}