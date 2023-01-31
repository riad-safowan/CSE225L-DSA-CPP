#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        else if (n != 1 && !isPrime(n)) {
            int a = n, b = n;
            while (!isPrime(a))
                a--;
            while (!isPrime(b))
                b++;
            cout << b - a << "\n";
        }
        else cout << 0 << "\n";
    }
    return 0;
}

