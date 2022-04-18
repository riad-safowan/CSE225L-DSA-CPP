#include<iostream>
using namespace std;

#define MX 555

long long store[MX][MX];

long long gridTraveler(long long  m, long long  n) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    if (store[m][n] != 0) return store[m][n];
    long long sum = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
    store[m][n] = sum;
    store[n][m] = sum;
    return sum;
}
int main() {
    cout << gridTraveler(1, 1) << endl;
    cout << gridTraveler(2, 3) << endl;
    cout << gridTraveler(3, 3) << endl;
    cout << gridTraveler(9, 90) << endl;
    cout << gridTraveler(500, 500) << endl;
    return 0;
}