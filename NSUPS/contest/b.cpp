#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        bool p = true;
        int t;
        cin >> t;
        int a[t];
        for (int ii = 0; ii < t; ii++)
            cin >> a[ii];


        int i = 0, j = 1, k = t - 1;
        for (j; j < k; j++)
        {
            if (a[i] + a[j] <= a[k]) {
                cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                p = false;
                break;
            }
        }
        if (p)
            cout << (-1) << "\n";
    }
    return 0;
}