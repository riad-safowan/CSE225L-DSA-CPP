#include<bits/stdc++.h>
using namespace std;
long long con(long long m)
{
    long long a = 0;
    while (m) {
        a += m % 2;
        m /= 2;
    }
    return a;
}

int main()
{
    long long n, m, a, b, t, l, i, sum, c;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        l = s.length();
        sum = 0;
        c = 1;

        for (i = l - 1;i >= 0;i--) {
            sum += (s[i] - '0') * c;
            c *= 10;
        }

        a = con(sum);
        sum = 0;
        c = 1;
        for (i = l - 1;i >= 0;i--) {
            sum += (s[i] - '0') * c;
            c *= 16;
        }
        b = con(sum);
        cout << a << " " << b << endl;
    }
    return 0;
}
