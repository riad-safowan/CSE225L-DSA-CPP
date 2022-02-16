#include<iostream>
#include "dynarr.cpp" 
using namespace std;

/*Task 1: In the driver file (main.cpp), perform the following sub-tasks.
1. Create two objects of this class, one with no constructor argument and one with the argument 5.
2. Take five input values from the user and store them in the array inside the second object using the set method.
3. For the second object, print all the values you just stored.
Note that, you cannot assign anything in the first object since the array inside it has size 0. Neither can you change
the size of this array to some other size. */

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
}
