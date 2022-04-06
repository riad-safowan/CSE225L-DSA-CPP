#include<iostream>
using namespace std;


int sumOfDigits(int n) {
    if (n < 10)
        return n;
    int r = n % 10;
    return sumOfDigits(n / 10) + r;
}

int main() {
    cout << sumOfDigits(125);
    return 0;
}