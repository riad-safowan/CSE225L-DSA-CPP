#include<iostream>
using namespace std;
int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    else if (b < a && b < c) return b;
    else return c;
}

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int kl = k * l, cd = c * d;

    cout << min(kl / nl, cd, p / np) / n << endl;
}