#include <iostream>
using namespace std;

//3. Take 2 integer inputs from keyboard and also ask the user for which operation to perform: ‘+’ or ‘-‘or ‘*’. 
//   Perform the appropriate operation and show the result. (Hint: you can use switch/case)
int main()
{
    int num1, num2;
    long result;
    char op;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operator(+,-,*,/): ";
    cin >> op;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        break;
    }
    cout << "result = " << result;
    return 0;
}