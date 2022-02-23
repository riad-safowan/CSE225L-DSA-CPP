#ifndef COMPLEX_H_INCLUDE
#define COMPLEX_H_INCLUDE
#include <iostream>
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

    friend Complex operator==(Complex, Complex);
    friend Complex operator==(int, Complex);
    friend Complex operator==(Complex, int);

    friend Complex operator!=(Complex, Complex);
    friend Complex operator!=(int, Complex);
    friend Complex operator!=(Complex, int);

    friend Complex operator>(Complex, Complex);
    friend Complex operator>(int, Complex);
    friend Complex operator>(Complex, int);

    friend Complex operator<=(Complex, Complex);
    friend Complex operator<=(int, Complex);
    friend Complex operator<=(Complex, int);

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
    sum.imaginary = a.imaginary + b;
    return sum;
}

Complex operator+(int a, Complex b) {
    Complex sum;
    sum.real = a + b.real;
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
    sum.imaginary = a.imaginary - b;
    return sum;
}

Complex operator-(int a, Complex b) {
    Complex sum;
    sum.real = a - b.real;
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

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    int num = 8;
    Complex result;

    // + operator
    result = c1 + c2;
    c1.Print();cout << " + "; c2.Print();cout << " = "; result.Print(); cout << endl;
    result = c1 + num;
    c1.Print();cout << " +   " << num << "i = "; result.Print(); cout << endl;
    result = num + c2;
    cout << num << "    + "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    // - operator
    result = c1 - c2;
    c1.Print();cout << " - "; c2.Print();cout << " = "; result.Print();cout << endl;
    result = c1 - num;
    c1.Print();cout << " -   " << num << "i = "; result.Print(); cout << endl;
    result = num - c2;
    cout << num << "    - "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    // * operator
    result = c1 * c2;
    c1.Print();cout << " * "; c2.Print();cout << " = "; result.Print();cout << endl;
    result = c1 * num;
    c1.Print();cout << " *   " << num << "i = "; result.Print(); cout << endl;
    result = num * c2;
    cout << num << "    * "; c2.Print();cout << " = "; result.Print(); cout << endl << endl;

    

}