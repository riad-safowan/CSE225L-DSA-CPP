#include<iostream>
using namespace std;

int gcdd(int m, int n) {
    int a = (m >= n) ? m : n;
    int b = (m >= n) ? n : m;

    int r = b;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int gcd = gcdd(a, b);
        cout << gcd << " " << (((long long)a * b) / gcd) << "\n";
    }
}