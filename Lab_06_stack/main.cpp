#include<iostream>
#include "stacktype.cpp"
using namespace std;

void printStack(StackType<int> stack) {
    StackType<int> temp;
    while (!stack.IsEmpty())
    {
        temp.Push(stack.Top());
        stack.Pop();
    }
    while (!temp.IsEmpty())
    {
        cout << temp.Top() << " ";
        temp.Pop();
    }
    cout << endl;
}

int main() {
    StackType<int> stack;
    cout << (stack.IsEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);
    cout << (stack.IsEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
    cout << (stack.IsFull() ? "Stack is full" : "Stack is not full") << endl;

    printStack(stack);

    stack.Push(3);
    printStack(stack);
    cout << (stack.IsFull() ? "Stack is full" : "Stack is not full") << endl;

    stack.Pop();
    stack.Pop();

    cout << stack.Top();
    
    return 0;
}