#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int d1 = abs(x2 - x1);
    int d2 = abs(y2 - y1);
    int dia = min(d1, d2);
    int move = abs(d1 - d2);
    cout << dia + move;
}