#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.length() == 5) {
            list<int> li;
            li.push_back('T');
            li.push_back('i');
            li.push_back('m');
            li.push_back('u');
            li.push_back('r');
            for (int i = 0; i < 5; i++) {
                li.remove(s[i]);
            }
            if (li.empty()) {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else {
            cout << "NO\n";
        }
    }
}