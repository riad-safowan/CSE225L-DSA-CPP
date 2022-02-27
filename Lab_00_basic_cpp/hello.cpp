#include <iostream>
using namespace std;

// class MyClass
// {                    // The class
// public:              // Access specifier
//     int myNum;       // Attribute (int variable)
//     string myString; // Attribute (string variable)
// };

class Car
{
public:
    Car()
    {
        cout << "New car is created";
    }
    int speed(int maxSpeed);
    void myMethod()
    { // Method/function defined inside the class
        cout << "Hello World!";
    }
};

int Car::speed(int maxSpeed)
{
    return maxSpeed;
}

void testInt(int a, int* b, int& c) {
    a = a * 10;
    *b = *b * 10;
    c = c * 10;
}

int main()
{
    cout << "Im Riad Safowan\n";
    cout << "I love the universe\n";

    // MyClass myObj;
    // myObj.myNum = 15;
    // myObj.myString = "Some text";
    // cout << myObj.myNum << "\n";
    // cout << myObj.myString;

    Car myObj;
    myObj.myMethod();         // Create an object of Car
    cout << myObj.speed(200)<<endl; // Call the method with an argument

    int a = 5;
    int bx = 5;
    int* b = &bx;
    int cx = 5;
    int& c = cx;

    cout << a << " " << b << " " << c << endl;
    testInt(a, b, c);
    cout << a << " " << b << " " << c << endl;

    return 0;
}
