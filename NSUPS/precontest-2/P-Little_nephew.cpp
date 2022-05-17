#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a == b && b == c && c == d && d == e && a == 0) break;
        long result = a * b * c * (d + (d * (d - 1))) * (e + (e * (e - 1)));
        cout << result<<endl;
    }
}

