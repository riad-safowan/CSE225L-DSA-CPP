#include<iostream>
using namespace std;
int main() {
    long long num;
    cin >> num;
    int ln;
    while (num > 0) {
        int d = num % 10;
        if (d == 4 || d == 7) ln++;
        num /= 10;
    }
    if (ln == 4 || ln == 7)
    {
        cout << "YES";
    }
    else cout << "NO";
}