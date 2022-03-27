#include<iostream>
using namespace std;

int main() {
    long long n, m, a, total, stoneN, stoneM;
    cin >> n;
    cin >> m;
    cin >> a;

    stoneN = n / a;
    if (n % a > 0)
        stoneN++;

    stoneM = m / a;
    if (m % a > 0)
        stoneM++;

    cout << stoneM * stoneN;
    return 0;
}