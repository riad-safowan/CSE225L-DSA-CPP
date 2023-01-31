#include<bits/stdc++.h>
using namespace std;

int main() {
    int y;
    cin >> y;
    while (true) {
        if (y % 4 == 2)
        {
            cout << y << "\n";
            return 0;
        }
        y++;
    }
}