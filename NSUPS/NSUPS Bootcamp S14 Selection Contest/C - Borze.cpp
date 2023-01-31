#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    while (s.length()) {
        if (s[0] == '.')
        {
            cout << 0;
            s.erase(0, 1);
        }
        else if (s[1] == '.')
        {
            cout << 1;
            s.erase(0, 2);
        }
        else {
            cout << 2;
            s.erase(0, 2);
        }    
    }
    cout << "\n";
}