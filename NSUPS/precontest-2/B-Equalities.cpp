#include<iostream>
using namespace std;
int main() {
    int s;
    cin >> s;
    int a[s];
    int l;
    for (int i = 0; i < s; i++)
    {
        int d;
        cin >> d;
        a[i] = d;
        if (l < d)
            l = d;
    }
    int n;
    for (int i = 0; i < s; i++)  
    {
        n += l - a[i];
    }
    cout << n;
}