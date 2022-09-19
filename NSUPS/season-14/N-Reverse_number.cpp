#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        int re = 0;
        while (num > 0)
        {
            re = re * 10 + num % 10;
            num /= 10;
        }
        cout << re << "\n";
    }
}