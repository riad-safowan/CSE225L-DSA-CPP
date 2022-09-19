#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        long long f=1;
        for (int i = 1; i <= a; i++)
        {
            f*=i;
        }
        cout << f << "\n";
    }
}