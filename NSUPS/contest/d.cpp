#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long  n;
        cin >> n;
        long long h = (n * (n + 1)) / 2;
        long long  a = 1;
        while (a <= n)
        {
            h -= 2 * a;
            a *= 2;
        }
        cout << h << "\n";
    }
}