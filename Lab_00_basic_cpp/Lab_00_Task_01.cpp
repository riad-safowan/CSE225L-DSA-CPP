#include <iostream>
using namespace std;

// 1. Take 2 integer inputs from keyboard and print their sum.
int main()
{
    int num1, num2, sum;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    sum = num1 + num2;
    cout << "Sum = " << sum;
}