#ifndef COMPLEX_H_INCLUDE
#define COMPLEX_H_INCLUDE
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    friend Complex operator+(Complex, Complex);
    friend Complex operator+(int, Complex);
    friend Complex operator+(Complex, int);

    friend Complex operator*(Complex, Complex);
    friend Complex operator*(int, Complex);
    friend Complex operator*(Complex, int);

    friend Complex operator-(Complex, Complex);
    friend Complex operator-(int, Complex);
    friend Complex operator-(Complex, int);

    friend bool operator==(Complex, Complex);
    friend bool operator==(int, Complex);
    friend bool operator==(Complex, int);

    friend bool operator!=(Complex, Complex);
    friend bool operator!=(int, Complex);
    friend bool operator!=(Complex, int);

    friend bool operator>(Complex, Complex);
    friend bool operator>(int, Complex);
    friend bool operator>(Complex, int);

    friend bool operator<=(Complex, Complex);
    friend bool operator<=(int, Complex);
    friend bool operator<=(Complex, int);

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
    if (imaginary < 0)
    {
        cout << real << imaginary << "i";
    }
    else {
        cout << real << "+" << imaginary << "i";
    }
}

Complex operator+(Complex a, Complex b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}

Complex operator+(Complex a, int b) {
    Complex sum;
    sum.real = a.real + b;
    sum.imaginary = a.imaginary;
    return sum;
}

Complex operator+(int a, Complex b) {
    Complex sum;
    sum.real = a + b.real;
    sum.imaginary = b.imaginary;
    return sum;
}

Complex operator-(Complex a, Complex b) {
    Complex sub;
    sub.real = a.real - b.real;
    sub.imaginary = a.imaginary - b.imaginary;
    return sub;
}

Complex operator-(Complex a, int b) {
    Complex sum;
    sum.real = a.real - b;
    sum.imaginary = a.imaginary;
    return sum;
}

Complex operator-(int a, Complex b) {
    Complex sum;
    sum.real = a - b.real;
    sum.imaginary = b.imaginary;
    return sum;
}

Complex operator*(Complex a, Complex b) {
    Complex product;
    product.real = a.real * b.real - a.imaginary * b.imaginary;
    product.imaginary = a.imaginary * b.real + a.real * b.imaginary;
    return product;
}

Complex operator*(Complex a, int b) {
    Complex product;
    product.real = a.real * b;
    product.imaginary = a.imaginary * b;
    return product;
}

Complex operator*(int a, Complex b) {
    Complex product;
    product.real = b.real * a;
    product.imaginary = b.imaginary * a;
    return product;
}

bool operator==(Complex a, Complex b) {
    return a.real == b.real && a.imaginary == b.imaginary;
}

bool operator==(Complex a, int b) {
    return a.real == b && a.imaginary == 0;
}

bool operator==(int a, Complex b) {
    return a == b.real && 0 == b.imaginary;
}

bool operator!=(Complex a, Complex b) {
    return a.real != b.real || a.imaginary != b.imaginary;
}

bool operator!=(Complex a, int b) {
    return a.real != b || a.imaginary != 0;
}

bool operator!=(int a, Complex b) {
    return a != b.real || 0 != b.imaginary;
}

bool operator>(Complex a, Complex b) {
    return pow((pow(a.real, 2) + pow(a.imaginary, 2)), 0.5) > pow((pow(b.real, 2) + pow(b.imaginary, 2)), 0.5);
}

bool operator>(Complex a, int b) {
    return pow((pow(a.real, 2) + pow(a.imaginary, 2)), 0.5) > b;
}

bool operator>(int a, Complex b) {
    return a > pow((pow(b.real, 2) + pow(b.imaginary, 2)), 0.5);
}

bool operator<=(Complex a, Complex b) {
    return pow((pow(a.real, 2) + pow(a.imaginary, 2)), 0.5) <= pow((pow(b.real, 2) + pow(b.imaginary, 2)), 0.5);
}

bool operator<=(Complex a, int b) {
    return pow((pow(a.real, 2) + pow(a.imaginary, 2)), 0.5) <= b;
}

bool operator<=(int a, Complex b) {
    return a <= pow((pow(b.real, 2) + pow(b.imaginary, 2)), 0.5);
}

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    int num = 8;
    Complex result;

    // + operator
    result = c1 + c2;
    c1.Print();cout << " + "; c2.Print();cout << " = "; result.Print(); cout << endl;
    result = c1 + num;
    c1.Print();cout << " +    " << num << " = "; result.Print(); cout << endl;
    result = num + c2;
    cout << num << "    + "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    // - operator
    result = c1 - c2;
    c1.Print();cout << " - "; c2.Print();cout << " = "; result.Print();cout << endl;
    result = c1 - num;
    c1.Print();cout << " -    " << num << " = "; result.Print(); cout << endl;
    result = num - c2;
    cout << num << "    - "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    // * operator
    result = c1 * c2;
    c1.Print();cout << " * "; c2.Print();cout << " = "; result.Print();cout << endl;
    result = c1 * num;
    c1.Print();cout << " *    " << num << " = "; result.Print(); cout << endl;
    result = num * c2;
    cout << num << "    * "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    // == operator
    c1.Print();cout << " == "; c2.Print();cout << " -> " << ((c1 == c2) ? "True" : "False") << endl;
    c1.Print();cout << " ==   " << num << "  -> " << ((c1 == num) ? "True" : "False") << endl;
    cout << num << "    == "; c2.Print();cout << " -> " << ((num == c2) ? "True" : "False") << endl << endl;

    // != operator
    c1.Print();cout << " != "; c2.Print();cout << " -> " << ((c1 != c2) ? "True" : "False") << endl;
    c1.Print();cout << " !=   " << num << "  -> " << ((c1 != num) ? "True" : "False") << endl;
    cout << num << "    != "; c2.Print();cout << " -> " << ((num != c2) ? "True" : "False") << endl << endl;

    // > operator
    c1.Print();cout << " > "; c2.Print();cout << " -> " << ((c1 > c2) ? "True" : "False") << endl;
    c1.Print();cout << " >   " << num << "  -> " << ((c1 > num) ? "True" : "False") << endl;
    cout << num << "    > "; c2.Print();cout << " -> " << ((num > c2) ? "True" : "False") << endl << endl;

    // <= operator
    c1.Print();cout << " <= "; c2.Print();cout << " -> " << ((c1 <= c2) ? "True" : "False") << endl;
    c1.Print();cout << " <=   " << num << "  -> " << ((c1 <= num) ? "True" : "False") << endl;
    cout << num << "    <= "; c2.Print();cout << " -> " << ((num <= c2) ? "True" : "False") << endl << endl;

}