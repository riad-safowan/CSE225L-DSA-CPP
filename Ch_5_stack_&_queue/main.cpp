#include<iostream>
#include "stack_array.cpp"
#include "stack_linked.cpp"
using namespace std;

int main() {
    StackType<int> stack;
    stack.Push(2);
    stack.Push(223);
    stack.Push(22354);
    stack.Push(2345);
    stack.Push(24536);

    while (!stack.IsEmpty()) {
        cout << stack.Top() << " ";
        stack.Pop();
    }
    cout << endl;

    LinkedStackType<int> stack2;
    stack2.Push(2);
    stack2.Push(223);
    stack2.Push(22354);
    stack2.Push(2345);
    stack2.Push(24536);

    while (!stack2.IsEmpty()) {
        cout << stack2.Top() << " ";
        stack2.Pop();
    }
    cout << endl;
    return 0;
}