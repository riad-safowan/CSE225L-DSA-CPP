#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1.length() <<" "<< s2.length() << "\n";
    cout << (s1 + s2) << "\n";
    char t;
    t = s1[0];
    s1[0] = s2[0];
    s2[0] = t;
    cout << s1 + " " + s2 << "\n";
}