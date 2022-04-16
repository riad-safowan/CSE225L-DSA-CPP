#include<iostream>
using namespace std;

#define MX 55

long long store[MX];

long long fib(long long n) {
    if (n <= 2)
        return 1;
    else if (store[n] != 0) {
        return store[n];
    }
    else
        store[n] = fib(n - 1) + fib(n - 2);
    return store[n];
}

int main() {
    cout << fib(200);
    return 0;
}