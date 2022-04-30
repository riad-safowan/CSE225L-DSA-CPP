#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, r=0, g=0, b=0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R') r++;
            else if (s[i] == 'G') g++;
            else b++;
        }
        if (r >= g && r >= b)
            cout << (n - r) << endl;
        else if (g >= r && g >= b)
            cout << (n - g) << endl;
        else
            cout << (n - b) << endl;
    }
}