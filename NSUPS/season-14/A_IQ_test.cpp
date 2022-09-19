#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, i, num, n_e, i_e, n_o, i_o;
    cin >> n;
    while (n--)
    {
        cin >> num;
        i++;
        if (num % 2 == 0) {
            n_e++;
            i_e = i;
        }
        else {
            n_o++;
            i_o = i;
        }
    }
    int o = (n_e == 1) ? i_e : i_o;
    cout << o;
}