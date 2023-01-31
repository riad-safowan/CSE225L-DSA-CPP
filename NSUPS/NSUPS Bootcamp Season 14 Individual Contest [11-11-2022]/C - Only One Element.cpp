#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int arr[num];
        bool yes = true;
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        sort(arr, arr + num);

        for (int i = 1; i < num; i++) {
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