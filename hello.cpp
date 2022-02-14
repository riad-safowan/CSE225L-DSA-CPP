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

int main()
{
    cout << "Im Riad Safowan\n";
    cout << "I love the universe";

    // MyClass myObj;
    // myObj.myNum = 15;
    // myObj.myString = "Some text";
    // cout << myObj.myNum << "\n";
    // cout << myObj.myString;

    Car myObj;
    myObj.myMethod();         // Create an object of Car
    cout << myObj.speed(200); // Call the method with an argument

    return 0;
}
