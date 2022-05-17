#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, e;
        cin >> s >> e;
        int a = 0;
        for (int i = s; i <= e; i++)
        {
            int num = i;
            while (num > 0)
            {
               if (num % 10 == 0){
                   a++;
                   break;
               }
                num /= 10;
            }
        }
        cout << a << "/" << (e - s + 1)<<endl;
    }
}