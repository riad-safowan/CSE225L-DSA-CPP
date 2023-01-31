#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    for (auto&& i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}