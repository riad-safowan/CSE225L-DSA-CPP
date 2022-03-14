#include <iostream>
#include "queuetype.cpp"
using namespace std;

void printQueue(QueueType<int> list) {
    QueueType<int> temp;
    while (!list.IsEmpty())
    {
        cout << list.Front() << " ";
        list.Dequeue();
    }
    cout << endl;
}

int main() {
    QueueType<int> list;

    cout << (list.IsEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

    list.Enqueue(5);
    list.Enqueue(7);
    list.Enqueue(4);
    list.Enqueue(2);

    cout << (list.IsEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

    cout << (list.IsFull() ? "Queue is full" : "Queue is not full") << endl;

    list.Enqueue(6);

    printQueue(list);

    cout << (list.IsFull() ? "Queue is full" : "Queue is not full") << endl;

    try {
        list.Enqueue(6);
    }
    catch (FullQueue err) {
        cout << "Queue Overflow\n";
    }

    list.Dequeue();
    list.Dequeue();

    printQueue(list);

    list.Dequeue();
    list.Dequeue();
    list.Dequeue();

    cout << (list.IsEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

    try {
        list.Dequeue();
    }
    catch (EmptyQueue err) {
        cout << "Queue Underflow\n";
    }

}
