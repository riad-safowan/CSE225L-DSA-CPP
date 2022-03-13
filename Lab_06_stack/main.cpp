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

bool isBalanced(string parenthesis) {
    StackType<char> stack;
    for (int i = 0; i < parenthesis.length(); i++)
    {
        if (parenthesis.at(i) == '(') {
            stack.Push(parenthesis.at(i));
        }
        else if (parenthesis.at(i) == ')') {
            if (stack.IsEmpty())
                return false;
            stack.Pop();
        }
    }
    return stack.IsEmpty();
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

    cout << stack.Top() << endl;

    cout << (isBalanced("()") ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced("(())()(()())()") ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced("(())()((()") ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced("(())))((() ") ? "Balanced" : "Not Balanced") << endl;
    return 0;
}