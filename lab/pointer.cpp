#include<iostream>
using namespace std;

void swap(int* x, int* y);

int main() {
    int x = 7;
    cout << x << endl;
    cout << &x << endl; //address

    int* p; // pointer
    p = &x;
    cout << p << endl; // address of x
    cout << *p << endl; // value belongs to the address

    int a = 1, b = 2;
    swap(&a, &b);
    cout << a << endl;
    cout << b << endl;

    // Double pointer
    int f = 7;
    int* c = &f;
    int** cc = &c;
    cout << *c << endl; // 7
    cout << *cc << endl; // address of f
    cout << **cc << endl;// 7

    // change value with pointer
    *c = 10;
    cout << f << endl;
    **cc = 20;
    cout << f << endl;

    return 0;
}

// swapping value by passing address
void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}