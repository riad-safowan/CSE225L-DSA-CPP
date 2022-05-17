#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cin >> num;
    for (int i = num / 2; i >= 0; i--)
    {
        int d = num - i;
        if (1 == __gcd(i, d)) {
            cout << i << " " << d;
            break;
        }
    }
}