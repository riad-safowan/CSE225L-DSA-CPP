#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, v, f = 0;
    cin >> n;
    vector<int>s;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        s.push_back(v);
    }

    sort(s.begin(), s.end());
    vector<int> ::iterator it = s.begin();
    for (int i = 0; i < n - 2; i++)
    {
        if (*it++ + *it++ > *it--) {
            f = 1;
            break;
        }
    }

    if (f) cout << "YES\n";
    else cout << "NO\n";
}