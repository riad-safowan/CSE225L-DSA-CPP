#include<iostream>
using namespace std;

/*Task 1: Using the new operator, allocate an integer array of user specified size (the user gives the size of the array as
input). Assign values to the array elements by taking user inputs and then print the values. Finally de-allocate the array
using the delete operator. */

int main()
{
    cout << "Enter the size of the array : ";
    int size;
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter value for element " << i << " : ";
        cin >> *(array+i);
    }
    for (int i = 0; i < size; i++) {
        cout << *(array+i) << " ";
    }

    delete[] array;
    return 0;
}

