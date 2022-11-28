#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int arr[a];
        bool yes = true;
        for (int i = 0; i < a; i++)
            cin >> arr[i];
        sort(arr, arr + a);

        for (int i = 1; i < a; i++) {
            if ((arr[i] - arr[i - 1]) > 1)
            {
                yes = false;
                break;
            }
        }

        if (yes)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}