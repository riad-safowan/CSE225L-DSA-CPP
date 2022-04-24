#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int i = 0;
        while (n > 1)
        {
            if (n % 2 == 0)
                n = n / 2;
            else if (n % 3 == 0)
                n = (n * 2) / 3;
            else if (n % 5 == 0)
                n = (n * 4) / 5;
            else {
                i = -1;
                break;
            }
            i++;
        }
        cout << i << endl;
    }
}