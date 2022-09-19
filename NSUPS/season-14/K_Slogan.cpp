#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    map<string, string>m;
    while (n--)
    {
        string f, l;
        getline(cin, f);
        getline(cin, l);
        m[f] = l;
    }

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string f;
        getline(cin, f);
        string l = m[f];
        cout << l << endl;
    }
}