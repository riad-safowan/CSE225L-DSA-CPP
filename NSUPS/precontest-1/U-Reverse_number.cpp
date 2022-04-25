#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        int re = 0;
        while (num > 0)
        {
            re = re * 10 + num % 10;
            num /= 10;
        }
        cout << re << endl;
    }
}