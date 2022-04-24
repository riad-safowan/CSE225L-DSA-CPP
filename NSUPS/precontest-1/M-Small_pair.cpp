#include<iostream>
using namespace std;
int main() {
    long t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        long s1 = -1, s2 = -1;
        while (n--) {
            long m;
            cin >> m;
            if (s1 == -1)
            {
                s1 = m;
            }
            else if (m < s1) {
                s2 = s1;
                s1 = m;
            }
            else if (m < s2 || s2 == -1) {
                s2 = m;
            }
        }
        cout << (s1 + s2) << endl;
    }
}