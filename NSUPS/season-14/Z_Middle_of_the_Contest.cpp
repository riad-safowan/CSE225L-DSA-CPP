#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, e;
    cin >> s;
    cin >> e;

    int sh = stoi(s.substr(0, 2));
    int sm = stoi(s.substr(3, 5));
    int eh = stoi(e.substr(0, 2));
    int em = stoi(e.substr(3, 5));

    int st = sh * 60 + sm;
    int et = eh * 60 + em;

    printf("%02d:%02d\n", ((et + st) / 2) / 60, ((et + st) / 2) % 60);
}