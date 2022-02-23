#ifndef COMPLEX_H_INCLUDE
#define COMPLEX_H_INCLUDE
#include <iostream>
using namespace std;

class Complex {
    friend Complex operator+(Complex, Complex); //independent also accessing private field
    friend Complex operator+(int, Complex);
    friend Complex operator+(Complex, int);
private:
    int real, imaginary;

public:
    Complex();
    Complex(int, int);
    int sum(int, int);
    void Print();
};
#endif

Complex::Complex() {
    real = 0;
    imaginary = 0;
}

Complex::Complex(int r, int i) {
    real = r;
    imaginary = i;
}

void Complex::Print() {
    cout << real << "+" << imaginary << "i" << endl;
}

Complex operator+(Complex a, Complex b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;

    return sum;
}

Complex operator+(Complex a, int b) {
    Complex sum;
    sum.imaginary = a.imaginary + b;
    return sum;
}

Complex operator+(int a, Complex b) {
    Complex sum;
    sum.real = a + b.real;
    return sum;
}

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex sum;
    sum = c1 + c2;
    sum.Print();

    int x, y;
    cin >> x >> y;
    cout << x + y << endl;
}
//homework: (+,-,==,!=,>,<=) 