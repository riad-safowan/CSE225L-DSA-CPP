#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n == 1) return true;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n, c;
    while (cin >> n >> c)
    {
        int o = 0, p = 0, q = 0, s = 0;
        for (int i = 1; i <= n; i++)
            if (isPrime(i))
                p++;

        cout << n << " " << c << ":";

        if (2 * c >= p) {
            for (int i = 1; i <= n; i++)
                if (isPrime(i))
                    cout << " " << i;
            cout << "\n\n";
            continue;
        }

        o = (p % 2 == 0) ? 2 * c : 2 * c - 1;
        s = (p % 2 == 0) ? (p / 2) - c : (p / 2.0) - c + .5;

        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                q++;
                if (q > s)
                    cout << " " << i;
            }
            if (q >= s + o) {
                cout << "\n\n";
                break;
            }
        }
    }
}