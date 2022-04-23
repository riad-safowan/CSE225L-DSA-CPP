#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int even, odd, ei, oi;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            even++;
            ei = i + 1;
        }
        else {
            odd++;
            oi = i + 1;
        }
    }
    if (even == 1) {
        cout << ei;
    }
    else {
        cout << oi;
    }
}