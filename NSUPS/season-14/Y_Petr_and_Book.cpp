#include<bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    int d[7];
    for (int i = 0; i < 7; i++)
        cin >> d[i];

    while (true)
    {
        for (int i = 0; i < 7; i++) {
            p -= d[i];
            if (p <= 0) {
                cout << (i + 1) << "\n";
                return 0;
            }
        }
    }
}