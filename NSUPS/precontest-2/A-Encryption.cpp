#include<bits/stdc++.h>
using namespace std;

long long getb1(long long num) {
    long long n;
    while (num > 0) {
        if (num % 2 == 1) {
            num--;
            n++;
        }
        num /= 2;
    }
    return n;
}

long long getb2(long long num) {
    long long n;
    while (num > 0) {
        n += getb1(num % 10);
        num /= 10;
    }
    return n;
}

int main() {
 
    long long n;
    cin >> n;
    while (n--){
        long long num;
        cin >> num;
        cout << getb1(num) << " " << getb2(num) << "\n";
    }
}

