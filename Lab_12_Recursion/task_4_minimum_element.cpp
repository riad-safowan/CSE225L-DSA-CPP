#include<iostream>
using namespace std;

int getBin(int n) {
    if (n == 0)
        return 0;
    return n % 2 + 10 * getBin(n / 2);
}

int main() {
    cout << getBin(4);
    return 0;
}