#include <iostream>
using namespace std;

//4. Write a function isPrime(int n)  which checks if ‘n’ is prime or not. Use this function to print all the prime 
//   numbers between 300 to 500. 

bool isPrime(int num) {
    bool isPrime = true;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main()
{
    for (int i = 300; i <= 500; i++)
    {
        if (isPrime(i)) {
            cout << i << ", ";
        }
    }
    return 0;
}

