#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b && a > c)
        {
            if (b > c) cout << b << endl;
            else cout << c << endl;
        }
        else if (b > a && b > c)
        {
            if (a > c) cout << a << endl;
            else  cout << c << endl;
        }
        else {
            if (a > b) cout << a << endl;
            else cout << b << endl;
        }
    }
}
