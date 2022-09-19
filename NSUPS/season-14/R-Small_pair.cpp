// #include<iostream>

// int main() {
//     int t;
//     scanf("%d", &t);
//     while (t--) {
//         int n;
//         scanf("%d", &n);
//         int s = -1, ss = -1;
//         while (n--) {
//             int m;
//             scanf("%d", &m);
//             if (s == -1)
//                 s = m;
//             else if (m < s) {
//                 ss = s;
//                 s = m;
//             }
//             else if (m < ss || ss == -1)
//                 ss = m;
//         }
//         printf("%d\n", (s + ss));
//     }
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        int s = -1, ss = -1;
        while (n--) {
            cin >> m;
            if (s == -1)
                s = m;
            else if (m < s) {
                ss = s;
                s = m;
            }
            else if (m < ss || ss == -1)
                ss = m;
        }
        cout << (s + ss) << "\n";
    }
}