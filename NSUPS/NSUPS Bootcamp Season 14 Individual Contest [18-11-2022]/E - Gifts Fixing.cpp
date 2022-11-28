#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int candy[n], orange[n];
        int sc = 1000000000, so = 1000000000;
        for (int i = 0; i < n; i++)
        {
            cin >> candy[i];
            if (sc > candy[i])
                sc = candy[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> orange[i];
            if (so > orange[i])
                so = orange[i];
        }

        long long total = 0;

        for (int i = 0; i < n; i++)
            if (candy[i] - sc > orange[i] - so)
                total += candy[i] - sc;
            else
                total += orange[i] - so;

        cout << total << "\n";
    }
}