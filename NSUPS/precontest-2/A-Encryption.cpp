#include<bits/stdc++.h>
using namespace std;

int getb1(int num) {
    int n;
    while (num > 0) {
        if (num % 2 == 1) {
            num--;
            n++;
        }
        num /= 2;
    }
    return n;
}

int getb2(int num) {
    int n;
    while (num > 0) {
        n += getb1(num % 10);
        num /= 10;
        cout << "";
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--){
        int num;
        cin >> num;
        cout << getb1(num) << " " << getb2(num) << "\n";
    }
}

