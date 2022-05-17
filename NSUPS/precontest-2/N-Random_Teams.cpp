#include<bits/stdc++.h>
using namespace std;

long long findMin(long long p, long long t) {
    long long r = 0;
    long long base = p / t;
    long long g1 = p % t;
    long long g2 = t - g1;

    r = (base * (base - 1) / 2) * g2;
    r += ((base + 1) * (base) / 2) * g1;
    return r;
}

long long findMax(long long p, long long t) {
    p -= t - 1;
    long long r = 0;
    r = p * (p - 1) / 2;
    return r;
}

int main() {
    long long p, t;
    cin >> p >> t;

    cout << findMin(p, t) << " " << findMax(p, t);
}