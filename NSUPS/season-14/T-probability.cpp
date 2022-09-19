#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, e;
        cin >> s >> e;
        int a = 0;
        for (int i = s; i <= e; i++)
        {
            int n = i;
            if (n == 0) {
                a++;
            }
            else {
                while (n > 0) {
                    if (n % 10 == 0) {
                        a++;
                        break;
                    }
                    n /= 10;
                }
            }
        }
        cout << a << "/" << (e - s + 1) << endl;
    }
}