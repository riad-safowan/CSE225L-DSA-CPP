#include<iostream>
using namespace std;

int main() {

// allocating memory address for a int variable
    int* a = new int;
    *a = 10;
    cout << *a<<endl;

// array itself return the first elements memory address
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin>>a;
        arr[i]=a;
    }
    cout<<arr<<endl;
    cout<<*arr<<endl;
    cout<<*arr+1<<endl;

    // array with dynamic memory allocation
    int* arr2 = new int[3];
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin>>a;
        arr2[i]=a;
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<arr2[i]<<endl;
    }
    delete [] arr2;

    // array with dynamic memory allocation
    int** arr3 = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        arr3[i]= new int[3];
    }

    delete [] arr3[0];
    delete [] arr3[1];
    delete [] arr3[2];

    return 0;
}