#include <iostream>
#include "queuetype.cpp"
using namespace std;

QueueType<int> q1, q2;

void push(int v) {
    
    q2.Enqueue(v);
    while (!q1.IsEmpty())
    {
        q2.Enqueue(q1.Front());
        q1.Dequeue();
    }

    QueueType<int> temp;
    temp = q2;
    q2 = q1;
    q1 = temp;
}

int top() {
    return q1.Front();
}
void pop() {
    q1.Dequeue();
}

int main() {
    push(12);
    push(13);
    push(14);
    push(15);
    pop();
    for (int i = 0; i < 3; i++)
    {
        cout << top()<<endl;
        pop();
    }
}