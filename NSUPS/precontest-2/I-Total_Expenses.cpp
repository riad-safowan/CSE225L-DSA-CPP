#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double q, p;
        cin >> q >> p;

        double total = p * q;
        if (q > 1000)
            total -= total * .1;

        printf("%.*f\n",6,total);
    }
}