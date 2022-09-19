#include <bits/stdc++.h> 
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, t=0;
    cin >> n >> a;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (data % a == 0)
            t++;
    }
    cout << t <<"\n";
}
