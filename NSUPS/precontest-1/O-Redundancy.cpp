#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum;
    while (n--) {
        int t;
        cin >> t;
        sum += t;
    }
    cout << sum;
}