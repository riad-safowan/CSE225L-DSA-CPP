#include<iostream>
#include "dynarr2D.cpp" 
using namespace std;

/*Task  2:  Modify the header and the source files. Add a member function void allocate(int s) which allows
you to change the size of the array. Make sure that memory is not leaked. */

int main() {

    int rows, cols;
    cout << "Enter the number of ROWS: ";
    cin >> rows;
    cout << "Enter the number of COLS: ";
    cin >> cols;

    dynArr2D<float> obj(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value for element " << i << " " << j << " : ";
            float value;
            cin >> value;
            obj.setValue(i, j, value);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << obj.getValue(i, j) << " ";
        }
        cout << endl;
    }

}
