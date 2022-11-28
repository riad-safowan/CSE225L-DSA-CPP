#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a = 1;
        while (n--)
        {
            switch (a)
            {
            case 1:
                cout << "a";
                a++;
                break;
            case 2:
                cout << "b";
                a++;
                break;
            case 3:
                a = 1;
                cout << "c";
                break;
            }
        }
        cout << "\n";
    }
}