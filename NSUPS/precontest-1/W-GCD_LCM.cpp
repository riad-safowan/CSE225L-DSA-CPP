#include<iostream>
using namespace std;

int gcdd(int m, int n) {
    int a, b;
    if (m >= n)
    {
        a = m;
        b = n;
    }
    else {
        b = m;
        a = n;
    }

    int r = b;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int lcmm(int m, int n)
{
    int a, b;
    a = (m > n) ? m : n;
    b = a;
    while (true)
    {
        if (a % m == 0 && a % n == 0)
            return a;
        a += b;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        // int lcm = lcmm(a, b);
        int gcd = gcdd(a, b);
        // cout << ((a * b) / lcm) << " " << lcm << endl;
        cout << gcd << " " << (((long long)a * b) / gcd) << endl;
    }
}