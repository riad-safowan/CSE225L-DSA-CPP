#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int d[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> d[i];
    }
    int i=1;
    while (true)
    {
        n -= d[i++];
        if (n < 0) {
            cout << --i % 7<<"\n";
            return 0;
        }
    }
}