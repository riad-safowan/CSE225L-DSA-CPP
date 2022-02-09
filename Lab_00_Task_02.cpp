#include <iostream>
using namespace std;

//2. Take an integer from keyboard and find its factorial. 
int main()
{
    int num;
    long result = 1;
    cout << "Enter the number: ";
    cin >> num;
    for (int i = num; i > 0; i--)
    {
        result = result * i;
    }
    cout << num << "! = " << result;
    return 0;
}