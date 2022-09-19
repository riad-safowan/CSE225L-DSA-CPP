#include<bits/stdc++.h>

using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        int t;
        cin >> t;
        string s;
        cin >> s;
        if (t == 1)
        {
            int ma;
            cin >> ma;
            m[s] += ma;
        }
        else if (t == 2)
            m[s] = 0;
        else
            cout << m[s] << "\n";
    }
}
