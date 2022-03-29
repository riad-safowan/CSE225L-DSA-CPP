#include <iostream>
#include "stacktype.cpp"
using namespace std;

StackType<int> s1, s2;

void enqueue(int v) {
    
    while (!s1.IsEmpty())
    {
        s2.Push(s1.Top());
        s1.Pop();
    }

    s2.Push(v);
    
    while (!s2.IsEmpty())
    {
        s1.Push(s2.Top());
        s2.Pop();
    }
}

int front() {
    return s1.Top();
}
void dequeue() {
    s1.Pop();
}

int main() {
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    dequeue();
    for (int i = 0; i < 3; i++)
    {
        cout << front() << endl;
        dequeue();
    }
    return 0;
}