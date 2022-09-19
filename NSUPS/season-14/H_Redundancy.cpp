#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    map<int, int> m;
    vector<int> v;

    while (cin >> n)
    {  
        if (m[n] == 0) 
            v.push_back(n);
        m[n] = ++m[n];
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << m[v[i]] << endl;
    }
}