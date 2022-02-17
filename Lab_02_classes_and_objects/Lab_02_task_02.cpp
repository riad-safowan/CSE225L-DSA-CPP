#include<iostream>
#include "dynarr.cpp" 
using namespace std;

/*Task  2:  Modify the header and the source files. Add a member function void allocate(int s) which allows
you to change the size of the array. Make sure that memory is not leaked. */

void dynArr::allocate(int s)
{
    if (s > size)
    {
        int* temp = data;
        int oldSize = size;
        delete data;
        data = new int[s];
        for (int i = 0; i < size; i++)
        {
            data[i] = temp[i];
        }
        size = s;
        delete temp;
    }
}

int main() {

    dynArr obj1 = dynArr();
    dynArr obj2 = dynArr(5);

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value for element " << i << " : ";
        int value;
        cin >> value;
        obj2.setValue(i, value);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << obj2.getValue(i) << " ";
    }

    obj1.allocate(10);

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter value for element " << i << " : ";
        int value;
        cin >> value;
        obj2.setValue(i, value);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << obj2.getValue(i) << " ";
    }

    obj1.allocate(5);
}
