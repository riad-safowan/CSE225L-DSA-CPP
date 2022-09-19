#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        if (d != i)x++;
    }
    if (x > 2)
        cout << "NO";
    else cout << "YES";
}